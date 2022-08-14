#include <iostream>

#include "solution.hpp"

int main(int argc, char *argv[])
{
    Solution s;
	std::string test_string_1 = "23";
	std::vector<std::string> result1 = s.letterCombinations(test_string_1);
	std::cout << "Input: " << test_string_1 << std::endl;
	std::cout << "Output size: " << result1.size() << std::endl;
	std::cout << "[";
	for (auto str: result1)
	{
		std::cout << "\"" << str << "\",";
	}
	std::cout << "]" << std::endl;

    std::cout << "-----------------------------" << std::endl;
	std::string test_string_2 = "";
	std::vector<std::string> result2 = s.letterCombinations(test_string_2);
	std::cout << "Input: " << test_string_2 << std::endl;
	for (auto str: result2)
	{
		std::cout << "output: " << str << std::endl;
	}
    return 0;
}
