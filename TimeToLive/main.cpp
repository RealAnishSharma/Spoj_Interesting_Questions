#include <bits/stdc++.h>

using namespace std;

vector<int> g[100001];
int my,N,mn[100001];
struct node
{
    int d,c;
};

void bfs(int s)
{
    queue<struct node> Q;
    struct node v;v.d=s;v.c=0;
    Q.push(v);

    bool vis[N+1];
    memset(vis,false,sizeof(vis));
    memset(mn,0,sizeof(mn));

    while(!Q.empty())
    {
        struct node w=Q.front();Q.pop();
        vis[w.d]=true;mn[w.d]=w.c;
        for(int i=0;i<g[w.d].size();i++)
        {
            if(!vis[g[w.d][i]]) {v.d=g[w.d][i];v.c=w.c+1;Q.push(v);}
        }
    }
    my=0;int may=0;
    for(int i=0;i<N;i++) if(may<mn[i]) {may=mn[i];my=i;}


}






int main()
{
    int t,u,v;
    scanf("%d",&t);
    while(t--)
    {
        for(int i=0;i<100001;i++) g[i].clear();

        scanf("%d",&N);
        for(int i=0;i<N-1;i++)
        {
        scanf("%d %d",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
        }

        bfs(0);
       bfs(my);
       int jj=0;
       for(int i=0;i<=N;i++)
       if(jj<mn[i]) jj=mn[i];

       if(jj%2==0) printf("%d\n",jj/2);
       else printf("%d\n",(jj+1)/2);
    }

    return 0;
}

/*
       //Floyd warshall
       int dist[N][N],INF=200000000;

       for(int i=0;i<N;i++)for(int j=0;j<N;j++) {dist[i][j]=INF;if(i==j)dist[i][j]=0;}

       for(int i=0;i<N;i++)for(int j=0;j<g[i].size();j++) dist[i][g[i][j]]=1;

       for(int k=0;k<N;k++)
       for(int i=0;i<N;i++)
       for(int j=0;j<N;j++)
       if(dist[i][j]>dist[i][k]+dist[k][j])
       dist[i][j]=dist[i][k]+dist[k][j];

       int maxo[N+1];
       memset(maxo,0,sizeof(maxo));

       for(int i=0;i<N;i++)
       for(int j=0;j<N;j++)
       if(dist[i][j]<INF&&dist[i][j]>maxo[i]) maxo[i]=dist[i][j];

       int mino=INF;
       for(int i=0;i<N;i++) if(mino>maxo[i]) mino=maxo[i];

       printf("%d\n",mino);
       */
