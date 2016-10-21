#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])
#define ALPHABET_SIZE 26
#define INDEX(c) ((int)c-(int)'a')
#define FREE(p) \
 free(p);\
 p=NULL;

 //forward declration
 typedef struct trie_node trie_node_t;
 struct trie_node
 {
     int value;
     trie_node_t *children[ALPHABET_SIZE];
 };

 typedef struct trie trie_t;

struct trie
{
    trie_node_t *root;
    int count;
};

trie_node_t *getNode(void)
{
    trie_node_t *pNode=NULL;
    pNode=new trie_node_t;

    if(pNode)
    {
        int i;
        pNode->value=0;
        for(i=0;i<ALPHABET_SIZE;i++) pNode->children[i]=NULL;
    }
    return pNode;
}

void initialize(trie_t *pTrie)
{
    pTrie->root=getNode();
    pTrie->count=0;
}

void insert(trie_t *pTrie,char key[])
{
    int level,index;
    int length=strlen(key);
    trie_node_t *pCrawl;
    pTrie->count++;
    pCrawl=pTrie->root;

    for(level=0;level<length;level++)
    {
        index=INDEX(key[level]);
        if(pCrawl->children[index]) pCrawl=pCrawl->children[index];
        else
        {
            pCrawl->children[index]=getNode();
            pCrawl=pCrawl->children[index];
        }
        pCrawl->value=pTrie->count;
    }
}

int search(trie_t *pTrie,char key[])
{
    int level,index;
    int length=strlen(key);
    trie_node_t *pCrawl;
    pCrawl=pTrie->root;

    for(level=0;level<length;level++)
    {
        index=INDEX(key[level]);
        if(!pCrawl->children[index]) return 0;
        pCrawl=pCrawl->children[index];
    }

    return (0!=pCrawl&&pCrawl->value);
}

int leafNode(trie_node_t *pNode)
{return (pNode->value!=0); }

int isItFreeNode(trie_node_t *pNode)
{
    int i;
    for(i=0;i<ALPHABET_SIZE;i++)
        if(pNode->children[i]) return 0;
    return 1;
}

bool deleteHelper(trie_node_t *pNode,char key[],int level,int len)
{
    if(pNode)
    {
        if(level==len)
        {
        if(pNode->value)
        {
            pNode->value=0;
            if(isItFreeNode(pNode)) return true;
            return false;
        }
        }
    else
    {
        int index=INDEX(key[level]);
        if(deleteHelper(pNode->children[index],key,level+1,len))
        {
            FREE(pNode->children[index]);
            return (!leafNode(pNode)&&isItFreeNode(pNode));
        }
    }
    }
    return false;
}

void deleteKey(trie_t *pTrie,char key[])
{
    int len=strlen(key);
    if(len>0)
        deleteHelper(pTrie->root,key,0,len);
}

int main()
{
    char keys[][8]={"she","shells","sea","shore","the","by","sheer"};
    trie_t trie;
    initialize(&trie);

    for(int i=0;i<ARRAY_SIZE(keys);i++)
        insert(&trie,keys[i]);

    deleteKey(&trie,keys[0]);

    printf("%s %s\n","she",search(&trie,"she")?"Present in trie":"Not present int trie");

    return 0;
}
