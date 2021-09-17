///reversing a linked list
#include<stdio.h>
#include<stdlib.h>

struct node{
    int value;
    struct node *link;
};

typedef struct node node_t;

struct list{
    node_t *head;
};
typedef struct list list_t;

void initialise( list_t *ptr){
    ptr->head=NULL;
}
 void insert( list_t *ptr){
    node_t *new;
    int val;
    
    new=(node_t *)malloc(sizeof(node_t));
   
    printf("\nEnter value: \n");
    scanf("%d",&val);
    new->value=val;
    new->link=NULL;
    new->link=ptr->head; 
    ptr->head=new;
        
}
void display( const list_t *ptr){
    node_t *cur;
    cur=ptr->head;
    while(cur != NULL){
        printf("%d - ",cur->value);
        cur=cur->link;
    }
    printf("NULL\n");
}

void reverse(list_t *ptr,list_t *reversed){
    node_t *cur;
    node_t *new;
    int i=2;
    cur=ptr->head;
    reversed->head=NULL;
    while(cur != NULL){
        new=(node_t *)malloc(sizeof(node_t)); 
        new->value=cur->value;
        new->link=NULL;
        new->link=reversed->head; 
        reversed->head=new;
        cur=cur->link;
    }
}

void swap(list_t *ptr,int v1,int v2){
    node_t *n1;
    node_t *n2;
    node_t *prev1;
    node_t *prev2;
    node_t *temp;
    n1=ptr->head;
    n2=ptr->head;
    while(n1->value != v1){
        prev1=n1;
        n1=n1->link;
    }
    while(n2->value != v2){
        prev2=n2;
        n2=n2->link;
    }
    prev1->link=n2;
    prev2->link=n1;
    temp=n1->link;
    n1->link=n2->link;
    n2->link=temp;
}

int main(){
    list_t l;
    list_t reversed;
    while(1){
        printf("1.Initialise list\n2.Insert Element\n3.Display\n4.Print Reveresed list\n5.Swap nodes\n6.Exit\n");
        int choice;
        int a, b;
        scanf("%d",&choice);
        switch(choice){
            case 1:
                initialise(&l);
                break;
            case 2:
                insert(&l);
                break;
            case 3:
                display(&l);
                break;
            case 4:
                reverse(&l,&reversed);
                display(&reversed);
                break;
            case 5:
                printf("Enter value of node you wish to swap: \n");
                scanf("%d %d",&a,&b);
                swap(&l,a,b);
                display(&l);
                break;
            case 6:
                exit(0);
            default:
                exit(0);
        }
    }
    return 0;
}