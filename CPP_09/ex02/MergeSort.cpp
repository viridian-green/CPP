#include "MergeSort.hpp"

	// MergeSort::MergeSort(){}

	// MergeSort::MergeSort(const MergeSort &oth){}

	// MergeSort &MergeSort::operator=(const MergeSort &oth){}

	// MergeSort::~MergeSort(){}


// void MergeSort::sortLarge()
// {

// }

void MergeSort::makeOriginalPairs()
{
	//TODO: deal with odd numbers later
	for (int i = 0; i + 1 < m_vec_sequ.size(); i++)
	{
		int a = m_vec_sequ[i];
		int b = m_vec_sequ[i + 1];

		if (a > b)
		{
        	m_main_chain.push_back(a);
        	m_pend_chain.push_back(b);
    	}
		else
		{
			m_main_chain.push_back(b);
        	m_pend_chain.push_back(a);
		}
	}
}

void MergeSort::VecJohnsonFord()
{
    if (m_main_chain.size() <= 2)
        return;

    // Form subpairs for recursion
    std::vector<int> subMain, subPend;
    for (size_t i = 0; i + 1 < m_main_chain.size(); i += 2) {
        if (m_main_chain[i] > m_main_chain[i+1]) {
            subMain.push_back(m_main_chain[i]);
            subPend.push_back(m_main_chain[i+1]);
        } else {
            subMain.push_back(m_main_chain[i+1]);
            subPend.push_back(m_main_chain[i]);
        }
    }

    // Recurse
    VecJohnsonFord(subMain, subPend);

    // Now mirror sort and reinsert pendings at this level
    recursiveSort(subMain, subPend);

}

// void MergeSort::JacobstahlInsert()
// {

// }

int MergeSort::parseInput(int ac, char **arg) {
	//TODO: deal with eval input later
	for (int i = 1; i < ac; i++)
	{
		std::string token = arg[i];
		if (::isdigit(token[0]))
		{
			int value = std::stoi(token.c_str());
			if (std::find(m_vec_sequ.begin(), m_vec_sequ.end(), value) == m_vec_sequ.end()  && value >= 0)
			{
				m_vec_sequ.push_back(std::atoi(token.c_str()));
				m_deque_sequ.push_back(std::atoi(token.c_str()));
			}
		}
		else
			return 1;
	}
	return 0;

};
