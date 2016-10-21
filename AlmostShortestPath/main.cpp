#include <bits/stdc++.h>

using namespace std;
int n,m,e,minq;
struct node
{
    int d,c;
};
struct dnd
{
    int dis;
    vector< pair<int,int> > p;
};

int arr[10001][2],f=0;


vector<struct node> g[501];

class CD
{
public:
    bool operator()(struct node a,struct node b)
    {
        return a.c>b.c;
    }
};


bool isCheck(struct node n,struct dnd dist[])
{
    if(n.c==dist[n.d].dis) return true;
    else return false;
}

int  djikstra(int s)
{

    priority_queue<struct node,vector<struct node>,CD> pq;

    struct dnd dist[n+1];
    for(int i=0;i<n;i++)
    {
        dist[i].dis=INT_MAX;
        dist[i].p.clear();
    }

    dist[s].dis=0;dist[s].p.push_back(make_pair(s,s));
    struct node ab;
    for(int i=0;i<n;i++)
    {
        ab.d=i;
        ab.c=dist[i].dis;
        pq.push(ab);
    }


    int ll=0,out[n];memset(out,0,sizeof(out));

    while(!pq.empty())
    {
        ab=pq.top();pq.pop();


        if(ll==n) break;
        if(out[ab.d]==0&&isCheck(ab,dist))
        {
            ll++;
            for(int i=0;i<g[ab.d].size();i++)
            {
                if(out[g[ab.d][i].d]==0&&dist[ab.d].dis!=INT_MAX)
                if(dist[g[ab.d][i].d].dis>dist[ab.d].dis+g[ab.d][i].c)
                {
                    dist[g[ab.d][i].d].dis=dist[ab.d].dis+g[ab.d][i].c;
                    dist[g[ab.d][i].d].p=dist[ab.d].p;
                    dist[g[ab.d][i].d].p.push_back(make_pair(ab.d,g[ab.d][i].d));
                }
                struct node hg; hg.d=g[ab.d][i].d ; hg.c=dist[g[ab.d][i].d].dis;
                pq.push(hg);
            }
            out[ab.d]=1;
        }
    }


//for(int i=0;i<dist[e].p.size();i++) printf("path:(%d,%d)->",dist[e].p[i].first,dist[e].p[i].second);printf("\nvalue->%d\n",dist[e].dis);



    for(int i=1;i<dist[e].p.size();i++)
    for(int j=0;j<g[dist[e].p[i].first].size();j++)
    if(g[dist[e].p[i].first][j].d==dist[e].p[i].second)
    {
        //g[dist[e].p[i].first][j].c=1e8;
        arr[f][0]=dist[e].p[i].first;
        arr[f][1]=j;
        f++;
        break;
    }








  //printf("%d",dist[e].dis);
    return dist[e].dis;

}








int main()
{
    int u,v,w;

    while(1){

    for(int i=0;i<501;i++) g[i].clear();

    scanf(" %d %d",&n,&m);
    if(n==0&&m==0) break;

    scanf(" %d %d",&s,&e);

    for(int i=0;i<m;i++)
    {
        scanf(" %d %d %d",&u,&v,&w);

        struct node ap;ap.d=v;ap.c=w;
        g[u].push_back(ap);
    }
    int vb;
    minq=djikstra(s);



    while(1)
    {
        vb=djikstra(s);
        if(vb>=1e8) break;
        if(vb>minq) break;
    }
    if(vb>=1e8) printf("-1\n");
    else printf("%d\n",vb);
    }

    return 0;
}
