#include <bits/stdc++.h>
using namespace std;

vector<int> g[5001],g_rev[5001];
stack<int> st;
int n,e,vis[5001],gro[5001];

void dfs_a(vector<int> G[],int s)
{
    vis[s]=1;
    for(int i=0;i<G[s].size();i++)
    if(vis[G[s][i]]==0)
    dfs_a(G,G[s][i]);

    st.push(s);
}

void dfs_b(vector<int> G[],int s,int cnt)
{
    vis[s]=0;
    for(int i=0;i<G[s].size();i++)
    if(vis[G[s][i]]==1)
    dfs_b(G,G[s][i],cnt);

    gro[s]=cnt;
}

void kosaraju()
{
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=n;i++) if(vis[i]==0) dfs_a(g,i);

    bool ans[5001];
    int v,cnt=0;

    while(!st.empty())
    {
        v=st.top();st.pop();
        if(vis[v]==1)
        {
            dfs_b(g_rev,v,cnt);
            ans[cnt]=true;
            cnt++;
        }
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<g[i].size();j++)
        {
            if(gro[i]!=gro[g[i][j]]) {ans[gro[i]]=false;break;}
        }
    }

    for(int i=1;i<=n;i++)
        if(ans[gro[i]])printf("%d ",i);printf("\n");

}


int main()
{
    int u,v;
    while(1)
    {
        for(int i=0;i<5001;i++) {g[i].clear();g_rev[i].clear();}

        scanf("%d",&n);
        if(n==0) break;
        scanf("%d",&e);

        for(int i=0;i<e;i++)
        {
           scanf("%d %d",&u,&v);
           g[u].push_back(v);
           g_rev[v].push_back(u);
        }

        kosaraju();
    }
    return 0;
}









/*
    f.clear();int chk[5001];for(int p=0;p<5001;p++) chk[p]=1;
    int flag,i,j,k,d;
    for(i=0;i<cnt;i++)
    {
        flag=-1;
       for(j=0;j<ans[i].size();j++)
       {

           if(g[ans[i][j]].size()==0) f.push_back(ans[i][j]);
           for(k=0;k<g[ans[i][j]].size();k++)
           {
               if(gro[g[ans[i][j]][k]]==gro[ans[i][j]]) {f.push_back(ans[i][j]);}
               else if(gro[g[ans[i][j]][k]]!=gro[ans[i][j]]) {flag=1;d=k;break;}
           }


           if(flag==1) break;
       }

       if(flag==1) {chk[g[ans[i][j]][d]]=0;while(d>0) {d--;f.pop_back();}}

    }

        sort(f.begin(),f.end());

       // printf("Ans\n");
        for(int ee=0;ee<f.size()-1;ee++)
        printf("%d ",f[ee]);
        printf("%d",f[f.size()-1]);
        printf("\n");*/
