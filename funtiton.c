#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ManagerProgram.h"
/// <summary>
/// �α��� ���
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
	printf("\t\t\t\t\t\t1. ������ ���\n\n");
	printf("\t\t\t\t\t\t2. �Һ��� ���\n\n");
	printf("\t\t\t\t\t\t3. ����\n\n");
}

void customer1_init()
{
	printf("\t\t\t\t\t\t1. ȸ������\n\n");
	printf("\t\t\t\t\t\t2. �α���\n\n");
	printf("\t\t\t\t\t\t3. ��ǰ �ֹ�\n\n");
	printf("\t\t\t\t\t\t4. ��ٱ���\n\n");
	printf("\t\t\t\t\t\t5. ��ٱ��� ����\n\n");
	printf("\t\t\t\t\t\t6. ����\n\n");
	printf("\t\t\t\t\t\t7. �ڷ�\n\n");
}
/*
void customer2_intit()
{
	printf("\t\t\t\t\t\t1.��ǰ �ֹ�\n");
	printf("\t\t\t\t\t\t2.��ٱ���\n");
	printf("\t\t\t\t\t\t3.�ֹ� �Ǽ� ��ȸ\n");
	printf("\t\t\t\t\t\t4.��ǰ ���\n");
	printf("\t\t\t\t\t\t5. ����\n");
	printf("\t\t\t\t\t\t��ȣ�� �������ּ���.\n");
}*/
void test() // ������ ���
{
	printf("\t\t\t\t\t\t0. ���ư���\n\n");
	printf("\t\t\t\t\t\t1. ��ǰ ���\n\n");
	printf("\t\t\t\t\t\t2. ȸ������ ����Ʈ\n\n");
	printf("\t\t\t\t\t\t3. ����\n\n");
}

// ȸ������
void sign_up(Node* head) // ȸ������
{
	//title();
	Node* new_node = (Node*)malloc(sizeof(Node));
	if (new_node == NULL) {
		printf("�޸� �Ҵ翡 �����߽��ϴ�.\n");
		exit(1);
	}
	new_node->next = head->next;
	head->next = new_node;

	printf("\t\t\t\t\t\t* ȸ������ *\n");
	printf("\t\t\t\t\t\t�̸�: ");
	scanf("%s", new_node->name);
	printf("\t\t\t\t\t\tID: ");
	scanf("%s", new_node->id);
	printf("\t\t\t\t\t\tPW: ");
	scanf("%s", new_node->pw);

	system("cls");
	title();
	printf("ȯ���մϴ�. %s�� ȸ�����ԵǾ����ϴ�.\n", new_node->name);
}

//�α���
int log_in(Node* head) // �α���
{
	//title();
	Node* curr = head->next;
	if (curr == NULL) {
		printf("\t\t\t\t\t���Ե� ������ �����ϴ�. ȸ������ �� �̿����ּ���.\n");
		return;
	}
	printf("\t\t\t\t\t* �α��� *\n");
	char input_id[20];
	char input_pw[50];
	while (1)
	{
		printf("\t\t\t\t\tID �Է��ϼ���: ");
		scanf("%s", input_id);
		printf("\t\t\t\t\tPW �Է��ϼ���: ");
		scanf("%s", input_pw);
		//if (input_id == 0 && input_pw==0) break;
		int success = 0; // �α��� Ȯ�ο� ����
		int id_check = 0; // ���̵� Ȯ�ο� ����
		int pw_check = 0; // ��й�ȣ Ȯ�ο� ����
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
			printf("\t\t\t\t\t%s�� �α��� �Ǿ����ϴ�.\n", curr->name);
			return 5;
		}
		else if (id_check && !pw_check) {
			printf("\t\t\t\t\t��й�ȣ�� �ٽ� �Է��ϼ���.\n");
		}
		else {
			printf("\t\t\t\t\t���̵� �ٽ� �Է��ϼ���.\n");
		}
	}
}

// ȸ������ ����Ʈ
void print_customers(Node* head) // ��� �� ���� ���
{
	//title();
	Node* current = head->next;

	if (current == NULL) {
		system("cls");
		printf("���Ե� ������ �����ϴ�. ȸ������ �� �̿����ּ���.\n");
		return;
	}

	printf("* �� ���� *\n");
	while (current != NULL) {
		printf("�̸�: %s\tID: %s\tPW: %s\n", current->name, current->id, current->pw);
		current = current->next;
	}
}


/// <summary>
/// ��ٱ��� ���
/// </summary>
/// <param name="head"></param>
void addNode(Node* head) {
	int input;
	while (1) {
		Node* newNode = (Node*)malloc(sizeof(Node));

		newNode->next = head->next;
		head->next = newNode;

		printf("���� : ");
		scanf("%s", newNode->data);

		printf("����:0 ");
		scanf("%d", &input);

		if (input == 0) break;
	}
}

//��ǰ �ֹ� ���
void print_product(Node* head) {
	Node* p = head->next;
	if (p == NULL) {
		printf("��ǰ�� �����ϴ�!\n");
		return;
	}
	while (p != NULL) {
		printf("%s\n", p->data);
		p = p->next;
		if (p != NULL)
			printf("\n");
	}

}

//��ǰ �ֹ�
void product_order(Node* head) {
	Node* p;

	while (1) {
		p = (Node*)malloc(sizeof(Node));
		char* end = "����";

		printf("\n�ֹ� �� ��ǰ��� ������ �Է����ּ���.(����� ���� �Է�)\n");
		printf("��ǰ�� : ");
		scanf("%s", p->data);

		if (strcmp(p->data, end) == 0)
			return;

		printf("���� : ");
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

//��ٱ��� ��ȸ
void inquiry_product(Node* head) {
	Node* p = head->next;
	int end;

	if (p == NULL) {
		printf("��ǰ�� �����ϴ�.\n");
		printf("���ư��� 0\n");
		scanf("%d", &end);
		if (end == 0) return;
	}
	while (p != NULL) {
		printf("%s\t%d��\n", p->data, p->count);
		p = p->next;
		if (p != NULL)
			printf("\n");
	}
	printf("\n���ư��� 0\n");
	scanf("%d", &end);
	if (end == 0) return;
}

//��ٱ��� ��ǰ ����
void delet_product1(Node* head) {
	int end;
	char x[20];
	Node* p = head->next;

	if (p == NULL) {
		printf("��ٱ��Ͽ� ��ǰ�� �������� �ʽ��ϴ�.\n");
		printf("���ư��� : 0\n");
		scanf("%d", &end);
		if (end == 0)
			return;
	}

	else {
		printf("��ǰ���� �Է����ּ���\n");
		scanf("%s", x);
		if (strcmp(p->data, x) == 0) {

		}
	}
}

void endProgram() {
	//title();
	printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t�����Ͻðڽ��ϱ�? ��(0)/�ƴϿ�(�ٸ� Ű)\n");
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