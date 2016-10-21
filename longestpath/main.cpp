#include<bits/stdc++.h>
using namespace std;
vector<int> g[10001];
int maxwt[100001];
bool check[10001];

void bfs(int n)
{
    queue< pair< int,int > > Q;
    Q.push(make_pair(n,0));
    while(!Q.empty())
    {
    int x=Q.front().first;
    int wt=Q.front().second;
    check[x]=true;
    for(int i=0;i<g[x].size();i++)
    {
        if(!check[g[x][i]])
        Q.push(make_pair(g[x][i],wt+1));
    }

    maxwt[x]=wt;
    Q.pop();
    }

}

int main()
{
    int n;
    scanf("%d",&n);
    //vector< pair<int,int> > v;
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        g[a].push_back(b);
        g[b].push_back(a);
    }


    bfs(1);
    int maxroot=0;
    for(int i=1;i<=n;i++) maxroot=maxwt[maxroot]<maxwt[i]?i:maxroot;


    memset(maxwt,0,sizeof(maxwt));
    memset(check,false,sizeof(check));

    bfs(maxroot);

    int d=0;
    for(int i=1;i<=n;i++)
    d=max(d,maxwt[i]);

    printf("%d\n",d);
}
