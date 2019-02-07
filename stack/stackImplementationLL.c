#define LINKED_LIST "linkedListStackOperations.h"

#include <stdio.h>
#include <stdlib.h>
#include LINKED_LIST

int main(){

  int choice, data;

  while(1){
    
    printf("***************************************\n");
    printf("*********  1. Push to stack   *********\n");
    printf("*********  2. Pop from stack  *********\n");
    printf("*********  3. View Top        *********\n");
    printf("*********  4. Is it Empty?    *********\n");
    printf("*********  5. Print stack     *********\n");
    printf("*********  6. Exit            *********\n");
    printf("***************************************\n");

    printf("Enter your choice: ");
    scanf("\n%d", &choice);

    switch(choice){

    case 1:
      printf("Enter data to push: ");
      scanf("\n%d",&data);
      push(data);
      printStack(head);
      printf("\n");
      break;

    case 2:
      pop();
      printStack(head);
      printf("\n");
      break;

    case 3:
      viewTop(head);
      break;
      
    case 4:
      if(isEmpty()){
		printf("The stack is empty\n");
		break;
      }else{
		printf("The stack is not empty\n");
		printStack(head);
		printf("\n");
		break;
      }

    case 5:
      if(head == NULL){
      	printf("Stack is empty\n"); 
      	break;
      }
      printStack(head);
      printf("\n");
      break;

    case 6:
      printf("Bye!\n");
      exit(0);
      break;

    default:
      printf("Invalid Choice!\n");
      break;
    }
  }
}