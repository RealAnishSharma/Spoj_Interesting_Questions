#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N,a=0,b=0,c=0,sum=0;
    scanf("%d",&N);
    char arr[100];

    for(int j=0;j<N;j++)
    {
        scanf(" %s",&arr);
        if(strcmp(arr,"1/4")==0) a++;
        else if(strcmp(arr,"1/2")==0) b++;
        else c++;
    }

    if(a-c>0) a=a-c;else a=0;

    if(b%2!=0&&a-2>=0) {a=a-2;}
    else if(b%2!=0&&a-2<0) a=0;

    if(b%2==0) b=b/2;
    else b=b/2+1;

    if(a%4==0) a=a/4;
    else a=a/4+1;

    printf("%d\n",a+b+c+1);

    return 0;
}
