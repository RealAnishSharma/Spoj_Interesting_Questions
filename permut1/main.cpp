#include <bits/stdc++.h>

using namespace std;

int marr[15][1000];
/*
int fino(int n,int k)
{

    if(n==2 && (k==0||k==1)) return 1;
    if(n==2) return 0;

    int p=0;
    for(int i=1;i<=k+1;i++)
    {
      p+=fino(n-1,k-i+1);
    }
    return  p;
}
*/
void fino(int n,int k)
{
    if(n==1)
    {if(k==0) marr[n][k]=1;else marr[n][k]=0;return;}

    if(n==2 && (k==0||k==1)) {marr[n][k]=1;return;}
    if(n==2) {marr[n][k]=0;return;}

    int p=0,v=k+1;

    for(int i=1;i<=n;i++)
    {
      if(marr[n-1][k-i+1]==-1) fino(n-1,k-i+1);
      p+=marr[n-1][k-i+1];
    }
    marr[n][k]=p;
}

int main()
{
    int d;
    scanf("%d",&d);
    while(d--)
    {
        int n,k;
        scanf("%d %d",&n,&k);

        for(int i=0;i<15;i++)for(int j=0;j<1000;j++) marr[i][j]=-1;

        fino(n,k);
        printf("%d\n",marr[n][k]);
    }
    return 0;
}
