#include <bits/stdc++.h>

using namespace std;

int n;
map < string ,int> mymap;
vector< pair< int ,int > > g[10001];

int p,sol[101][2],ans[101];


struct pqn
{
    int u,dis;
};

class CompareDist
{
public:
    bool operator()(struct pqn n1,struct pqn n2) {
        return n1.dis>n2.dis;
    }
};

bool isCheck(struct pqn x,int dist[])
{
    if(dist[x.u]==x.dis) return true;
    else return false;
}


void djikstra(int src)
{
    int i;
    int dist[n+1];

    priority_queue<struct pqn,vector<struct pqn>,CompareDist> pq;

    for(i=1;i<=n;i++)
    {
        if(i==src) dist[i]=0;
        else dist[i]=INT_MAX;

        struct pqn p;
        p.u=i;
        p.dis=dist[i];
        pq.push(p);
    }


    int out[n+1];memset(out,0,sizeof(out));
    int ll=0;
    while(!pq.empty())
    {
        struct pqn ab=pq.top();pq.pop();
        int y=ab.u;

        if(ll==n) break;

        if(isCheck(ab,dist)&&out[y]==0)
        {
        ll++;
        for(int k=0;k<g[y].size();k++)
        {
            if(out[g[y][k].first]==0&&dist[y]!=INT_MAX)
            if(dist[g[y][k].first]>g[y][k].second+dist[y])
            dist[g[y][k].first]=g[y][k].second+dist[y];

            struct pqn zz;zz.u=g[y][k].first;zz.dis=dist[g[y][k].first];
            pq.push(zz);
        }

        out[y]=1;

        }

    }


    //while(!pq.empty()){struct pqn ab=pq.top();pq.pop();cout<<"->"<<ab.u<<" "<<ab.dis<<endl;}


    for(int m=0;m<p;m++)
    if(sol[m][0]==src)
    ans[m]=dist[sol[m][1]];
    else if(sol[m][1]==src)
    ans[m]=dist[sol[m][1]];

}


int main()
{
    int s;
    scanf(" %d",&s);
    while(s--)
    {
        memset(ans,-1,sizeof(ans));
        scanf(" %d",&n);
        char str[11];
        int u,v,ng;

        for(int i=0;i<10001;i++) g[i].clear();
        mymap.clear();

        for(int i=1;i<=n;i++)
        {
            scanf(" %s",str);
            mymap[str]=i;

            scanf("%d",&ng);

            for(int j=0;j<ng;j++)
            {
                scanf("%d %d",&u,&v);
                g[i].push_back(make_pair(u,v));
            }

        }

        scanf("%d",&p);

        for(int k=0;k<p;k++)
        {
            char s[11],d[11];
            scanf(" %s",s);scanf(" %s",d);
            sol[k][0]=mymap[s];
            sol[k][1]=mymap[d];
        }

        for(int k=0;k<p;k++)
        {
            if(ans[k]==-1)
            djikstra(sol[k][0]);
        }

        for(int k=0;k<p;k++) printf("%d\n",ans[k]);
    }
    return 0;
}
