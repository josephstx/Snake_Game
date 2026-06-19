#include <random>
#include <RandNum.hpp>

int RandNum::getRandInt(int bottom_limit, int top_limit) {
    std::random_device rnd;
    std::mt19937 gen(rnd());
    std::uniform_int_distribution<int> range(bottom_limit, top_limit);
    return range(gen);
}