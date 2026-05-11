// Количество строк с большим количество положительных элементов
// [The Number of rows with a large number of positive elements]
// 
// Дана математическая прямоугольная матрица размером N на M.
// Необходимо разработать функцию(или программу), которая находит
// количество строк, в которых положительных элементов больше 
// чем всех остальных (отрицательных и нулевых).

#include "logic.h"

int count_rows_with_more_positive_values(int** matrix, int n, int m) {
	if (n < 1 || m < 1 || matrix == nullptr) {
		return 0;
	}

	int count_of_row = 0;


	for (int i = 0; i < n; i++)
	{
		int count_of_pos = 0;
		int count_of_other = 0;
		for (int j = 0; j < m; j++)
		{
			if (matrix[i][j] > 0) {
				count_of_pos++;
			}
			else {
				count_of_other++;
			}
		}
		if (count_of_pos > count_of_other) {
			count_of_row++;
		}
	}
	return count_of_row;
}