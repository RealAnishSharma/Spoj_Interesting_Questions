#include<iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;
//Node Structure of XOR List
struct Node
{
  int data;
  struct Node *x_ptr;
};

//XOR Operation on addresses of two nodes
struct Node * Xor(struct Node *m, struct Node *n)
{
  return (struct Node *)((unsigned)m ^ (unsigned)n);
}

//Inserting into XOR List from start of list
void insert(struct Node **head, int x)
{
  //Create a new node to be inserted
  struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
  temp->data = x;

  //As it is inserted at beginning its x_ptr will (NULL XOR head)
  temp->x_ptr = Xor(NULL,(*head));

  //If list is not empty then x_ptr of head will be (new node XOR next node)
  if((*head) != NULL)
  {
    //Get address of Next Node
    struct Node *nextNode = Xor(NULL,(*head)->x_ptr);

    //Store XOR of new node and next node
    (*head)->x_ptr = Xor(temp,nextNode);
  }

  //Make the new node as head
  *head = temp;
}

//Printing XOR List
void printList(struct Node *head)
{
  struct Node *previous, *current, *next;
  previous = NULL;
  current = head;

  while(current)
  {
    //print data of current node
    printf(" %d ",current->data);

    //get address of next node as (previous node XOR (previous XOR next node))
    //where current->x_ptr = (previous XOR next node)
    next = Xor(previous,current->x_ptr);

    //update previous and current for next iteration
    previous = current;
    current = next;
  }

  printf("\n");
}

int main()
{
  /*Create doubly linked list as 10->20->30->40->50 */

  struct Node *head=NULL;
  insert(&head,50);
  insert(&head,40);
  insert(&head,30);
  insert(&head,20);
  insert(&head,10);

  //Print the XOR list
  printList(head);

  return 0;
}
