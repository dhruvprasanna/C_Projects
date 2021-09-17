#include<stdio.h>
#include<stdlib.h>
struct stack{
    int top;
    char *operator;
};
typedef struct stack Stack;
void infixtopostfix(char *exp,char *postfix){
    Stack s;
    initstack(&s,strlen(exp));
    for(int i=o;strlen(exp);i++){
        if(isOperand(exp[i])){
            postfix[k]=exp[i];
            k++;
        }
        else if(exp[i]=='(')    
            push(&s,exp[i]);
    }
}
void push(Stack *s,char ch){
    s->top=
}
int main(){
    char exp[20],postfix[50];
    printf("\n Enter the infix expression: ");
    scanf("%d")
}