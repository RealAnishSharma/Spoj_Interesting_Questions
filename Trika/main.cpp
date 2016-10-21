#include <bits/stdc++.h>

using namespace std;
int arr[21][21];
int marr[25][25][101];
int N,M;

void maxo(int x,int y,int p)
{
    if(p==0&&!(x==N-1&&y==N-1)) {marr[x][y][p]=INT_MIN;return;}
    if(x>=N||y>=M) {marr[x][y][p]=INT_MIN;return;}

    if(x==N-1&&y==M-1)
    {marr[x][y][p]=p;return;}

    if(p-arr[x+1][y]>=0&&p-arr[x][y+1]>=0)
    {
         if(marr[x+1][y][p-arr[x+1][y]]==-1) maxo(x+1,y,p-arr[x+1][y]);
         if(marr[x][y+1][p-arr[x][y+1]]==-1) maxo(x,y+1,p-arr[x][y+1]);
         marr[x][y][p]=max(marr[x+1][y][p-arr[x+1][y]],marr[x][y+1][p-arr[x][y+1]]);return;
    }
    else if(p-arr[x+1][y]>=0&&p-arr[x][y+1]<0)
    {
         if(marr[x+1][y][p-arr[x+1][y]]==-1) maxo(x+1,y,p-arr[x+1][y]);
         marr[x][y][p]=marr[x+1][y][p-arr[x+1][y]];
         return;
    }
    else if(p-arr[x+1][y]<0&&p-arr[x][y+1]>=0)
    {
         if(marr[x][y+1][p-arr[x][y+1]]==-1) maxo(x,y+1,p-arr[x][y+1]);
         marr[x][y][p]=marr[x][y+1][p-arr[x][y+1]];
         return;
    }
    else
    {
        marr[x][y][p]=INT_MIN;return;
    }
}


int main()
{
    int X,Y;
    scanf("%d %d %d %d",&N,&M,&X,&Y);

    for(int i=0;i<N;i++)
    for(int j=0;j<M;j++)
    scanf("%d",&arr[i][j]);

    for(int i=0;i<25;i++)
    for(int j=0;j<25;j++)
    for(int k=0;k<101;k++)
    marr[i][j][k]=-1;

    maxo(X-1,Y-1,arr[X-1][Y-1]);
    if(marr[X-1][Y-1][arr[X-1][Y-1]]>=0) printf("Y %d\n",marr[X-1][Y-1][arr[X-1][Y-1]]);
    else printf("N\n");

    return 0;
}

/*
int maxo(int x,int y,int p)
{
    if(x>=N||y>=M) return INT_MIN;

    if(x==N-1&&y==M-1) return p;//arr[N-1][M-1];

    return max(maxo(x+1,y,p-arr[x+1][y]),maxo(x,y+1,p-arr[x][y+1]));
}
*/
