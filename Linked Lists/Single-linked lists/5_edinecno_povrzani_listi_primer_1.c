#include <stdio.h>

typedef struct element
{
	int info; //податок
	struct element *link; //покажувач кон следен јазол
} node;
typedef node *list;

node *mk_linked_list(int n)
{
	int data;
	node *head, *tmp;
	head = NULL;
	tmp = NULL;
	while (n--)
	{
		tmp = (node *)malloc(sizeof(node));
		//Vo C++ динамичка алокација со new
		scanf("%d", &data);
		tmp->info = data;
		tmp->link = head;
		head = tmp;
	}
	return(head);
}

void print_list(node *head)
{
	while (head != NULL)
	{
		printf("%d \t", head->info);
		head = head->link;
	}
}

void free_list(node *head)
{
	node *pom;
	while (head != NULL)
	{
		pom = head;
		head = head->link;
		free(pom);
		//Vo C++ : delete [] ____
	}
}

int list_length(node *head)
{
	int n = 0;
	while (head != NULL)
	{
		head = head->link;
		n++;
	}
	return n;
}

node *find_first(node *head, int data)
{
	while (head != NULL && head->info != data)
	{
		head = head->link;
	}
	return head;
}

void insert_inside(node *jazol, int data)
{
	node *tmp = (node *)malloc(sizeof(node));
	tmp->info = data;
	tmp->link = jazol->link;
	jazol->link = tmp;
}

void delete_after(node *jazol)
{
	if (jazol->link == NULL) return;
	node *tmp = jazol->link; //tmp е следбеник
	jazol->link = tmp->link;
	free(tmp);
}

int delete_node(node **head, node *jazol)
{
	if (*head == jazol)
		*head = jazol->link;
	else
	{
		node *pom = *head;
		while (pom->link != jazol && pom != NULL)
			pom = pom->link;
		if (pom == NULL) return 0;
		pom->link = jazol->link;
	}
	free(jazol);
	return 1;
}

void insert_front(node **head, int data)
{
	node *tmp = (node *)malloc(sizeof(node));
	tmp->info = data;
	tmp->link = *head;
	*head = tmp;
}

int main()
{
	node *head;
	head = NULL;
	insert_front(&head, 5);
	printf("%d", head->info);
	return 0;
}