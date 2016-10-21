#include <bits/stdc++.h>

using namespace std;

vector<int> g[100001];
bool vis[100001];
int N,e;

void bfs(int s)
{
   // printf("bfs in from %d\n",s);

    queue<int> Q;
    Q.push(s);

    while(!Q.empty())
    {
        int b=Q.front();Q.pop();
        vis[b]=true;
        for(int i=0;i<g[b].size();i++)
        {
            if(!vis[g[b][i]]) Q.push(g[b][i]);
        }
    }
}









int main()
{
    int t,u,v;
    scanf("%d",&t);
    while(t--)
    {
        for(int i=0;i<100001;i++) g[i].clear();
        memset(vis,false,sizeof(vis));

        scanf(" %d",&N);
        scanf(" %d",&e);

        for(int i=0;i<e;i++)
        {
            scanf(" %d %d",&u,&v);

            g[u].push_back(v);
            g[v].push_back(u);
        }


        int d=0;
        for(int i=0;i<N;i++)
        if(!vis[i])
        {bfs(i);d++;}

        printf("%d\n",d);
    }
    return 0;
}
