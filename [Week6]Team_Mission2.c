#include <stdio.h>
#include <stdlib.h>

typedef struct stackNode {
    int data;
    struct stackNode* next;
} StackNode;

StackNode* createStackNode(int data) {
    StackNode* node = (StackNode*)malloc(sizeof(StackNode));
    node->data = data;
    node->next = NULL;
    return node;
}

int isEmpty(StackNode* root) {
    return !root;
}

void push(StackNode** root, int data) {
    //새로운 노드 생성 후 next를 null로 지정
    StackNode *new_node = (StackNode *)malloc(sizeof(StackNode));
    new_node->next   = NULL;
    new_node->data  = data;
    if(*root == NULL){
        *root  = new_node;
        return;
    }
    //새로운 노드의 next 를 기존 노드에 넣어 스택 구현
    new_node->next = *root;
    *root = new_node;

    printf("%d pushed to stack\n", data);
}

int pop(StackNode** root) {
    if (isEmpty(*root))
        return -9999;
    int popped;
    StackNode *temp = *root;
    popped = temp->data;
    *root = temp->next;
    free(temp);
    return popped;
}

int peek(StackNode** root) {
    if (isEmpty(*root))
        return -9999;
    return (*root)->data;
}

int main() {
    StackNode* root = NULL;

    push(&root, 10);
    push(&root, 20);
    push(&root, 30);
    push(&root, 40);

    printf("%d pop from stack\n", pop(&root));
    printf("%d pop from stack\n", pop(&root));

    push(&root, 50);
    printf("%d peeked from stack\n", peek(&root));
    printf("%d pop from stack\n", pop(&root));
    printf("%d pop from stack\n", pop(&root));
    printf("%d pop from stack\n", pop(&root));
    return 0;
}
