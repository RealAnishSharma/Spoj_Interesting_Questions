#include <bits/stdc++.h>
#include <limits>
using namespace std;
int arr[101][101],h,w,marr[105][105];

void maxa(int r,int i)
{
    int a,b,c;
    if(i<0||i>=w) {marr[r][i+1]=INT_MIN;return;}
    if(r==h-1) {marr[r][i+1]==0;return;}

    if(marr[r+1][i]==-1) maxa(r+1,i-1);
    if(marr[r+1][i+1]==-1) maxa(r+1,i);
    if(marr[r+1][i+2]==-1) maxa(r+1,i+1);


    if(i>0)
    a=arr[r+1][i-1]+marr[r+1][i];
    else
    a=INT_MIN;

    b=arr[r+1][i]+marr[r+1][i+1];
    c=arr[r+1][i+1]+marr[r+1][i+2];

    marr[r][i+1]=max(a,max(b,c));


}

int maxo(int r)
{
    int p,maxp=INT_MIN;
    for(int i=0;i<w;i++)
    {
        maxa(r,i);
        p=marr[r][i+1]+arr[r][i];
        if(p>maxp) maxp=p;
    }
    return (maxp+1);
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf(" %d%d",&h,&w);

        for(int i=0;i<h;i++)
        for(int j=0;j<w;j++)
        scanf("%d",&arr[i][j]);

        for(int i=0;i<105;i++)for(int j=0;j<105;j++)marr[i][j]=-1;

        printf("%d\n",maxo(0));

    }
    return 0;
}







/*
    if(r==h-1) {marr[r][i]==0;return;}
    if(i<0||i>w) {marr[r][i]=INT_MIN;return;}


    if(marr[r+1][i-1]==-1) maxa(r+1,i-1);
    if(marr[r+1][i]==-1) maxa(r+1,i);
    if(marr[r+1][i+1]==-1) maxa(r+1,i+1);

    a=arr[r+1][i-1]+marr[r+1][i-1];
    b=arr[r+1][i]+marr[r+1][i];
    c=arr[r+1][i+1]+marr[r+1][i+1];

    marr[r][i]=max(a,max(b,c));
*/

/*
int maxa(int r,int i)
{
    int a,b,c;

    if(r==h-1) return 0;
    if(i<0||i>w) return INT_MIN;

    a=arr[r+1][i-1]+maxa(r+1,i-1);
    b=arr[r+1][i]+maxa(r+1,i);
    c=arr[r+1][i+1]+maxa(r+1,i+1);

    return max(a,max(b,c));
}
*/
