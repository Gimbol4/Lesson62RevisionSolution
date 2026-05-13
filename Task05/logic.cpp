// Последний локальный минимум
// [The last local minimum]
// 
// Дана математическая прямоугольная матрица размером N на M.
// Необходимо разработать эффективную функцию (или программу), которая 
// находит и возвращает местоположение последнего локального минимума. 

#include "logic.h"

void get_last_local_minimum(int** matrix, int n, int m, int* ii, int* jj) {
    *ii = 0;
    *jj = 0;

    if (n <= 0 || m <= 0 || matrix == nullptr || (n == 1 && m ==1)) {
        return;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            bool isLocalMin = true;
            int current = matrix[i][j];

            if (i > 0 && matrix[i - 1][j] <= current) isLocalMin = false;
            if (isLocalMin && i < n - 1 && matrix[i + 1][j] <= current) isLocalMin = false;
            if (isLocalMin && j > 0 && matrix[i][j - 1] <= current) isLocalMin = false;
            if (isLocalMin && j < m - 1 && matrix[i][j + 1] <= current) isLocalMin = false;

            if (isLocalMin) {
                *ii = i + 1;
                *jj = j + 1;
            }
        }
    }
}