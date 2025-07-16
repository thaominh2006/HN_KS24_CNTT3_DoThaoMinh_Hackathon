//
// Created by Admin on 16/07/2025.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int id;
    char title[100];
    char author[100];
    char category[50];
    float price;
}Book;
typedef struct SNode{
    Book book;
    struct SNode *next;
}SNode;
typedef struct DNode{
    Book book;
    struct DNode* next;
    struct DNode *prev;
}DNode;
SNode *head = NULL;
DNode* completedBook = NULL;
int countId = 1;
int checkID(int id){
    SNode* temp = head;
    while (temp != NULL){
        if (temp -> book.id == id){
            return 1;
        }
        temp = temp -> next;
    }
    return 0;
}
void addBook(){
    SNode* newNode = (SNode *)malloc(sizeof(SNode));
    if (newNode == NULL){
        printf("Bo nho khong du de cap phat!\n");
        return;
    }
    do{
        printf("Nhap ma sach: ");
        scanf("%d", &newNode->book.id);
        if (checkID(newNode->book.id)){
            printf("Ma sach da ton tai! Vui long nhap lai.\n");
        }
    }while (checkID(newNode->book.id));
    getchar();

    printf("Nhap ten sach moi: ");
    fgets(newNode->book.title, sizeof(newNode->book.title), stdin);
    newNode->book.title[strcspn(newNode->book.title,"\n")] = '\0';

    printf("Nhap ten tac gia: ");
    fgets(newNode->book.author, sizeof(newNode->book.author), stdin);
    newNode->book.author[strcspn(newNode->book.author, "\n")] = '\0';

    printf("Nhap the loai sach moi: ");
    fgets(newNode->book.category, sizeof(newNode->book.category), stdin);
    newNode->book.category[strcspn(newNode->book.category, "\n")] = '\0';

    printf("Nhap gia sach moi: ");
    scanf("%f", &newNode->book.price);

    newNode -> next = head;
    head = newNode;
    printf("Them sach moi thanh cong!\n");
}
void displayBook(){
    SNode* temp = head;
    if (!temp){
        printf("Danh sach quan ly sach trong!\n");
        return;
    }
    printf("Danh sach sach:\n");
    while (temp){
        printf("Ma sach: %d | Ten sach: %s | Ten tac gia: %s | The loai: %s | Gia tien: %.2f VND\n", temp->book.id, temp->book.title, temp->book.author, temp->book.category, temp->book.price);
        temp = temp->next;
    }
}
void deleteBook()
{
    int id;
    printf("Nhap ma sach ban muon xoa: ");
    scanf("%d", &id);
    SNode* temp = head;
    SNode* prev = NULL;
    while (temp != NULL && temp->book.id != id){
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL){
        printf("Khong tim thay sach!\n");
        return;
    }
    if (prev == NULL){
        head = temp->next;
    }else{
        prev->next = temp->next;
    }
    free(temp);
    printf("Da xoa sach thanh cong!\n");
}
void updateBook(){
    int id;
    printf("Nhap ma sach ban muon cap nhat: ");
    scanf("%d", &id);
    getchar();
    SNode* temp = head;
    while (temp != NULL && temp->book.id != id){
        temp = temp -> next;
    }
    if (temp == NULL)
    {
        printf("Khong tim thay sach!\n");
        return;
    }
    printf("Nhap ten sach: ");
    fgets(temp->book.title, sizeof(temp->book.title), stdin);
    temp->book.title[strcspn(temp->book.title, "\n")] = '\0';

    printf("Nhap ten tac gia: ");
    fgets(temp->book.author, sizeof(temp->book.author), stdin);
    temp->book.author[strcspn(temp->book.author, "\n")] = '\0';

    printf("Nhap the loai sach: ");
    fgets(temp->book.category, sizeof(temp->book.category), stdin);
    temp->book.category[strcspn(temp->book.category, "\n")] = '\0';

    printf("Nhap gia sach: ");
    scanf("%f", &temp->book.price);
    getchar();

    printf("Cap nhat sach thanh cong!\n");
}

int main(){
    int choice;
    do
    {
        printf("********BOOK MANAGER********\n");
        printf("1. Them sach.\n");
        printf("2. Hien thi danh sach tat ca quyen sach.\n");
        printf("3. Xoa sach.\n");
        printf("4. Cap nhat thong tin mot quyen sach\n");
        printf("5. Danh dau sach da doc.\n");
        printf("6. Sap xep sach theo gia tang dan.\n");
        printf("7. Tim kiem sach theo tieu de.\n");
        printf("8. Thoat chuong trinh.\n");
        printf("Lua chon cua ban la: \n");
        scanf("%d", &choice);
        getchar();

        switch (choice){
            case 1:
                addBook();
                break;
            case 2:
                displayBook();
                break;
            case 3:
                deleteBook();
                break;
            case 4:
                updateBook();
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
            case 8:
                printf("Thoat chuong trinh!\n");
                break;
            default:
                printf("Lua chon khong hop le! Vui long chon lai\n");
        }
    }while (choice != 8);

    return 0;
}