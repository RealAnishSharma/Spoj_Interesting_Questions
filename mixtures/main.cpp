#include <bits/stdc++.h>
#include <limits>
using namespace std;
int marr[101][101],carr[101][101];

int mino(int arr[],int b,int e)
{
    if(b==e) {marr[b][e]=0;return 0;}

    int p,k,minp=INT_MAX;

    for(k=b;k<e;k++)
    {
        if(marr[b][k]==-1) mino(arr,b,k);
        if(marr[k+1][e]==-1) mino(arr,k+1,e);

        p=marr[b][k]+marr[k+1][e]+carr[b][k]*carr[k+1][e];
        if(minp>p) minp=p;
    }
    marr[b][e]=minp;
    return marr[b][e];
}

int main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
        int arr[n];
        for(int i=0;i<n;i++) scanf(" %d",&arr[i]);

        for(int i=0;i<101;i++)for(int j=0;j<101;j++){marr[i][j]=-1;carr[i][j]=-1;}

        for(int i = 0;i < n;++i) carr[i][i] = arr[i];
        for(int i = 0;i < n;++i){
            for(int j = i+1;j < n;++j){
                carr[i][j] = carr[i][j-1] + arr[j];
                if(carr[i][j] >= 100) carr[i][j] -= 100;
            }
        }

        printf("%d\n",mino(arr,0,n-1));
    }
    return 0;
}




/*
int mino(int arr[],int b,int e)
{
    if(b==e) return 0;
    int p,k,minp=INT_MAX;
    for(k=b;k<e;k++)
    {
        int i,arr1[e];
        for(i=b;i<k;i++) arr1[i]=arr[i];
        arr1[k]=(arr[k]+arr[k+1])%100;
        for(i=k+2;i<=e;i++) arr1[i-1]=arr[i];

        p=mino(arr1,b,e-1)+arr[k]*arr[k+1];


        if(p<minp) minp=p;
    }
    return minp;
}

int mino(int arr[],int b,int e)
{
    if(b==e) return 0;
    int p,k,minp=INT_MAX;

    for(k=b;k<e;k++)
    {
        p=mino(arr,b,k)+mino(arr,k+1,e)+csum(arr,b,k)*csum(arr,k+1,e);
        if(minp>p) minp=p;
    }
    return minp;
}


void csum(int arr[],int i,int j)
{
    int sum=0;
    for(int k=i;k<=j;k++) sum+=arr[k];
    carr[i][j]=sum%100;
}
*/
