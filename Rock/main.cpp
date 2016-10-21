#include <bits/stdc++.h>
#include <limits>
using namespace std;
char carr[201];
int arr[201];
int marr[201][201];

void maxo(int b,int e)
{
    if(b==e) {marr[b][e]=arr[b];return;}

    int mm=0;
    for(int i=b;i<=e;i++)if(arr[i]==1) mm++;if(mm>(e-b+1-mm)) {marr[b][e]=e-b+1;return;}

    int p,maxp=INT_MIN;

    for(int i=b;i<e;i++)
    {
        if(marr[b][i]==-1) maxo(b,i);
        if(marr[i+1][e]==-1) maxo(i+1,e);
        p=marr[b][i]+marr[i+1][e];
        if(p>maxp) maxp=p;
    }

    marr[b][e]=maxp;
    return;
}

int main()
{
    int t,n;

    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        scanf(" %s",carr);
        for(int i=0;i<n;i++) arr[i]=(int)carr[i]-48;

        for(int i=0;i<201;i++)for(int j=0;j<201;j++)marr[i][j]=-1;

     //   printf("%d\n",maxo(0,n-1));
     maxo(0,n-1);
     printf("%d\n",marr[0][n-1]);
    }
    return 0;
}

/*
int maxo(int b,int e)
{
    if(b==e) return arr[b];

    int mm=0;
    for(int i=b;i<=e;i++)if(arr[i]==1) mm++;if(mm>(e-b+1-mm)) return (e-b+1);

    int p,maxp=INT_MIN;

    for(int i=b;i<e;i++)
    {
        int u=0,v=0,s=0;
        for(int k=b;k<=i;k++)if(arr[k]==1) u++;if(u>(i-b-u+1)) s++;
        for(int k=i+1;k<=e;k++)if(arr[k]==1) v++; if(v>(e-i-v)) s++;

        p=maxo(b,i)+maxo(i+1,e);

        if(p>maxp) maxp=p;
    }

    return maxp;
}
*/
