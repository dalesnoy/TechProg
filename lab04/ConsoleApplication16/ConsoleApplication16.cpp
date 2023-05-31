#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

class vect;
class matrix;

vect operator *(const matrix& m, const vect& v);
vect operator *(const vect& v, const matrix& m);
vect solveSystem(const matrix& A, const vect& b);




class vect
{
private:
	int dim;
	double* elements;

public:

	vect()
	{
		cout << "Created NULL vector\n";
	}

	vect(int d)
	{
		dim = d;
		elements = new double[dim];
		for (int i = 0; i < dim; i++)
			elements[i] = 0;
	}

	vect(int d, double* x)
	{
		dim = d;
		elements = new double[dim];
		for (int i = 0; i < dim; i++)
			elements[i] = x[i];
	}

	~vect()
	{
		delete[] elements;
	}

	vect(vect& x)
	{
		dim = x.dim;
		elements = new double[dim];
		for (int i = 0; i < dim; i++)
			elements[i] = x.elements[i];
	}

	void print()
	{
		cout << "\nVector: ( ";
		for (int i = 0; i < dim; i++)
		{
			cout << elements[i];
			if (i < dim - 1)
				cout << ",";
		}
		cout << " )\n";
	}

	vect operator +(const vect& r)
	{
		vect tmp(dim);
		for (int i = 0; i < dim; i++)
			tmp.elements[i] = elements[i] + r.elements[i];

		return tmp;
	}

	vect operator -(const vect& r)
	{
		vect tmp(dim);
		for (int i = 0; i < dim; i++)
			tmp.elements[i] = elements[i] - r.elements[i];

		return tmp;
	}

	vect operator *(double c)
	{
		vect tmp(dim);
		for (int i = 0; i < dim; i++)
			tmp.elements[i] = c * elements[i];

		return tmp;
	}

	vect operator /(double c)
	{
		vect tmp(dim);
		for (int i = 0; i < dim; i++)
			tmp.elements[i] = elements[i] / c;

		return tmp;
	}


	double operator *(const vect& r)
	{
		vect tmp(r.dim);
		double p = 0;
		for (int i = 0; i < dim; i++)
			p = p + (elements[i] * r.elements[i]);
		return p;
	}

	vect& operator =(const vect& r)
	{
		this->dim = r.dim;
		this->elements = new double[r.dim];
		for (int i = 0; i < dim; i++)
			this->elements[i] = r.elements[i];

		return *this;
	}

	friend vect operator *(const matrix& m, const vect& v);
	friend vect operator *(const vect& v, const matrix& m);
	friend vect solveSystem(const matrix& A, const vect& b);



};

class matrix
{
private:
	int rows;
	int cols;
	vector<vector<double>> elements;

public:
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
	{
		cout << "\nMatrix:\n";
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

	friend vect operator *(const matrix& m, const vect& v);
	friend vect operator *(const vect& v, const matrix& m);
	friend vect solveSystem(const matrix& A, const vect& b);


};

vect operator *(const matrix& m, const vect& v)
{
	int dim = v.dim;
	double* result = new double[dim];
	for (int i = 0; i < dim; i++)
	{
		double sum = 0;
		for (int j = 0; j < dim; j++)
		{
			sum += m.elements[i][j] * v.elements[j];
		}
		result[i] = sum;
	}
	vect tmp(dim, result);
	delete[] result;
	return tmp;
}

vect operator *(const vect& v, const matrix& m)
{
	int dim = v.dim;
	double* result = new double[dim];
	for (int i = 0; i < dim; i++)
	{
		double sum = 0;
		for (int j = 0; j < dim; j++)
		{
			sum += m.elements[i][j] * v.elements[j];
		}
		result[i] = sum;
	}
	vect tmp(dim, result);
	delete[] result;
	return tmp;
}

vect solveSystem(const matrix& A, const vect& b)
{
	// Проверка совместности системы и подготовка переменных

	int n = A.rows;
	matrix Aug(n, n + 1); // Расширенная матрица системы

	// Заполнение расширенной матрицы системы
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			Aug.elements[i][j] = A.elements[i][j];
		}
		Aug.elements[i][n] = b.elements[i];
	}

	// Решение системы методом Гаусса

	// Прямой ход
	for (int k = 0; k < n; k++) {
		// Поиск ведущего элемента
		int maxRow = k;
		for (int i = k + 1; i < n; i++) {
			if (fabs(Aug.elements[i][k]) > fabs(Aug.elements[maxRow][k])) {
				maxRow = i;
			}
		}

		// Перестановка строк
		if (maxRow != k) {
			for (int j = k; j <= n; j++) {
				swap(Aug.elements[k][j], Aug.elements[maxRow][j]);
			}
		}

		// Приведение к треугольному виду
		for (int i = k + 1; i < n; i++) {
			double factor = -Aug.elements[i][k] / Aug.elements[k][k];
			for (int j = k; j <= n; j++) {
				Aug.elements[i][j] += factor * Aug.elements[k][j];
			}
		}
	}

	// Обратный ход
	vect solution(n);
	for (int i = n - 1; i >= 0; i--) {
		double sum = 0;
		for (int j = i + 1; j < n; j++) {
			sum += Aug.elements[i][j] * solution.elements[j];
		}
		solution.elements[i] = (Aug.elements[i][n] - sum) / Aug.elements[i][i];
	}

	return solution;
}


int main()
{
	vector<vector<double>> matrix1Data =
	{
		{1, 2},
		{3, 4},
	};

	double a1[2] = { 5,6 };

	matrix m1(2, 2, matrix1Data);

	vect v1(2, a1);

	vect otv;

	otv = m1 * v1;
	cout << "Matrix and vector multiplication:";
	otv.print();
	cout << endl;

	otv = solveSystem(m1, v1);
	cout << "Solving a system of linear algebraic equations:"; //Решение системы линейных алгебраических уравнений, где матрица - система линейных уравнений, а b - правая часть уравнения(свободные члены)
	otv.print();
	cout << endl;


	/*vector<vector<double>> matrix1Data =
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


	return 0;

	double a1[3] = { 1,10,11 }, a2[3] = { 7,12,-6 };
	vect v1(3, a1), v2(3, a2);

	v1.print();
	v2.print();
	double c = v1 * v2;
	cout << "dot product: " << c << "\n";

	vect v3;
	cout << "sum: ";
	v3 = v1 + v2;
	v3.print();
	cout << "\n";

	cout << "sub: ";
	v3 = v1 - v2;
	v3.print();
	cout << "\n";

	cout << "mul: ";
	v3 = v1 * 3;
	v3.print();
	cout << "\n";

	cout << "div: ";
	v3 = v1 / 3;
	v3.print();
	cout << "\n";*/

}