#include <bits/stdc++.h>

using namespace std;
int N,M;
bool vis[10001];

vector<int> g[20001];

bool isCycle(int b,int p)
{
    vis[b]=true;

    for(int i=0;i<g[b].size();i++)
    {
        if(!vis[g[b][i]])
        {
            if(isCycle(g[b][i],b)) return true;
        }

        else if(g[b][i]!=p) return true;
    }

    return false;
}

bool isTree()
{
    memset(vis,false,sizeof(vis));

   if(isCycle(1,-1)) return false;

    for(int i=1;i<=N;i++)
        if(!vis[i]) return false;

    return true;
}

int main()
{
    int u,v;
    for(int i=0;i<20001;i++) g[i].clear();

    scanf("%d %d",&N,&M);

    for(int i=0;i<M;i++)
    {
        scanf("%d %d",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }

    if(isTree()) printf("YES\n");
    else printf("NO\n");

    return 0;
}
