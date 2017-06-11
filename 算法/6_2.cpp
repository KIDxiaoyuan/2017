/*************************************************************************
	> File Name: 6_2.cpp
	> Author:KID_XiaoYuan 
	> Mail:kuailexy@126.com
	> Created Time: 2017年06月05日 星期一 18时41分08秒
    > 算法描述：Rails ：判断输入的数字能否通过栈的方式后输出 如果可以 输出YES否则输出NO
    > 样例输入： 5 
                 1 2 3 4 5
                 3 4 5 2 1
    > 样例输出：YES
    > 参考更高效代码：p141
 ************************************************************************/
#include<stack>
#include<iostream>
#define MAX 100
using namespace std;
int input[MAX];
int input2[MAX];

int main()
{
    stack<int> s;
    int n,j = 0,k = 0 ;
    scanf("%d",&n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d",&input[i]);
    }
    
    for(int i =0; i < n; i++)
    {
        scanf("%d",&input2[i]);
    }
    while(j < n)
    {
        s.push(input[j]);
        while(k < n && (s.top() == input2[k]))
        {
            s.pop();
            k++;
        }
        j++;
    }
    printf("%s\n",(s.empty()?"YES":"NO"));

    return 0;
}
