#include <stdio.h>
#include <stdlib.h>

struct Node{
  int data;
  struct Node* next;
};

struct Node* head;
int listSize = 0;

void push(int data){
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode->data = data;
  if(head == NULL){
    newNode->next = head;
    head = newNode;
    listSize++;
    return;
  }
  struct Node* iter = head;
  
  while(iter->next != NULL){
    iter = iter->next;
  }
  iter->next = newNode;
  newNode->next = NULL;
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

void insert(int data, int pos){
  if(pos == listSize || (head == NULL && pos == 1)){
    push(data);
    return;
  }else if(pos > listSize || pos <= 0){
    printf("Index out of bound, please check the list size and try again\n");
    return;
  }else if(pos == 1){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
    return;
  }
  struct Node* iter = head;
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  int i;
  for(i = 0; i < pos-2; i++){
    iter = iter->next;
  }
  newNode->data = data;
  newNode->next = iter->next;
  iter->next = newNode;
}

void delete(int pos){
  if(pos > listSize || pos <= 0){
    printf("Index out of bound, please check the list size and try again\n");
   return;
  }else if(pos == listSize){
    pop();
    return;
  }else if(pos == 1){
    struct Node* iter = head;
    head = iter->next;
    free(iter);
    return;
  }else if(listSize == 1){
    pop();
    return;
  }
  struct Node* iter = head;
  int i;
  for(i = 0; i < pos-1; i++){
    iter = iter->next;
  }
  struct Node* nodeToDelete = iter->next;
  iter->next = nodeToDelete->next;
  free(nodeToDelete);
}

void forwardPrintWithRecursion(struct Node* head){
  if(head == NULL) return;
  printf("%d ", head->data);
  forwardPrintWithRecursion(head->next);
}

void reversePrintWithRecursion(struct Node* head){
  if(head == NULL) return;
  reversePrintWithRecursion(head -> next);
  printf("%d ", head->data);
}

void reverseListWithRecursion(struct Node* current){
  if(current->next == NULL){
    head = current;
    return;
  }
  reverseListWithRecursion(current->next);
  struct Node* prev = current->next;
  prev->next = current;
  current->next = NULL;
}

void delete_list(struct Node* head){
  
  while(head->next != NULL){
    struct Node *temp = head;
    head = head->next;
    free(temp);
  }

  free(head);
  return;
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

void size(){
  printf("Size of the list is: %d\n", listSize);
}

int is_empty(){
  if(head == NULL || 
    listSize == 0){
    printf("The list is empty\n");
    return 0;
  }
  return 1;
}

int main(){
   head = NULL;
   while(1){

    printf("**********************************************\n");
    printf("*    Welcome to linked list                  *\n");
    printf("*    1. Push to the list                     *\n");
    printf("*    2. Pop from the list                    *\n");
    printf("*    3. Insert at a position                 *\n");
    printf("*    4. Delete from a position               *\n");
    printf("*    5. Display list size                    *\n");
    printf("*    6. Display list                         *\n");
    printf("*    7. Print list using recursion           *\n");
    printf("*    8. Reverse print list using recursion   *\n");
    printf("*    9. Reverse list using recursion         *\n");
    printf("*    10.!!! DELETE LIST !!!                  *\n");    
    printf("*    11.Exit                                 *\n");
    printf("**********************************************\n");
    
    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);
    struct Node* refHead = head;
    
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

    case 3:
      printf("Enter position to insert at: ");
      int pos;
      scanf("\n%d", &pos);
      //printf("\n");
      printf("Enter data: ");
      scanf("%d", &data);
      printf("\n");
      insert(data, pos);
      display();
      break;

    case 4:
      if(listSize == 0){
      	printf("The list is empty, deletion not possible\n");
      	break;
      }
      printf("Enter the position to delete from: ");
      scanf("\n%d", &pos);
      delete(pos);
      display();
      break;
      
    case 5:
      size();
      break;

    case 6:
      display();
      break;

    case 7:
      if(is_empty() == 0)
        break;
      forwardPrintWithRecursion(refHead);
      printf("\n");
      break;

    case 8:
      if(is_empty() == 0)
        break;
      reversePrintWithRecursion(refHead);
      printf("\n");
      break;

    case 9:
      if(is_empty() == 0)
        break;
      reverseListWithRecursion(refHead);
      display();
      break;

    case 10:
      delete_list(refHead);
      printf("Deleted the list!\n");
      head = NULL; listSize = 0;
      break;

    case 11:
      printf("Bye!\n");
      exit(0);
      break;

    default:
      printf("Invalid choice\n");
      printf("\n\n\n\n\n\n\n\n");
    }
  }
}
