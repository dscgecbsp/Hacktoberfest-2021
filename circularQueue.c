#include<stdio.h>
#include<stdlib.h>
struct circularQueue{
    int size;
    int f, r;
    int *arr;
};
int isEmpty(struct circularQueue *q){
    if(q->f==q->r){
        return 1;
    }
    else{
        return 0;
    }
}
int isFull(struct circularQueue* q){
    if((q->r+1)%q->size==q->f){
        return 1;
    }
    else{
        return 0;
    }
}
void enqueue(struct circularQueue* q, int val){
    if(isFull(q)){
        printf("Circular queue is full");
    }
    else{
        q->r = (q->r+1)%q->size;
        q->arr[q->r] = val;
        printf("Enqueued element is %d\n", val);
    }
}
int dequeue(struct circularQueue* q){
    int val = -1;
    if(isEmpty(q)){
        printf("Circular queue is empty");
    }
    else{
        q->f = (q->f+1)%q->size;
        val = q->arr[q->f];
        printf("Dequeued element is %d\n", val);
    }
    return val;
}
void queueTraverse(struct circularQueue* q){
    for(int i=q->f; i>q->r; i=(i+1)%q->size){
        printf("Element: %d\n", q->arr[i]);
    }
}
int main(){
    struct circularQueue q;
    q.size = 4;
    q.f = q.r = -1;
    q.arr = (int *)malloc(q.size*sizeof(int));
    enqueue(&q, 12);
    enqueue(&q, 23);
    enqueue(&q, 34);
    enqueue(&q, 45);
    enqueue(&q, 56);
    queueTraverse(&q);
    printf("Removed element: %d\n", dequeue(&q));
    queueTraverse(&q);
    return 0;
}