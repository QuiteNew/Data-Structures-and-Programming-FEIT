#include <stdio.h>
#include <stdlib.h>

#define NEW(t) (t*)malloc(sizeof(t))

typedef int info_t;
typedef struct element
{
	info_t info;
	struct element *prev;
	struct element *next;
} node;
typedef node * nodep;

nodep new_list(void)
{
	nodep t = NEW(node);
	t->prev = t;
	t->next = t;
	return(t);
}

void ins_after(nodep l, info_t x)
{
	nodep t = NEW(node);
	t->info = x;
	l->next->prev = t;
	t->next = l->next;
	t->prev = l;
	l->next = t;
}

void ins_before(nodep l, info_t x)
{
	nodep t = NEW(node);
	t->info = x;
	l->prev->next = t;
	t->prev = l->prev;
	t->next = l;
	l->prev = t;
}

void mk_link_list(nodep p, int n)
{
	info_t data;
	while (n--)
	{
		scanf("%d", &data);
		ins_before(p, data);
	}
}

void del_node(nodep p)
{
	p->prev->next = p->next;
	p->next->prev = p->prev;
	free(p);
}

nodep find_first(nodep l, info_t x)
{
	nodep end;
	for (l = (end = l)->next; l != end && l->info != x; l = l->next);
	return (l != end ? l : NULL);
}

nodep find_last(nodep l, info_t x)
{
	nodep end;
	for (l = (end = l)->prev; l != end && l->info != x; l = l->prev);
	return (l != end ? l : NULL);
}

void printlist(nodep p)
{
	void printnode(nodep);
	nodep end;
	for (p = (end = p)->next; p != end; p = p->next)
		printnode(p);
	putchar("\n");
}

void printnode(nodep p)
{
	printf("->%d", p->info);
}

void free_link_list(nodep p)
{
	nodep q, end = p;
	p = p->next;
	while (p != end)
	{
		p = (q = p)->next;
		free(q);
	}
	free(p);
}

void ins_in_order(nodep l, info_t x)
{
	nodep p = l->next; /* skokni go jazel vodacot */

	if (x <= p->info) /* vmetni na chelo */
		ins_after(l, x);
	else /* najdi mu go mesoto */
	{
		while (p != l && p->info < x)
			p = p->next;
		ins_before(p, x);
	}
}

int main()
{
	return 1;
}