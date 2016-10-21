#include <bits/stdc++.h>

using namespace std;
int n,m,ans=0;

char arr[1001][1001];
bool vis[1001][1001];
int lyr[1001][1001];

struct ab
{
    int x,y;
};

void bfs(int i,int j,int ly)
{
    queue<struct ab> Q;

    struct ab p,f;
    p.x=i,p.y=j;

    Q.push(p);

    while(!Q.empty())
    {
        p=Q.front();Q.pop();

        if(vis[p.x][p.y]==true)
        if(lyr[p.x][p.y]<ly) ans--;

        if(vis[p.x][p.y]!=true){
        vis[p.x][p.y]=true;
        lyr[p.x][p.y]=ly;

        if(arr[p.x][p.y]=='N') {f.x=p.x-1;f.y=p.y;Q.push(f);}
        else if(arr[p.x][p.y]=='S') {f.x=p.x+1;f.y=p.y;Q.push(f);}
        else if(arr[p.x][p.y]=='E') {f.x=p.x;f.y=p.y+1;Q.push(f);}
        else if(arr[p.x][p.y]=='W') {f.x=p.x;f.y=p.y-1;Q.push(f);}
        }
    }

}

void foo()
{
    memset(vis,false,sizeof(bool)*1001*1001);
    memset(lyr,-1,sizeof(int)*1001*1001);

    int e=1;
    for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
    {
        if(!vis[i][j]) {bfs(i,j,e);ans++;e++;}
    }

    printf("%d\n",ans);
}

int main()
{
    scanf("%d %d",&n,&m);

    for(int i=0;i<n;i++)
   // for(int j=0;j<m;j++)
    scanf(" %s",arr[i]);

    foo();

    return 0;
}
