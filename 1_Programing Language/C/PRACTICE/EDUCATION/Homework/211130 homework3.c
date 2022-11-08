#include<stdio.h>
#define N 100
void CalculateSquare(int *hight,int n)
{
    static int i=0,square=0;
    for(int start=0;start<n;start++)//定义扫描开始的位置
        if(hight[start]>=hight[i])//定义扫描的高度
            for(int temp=0,end=start;end<n;end++)
            {
                if(hight[end]<hight[i])break;//通过与下一高度的比较判断扫描是否终止
                temp=hight[i]*(end-start+1);//计算当前扫描所经过的面积，即为当前所计算的矩形的面积
                if(temp>square) square=temp;//若当前矩形的面积大于先前记录中最大的矩形面积，则将最大矩形面积替换为当前值
            }
    if(++i<n)CalculateSquare(hight,n);
    else printf("The max square of the rectangle is: %d\n",square);
}
int main()
{
    int n,hight[N]={0};
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&hight[i]);
    CalculateSquare(hight,n);
    return 0;
}

//我是用的为c99，可以在程序的任意位置定义变量；如果你使用的为c89，请将变量定义在最开头