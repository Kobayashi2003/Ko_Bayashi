// constexpr 常量表达式

// 将运行时的计算提前到编译时来做性能优化

#include <iostream>

using LLI = long long int;

constexpr LLI qpow(int x, int y) {
    LLI tmp_x = x, result = 1;
    while (y > 0) {
        if (y & 1) { // 若 y 为奇数
            result *= tmp_x;
        }
        y >>= 1;
        tmp_x = tmp_x * tmp_x;
    }
    return result;
}

int main() {

    int arr[ qpow(2, 5) ] = {}; 

    std::cout << sizeof(arr)/sizeof(int) << std::endl;

    return 0;
}