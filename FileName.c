#include <stdio.h>
#include <stdlib.h>
#include "ManagerProgram.h"

int main()
{
	Node* head = (Node*)malloc(sizeof(Node));
	if (head == NULL) {
		printf("메모리 할당에 실패했습니다.\n");
		exit(1);
	}

	head->next = NULL;
	int user;
	while (1) // 첫 화면
	{
		title();
		mode_intit();
		printf("\t\t\t\t\tUser: ");
		scanf("%d", &user);

		if (user == 1) // 관리자
		{
			system("cls");
			printf("\n\n\n\t\t\t\t\t  -------관리자 모드-------\n\n");

			while (1)
			{
				test();
				printf("\t\t\t\t\tUser: ");
				scanf("%d", &user);
				if (user == 1) {
					system("cls");
					addNode(head);
				}
				else if (user == 2) {
					system("cls");
					print_customers(head);
				}
				else if (user == 0) {
					system("cls");
					break;
				}
				else if (user == 3)
				{
					while (1)
					{
						system("cls");
						endProgram();
						scanf("%d", &user);
						if (user == 0) return;
						else system("cls"); break;
					}
				}
				else {
					system("cls");
					printf("다시 입력하세요\n");
				}
			}
		}
		else if (user == 2) // 소비자
		{
			system("cls");
			printf("\n\n\n\t\t\t\t\t  -------소비자모드-------\n\n");
			//title();
			while (1)
			{
				//title();
				customer1_init();
				printf("\t\t\t\t\tUser: ");
				scanf("%d", &user);
				if (user == 1) {
					system("cls");
					sign_up(head);
				}
				else if (user == 2)
				{
					system("cls");
					log_in(head);
				}
				else if (user == 3) {
					
					product_order(head);
				}
				else if (user == 4) {
					system("cls");
					inquiry_product(head);
				}
				else if (user == 5) {
					system("cls");
					delet_product1(head);
				}
				else if (user == 6) {
					while (1)
					{
						system("cls");
						endProgram();
						scanf("%d", &user);
						if (user == 0) return;
						else system("cls"); break;
					}
				}
				else if (user == 7) { // 뒤로가기
					system("cls");
					break;
				}
				else {
					system("cls");
					printf("다시 입력하세요.\n");
				}
			}
		}
		else if (user == 3) // 종료
		{
			while (1)
			{
				system("cls");
				endProgram();
				scanf("%d", &user);
				if (user == 0) return;
				else {
					system("cls"); break;
				}
			}
		}
		else {
			system("cls");
			printf("다시 입력하세요\n");
		}
	}
	return 0;
}