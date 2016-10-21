#include <bits/stdc++.h>

using namespace std;

int N,q[101],p[101],t[101];

int maxo(int b,int T)
{
    return max(maxo(b+1,T-t[b])+q[b],maxo(b+1,T));
}

int main()
{
    int T;
    scanf(" %d %d",&N,&T);
    for(int i=0;i<N;i++)
        scanf(" %d %d %d",t[i],p[i],q[i]);

    for(int i=0;i<7;i++) st[i]=-1;

    printf("%d\n",maxo(0,T));
    return 0;
}
