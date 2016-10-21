#include <bits/stdc++.h>

using namespace std;
int N,M,aa,bb,T,arr[101][101];

struct node
{
    int x,y,c;
};

class CD
{
    public:
    bool operator()(struct node n1,struct node n2)
    {
        return n1.c>n2.c;
    }
};

bool isCheck(struct node n,int cost)
{
    if(cost==n.c) return true;
    else return false;
}

void djikstra()
{
    priority_queue <struct node,vector<struct node>,CD> pq;

    int cost[101][101];

    for(int i=0;i<=M;i++)
    for(int j=0;j<=N;j++) cost[i][j]=INT_MAX;


    cost[1][1]=arr[1][1];

    struct node ab,uv;

    for(int i=1;i<=M;i++)
    for(int j=1;j<=N;j++)
    {
        ab.x=i;ab.y=j;ab.c=cost[i][j];pq.push(ab);
    }

    int ll=0,out[M+1][N+1];
    for(int i=0;i<=M;i++)for(int j=0;j<=N;j++) out[i][j]=0;


    while(!pq.empty())
    {
        uv=pq.top();pq.pop();

        if(ll==N*M) break;


        if(out[uv.x][uv.y]==0&&isCheck(uv,cost[uv.x][uv.y])&&cost[uv.x][uv.y]!=INT_MAX){
        ll++;


        if(uv.x+1<=M && out[uv.x+1][uv.y]==0 && cost[uv.x+1][uv.y]>cost[uv.x][uv.y]+arr[uv.x+1][uv.y])
        {
            cost[uv.x+1][uv.y]=cost[uv.x][uv.y]+arr[uv.x+1][uv.y];
            ab.x=uv.x+1;ab.y=uv.y;ab.c=cost[uv.x+1][uv.y];pq.push(ab);
        }

        if(uv.x-1>=1 && out[uv.x-1][uv.y]==0 && cost[uv.x-1][uv.y]>cost[uv.x][uv.y]+arr[uv.x-1][uv.y])
        {
            cost[uv.x-1][uv.y]=cost[uv.x][uv.y]+arr[uv.x-1][uv.y];
            ab.x=uv.x-1;ab.y=uv.y;ab.c=cost[uv.x-1][uv.y];pq.push(ab);
        }

        if(uv.y+1<=N && out[uv.x][uv.y+1]==0 && cost[uv.x][uv.y+1]>cost[uv.x][uv.y]+arr[uv.x][uv.y+1])
        {
            cost[uv.x][uv.y+1]=cost[uv.x][uv.y]+arr[uv.x][uv.y+1];
            ab.x=uv.x;ab.y=uv.y+1;ab.c=cost[uv.x][uv.y+1];pq.push(ab);
        }

        if(uv.y-1>=1 && out[uv.x][uv.y-1]==0 && cost[uv.x][uv.y-1]>cost[uv.x][uv.y]+arr[uv.x][uv.y-1])
        {
            cost[uv.x][uv.y-1]=cost[uv.x][uv.y]+arr[uv.x][uv.y-1];
            ab.x=uv.x;ab.y=uv.y-1;ab.c=cost[uv.x][uv.y-1];pq.push(ab);
        }

        out[uv.x][uv.y]=1;

        }

    }

    if(cost[aa][bb]<=T)
    printf("YES\n%d\n",(T-cost[aa][bb]));
    else
    printf("NO\n");
}





int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&M,&N);

        for(int i=1;i<=M;i++)
        for(int j=1;j<=N;j++)
        {
            scanf(" %d",&arr[i][j]);

        }
        scanf("%d %d %d",&aa,&bb,&T);
        djikstra();
    }
    return 0;
}
