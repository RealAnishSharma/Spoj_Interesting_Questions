#include <bits/stdc++.h>

using namespace std;
int marr[1001][1001];
/*
int maxo(int arr[],int b,int e,int K)
{
    if(K<0) return 0;
    if(b>e) return 0;
    if(b==e) if(arr[b]<=K) return arr[b]; else return 0;

    if(K<arr[b]) return maxo(arr,b+1,e,K);

    return max(arr[b]+maxo(arr,b+2,e,K-arr[b]),maxo(arr,b+1,e,K));
}

*/
void maxo(int arr[],int b,int e,int K)
{


    if(b>e) {marr[K][b]=0;return;}
    if(b==e) {if(arr[b]<=K) marr[K][b]=arr[b];else marr[K][b]=0;return;}

    if(K-arr[b]>=0)
    {
    if(marr[K-arr[b]][b+2]==-1) maxo(arr,b+2,e,K-arr[b]);
    if(marr[K][b+1]==-1) maxo(arr,b+1,e,K);
    marr[K][b]=max(arr[b]+marr[K-arr[b]][b+2],marr[K][b+1]);
    }
    else
    {
     if(marr[K][b+1]==-1) maxo(arr,b+1,e,K);
     marr[K][b]=marr[K][b+1];
    }
}

int main()
{
    int N,K,T,vv=1;
    scanf("%d",&T);
    while(T--)
    {
        scanf(" %d%d",&N,&K);
        int arr[N];
        for(int u=0;u<1001;u++)for(int v=0;v<1001;v++)marr[u][v]=-1;
        for(int i=0;i<N;i++) scanf(" %d",&arr[i]);
        maxo(arr,0,N-1,K);
        printf("Scenario #%d: %d\n",vv++,marr[K][0]);
      // printf("Scenario #%d: %d",vv++,maxo(arr,0,N-1,K));
    }
    return 0;
}
