#include <vector>

class Solution
{
   public:
    void backtracking(const std::vector<int>& nums, int start_idx, std::vector<int>& path)
    {
		m_result.push_back(path);
		if (start_idx > nums.size() - 1)
			return;

		for (int i = start_idx; i < nums.size(); ++i)
		{
			path.push_back(nums[i]);	
			backtracking(nums, i + 1, path);
			path.pop_back();
		}
    }

	std::vector<std::vector<int>> subsets(std::vector<int> nums)
    {
		m_path.clear();
        m_result.clear();
        backtracking(nums, 0, m_path);
        return m_result;
    }

   private:
	std::vector<int> m_path;
	std::vector<std::vector<int>> m_result;
};
