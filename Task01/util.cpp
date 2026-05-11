#include "util.h"

string convert(int** matrix, int n, int m) {
	string s = "";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			s += to_string(matrix[i][j]) + " ";
		}
		s += "\n";
	}

	return s;
}

void print_test(int** matrix, int n, int m, double expected, string test_name) {
	double actual = calculate_arithmetical_mean_of_nonzero_elements(matrix, n, m);
	bool result = actual == expected;

	cout << test_name << " - " << (result ? "completed successfully. Well DONE!!!\033[1;32m [PASS]"
		: "was not running successfully. ERROR!\033[1;31m [FAIL]") << endl;

	cout << "\033[0m";
		
	if (!result) {
		if (n > 0 && m > 0 && matrix != nullptr) {
			cout << "Current Matrix:\n" << convert(matrix, n, m);
		}
	
		cout << "Result arithmetical mean: expected = " << expected
			<< ", but actual = " << actual << endl;
	}

	cout << "\033[1;33m";
	cout << "----------------------------------------------------------" << endl;
	cout << "\033[0m";
}