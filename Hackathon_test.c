//
// Created by Admin on 25/07/2025.
//

#include <stdio.h>
#include <stdlib.h>
#include<string.h>

#define MAX 100
//B1: Khoi tao Struct
typedef struct {
    char title[MAX];
}Song;

typedef struct QNode{
    Song song;
    struct QNode *next;
}QNode;
typedef struct Queue{
    QNode *front;
    QNode *rear;
}Queue;

typedef struct SNode {
    Song song;
    struct SNode *next;
}SNode;
typedef struct Stack{
    SNode*top;
}Stack;

//B2: Cac ham thao tac
void initQueue(Queue*q) {
    q->front=NULL;
    q->rear=NULL;
}

int isEmptyQueue(Queue*q) {
     return q->front==NULL;
}

void enQueue(Queue*q,Song song) {
    QNode *newNode=(QNode*)malloc(sizeof(QNode));
    newNode->song=song;
    newNode->next=NULL;
    if (q->rear==NULL) {
        q->front=newNode;
        q->rear=newNode;
    }else {
        q->rear->next=newNode;
        q->rear=newNode;
    }
}

int deQueue(Queue*q,Song *song) {
    if (isEmptyQueue(q)) {
        printf("Hang doi rong\n");
        return 0;
    }
    QNode *temp=q->front;
    *song=temp->song;
    q->front=q->front->next;
    if (q->front==NULL) {
        q->rear=NULL;
    }
    free(temp);
    return 1;
}

//Stack function
void initStack(Stack*s) {
    s->top=NULL;
}

int isEmptyStack(Stack*s) {
    return s->top==NULL;
}

void push(Stack*s,Song song) {
    SNode* newNode=(SNode*)malloc(sizeof(SNode));
    newNode->song=song;
    newNode->next=s->top;
    s->top=newNode;
}

int pop(Stack*s,Song *song) {
    if (isEmptyStack(s)) {
        printf("Stack rong\n");
        return 0;
    }
    SNode*temp=s->top;
    *song=temp->song;
    s->top=s->top->next;
    free(temp);
    return 1;
}

void displayHistory(Stack*s) {
    if (isEmptyStack(s)) {
        printf("Lich su phat rong!\n");
        return;
    }
    printf("\nPlayed Songs History\n");
    SNode*current=s->top;
    while(current!=NULL) {
        printf("%s\n",current->song.title);
        current=current->next;
    }
}


int main() {
    Queue nextQueue;
    initQueue(&nextQueue);
    Stack historyStack;
    initStack(&historyStack);

    int choice;
    char input[MAX];
    Song currentSong;

    do {
        printf("\n=== MUSIC PLAYER ===\n");
        printf("1. ADD\n");
        printf("2. PLAY NEXT\n");
        printf("3. PLAY PREVIOUS\n");
        printf("4. HISTORY\n");
        printf("5. EXIT\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                printf("Nhap ten bai hat: ");
                fgets(input, sizeof(input), stdin);
                input[strcspn(input, "\n")] = '\0';
                strcpy(currentSong.title, input);
                enQueue(&nextQueue,currentSong);
                printf("Da them bai hat %s vao hang doi\n", currentSong.title);
                break;
            case 2:
                if (deQueue(&nextQueue,&currentSong)) {
                    push(&historyStack,currentSong);
                    printf("Dang phat bai hat: %s\n", currentSong.title);
                }else {
                    printf("Khong co bai hat trog hang doi\n");
                }

                break;
            case 3:
                if (pop(&historyStack,&currentSong)) {
                    printf("Quay lai bai truoc: %s\n", currentSong.title);
                }else {
                    printf("Khong co bai truoc de quay lai\n");
                }
                break;
            case 4:
                displayHistory(&historyStack);
                break;
            case 5:
                printf("Dang thoat chuong trinh\n");
                return 0;
            default:
                printf("Lua chon khog hop le. Thu lai!");
                break;
        }
    }while (choice != 5);

    return 0;

}