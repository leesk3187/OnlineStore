#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ManagerProgram.h"
/// <summary>
/// 로그인 기능
/// </summary>
void title()
{
	printf("\n  #####   #                                      #                                                   ##       ##    \n");
	printf(" #     #  #                                                                                            #        #    \n");
	printf(" #        ######    #####   ######   ######    ###     # ####    ######           ### ##    ######     #        #    \n");
	printf("  #####   #     #  #     #  #     #  #     #     #     ##    #  #     #           #  #  #  #     #     #        #    \n");
	printf("       #  #     #  #     #  #     #  #     #     #     #     #  #     #           #  #  #  #     #     #        #    \n");
	printf(" #     #  #     #  #     #  #     #  #     #     #     #     #   ######           #  #  #  #    ##     #        #    \n");
	printf("  #####   #     #   #####   ######   ######    #####   #     #        #           #     #   #### #    ###      ###   \n");
	printf("                            #        #                           #####                                                \n\n\n\n\n");
}

void mode_intit()
{
	printf("\t\t\t\t\t\t1. 관리자 모드\n\n");
	printf("\t\t\t\t\t\t2. 소비자 모드\n\n");
	printf("\t\t\t\t\t\t3. 종료\n\n");
}

void customer1_init()
{
	printf("\t\t\t\t\t\t1. 회원가입\n\n");
	printf("\t\t\t\t\t\t2. 로그인\n\n");
	printf("\t\t\t\t\t\t3. 상품 주문\n\n");
	printf("\t\t\t\t\t\t4. 장바구니\n\n");
	printf("\t\t\t\t\t\t5. 장바구니 삭제\n\n");
	printf("\t\t\t\t\t\t6. 종료\n\n");
	printf("\t\t\t\t\t\t7. 뒤로\n\n");
}
/*
void customer2_intit()
{
	printf("\t\t\t\t\t\t1.상품 주문\n");
	printf("\t\t\t\t\t\t2.장바구니\n");
	printf("\t\t\t\t\t\t3.주문 건수 조회\n");
	printf("\t\t\t\t\t\t4.상품 등록\n");
	printf("\t\t\t\t\t\t5. 종료\n");
	printf("\t\t\t\t\t\t번호를 선택해주세요.\n");
}*/
void test() // 관리자 모드
{
	printf("\t\t\t\t\t\t0. 돌아가기\n\n");
	printf("\t\t\t\t\t\t1. 상품 등록\n\n");
	printf("\t\t\t\t\t\t2. 회원정보 리스트\n\n");
	printf("\t\t\t\t\t\t3. 종료\n\n");
}

// 회원가입
void sign_up(Node* head) // 회원가입
{
	//title();
	Node* new_node = (Node*)malloc(sizeof(Node));
	if (new_node == NULL) {
		printf("메모리 할당에 실패했습니다.\n");
		exit(1);
	}
	new_node->next = head->next;
	head->next = new_node;

	printf("\t\t\t\t\t\t* 회원가입 *\n");
	printf("\t\t\t\t\t\t이름: ");
	scanf("%s", new_node->name);
	printf("\t\t\t\t\t\tID: ");
	scanf("%s", new_node->id);
	printf("\t\t\t\t\t\tPW: ");
	scanf("%s", new_node->pw);

	system("cls");
	title();
	printf("환영합니다. %s님 회원가입되었습니다.\n", new_node->name);
}

//로그인
int log_in(Node* head) // 로그인
{
	//title();
	Node* curr = head->next;
	if (curr == NULL) {
		printf("\t\t\t\t\t가입된 정보가 없습니다. 회원가입 후 이용해주세요.\n");
		return;
	}
	printf("\t\t\t\t\t* 로그인 *\n");
	char input_id[20];
	char input_pw[50];
	while (1)
	{
		printf("\t\t\t\t\tID 입력하세요: ");
		scanf("%s", input_id);
		printf("\t\t\t\t\tPW 입력하세요: ");
		scanf("%s", input_pw);
		//if (input_id == 0 && input_pw==0) break;
		int success = 0; // 로그인 확인용 변수
		int id_check = 0; // 아이디 확인용 변수
		int pw_check = 0; // 비밀번호 확인용 변수
		Node* curr = head;
		while (curr != NULL)
		{
			if (strcmp(curr->id, input_id) == 0)
			{
				id_check = 1;
				if (strcmp(curr->pw, input_pw) == 0)
				{
					pw_check = 1;
				}
				break;
			}
			curr = curr->next;
		}
		if (id_check && pw_check) {
			system("cls");
			title();
			printf("\t\t\t\t\t%s님 로그인 되었습니다.\n", curr->name);
			return 5;
		}
		else if (id_check && !pw_check) {
			printf("\t\t\t\t\t비밀번호를 다시 입력하세요.\n");
		}
		else {
			printf("\t\t\t\t\t아이디를 다시 입력하세요.\n");
		}
	}
}

// 회원정보 리스트
void print_customers(Node* head) // 모든 고객 정보 출력
{
	//title();
	Node* current = head->next;

	if (current == NULL) {
		system("cls");
		printf("가입된 정보가 없습니다. 회원가입 후 이용해주세요.\n");
		return;
	}

	printf("* 고객 정보 *\n");
	while (current != NULL) {
		printf("이름: %s\tID: %s\tPW: %s\n", current->name, current->id, current->pw);
		current = current->next;
	}
}


/// <summary>
/// 장바구니 기능
/// </summary>
/// <param name="head"></param>
void addNode(Node* head) {
	int input;
	while (1) {
		Node* newNode = (Node*)malloc(sizeof(Node));

		newNode->next = head->next;
		head->next = newNode;

		printf("물건 : ");
		scanf("%s", newNode->data);

		printf("종료:0 ");
		scanf("%d", &input);

		if (input == 0) break;
	}
}

//상품 주문 목록
void print_product(Node* head) {
	Node* p = head->next;
	if (p == NULL) {
		printf("상품이 없습니다!\n");
		return;
	}
	while (p != NULL) {
		printf("%s\n", p->data);
		p = p->next;
		if (p != NULL)
			printf("\n");
	}

}

//상품 주문
void product_order(Node* head) {
	Node* p;

	while (1) {
		p = (Node*)malloc(sizeof(Node));
		char* end = "종료";

		printf("\n주문 할 상품명과 갯수를 입력해주세요.(종료시 종료 입력)\n");
		printf("상품명 : ");
		scanf("%s", p->data);

		if (strcmp(p->data, end) == 0)
			return;

		printf("갯수 : ");
		scanf("%d", &p->count);

		if (head == NULL) {
			head = p;
		}
		else {
			p->next = head->next;
			head->next = p;
		}
	}
}

//장바구니 조회
void inquiry_product(Node* head) {
	Node* p = head->next;
	int end;

	if (p == NULL) {
		printf("상품이 없습니다.\n");
		printf("돌아가기 0\n");
		scanf("%d", &end);
		if (end == 0) return;
	}
	while (p != NULL) {
		printf("%s\t%d개\n", p->data, p->count);
		p = p->next;
		if (p != NULL)
			printf("\n");
	}
	printf("\n돌아가기 0\n");
	scanf("%d", &end);
	if (end == 0) return;
}

//장바구니 상품 삭제
void delet_product1(Node* head) {
	int end;
	char x[20];
	Node* p = head->next;

	if (p == NULL) {
		printf("장바구니에 상품이 존재하지 않습니다.\n");
		printf("돌아가기 : 0\n");
		scanf("%d", &end);
		if (end == 0)
			return;
	}

	else {
		printf("상품명을 입력해주세요\n");
		scanf("%s", x);
		if (strcmp(p->data, x) == 0) {

		}
	}
}

void endProgram() {
	//title();
	printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t종료하시겠습니까? 네(0)/아니오(다른 키)\n");
	printf("\t\t\t\t\t\tUser: ");
}
//void cupon(Node* head)
//{
//	title();
//	Node* current = head->next;
//	int cuponn = 0;
//	if (current->count >= 3) {
//		cuponn++;
//	}
//
//}