#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int A[MAX_SIZE];

int top = -1;

void push(int data){
  A[++top] = data; return;
}

void pop(){
  if(top == -1){
    printf("The stack is already empty, nothing to remove\n");
    return;
  }
  --top; return;
}

void viewTop(){
  if(top == -1){
    printf("Stack is empty\n");
    return;
  }
  printf("Top of the stack: %d\n", A[top]);
  return;
}

int isEmpty(){
  return top==-1?1:0;
}

void printStack(){
  int i;
  for(int i = 0; i <= top; i++){
    printf("%d ",A[i]);
  }printf("\n");
  return;
}

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
      printStack();
      break;

    case 2:
      pop();
      printStack();
      break;

    case 3:
      viewTop();
      break;
      
    case 4:
      if(isEmpty()){
	printf("The stack is empty\n");
	break;
      }else{
	printf("The stack is not empty\n");
	printStack();
	break;
      }

    case 5:
      printStack();
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
