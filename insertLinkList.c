#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;
};
typedef struct node Node;

/*top -> a1 -> b2 -> c4_NULL*/
void printList(Node* top)
{
	Node *cur;
	for (cur=top; cur->next!=NULL; cur=cur->next)
	{
		printf("List data: %d\t", cur->next->data);
	}
	printf("\n");
}

void addList(Node* top, int input)
{
	Node *cur;
	for (cur=top; cur->next!=NULL; cur=cur->next)
	{
		if (cur->next->data > input)
		{
			Node *newnode = (Node*) malloc(sizeof(Node));
			newnode->data = input;
			newnode->next = cur->next;
			cur->next = newnode; // cur->next 被設成3, 下一圈又符合if 條件
			break; // 所以一定要有 break, addList 成功後就跳出迴圈
		}
		else if(cur->next->data <input && cur->next->next==NULL) //當list內所有的值都比input小
		{
			Node *newnode = (Node*) malloc(sizeof(Node));
			newnode->data = input;
			newnode->next = NULL;
			cur->next->next = newnode;
			break;
		}

	}
}

int main(int argc, char *argv[])
{
	Node c={4, NULL};
	Node b={2, &c};
	Node a={1, &b};
	Node top={NULL, &a};

	printList(&top);
	addList(&top, 3);
	addList(&top, 5);
	printList(&top);

	return 0;
}