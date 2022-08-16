#include <vector>

class Solution
{
   public:
    // 两点
    // 1. 必须要排序, 为去重服务
    // 2. 需要去重
    // 以1, 2, 2, 3为例，按照之前的算法，会产生1, 2, 3和1, 2, 3
    // 相同的元素，只允许同分支，不允许同层
    std::vector<std::vector<int>> mResult;
    int mTarget;
    std::vector<int> mCurResult;
    // 前提是输入必须是按顺序的，所以最好在开始做个排序
    void combine_backtracking(
        const std::vector<int>& candidates, int start_idx, int& sum, std::vector<bool>& used_vec)
    {
        if (mTarget == sum) {
            mResult.push_back(mCurResult);
            return;
        }

        if (sum > mTarget) {
            return;
        }

        // KEY POINT 3 can pruning
        for (int i = start_idx; i < candidates.size() && candidates[i] <= mTarget - sum; ++i) {
            if (i > 0 && candidates[i - 1] == candidates[i] && used_vec[i - 1] == false) continue;

            mCurResult.push_back(candidates[i]);
            sum += candidates[i];
            // KEY POINT 2
			used_vec[i] = true;
			// i或者i+1，非常重要
            combine_backtracking(candidates, i + 1, sum, used_vec);
            sum -= candidates[i];
            used_vec[i] = false;
            mCurResult.pop_back();
        }
    }
    std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target)
    {
        mTarget = target;
        int sum = 0;

        std::vector<bool> used_vec(candidates.size(), false);

        // KEY POINT 1
        std::sort(candidates.begin(), candidates.end());
        combine_backtracking(candidates, 0, sum, used_vec);
        return mResult;
    }
};
