/*************************************************************************
	> File Name: 6_12.cpp
	> Author:KID_XiaoYuan 
	> Mail:kuailexy@126.com
	> Created Time: 2017年06月06日 星期二 19时56分48秒
 ************************************************************************/

#include<iostream>
#include<cstring>
#define MAXN 100+5

char pic[MAXN][MAXN];
int idx[MAXN][MAXN];

int m,n;

using namespace std;

void dfs(int r,int c,int id)
{
    //printf("vist pic[%d][%d]\n",r,c);
    if(r < 0 || r >= m || c < 0 || c >= n)//出界的格子
    return;
    if(pic[r][c] != '@' || idx[r][c] > 0)//非‘@’或已被访问过
    return;
    idx[r][c] = id;//连通分量标号
    for(int dr = -1; dr <= 1;dr++)//横向搜索
    {
        for(int dc =-1;dc <=1;dc++ )//纵向搜索
        {
            if(dr != 0 || dc != 0)//排除自身
            {
                dfs(r+dr,c+dc,id);//递归搜索
            }
        }
    }
}

int main()
{
    cin>>m>>n;
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin>>pic[i][j];
        }
    }

    memset(idx,0,sizeof(idx));

    int cnt  = 0;

    for(int i =0; i < m ; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(pic[i][j] =='@' && idx[i][j] == 0)
            {
                dfs(i,j,++cnt);
            }
        }
    }

    printf("%d\n",cnt);
    
    return 0;
}
