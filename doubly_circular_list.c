#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct				tfield
{
	struct tfield	*left;
	char			name[20];
	char			tel[20];
	struct tfield	*right;
};

struct tfield		*talloc(void);

int	main(void)
{
	struct tfield *head, *p;
	head = talloc();
	head->left = head->right = head;
	while (p = talloc(), scanf("%s %s", p->name, p->tel) != EOF)
	{
		p->right = head;
		p->left = head->left;
		head->left->right = p;
		head->left = p;
	}
	printf("\ncircular list right\n");
	p = head->right;
	while (p != head)
	{
		printf("%10s %10s\n", p->name, p->tel);
		p = p->right;
	}
	printf("\ncircular list left\n");
	p = head->left;
	while (p != head)
	{
		printf("%10s %10s\n", p->name, p->tel);
		p = p->left;
	}
}

struct tfield	*talloc(void)
{
	return ((struct tfield *)malloc(sizeof(struct tfield)));
}
