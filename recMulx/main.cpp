#include <bits/stdc++.h>

using namespace std;
/*
//Chap1//
int MCO(int p[],int n)
{
    int m[n][n];
    int i,j,k,L,q;


    for(i=1;i<n;i++) m[i][i]=0;

    for(L=2;L<n;L++)
    {
        for(i=1;i<=n;i++)
        {
            j=i+L-1;
            m[i][j]=INT_MAX;
            for(k=i;k<=j-1;k++)
            {
                q=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
                if(q<m[i][j]) m[i][j]=q;
            }
        }
    }

    return m[1][n-1];
}

int main()
{
    int arr[]={1,2,3,4};
    int size=sizeof(arr)/sizeof(arr[0]);

    cout<<"Minimum number of multiplication is"<<MCO(arr,size);
    return 0;
}
*/

int knapsack(int W,int wt[],int val[],int n)
{
    int i,j,dp[n+1][n+1];

    for(i=0;i<=n;i++) dp[i][0]=0;
    for(j=0;j<=n;j++) dp[0][j]=0;

    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(wt[j]==0) dp[i][j]=0;
            else if(wt[j]>W) dp[i][j]=dp[i][j-1];
            else dp[i][j]=max(val[i]+dp[i-wt[i]][j-1],dp[i][j-1]);
        }
    }
    return dp[n][n];
}








int main()
{
    int val[]={60,100,120};
    int wt[]={10,20,30};
    int n=sizeof(val)/sizeof(val[0]);
    int W=50;
    printf("%d",knapsack(W,wt,val,n));
    return 0;
}














