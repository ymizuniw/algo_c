#include <stdio.h>

#define MaxSize 100

int		queue[MaxSize];
int		head = 0, tail = 0;
int		queuein(int);
int		queueout(int *);
void	disp(void);

int	main(void)
{
	int c, n;
	while (printf("]"), (c = getchar()) != EOF)
	{
		rewind(stdin);
		switch (c)
		{
		case 'i':
		case 'I':
			printf("data--> ");
			scanf("%d", &n);
			rewind(stdin);
			if (queuein(n) == -1)
				printf("queue is full\n");
			break ;
		case 'o':
		case 'O':
			if (queueout(&n) == -1)
				printf("queue is empty\n");
			else
				printf("data -->%d\n", n);
			break ;
		case 'l':
		case 'L':
			disp();
			break ;
		}
	}
}

int	queuein(int n)
{
	if ((tail + 1) % MaxSize != head)
	{
		queue[tail] = n;
		tail++;
		tail %= MaxSize;
		return (0);
	}
	else
		return (-1);
}

int	queueout(int *n)
{
	if (tail != head)
	{
		*n = queue[head];
		head++;
		head %= MaxSize;
		return (0);
	}
	else
		return (-1);
}

void	disp(void)
{
	int	i;

	i = head;
	while (i != tail)
	{
		printf("%d\n", queue[i]);
		i++;
		i %= MaxSize;
	}
}

// abstract: array_idx == mod_size;
//キューを循環させたいので、インデックスも循環させたい。
//インデックスを循環させるには、キューサイズを法としてインデックを取れば良い。
// end.