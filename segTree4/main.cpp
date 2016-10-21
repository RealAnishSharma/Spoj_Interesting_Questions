#include <iostream>
#include <cstdio>
#include <climits>
using namespace std;

int A[50000],st[1000000];

int build(int i,int j,int ind)
{
    if(i==j)
    {
        st[ind]=A[i];
        return st[ind];
    }
    int p;
    int m=(i+j)/2;
    build(i,m,2*ind+1);
    build(m+1,j,ind*2+2);
    if(st[ind*2+1]>st[2*ind+2]) p=st[ind*2+1];
    else p=st[ind*2+2];
    if(p>(st[ind*2+1]+st[ind*2+2])) st[ind]=p;
    else st[ind]=st[2*ind+1]+st[2*ind+2];
    return st[ind];
}

int query(int i,int j,int qs,int qe,int ind)
{
    if(qs<=i&&qe>=j) return st[ind];
    if(qs>j||qe<i) return INT_MIN;
    int m=(i+j)/2;

    int u=query(i,m,qs,qe,2*ind+1);
    int v=query(m+1,j,qs,qe,2*ind+2);

    if(u==INT_MIN) return v;
    if(v==INT_MIN) return u;

    int p=max(u,v);
    int g=max(p,u+v);

    return g;
}

int main()
{
    int N,Q,i,x,y;
    scanf("%d",&N);

    for(i=0;i<N;i++) scanf("%d",&A[i]);

    build(0,N-1,0);
    scanf("%d",&Q);
    int Qr[Q],z=0;
    while(Q--)
    {
        scanf("%d %d",&x,&y);
        Qr[z++]=query(0,N-1,x-1,y-1,0);
    }

    for(int i=0;i<z;i++)
        printf("%d\n",Qr[i]);
}
