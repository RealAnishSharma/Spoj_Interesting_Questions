#include <bits/stdc++.h>

using namespace std;
char arr[26][26];
int w,h,dist[26][26],xes[630][2];

struct pqn
{
    int x,y,val;
};

class CompareDist
{
    public:
    bool operator()(struct pqn n1,struct pqn n2) {
        return n1.val>n2.val;
    }
};

bool isCheck(struct pqn a)
{
    if(a.val==dist[a.x][a.y]) return true;
    else return false;
}


void djikstra(int a,int b,int aa,int bb)
{

    for(int i=0;i<h;i++)
    for(int j=0;j<w;j++)
    dist[i][j]=INT_MAX;

    dist[a][b]=0;

    struct pqn ab;
    priority_queue< struct pqn,vector<struct pqn>,CompareDist > pq;

    int oo=0;
    for(int i=0;i<h;i++)
    for(int j=0;j<w;j++)
    if(arr[i][j]!='X')
    {
        oo++;
        ab.x=i;ab.y=j;ab.val=dist[i][j];
        pq.push(ab);
    }

    int out[h][w],mm;
    memset(out,0,sizeof(int)*h*w);

    while(!pq.empty())
    {
        if(mm==oo) break;
        struct pqn p,bn;
        p=pq.top();pq.pop();

        if(isCheck(p)&&out[p.x][p.y]==0&&dist[p.x][p.y]!=INT_MAX){



        if(p.x+1<h&&out[p.x+1][p.y]==0&&arr[p.x+1][p.y]!='X')
        {

            if(arr[p.x+1][p.y]=='D'){
            if(dist[p.x+1][p.y]>dist[p.x][p.y])
                    dist[p.x+1][p.y]=dist[p.x][p.y];}
            else{
            if(dist[p.x+1][p.y]>dist[p.x][p.y]+((int)arr[p.x+1][p.y]-'0'))
                    dist[p.x+1][p.y]=dist[p.x][p.y]+((int)arr[p.x+1][p.y]-'0');}

            bn.x=p.x+1;bn.y=p.y;bn.val=dist[p.x+1][p.y];
            pq.push(bn);
        }



        if(p.x-1>=0&&out[p.x-1][p.y]==0&&arr[p.x-1][p.y]!='X')
        {

            if(arr[p.x-1][p.y]=='D'){
            if(dist[p.x-1][p.y]>dist[p.x][p.y])
                    dist[p.x-1][p.y]=dist[p.x][p.y];}
            else{
            if(dist[p.x-1][p.y]>dist[p.x][p.y]+((int)arr[p.x-1][p.y]-'0'))
                    dist[p.x-1][p.y]=dist[p.x][p.y]+((int)arr[p.x-1][p.y]-'0');}

            bn.x=p.x-1;bn.y=p.y;bn.val=dist[p.x-1][p.y];
            pq.push(bn);
        }



        if(p.y+1<w&&out[p.x][p.y+1]==0&&arr[p.x][p.y+1]!='X')
        {

            if(arr[p.x][p.y+1]=='D')
            {if(dist[p.x][p.y+1]>dist[p.x][p.y])
                    dist[p.x][p.y+1]=dist[p.x][p.y];}
            else
           {if(dist[p.x][p.y+1]>dist[p.x][p.y]+((int)arr[p.x][p.y+1]-'0'))
                    dist[p.x][p.y+1]=dist[p.x][p.y]+((int)arr[p.x][p.y+1]-'0');}


            bn.x=p.x;bn.y=p.y+1;bn.val=dist[p.x][p.y+1];


            pq.push(bn);
        }

        if(p.y-1>=0&&out[p.x][p.y-1]==0&&arr[p.x][p.y-1]!='X')
        {

            if(arr[p.x][p.y-1]=='D'){
            if(dist[p.x][p.y-1]>dist[p.x][p.y])
                    dist[p.x][p.y-1]=dist[p.x][p.y];}
            else
           {if(dist[p.x][p.y-1]>dist[p.x][p.y]+((int)arr[p.x][p.y-1]-'0'))
                    dist[p.x][p.y-1]=dist[p.x][p.y]+((int)arr[p.x][p.y-1]-'0');}

            bn.x=p.x;bn.y=p.y-1;bn.val=dist[p.x][p.y-1];

            pq.push(bn);
        }

        out[p.x][p.y]=1;mm++;
    }
    }
    printf("%d\n",dist[aa][bb]);

}


int main()
{
    int a,b,aa,bb,y=0;
    while(1)
    {
    scanf("%d %d",&w,&h);

    if(w==0&&h==0) break;

    for(int k=0;k<h;k++)
    for(int j=0;j<w;j++)
    {
    scanf(" %c",&arr[k][j]);
    if(arr[k][j]=='S') {a=k,b=j;}
    if(arr[k][j]=='D') {aa=k;bb=j;}
    }

    djikstra(a,b,aa,bb);
    }

    return 0;
}
