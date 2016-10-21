#include <bits/stdc++.h>

using namespace std;

int d,n,m;
char arr[190][190];
int ans[190][190];
struct node
{
    int x,y;
};

void bfs()
{
    queue<struct node> Q;
    struct node ab,pq;

    for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
    {
        if(arr[i][j]=='1'){
        ab.x=i;
        ab.y=j;
        ans[i][j]=0;
        Q.push(ab);
    }}


    while(!Q.empty())
    {
        ab=Q.front(); Q.pop();

        if(ab.x+1<n&&ans[ab.x+1][ab.y]>ans[ab.x][ab.y]+1)
            {pq.x=ab.x+1;pq.y=ab.y;Q.push(pq);ans[ab.x+1][ab.y]=ans[ab.x][ab.y]+1;}
        if(ab.y+1<m&&ans[ab.x][ab.y+1]>ans[ab.x][ab.y]+1)
            {pq.x=ab.x;pq.y=ab.y+1;Q.push(pq);ans[ab.x][ab.y+1]=ans[ab.x][ab.y]+1;}
        if(ab.x-1>=0&&ans[ab.x-1][ab.y]>ans[ab.x][ab.y]+1)
            {pq.x=ab.x-1;pq.y=ab.y;Q.push(pq);ans[ab.x-1][ab.y]=ans[ab.x][ab.y]+1;}
        if(ab.y-1>=0&&ans[ab.x][ab.y-1]>ans[ab.x][ab.y]+1)
            {pq.x=ab.x;pq.y=ab.y-1;Q.push(pq);ans[ab.x][ab.y-1]=ans[ab.x][ab.y]+1;}
    }
}


int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&m);
        for(int j=0;j<n;j++)
        scanf(" %s",arr[j]);

        for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        ans[i][j]=100000000;

        bfs();

        for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
        {
          printf("%d ",ans[i][j]);
        }printf("\n");}

    }
    return 0;
}


