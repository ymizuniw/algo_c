#include <stdio.h>

#define MaxSize 100

int	queue[MaxSize];
int	head = 0, tail = 0;
int	queuein(int);
int	queueout(int *);

int	main(void)
{
	int c, n;
	while (printf("]"), (c = getchar()) != EOF)
	{
		rewind(stdin);
		if (c == 'i' || c == 'I')
		{
			printf("data--> ");
			scanf("%d", &n);
			rewind(stdin);
			if (queuein(n) == 1)
				printf("queue is full\n");
		}
		if (c == 'o' || c == 'O')
		{
			if (queueout(&n) == -1)
				printf("queue is empty\n");
			else
				printf("queu data--> %d\n", n);
		}
	}
}

// size:5
//  0 1 2 3 4

// if;
// tail = 0;
// (tail+1)%maxsize = 1
// tail = 1;
// (tail+1)%maxsize = 2
// tail = 2;
// (tail+1)%maxsize = 3
// tail = 3;
// (tail+1)%maxsize = 4
// tail = 4;
// (tail+1)%maxsize = 0

// tail+1==MaxSize;

// head=tail:mod_maxsize(tail)==mod_maxsize(head);

// size 10

// if;
// tail = 0;
// (tail+1)%maxsize = 1
// tail = 1;
// (tail+1)%maxsize = 2
// tail = 2;
// (tail+1)%maxsize = 3
// tail = 3;
// (tail+1)%maxsize = 4
// tail = 4;
// (tail+1)%maxsize = 5

int	queuein(int n)
{
	//もし最大サイズに到達してるなら、それはキューが一周したことになる。したの分岐も同じような調整をしている。
	if ((tail + 1) % MaxSize != head)
	{
		queue[tail] = n;
		tail++;                //次の操作でサイズによるインデックスの調整を行うため、配列インデックスに１加えた値が必要。
		tail = tail % MaxSize; //最大サイズに満たない範囲で対応するインデックスは、modで表される。
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
		head = head % MaxSize;
		return (0);
	}
	else
		return (-1);
}
