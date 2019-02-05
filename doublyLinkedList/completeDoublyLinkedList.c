#include <stdio.h>
#include <stdlib.h>

struct Node{
  int data;
  struct Node* next;
  struct Node* prev;
};

int listSize = 0;
struct Node* head;

void push(int data){
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->prev = NULL;
  newNode->next = NULL;
  if(head == NULL){
    head = newNode;
    listSize++;
    return;
  }else{
    struct Node* iter = head;
    while(iter->next != NULL) iter = iter->next;
    iter->next = newNode;
    newNode->prev = iter;
    newNode->next = NULL;
    listSize++; return;
  }
}

void pop(){
  if(listSize == 0){
    printf("The list is empty, nothing to delete\n");
    return;
  }else if(listSize == 1){
    struct Node* iter = head;
    free(iter);
    head = NULL;
    listSize--;
    return;
  }else{
    struct Node* iter = head;
    while(iter->next != NULL){
      iter = iter->next;
    }
    struct Node* prevNode = iter->prev;
    prevNode->next = NULL;
    free(iter);
    listSize--;
    return;
  }
}

void display(){
  if(listSize == 0){
    printf("Nothing to display, the list is empty\n");
    return;
  }
  struct Node* iter = head;
  while(iter != NULL){
    printf("%d ", iter->data);
    iter = iter->next;
  }
  printf("\n");
  return;
}

void insertAtPosition(int data, int pos){
  if(pos <= 0 || pos > listSize+1){
    printf("Index out of bound, please enter a valid position\n");
    return;
  }else if(head == NULL){
    push(data); return;
  }else if(pos == 1){
    struct Node* headRef = head;
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = headRef;
    newNode->prev = NULL;
    headRef->prev = newNode;
    head = newNode; listSize++; return;
  }else{
    struct Node* iter = head;
    int i;
    for(i = 1; i < pos; i++){
      iter = iter->next;
    }
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    struct Node* prevNode = iter->prev;
    prevNode->next = newNode;
    newNode->prev = prevNode;
    newNode->next = iter;
    iter->prev = newNode;
    listSize++; return;
  }
}

void removeFromPosition(int pos){
  if(pos <= 0 || pos > listSize){
    printf("Index out of bound, please enter a valid position\n");
    return;
  }else if(head == NULL){
    printf("The list is empty, nothing to delete\n"); return;
  }else if(pos == listSize){
    pop(); return;
  }else if(pos == 1){
    struct Node* headRef = head;
    struct Node* nextToHead = head->next;
    free(headRef);
    nextToHead->prev = NULL;
    head = nextToHead; return;
  }else{
    struct Node* iter = head;
    int i;
    for(i = 1; i < pos; i++){
      iter = iter->next;
    }
    struct Node* prevNode = iter->prev;
    struct Node* nextNode = iter->next;
    prevNode->next = nextNode;
    nextNode->prev = prevNode;
    free(iter); listSize--; return;
  }
}

void reverseTraverse(){
  struct Node* current = head;
  while(current->next != NULL){
    current = current->next;
  }
  while(current != NULL){
    printf("%d ", current->data);
    current = current->prev;
  }
  printf("\n"); return;
}
    

int main(){

  head = NULL;
  int choice, data, pos;

  while(1){

    printf("*******************************************************\n");
    printf("*         1. Push to list                             *\n");
    printf("*         2. Pop from list                            *\n");
    printf("*         3. Display list                             *\n");
    printf("*         4. Insert at a position                     *\n");
    printf("*         5. Remove from a position                   *\n");
    printf("*         6. Reverse list                             *\n");
    printf("*         7. Exit                                     *\n");
    printf("*******************************************************\n");

    printf("Enter your choice: ");
    scanf("\n%d", &choice);
    
    switch(choice){

    case 1:
      printf("Enter the data: ");
      scanf("\n%d", &data);
      push(data);
      display();
      break;
      
    case 2:
      pop();
      display();
      break;

    case 3:
      display();
      break;

    case 4:
      printf("Enter the data: ");
      scanf("\n%d", &data);
      printf("Enter the position: ");
      scanf("\n%d", &pos);
      insertAtPosition(data, pos);
      display();
      break;

    case 5:
      printf("Enter the position: ");
      scanf("\n%d", &pos);
      removeFromPosition(pos);
      display();
      break;

    case 6:
      reverseTraverse();
      break;

    case 7:
      printf("bye!\n");
      exit(0);
      break;
    
    default:
      printf("Invalid choice!\n");
      break;
    }
  }
}
