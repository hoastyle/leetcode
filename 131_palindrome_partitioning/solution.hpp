#include <vector>

class Solution
{
   public:
    std::vector<std::vector<std::string>> palindromePartitioning(std::string s)
    {
        mPath.clear();
        mResult.clear();

        backtracking(s, 0);
        return mResult;
    }

    void backtracking(const std::string& s, int segment_index)
    {
        // 结束条件
        if (segment_index >= s.size()) {
            mResult.push_back(mPath);
            return;
        }

        // 循环条件
        for (int i = segment_index; i < s.size(); ++i) {
			std::string sub_str = s.substr(segment_index, i - segment_index + 1);
            if (isPalindrome(sub_str)) {
				mPath.push_back(sub_str);
            } else {
				continue;	
			}

			// 递归条件
			backtracking(s, i + 1);
			mPath.pop_back();
        }
    }

   private:
    bool isPalindrome(const std::string& s)
    {
        if (1 == s.size()) {
            return true;
        } else if (s.empty()) {
            return false;
        }

        for (int i = 0, j = s.size() - 1; i <= j; ++i, --j) {
            if (s[i] != s[j]) return false;
        }
        return true;
    }

   private:
    std::vector<std::string> mPath;
    std::vector<std::vector<std::string>> mResult;
};
