#include <bits/stdc++.h>

using namespace std;
int k,R,C,vis[100][100];
struct pos
{
    int x,y;
};

struct pos mo[11],c1[11],c2[11];

void foo(int i)
{
    struct pos aux,c1x,c2x;
    queue<struct pos> mouse;

    mouse.push(mo[i]);

    c1x=c1[i];c2x=c2[i];

    while(!mouse.empty())
    {

    aux=mouse.front();mouse.pop();

    if(aux.x-1<0 || aux.x>=R || aux.y-1<0 || aux.y>=C) {printf("YES\n");return;}


    struct pos d;

    d.x=aux.x+1;d.y=aux.y;vis[d.x][d.y]=0;mouse.push(d);
    d.x=aux.x-1;d.y=aux.y;vis[d.x][d.y]=0;mouse.push(d);
    d.x=aux.x;d.y=aux.y+1;vis[d.x][d.y]=0;mouse.push(d);
    d.x=aux.x;d.y=aux.y-1;vis[d.x][d.y]=0;mouse.push(d);








    }
}

int main()
{
    scanf(" %d %d %d",&R,&C,&k);

    for(int i=0;i<k;i++)
    scanf("%d %d %d %d %d %d",&mo[i].x,&mo[i].y,&c1[i].x,&c1[i].y,&c2[i].x,&c2[i].y);

    for(int i=0;i<k;i++)
    {
    memset(vis,-1,sizeof(int)*10000);
    foo(i);
    }
    return 0;
}


  //  aux1=cat1.front();cat1.pop();
  //  aux2=cat2.front();cat2.pop();

  //  cat1.push(c1[i]);
  //  cat2.push(c2[i]);
  //,aux1,aux2;
