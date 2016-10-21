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
    if(st[ind*2+1]>st[2*ind+2]) p=st[ind*2+1];else p=st[ind*2+2];
    if(p>(st[ind*2+1]+st[ind*2+2])) st[ind]=p; else st[ind]=st[2*ind+1]+st[2*ind+2];
}

int query(int i,int j,int qs,int qe,int ind)
{
    if(qs<=i&&qe>=j) return st[ind];
    if(qs>j||qe<i) return 0;
    int m=(i+j)/2;
    return max(query(i,m,qs,qe,2*ind+1),query(m+1,j,qs,qe,2*ind+2),query(i,m,qs,qe,2*ind+1)+query(m+1,j,qs,qe,2*ind+2));
}



int main()
{
    int N,Q,i,x,y;
    scanf("%d",&N);

    for(i=0;i<N;i++) scanf("%d",A[i]);

    build(0,N-1,0);
    scanf("%d",&Q);
    while(Q--)
    {
        scanf("%d %d",&x,&y);
        printf("%d\n",query(0,N-1,x,y,0));
    }
}
