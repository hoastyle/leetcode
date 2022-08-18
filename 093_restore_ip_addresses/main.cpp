#include <iostream>

#include "solution.hpp"

int main(int argc, char *argv[])
{
    Solution s;

    std::vector<std::string> test_str_vec = {"25525511135", "0000", "101023"};

    for (auto test_str : test_str_vec) {
        std::vector<std::string> result_vec = s.restore_ip_addresses(test_str);
        std::cout << "Input string: " << test_str << ", possible ip size: " << result_vec.size()
                  << std::endl;
        for (auto result : result_vec) {
            std::cout << result << std::endl;
        }
        std::cout << std::endl;
    }

    return 0;
}
