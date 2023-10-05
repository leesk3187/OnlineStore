#include "ManagerProgram.h"
int global_login_status = 0; // 전역 변수 초기화
//Cus* current_cus = NULL;
int main()
{
	Node* head = (Node*)malloc(sizeof(Node));
	Node* head2 = (Node*)malloc(sizeof(Node)); // 소비자 장바구니
	Node* head3 = (Node*)malloc(sizeof(Node)); // 구매 내역
	Cus* cus = (Cus*)malloc(sizeof(Cus));
	if (head == NULL) {
		printf("메모리 할당에 실패했습니다.\n");
		exit(1);
	}
	head->next = NULL;
	cus->next = NULL;
	head2->next = NULL;
	head3->next = NULL;
	int user;
	int passwordTry = 0;

	while (1) // 첫 화면
	{
		title();

		mode_intit();
		printf("\t\t\t\t\t\t\tUser: ");
		scanf("%d", &user);

		if (user == 1) // 관리자
		{
			system("cls");
			printf("\n\n\n\t\t\t\t\t\t  ======= 관리자 모드 =======\n\n");
			while (passwordTry < 3) {
				if (getPassword()) {
					printf("\n>> 관리자 모드 진입 <<\n\n");
					Sleep(1000);
					system("cls");
					break;
				}
				else {
					printf(">> 비밀번호가 틀렸습니다. (기회: %d/3)\n\n", passwordTry + 1);
					passwordTry++;
				}
			}
			if (passwordTry == 3) {
				printf(">> 비밀번호 입력 3회 실패. 프로그램을 종료합니다.\n");
				freeMemory_node(head);
				freeMemory_node(head2);
				freeMemory_node(head3);
				freeMemory_cus(cus);
				return 0;
			}

			while (1)
			{
				printf("\n\n\n\t\t\t\t\t\t  ======= 관리자 모드 =======\n\n");
				master();
				printf("\t\t\t\t\t\t  User: ");
				scanf("%d", &user);
				if (user == 1) {
					system("cls");
					addProduct(head);
				}
				else if (user == 2) {
					system("cls");
					listProducts(head);
				}
				else if (user == 3) {
					system("cls");
					updateProduct(head);
				}
				else if (user == 4) {
					system("cls");
					deleteProduct(&head);
				}
				else if (user == 5) {
					system("cls");
					print_customers(cus);
				}
				else if (user == 0) {
					system("cls");
					break;
				}
				else if (user == 6)
				{
					system("cls");
					endProgram();
				}
				else {
					system("cls");
					while (getchar() != '\n');
					printf("다시 입력하세요\n");
				}
			}
		}
		else if (user == 2) // 소비자
		{
			system("cls");
			//title();
			while (1)
			{
				//title();
				printf("\n\n\n\t\t\t\t\t\t ======= 소비자 모드 =======\n\n");
				customer1_init();
				printf("\t\t\t\t\t\t User: ");
				scanf("%d", &user);
				if (user == 0) { // 뒤로가기
					system("cls");
					break;
				}
				else if (user == 1) {
					system("cls");
					sign_up(cus);
				}
				else if (user == 2)
				{
					system("cls");
					int login_result = log_in(cus);
					if (login_result == 1) {
						global_login_status = 1;
						freeMemory_node(head2);
						freeMemory_node(head3);
						head2 = (Node*)malloc(sizeof(Node));
						head3 = (Node*)malloc(sizeof(Node));

						if (head2 == NULL || head3 == NULL) {
							printf("메모리 할당에 실패했습니다.\n");
							exit(1);
						}

						head2->next = NULL;
						head3->next = NULL;
					}
				}
				else if (user == 3) {
					 system("cls");
					 if (login_required()) {
						 listProducts(head);
						// printf("%s님", cus->name);
						 product_order(head, head2,head3); // 추가
					 }
				}
				else if (user == 4) {
					 system("cls");
					 if (login_required()) {
						 inquiry_product(head2);
						 int num;
						 printf("\t\t\t\t\t\t 1. 장바구니 상품 구매하기\n");
						 printf("\n\t\t\t\t\t\t 2. 장바구니 삭제하기\n");
						 printf("\n\t\t\t\t\t\t 3. 뒤로가기\n");
						 printf("\n\t\t\t\t\t\t User: ");
						 scanf("%d", &num);
						 if (num == 1)
						 {
							 system("cls");
							 order_basket(head2,head3);
						 }
						 else if (num == 2)
						 {
							 system("cls");
							 inquiry_product(head2);
							 delet_product(head, head2); // 추가
						 }
						 else if (num==3){
							 system("cls");
							 continue;
						 }
						 else {
							 while (getchar() != '\n');
							 printf("다시 입력하세요\n");
						 }
					 }
					
				}

				else if (user == 5) {
					 system("cls");
					 if (login_required()) {
						 buy_history(head3);
					 }
				 }
				else if (user == 6) {
					 system("cls");
					 if (login_required()) {
						 buy_history(head3);
						 Cus* curr = cus;
						 while (curr->next != NULL)
						 {
							 curr = curr->next;
						 }
						 save(head3, curr);
					 }
				 }
				else if (user == 7) {
					 system("cls");
					 endProgram();
				}
				else {
					system("cls");
					while (getchar() != '\n');
					printf("다시 입력하세요.\n");
				}
			}
		}
		else if (user == 3) // 종료
		{
			system("cls");
			endProgram();
		}
		else {
			system("cls");
			printf("다시 입력하세요\n");
		}
	}
	freeMemory_node(head);
	freeMemory_node(head2);
	freeMemory_node(head3);
	freeMemory_cus(cus);
	return 0;
}