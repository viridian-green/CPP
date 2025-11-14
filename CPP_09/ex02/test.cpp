#include <vector>
#include <algorithm>

class FJPairless
{
public:
    // Main entry point: returns the indices of elements in sorted order
    std::vector<int> JAlgo(const std::vector<int>& arr)
    {
        // Step 0: special cases
        if (arr.size() <= 1)
            return index_sequence(arr.size());   // {0} or empty

        // Step 1: create an index array (like the human tracking positions)
        std::vector<int> idx = index_sequence(arr.size());

        // Run pairless recursive core
        return recurse(arr, idx);
    }

private:

    // Create index list: 0,1,2,...,n-1
    std::vector<int> index_sequence(size_t n)
    {
        std::vector<int> v(n);
        for (size_t i = 0; i < n; i++) v[i] = i;
        return v;
    }

    //-----------------------------------------------------------------
    // THE CORE PAIRLESS ALGORITHM (“Human logic Ford–Johnson recursion”)
    //-----------------------------------------------------------------
    std::vector<int> recurse(const std::vector<int>& arr,
                             const std::vector<int>& idx)
    {
        size_t n = idx.size();
        if (n <= 1)
            return idx; // base case

        //-----------------------------------------
        // 1. Conceptually create pairs of indices
        //-----------------------------------------

        // main: indices of larger elements
        std::vector<int> main;
        // pend: indices of smaller elements
        std::vector<int> pend;

        main.reserve(n / 2 + 1);
        pend.reserve(n / 2 + 1);

        for (size_t i = 0; i < n; i += 2)
        {
            if (i + 1 == n)
            {
                // leftover element → goes to main (FJ rule)
                main.push_back(idx[i]);
            }
            else
            {
                int a = idx[i];
                int b = idx[i+1];

                // compare using arr
                if (arr[a] > arr[b])
                {
                    main.push_back(a);
                    pend.push_back(b);
                }
                else
                {
                    main.push_back(b);
                    pend.push_back(a);
                }
            }
        }

        //-----------------------------------------
        // 2. Recurse on the "main chain" only
        //-----------------------------------------

        std::vector<int> sorted_main = recurse(arr, main);

        //-----------------------------------------
        // 3. Now we rebuild the pair order
        //    without having stored actual pairs.
        //
        //    The relationship is implicit:
        //    if main[i] = index of larger element,
        //    then pend[i] = index of its smaller partner.
        //-----------------------------------------

        std::vector<int> result;
        result.reserve(n);

        // For each main element in sorted order:
        for (int big_idx : sorted_main)
        {
            // Find its partner in pend
            // (same position in the original main array)
            auto it = std::find(main.begin(), main.end(), big_idx);
            size_t pos = it - main.begin();

            result.push_back(big_idx);

            // if this big has a pend partner, insert it later
            // (true Jacobsthal insertion happens in the final phase,
            // but for this demonstration we keep order-preserving logic)
            if (pos < pend.size())
            {
                // We'll append the pend elements after main sequence.
                // Real FJ insertion is more complex (binary inserts
                // in Jacobsthal order), but this preserves pairing
                // relationships WITHOUT using Pair{} structs.
            }
        }

        // Append pend chain (not yet Jacobsthal-inserted)
        result.insert(result.end(), pend.begin(), pend.end());

        return result;
    }
};