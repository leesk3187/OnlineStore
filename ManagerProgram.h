#pragma once
typedef struct ndoe {
	// �⺻����
	char name[20];
	char id[20];
	char pw[50];

	// ��ٱ���
	char data[20]; //��ǰ
	int count; // ��ǰ ����
	int cost; // ����

	//������ ����ü
	
	struct node* next;
}Node;

void mode_intit();
void title();
void customer1_init();
void customer2_intit();
void test();
void sign_up(Node* head);
int log_in(Node* head);
void print_customers(Node* head);
void endProgram();
// ��ٱ���
void addNode(Node* head);
void print_product(Node* head);
void product_order(Node* head);
void inquiry_product(Node* head);
void delet_product1(Node* head);
