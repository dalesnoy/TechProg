/*Начинаем с объявления необходимых библиотек: iostream, 
cmath и vector. iostream библиотека является стандартной библиотекой ввода-вывода для C++,
а cmath позволяет использовать различные математические функции, 
такие как sqrt, pow, sin, cos и другие. Vector используется для хранения двумерных массивов элементов типа double.*/
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

class matrix
{
private:
	int rows;
	int cols;
	vector<vector<double>> elements;

public:
	/*Создаем класс matrix. Он включает в себя три автоматически сгенерированных конструктора,
	деструктор, операторы сложения, вычитания и умножения матриц,
	а также операторы умножения и деления матрицы на число и оператор присваивания.*/
	matrix() { }

	matrix(int r, int c)
	{
		rows = r;
		cols = c;
		elements = vector<vector<double>>(rows, vector<double>(cols, 0));
	}

	matrix(int r, int c, vector<vector<double>> el)
	{
		rows = r;
		cols = c;
		elements = el;
	}

	~matrix()
	{
	}

	matrix(const matrix& m)
	{
		rows = m.rows;
		cols = m.cols;
		elements = m.elements;
	}

	void print()
		/*Создаем метод print(), 
		который выводит содержимое матрицы на экран.*/
	{
		//cout << "\nMatrix:\n";
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				cout << elements[i][j] << " ";
			}
			cout << endl;
		}
	}

	matrix operator +(const matrix& m)
	{
		matrix result(rows, cols);
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				result.elements[i][j] = elements[i][j] + m.elements[i][j];
			}
		}
		return result;
	}

	matrix operator -(const matrix& m)
	{
		matrix result(rows, cols);
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				result.elements[i][j] = elements[i][j] - m.elements[i][j];
			}
		}
		return result;
	}

	matrix operator *(double c)
	{
		matrix result(rows, cols);
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				result.elements[i][j] = c * elements[i][j];
			}
		}
		return result;
	}

	matrix operator /(double c)
	{
		matrix result(rows, cols);
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				result.elements[i][j] = elements[i][j] / c;
			}
		}
		return result;
	}

	matrix operator *(const matrix& m)
	{
		matrix result(rows, m.cols);
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < m.cols; j++)
			{
				double sum = 0;
				for (int k = 0; k < cols; k++)
				{
					sum += elements[i][k] * m.elements[k][j];
				}
				result.elements[i][j] = sum;
			}
		}
		return result;
	}

	matrix& operator =(const matrix& m)
	{
		rows = m.rows;
		cols = m.cols;
		elements = m.elements;
		return *this;
	}
};

int main()
/*В функции main() создаем две матрицы размером 3х3, заполняя их значениями с помощью векторов.*/
{
	vector<vector<double>> matrix1Data =
	{
		{1, 2, 3},
		{4, 5, 6},
		{7, 8, 9}
	};
	vector<vector<double>> matrix2Data =
	{
		{10, 11, 12},
		{13, 14, 15},
		{16, 17, 18}
	};

	matrix m1(3, 3, matrix1Data);
	matrix m2(3, 3, matrix2Data);

	/*Чтобы продемонстрировать работу матричных операций, создаем переменную scalar типа double и инициализируем ее значением 3.*/
	/*. Затем выводим содержимое матриц на экран с помощью метода print().*/
	double scalar = 3;
	cout << "scalar: " << scalar;
	cout << endl << endl;

	cout << "m1:";
	cout << endl;
	m1.print();
	cout << endl;

	cout << "m2:";
	cout << endl;
	m2.print();
	cout << endl;

	matrix m3;

	cout << "sum (m1+m2): ";
	cout << endl;
	m3 = m1 + m2;
	m3.print();
	cout << endl;

	cout << "sub (m1-m2): ";
	cout << endl;
	m3 = m1 - m2;
	m3.print();
	cout << endl;

	cout << "mul (m1 * m2) : ";
	cout << endl;
	m3 = m1 * m2;
	m3.print();
	cout << endl;

	cout << "mul (m1*scalar): ";
	cout << endl;
	m3 = m1 * scalar;
	m3.print();
	cout << endl;

	cout << "div (m1/scalar): ";
	cout << endl;
	m3 = m1 / scalar;
	m3.print();
	cout << endl;
	/*Выполняем матричные операции с помощью перегруженных операторов: сначала складываем (m1 + m2),
	потом вычитаем (m1 - m2), затем перемножаем (m1 * m2) и также выполняем умножение матрицы на скаляр (m1 * scalar) 
	и деление матрицы на скаляр (m1 / scalar).*/

	return 0;
}
