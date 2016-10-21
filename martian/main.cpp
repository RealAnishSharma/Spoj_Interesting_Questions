#include <bits/stdc++.h>
#include <limits>
using namespace std;

int yey[501][501],blo[501][501],marr[600][600];


void maxo(int r,int c)
{
    int sumy=0,sumb=0;

    if(r==0&&c==0) {marr[r][c]=max(yey[0][0],blo[0][0]);return;}

    for(int i=0;i<=c;i++) sumy+=yey[r][i];
    for(int i=0;i<=r;i++) sumb+=blo[i][c];

    if(r-1>=0&&c-1>=0)
    {
        if(marr[r-1][c]==-1) maxo(r-1,c);
        if(marr[r][c-1]==-1) maxo(r,c-1);
        marr[r][c]=max(marr[r-1][c]+sumy,marr[r][c-1]+sumb);
        return;
    }
    else if(r-1>=0&&c-1<0)
    {
        if(marr[r-1][c]==-1) maxo(r-1,c);
        marr[r][c]=max(marr[r-1][c]+sumy,sumb);
        return;
    }
    else if(r-1<0 && c-1>=0)
    {
        if(marr[r][c-1]==-1) maxo(r,c-1);
        marr[r][c]=max(sumy,marr[r][c-1]+sumb);
        return;
    }
    else
    {
        marr[r][c]=max(sumy,sumb);
        return;
    }
}

int main()
{
    int n,m;
    while(1)
    {
        scanf(" %d%d",&n,&m);

        if(n==0&&m==0) break;

        for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        scanf("%d",&yey[i][j]);

        for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        scanf("%d",&blo[i][j]);

        for(int i=0;i<600;i++)
        for(int j=0;j<600;j++)
        marr[i][j]=-1;

       // printf("%d\n",maxo(n,m));
        maxo(n-1,m-1);
        printf("%d\n",marr[n-1][m-1]);
    }
    return 0;
}




/*

int maxo(int r,int c)
{
    if(r<0||c<0) return 0;

    int sumy=0,sumb=0;

    for(int i=0;i<c;i++) sumy+=yey[r-1][i];
    for(int i=0;i<r;i++) sumb+=blo[i][c-1];

    return max(maxo(r-1,c)+sumy,maxo(r,c-1)+sumb);
}

*/
