// Task 01 [The arithmetic mean of non-zero elements]
// Среднее арифметическое ненулевых элементов
// 
// Дана математическая прямоугольная матрица размером N на M.
// Необходимо спроектировать эффективный алгоритм и разработать функцию, 
// которая вычисляет среднее арифметическое ненулевых элементов матрицы. 
// Не забудьте про механизм "защиты от дурака".

#include "logic.h"

double calculate_arithmetical_mean_of_nonzero_elements(int** matrix, int n, int m) {
	if (n < 1 || m < 1 || matrix == nullptr) {
		return -1;
	}

	double mid = 0;
	int count = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (matrix[i][j] != 0) {
				mid += matrix[i][j];
				count++;
			}
		}
	}
	return count != 0 ? mid / count : 0;
}