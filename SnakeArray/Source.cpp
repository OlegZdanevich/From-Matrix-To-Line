#include <iostream>

using namespace std;

int* FillMatrixB(int**, int);
inline int** AllocMatrix(int);
inline int* AllocArray(int);
inline bool IsDataValid(int n);
void EnterDimention(int &t);
void FillMatrix(int**, int);
void DisplayMatrix(int**, int);
void DisplayMatrix(int*, int);
inline void ClearMemory(int**, int);
inline void ClearMemory(int*);


int main()
{

	while (true)
	{
		cout.width(50);
		cout << endl << "Welcome to the programm!";
		cout << endl << endl << "*******************************************************************************" << endl << endl;
		int n;
		EnterDimention(n);
		int**a = AllocMatrix(n);
		FillMatrix(a, n);
		system("cls");
		cout << endl << "Before" << endl << endl;
		DisplayMatrix(a, n);
		cout << endl << endl << "*******************************************************************************" << endl << endl;
		cout << endl << "after" << endl << endl;
		int *b = FillMatrixB(a, n);
		DisplayMatrix(b, n*n);
		cout << endl << endl << "*******************************************************************************" << endl << endl;
		cout << endl;
		system("pause");
		system("cls");
		ClearMemory(a, n);
		ClearMemory(b);
		char s;
		cout << "Would you like to countinie? " << endl;
		cout << "Yes- y or Y " << endl;
		cout << "No- other symbols" << endl;
		cout << "Waiting for Enter: " << endl;
		cin >> s;
		system("cls");
		if (s == 'y' || s == 'Y') continue;
		break;

	}

	return 0;
}




int* FillMatrixB(int**a, int n)
{
	int*b = AllocArray(n*n);
	int up = 0;
	int down = n - 1;
	int left = 0;
	int right = n - 1;
	bool s = 0;
	int k = 0;
	while (k < (n*n - 1))
	{
		if (s == true) left++;
		for (int i = right; i >= left; i--)
		{
			if (i != right)k++;
			b[k] = a[up][i];
		}
		if (s == true) down--;
		for (int i = up + 1; i <= down; i++)
		{
			k++;
			b[k] = a[i][left];
		}
		if (s == true) right--;
		for (int i = left + 1; i <= right; i++)
		{
			k++;
			b[k] = a[down][i];
		}
		up++;
		for (int i = down - 1; i >= up; i--)
		{
			k++;
			b[k] = a[i][right];
		}
		s = 1;
	}
	return b;
}

inline int** AllocMatrix(int n)
{
	int**a = new int*[n];
	for (int i = 0; i < n; i++)
	{
		a[i] = AllocArray(n);
	}
	return a;
}

inline int* AllocArray(int n)
{
	int*a = new int[n];
	return a;
}

inline bool IsDataValid(int n)
{
	if (n <= 0) return false;
	return true;
}

void EnterDimention(int &t)
{
	while (true)
	{
		cout << "Enter size   0<=n    : ";
		cin >> t;
		if (IsDataValid(t)) break;
		cout << "Error!" << endl;
	}
}

void FillMatrix(int**matr, int n)
{
	for (int i = 0, k = n*n; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			matr[i][j] = k;
			k--;
		}
	}
}


void DisplayMatrix(int** a, int n)
{
	for (int i = 0; i < n; i++)
	{
		DisplayMatrix(a[i], n);
		cout << endl;
	}
	cout << endl;
}

void DisplayMatrix(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout.width(7);
		cout << a[i];
	}
}

inline void ClearMemory(int**a, int m)
{
	for (int i = 0; i < m; i++)
	{
		ClearMemory(a[i]);
	}
	delete[] a;
}

inline void ClearMemory(int*a)
{
	delete[] a;
}