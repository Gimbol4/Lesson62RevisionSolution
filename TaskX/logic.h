#include <iostream>
#include <string>
using namespace std;

int** compactMatrix(int** matrix, int N, int M, int& rN, int& rM);
void printMatrix(int** matrix, int N, int M);
void freeMatrix(int** matrix, int N);
