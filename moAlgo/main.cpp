#include <bits/stdc++.h>
#include <algorithm>
using namespace std;


#define N 311111
#define BLOCK 555
#define QN 200002

int cnt[1111111],A[N],ans[N],answer=0;


struct node
{
    int i,L,R;
}qu[QN];

bool cmp(node a,node b)
{
    if(a.L/BLOCK!=b.L/BLOCK)
    return a.L/BLOCK<b.L/BLOCK;
    return a.R<b.R;
}


void add(int position)
{
    cnt[A[position]]++;
    if(cnt[A[position]]==1)
        answer++;
}

void remove(int position)
{
    cnt[A[position]]--;
    if(cnt[A[position]]==0)
        answer--;
}


int main()
{
    int i,q,n;
    scanf("%d",&n);

    for(i=0;i<n;i++)
        scanf("%d",&A[i]);

    scanf("%d",&q);

    for (i=0;i<q;i++)
    {
        scanf(" %d%d",&qu[i].L,&qu[i].R);
        qu[i].L--;
        qu[i].R--;
        qu[i].i=i;
    }

    sort(qu,qu+q,cmp);

    for(i=0;i<q;i++)
        printf("(%d,%d)\n",qu[i].L,qu[i].R);




    int currentL=0,currentR=0;
    for(i=0;i<q;i++)
    {
        while(currentL<qu[i].L)
        {
            remove(currentL);
            currentL++;
        }

        while(currentL>qu[i].L)
        {
            add(currentL-1);
            currentL--;
        }

        while(currentR<=qu[i].R)
        {
            add(currentR);
            currentR++;
        }

        while(currentR>qu[i].R+1)
        {
            remove(currentR-1);
            currentR--;
        }

        ans[qu[i].i]=answer;
    }


    for(i=0;i<q;i++)
        printf("%d\n",ans[i]);
    return 0;
}
