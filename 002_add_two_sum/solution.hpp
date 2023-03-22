#include <algorithm>
#include <vector>
#include <unordered_map>

class Solution
{
   public:
    // brute force
    std::vector<int> twoSum1(std::vector<int>& nums, int target)
    {
        std::vector<int> result;

        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                if (nums[i] + nums[j] == target) {
                    result = {i, j};
                }
            }
        }

        return result;
    }

    // use more space and o(1)
    std::vector<int> twoSum2(std::vector<int>& nums, int target)
    {
		std::unordered_map<int, int> dataMap;
		std::vector<int> result;

        for (int i = 0; i < nums.size(); ++i) {
            if (dataMap.count(target - nums[i]) > 0) {
                result = {dataMap[target - nums[i]], i};
            } else {
                dataMap[nums[i]] = i;
            }
        }

		return result;
    }
};
