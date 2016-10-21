#include <bits/stdc++.h>

using namespace std;
int C,R,a,b;
char arr[1001][1001];

int bfs(int x,int y)
{
    int cnt[R][C];bool check[R][C];
    for(int i=0;i<R;i++)for(int j=0;j<C;j++){cnt[i][j]=-1;check[i][j]=false;}
    cnt[x][y]=0;
    queue< pair < int,int > > Q;
    Q.push(make_pair(x,y));

    while(!Q.empty())
    {
        pair<int,int> p;
        p=Q.front();

        check[p.first][p.second]=true;

        if(p.first+1<R && arr[p.first+1][p.second]=='.' && !check[p.first+1][p.second] /*&& cnt[p.first+1][p.second]<cnt[p.first][p.second]+1*/)
        {
            Q.push(make_pair(p.first+1,p.second));
            cnt[p.first+1][p.second]=1+cnt[p.first][p.second];
        }

        if(p.first-1>=0 && arr[p.first-1][p.second]=='.' &&  !check[p.first-1][p.second]/*&& cnt[p.first-1][p.second]<cnt[p.first][p.second]+1*/)
        {
            Q.push(make_pair(p.first-1,p.second));
            cnt[p.first-1][p.second]=1+cnt[p.first][p.second];
        }

        if(p.second+1<C && arr[p.first][p.second+1]=='.' &&  !check[p.first][p.second+1] /*&&cnt[p.first][p.second+1]<cnt[p.first][p.second]+1*/)
        {
            Q.push(make_pair(p.first,p.second+1));
            cnt[p.first][p.second+1]=1+cnt[p.first][p.second];
        }

        if(p.second-1>=0 && arr[p.first][p.second-1]=='.' &&  !check[p.first][p.second-1] /*&&cnt[p.first][p.second-1]<cnt[p.first][p.second]+1*/)
        {
            Q.push(make_pair(p.first,p.second-1));
            cnt[p.first][p.second-1]=1+cnt[p.first][p.second];
        }

        Q.pop();
    }

    int maxo=0;
    for(int i=0;i<R;i++)
    for(int j=0;j<C;j++)
    {
        if(maxo<cnt[i][j])
        {
            maxo=cnt[i][j];a=i;b=j;
        }
    }

    return maxo;
}

int main()
{
    int T,i,j,flag;
    scanf("%d",&T);
    while(T--)
    {
        flag=0;
        scanf("%d %d",&C,&R);

        for(int u=0;u<R;u++)
            scanf(" %s",arr[u]);


        for(i=0;i<R;i++){
        for(j=0;j<C;j++)
        {if(arr[i][j]=='.') {flag=1;break;}}
        if(flag==1) break;
        }

        bfs(i,j);


        printf("Maximum rope length is %d.\n",bfs(a,b));
    }
    return 0;
}
