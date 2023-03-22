#include <iostream>

#include "solution.hpp"

int main(int argc, char *argv[])
{
    Solution s;

    std::vector<int> result;

    std::vector<int> nums = {2, 7, 11, 15};
    std::cout << "Input: " << std::endl;
    for (int i = 0; i < nums.size(); ++i) {
        std::cout << nums[i] << " ";
    }
    std::cout << std::endl;
    int target = 9;

    result = s.twoSum1(nums, target);
    std::cout << "result: " << result[0] << " " << result[1] << std::endl;

    result = s.twoSum2(nums, target);
    std::cout << "result: " << result[0] << " " << result[1] << std::endl;

    return 0;
}
