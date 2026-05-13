// Task X [The matrix compression]
// Сжатие матрицы 
// 
// Дана математическая прямоугольная матрица размером N на M.
// Необходимо спроектировать эффективный алгоритм и разработать функцию, 
// которая уплотняет заданную матрицу, удаляя из нее строки 
// и столбцы, полностью заполненные нулями, т.е. нулевые строки 
// и/или столбцы. 
// Не забудьте про механизм "защиты от дурака".
//
// На базе разработанной функции реализовать тестовый или полноценный
// проект для демонстрации правильности работы алгоритма функции.

#include "logic.h"

int** compactMatrix(int** matrix, int N, int M, int& rN, int& rM) {
	if (matrix == nullptr || N <= 0 || M <= 0) {
		rN = 0;
		rM = 0;
		return nullptr;
	}

	bool* rowHasData = new bool[N] {false};
	bool* colHasData = new bool[M] {false};

	rN = 0;
	rM = 0;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (matrix[i][j] != 0) {
				if (!rowHasData[i]) {
					rowHasData[i] = true;
					rN++;
				}
				if (!colHasData[j]) {
					colHasData[j] = true;
					rM++;
				}
			}
		}
	}

	if (rN == 0 || rM == 0) {
		delete[] rowHasData;
		delete[] colHasData;
		rN = 0;
		rM = 0;
		return nullptr;
	}

	int** newMatrix = new int* [rN];
	for (int i = 0; i < rN; ++i) {
		newMatrix[i] = new int[rM];
	}

	int newRow = 0;
	for (int i = 0; i < N; ++i) {
		if (!rowHasData[i]) continue;

		int newCol = 0;
		for (int j = 0; j < M; ++j) {
			if (!colHasData[j]) continue;

			newMatrix[newRow][newCol] = matrix[i][j];
			newCol++;
		}
		newRow++;
	}

	delete[] rowHasData;
	delete[] colHasData;

	return newMatrix;
}

void printMatrix(int** matrix, int N, int M) {
	if (matrix == nullptr || N == 0 || M == 0) {
		cout << "[Empty Matrix]" << endl;
		return;
	}
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

void freeMatrix(int** matrix, int N) {
	if (matrix == nullptr) return;
	for (int i = 0; i < N; ++i) {
		delete[] matrix[i];
	}
	delete[] matrix;
}