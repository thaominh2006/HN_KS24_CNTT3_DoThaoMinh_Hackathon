//
// Created by Admin on 24/07/2025.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NAME 100
#define MAX_POS 100

typedef struct Employee{
    int id;
    char name[MAX_NAME];
    char position[MAX_POS];
    float salary;
}Employee;
typedef struct SNode{
    Employee employee;
    struct SNode* next;
}SNode;
typedef struct DNode{
    Employee employee;
    struct DNode* next;
    struct DNode* prev;
}DNode;
void showMenu()
{
    printf("********MENU********\n");
    printf("1. Them nhan vien.\n");
    printf("2. Hien th danh sach nhan vien dang lam viec.\n");
    printf("3. Xoa nhan vien theo ID.\n");
    printf("4. Cap nhat thong tin nhan vien.\n");
    printf("5. Danh dau nhan vien da nghi viec.\n");
    printf("6. Hien thi danh sach nhan vien da nghi viec.\n");
    printf("7. Sap xep nhan vien theo luong (Bubble sort).\n");
    printf("8. Tim kiem nhan vien theo ten(Linear Search).\n");
    printf("9. Thoat chuong trinh.\n");
}
int countID = 1;
Employee inputEmployee(){
    Employee employee;
    employee.id = countID++;
    printf("Nhap ten nhan vien: ");
    fgets(employee.name, MAX_NAME, stdin);
    employee.name[strcspn(employee.name, "\n")] = '\0';
    printf("Nhap vi tri cong viec: ");
    fgets(employee.position, MAX_POS, stdin);
    employee.position[strcspn(employee.position, "\n")] = '\0';
    printf("Nhap muc luong: ");
    scanf("%f", &employee.salary);
    return employee;
}
void addEmployee(SNode** head)
{
    SNode* node = (SNode *)malloc(sizeof(SNode));
    node->employee=inputEmployee();
    node->next=NULL;
    if (*head == NULL){
        *head = node;
    }else{
        SNode* temp = *head;
        while (temp->next != NULL){
            temp = temp->next;
        }
        temp->next= node;
    }
    printf("Them nhan vien thanh cong.\n");
}
void printList(SNode* head)
{
    printf("Danh sach nhan vien dang lam viec: \n");
    while (head != NULL){
        printf("ID: %d\n", head->employee.id);
        printf("Ten nhan vien: %s\n", head->employee.name);
        printf("Vi tri cong viec: %s\n", head->employee.position);
        printf("Muc luong: %f\n", head->employee.salary);
        head=head->next;
    }
}
void deleteEmployee(Node** head, int idDelete){
    
}
