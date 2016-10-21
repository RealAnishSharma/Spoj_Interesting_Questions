#include<bits/stdc++.h>
using namespace std;

queue<int> q;
int par[20005],value[20005];

void foo(int n)
{
    int curr;
    q.push(1);par[1]=0;

    while(!q.empty())
    {
        curr=q.front();q.pop();

        if(curr==0)
        {
            stack<int>st;
            while(par[curr]!=0)
            {
                st.push(value[curr]);
                curr=par[curr];
            }

            st.push(1);

            while(!st.empty())
            {printf("%d",st.top());st.pop();}
            printf("\n");
            break;
        }
        int temp;
        temp=(curr*10)%n;
        if(par[temp]==-1){
        par[temp]=curr;
        value[temp]=0;
        q.push(temp);
        }
        temp=curr*10+1;
        temp=temp%n;
        if(par[temp]==-1){
        par[temp]=curr;
        value[temp]=1;
        q.push(temp);
        }
}
}

int main()
{
    int n,t;
    scanf("%d",&t);
    while(t--)
    {
        while(!q.empty()) q.pop();
        for(int i=0;i<20000;i++) {par[i]=-1;value[i]=-1;}
        scanf("%d",&n);
        foo(n);
    }
}






//METHOD 3
/*
#include <bits/stdc++.h>
#include <string>
using namespace std;

struct node
{
    int rem,lc;
    struct node* l,*r,*p;
};
int chaa=1;
struct node* root;

struct node* createNode(int w,struct node* v,int lchild)
{
    struct node* x=(struct node*)malloc(sizeof(struct node));
    x->rem=w;
    x->l=NULL;
    x->r=NULL;
    x->lc=lchild;
    x->p=v;
    return x;
};


void createGraph(struct node* temp,int n,int j)
{
    if(n==28) return;
    int d=temp->rem*10;

    temp->l=createNode(d%j,temp,1);
    temp->r=createNode((d+1)%j,temp,0);
    chaa+=2;
    printf("%d\n",chaa);

    createGraph(temp->l,n+1,j);
    createGraph(temp->r,n+1,j);
}



struct node* bfs(struct node *root)
{
    queue<struct node*> Q;
    Q.push(root);

    while(!Q.empty())
    {
        struct node* curr=Q.front();Q.pop();
        if(curr->rem==0) return curr;
        if(curr->l!=NULL)
        Q.push(curr->l);
        if(curr->r!=NULL)
        Q.push(curr->r);
    }

}


void yee(struct node* G)
{
    char c[100],ans[100];
    int k=0,u=0;
    while(G->p!=NULL)
    {
        if(G->lc==0) c[u]='1';
        else c[u]='0';
        G=G->p;
        u++;
    }

    c[u]='1';

    for(int i=u;i>=0;i--)ans[k++]=c[i];
    ans[k]='\0';

    printf("%s\n",ans);
}


int main()
{
    int K,n;
    printf("%d",sizeof(struct node));
    scanf("%d",&K);
    root=createNode(1,NULL,2);

    while(K--)
    {
        scanf("%d",&n);
        if(n==1) printf("1\n");
        else
        {
         createGraph(root,1,n);
         printf("done\n");
         struct node* G=bfs(root);
         yee(G);
        }
    }
    return 0;
}
*/
//METHOD 2
/*#include <bits/stdc++.h>
#include <string>
using namespace std;

struct node
{
    char num[25];
    int stln;
    struct node* l,*r;
};
struct node* root;

struct node* createNode(char st[],int level)
{
    struct node* x=(struct node*)malloc(sizeof(struct node));
    strcpy(x->num,st);
    x->num[level]='\0';
    x->stln=level;
    x->l=NULL;
    x->r=NULL;
    return x;
};

void createGraph(struct node* temp,int n)
{
    if(n==25) return;

    char p[25];

    strcpy(p,temp->num);p[n]='0';
    temp->l=createNode(p,n+1);

    p[n]='1';
    temp->r=createNode(p,n+1);

    createGraph(temp->l,n+1);
    createGraph(temp->r,n+1);
}

int divio(char str[],int n)
{
    int m,q=strlen(str);
    m=str[0]-'0';

    if(q==1) return m%n;
    else
    for(int i=1;i<q;i++)
    {
        m=m*10+(str[i]-'0');m=m%n;
    }
    return m;
}


char* bfs(struct node *root,int n)
{
    queue<struct node*> Q;

    Q.push(root);

    while(!Q.empty())
    {
        struct node* curr=Q.front();Q.pop();

        if(divio(curr->num,n)==0) return curr->num;

        if(curr->l!=NULL)
        Q.push(curr->l);
        if(curr->r!=NULL)
        Q.push(curr->r);
    }

}


int main()
{
    int K,n;
    scanf("%d",&K);

    char x[1]={'1'};

    root=createNode(x,1);
    createGraph(root,1);


    while(K--)
    {
        scanf("%d",&n);
        cout<<bfs(root,n)<<endl;
    }
    return 0;
}
*/



//METHOD 1
/*
struct node
{
    unsigned long long int i;
    struct node* l,*r;
};
struct node* root;

struct node* createNode(unsigned long long int j)
{
    struct node* x=(struct node*)malloc(sizeof(struct node));
    x->i=j;
    x->l=NULL;x->r=NULL;
    return x;
};

void createGraph(struct node* temp,int n)
{
    if(n==20) return;

    unsigned long long int p=((temp->i)*(unsigned long long int)10);


    temp->l=createNode(p);
    temp->r=createNode(p+1);

    createGraph(temp->l,n+1);
    createGraph(temp->r,n+1);
}


unsigned long long int bfs(struct node *root,unsigned long long int n)
{
    queue<struct node*> Q;

    Q.push(root);

    while(!Q.empty())
    {
        struct node* curr=Q.front();Q.pop();

        if((curr->i%n)==0) return curr->i;


        if(curr->l!=NULL)
        Q.push(curr->l);
        if(curr->r!=NULL)
        Q.push(curr->r);
    }
}
*/
