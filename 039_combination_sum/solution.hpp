#include <vector>
#include <algorithm>

class Solution {
public:
    // 核心诉求: 根据输入，非重复的数字数组，找到组合使其和为目标值
    // 难点1: 如何自动化整个流程？回溯法
    // 难点2: 如何区分不同的字符串？如何一一对应？利用元素和其出现次数，构建一一映射的数值？
    // 可以不做比较，按顺序即可
    std::vector<std::vector<int>> mResult;
    int mTarget;
    std::vector<int> mCurResult;
	// 前提是输入必须是按顺序的，所以最好在开始做个排序
    void combine_backtracking(const std::vector<int>& candidates, int start_idx, int& sum)
    {
        if (mTarget == sum)
        {
            mResult.push_back(mCurResult);
            return;
        }

        if (sum > mTarget)
        {
            return;
        }

		// KEY POINT 3 can pruning
        for (int i = start_idx; i < candidates.size() && candidates[i] <= mTarget - sum; ++i)
        {
            mCurResult.push_back(candidates[i]);
            sum += candidates[i];
			// KEY POINT 2
            combine_backtracking(candidates, i, sum);       
            sum -= candidates[i];
            mCurResult.pop_back();
        }
    }
	std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
        mTarget = target;
        int sum = 0;

		// KEY POINT 1
		std::sort(candidates.begin(), candidates.end());
        combine_backtracking(candidates, 0, sum);
        return mResult;
    }
};
