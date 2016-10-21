#include <bits/stdc++.h>

using namespace std;
int n;
char str[11];
vector< pair < unsigned int ,unsigned int > > g[10001];

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


void initialize(int Arr[],int Size[],int N)
{
    for(int i=0;i<N;i++){Arr[i]=i;Size[i]=1;}
}

int root(int Arr[],int i)
{
    while(Arr[i]!=i){Arr[i]=Arr[Arr[i]];i=Arr[i];}
    return i;
}

bool Find(int Arr[],int a,int b)
{
    if(root(Arr,a)==root(Arr,b)) return true;
    else return false;
}


void Union(int Arr[],int Size[],int A,int B)
{
    int root_A=root(Arr,A);
    int root_B=root(Arr,B);

    if(Size[root_A]<Size[root_B])
    {
        Arr[root_A]=Arr[root_B];
        Size[root_B]+=Size[root_A];
    }
    else
    {
        Arr[root_B]=Arr[root_A];
        Size[root_A]+=Size[root_B];
    }
}

void kruskal()
{
        struct edge ab,xopa[1000];
        priority_queue<struct edge,vector<struct edge>,CD> pq;

        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<g[i].size();j++)
            {
                if(g[i][j].first>i)
                {
                    ab.s=i;ab.d=g[i][j].first;ab.c=g[i][j].second;
                    pq.push(ab);
                }
            }
        }

        int e=0,Arr[n+1],Size[n+1];
        unsigned int cost=0;

        initialize(Arr,Size,n+1);


        while(e<n-1)
        {
            ab=pq.top();pq.pop();

            if(!Find(Arr,ab.s,ab.d))
            {
                cost+=ab.c;e++;Union(Arr,Size,ab.s,ab.d);
            }
        }


        printf("%d\n",cost);
        return;
}









int main()
{
    int s,ng;
    unsigned int u,v;
    struct edge ed;
    scanf("%d",&s);
    while(s--)
    {
     scanf("%d",&n);

     for(int i=0;i<10001;i++) g[i].clear();

     for(int i=1;i<=n;i++)
     {
         scanf(" %s",str);
         scanf("%d",&ng);

         for(int j=0;j<ng;j++)
         {
             scanf("%d %d",&u,&v);
             g[i].push_back(make_pair(u,v));
         }
     }
     kruskal();
    }
    return 0;
}
