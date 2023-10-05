#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#define PASSWORD "1"

#ifndef GLOBAL_VARIABLES_H
#define GLOBAL_VARIABLES_H

typedef struct node {
	// �⺻����
	char data[20]; //��ǰ��
	int price; // ����
	//int num; //count
	int pronum;//��ǰ (���)����
	int dataCount;
	struct node* next;
}Node;

typedef struct cus {
	char name[20];
	char id[20];
	char pw[50];
	struct cus* next;
}Cus;

extern int global_login_status; // �α��� ���� Ȯ�� ����
//extern Cus* current_cus; // ���� �α����� �� ����ü ������

#endif // GLOBAL_VARIABLES_H



void mode_intit();
void title();
void customer1_init();
void master();
void sign_up(Cus* head);
int log_in(Cus* head);
int login_required();
void print_customers(Node* head);
void endProgram();


void addProduct(Node* head);
void listProducts(Node* head);
void updateProduct(Node* head);
void deleteProduct(Node** head);
int getPassword();


void inquiry_product(Node* head2);
void delet_product(Node* head1, Node* head2);
void product_order(Node* head1, Node* head2, Node* head3);
void order_basket(Node* head,Node* head3);
void buy_history(Node* head3);

void freeMemory_node(Node* head);
void freeMemory_cus(Cus* head);

void save(Node* head3, Cus* cus);