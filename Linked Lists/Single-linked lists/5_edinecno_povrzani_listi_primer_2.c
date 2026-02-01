#include <stdio.h>

typedef struct element
{
	int info; //податок
	struct element *link; //покажувач кон следен јазол
} node;
typedef node *list;

node *new_list()
{
	node *pom = (node *)malloc(sizeof(node));
	pom->link = NULL;
	return(pom);
}

void mk_link_list(node *vod, int n)
{
	node *pom;
	int data;
	while (n--)
	{
		pom = (node *)malloc(sizeof(node));
		scanf("%d", &data);
		pom->info = data;
		pom->link = vod->link;
		vod->link = pom; //НЕ vod=pom;
	}
}

void print_list(node* vod)
{
	vod = vod->link;
	//Водачот нема инфо поле, не се печати
	while (vod != NULL)
	{
		printf("%d", vod->info);
		vod = vod->link;
	}
}

void free_list(node *vod)
{
	node *q;
	while (vod != NULL)
	{
		vod = (q = vod)->link;
		free(q);
	}
}

int len(node *vod) {
	int n = 0;
	vod = vod->link;
	//Водачот не влегува во должина на листа
	while (vod != NULL) {
		vod = vod->link;
		n++;
	}
	return(n);
}

node *find_first(node *vod, int x)
{
	vod = vod->link;
	//Водачот нема инфо поле
	while (vod != NULL && vod->info != x)
		vod = vod->link;
	return(vod);
}

void insert_inside(node *vod, int data)
{
	node *tmp = (node *)malloc(sizeof(node));
	tmp->info = data;
	tmp->link = vod->link;
	vod->link = tmp;
}

void delete_after(node *jazol)
{
	if (jazol->link == NULL) return;
	node *tmp = jazol->link; //tmp е следбеник
	jazol->link = tmp->link;
	free(tmp);
}

void del_first(node *vod)
{
	node *pom = vod->link;
	//се прескокнува водачот
	if (pom == NULL) return;
	/* listata e veke prazna */
	vod->link = pom->link;
	free(pom);
}

int main()
{
	//Повик во main() :
	node *list;
	list = new_list();
	mk_link_list(list, 4);
}