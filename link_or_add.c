#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct				tfield
{
	char			name[20];
	char			tel[20];
	struct tfield	*pointer;
} * head;

struct tfield		*talloc(void);
void				genlist(void);
void				displist(void);
void				link(char *);

int	main(void)
{
	char	key[20];

	genlist();
	displist();
	rewind(stdin);
	while (printf("Key Name "), scanf("%s", key) != EOF)
	{
		link(key);
	}
	displist();
	return (0);
}

void	link(char *key)
{
	struct tfield *p, *n;
	n = talloc();
	printf("additional data ");
	scanf("%s %s", n->name, n->tel);
	p = head; // LIFO
	while (p != NULL)
	{
		if (strcmp(key, p->name) == 0)
		{
			n->pointer = p->pointer;
			p->pointer = n; //?
			return ;
		}
		p = p->pointer;
	}
	printf("key data not found. key data is added.\n");
	n->pointer = head;
	head = n;
}

void	genlist(void)
{
	struct tfield	*p;

	head = NULL;
	while (p = talloc(), scanf("%s %s", p->name, p->tel) != EOF)
	{
		p->pointer = head;
		head = p;
	}
}

void	displist(void)
{
	struct tfield	*p;

	p = head; // defined out of this function.
	while (p != NULL)
	{
		printf("%15s %15s\n", p->name, p->tel);
		p = p->pointer;
	}
}

struct tfield	*talloc(void)
{
	return ((struct tfield *)malloc(sizeof(struct tfield)));
}
