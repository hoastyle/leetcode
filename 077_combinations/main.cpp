#include <iostream>

#include "solution.hpp"

int main(int argc, char *argv[])
{
    Solution s;
    for (const auto &v : s.compute(5, 3, false)) {
        for (auto i : v) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "-------------- pruning --------------" << std::endl;
    for (const auto &v : s.compute(5, 3, true)) {
        for (auto i : v) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
