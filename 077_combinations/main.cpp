#include <iostream>
#include "solution.hpp"

int main(int argc, char *argv[])
{
    Solution s;
    for (const auto &v : s.compute(4, 3)) {
        for (auto i : v) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
