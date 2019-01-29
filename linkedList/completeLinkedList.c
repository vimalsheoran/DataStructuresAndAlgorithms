#include <stdio.h>
#include <stdlib.h>

struct Node{
  int data;
  struct Node* next;
};

struct Node* head;
int listSize = -1;

void push(int data){
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = NULL;
  if(head == NULL){
    head = newNode;
    listSize++;
    return;
  }
  struct Node* iter = head;
  while(iter != NULL){
    iter = iter->next;
  }
  iter->next = newNode;
  listSize++;
}

void pop(){
  if(head == NULL || listSize == -1){
    printf("The list is already empty\n");
    return;
  }else if(listSize == 0){
    struct Node* temp = head;
    free(temp);
    head = NULL;
    listSize--;
    return;
  }
  int i;
  struct Node* iter = head;
  for(i = 0; i < listSize-1; i++){
    iter = iter->next;
  }
  free(iter->next);
  iter->next = NULL;
  listSize--;
}

void display(){
  struct Node* temp = head;
  if(listSize == -1 || head == NULL){
    printf("Nothing to display, the list is empty\n");
    return;
  }
  while(temp != NULL){
    printf("%d ", temp->data);
    temp = temp->next;
  }printf("\n");
}

int main(){
   head = NULL;
   while(1){

    printf("Welcome to linked list\n");
    printf("1. Push to the list\n");
    printf("2. Pop from the list\n");
    printf("3. Insert at a position\n");
    printf("4. Delete from a position\n");
    printf("5. Display list size\n");
    printf("6. Display list\n");

    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice){

    case 1:
      printf("Enter data to push: ");
      int data;
      scanf("%d", &data);
      push(data);
      display();
      break;

    case 2:
      pop();
      display();
      break;

    case 6:
      display();
      break;

    default:
      printf("Invalid choice\n");
      printf("\n\n\n\n\n\n\n\n");
    }
  }
}
