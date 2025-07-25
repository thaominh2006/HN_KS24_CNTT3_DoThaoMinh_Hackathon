//
// Created by Admin on 25/07/2025.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NAME 100

typedef struct Product{
    int id;
    char name[MAX_NAME];
    float price;
    int quantity;
}Product;
typedef struct SNode{
    Product product;
    struct SNode* next;
}SNode;
typedef struct DNode{
    Product product;
    struct DNode* next;
    struct DNode* prev;
}DNode;
void showMenu(){
    printf("********PRODUCT MANAGER********\n");
    printf("1. Them san pham.\n");
    printf("2. Hien thi danh sach san pham.\n");
    printf("3. Xoa san pham theo ID.\n");
    printf("4. Cap nhat thong tin san pham.\n");
    printf("5. Danh dau san pham da ban.\n");
    printf("6. Hien thi danh sach san pham da ban.\n");
    printf("7. Sap xep san pham theo gia tang dan.\n");
    printf("8. Tim kiem san pham theo ten.\n");
    printf("9. Dua tren danh sach san pham dang ban, tao mot cay nhi phan theo price cua san pham. Sau do cho phpe hien thi san pham theo gia tang dan.\n");
    printf("10. Thoat\n");
}
int countID = 1;
Product inputProduct(SNode* head){
    Product product;
    char tempName[MAX_NAME];
    while (1){
        printf("Nhap ten san pham: ");
        fgets(tempName, sizeof(tempName), stdin);
        tempName[strcspn(tempName, "\n")] = '\0';

        int isDuplicate = 0;
        SNode* current = head;
        while (current != NULL){
            if (strcasecmp(current->product.name, tempName) == 0){
                isDuplicate = 1;
                break;
            }
            current = current->next;
        }
        if (isDuplicate){
            printf("Ten san pham da ton tai. Vui long nhap lai!\n");
        }else{
            strcpy(product.name, tempName);
            break;
        }
    }
    product.id = countID++;

    printf("Nhap gia san pham: ");
    scanf("%f", &product.price);
    while (getchar() != '\n');

    printf("Nhap so luong san pham ton kho: ");
    scanf("%d", &product.quantity);
    while (getchar() != '\n');
    return product;
}
void addProduct(SNode** head){
    SNode* newNode = (SNode *)malloc(sizeof(SNode));
    newNode->product = inputProduct(*head);
    newNode->next = NULL;

    if (*head == NULL){
        *head = newNode;
    }else{
        SNode* temp = *head;
        while (temp->next != NULL){
            temp = temp->next;
        }
        temp->next=newNode;
    }
    printf("Them moi san pham thanh cong!\n");
}
void printList(SNode* head){
    if (head == NULL){
        printf("Danh sach trong.\n");
        return;
    }
    printf("Danh sach toan bo san pham trong kho la: \n");
    while (head != NULL){
        printf("ID: %d\n", head->product.id);
        printf("Ten san pham: %s\n", head->product.name);
        printf("Gia san pham: %.3f\n", head->product.price);
        printf("So luong san pham to kho: %d\n", head->product.quantity);
        head=head->next;
    }
}
void deleteProduct(SNode** head, int idDelete){
    SNode* temp = *head, *prev = NULL;
    while (temp != NULL && temp->product.id != idDelete){
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL){
        printf("San pham khong ton tai.\n");
        return;
    }
    if (prev == NULL){
        *head = temp->next;
    }else{
        prev->next=temp->next;
        free(temp);
    }
    printf("Xoa san pham thanh cong.\n");
}
void updateProduct(SNode* head, int idUpdate){
    while (head != NULL){
        if (head ->product.id == idUpdate){
            printf("Nhap ten san pham moi: ");
            getchar();
            fgets(head->product.name, MAX_NAME, stdin);
            head->product.name[strcspn(head->product.name, "\n")] = '\0';
            printf("Nhap gia tien moi: ");
            scanf("%f", &head->product.price);
            while (getchar() != '\n');
            printf("Nhap so luong san pham: ");
            scanf("%d", &head->product.quantity);
            while (getchar() != '\n');
            printf("Cap nhat san pham thanh cong.\n");
            return ;
        }
        head = head -> next;
    }
    printf("Khong tim thay san pham nao.\n");
}
void freeNodeSingly(SNode* head){
    SNode* temp;

    while (head != NULL){
        temp = head;
        head = head->next;
        free(temp);
    }
}
int main(){
    int choice, id;
    SNode* productList = NULL;
    do{
        showMenu();
        printf("Lua chon cua ban la: ");
        scanf("%d", &choice);
        while (getchar() != '\n');

        switch (choice){
            case 1:
                addProduct(&productList);
                break;
            case 2:
                printList(productList);
                break;
            case 3:
                printf("Nhap ID khoa hoc can xoa: ");
                scanf("%d", &id);
                deleteProduct(&productList, id);
                break;
            case 4:
                printf("Nhap ID can cap nhat: ");
                scanf("%d", &id);
                updateProduct(productList, id);
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
            case 8:
                break;
            case 9:
                break;
            case 10:
                printf("Thoat chuong trinh!\n");
                break;
            default:
                printf("Lua chon khong hop le! Vui long chon lai\n");
                break;
        }

    }while (choice != 10);
    freeNodeSingly(productList);
    return 0;
}


