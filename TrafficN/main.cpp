#include <bits/stdc++.h>

using namespace std;
int n,m,k,s,t;
int INF=200000000;

struct node
{
    int d,c;
};

class CD
{
public:
    bool operator()(struct node e1,struct node e2)
    {
        return e1.c>e2.c;
    }
};

bool isCheck(struct node e,int dist[])
{
    if(e.c==dist[e.d]) return true;
    else return false;
}

void djikstra(vector<struct node> g[],int* dist,int b)
{
    priority_queue<struct node,vector<struct node>,CD> pq;

    struct node ab,er;
    for(int i=1;i<=n;i++) dist[i]=INF;
    dist[b]=0;

    for(int i=1;i<=n;i++){
    ab.d=i;ab.c=dist[i];
    pq.push(ab);
    }

    int out[n+1];memset(out,-1,sizeof(out));
    int ll=0;
    while(!pq.empty())
    {
        ab=pq.top();pq.pop();
        if(ll==n) break;

        if(isCheck(ab,dist)&&out[ab.d]==-1){
        ll++;
        for(int i=0;i<g[ab.d].size();i++)
        {
            if(out[g[ab.d][i].d]==-1 && dist[ab.d]!=INF)
            if(dist[g[ab.d][i].d] > dist[ab.d]+g[ab.d][i].c)
            dist[g[ab.d][i].d]=dist[ab.d]+g[ab.d][i].c;

            er.d=g[ab.d][i].d;  er.c=dist[er.d];
            pq.push(er);
        }
        out[ab.d]=1;
        }
    }
}

int main()
{
    int T,u,v,w,fa[10001],ba[10001];
    vector<struct node> g[10001],gr[10001];
    struct node ed;
    scanf("%d",&T);
    while(T--)
    {
        for(int i=0;i<10001;i++) {g[i].clear();gr[i].clear();fa[i]=INF;ba[i]=INF;}

        scanf("%d %d %d %d %d",&n,&m,&k,&s,&t);

        for(int i=0;i<m;i++)
        {
            scanf("%d %d %d",&u,&v,&w);
            ed.d=v; ed.c=w;
            g[u].push_back(ed);
            ed.d=u;
            gr[v].push_back(ed);
        }

        djikstra(g,fa,s);
        djikstra(gr,ba,t);

        int ans=min(fa[t],ba[s]);
        for(int i=0;i<k;i++)
        {
            scanf("%d %d %d",&u,&v,&w);
            ans=min(ans,min(fa[u]+w+ba[v],ba[u]+w+fa[v]));
        }
        if(ans==INF) printf("-1\n");else printf("%d\n",ans);

    }
    return 0;
}
