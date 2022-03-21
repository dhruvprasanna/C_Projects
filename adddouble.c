///hopefully this shit actually works finally
#include<stdio.h>
#include<stdlib.h>

struct node{
    int key;
    struct node *rlink;
    struct node *llink;
};

typedef struct node node_t;

struct dlist{
    node_t *head;
};

typedef struct dlist list_t;

void initialise(list_t *ptr){
    ptr->head=NULL;
}
void insertfront(list_t *ptr,int k){
    node_t *new;
    node_t *cur;
    if (ptr->head==NULL){
        new=(node_t *)malloc(sizeof(node_t));
        new->rlink=NULL;
        new->key=k;
        new->llink=NULL;
        ptr->head=new;
    }
    else{
        new=(node_t *)malloc(sizeof(node_t));
        cur=ptr->head;
        new->rlink=cur;
        new->key=k;
        new->llink=NULL;
        cur->llink=new;
        ptr->head=new;
        
    }
}
void display(list_t *ptr){
    node_t *cur;
    cur=ptr->head;
    while (cur != NULL){
        printf("%d - ",cur->key);
        cur=cur->rlink;
    }
    printf("NULL\n");
}
void add(list_t *ptr1 ,list_t *ptr2){
    node_t *cur1;
    node_t *prev1;
    cur1=ptr1->head;
    while(cur1!=NULL){
        prev1=cur1;
        cur1=cur1->rlink;
    }
    node_t *cur2;
    node_t *prev2;
    cur2=ptr2->head;
    while(cur2!=NULL){
        prev2=cur2;
        cur2=cur2->rlink;
    }
    node_t *start;
    start=ptr1->head;
    while(prev1 != start->llink){
        if((prev1->key+prev2->key)>=10){
           if(prev1->llink==NULL){
                node_t *newv;
                node_t *lol;
                newv=(node_t *)malloc(sizeof(node_t));
                lol=prev1;
                newv->rlink=lol;
                prev1->llink=newv;
                newv->key=1;
                prev1->key=(prev1->key+prev2->key)%10;
                ptr1->head=newv;
            }
            else{
                prev1->key=(prev1->key+prev2->key)%10;
                node_t *n;
                n=prev1->llink;
                n->key++;
            }

        }
        else{
            prev1->key=(prev1->key+prev2->key);
        }
        prev1=prev1->llink;
        prev2=prev2->llink;
    }
}
int main(){
    int choice,k;
    list_t l1;
    list_t l2;
    while(1){
        printf("\n1:Initialise Lists\n2.Insert element in N1\n3.Insert Element in N2\n4.Display Number 1\n5.Display Number 2\n6.Add\n7.Exit\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                initialise(&l1);
                initialise(&l2);
                break;
            case 2:
                printf("Enter element\n");
                scanf("%d",&k);
                insertfront(&l1,k);
                break;
            case 3:
                printf("Enter element\n");
                scanf("%d",&k);
                insertfront(&l2,k);
                break;
            case 4:
                display(&l1);
                break;
            case 5:
                display(&l2);
                break;
            case 6:
                add(&l1,&l2);
                display(&l1);
                break;
            case 7:
                exit(0);
            default:
                exit(0);
        }
    }
}