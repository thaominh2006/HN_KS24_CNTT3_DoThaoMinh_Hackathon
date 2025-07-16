//
// Created by Admin on 16/07/2025.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 100

typedef struct Node{
    char command[MAX_LEN];
    struct Node* next;
}Node;

typedef struct Stack
{
    Node* top;
}Stack;
void initStack(Stack *s)
{
    s -> top = NULL;
}
int isEmpty(Stack *s)
{
    return s -> top = NULL;
}
void push(Stack *s, const char *cmd)
{
    Node *newNode = (Node *)malloc(sizeof(Node *));
    if (newNode == NULL)
    {
        printf("Bo nho khong du de cap phat!\n");
        return;
    }
    strcpy(newNode->command, cmd);
    newNode->next = s -> top;
    s -> top = newNode;
}
int main()
{
    Stack historyStack;
    initStack(&historyStack);
    Stack redoStack;
    initStack(&redoStack);
    char input[MAX_LEN];
    int choice;
    do
    {
        printf("********TERMINAL HISTORY********\n");
        printf("1. Insert: Go lenh moi.\n");
        printf("2. Undo: Hoan tac lenh gan nhat.\n");
        printf("3. Redo: Phuc hoi lenh vua undo.\n");
        printf("4. Hien thi: In toan bo lich su lenh.\n");
        printf("5. Thoat: Ket thuc chuong trinh.\n");
        printf("Lua chon cua ban la: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Nhap lenh moi: ");
            fgets(input, sizeof(input), stdin);
            input[strcspn(input, "\n")] = '\0';
            push(&historyStack, input);
            printf("Da them lenh moi!\n");
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            printf("Thoat chuong trinh.\n");
            break;
        default:
            printf("Lua chon khong hop le!");
        }
    }while (choice != 5);
    return 0;
}

