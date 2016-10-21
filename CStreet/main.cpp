#include <bits/stdc++.h>
using namespace std;

unsigned int p,n,m;
vector< pair< unsigned int,unsigned int > > g[1001];

struct edge
{
    unsigned int s,d,c;
};


class CD
{
public:
    bool operator()(struct edge n1,struct edge n2)
    {
        return n1.c>n2.c;
    }
};



void initialise(int Arr[],int Size[],int N)
{
    for(int i=0;i<N;i++){Arr[i]=i;Size[i]=1;}
}

int root(int Arr[],int a)
{
    while(Arr[a]!=a)
    {
        Arr[a]=Arr[Arr[a]];
        a=Arr[a];
    }
    return a;
}


bool Find(int Arr[],int a,int b)
{
    if(root(Arr,a)==root(Arr,b)) return true;
    else return false;
}

void Union(int Arr[],int Size[],int a,int b)
{
    int root_A=root(Arr,a);
    int root_B=root(Arr,b);

    if(Size[root_A]>Size[root_B])
    {
        Arr[root_B]=Arr[root_A];
        Size[root_A]+=Size[root_B];
    }
    else
    {
        Arr[root_A]=Arr[root_B];
        Size[root_B]+=Size[root_A];
    }
}

void kruskal()
{
    struct edge ab;
    priority_queue<struct edge,vector<struct edge>,CD> pq;

    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<g[i].size();j++)
        {
            ab.s=i;ab.d=g[i][j].first;ab.c=g[i][j].second;
            pq.push(ab);
        }
    }


    unsigned int e=0,cost=0;
    int Arr[n+1],Size[n+1];

    initialise(Arr,Size,n+1);

    while(e<n-1)
    {
        ab=pq.top();pq.pop();

        if(!Find(Arr,ab.s,ab.d))
        {
            cost+=ab.c;e++;Union(Arr,Size,ab.s,ab.d);
        }
    }

    printf("%d\n",cost*p);

}


int main()
{
    int t;
    unsigned int u,v,w;
    scanf("%d",&t);
    while(t--)
    {
      for(int i=0;i<1001;i++) g[i].clear();

      scanf(" %d %d %d",&p,&n,&m);

      for(int i=0;i<m;i++)
      {
          scanf("%d %d %d",&u,&v,&w);
          g[u].push_back(make_pair(v,w));
      }
      kruskal();
    }
    return 0;
}
