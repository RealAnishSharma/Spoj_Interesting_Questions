#include <bits/stdc++.h>

using namespace std;
int M,wt[55],vl[55],marr[55][1001];

void maxo(int b,int e,int K)
{
    if(b>e) {marr[b][K]=0;return;}

    if(b==e){if(K>=wt[b])marr[b][K]=vl[b];else marr[b][K]=0;return;}

    if(K-wt[b]>=0)
    {
    if(marr[b+1][K-wt[b]]==-1) maxo(b+1,e,K-wt[b]);
    if(marr[b+1][K]==-1) maxo(b+1,e,K);
    marr[b][K]=max(marr[b+1][K-wt[b]]+vl[b],marr[b+1][K]);
    return;
    }
    else
    {
        if(marr[b+1][K]==-1) maxo(b+1,e,K);
        marr[b][K]=marr[b+1][K];
        return;
    }
}



int main()
{
    int N,K;
    scanf("%d",&N);
    while(N--)
    {
        scanf("%d%d",&K,&M);
        for(int i=0;i<M;i++)
            scanf("%d%d",&wt[i],&vl[i]);

        for(int i=0;i<55;i++)for(int j=0;j<1001;j++)marr[i][j]=-1;

        maxo(0,M-1,K);
       printf("Hey stupid robber, you can get %d.\n",marr[0][K]);
  //        printf("Hey stupid robber, you can get %d.\n",maxo(0,M,K));

    }
    return 0;
}


/*
int maxo(int b,int e,int K)
{
    if(K<0) return 0;
    if(b>e) return 0;
    if(K<wt[b]) return maxo(b+1,e,K);

    if(b==e)
    if(K>=wt[b])return vl[b];else return 0;

    return max(maxo(b+1,e,K-wt[b])+vl[b],maxo(b+1,e,K));
}
*/
