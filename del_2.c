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
void				del(char *);

int	main(void)
{
	char	key[20];

	genlist();
	displist();
	rewind(stdin);
	while (printf("Key Data "), scanf("%s", key) != EOF)
		del(key);
	displist();
}

void	del(char *key)
{
	struct tfield	*p;

	p = head; // head is the lastly added node.
	while (p->pointer != NULL)
	{
		if (strcmp(key, p->pointer->name) == 0)
		{
			p->pointer = p->pointer->pointer;
			return ;
		}
		p = p->pointer;
	}
	printf("Key Data not found\n");
}

void	genlist(void)
{
	struct tfield	*p;

	head = NULL;
	do
	{
		p = talloc();
		p->pointer = head;
		head = p;
	} while (scanf("%s %s", p->name, p->tel) != EOF);
}

void	displist(void)
{
	struct tfield	*p;

	p = head->pointer;
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
