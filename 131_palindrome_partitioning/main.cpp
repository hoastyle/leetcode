#include <iostream>

#include "solution.hpp"

int main(int argc, char *argv[])
{
    Solution s;

	std::vector<std::string> test_str_vec = {"aab", "a", "ababa"};

	for (auto test_str: test_str_vec)
	{
		std::cout << "Input string: " << test_str << std::endl;
		std::vector<std::vector<std::string>> result_vec = s.palindromePartitioning(test_str);
		for (auto result: result_vec)
		{
			std::cout << "[";
			int i = 0;
			for (auto str: result)	
			{
				if (i != result.size() - 1)
					std::cout << "\"" << str << "\",";
				else
					std::cout << "\"" << str << "\"";
				++i;
			}
			std::cout << "]" << std::endl;
		}
		std::cout << std::endl;
	}

    return 0;
}
