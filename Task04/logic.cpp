// Сумма элементов столбцов с экстремальными элементами
// [The Sum of elements of columns with extreme elements]
// 
// Дана математическая прямоугольная матрица размером N на M.
// Необходимо разработать функцию (или программу), которая 
// высчитывает сумму элементов в тех столбцах заданной матрицы,
// которые содержат хотя бы один экстремальный элемент.

#include "logic.h"

int sum_elements_of_columns_with_extreme_value(int** matrix, int n, int m) {
    if (matrix == nullptr || n <= 0 || m <= 0) {
        return 0;
    }

    int max_val = matrix[0][0];
    int min_val = matrix[0][0];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] > max_val) max_val = matrix[i][j];
            if (matrix[i][j] < min_val) min_val = matrix[i][j];
        }
    }

    int totalSum = 0;

    for (int j = 0; j < m; j++) {
        bool hasExtreme = false;
        int currentColumnSum = 0;

        for (int i = 0; i < n; i++) {
            currentColumnSum += matrix[i][j];
            if (matrix[i][j] == max_val || matrix[i][j] == min_val) {
                hasExtreme = true;
            }
        }

        if (hasExtreme) {
            totalSum += currentColumnSum;
        }
    }

    return totalSum;
}