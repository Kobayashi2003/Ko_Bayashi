# rvalue reference 右值引用

```cpp
#include <iostream>

inline double f(double tf) { return 5.0*(tf-32.0)/9.0; }

int main() {

    using namespace std;
    double tc = 21.5;
    double && rd1 = 7.07;
    double && rd2 = tc * 1.8 + 32.0;
    double && rd3 = f(rd2);
    cout << " tc value and address: " << tc << " " << &tc << endl;
    cout << " rd1 value and address: " << rd1 << " " << &rd1 << endl;
    cout << " rd2 value and address: " << rd2 << " " << &rd2 << endl;
    cout << " rd3 value and address: " << rd3 << " " << &rd3 << endl;
    
    return 0;
}
```


## 左值、右值的纯右值、将亡值、右值

- **左值**（lvalue, left value），顾名思义就是赋值符号左边的值。准确来说，左值是表达式（不一定是赋值表达式）后依然存在的持久对象
- **右值**（rvalue, right value），右边的值，是表达式后不再存在的临时对象
  而 C++11 中为了引入强大的右值引用，又将右值分为了纯右值（pure rvalue）和将亡值（xvalue）
- **纯右值**（prvalue, pure rvalue），纯粹的右值，要么是纯粹的字面量，例如 10，true；要么是求值结果相当于字面量或匿名临时对象，例如 1+2。非引用返回的临时变量、运算表达式产生的临时变量、原始字面量、lambda 表达式、函数返回值等都是纯右值

> 需要注意的是，字面量除了字符串字面量外，其他字面量都是纯右值，而字符串字面量是左值，类型为 const char 数组. 例如：

```cpp
```