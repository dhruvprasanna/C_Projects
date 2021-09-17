//circular linked list
#include<stdio.h>
#include<stdlib.h>
struct node{
    int key;
    struct node *link;
};
typedef struct node node_t;
struct dlist{
    node_t *head;
};
typedef struct dlist list_t;

void initialise( list_t *ptr){
    ptr->head=NULL;
}
void insertfront(list_t *ptr,int k){
    node_t *new;
    node_t *cur;
    node_t *temp;
    new=(node_t *)malloc(sizeof(node_t));
    new->key=k;
    cur=ptr->head;
    temp=ptr->head; 
    new->link=cur;
    ptr->head=new;
    if (temp ==  NULL){
        new->link=new;
    }
    if(temp != NULL){
        while(temp->link != cur){
            temp=temp->link;
        }
        temp->link=new;
    }
}
void display(list_t *ptr){
    node_t *cur;
    node_t *temp;
    cur=ptr->head;
    temp=ptr->head;
    printf("<");
    while(cur->link != temp){
        printf("- %d - ",cur->key);
        cur=cur->link;
    }
    printf("- %d -> ",cur->key);
}
int main(){
    int i;
    int k;
    list_t l;
    initialise(&l);
    printf("Enter number of nodes:\n");
    scanf("%d",&i);
    for(int j =0;j<i;j++){
        printf("Enter value:\n");
        scanf("%d",&k);
        insertfront(&l,k);
    }
    display(&l);
}