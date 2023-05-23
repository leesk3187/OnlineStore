#pragma once
typedef struct ndoe {
	// 기본정보
	char name[20];
	char id[20];
	char pw[50];

	// 장바구니
	char data[20]; //상품
	int count; // 상품 개수
	int cost; // 가격

	//관리자 구조체
	
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
// 장바구니
void addNode(Node* head);
void print_product(Node* head);
void product_order(Node* head);
void inquiry_product(Node* head);
void delet_product1(Node* head);
