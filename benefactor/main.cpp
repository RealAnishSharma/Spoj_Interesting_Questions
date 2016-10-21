#include <bits/stdc++.h>

using namespace std;
int n;

vector < pair< int,int > >g[50001];
int mwt[500001];bool check[500001];


void bfs(int n)
{
    queue< pair< int , int > > Q;
    Q.push(make_pair(n,0));

    while(!Q.empty())
    {
        int x=Q.front().first;
        int wt=Q.front().second;
        check[x]=true;
        for(int i=0;i<g[x].size();i++)
        {
            if(!check[g[x][i].first])
                Q.push(make_pair(g[x][i].first,g[x][i].second+wt));
        }

        mwt[x]=wt;
        Q.pop();
    }

}


int main()
{
    int t;
    scanf(" %d",&t);
    while(t--)
    {
        for(int i=0;i<50001;i++)
        g[i].clear();

        scanf("%d",&n);
        for(int i=0;i<n-1;i++)
        {
            int u,v,l;
            scanf(" %d %d %d",&u,&v,&l);
            g[u].push_back(make_pair(v,l));
            g[v].push_back(make_pair(u,l));
        }

        memset(check,false,sizeof(check));
        memset(mwt,0,sizeof(mwt));

        bfs(1);
        int maxroot=0;
        for(int i=1;i<=n;i++) maxroot=mwt[maxroot]<mwt[i]?i:maxroot;


        memset(check,false,sizeof(check));
        memset(mwt,0,sizeof(mwt));

        bfs(maxroot);

        int d=0;
        for(int i=1;i<=n;i++)
            d=max(d,mwt[i]);

        printf("%d\n",d);
    }
    return 0;
}

