/*   Integer linked list functions 

		by Johan Kämpe
    https://www.linkedin.com/in/johankampe/
    https://github.com/GoblinDynamiteer/

*/

#include "libll.h"

/*  Inserts value last in list
    returns pointer to first node   */
node * insLast(node * n, int val){
  node * top = n;
  if(isEmpty(n)){
    top = createNode(val);
  }
  else{
    while(!isEmpty(getNext(n))){
      n = getNext(n);
    }
    n->next = createNode(val);
  }
  return top;
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
  if(isEmpty(n->next)){
    //printf("Next is empty, returning NULL\n");
    return NULL;
  }
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

/*  Frees node of a given linked list   */
node * freeNodes(node * list){
  if(isEmpty(list)){
    return NULL;
  }
  if(isEmpty(getNext(list))){
    free(list);
    return NULL;
  }
  else{ //Not ideal.
    node * next = getNext(list);
    node * current = list;
    free(current);
    while(!isEmpty(getNext(next))){
      current = next;
      next = getNext(next);
      free(current);
    }
  }
  return NULL;
}

/*	Print list values	*/
void printList(node * list){
	int count = countItems(list);
	for(int i = 0; i < count; i++){
		printf("node %03d: %d\n", i+1, list->value);
		list = getNext(list);
	}
}
