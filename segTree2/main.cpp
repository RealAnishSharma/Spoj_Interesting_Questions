#include <iostream>
#include<climits>
#include<cstdio>
using namespace std;

int A[100000];
//Construct segment tree


struct node
{
    int mxv;
    int index;
} st[270000];


struct node build(int i,int j,int ind)
{
    if(i==j)
    {
        st[ind].mxv=A[i];
        st[ind].index=i;
        return st[ind];
    }

    struct node M,N;
    int m=(i+j)/2;
    M=build(i,m,2*ind+1);
    N=build(m+1,j,2*ind+2);

    if(M.mxv>N.mxv) st[ind]=M;
    else st[ind]=N;

    return st[ind];

}

struct node getMax(int i,int j,int qs,int qe,int ind)
{
    struct node A,B,b;

     b.mxv=INT_MIN;
     b.index=-1;

    if(qs<=i&&qe>=j) return st[ind];
    if(j<qs||i>qe) return b;

    int m=(i+j)/2;

    A=getMax(i,m,qs,qe,2*ind+1);
    B=getMax(m+1,j,qs,qe,2*ind+2);

    if(A.mxv>B.mxv) return A;
    else return B;
}


void update(int ss,int se,int i,int val,int si)
{
  /*  if(i<ss||i>se) return;
    st[si].mxv=val;
    if(se!=ss)
    {
        int m=(ss+se)/2;
        update(ss,m,i,val,si*2+1);
        update(m+1,se,i,val,si*2+2);
    }
 */
 if(se==ss)
 {
     A[i]=val;
     st[si].mxv=val;
 }
 else
 {
     int m=(ss+se)/2;
     if(ss<=i&&i<=m)
        update(ss,m,i,val,2*si+1);
     else
        update(m+1,se,i,val,2*si+2);

    if(st[si*2+1].mxv>st[si*2+2].mxv)
        st[si]=st[si*2+1];
    else
        st[si]=st[si*2+2];
 }


}


int getSum(int i,int j,int qs,int qe,int ind)
{
    struct node p,q;
    p=getMax(i,j,qs,qe,ind);
    update(i,j,p.index,INT_MIN,0);
    q=getMax(i,j,qs,qe,ind);
    update(i,j,p.index,p.mxv,0);
    //printf("In update %d+%d",p.mxv,q.mxv);

    return p.mxv+q.mxv;
}


int main()
{
    int i,N,Q,x,y;
    char ch;
    scanf("%d",&N);

    for(i=0;i<N;i++) scanf("%d",&A[i]);
    build(0,N-1,0);
    //for(i=0;i<9;i++) printf("%d ",st[i].mxv);


    scanf("%d",&Q);
    while(Q--)
    {
        scanf(" %c %d %d",&ch,&x,&y);
        if(ch=='Q')
            printf("%d\n",getSum(0,N-1,x-1,y-1,0));
        else
            update(0,N-1,x-1,y,0);
    }

    return 0;
}
