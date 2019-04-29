#include<stdio.h>
#include<stdlib.h>

// Node
// PageEntry
// PageTable
// enq
// deq


struct node{
	int data;
	struct node *next;
};
typedef struct node Node;

struct pageentry{
	int page;
	int frame;
};
typedef struct pageentry PageEntry;

struct pagetable{
	int no_pages; //to iterate thrugh entries(no of entries = no of pages)
	PageEntry entry[10];
};
typedef struct pagetable PageTable;


Node *current = NULL;
Node *prev = NULL;

void printList(Node *head)
{
    Node *ptr = head;
    while(ptr != NULL) {
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

Node* enq(Node *head, int data)
{
    Node *link = (Node*)malloc(sizeof(Node));
    link->data = data;
    link->next = head;
    head = link;
    return head;
}
Node* deq(Node* head)
{
    Node *temp = head;
    if(head == NULL) return head;
    else if(head->next == NULL) {
        free(head);
        head = NULL;
        return head;
    }
    for(temp = head; temp->next != NULL; temp = temp->next)
        prev = temp;
    free(temp);
    prev->next = NULL;
    return head;
}

int memsize = 32;
int pagesize = 2;



int main(){
	Node* head = NULL;
	int frameno = memsize/pagesize;
	for (int i = 0; i < (frameno/2); ++i){
		head = enq(head,rand()%frameno);
	}
	printList(head);

	PageTable table[10];
	table[0].entry[0].page=1;
	table[0].entry[0].frame=3;
	printf("%d\n", table[0].entry[0].frame);
	return 0;
}