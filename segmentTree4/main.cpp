#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
#define SIZE 200000
int arr[SIZE],st[572150];

int build(int i,int j,int ind)
{
    if(i==j)
    {
        st[ind]=arr[i];
        return st[ind];
    }

    int m=(i+j)/2;
    st[ind]=build(i,m,2*ind+1)+build(m+1,j,2*ind+2);
    return st[ind];
}

int getSum(int i,int j,int qs,int qe,int ind)
{

    if(qs<=i&&qe>=j) return st[ind];
    if(qe<i||qs>j) return 0;
    int m=(i+j)/2;
    return getSum(i,m,qs,qe,2*ind+1)+getSum(m+1,j,qs,qe,2*ind+2);
}

/*
void update(int ss,int se,int i,int val,int si)
{
    if(se==ss)
        {
            arr[i]=val;
            st[si]=val;
        }
    else
        {
            int m=(ss+se)/2;
            if(ss<=i&&i<=m)
                update(ss,m,i,val,2*si+1);
            else
                update(m+1,se,i,val,2*si+2);
            st[si]=st[si*2+1]+st[si*2+2];
        }
}
*/
void update2(int ss, int se, int i, int diff, int si)
{
    // Base Case: If the input index lies outside the range of
    // this segment
    if (i < ss || i > se)
        return;

    // If the input index is in range of this node, then update
    // the value of the node and its children
    st[si] = st[si] + diff;
    if (se != ss)
    {
        int mid = (ss+se)/2;
        update2(ss, mid, i, diff, 2*si + 1);
        update2(mid+1, se, i, diff, 2*si + 2);
    }
}


int main()
{
    int q,v,c,d,n,N;
    scanf(" %d",&n);
    N=SIZE-n;
    for(int i=0;i<SIZE;i++) arr[i]=0;
    for(int i=N;i<SIZE;i++) scanf("%d",&arr[i]);


    build(0,SIZE-1,0);

    scanf("%d",&q);

    while(q--)
    {
        scanf("%d",&v);
        if(v==1)
        {
            scanf(" %d%d",&c,&d);
            printf("%d\n",getSum(0,SIZE-1,c-1+N,d-1+N,0));
        }
        else
        {
            scanf("%d",&c);
            /*for(int i=n-1;i>=0;i--)
                arr[i+1]=arr[i];

            arr[0]=c;n++;
            build(0,n-1,0);*/

            N--;
            update2(0,SIZE-1,N,c,0);

        }
    }
    return 0;
}
/*


#include<algorithm>
#include<cstdio>

#define MAX 524288
#define VAL 362144

using namespace std;

int A[MAX],negative=0;

long long sum1(int i,int j)
{
	long long sum=A[i];
	if(j>i)
		sum=sum+A[j];
	while(i/2!=j/2)
	{
		if(i%2==0)
		{
			sum=sum+A[i+1];
		}
		if(j%2!=0)
		{
			sum=sum+A[j-1];
		}
		i=i/2;
		j=j/2;
	}
	return sum;
}
int update(int i,int value)
{
	while(i!=1)
	{
		A[i]=A[i]+value;
		i=i/2;
	}

}
int main()
{
	int Query,operation,numbers;
	for(int i=0; i<MAX; i++)
		A[i]=0;

	// Scanning part

	scanf("%d",&numbers);
	negative=0;


	for(int i=1; i<=numbers; i++)
		scanf("%d",&A[VAL+i]);

	for(int i=262143; i>=0; i--)
		A[i] = A[2*i] + A[2*i + 1];

	scanf("%d",&Query);

	int delta,current,min,max;

	while(Query--)
	{
		scanf("%d",&operation);

		if(operation==1)
		{
			scanf("%d %d",&min,&max);
			min=min+VAL+negative;
			max=max+VAL+negative;
			printf("%lld\n",sum1(min,max));
		}
		if(operation==2)
		{
			scanf("%d",&delta);
			current=VAL+negative;
			update(current,delta);
			negative--;
		}

	}
	return 0;

}
*/
