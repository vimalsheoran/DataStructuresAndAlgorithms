#include <stdio.h>
#include <stdlib.h>

struct Node{
  int data;
  struct Node* next;
};

struct Node* head;
int listSize = -1;

void push(int data){
  struct Node* newNode = (Node*)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = NULL;
  if(head == NULL){
    head = newNode;
    return;
  }
  struct Node* iter = head;
  while(iter != NULL){
    iter = iter->next;
  }
  iter->next = newNode;
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
    scanf("%d\n", &choice);

    switch(choice){

    case 1:
      int data;
      printf("Enter data to push: ");
      scanf("%d\n", &data);
      push(data);
      break;

    default:
      printf("Invalid choice\n");
      printf("\n\n\n\n\n\n\n\n");
    }
  }
}
