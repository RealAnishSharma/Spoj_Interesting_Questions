//CHOP AHOY REVISITED
#include <bits/stdc++.h>
#include <string>

using namespace std;
int len;
int arr[26],check[26][26];


int maxa(int b,int e,int l)
{
    if(l==len) {check[b][e]=0;return 1;}
    else
    {
        int p=0,q=0,r=0;

        for(int i=0;i<len;i++)
        {
            if(i<b) p+=arr[i];
            else if(i>e) r+=arr[i];
            else q+=arr[i];
        }
        if(e==len-1) {if(p<=q) {check[b][e]=0;check[0][b-1]=0;return 1;}else {check[b][e]=0;check[0][b-1]=0;return 0;}}

        if(p<=q&&q<=r) {check[b][e]=0;check[0][b-1]=0;check[e+1][len-1]=0;return 1;}
        else  {check[b][e]=0;check[0][b-1]=0;check[e+1][len-1]=0;return 0;}
    }
}

int maxo(int b,int e,int sl)
{
    if(sl<1) return 0;
    int p=0;
    for(int i=0;i<len-sl+1;i++)
    {
        if(check[b+i][b+i+sl-1]==-1)
        p+=maxa(b+i,b+i+sl-1,sl);
    }

    p+=maxo(b,e,sl-1);

    return p;
}

int main()
{
    int k=1;
    char a[26];
    while(1)
    {
        scanf("%s",a);
        if(strcmp(a,"bye")==0) return 0;
        len=strlen(a);

        for(int i=0;i<len;i++) {arr[i]=(int)a[i]-48;}
        memset(check,-1,sizeof(check));


        printf("%d. %d\n",k++,maxo(0,len-1,len));
    }
    return 0;
}








/*scanf("%d%d",&m,&n);
        if(m==0 && n==0) break;

        int arr[m][n];
        for(int i=0;i<m;i++)for(int j=0;j<n;j++)scanf("%d",&arr[i][j]);

        printf("%d\n",maxo((int *)arr,0,m,n));
*/


/*

int maxo(int *arr,int cr,int m,int n)
{
    //for(int i=0;i<3;i++)for(int j=0;j<3;j++)
    //printf("%d ",*((arr+i*n)+j));

    for()


    return 0;
}

*/
