#ifndef MERGESORT_TPP
#define MERGESORT_TPP

#include <algorithm>
#include <cmath>
#include <ctime>
#include <iostream>
#include <vector>

template<typename Container>
struct PairWithIndex {
    typename Container::value_type main;
    typename Container::value_type pend;
    size_t originalIndex;
};

template<typename Container>
class MergeSort {
private:
    Container m_sequence;
    Container m_result;
    int m_comparaisons;
    double dur_vec;
    std::vector<size_t> order;

    std::vector<size_t> generateJacobstahl(size_t n) {
        std::vector<size_t> jacobstahl;
        jacobstahl.push_back(0);
        if (n > 0) 
            jacobstahl.push_back(1);

        size_t idx = 1;
        while (true) {
            size_t next = jacobstahl[idx] + 2 * jacobstahl[idx - 1];
            jacobstahl.push_back(next);
            if (next >= n) 
                break;
            idx++;
        }

        return jacobstahl;
    }

    std::vector<size_t> getJacobsthalOrder(size_t n) {
        if (n == 0) 
            return std::vector<size_t>();

        std::vector<size_t> jacobstahl = generateJacobstahl(n);
        std::vector<size_t> order;
        std::vector<bool> used(n, false);

        for (size_t i = 1; i < jacobstahl.size(); i++) {
            size_t jCurrent = jacobstahl[i];
            size_t jPrev = jacobstahl[i - 1];

            size_t insertUpTo = std::min(jCurrent, n);

            for (size_t j = insertUpTo; j > jPrev; j--) {
                if (j > 0 && !used[j - 1]) {
                    order.push_back(j - 1);
                    used[j - 1] = true;
                }
            }
        }

        for (size_t i = 0; i < n; i++) {
            if (!used[i]) {
                order.push_back(i);
            }
        }

        return order;
    }

public:
    MergeSort() : m_comparaisons(0), dur_vec(0.0) {}

    int parseInput(int ac, char **arg) {
        for (int i = 1; i < ac; i++) {
            std::string token = arg[i];
            if (::isdigit(token[0])) {
                int value = std::stoi(token.c_str());
                if (std::find(m_sequence.begin(), m_sequence.end(), value) == m_sequence.end() && value >= 0) {
                    m_sequence.push_back(value);
                }
            } else {
                return 1;
            }
        }
        return 0;
    }

    Container FJAlgo(Container input) {
        if (input.size() <= 1) {
            return input;
        }

        std::vector<PairWithIndex<Container>> pairs;
        typename Container::value_type leftover = -1;
        bool has_leftover = false;

        Container main_chain;

        // Create pairs
        auto it = input.begin();
        while (it != input.end()) {
            auto first = it++;
            if (it == input.end()) {
                leftover = *first;
                has_leftover = true;
                break;
            }
            auto second = it++;

            PairWithIndex<Container> p;
            if (*first < *second) {
                m_comparaisons++;
                std::swap(*first, *second);
            }
            p.main = *first;
            p.pend = *second;
            main_chain.push_back(*first);
            p.originalIndex = pairs.size();
            pairs.push_back(p);
        }

        // Recursively sort the main chain
        main_chain = FJAlgo(main_chain);

        // Reorder pairs according to sorted main chain
        std::vector<PairWithIndex<Container>> sortedPairs;
        for (auto it = main_chain.begin(); it != main_chain.end(); ++it) {
            for (size_t j = 0; j < pairs.size(); j++) {
                if (pairs[j].main == *it) {
                    m_comparaisons++;
                    sortedPairs.push_back(pairs[j]);
                    pairs[j].main = -1;
                    break;
                }
            }
        }

        // Start with sorted main chain
        m_result = main_chain;

        // Insert first pend at the beginning
        if (!sortedPairs.empty()) {
            m_result.insert(m_result.begin(), sortedPairs[0].pend);
        }

        // Get Jacobsthal insertion order
        order = getJacobsthalOrder(sortedPairs.size());

        // Insert remaining pends in Jacobsthal order
        for (size_t i = 0; i < order.size(); i++) {
            size_t idx = order[i];
            if (idx == 0) 
                continue;
            if (idx >= sortedPairs.size()) 
                continue;

            typename Container::value_type toInsert = sortedPairs[idx].pend;
            typename Container::value_type pairBigger = sortedPairs[idx].main;

            // Find max position (paired element's position)
            size_t maxPos = 0;
            auto res_it = m_result.begin();
            for (size_t j = 0; j < m_result.size(); j++, ++res_it) {
                if (*res_it == pairBigger) {
                    maxPos = j;
                    break;
                }
            }

            // Binary search up to maxPos
            size_t left = 0;
            size_t right = maxPos + 1;
            while (left < right) {
                size_t mid = left + (right - left) / 2;
                auto mid_it = m_result.begin();
                std::advance(mid_it, mid);
                
                if (*mid_it < toInsert) {
                    m_comparaisons++;
                    left = mid + 1;
                } else {
                    right = mid;
                }
            }
            
            auto insert_pos = m_result.begin();
            std::advance(insert_pos, left);
            m_result.insert(insert_pos, toInsert);
        }

        // Insert straggler
        if (has_leftover) {
            size_t pos = 0;
            for (auto it = m_result.begin(); it != m_result.end(); ++it, ++pos) {
                if (!(*it < leftover)) {
                    break;
                }
                m_comparaisons++;
            }
            auto insert_pos = m_result.begin();
            std::advance(insert_pos, pos);
            m_result.insert(insert_pos, leftover);
        }

        return m_result;
    }

    int getNbrComparaisons() {
        return m_comparaisons;
    }

    void printResult() {
        if (m_result.empty() || (m_result.size() > 0 && *m_result.begin() == -1))
            m_result = m_sequence;

        // std::cout << "Before:  ";
        // for (auto it = m_sequence.begin(); it != m_sequence.end(); ++it) {
        //     std::cout << *it << " ";
        // }
        // std::cout << "\n";

        // std::cout << "After:  ";
        // for (auto it = m_result.begin(); it != m_result.end(); ++it) {
        //     std::cout << *it << " ";
        // }
        // std::cout << "\n";

        std::cout << "Time to process a range of " << m_sequence.size() << " elements: ";
        std::printf("%.6fs\n", dur_vec);
        
        // std::cout << "Comparisons used: " << getNbrComparaisons() << std::endl;

    // std::cout << "order: ";
	// for (size_t x : getOrder()) {
	// 	std::cout << x + 1 << " ";
	// }
    }

    void vec_duration() {
        clock_t start = clock();
        // Your sorting logic here
        clock_t end = clock();
        dur_vec = double(end - start) / CLOCKS_PER_SEC;
    }


    void deq_duration() {
        clock_t start = clock();
        // Your sorting logic here
        clock_t end = clock();
        dur_vec = double(end - start) / CLOCKS_PER_SEC;
    }

    Container getInput() {
        return m_sequence;
    }

    std::vector<size_t> getOrder() {
        return order;
    }
};

#endif 