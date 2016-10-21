#include <bits/stdc++.h>

#define FOR(i,m) for(int i=0;i<m;i++)
#define clearo for(int ii=0;ii<101;ii++)for(int jj=0;jj<101;jj++) {road[ii][jj]=1e9;dist[ii][jj]=1e9;}

using namespace std;

int n,m,B,V=101;
int road[101][101],dist[101][101],ord[6][3],marr[101];

int minko(int b,int e,int i)
{
    int d=dist[ord[i][0]][ord[i][1]],mind=1e5,flg=0;
    for(int j=b;j<=e;j++)
    {
        if(ord[j][2]==0) {flg++;continue;}
        if(ord[j][2]!=0)
        {ord[j][2]--;

        d=d+minko(b,e,j)+dist[ord[i][1]][ord[j][0]];
        ord[j][2]++;}
        if(mind>d) mind=d;
    }

    if(flg==e-b+1) {d+=dist[ord[i][1]][B];mind=d;}
    return mind;
}

int mino(int b,int e)
{
    int minp=1e9,p=0;
    for(int i=b;i<=e;i++)
    {
        ord[i][2]--;
        p=minko(b,e,i)+dist[B][ord[i][0]];
        ord[i][2]++;
        if(p<minp) minp=p;
     //   printf("i=%d p=%d\n",i,p);
    }
    return minp;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        clearo;memset(marr,-1,sizeof(marr));
        int i,j,k,u,v,r,z;
        scanf(" %d %d %d",&n,&m,&B);

        FOR(i,m){
        scanf(" %d %d %d",&u,&v,&r);
        if(r<road[u][v]||r<road[v][u]){road[u][v]=r;road[v][u]=r;}
        }

        scanf("%d",&z);
        FOR(i,z) scanf(" %d %d %d",&ord[i][0],&ord[i][1],&ord[i][2]);

        //Floyd's algoritm
        for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
        dist[i][j] = road[i][j];

        for(i=1;i<=n;i++) dist[i][i]=0;

        for (k = 1; k <= n; k++)
        for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
        if (dist[i][k] + dist[k][j] < dist[i][j])
        dist[i][j] = dist[i][k] + dist[k][j];
        //

       /* for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            printf("%d\t",dist[i][j]);
            printf("\n");
        }
*/
        printf("%d\n",mino(0,z-1));
    }
    return 0;
}
