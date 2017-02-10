/*
 * libll.c
 *
 *  Created on: 02 feb. 2017
 *  By: Johan Kämpe
 */

/*   Linked list functions  */

#include "libll.h"

/*  Inserts value last in list   */
void insLast(node * n, int val){
  while(!isEmpty(getNext(n))){
    n = getNext(n);
  }
  n->next = createNode(val);
}

/*  Inserts value first in list,
    returns pointer to first node   */
node * insFirst(node * n, int val){
  if(isEmpty(n)){
    n = createNode(val);
  }
  else{
    node * temp = n;
    n = createNode(val);
    n->next = temp;
  }
  return n;
}

/*  Check if node is empty  */
bool isEmpty(node * n){
  return (n == NULL);
}

/*  Creates a new node, returns pointer   */
node * createNode(int val){
  node * newNode = (node *)malloc(sizeof(node));
  /*  Security check   */
  if(isEmpty(newNode)){
    printf("Malloc of new node failed!\n");
    return NULL;
  }
  newNode->value = val;
  newNode->next = NULL;
  return newNode;
}

/*  Returns the next node in the list   */
node * getNext(node * n){
  return n->next;
}

/*  Returns the node at position num the list   */
node * getNode(node * n, int num){
  int i = num - 1;
  if(!i){
    return n;
  }
  while(i--){
    if(isEmpty(getNext(n))){
      printf("Cant get node at %d, outside list!\n", num);
      return NULL;
    }
    else{
      n = getNext(n);
    }
  }
  return n;
}

/*  Returns number of items in list   */
int countItems(node * n){
  int c = 0;
  while(!isEmpty(n)){
    c++;
    n = getNext(n);
  }
  return c;
}

/*  Remove node from list   */
node * removeNode(node * list, node * n){
  node * newTop = list;
  /*   If node to remove is the first node  */
  if(list == n){
    newTop = getNext(list);
    return newTop;
  }
  /*  Go to node before node to remove   */
  while(getNext(list) != n){
    list = getNext(list);
  }
  /*  Skip next node   */
  if(isEmpty(getNext(n))){
    list->next = NULL;
  }
  else{
    list->next = getNext(n);
  }
  return newTop;
}
