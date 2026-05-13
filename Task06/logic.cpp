// Минимальный максимум среди всех локальных максимумов
// [The minimum maximum among all local maxima].
// 
// Дана математическая прямоугольная матрица размером N на M.
// Необходимо разработать функцию (или программу), которая 
// находит значение локального максимума, который является
// минимальным среди всех локальных максимумов. 

#include "logic.h"

int get_min_maximum(int** matrix, int n, int m) {
    if (matrix == nullptr || n <= 0 || m <= 0 || (n == 1 && m == 1)) {
        return 0;
    }

    int minLocalMax = 0;
    bool found = false;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            bool isLocalMax = true;
            bool hasNeighbors = false;

            for (int ni = i - 1; ni <= i + 1; ++ni) {
                for (int nj = j - 1; nj <= j + 1; ++nj) {
                    if (ni == i && nj == j) continue;

                    if (ni >= 0 && ni < n && nj >= 0 && nj < m) {
                        hasNeighbors = true;
                        if (matrix[ni][nj] >= matrix[i][j]) {
                            isLocalMax = false;
                            break;
                        }
                    }
                }
                if (!isLocalMax) break;
            }

            if (isLocalMax && hasNeighbors) {
                if (!found || matrix[i][j] < minLocalMax) {
                    minLocalMax = matrix[i][j];
                    found = true;
                }
            }
        }
    }

    return found ? minLocalMax : 0;
}