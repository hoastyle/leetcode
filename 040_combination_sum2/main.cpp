#include <iostream>

#include "solution.hpp"

int main(int argc, char *argv[])
{
    Solution s;
	std::vector<int> input_vec = {10,1,2,7,6,1,5};
	std::vector<std::vector<int>> result = s.combinationSum(input_vec, 8);
	for (int i = 0; i < result.size(); ++i)
	{
	    std::cout << "[";
		for (int j = 0; j < result[i].size(); ++j)	
		{
			if (j == result[i].size() - 1)
				std::cout << result[i][j];
			else
				std::cout << result[i][j] << ", ";
		}
		if (i == result.size() - 1)
			std::cout << "]";
		else
			std::cout << "], ";
	}
	std::cout << std::endl;

    return 0;
}
