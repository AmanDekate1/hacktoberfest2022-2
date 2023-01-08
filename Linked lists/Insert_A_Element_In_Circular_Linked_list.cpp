#include <iostream>
using namespace std;

struct Node{
    int data;
    struct Node *next;
}*head;

void create(int A[],int n){
    struct Node *t, *last;
    head=(struct Node *)malloc(sizeof(struct Node));
    head->data=A[0];
    head->next=head;
    last=head;
    for(int i=1;i<n;i++){
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=last->next;
        last->next=t;
        last=t;
    }
}

void display(struct Node *h){
    do{
        printf("%d ",h->data);
        h=h->next;
    }while(h!=head);
    printf("\n");
}

int Length(struct Node *p){
    int len=0;
    do{
        len++;
        p=p->next;
    }while(p!=head);
    return len;
}

void Insert(struct Node *p,int index, int x){
    if(index<0 || index>Length(p))      //if invalid index, return
        return;
    struct Node *t;
    //if we are inserting before 'head'
    if(index==0){
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=x;
        //if circular LL is empty
        if(head=NULL){
            head=t;
            head->next=head;
        }else{                   //we want 'p' to point to hole before head
            while(p->next!=head)
                p=p->next;
            p->next=t;
            t->next=head;
            head=t;             //new node 't' is now 'head'
        }
    }
    else{
        //we want 'p' to point to node just before index
        for(int i=0;i<index-1;i++)
            p=p->next;
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=x;
        t->next=p->next;
        p->next=t;
    }
}

int main(){
    int A[]={5,10,15,20,25};
    create(A,5);
    display(head);
    Insert(head,2,2000);
    display(head);
    Insert(head,0,0);
    display(head);
    return 0;
}
