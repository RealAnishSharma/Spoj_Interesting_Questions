#include <bits/stdc++.h>

using namespace std;
int R,C;
char mtx[100][100];
int vis[100][100],ho[100][100][9];

struct pos
{
    int x,y;
} aux;

void foo()
{
    int k=0;
    stack<struct pos> st;
    char sen[]="ALLIZZWELL";

    for(int i=0;i<R;i++)
    for(int j=0;j<C;j++)
    {
        memset(vis,-1,sizeof(vis));

        if(mtx[i][j]=='A')
        {
          aux.x=i;aux.y=j;
          st.push(aux);
          vis[i][j]=0;
          k++;
          while(!st.empty())
          {

              if(k==10) {printf("YES\n");return;}

               struct pos w=st.top();//printf("%d %d %c\n",i,j,mtx[w.x][w.y]);

            //   if(mtx[w.x][w.y]=='E'){printf("[E reached : vis=%d ho=%d\n}",vis[w.x+1][w.y],ho[w.x][w.y][1]);}

               if(w.x+1>=0&&w.x+1<R&&sen[k]==mtx[w.x+1][w.y]&&vis[w.x+1][w.y]==-1&&ho[w.x][w.y][1]==-1)
               {
                k++;
                aux.x=w.x+1;aux.y=w.y;vis[w.x+1][w.y]=0;
                st.push(aux);
                ho[w.x][w.y][1]=0;

               }

               else if(w.y+1>=0&&w.y+1<C&&sen[k]==mtx[w.x][w.y+1]&&vis[w.x][w.y+1]==-1&&ho[w.x][w.y][2]==-1)
               {
                k++;
                aux.x=w.x;aux.y=w.y+1;vis[w.x][w.y+1]=0;
                st.push(aux);
                ho[w.x][w.y][2]=0;
               }

               else  if(w.x-1>=0&&w.x-1<R&&sen[k]==mtx[w.x-1][w.y]&&vis[w.x-1][w.y]==-1&&ho[w.x][w.y][3]==-1)
               {
                k++;
                aux.x=w.x-1;aux.y=w.y;vis[w.x-1][w.y]=0;
                st.push(aux);
                ho[w.x][w.y][3]=0;
               }


              else if(w.y-1>=0&&w.y-1<C&&sen[k]==mtx[w.x][w.y-1]&&vis[w.x][w.y-1]==-1&&ho[w.x][w.y][4]==-1)
              {
                k++;
                aux.x=w.x;aux.y=w.y-1;vis[w.x][w.y-1]=0;
                st.push(aux);
                ho[w.x][w.y][4]=0;
              }


             else if(w.x+1>=0&&w.x+1<R&&w.y+1>=0&&w.y+1<C&&sen[k]==mtx[w.x+1][w.y+1]&&vis[w.x+1][w.y+1]==-1&&ho[w.x][w.y][5]==-1)
             {
                k++;
                aux.x=w.x+1;aux.y=w.y+1;vis[w.x+1][w.y+1]=0;
                st.push(aux);
                ho[w.x][w.y][5]=0;
             }



             else if(w.x+1>=0&&w.x+1<R&&w.y-1>=0&&w.y-1<C&&sen[k]==mtx[w.x+1][w.y-1]&&vis[w.x+1][w.y-1]==-1&&ho[w.x][w.y][6]==-1)
             {
                k++;
                aux.x=w.x+1;aux.y=w.y-1;vis[w.x+1][w.y-1]=0;
                st.push(aux);
                ho[w.x][w.y][6]=0;
             }


             else if(w.x-1>=0&&w.x-1<R&&w.y+1>=0&&w.y+1<C&&sen[k]==mtx[w.x-1][w.y+1]&&vis[w.x-1][w.y+1]==-1&&ho[w.x][w.y][7]==-1)
             {
                k++;
                aux.x=w.x-1;aux.y=w.y+1;vis[w.x-1][w.y+1]=0;
                st.push(aux);
                ho[w.x][w.y][7]=0;
             }


             else if(w.x-1>=0&&w.x-1<R&&w.y-1>=0&&w.y-1<C&&sen[k]==mtx[w.x-1][w.y-1]&&vis[w.x-1][w.y-1]==-1&&ho[w.x][w.y][8]==-1)
             {
                k++;
                aux.x=w.x-1;aux.y=w.y-1;vis[w.x-1][w.y-1]=0;
                st.push(aux);
                ho[w.x][w.y][8]=0;
             }

             else
             {
                 struct pos w=st.top();
                 for(int pp=0;pp<9;pp++) ho[w.x][w.y][pp]=-1;
                 vis[w.x][w.y]=-1;
                 st.pop();k--;
             }
          }
        }
    }
    if(k==10) printf("YES\n");
    else printf("NO\n");

}









int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf(" %d %d",&R,&C);
        memset(vis,-1,sizeof(vis));memset(ho,-1,sizeof(int)*90000);

        for(int i=0;i<R;i++)for(int j=0;j<C;j++) scanf(" %c",&mtx[i][j]);

        foo();

    }
    return 0;
}
