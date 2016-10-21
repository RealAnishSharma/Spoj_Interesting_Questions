#include <bits/stdc++.h>
#include<limits>
using namespace std;

int dest[10001],len[10001],cost[10001],src[10001],marr[101][10001];
int N;
bool vis[101];

void mino(int ds,int K,int R)
{
    if(ds==1) {marr[ds][K]=0;return;}

    int minp=((N-1)*100+1),p=minp;

    for(int i=0;i<R;i++)
    {
        if(dest[i]==ds&&vis[src[i]]==false)
        {
            vis[src[i]]=true;

            if(K-cost[i]<0)
            {
             p=((N-1)*100+1);
            }
            else
            {
            if(marr[src[i]][K-cost[i]]==-1) mino(src[i],K-cost[i],R);
            p=len[i]+marr[src[i]][K-cost[i]];
            }

            vis[src[i]]=false;
        }

        if(minp>p) minp=p;
    }
       marr[ds][K]=minp;
}

int main()
{
    int T,K,R,d;
    scanf("%d",&T);
    while(T--)
    {
        scanf(" %d%d%d",&K,&N,&R);
        for(int i=0;i<R;i++)
        {
            scanf(" %d %d %d %d",&src[i],&dest[i],&len[i],&cost[i]);
        }

        for(int i=0;i<101;i++) vis[i]=false;

        for(int j=0;j<101;j++)for(int k=0;k<10001;k++)marr[j][k]=-1;

        mino(N,K,R);
        d=marr[N][K];

        if(d>((N-1)*100)) d=-1;
        printf("%d\n",d);

    }

    return 0;
}

