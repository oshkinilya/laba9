#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <locale.h>
#include <queue>
using namespace std;

queue<int>q;
void BFSD(int s, int n, int* dis, int** G) {
	q.push(s);
	dis[s] = 0;
	while (!q.empty()) {
		s = q.front();
		q.pop();
		for (int i = 0; i < n; i++)
		{
			if (G[s][i] == 1 && dis[i] == -1)
			{
				q.push(i);
				dis[i] = dis[s] + 1;
				printf("%d[%d->%d] ", dis[i], s, i);
			}
		}
	}
}

int main() {
	int n, m, i = 0;
	srand(time(NULL));
	setlocale(LC_ALL, "Russian");
	printf("Введите количество вершин для матрицы: ");
	scanf_s("%d", &n);
	int** M = new int* [n];
	int* dis = new int[n];
	for (int i = 0; i < n; i++)
	{
		M[i] = new int[n];
		dis[i] = -1;
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			if (i == j)
			{
				M[i][j] = 0;
			}
			else if (i != j)
			{
				M[i][j] = rand() % 2;
				M[j][i] = M[i][j];
			}
		}
	}

	printf("Матрица смежности:\n");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%d ", M[i][j]);
		}
		printf("\n");
	}
	printf("Введите номер стартовой вершины: ");
	scanf_s("%d", &m);
	BFSD(m, n, &dis[0], &(&M)[0][0]);
}