// Сумма элементов [The sum of elements]
// 
// Дана математическая квадратная матрица размером N.
// Необходимо разработать функцию (или программу), 
// которая вычисляет сумму элементов матрицы, 
// расположенных на главной и побочной диагоналях.
#include "logic.h"

int sum_main_and_second_diagonales_elements(int** matrix, int n) {
	if (n < 1 || matrix == nullptr) {
		return 0;
	}

	int summ = 0;

	for (int i = 0; i < n; i++)
	{
		summ += matrix[i][i];

		if (i != n - i - 1) {
			summ += matrix[i][n - i - 1];
		}
	}
	return summ;

}