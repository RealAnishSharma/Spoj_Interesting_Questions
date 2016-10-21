#include <bits/stdc++.h>

using namespace std;

int n,m,b,e;
struct node
{
    int d,t;
};

class CD
{
public:
    bool operator()(struct node n1,struct node n2)
    {
        return n1.t>n2.t;
    }
};

vector <struct node> g[100001];

bool isCheck(struct node k,int time[])
{
    if(k.t==time[k.d]) return true;
    else return false;
}





void djikstra()
{
    priority_queue<struct node,vector<struct node>,CD> pq;

    struct node nd;

    int time[100001];

    for(int i=1;i<=n;i++)
    time[i]=INT_MAX;

    time[b]=0;

    for(int i=1;i<=n;i++)
    {
        nd.d=i;nd.t=time[i];
        pq.push(nd);
    }

    int out[n+1],ll=0;
    memset(out,-1,sizeof(out));

    while(!pq.empty())
    {
        nd=pq.top();pq.pop();

        if(ll==n) break;

        if(out[nd.d]==-1&&isCheck(nd,time))
        {
            ll++;
            for(int k=0;k<g[nd.d].size();k++)
            {
                if(out[g[nd.d][k].d]==-1&&time[nd.d]!=INT_MAX)
                if(time[g[nd.d][k].d]>g[nd.d][k].t+time[nd.d])
                    time[g[nd.d][k].d]=g[nd.d][k].t+time[nd.d];

                    struct node c;c.d=g[nd.d][k].d;c.t=time[g[nd.d][k].d];
                    pq.push(c);
            }
              out[nd.d]=0;
        }
    }

    if(time[e]==INT_MAX)printf("NONE\n");
    else printf("%d\n",time[e]);
}







int main()
{
    int T,u,v,w;
    struct node nd;
    scanf("%d",&T);
    while(T--)
    {
        for(int i=0;i<100001;i++)
            g[i].clear();

        scanf("%d %d %d %d",&n,&m,&b,&e);

        for(int i=0;i<m;i++)
        {
            scanf(" %d %d %d",&u,&v,&w);
            nd.d=v;nd.t=w;
            g[u].push_back(nd);
            nd.d=u,nd.t=w;
            g[v].push_back(nd);
        }

        djikstra();
    }
    return 0;
}
