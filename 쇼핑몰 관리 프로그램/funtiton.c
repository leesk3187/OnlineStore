#include "ManagerProgram.h"
// ���� ������
/// <summary>
/// �α��� ���
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
	printf("\t\t\t\t\t\t\t1. ������ ���\n\n");
	printf("\t\t\t\t\t\t\t2. �Һ��� ���\n\n");
	printf("\t\t\t\t\t\t\t3. ����\n\n");
}

//������ ��Ʈ//
void master()
{
	printf("\t\t\t\t\t\t\t  0. ���ư���\n\n");
	printf("\t\t\t\t\t\t\t  1. ��ǰ ���\n\n");
	printf("\t\t\t\t\t\t\t  2. ��ǰ ���\n\n");
	printf("\t\t\t\t\t\t\t  3. ��ǰ ����\n\n");
	printf("\t\t\t\t\t\t\t  4. ��ǰ ����\n\n");
	printf("\t\t\t\t\t\t\t  5. ȸ������\n\n");
	printf("\t\t\t\t\t\t\t  6. ����\n\n");
}

//������ �α���
int getPassword() {
	char input[20];
	printf(">> ������ ��й�ȣ�� �Է����ּ���: ");
	scanf("%s", input);
	return !strcmp(input, PASSWORD);
}
int totalProductCount = 0;

//��ǰ ���
void addProduct(Node* head) {
	printf("\n\n\n\n\t\t\t\t\t\t ======== ��ǰ ��� ========\n");
	Node* newItem = (Node*)calloc(1, sizeof(Node));
	Node* current = head;
	printf("\n\n\t\t\t\t\t\t >> ��ǰ��: ");
	scanf("%s", newItem->data);
	printf("\n\t\t\t\t\t\t >> ����: ");
	scanf("%d", &newItem->price);
	printf("\n\t\t\t\t\t\t >> ����: ");
	scanf("%d", &newItem->pronum);
	while (current->next != NULL) {
		current = current->next;
	}
	newItem->next = current->next;
	current->next = newItem;
	newItem->dataCount = ++totalProductCount;; // ��ǰ �ε���

	system("cls");
	printf("\n>> ��ǰ ��� �Ϸ�.\n");
	printf("\n=============================\n");
	printf("-> %s  (����: %d) (����: %d)\n", newItem->data, newItem->price, newItem->pronum);
	printf("=============================");
}

//��ǰ ���
void listProducts(Node* head) {
	Node* curItem = head->next;
	if (curItem == NULL) {
		system("cls");
		printf("\n\n\t\t\t\t\t\t>> ��ϵ� ��ǰ�� �����ϴ�.\n");
		return;
	}
	system("cls");
	int index = 0;
	printf("\n\n\t\t\t\t\t\t ===== ��ϵ� ��ǰ ��� =====\n");
	while (curItem != NULL) {
		printf("\t\t\t\t\t\t -> %d. %s (����: %d) (����: %d)\n", ++index, curItem->data, curItem->price, curItem->pronum);
		curItem = curItem->next;
	}
	printf("\t\t\t\t\t\t =============================");
}

// ��ǰ ����
void updateProduct(Node* head) {
	Node* curItem = head->next;
	if (curItem == NULL) {
		system("cls");
		printf("\n>> ������ ��ǰ�� �����ϴ�.\n");
		return;
	}
	system("cls");
	printf("\n\n\n\n\t\t\t\t\t\t ===== ��ϵ� ��ǰ ��� =====\n");
	int index = 0;
	while (curItem != NULL) {
		printf("\t\t\t\t\t\t -> %d. %s  (����: %d) (����: %d)\n", ++index, curItem->data, curItem->price, curItem->pronum);
		curItem = curItem->next;
	}
	printf("\t\t\t\t\t\t ============================");
	printf("\n\n\t\t\t\t\t\t >> ������ ��ǰ ��ȣ�� �Է��ϼ���: ");
	int productNum;
	scanf("%d", &productNum);
	if (productNum <= 0 || productNum > index) {
		system("cls");
		printf("\n>> �߸��� �Է��Դϴ�.\n");
		return;
	}
	curItem = head->next;
	for (int i = 1; i < productNum; i++) {
		curItem = curItem->next;
	}
	system("cls");
	printf("\n\n\n\n\t\t\t\t\t\t >> ���ο� ��ǰ�� �Է�: ");
	scanf("%s", curItem->data);
	printf("\n\t\t\t\t\t\t >> ���ο� ���� �Է�: ");
	scanf("%d", &curItem->price);
	printf("\n\t\t\t\t\t\t >> ���ο� ���� �Է�: ");
	scanf("%d", &curItem->pronum);
	system("cls");
	printf("\n>> ��ǰ ���� �Ϸ�.\n");
}

//��� ��ǰ ����
void deleteProduct(Node** head) {
	Node* curItem = (*head)->next;
	if (curItem == NULL) {
		system("cls");
		printf("\n>> ������ ��ǰ�� �����ϴ�.\n");
		return;
	}

	printf("\n\n\n\n\t\t\t\t\t\t ===== ��ϵ� ��ǰ ��� =====\n");
	int index = 0;
	while (curItem != NULL) {
		printf("\t\t\t\t\t\t -> %d. %s (����: %d) (����: %d)\n", ++index, curItem->data, curItem->price, curItem->pronum);
		curItem = curItem->next;
	}
	printf("\t\t\t\t\t\t ============================\n");
	printf("\n\t\t\t\t\t\t >> ������ ��ǰ ��ȣ�� �Է��ϼ���: ");
	int productNum;
	scanf("%d", &productNum);
	if (productNum <= 0 || productNum > index) {
		system("cls");
		printf("\n>> �߸��� �Է��Դϴ�.\n");
		return;
	}

	Node* prevItem = NULL;
	curItem = (*head)->next;
	for (int i = 1; i < productNum; i++) {
		prevItem = curItem;
		curItem = curItem->next;
	}
	if (prevItem == NULL) {
		// ������ ��ǰ�� ù��° ��ǰ�� ���
		(*head)->next = curItem->next;
	}
	else {
		prevItem->next = curItem->next;
	}
	free(curItem);
	system("cls");
	printf("\n>> ��ǰ ���� �Ϸ�.\n");
}

// ȸ������ ����Ʈ
void print_customers(Cus* head) // ��� �� ���� ���
{
	Cus* current = head->next;

	if (current == NULL) {
		system("cls");
		printf("\n>> ���Ե� ȸ�������� �����ϴ�.\n");
		return;
	}

	printf("\n===== �� ���� =====\n");
	while (current != NULL) {
		printf("�̸�: %s ID: %s PW: %s\n", current->name, current->id, current->pw);
		current = current->next;
	}
}

//�Һ��� ��Ʈ//
void customer1_init()
{
	printf("\t\t\t\t\t\t\t0. �ڷΰ���\n\n");
	printf("\t\t\t\t\t\t\t1. ȸ������\n\n");
	printf("\t\t\t\t\t\t\t2. �α���\n\n");
	printf("\t\t\t\t\t\t\t3. ��ǰ �ֹ�\n\n");
	printf("\t\t\t\t\t\t\t4. ��ٱ���\n\n");
	printf("\t\t\t\t\t\t\t5. ���� ���� Ȯ��\n\n");
	printf("\t\t\t\t\t\t\t6. ���ų��� ����\n\n");
	printf("\t\t\t\t\t\t\t7. ����\n\n");
}

// ȸ������
void sign_up(Cus* cus) // ȸ������
{
	Cus* new_node = (Cus*)malloc(sizeof(Cus));
	Cus* current = cus;
	if (new_node == NULL) {
		printf(">> �޸� �Ҵ翡 �����߽��ϴ�.\n");
		exit(1);
	}
	while (current->next != NULL) // ����
	{
		current = current->next;
	}
	new_node->next = current->next;
	current->next = new_node;
	//new_node->nameCount = 1;

	printf("\n\t\t\t\t\t\t ===== ȸ������ =====\n");
	printf("\n\t\t\t\t\t\t �̸�: ");
	scanf("%s", new_node->name);
	printf("\n\t\t\t\t\t\t ID: ");
	scanf("%s", new_node->id);
	printf("\n\t\t\t\t\t\t PW: ");
	scanf("%s", new_node->pw);

	system("cls");
	printf("\n\t\t\t\t\t** ȯ���մϴ�. %s�� ȸ�����ԵǾ����ϴ�. **\n\n", new_node->name);
}

//�α���
int log_in(Cus* head) // �α���
{
	//title();
	Cus* curr = head->next;
	if (curr == NULL) {
		printf("\n\t\t\t\t\t ���Ե� ������ �����ϴ�. ȸ������ �� �̿����ּ���.\n");
		return;
	}
	char input_id[20];
	char input_pw[50];
	int user;
	printf("\n\n\t\t\t\t �α��� �Ͻðڽ��ϱ�? (* ���ų����� �����˴ϴ�. ���� ���� *)\n\n\t\t\t\t\t\t ��(1) /�ƴϿ�(�ٸ� Ű)\n\n\t\t\t\t\t\t User: ");
	scanf("%d", &user);
	system("cls");

	if (user == 1)
	{
		printf("\n\n\n\n\t\t\t\t\t\t\t * �α���*\n");

		while (1)
		{
			printf("\n\t\t\t\t\t\t\t�ڷΰ���(0) \n");
			printf("\n\t\t\t\t\t\t  ID �Է��ϼ���: ");
			scanf("%s", input_id);
			if (input_id[0] == '0' && input_id[1] == '\0') {
				system("cls");  return 0;
			}
			printf("\n\t\t\t\t\t\t  PW �Է��ϼ���: ");
			scanf("%s", input_pw);
			//if (input_id == 0 && input_pw==0) break;
			int success = 0; // �α��� Ȯ�ο� ����
			int id_check = 0; // ���̵� Ȯ�ο� ����
			int pw_check = 0; // ��й�ȣ Ȯ�ο� ����
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
				printf("\t\t\t\t\t\t   %s�� �α��� �Ǿ����ϴ�.\n", curr->name);
				//current_cus = curr; // ���� �� ���� ����
				return 1;
			}
			else if (id_check && !pw_check) {
				system("cls");
				printf("\n\t\t\t\t\t\t!!! ��й�ȣ�� �ٽ� �Է��ϼ��� !!!\n");
			}
			else {
				system("cls");
				printf("\n\t\t\t\t\t\t!!! ��ϵ��� ���� ID�Դϴ� !!!\n");
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
		printf("\n�α��� �� �̿� ������ ����Դϴ�.\n");
		return 0;
	}
}
/// ��ٱ��� ���

//��ǰ �ֹ�
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

		printf("\n\n\t\t\t\t\t�ֹ� �� ��ǰ��� ������ �Է����ּ���.(����� 0 �Է�)\n\n");
		printf("\t\t\t\t\t��ǰ�� : ");
		scanf("%s", x);

		if (strcmp(x, end) == 0) {
			system("cls");
			return;
		}
		while (find != NULL) {
			if (strcmp(x, find->data) == 0) {
				count++;
				printf("\n\t\t\t\t\t���� : ");
				scanf("%d", &input);

				if (find->pronum >= input) {
					printf("\n\t\t\t\t\t�ٷ� ���� : 1 / ��ٱ��� �ֱ� : 2\n");
					printf("\n\t\t\t\t\tUser: ");
					scanf("%d", &chose);
					if (chose == 1) { //�ٷα���
						printf("\t\t\t\t\t�ֹ��Ϸ�\n");
						find->pronum = find->pronum - input;
						strcpy(add->data, x);
						add->pronum = input;
						add->price = find->price * input;
						add->next = head3->next;
						head3->next = add;
					}
					else if (chose == 2) { //��ٱ��� �ֱ�
						strcpy(p->data, x);
						p->pronum = input;
						find->pronum = find->pronum - input;
						p->price = find->price * input;
						printf("\n\t\t\t\t\t��ٱ��Ͽ� �߰��߽��ϴ�.\n");
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
					printf("\n\t\t\t\t\t!!! ��ǰ ��� �����մϴ� !!!\n");
				}
			}
			find = find->next;
		}
		if (count == 0)
			printf("\n\t\t\t\t\t\t!!! ��ǰ�� �������� �ʽ��ϴ� !!!\n");
	}
}

//��ٱ��� ��ǰ ����
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
         printf("\t\t\t\t\t ��ǰ���� �Է����ּ���. �ڷΰ���(0) : ");
         scanf("%s", x);

         if (strcmp(x, end) == 0) return;

         while (curr != NULL) {
            if (strcmp(x, curr->data) == 0) {
               count++;
               printf("\n\t\t\t\t\t ���� �� ������ �Է����ּ��� : ");
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
						   printf("\n\t\t\t\t\t\t  ��ǰ�� �����Ǿ����ϴ�.\n");
                           return;
                        }
                     }
                     cost = cost->next;
                  }
				  printf("\n\t\t\t\t\t\t  ��ǰ�� �����Ǿ����ϴ�.\n");
               }
               else {
                  printf("\t\t\t\t!!! ������ �� �����ϴ� !!!\n\n");
               }
            }
            prev = curr;
            curr = curr->next;
         }
         if (count == 0)
            printf("!!! ��ǰ�� �������� �ʽ��ϴ� !!!\n");
      }
   }
}

// ��ٱ�����ȸ
void inquiry_product(Node* head) {
	Node* p = head->next;
	int end;

	if (p == NULL) {
		printf("\n\t\t\t\t\t ================= ��ٱ��� =================\n");
		printf("\t\t\t\t\t\t     !!! ��ǰ�� �����ϴ� !!!\n");
		printf("\t\t\t\t\t ============================================\n\n");
		return;
	}
	printf("\n\t\t\t\t\t ================= ��ٱ��� =================\n");

	while (p != NULL) {
		printf("\t\t\t\t\t -> %s (����: %d) (����: %d)\n", p->data, p->pronum, p->price);
		p = p->next;
	}
	printf("\t\t\t\t\t ============================================\n\n");
}

// ��ٱ��� �ִ� ���� �ֹ�
void order_basket(Node* head, Node* head3) {
	Node* curr = head->next;
	Node* buy = head3->next;
	Node* next_node;

	if (curr == NULL) {
		printf("!!! �ֹ��� ��ǰ�� �����ϴ�. !!!\n");
		return;
	}

	while (curr != NULL) {			//�ֹ��ϱ� �� (��ٱ��Ͽ� �ִ� ������ ������� ��) �ֹ� ������ ����
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
	printf("�ֹ� �Ϸ�\n");
}

//�ֹ� ����
void buy_history(Node* head3) {
	Node* p = head3->next;
	int index = 0;

	if (p == NULL) {
		printf("\n======== ���ų��� =========\n");
		printf("!!! �ֹ� ������ �����ϴ� !!!\n");
		printf("============================\n\n");
		return;
	}
	printf("========== ���ų��� =========\n");

	while (p != NULL) {
		printf("-> %d. %s (����: %d) (����: %d)\n", ++index, p->data, p->pronum, p->price);
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
		fprintf(fp, "[%s���� ���ų���]\n", cus->name);
		while (curr != NULL)
		{
			fprintf(fp, "%d.  %s\t%d��\t%d��\n", ++index, curr->data, curr->pronum, curr->price);
			printf("%s\t%d��\t%d��\n", curr->data, curr->pronum, curr->price);
			curr = curr->next;
		}
	}
	fprintf(fp, "\n\n");
	printf("���� �Ϸ�\n");
	fclose(fp);
}
void endProgram() {
	int user;

	printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t�����Ͻðڽ��ϱ�?\n");
	printf("\t\t\t\t\t\t��(0) / �ƴϿ�(�ٸ� Ű�� �Է��ϼ���)\n");
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