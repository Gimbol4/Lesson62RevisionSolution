#include "logic.h"

int main() {
    int N = 5, M = 4;

    int data[5][4] = {
        {1, 0, 2, 0},
        {0, 0, 0, 0},
        {3, 0, 4, 5},
        {0, 0, 0, 0},
        {6, 0, 7, 0}
    };

    int** matrix = new int* [N];
    for (int i = 0; i < N; ++i) {
        matrix[i] = new int[M];
        for (int j = 0; j < M; ++j) {
            matrix[i][j] = data[i][j];
        }
    }

    cout << "Original Matrix:" << endl;
    printMatrix(matrix, N, M);

    int newN, newM;
    int** compact = compactMatrix(matrix, N, M, newN, newM);

    cout << "\nCompacted Matrix (" << newN << "x" << newM << "):" << endl;
    printMatrix(compact, newN, newM);

    freeMatrix(matrix, N);
    freeMatrix(compact, newN);

    return 0;
}