/*
输入圆锥底半径和高，输出其体积
（数据范围取[0,100]内实数；
先后输入其半径，高；
圆周率值定义为3.14；
输出结果保留至小数点后两位）

输入输出样例
输入样例1：
1 2
输出样例1：
2.09

输入样例2：
3.2 5.6
输出样例2：
60.02
*/

#include<stdio.h>
#define pi 3.14
int main()
{
    double r,h;
    printf("请依次输入圆锥底部半径及圆锥的高\n");
    scanf("%lf %lf",&r,&h);
    double v;
    v=pi*r*r*h/3;
    printf("圆锥的体积为%4.2f\n",v);
    return 0;
}