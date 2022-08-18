#include <vector>

class Solution
{
   private:
    bool isValid(std::string& s, int start_idx, int end_idx)
    {
        std::string sub_str = s.substr(start_idx, end_idx - start_idx + 1);
        if (sub_str.empty()) return false;

        if (sub_str.size() == 1 && sub_str[0] - '0' == 0) return true;

        int pre_zero_size = 0;
        for (int i = 0; i < sub_str.size(); ++i) {
            if (sub_str[i] != 0)
                break;
            else
                ++pre_zero_size;
        }
        if (pre_zero_size != 0) return false;

        if (std::atoi(sub_str.c_str()) <= 255 && std::atoi(sub_str.c_str()) >= 0) {
            return true;
        }
        return false;
    }

   public:
    void backtracking(std::string& s, int start_idx, int& point_num)
    {
        if (point_num == 3) {
            if (isValid(s, start_idx, s.size() - 1)) {
                m_result.push_back(s);
            }
            return;
        }

        for (int i = start_idx; i < s.size(); ++i) {
            if (isValid(s, start_idx, i)) {
                s.insert(s.begin() + i + 1, '.');
                ++point_num;
                backtracking(s, i + 2, point_num);
                --point_num;
                s.erase(s.begin() + i + 1);
            } else {
				// continue;
				// use break to replace continue, kind of pruning
				break;
            }
        }

        return;
    }

    std::vector<std::string> restore_ip_addresses(std::string& s)
    {
        m_result.clear();
        int point_num = 0;
        backtracking(s, 0, point_num);
        return m_result;
    }

   private:
    std::vector<std::string> m_result;
};
