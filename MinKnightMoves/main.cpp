#include <bits/stdc++.h>

using namespace std;

char csrc[2],cdest[2];
int src[2],dest[2];

struct node
{
    int x,y;
};

void bfs()
{

   queue<struct node> Q;

   struct node p,ab,vb;

   p.x=src[0];p.y=src[1];

   Q.push(p);

   int cost[9][9];
   for(int i=1;i<9;i++)for(int j=1;j<9;j++)cost[i][j]=100000000;
   cost[p.y][p.x]=0;

   while(!Q.empty())
   {
       ab=Q.front();Q.pop();

       if(ab.y+2>0 && ab.y+2<9 && ab.x-1>0 && ab.x-1<9 && /*vis[ab.y+2][ab.x-1]==0*/cost[ab.y+2][ab.x-1]>cost[ab.y][ab.x]+1)
       {
           vb.y=ab.y+2;vb.x=ab.x-1;Q.push(vb);

         //  if(cost[ab.y+2][ab.x-1]>cost[ab.y][ab.x]+1)
           cost[ab.y+2][ab.x-1]=cost[ab.y][ab.x]+1;
       }


       if(ab.y+2>0 && ab.y+2<9 && ab.x+1>0 && ab.x+1<9 && /*vis[ab.y+2][ab.x+1]==0*/cost[ab.y+2][ab.x+1]>cost[ab.y][ab.x]+1)
       {

           vb.y=ab.y+2;vb.x=ab.x+1;Q.push(vb);

           //if(cost[ab.y+2][ab.x+1]>cost[ab.y][ab.x]+1)
           cost[ab.y+2][ab.x+1]=cost[ab.y][ab.x]+1;

       }

       if(ab.y-2>0 && ab.y-2<9 && ab.x+1>0 && ab.x+1<9 && /*vis[ab.y-2][ab.x+1]==0*/cost[ab.y-2][ab.x+1]>cost[ab.y][ab.x]+1)
       {

           vb.y=ab.y-2;vb.x=ab.x+1;Q.push(vb);

          // if(cost[ab.y-2][ab.x+1]>cost[ab.y][ab.x]+1)
           cost[ab.y-2][ab.x+1]=cost[ab.y][ab.x]+1;

       }


       if(ab.y-2>0 && ab.y-2<9 && ab.x-1>0 && ab.x-1<9 && /*vis[ab.y-2][ab.x-1]==0*/cost[ab.y-2][ab.x-1]>cost[ab.y][ab.x]+1)
       {

           vb.y=ab.y-2;vb.x=ab.x-1;Q.push(vb);

          // if(cost[ab.y-2][ab.x-1]>cost[ab.y][ab.x]+1)
           cost[ab.y-2][ab.x-1]=cost[ab.y][ab.x]+1;

       }

       if(ab.y+1>0 && ab.y+1<9 && ab.x+2>0 && ab.x+2<9 && /*vis[ab.y+1][ab.x+2]==0*/cost[ab.y+1][ab.x+2]>cost[ab.y][ab.x]+1)
       {

           vb.y=ab.y+1;vb.x=ab.x+2;Q.push(vb);

        //   if(cost[ab.y+1][ab.x+2]>cost[ab.y][ab.x]+1)
           cost[ab.y+1][ab.x+2]=cost[ab.y][ab.x]+1;

       }

       if(ab.y+1>0 && ab.y+1<9 && ab.x-2>0 && ab.x-2<9 && /*vis[ab.y+1][ab.x-2]==0*/cost[ab.y+1][ab.x-2]>cost[ab.y][ab.x]+1)
       {

           vb.y=ab.y+1;vb.x=ab.x-2;Q.push(vb);

          // if(cost[ab.y+1][ab.x-2]>cost[ab.y][ab.x]+1)
           cost[ab.y+1][ab.x-2]=cost[ab.y][ab.x]+1;

       }

       if(ab.y-1>0 && ab.y-1<9 && ab.x+2>0 && ab.x+2<9 && /*vis[ab.y-1][ab.x+2]==0*/cost[ab.y-1][ab.x+2]>cost[ab.y][ab.x]+1)
       {

           vb.y=ab.y-1;vb.x=ab.x+2;Q.push(vb);

          // if(cost[ab.y-1][ab.x+2]>cost[ab.y][ab.x]+1)
           cost[ab.y-1][ab.x+2]=cost[ab.y][ab.x]+1;

       }

       if(ab.y-1>0 && ab.y-1<9 && ab.x-2>0 && ab.x-2<9 && /*vis[ab.y-1][ab.x-2]==0*/cost[ab.y-1][ab.x-2]>cost[ab.y][ab.x]+1)
       {

           vb.y=ab.y-1;vb.x=ab.x-2;Q.push(vb);

          // if(cost[ab.y-1][ab.x-2]>cost[ab.y][ab.x]+1)
           cost[ab.y-1][ab.x-2]=cost[ab.y][ab.x]+1;

       }


   }

/*
   for(int i=1;i<9;i++)
   {
       for(int j=1;j<9;j++) printf("%d %d %d\n",i,j,cost[i][j]);
   }*/

    printf("%d\n",cost[dest[1]][dest[0]]);
    return ;

}

int main()
{
    int T;


    scanf("%d",&T);
    while(T--)
    {
        scanf(" %s",csrc);scanf(" %s",cdest);
        src[0]=(int)csrc[0]-96;
        src[1]=(int)csrc[1]-48;
        dest[0]=(int)cdest[0]-96;
        dest[1]=(int)cdest[1]-48;

     //   printf("%d %d",src[0],src[1]);

        bfs();

    }
    return 0;
}
