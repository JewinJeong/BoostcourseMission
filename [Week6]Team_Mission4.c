#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* next;
} Node;

void append(Node* head, int data) {
    Node *tmp = (Node *)malloc(sizeof(Node));
	tmp->data = data;
	tmp->next = head->next;
    head->next = tmp;

    
}

int getLastNode (Node* head, int k) {
    if (k < 0)
		return -999;
	Node *p = head;
	for (int i=0; i<k && p!=NULL; i++)
		p = p->next;
	return p->data;
}

void printList(Node* head) {
	Node *curr = head->next;
    while (curr != NULL)               // 포인터가 NULL이 아닐 때 계속 반복
    {
        printf("%d ", curr->data);  
        curr = curr->next;             
    }
    printf("\n");
}

int main() {
    Node* head = (Node*)malloc(sizeof(Node));
    append(head, 9);
    append(head, 8);
    append(head, 4);
    append(head, 14);
    append(head, 5);

    printList(head);

    printf("\n%dth last node is %d\n", 2, getLastNode(head, 2));
}
