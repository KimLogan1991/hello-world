#include <stdio.h>
#include <time.h>

#define MAX_SIZE 1001
#define SWAP(x, y, t)((t) = (x), (x) = (y), (y) = (t))

void sort(int list[], int n)
{
	int i, j, min, temp;
	for (i = 0; i < n-1; i ++) {
		min = i;
		for (j = i + 1; j < n; j++) 
			if (list[j] < list[min])
				min = j;
		SWAP(list[i], list[min], temp);
	}
}

int main(void)
{
	int i, n, step = 10;
	int a[MAX_SIZE];
	double duration;
	clock_t start;

	/* time for n = 0, 10, ..., 100, 200, ..., 1000 */
	printf("	n	repetitions	time\n");
	for (n = 0; n < MAX_SIZE; n += step)
	{
		/* get time for size n */
		long repetitions = 0;
		start = clock();
		do
		{
			repetitions++;

		/* initialize with worst-case data */
			for (i = 0; i < n; i++)
				a[i] = n - 1;
		
			sort(a, n);
		} while (clock() - start < CLOCKS_PER_SEC);

		duration = ((double)(clock() - start)) / CLOCKS_PER_SEC;
		duration /= repetitions;
		printf("	%6d	%9d	%f\n", n, repetitions, duration);
		if (n == 100) step = 100;
	}
	return 0;
}

