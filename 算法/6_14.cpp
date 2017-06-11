/*************************************************************************
	> File Name: 6_14.cpp
	> Author:KID_XiaoYuan 
	> Mail:kuailexy@126.com
	> Created Time: 2017年06月06日 星期二 21时33分15秒
 ************************************************************************/

#include<string>
#include<cstring>
#include<queue>
#include<iostream>
#define MAXN 100

using namespace std;

const char* dirs  = "NESW";
const char* turns = "FLR";

const int dr[] = {-1,0,1,0};
const int dc[] = {0,1,0,-1};//顺时针方向

struct node {  
    int r, c, dir;  
    node(int r = 0, int c = 0, int dir = 0) : r(r), c(c), dir(dir) {}  
};  
string maze_name;
int c0,r0,r1,c1,dir,r2,c2;
int has_edge[MAXN][MAXN][MAXN][MAXN];//表示当前是(r,c,dir);
int d[MAXN][MAXN][MAXN];
node p[MAXN][MAXN][MAXN];

int dir_id(char c)//返回方位编号
{
    return strchr(dirs,c)-dirs;
}

int turn_id (char c)//返回方向编号
{
    return(strchr(turns,c)-turns);
}

node walk(const node u,int turn)//模拟行走函数
{
    int dir = u.dir;
    if(turn == 1)
    {
        dir = (dir+3)%4;//逆时针
    }
    if(turn == 2)
    {
        dir = (dir+1)%4;//顺时针
    }
    return (node (u.r+dr[dir],u.c+dc[dir],dir));
}

void read_edge()
{
    memset(has_edge,0,sizeof(has_edge));
    int pr,pc,pdir,pturn;
    string temp;
    while(cin >> pr)
    {
        if(pr == 0)
        {
            break;
        }
        cin >> pc;
        while(cin>>temp)
        {
            if(temp =="*")
            break;
            pdir = dir_id(temp[0]);
            for(int i = 1; i < temp.length();i++ )
            {
                pturn = turn_id (temp[i]);
                has_edge[pr][pc][pdir][pturn] = 1;
            }
        }
    }
}

void print_ans(node u)
{
    vector<node> nodes;
    for(;;)
    {
        nodes.push_back(u);
        if(d[u.r][u.c][u.dir] == 0)
        break;
        u = p[u.r][u.c][u.dir];
    }
    nodes.push_back(node(r0,c0,dir));

    int cnt = 0;
    for(int i = nodes.size()-1; i >= 0; i--)
    {
        if(cnt % 10 == 0)
        {
            puts(" ");
        }
        printf(" (%d %d) ",nodes[i].r,nodes[i].c);
        if(++cnt % 10 == 0)
        {
          printf("\n");
        }
    }
    if(nodes.size() % 10 != 0)
    {
        printf("\n");
    }
}

bool inside(int r,int c)
{
    if(r >= 1 && r <= 9 && c >= 1 && c <= 9)
    {
        return true;
    }
    return false;
}

bool read_list()
{
    cin>> maze_name;
    if(maze_name == "END")
    return false;
    char dir0;
    cin>>r0>>c0>>dir0>>r2>>c2;
    dir = dir_id(dir0);
    r1 = r0 + dr[dir];
    c1 = c0 + dc[dir];
    read_edge();
    return true;
}

void solve()
{
    queue<node> q;
    memset(d,-1,sizeof(d));
    node n1(r1,c1,dir);
    d[r1][c1][dir] = 0;
    q.push(n1);
    while(!q.empty())
    {
        node u = q.front();
        q.pop();
        if(u.r == r2 && u.c == c2)
        {
            print_ans(u);
            return;
        }
        for(int i = 0; i < 3; i++)
        {
            node v = walk(u,i);
            if(has_edge[u.r][u.c][i] && inside(v.r,v.c) && d[v.r][v.c][v.dir] < 0)
            {
                d[v.r][v.c][v.dir] = d[u.r][u.c][u.dir]+1;
                p[v.r][v.c][v.dir] = u;
                q.push(v);
            }
        }
    }
    cout << maze_name << endl;
    cout << " No Solution Possible"<<endl;
}

int main()
{
    while(read_list())
    {
        solve();
    }
    return 0;
}
