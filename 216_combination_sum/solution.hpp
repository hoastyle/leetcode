#include <vector>

// 该问题，输入为n和k
// 当k较小，可通过多层循环遍历暴力解决该问题，但是如果k较多，则代码无法编写。如何编写一个50层循环？
// 对于组合问题，其实就是给定集合，获取满足要求的子集合问题。
// 可抽象为数，n即为树的宽度，k即为树的深度。
// 而数的深度问题，可利用递归来解决。该问题的基本思路即为递归遍历，并通过剪枝优化

class Solution
{
   public:
    std::vector<std::vector<int>> compute(int n, int k, int targetSum, bool pruning)
    {
        this->n = n;
        this->k = k;

        std::vector<int> path;
        result.clear();

		int sum = 0;
        if (!pruning)
            combine_backtracking(1, targetSum, path, sum);
        else
            combine_backtracking_pruning(1, targetSum, path, sum);

        return result;
    }

    void combine_backtracking(int start_idx, int targetSum, std::vector<int>& path, int& sum)
    {
        if (k == path.size()) {
			if (sum == targetSum)
				result.push_back(path);

            return;
        }

        for (int i = start_idx; i <= n; ++i) {
            path.push_back(i);
			sum += i;
            combine_backtracking(i + 1, targetSum, path, sum);
			sum -= i;
            path.pop_back();
        }
    }

    void combine_backtracking_pruning(int start_idx, int targetSum, std::vector<int>& path, int& sum)
    {
        if (k == path.size()) {
			if (sum == targetSum)
				result.push_back(path);
            return;
        }

        // 如何剪枝？
        // 当前path中已有path.size()，而目标是k，则还需k - path.size()
        // 那么n个数中，应预留出k - path.size()个数
        // 这里的+1对应于左闭，需注意
        for (int i = start_idx; i <= n - (k - path.size()) + 1; ++i) {
            path.push_back(i);
			sum += i;
            combine_backtracking_pruning(i + 1, targetSum, path, sum);
			sum -= i;
            path.pop_back();
        }
    }

   private:
    int n;
    int k;
    std::vector<std::vector<int>> result;
};
