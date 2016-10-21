#include <bits/stdc++.h>
using namespace std;

int n,m;

struct node
{
    int d;
    double p;
};

vector<struct node>g[101];

class CD
{
public:
    bool operator()(struct node n1,struct node n2)
    {return n2.p>n1.p;}
};

bool isCheck(struct node n,double disp[])
{
    if(disp[n.d]==n.p) return true;
    else return false;
}

void djikstra()
{
    priority_queue<struct node,vector<struct node>,CD> pq;

    double disp[101];
    struct node nd;

    for(int i=0;i<101;i++)
    disp[i]=0.0;

    disp[1]=1.0;

    for(int i=1;i<=n;i++)
    {
        nd.d=i;nd.p=disp[i];
        pq.push(nd);
    }

    int ll=0,out[101];memset(out,0,sizeof(out));

    while(!pq.empty())
    {
        nd=pq.top();pq.pop();
        if(ll==n) break;

        if(out[nd.d]==0&&isCheck(nd,disp))
        {

            ll++;
            for(int i=0;i<g[nd.d].size();i++)
            {
                if(out[g[nd.d][i].d]==0&&disp[nd.d]!=0)
                if(disp[g[nd.d][i].d] < (disp[nd.d]*g[nd.d][i].p))
                disp[g[nd.d][i].d]=(disp[nd.d]*g[nd.d][i].p);

                struct node hj; hj.d=g[nd.d][i].d; hj.p=disp[g[nd.d][i].d];
                pq.push(hj);
            }
            out[nd.d]=1;
        }
    }

    printf("%.6lf percent\n",disp[n]*100);
}

int main()
{
    int u,v,w;
    struct node hk;
    while(1){

    for(int i=0;i<101;i++) g[i].clear();

    scanf("%d",&n);
    if(n==0) break;
    scanf("%d",&m);

    for(int i=0;i<m;i++)
    {
        scanf(" %d %d %d",&u,&v,&w);
        hk.d=v,hk.p=w/100.0;
        g[u].push_back(hk);
        hk.d=u;//,hk.p=((float)w)/(float)100;
        g[v].push_back(hk);
    }

    djikstra();

    }
    return 0;
}








