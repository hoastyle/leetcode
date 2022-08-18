#include <iostream>

#include "solution.hpp"

int main(int argc, char *argv[])
{
    Solution s;

    std::vector<std::vector<int>> test_vec = {{1, 2, 3}, {0}};

    for (auto test : test_vec) {
        std::vector<std::vector<int>> result_vec = s.subsets(test);
        for (auto result : result_vec) {
			std::cout << "[";
			int i = 0;
			for (auto num: result)
			{
				if (i == result.size() - 1)
					std::cout << num;
				else
					std::cout << num << ", ";	
				++i;
			}
			std::cout << "]" << std::endl;
        }
        std::cout << std::endl;
    }

    return 0;
}
