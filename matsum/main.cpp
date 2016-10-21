#include<bits/stdc++.h>
using namespace std;

int N,mat[1025][1025],BIT[1025][1025];

void update(int x, int y, int val)
{
    for (; x <= N; x += (x & -x))
    for (int y1=y; y1 <= N; y1 += (y1 & -y1))
    BIT[x][y1] += val;
    return;
}

int getSum(int x, int y)
{
    int sum = 0;
    for(; x > 0; x -= x&-x)
    for(int y1=y; y1 > 0; y1 -= y1&-y1)
    sum += BIT[x][y1];

    return sum;
}


int main()
{
    int x1,y1,x2,y2,x,y,num,t,e,ans;char str[20];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&N);

        for(int i=0;i<=N;i++)for(int j=0;j<=N;j++){mat[i][j]=0;BIT[i][j]=0;}

        while(1)
        {
            scanf(" %s",str);
            if(strcmp(str,"END")==0) break;

            if(strcmp(str,"SET")==0)
            {
                scanf("%d %d %d",&x,&y,&num);
                x++,y++;
                update(x,y,num-mat[x][y]);
                mat[x][y]=num;
            }

            if(strcmp(str,"SUM")==0)
            {
                scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
                x1++,x2++,y1++,y2++;
                ans = getSum(x2, y2)-getSum(x2, y1-1)-getSum(x1-1, y2)+getSum(x1-1, y1-1);
                printf("%d\n",ans);
            }

        }
        printf("\n");

    }
    return 0;

}
