//Edit distance problem
#include <bits/stdc++.h>
#include <string>
using namespace std;
char str1[2001],str2[2001];

int e1,e2,marr[2101][2101];

int min(int a,int b,int c)
{
    return min(a,min(b,c));
}
/*
int mino(int b1,int b2)
{
    if(e1==0) return e2;
    if(e2==0) return e1;
    if(b1>e1&&b2>e2) return 0;
    if(b1>=e1&&b2<e2) return e2-b2;
    if(b2>=e2&&b1<e1) return e1-b1;
    if(str1[b1]==str2[b2]) return mino(b1+1,b2+1);
    int p,q,r;
    p=1+mino(b1,b2+1);
    q=1+mino(b1+1,b2);
    r=1+mino(b1+1,b2+1);
    return min(p,q,r);
}
*/


void mino(int b1,int b2)
{
    if(e1==0) {marr[b1][b2]=e2;return;}
    if(e2==0) {marr[b1][b2]=e1;return;}


    if(b1>=e1&&b2>=e2) {marr[b1][b2]=0;return;}
    if(b1>=e1&&b2<e2) {marr[b1][b2]=abs(e2-b2);return;}

    if(b2>=e2&&b1<e1) {marr[b1][b2]=abs(e1-b1);return;}


    if(str1[b1]==str2[b2]) {
        if(marr[b1+1][b2+1]==-1) mino(b1+1,b2+1);
        marr[b1][b2]=marr[b1+1][b2+1];
        return;
    }

    int p,q,r;


    if(marr[b1][b2+1]==-1) mino(b1,b2+1);
    if(marr[b1+1][b2]==-1) mino(b1+1,b2);
    if(marr[b1+1][b2+1]==-1) mino(b1+1,b2+1);

    p=1+marr[b1][b2+1];
    q=1+marr[b1+1][b2];
    r=1+marr[b1+1][b2+1];

    marr[b1][b2]=min(p,q,r);
}


int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf(" %s",str1);
        scanf(" %s",str2);
        e1=strlen(str1);e2=strlen(str2);

        for(int i=0;i<2101;i++)
        for(int j=0;j<2101;j++)
        marr[i][j]=-1;

       /* for(int i=0;i<=e1;i++) marr[i][0]=i;
        for(int j=0;j<=e2;j++) marr[0][j]=j;

        for(int i=1;i<=e1;i++)
        {
            for(int j=1;j<=e2;j++)
            {
                if(str1[i-1]==str2[j-1]) marr[i][j]=marr[i-1][j-1];
                else
                    marr[i][j]=min(1+marr[i-1][j],1+marr[i][j-1],1+marr[i-1][j-1]);

            }
        }*/

        mino(0,0);
        printf("%d\n",marr[0][0]);
    }
    return 0;
}




























