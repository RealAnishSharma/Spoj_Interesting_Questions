#include <iostream>
#include<cstring>
#include<cstdio>

using namespace std;
#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])
#define ALPHABET_SIZE 26
#define CHAR_TO_INDEX(c) ((int)c-(int)'a')
#define FREE(p) free(p); p=NULL;

struct TrieNode
{
    struct TrieNode *children[ALPHABET_SIZE];
    bool isLeaf;
};

struct TrieNode *getNode(void)
{
    struct TrieNode *pNode =new struct TrieNode;
   // pNode=(struct TrieNode*)malloc(sizeof(struct TrieNode));

    if(pNode)
    {
        int i;
        pNode->isLeaf=false;
        for(i=0;i<ALPHABET_SIZE;i++)
            pNode->children[i]=NULL;
    }
    return pNode;
}


void insert(struct TrieNode *root,const char *key)
{
    int level,index;
    int length=strlen(key);
    struct TrieNode *pCrawl=root;
    for(level=0;level<length;level++)
    {
        index=CHAR_TO_INDEX(key[level]);
        if(!pCrawl->children[index])
            pCrawl->children[index]=getNode();

        pCrawl=pCrawl->children[index];
    }

    pCrawl->isLeaf=true;
}

bool search(struct TrieNode *root,const char *key)
{
    int level,index;
    int length=strlen(key);
    struct TrieNode *pCrawl=root;

    for(level=0;level<length;level++)
    {
        index=CHAR_TO_INDEX(key[level]);
        if(!pCrawl->children[index])
            return false;

        pCrawl=pCrawl->children[index];
    }
    return (pCrawl!=NULL && pCrawl->isLeaf);
}











int main()
{
    char bb[100];
    char keys[][8]={"the","a","there","answer","any","by","bye","their"};
    char output[][32]={"Not present in trie","Present in trie"};
    struct TrieNode *root=getNode();

    int i;
    for(i=0;i<ARRAY_SIZE(keys);i++) insert(root,keys[i]);

    while(1)
    {

        scanf(" %s",bb);
        printf("%s --- %s\n",bb,output[search(root,bb)]);
    }
    return 0;
}
