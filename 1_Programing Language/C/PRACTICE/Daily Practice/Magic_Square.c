//注释是我自己写的！！！！by KOBAYASHI
#include<stdio.h>
#define N 3 //设置阶数 
int main()
{   
    int a[N][N]={0};//首先注意这里，这里十分关键：首先将a[][]进行初始化，令二维数组中的每一项都为零
    int i, j, k, t, x, y;   

    //首先将自然数1放在第一行的中间
    i=0;  //自然数1的行标    
    j=N/2;  //自然数1的列   
    t=N-1;  //最后一行、最后一列的下标  

    for(k=1; k<=N*N; k++) //设置循环，将自然数1~n^2按照顺序放入魔方阵中  
    {        
        a[i][j]=k;//将第k个数放在魔方阵的第i行第j列上

        //定义变量x、y用于暂时保存i与j的值
        x=i;        
        y=j;      

        //这组 if else 语句用于判断当前该数是否处于第0行的位置          
        if(i == 0)//若该数位于第0行，根据规则(2)，需将下一个数字放在最后一行(即为第N-1行)
        i=t;        
        else//若该数不位于第0行，则将下一个数字放在该数的上一行          
        i=i-1; 

        //这组 if else 语句用于判断当前该数是否处于最后一列(即第N-1列的位置)
        if(j != t)//若该数不位于最后一列，则将下一个数字放在该数的的下一列           
        j=j+1;  
        else//若该数位于最后一列，根据规则(3)，需将下一个数字放在第0列         
        j=0;   

        //注意在最开头我们已经将魔方阵进行了一次初始化，因此没有进行赋值的项它的值都等于0
        //该if语句可以帮助我们判断下一个数即将要放入的位置上是否已经储存有别的数字
        if(a[i][j]!=0)//若此时a[i][j]!=0则说明此时a[i][j]上已经储存过别的数字        
        {            
            i=x+1;//则此时根据规则(4)我们需要将该数储存到a[i][j]的正下方            
            j=y;        
        }    
    } 

    //最后是用双循环嵌套将魔方阵输出
    printf("生成的%d阶魔方阵为：",N);    
    for(i=0; i<N; i++)    
    {        
        printf("\n");       
        for(j=0; j<N; j++)        
        {            
             printf("%5d", a[i][j]);        
        }    
    }   
    printf("\n");


    return 0;
    }
    //(1)假定阵列的行列下标都从0开始，则魔方阵的生成方法为：在第0行中间置1，对从2开始的其余n2-1个数依次按下列规则存放：//(1) 假定当前数的下标为(i，j)，则下一个数的放置位置为当前位置的右上方，即下标为(i-1，j+1)的位置。
    //(2) 如果当前数在第0行，即i-1小于0，则将下一个数放在最后一行的下一列上，即下标为(n-1，j+1)的位置。
    //(3) 如果当前数在最后一列上，即j+1大于n-1，则将下一个数放在上一行的第一列上，即下标为(i-1，0)的位置。
    //(4) 如果当前数是n的倍数，则将下一个数直接放在当前位置的正下方，即下标为(i+1，j）的位置。