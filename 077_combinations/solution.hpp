#include <vector>

class Solution
{
	public:
		std::vector<std::vector<int>> compute(int n, int k)
		{
			this->n = n;
			this->k = k;	

			std::vector<int> path;
			combine_backtracking(1, path);
			return result;
		}
		void combine_backtracking(int start_idx, std::vector<int>& path)
		{
			if (k == path.size())	
			{
				result.push_back(path);	
				return;
			}

			for (int i = start_idx; i <= n; ++i)
			{
				path.push_back(i);	
				combine_backtracking(i + 1, path);
				path.pop_back();
			}
		}

	private:
		int n;
		int k;
		std::vector<std::vector<int>> result;
};
