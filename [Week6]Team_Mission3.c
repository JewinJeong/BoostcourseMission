#include <stdio.h>
#include <stdlib.h>

typedef struct queue {
    int front;
    int rear;
    int size;
    int capacity;
    int* array;
} Queue;

Queue* createQueue(int capacity) {
    Queue* queue = (Queue *)malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->front = 0;
    queue->size = 0;
    queue->rear = capacity-1; // 왜 이렇게 초기화 했는지 잘 생각해 보세요!
    queue->array = (int *)malloc(sizeof(int)*queue->capacity);
    return queue;
}

int isFull(Queue* queue) {
    return (queue->size == queue->capacity);
}

int isEmpty(Queue* queue) {
    return (queue->size == 0);
}

void enqueue(Queue* queue, int item) {
    if (isFull(queue)) {
        return;
    }
    // queue->array[queue->front++] = item;
    // queue->size++;
	queue->rear = (queue->rear + 1)%(queue->capacity); 
	/* if (q->rear +1) = capacity, q->rear = 0; */
	queue->array[queue->rear] = item;
	queue->size++;
    printf("%d enqueued to queue\n", item);
}

int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        return -9999;
    }
    int item = queue->array[queue->front];
	queue->front = (queue->front + 1)%(queue->capacity); 
	/* 배열의 끝에 도달(q->front+1 == capacity)하면 다시 0으로 돌아감 */
	queue->size--;
    return item;
}


int main() {
    Queue* queue = createQueue(1000);

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);

    printf("%d dequeued from queue\n", dequeue(queue));
    printf("%d dequeued from queue\n", dequeue(queue));
    printf("%d dequeued from queue\n", dequeue(queue));
    printf("%d dequeued from queue\n", dequeue(queue));
    return 0;
}
