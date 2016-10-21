/*#include <bits/stdc++.h>
using namespace std;

vector<int> g[1001],g_rev[1001];
stack<int> st;
int n,vis[1001],gro[1001];


void dfs1(vector<int> G[],int s)
{
    vis[s]=1;
    for(int i=0;i<G[s].size();i++)
    if(vis[G[s][i]]==0)
    dfs1(G,G[s][i]);

    st.push(s);
}


void dfs2(vector<int> G[],int s,int cnt)
{
    vis[s]=0;
    gro[s]=cnt;
    for(int i=0;i<G[s].size();i++)
    if(vis[G[s][i]]==1)
    dfs2(G,G[s][i],cnt);
}


void kosaraju()
{
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=n;i++) if(vis[i]==0) dfs1(g,i);

    int v,cnt=0;
    bool ans[1001];
    while(!st.empty())
    {
        v=st.top();st.pop();
        if(vis[v]==1)
        {
            dfs2(g_rev,v,cnt);
            ans[cnt]=true;
            cnt++;
        }
    }

    for(int i=1;i<=n;i++)
    for(int j=0;j<g[i].size();j++)
    {
        if(gro[i]!=gro[g[i][j]]) {ans[gro[i]]=false;break;}
    }

    int po=0;
    for(int i=0;i<cnt;i++) if(ans[i]) po++;
    if(po>1) printf("0\n");
    else{
    int hh=0;
    for(int i=1;i<=n;i++)
        if(ans[gro[i]]) hh++;

    printf("%d\n",hh);
}
}

int main()
{
    int t,u,m;
    scanf("%d",&t);
    while(t--)
    {
        for(int i=0;i<1001;i++){g[i].clear();g_rev[i].clear();}
        scanf("%d",&n);

        for(int i=1;i<=n;i++)
        {
            scanf("%d",&m);
            for(int j=0;j<m;j++)
            {
                scanf("%d",&u);
                g[i].push_back(u);
                g_rev[u].push_back(i);
            }
        }

        kosaraju();
    }
    return 0;
}
*/
#include <bits/stdc++.h>

using namespace std;
int n,arr[10001];

void update(int idx,int val)
{
    idx++;
    while(idx<=n)
    {
        arr[idx]+=val;
        idx+=(idx&(-idx));
    }
}


void update2(int a,int b,int val)
{
    update(a,val);
    update(b+1,-val);
}

int sum(int idx)
{
    idx++;
    int s=0;
    while(idx>0)
    {
        s+=arr[idx];
        idx=idx-(idx&(-idx));
    }
    return s;
}


int ind(int idx)
{
    idx++;
    int s=arr[idx];
    if(idx>0){
        int z=idx-(idx&(-idx));
        idx--;
        while(idx!=z)
        {
            s-=arr[idx];idx-=(idx&(-idx));
        }
    }
    return s;
}


int query(int idx)
{
    idx++;
    int sum=0;
    for(;idx;idx-=(idx&(-idx))) sum+=arr[idx];
    return sum;
}




int main()
{
    int t,u,l,r,val;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&u);

        memset(arr,0,sizeof(arr));
        for(int i=0;i<u;i++)
        {
            scanf("%d %d %d",&l,&r,&val);

            update2(l,r,val);
           // for(int j=l;j<=r;j++) update(j,val);
        }
        int q,a;
        scanf("%d",&q);
        for(int i=0;i<q;i++)
        {
            scanf("%d",&a);printf("%d\n",query(a));
        }


    }
    return 0;
}
