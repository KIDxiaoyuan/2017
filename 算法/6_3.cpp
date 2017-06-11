/*************************************************************************
	> File Name: 6_3.cpp
	> Author:KID_XiaoYuan 
	> Mail:kuailexy@126.com
	> Created Time: 2017年06月05日 星期一 19时25分21秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<stack>

using namespace std;

typedef struct Data
{
    public:
    char name;
    int a,b;
    
    /*void input (char &name ,int &a , int &b)
    {
        name = name;
        a = a;
        b = b;
    }*/

}data;

int main()
{
    data m[26];
    stack<data> s;
    int n;
    cin>>n;//输入元素个数
    for(int i = 0; i < n; i++)//输入元素信息
    {
        char name;
        cin>>name;
        cin>>m[name- 'A'].a>>m[name-'A'].b;
    }
    bool error = false;
    string str;//输入计算字符串
    cin>>str;
    int ans = 0;
   for(int i =0; i < str.length();i++)
    {
       if(isalpha(str[i]))//判断是否为字母
        {
            s.push(m[ str[i] - 'A'] );
        }
        else if( str[i] == ')')//如果是）则需要计算
        {
            data m1, m2;
            m2 = s.top();
            s.pop();
            m1 = s.top();
            s.pop();
            
            if(m1.b != m2.a)
            {
                printf("ERROR DATA : M1.B = %d M2.A = %d\n",m1.b,m2.a);
                error = true;
                break;
            }
            ans += m1.a * m1.b * m2.b;
            data c;
            c.a = m1.a;
            c.b = m2.b;
            s.push(c);
        }

    }
    error ? (printf("error\n")) : (printf("%d\n",ans));
    return 0;
}
