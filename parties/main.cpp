#include <bits/stdc++.h>

using namespace std;
int cost[101],fun[101],N;
int marr[501][101],karr[501][101];

void maxo(int K,int b)
{
    if(b>N-1){marr[K][b]=0;karr[K][b]=0;return;}

    if(b==N-1) {if(K>=cost[b]) {marr[K][b]=fun[b];karr[K][b]=cost[b];}else {marr[K][b]=0;karr[K][b]=0;}return;}


    if(K-cost[b]>=0)
    {
        if(marr[K-cost[b]][b+1]==-1) maxo(K-cost[b],b+1);
        if(marr[K][b+1]==-1) maxo(K,b+1);

        int u,v;
        u=marr[K-cost[b]][b+1]+fun[b];
        v=marr[K][b+1];

        if(u>v)
        {
           marr[K][b]=u;karr[K][b]=cost[b]+karr[K-cost[b]][b+1];
        }
        else if(u==v)
        {
            if(karr[K][b+1]<cost[b]+karr[K-cost[b]][b+1]) karr[K][b]=karr[K][b+1];
            else karr[K][b]=cost[b]+karr[K-cost[b]][b+1];

            marr[K][b]=u;
        }
        else
        {
            marr[K][b]=v;karr[K][b]=karr[K][b+1];
        }
        return;
    }
    else
    {
        if(marr[K][b+1]==-1) maxo(K,b+1);
        marr[K][b]=marr[K][b+1];
        karr[K][b]=karr[K][b+1];
        return;
    }
}


int main()
{
    while(1)
    {
        int K;
        scanf("%d %d",&K,&N);
        if(K==0 && N==0) break;

        for(int i=0;i<N;i++)
            scanf("%d %d",&cost[i],&fun[i]);

        for(int i=0;i<501;i++)for(int j=0;j<101;j++){marr[i][j]=-1;karr[i][j]=0;}

        maxo(K,0);
        printf("%d %d\n",karr[K][0],marr[K][0]);

    }
    return 0;
}

/*
int maxo(int K,int b)
{
    if(K<0) return 0;
    if(b>N-1) return 0;
    if(K<cost[b]) return maxo(K,b+1);

    if(b==N-1) {if(K-cost[N-1]>=0) return fun[b];else return 0;}


    int a=maxo(K-cost[b],b+1)+fun[b];
    int q=maxo(K,b+1);

    return max(a,q);
}

*/
