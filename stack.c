/* follows last in first out. Linear data structure.
Push - to add element
Pop - remove 1 item - which was last put in to the stack
Peek - see whats on the top of stack.

If empty stack, we set top = -1
If stack implemented using arrays/list , then we can set (size of array-1) = size of stack. Just a limit for size of stack
*/

/* Q) Implement stack data structure using arrays */
#include<stdio.h>
#include<stdlib.h>
struct stack{
    int top;
    int *arr;
    int Maxsize;
};
typedef struct stack Stack;

void initialize(Stack *S, int size){
    S->top=-1;
    S->Maxsize=size;
    //allocating memory for "size" no of elements
    S->arr=(int *)malloc(S->Maxsize*sizeof(int));
}
int isfull(Stack *S){
    if(S->top==(S->Maxsize-1))
        return 1;
    return 0;
}

void push(Stack *S,int ele){
    //always check overflow condiiton before placing element into stack
    if(!isfull(S)){
        //meaning: if stack is not full
        S->top++;
        S->arr[S->top]=ele;
        printf("%d",S->arr[S->top]);
        return;
    }
    printf("\n Stack overflow, could not push element into stack\n");
}


int isempty(Stack *S){
    if(S->top==-1)
        return 1;//empty stack
    return 0;//if stack is not empty
}

int pop(Stack *S){
    //check stack underflow condition
    int ele;
    if(!isempty(S)){
        ele=S->arr[S->top];
        S->top--;
        printf("%d",ele);
        return ele;
    }
    printf("\n STack underflow....Element cant be removed from an empty stack");
    return -1;//since func is int type, we need to return for fail case as well
}

int main(){
    Stack S;
    int size,ele;
    printf("\n Stack size\n");
    scanf("%d", &size);
    initialize(&S,size);
    push(&S,10);
    push(&S,20);
    push(&S,30);

    ele=pop(&S);
    if(ele==-1)
        printf(" \n %d popped\n", ele);
    
    ele=pop(&S);
    if(ele==-1)
        printf(" \n %d popped\n", ele);
    
    ele=pop(&S);
    if(ele==-1)
        printf(" \n %d popped\n", ele);
    
    ele=pop(&S);
    if(ele==-1)
        printf(" \n %d popped\n", ele);
}