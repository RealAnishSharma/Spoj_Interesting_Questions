#include <bits/stdc++.h>

using namespace std;
int V,K,s,e;

struct node
{
    int d,c;
};

class CD
{
public:
    bool operator()(struct node n1,struct node n2)
    {return n1.c>n2.c;}
};



vector<struct node> g[10001];


bool isCheck(struct node n,int dist[])
{
    if(dist[n.d]==n.c) return true;
    else return false;
}

void djikstra()
{
    priority_queue<struct node,vector<struct node>,CD> pq;

    int dist[10001],out[10001];
    struct node ab;

    for(int i=1;i<=10001;i++)
    {
        dist[i]=INT_MAX;
    }

    dist[s]=0;

    for(int i=1;i<=V;i++)
    {
        ab.d=i , ab.c=dist[i];
        pq.push(ab);
    }

    memset(out,0,sizeof(out));

    int ll=0;
    while(!pq.empty())
    {
        if(ll==V) break;
        ab=pq.top();pq.pop();

        if(out[ab.d]==0&&isCheck(ab,dist))
        {
            ll++;
            for(int k=0;k<g[ab.d].size();k++)
            {
                if(out[g[ab.d][k].d]==0&&dist[ab.d]!=INT_MAX)
                if(dist[g[ab.d][k].d]>dist[ab.d]+g[ab.d][k].c)
                dist[g[ab.d][k].d]=dist[ab.d]+g[ab.d][k].c;

                struct node ff; ff.c=dist[g[ab.d][k].d]; ff.d=g[ab.d][k].d;
                pq.push(ff);
            }
            out[ab.d]=1;
        }
    }


   // for(int i=1;i<=V;i++)
     //   printf("->%d  %d\n",i,dist[i]);

    if(dist[e]!=INT_MAX) printf("%d\n",dist[e]);
    else printf("NO\n");
}

int main()
{
    int t,u,v,w;
    scanf(" %d",&t);
    while(t--)
    {
        for(int i=0;i<10001;i++) g[i].clear();

        scanf(" %d %d",&V,&K);
        for(int i=0;i<K;i++)
        {
            scanf("%d %d %d",&u,&v,&w);
            struct node p;
            p.d=v;p.c=w;

            g[u].push_back(p);
        }

        scanf("%d %d",&s,&e);
        djikstra();
    }

    return 0;
}
