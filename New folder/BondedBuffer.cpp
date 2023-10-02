#include <stdio.h>
#include <stdlib.h>

int mutex = 1;
int full = 0;

int Empty = 10, x = 0;

void producer()
{
	--mutex;
	++full;
	--Empty;
	x++;
	printf("\nProducer produces item %d",x);
	++mutex;
}

void consumer()
{
	--mutex;
	--full;
	++Empty;
	printf("\nConsumer consumes item %d",x);
	x--;
	++mutex;
}

// Driver Code
int main()
{
	int n, i;
	printf("\n1. Press 1 for Producer"
		"\n2. Press 2 for Consumer"
		"\n3. Press 3 for Exit");

	while(1) {

		printf("\nEnter your choice:");
		scanf("%d", &n);

		// Switch Cases
		switch (n) {
		case 1:
			if ((mutex == 1) && (Empty != 0)) {
				producer();
			}
			else {
				printf("Buffer is full!");
			}
			break;
		case 2:
			if ((mutex == 1) && (full != 0)) {
				consumer();
			}
			else {
				printf("Buffer is empty!");
			}
			break;
		case 3:
			exit(0);
			break;
		}
	}
}
