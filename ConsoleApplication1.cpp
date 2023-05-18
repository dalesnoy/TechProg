#include <iostream>
#include <fstream>



using namespace std;



int main()
{
	setlocale(0, "");
	
	cout << "Выберите действие:\n1 - перемножение матриц\n2 - другое\n";
	
	int flag, flag1;
	cin >> flag;
	int i, j, n, m, arr[10][10], arr1[10][10], arr2[10][10],
	arr3[10][10];

	if (flag !=1)
	{
		cout << "Выберите действие:\n1 - сложение\n2 - вычитание\n3 -Транспонирование матрицы A\n";
		cout << "4 - Транспонирование матрицы B\n5 - Умножение матрицы A на число\n";
		cout << "6 - умножение матрицы B на число\n7 - Деление матрицы A на числo\n8-Деление матрицы B на число\n";
		cin >> flag1;

		cout << "Введите размер A матрицы\n";
		cin >> n;
		cin >> m;
		cout << "Введите A матрицу\n";
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < m; j++)
			{
				cin >> arr[i][j];
			}
		}
		cout << "Матрица A:\n";
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < m; j++)
			{
				cout << arr[i][j] << "\t";
			}
			cout << endl;
		}

		cout << "Введите размер B матрицы\n"; cin >> n; cin >> m;
		cout << "Введите B матрицу\n";
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < m; j++)
			{
				cin >> arr1[i][j];
			}
		}
		cout << "Матрица B:\n";
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < m; j++)
			{
				cout << arr1[i][j] << "\t";
			}
			cout << endl;
		}

		switch (flag1)
		{
			/*
			cout << "Введите размер A матрицы\n"; 
			cin >> n; 
			cin >> m;
			cout << "Введите A матрицу\n";
			for (i = 0; i < n; i++)
			{
				for (j = 0; j < m; j++)
				{
					cin >> arr[i][j];
				}
			}
			cout << "Матрица A:\n";
			for (i = 0; i < n; i++)
			{
				for (j = 0; j < m; j++)
				{
					cout << arr[i][j] << "\t";
				}
				cout << endl;
			}

			cout << "Введите размер B матрицы\n"; cin >> n; cin >> m;
			cout << "Введите B матрицу\n";
			for (i = 0; i < n; i++)
			{
				for (j = 0; j < m; j++)
				{
					cin >> arr1[i][j];
				}
			}
			cout << "Матрица B:\n";
			for (i = 0; i < n; i++)
			{
				for (j = 0; j < m; j++)
				{
					cout << arr1[i][j] << "\t";
				}
				cout << endl;
			}

			*/

			//Сложение
		case 1:

			

			cout << endl;
			cout << "Сумма матриц A и B\n";
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < m; j++)
				{
					arr2[i][j] = arr[i][j] + arr1[i][j];
				}
				cout << endl;
			}
			for (i = 0; i < n; i++)
			{
				for (j = 0; j < m; j++)
				{
					cout << arr2[i][j] << "\t";
				}
				cout << endl;
			}
			break;
			//Вычитание
		case 2:

			cout << endl;
			cout << "Разность матриц A и B\n";
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < m; j++)
				{
					arr3[i][j] = arr[i][j] - arr1[i][j];
				}
				cout << endl;
			}
			for (i = 0; i < n; i++)
			{
				for (j = 0; j < m; j++)
				{
					cout << arr3[i][j] << "\t";
				}
				cout << endl;
			}
			break;
			//Транспонирование матрицы A
		case 3:

			cout << endl;
			cout << "Транспонирование матрицы A\n";


			for (i = 0; i < n; i++)
			{
				for (j = 0; j < m; j++)
				{
					cout << arr[j][i] << "\t";
				}
				cout << endl;
			}
			break;
			//Транспонирование матрицы B
		case 4:

			cout << endl;
			cout << "Транспонирование матрицы B\n";
			for (i = 0; i < n; i++)
			{
				for (j = 0; j < m; j++)
				{
					cout << arr1[j][i] << "\t";
				}
				cout << endl;
			}
			break;
			//умножение матрицы A на число
		case 5:

			cout << endl;
			cout << "Умножение матрицы A на число\n";
			int c;
			cout << "Введите число\n"; cin >> c;
			for (i = 0; i < n; i++)
			{
				for (j = 0; j < m; j++)
				{
					cout << arr[i][j] * c << "\t";
				}
				cout << endl;
			}
			break;

			//умножение матрицы B на число
		case 6:

			cout << endl;
			cout << "Умножение матрицы B на число\n";
			int d;
			cout << "Введите число\n"; cin >> d;
			for (i = 0; i < n; i++)
			{
				for (j = 0; j < m; j++)
				{
					cout << arr1[i][j] * d << "\t";
				}
				cout << endl;
			}
			break;
			//Деление матрицы A на число
		case 7:

			cout << endl;
			cout << "Деление матрицы A на число\n";
			int e;
			cout << "Введите число\n"; cin >> e;
			for (i = 0; i < n; i++)
			{
				for (j = 0; j < m; j++)
				{
					cout << arr[i][j] / e << "\t";
				}
				cout << endl;
			}
			break;
			//Деление матрицы B на число
		case 8:

			cout << endl;
			cout << "Деление матрицы B на число\n";
			int f;
			cout << "Введите число\n"; cin >> f;
			for (i = 0; i < n; i++)
			{
				for (j = 0; j < m; j++)
				{
					cout << arr1[i][j] / f << "\t";
				}
				cout << endl;
				break;
			}
		}
	}else {
		int row1, row2, col1, col2;
		double** a, ** b, ** c;
		system("chcp 1251");
		system("cls");
		cout << "Введите количество строк первой матрицы: ";
		cin >> row1;
		cout << "Введите количество столбцов первой матрицы: ";
		cin >> col1;
		cout << "Введите количество строк второй матрицы: ";
		cin >> row2;
		cout << "Введите количество столбцов второй матрицы: ";
		cin >> col2;
		if (col1 != row2)
		{
			cout << "Умножение невозможно!";
			cin.get(); cin.get();
			return 0;
		}
		// Ввод элементов первой матрицы
		a = new double* [row1];
		cout << "Введите элементы первой матрицы" << endl;
		for (int i = 0; i < row1; i++)
		{
			a[i] = new double[col1];
			for (int j = 0; j < col1; j++)
			{
				cout << "a[" << i << "][" << j << "]= ";
				cin >> a[i][j];
			}
		}
		// Вывод элементов первой матрицы
		for (int i = 0; i < row1; i++)
		{
			for (int j = 0; j < col1; j++)
				cout << a[i][j] << " ";
			cout << endl;
		}
		// Ввод элементов второй матрицы
		b = new double* [row2];
		cout << "Введите элементы второй матрицы" << endl;
		for (int i = 0; i < row2; i++)
		{
			b[i] = new double[col2];
			for (int j = 0; j < col2; j++)
			{
				cout << "b[" << i << "][" << j << "]= ";
				cin >> b[i][j];
			}
		}
		// Вывод элементов второй матрицы
		for (int i = 0; i < row2; i++)
		{
			for (int j = 0; j < col2; j++)
			{
				cout << b[i][j] << " ";
			}
			cout << endl;
		}
		// Умножение матриц
		c = new double* [row1];
		for (int i = 0; i < row1; i++)
		{
			c[i] = new double[col2];
			for (int j = 0; j < col2; j++)
			{
				c[i][j] = 0;
				for (int k = 0; k < col1; k++)
					c[i][j] += a[i][k] * b[k][j];
			}
		}
		// Вывод матрицы произведения
		cout << "Матрица произведения" << endl;
		for (int i = 0; i < row1; i++)
		{
			for (int j = 0; j < col2; j++)
				cout << c[i][j] << " ";
			cout << endl;
		}
		cin.get(); cin.get();
			}
	
	return 0;
}



