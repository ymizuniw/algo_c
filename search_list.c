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

// sentinel 以外でキーデータに一致したらそれはデータが発見されたということ。
int	main(void)
{
	char	key[20];

	struct tfield *head, *p, sentinel;
	head = &sentinel;
	while (p = talloc(), scanf("%s %s", p->name, p->tel) != EOF)
	{
		p->pointer = head;
		head = p;
	}
	rewind(stdin);
	while (printf("key name "), scanf("%s", key) != EOF)
	{
		strcpy(sentinel.name, key);
		p = head;
		while (strcmp(p->name, key) != 0)
			p = p->pointer;
		if (p != &sentinel)
			printf("%s %s\n", p->name, p->tel);
		else
			printf("key data not found\n");
	}
}

struct tfield	*talloc(void)
{
	return ((struct tfield *)malloc(sizeof(struct tfield)));
}