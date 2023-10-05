#include "ManagerProgram.h"
// 현재 진행중
/// <summary>
/// 로그인 기능
/// </summary>

void title()
{
	printf("\n     #####   #                                      #                                                   ##       ##    \n");
	printf("    #     #  #                                                                                            #        #    \n");
	printf("    #        ######    #####   ######   ######    ###     # ####    ######           ### ##    ######     #        #    \n");
	printf("     #####   #     #  #     #  #     #  #     #     #     ##    #  #     #           #  #  #  #     #     #        #    \n");
	printf("          #  #     #  #     #  #     #  #     #     #     #     #  #     #           #  #  #  #     #     #        #    \n");
	printf("    #     #  #     #  #     #  #     #  #     #     #     #     #   ######           #  #  #  #    ##     #        #    \n");
	printf("     #####   #     #   #####   ######   ######    #####   #     #        #           #     #   #### #    ###      ###   \n");
	printf("                               #        #                           #####                                                \n\n\n\n\n");
}

void mode_intit()
{
	printf("\t\t\t\t\t\t\t1. 관리자 모드\n\n");
	printf("\t\t\t\t\t\t\t2. 소비자 모드\n\n");
	printf("\t\t\t\t\t\t\t3. 종료\n\n");
}

//관리자 파트//
void master()
{
	printf("\t\t\t\t\t\t\t  0. 돌아가기\n\n");
	printf("\t\t\t\t\t\t\t  1. 상품 등록\n\n");
	printf("\t\t\t\t\t\t\t  2. 상품 목록\n\n");
	printf("\t\t\t\t\t\t\t  3. 상품 수정\n\n");
	printf("\t\t\t\t\t\t\t  4. 상품 삭제\n\n");
	printf("\t\t\t\t\t\t\t  5. 회원정보\n\n");
	printf("\t\t\t\t\t\t\t  6. 종료\n\n");
}

//관리자 로그인
int getPassword() {
	char input[20];
	printf(">> 관리자 비밀번호를 입력해주세요: ");
	scanf("%s", input);
	return !strcmp(input, PASSWORD);
}
int totalProductCount = 0;

//상품 등록
void addProduct(Node* head) {
	printf("\n\n\n\n\t\t\t\t\t\t ======== 상품 등록 ========\n");
	Node* newItem = (Node*)calloc(1, sizeof(Node));
	Node* current = head;
	printf("\n\n\t\t\t\t\t\t >> 상품명: ");
	scanf("%s", newItem->data);
	printf("\n\t\t\t\t\t\t >> 가격: ");
	scanf("%d", &newItem->price);
	printf("\n\t\t\t\t\t\t >> 개수: ");
	scanf("%d", &newItem->pronum);
	while (current->next != NULL) {
		current = current->next;
	}
	newItem->next = current->next;
	current->next = newItem;
	newItem->dataCount = ++totalProductCount;; // 상품 인덱스

	system("cls");
	printf("\n>> 상품 등록 완료.\n");
	printf("\n=============================\n");
	printf("-> %s  (가격: %d) (개수: %d)\n", newItem->data, newItem->price, newItem->pronum);
	printf("=============================");
}

//상품 목록
void listProducts(Node* head) {
	Node* curItem = head->next;
	if (curItem == NULL) {
		system("cls");
		printf("\n\n\t\t\t\t\t\t>> 등록된 상품이 없습니다.\n");
		return;
	}
	system("cls");
	int index = 0;
	printf("\n\n\t\t\t\t\t\t ===== 등록된 상품 목록 =====\n");
	while (curItem != NULL) {
		printf("\t\t\t\t\t\t -> %d. %s (가격: %d) (개수: %d)\n", ++index, curItem->data, curItem->price, curItem->pronum);
		curItem = curItem->next;
	}
	printf("\t\t\t\t\t\t =============================");
}

// 상품 수정
void updateProduct(Node* head) {
	Node* curItem = head->next;
	if (curItem == NULL) {
		system("cls");
		printf("\n>> 수정할 상품이 없습니다.\n");
		return;
	}
	system("cls");
	printf("\n\n\n\n\t\t\t\t\t\t ===== 등록된 상품 목록 =====\n");
	int index = 0;
	while (curItem != NULL) {
		printf("\t\t\t\t\t\t -> %d. %s  (가격: %d) (개수: %d)\n", ++index, curItem->data, curItem->price, curItem->pronum);
		curItem = curItem->next;
	}
	printf("\t\t\t\t\t\t ============================");
	printf("\n\n\t\t\t\t\t\t >> 수정할 상품 번호를 입력하세요: ");
	int productNum;
	scanf("%d", &productNum);
	if (productNum <= 0 || productNum > index) {
		system("cls");
		printf("\n>> 잘못된 입력입니다.\n");
		return;
	}
	curItem = head->next;
	for (int i = 1; i < productNum; i++) {
		curItem = curItem->next;
	}
	system("cls");
	printf("\n\n\n\n\t\t\t\t\t\t >> 새로운 상품명 입력: ");
	scanf("%s", curItem->data);
	printf("\n\t\t\t\t\t\t >> 새로운 가격 입력: ");
	scanf("%d", &curItem->price);
	printf("\n\t\t\t\t\t\t >> 새로운 개수 입력: ");
	scanf("%d", &curItem->pronum);
	system("cls");
	printf("\n>> 상품 수정 완료.\n");
}

//등록 상품 삭제
void deleteProduct(Node** head) {
	Node* curItem = (*head)->next;
	if (curItem == NULL) {
		system("cls");
		printf("\n>> 삭제할 상품이 없습니다.\n");
		return;
	}

	printf("\n\n\n\n\t\t\t\t\t\t ===== 등록된 상품 목록 =====\n");
	int index = 0;
	while (curItem != NULL) {
		printf("\t\t\t\t\t\t -> %d. %s (가격: %d) (개수: %d)\n", ++index, curItem->data, curItem->price, curItem->pronum);
		curItem = curItem->next;
	}
	printf("\t\t\t\t\t\t ============================\n");
	printf("\n\t\t\t\t\t\t >> 삭제할 상품 번호를 입력하세요: ");
	int productNum;
	scanf("%d", &productNum);
	if (productNum <= 0 || productNum > index) {
		system("cls");
		printf("\n>> 잘못된 입력입니다.\n");
		return;
	}

	Node* prevItem = NULL;
	curItem = (*head)->next;
	for (int i = 1; i < productNum; i++) {
		prevItem = curItem;
		curItem = curItem->next;
	}
	if (prevItem == NULL) {
		// 삭제할 상품이 첫번째 상품인 경우
		(*head)->next = curItem->next;
	}
	else {
		prevItem->next = curItem->next;
	}
	free(curItem);
	system("cls");
	printf("\n>> 상품 삭제 완료.\n");
}

// 회원정보 리스트
void print_customers(Cus* head) // 모든 고객 정보 출력
{
	Cus* current = head->next;

	if (current == NULL) {
		system("cls");
		printf("\n>> 가입된 회원정보가 없습니다.\n");
		return;
	}

	printf("\n===== 고객 정보 =====\n");
	while (current != NULL) {
		printf("이름: %s ID: %s PW: %s\n", current->name, current->id, current->pw);
		current = current->next;
	}
}

//소비자 파트//
void customer1_init()
{
	printf("\t\t\t\t\t\t\t0. 뒤로가기\n\n");
	printf("\t\t\t\t\t\t\t1. 회원가입\n\n");
	printf("\t\t\t\t\t\t\t2. 로그인\n\n");
	printf("\t\t\t\t\t\t\t3. 상품 주문\n\n");
	printf("\t\t\t\t\t\t\t4. 장바구니\n\n");
	printf("\t\t\t\t\t\t\t5. 구매 내역 확인\n\n");
	printf("\t\t\t\t\t\t\t6. 구매내역 저장\n\n");
	printf("\t\t\t\t\t\t\t7. 종료\n\n");
}

// 회원가입
void sign_up(Cus* cus) // 회원가입
{
	Cus* new_node = (Cus*)malloc(sizeof(Cus));
	Cus* current = cus;
	if (new_node == NULL) {
		printf(">> 메모리 할당에 실패했습니다.\n");
		exit(1);
	}
	while (current->next != NULL) // 역순
	{
		current = current->next;
	}
	new_node->next = current->next;
	current->next = new_node;
	//new_node->nameCount = 1;

	printf("\n\t\t\t\t\t\t ===== 회원가입 =====\n");
	printf("\n\t\t\t\t\t\t 이름: ");
	scanf("%s", new_node->name);
	printf("\n\t\t\t\t\t\t ID: ");
	scanf("%s", new_node->id);
	printf("\n\t\t\t\t\t\t PW: ");
	scanf("%s", new_node->pw);

	system("cls");
	printf("\n\t\t\t\t\t** 환영합니다. %s님 회원가입되었습니다. **\n\n", new_node->name);
}

//로그인
int log_in(Cus* head) // 로그인
{
	//title();
	Cus* curr = head->next;
	if (curr == NULL) {
		printf("\n\t\t\t\t\t 가입된 정보가 없습니다. 회원가입 후 이용해주세요.\n");
		return;
	}
	char input_id[20];
	char input_pw[50];
	int user;
	printf("\n\n\t\t\t\t 로그인 하시겠습니까? (* 구매내역이 삭제됩니다. 저장 권장 *)\n\n\t\t\t\t\t\t 예(1) /아니오(다른 키)\n\n\t\t\t\t\t\t User: ");
	scanf("%d", &user);
	system("cls");

	if (user == 1)
	{
		printf("\n\n\n\n\t\t\t\t\t\t\t * 로그인*\n");

		while (1)
		{
			printf("\n\t\t\t\t\t\t\t뒤로가기(0) \n");
			printf("\n\t\t\t\t\t\t  ID 입력하세요: ");
			scanf("%s", input_id);
			if (input_id[0] == '0' && input_id[1] == '\0') {
				system("cls");  return 0;
			}
			printf("\n\t\t\t\t\t\t  PW 입력하세요: ");
			scanf("%s", input_pw);
			//if (input_id == 0 && input_pw==0) break;
			int success = 0; // 로그인 확인용 변수
			int id_check = 0; // 아이디 확인용 변수
			int pw_check = 0; // 비밀번호 확인용 변수
			curr = head;
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
				printf("\t\t\t\t\t\t   %s님 로그인 되었습니다.\n", curr->name);
				//current_cus = curr; // 현재 고객 정보 변경
				return 1;
			}
			else if (id_check && !pw_check) {
				system("cls");
				printf("\n\t\t\t\t\t\t!!! 비밀번호를 다시 입력하세요 !!!\n");
			}
			else {
				system("cls");
				printf("\n\t\t\t\t\t\t!!! 등록되지 않은 ID입니다 !!!\n");
			}
		}
	}
	else {
		while (getchar() != '\n');
		system("cls");
		return;
	}

}
int login_required() {
	if (global_login_status) {
		return 1;
	}
	else {
		printf("\n로그인 후 이용 가능한 기능입니다.\n");
		return 0;
	}
}
/// 장바구니 기능

//상품 주문
void product_order(Node* head1, Node* head2, Node* head3) { // head1
	Node* p;
	int count, input, chose;
	char x[20], * end = "0";

	while (1) {
		Node* find = head1->next;
		Node* add = head3->next;
		head1->next = find;
		p = (Node*)malloc(sizeof(Node));
		add = (Node*)malloc(sizeof(Node));
		count = 0;

		printf("\n\n\t\t\t\t\t주문 할 상품명과 개수를 입력해주세요.(종료시 0 입력)\n\n");
		printf("\t\t\t\t\t상품명 : ");
		scanf("%s", x);

		if (strcmp(x, end) == 0) {
			system("cls");
			return;
		}
		while (find != NULL) {
			if (strcmp(x, find->data) == 0) {
				count++;
				printf("\n\t\t\t\t\t개수 : ");
				scanf("%d", &input);

				if (find->pronum >= input) {
					printf("\n\t\t\t\t\t바로 구매 : 1 / 장바구니 넣기 : 2\n");
					printf("\n\t\t\t\t\tUser: ");
					scanf("%d", &chose);
					if (chose == 1) { //바로구매
						printf("\t\t\t\t\t주문완료\n");
						find->pronum = find->pronum - input;
						strcpy(add->data, x);
						add->pronum = input;
						add->price = find->price * input;
						add->next = head3->next;
						head3->next = add;
					}
					else if (chose == 2) { //장바구니 넣기
						strcpy(p->data, x);
						p->pronum = input;
						find->pronum = find->pronum - input;
						p->price = find->price * input;
						printf("\n\t\t\t\t\t장바구니에 추가했습니다.\n");
						if (head2 == NULL) {
							head2 = p;
						}
						else {
							p->next = head2->next;
							head2->next = p;
						}
						break;
					}
				}
				else {
					printf("\n\t\t\t\t\t!!! 상품 재고가 부족합니다 !!!\n");
				}
			}
			find = find->next;
		}
		if (count == 0)
			printf("\n\t\t\t\t\t\t!!! 상품이 존재하지 않습니다 !!!\n");
	}
}

//장바구니 상품 삭제
void delet_product(Node* head1, Node* head2) {
   int input;
   char x[20];
   char* end = "0";
   int index = 0;
   Node* curr = head2->next;
   Node* cost = head1->next;

   if (curr == NULL) {
      return;
   }

   else {
      printf("\n");
      while (1) {
         curr = head2->next;
         cost = head1->next;
         Node* prev = head2;
         int count = 0;
         printf("\t\t\t\t\t 상품명을 입력해주세요. 뒤로가기(0) : ");
         scanf("%s", x);

         if (strcmp(x, end) == 0) return;

         while (curr != NULL) {
            if (strcmp(x, curr->data) == 0) {
               count++;
               printf("\n\t\t\t\t\t 삭제 할 개수를 입력해주세요 : ");
               scanf("%d", &input);

               if (curr->pronum >= input) {
                  while (cost != NULL) {
                     if (strcmp(x, cost->data) == 0) {
                        curr->pronum = curr->pronum - input;
                        curr->price = curr->price - (cost->price * input);
                        cost->pronum += input;

                        if (curr->pronum == 0) {
                           prev->next = curr->next;
                           free(curr);
						   system("cls");
						   printf("\n\t\t\t\t\t\t  상품이 삭제되었습니다.\n");
                           return;
                        }
                     }
                     cost = cost->next;
                  }
				  printf("\n\t\t\t\t\t\t  상품이 삭제되었습니다.\n");
               }
               else {
                  printf("\t\t\t\t!!! 삭제할 수 없습니다 !!!\n\n");
               }
            }
            prev = curr;
            curr = curr->next;
         }
         if (count == 0)
            printf("!!! 상품이 존재하지 않습니다 !!!\n");
      }
   }
}

// 장바구니조회
void inquiry_product(Node* head) {
	Node* p = head->next;
	int end;

	if (p == NULL) {
		printf("\n\t\t\t\t\t ================= 장바구니 =================\n");
		printf("\t\t\t\t\t\t     !!! 상품이 없습니다 !!!\n");
		printf("\t\t\t\t\t ============================================\n\n");
		return;
	}
	printf("\n\t\t\t\t\t ================= 장바구니 =================\n");

	while (p != NULL) {
		printf("\t\t\t\t\t -> %s (개수: %d) (가격: %d)\n", p->data, p->pronum, p->price);
		p = p->next;
	}
	printf("\t\t\t\t\t ============================================\n\n");
}

// 장바구니 있는 물건 주문
void order_basket(Node* head, Node* head3) {
	Node* curr = head->next;
	Node* buy = head3->next;
	Node* next_node;

	if (curr == NULL) {
		printf("!!! 주문할 상품이 없습니다. !!!\n");
		return;
	}

	while (curr != NULL) {			//주문하기 전 (장바구니에 있는 물건이 사라지기 전) 주문 내역에 저장
		Node* newNode = (Node*)calloc(1, sizeof(Node));
		strcpy(newNode->data, curr->data);
		newNode->price = curr->price;
		newNode->pronum = curr->pronum;
		newNode->next = head3->next;
		head3->next = newNode;
		curr = curr->next;
	}

	curr = head->next;

	while (curr != NULL) {
		next_node = curr->next;
		free(curr);
		curr = next_node;
	}

	head->next = NULL;
	printf("주문 완료\n");
}

//주문 내역
void buy_history(Node* head3) {
	Node* p = head3->next;
	int index = 0;

	if (p == NULL) {
		printf("\n======== 구매내역 =========\n");
		printf("!!! 주문 내역이 없습니다 !!!\n");
		printf("============================\n\n");
		return;
	}
	printf("========== 구매내역 =========\n");

	while (p != NULL) {
		printf("-> %d. %s (개수: %d) (가격: %d)\n", ++index, p->data, p->pronum, p->price);
		p = p->next;
	}
	printf("============================\n\n");

}
void save(Node* head3, Cus* cus)
{
	FILE* fp = fopen("buy_history.txt", "a");
	int index = 0;
	Node* curr = head3->next;
	Cus* curr2 = cus->next;
	if (curr == NULL);
	else {
		fprintf(fp, "[%s님의 구매내역]\n", cus->name);
		while (curr != NULL)
		{
			fprintf(fp, "%d.  %s\t%d개\t%d원\n", ++index, curr->data, curr->pronum, curr->price);
			printf("%s\t%d개\t%d원\n", curr->data, curr->pronum, curr->price);
			curr = curr->next;
		}
	}
	fprintf(fp, "\n\n");
	printf("저장 완료\n");
	fclose(fp);
}
void endProgram() {
	int user;

	printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t종료하시겠습니까?\n");
	printf("\t\t\t\t\t\t네(0) / 아니오(다른 키를 입력하세요)\n");
	printf("\t\t\t\t\t\tUser: ");
	scanf("%d", &user);

	if (user == 0) {
		exit(0);
	}
	else {
		while (getchar() != '\n');

		system("cls");
	}
}

void freeMemory_node(Node* head) {
	Node* temp;
	Node* curr = head;

	while (curr != NULL) {
		temp = curr;
		curr = curr->next;
		free(temp);
	}
}

void freeMemory_cus(Cus* head) {
	Cus* temp;
	Cus* curr = head;

	while (curr != NULL) {
		temp = curr;
		curr = curr->next;
		free(temp);
	}
}