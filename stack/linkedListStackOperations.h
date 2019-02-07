struct Node{
  int data;
  struct Node* next;
  struct Node* prev;
};

struct Node* head = NULL;

void push(int data){
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode->data = data;
  if(head == NULL){
    newNode->next = NULL;
    newNode->prev = NULL;
    head = newNode;
    return;
  }
  struct Node* prevNode = head;
  newNode->prev = prevNode;
  prevNode->next = newNode;
  newNode->next = NULL;
  head = newNode;
  return;
}

void pop(){
  if(head == NULL){
    printf("The stack is already empty\n");
    return;
  }else{
    struct Node* headNode = head;
    head = headNode->prev;
    free(headNode); return;
  }
}

void viewTop(){
  if(head == NULL){
    printf("The stack is empty\n");
    return;
  }else{
    printf("Top of stack: %d\n", head->data);
    return;
  }
}

int isEmpty(){
  return head == NULL?1:0;
}

void printStack(struct Node* head){
  if(head == NULL) return;
  printStack(head->prev);
  printf("%d ",head->data);
}
    
  
    
