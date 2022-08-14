#include <vector>

class Solution
{
   public:
    const std::string letterMap[10] = {
        "",      // 0
        "",      // 1
        "abc",   // 2
        "def",   // 3
        "ghi",   // 4
        "jkl",   // 5
        "mno",   // 6
        "pqrs",  // 7
        "tuv",   // 8
        "wxyz",  // 9
    };

   public:
    std::vector<std::string> letterCombinations(std::string digits)
    {
		result.clear();
        int size = digits.size();

        if (0 == size) {
            return result;
        }

		std::string target;
        backtracking(digits, 0, target);
        return result;
    }

	void backtracking(const std::string& digits, int start_index, std::string& target)
	{
		// std::cout << "medium target: " << target << std::endl;
		if (digits.size() == target.size())
		{
			result.push_back(target);	
			// std::cout << "target: " << target << std::endl;
			return;
		}

		int index = digits[start_index] - '0';
		if (index >= 0 && index <= 9)
		{
			int letter_size = letterMap[index].size();
			for (int i = 0; i < letter_size; ++i)
			{
				target.push_back(letterMap[index].at(i));	
				backtracking(digits, start_index + 1, target);
				target.pop_back();	
			}
		}
		return;
	}

   private:
    std::vector<std::string> result;
};
