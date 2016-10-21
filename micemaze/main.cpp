#include <bits/stdc++.h>

using namespace std;

int N,e,T,M,d=0;
vector<struct node> g[101];

struct node
{
    int x,c;
};


class CD
{
public:
    bool operator()(struct node n1,struct node n2)
    {
        return n1.c>n2.c;
    }
};

bool isCheck(struct node n,int cost[])
{
    if(n.c==cost[n.x]) return true;
    else return false;
}

void djikstra(int r)
{
    priority_queue< struct node,vector<struct node>,CD > pq;

    int cost[101];//memset(cost,INT_MAX,sizeof(int)*101);
    for(int i=1;i<=N;i++) cost[i]=INT_MAX;
    cost[r]=0;

    struct node ab,uv;

    for(int i=1;i<=N;i++)
    {
        ab.x=i;ab.c=cost[i];pq.push(ab);
    }

    int ll=0,out[101];memset(out,0,sizeof(out));

    while(!pq.empty())
    {
        uv=pq.top();pq.pop();

        //printf("->%d %d\n",uv.x,uv.c);
       // if(uv.x==e) break;
        if(ll==N) break;

        if(out[uv.x]==0&&isCheck(uv,cost))
        {
            ll++;
            for(int i=0;i<g[uv.x].size();i++)
            {
                if(out[g[uv.x][i].x]==0&&cost[uv.x]!=INT_MAX)
                if(cost[g[uv.x][i].x]>cost[uv.x]+g[uv.x][i].c)
                cost[g[uv.x][i].x]=cost[uv.x]+g[uv.x][i].c;

                ab.x=g[uv.x][i].x;ab.c=cost[g[uv.x][i].x];pq.push(ab);
            }
            out[uv.x]=1;
        }
    }
    if(cost[e]<=T) d++;
}



int main()
{
    int u,v,w;
    scanf(" %d %d %d %d",&N,&e,&T,&M);

    for(int i=0;i<101;i++) g[i].clear();

    for(int i=0;i<M;i++)
    {
        scanf(" %d %d %d",&u,&v,&w);

        struct node m;m.x=v,m.c=w;
        g[u].push_back(m);
    }

    d=0;
    for(int i=1;i<=N;i++)
    djikstra(i);

    printf("%d\n",d);
    return 0;
}
