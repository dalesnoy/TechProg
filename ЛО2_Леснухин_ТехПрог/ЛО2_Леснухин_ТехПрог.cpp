
#include <iostream>
#include <cmath>
using namespace std;

class vect
{
private:
	int dim;
	double* elements;

public:
	vect(); // vect(): конструктор без параметров, печатает сообщение об создании нулевого вектора
	
	
	vect(int d);  // vect(int d): конструктор, создает нулевой вектор размерности d
	
	
	vect(int d, double* x);/*vect(int d, double* x) : конструктор с параметром, создает размерности
							d и заполняет его элементами из массива x */
	
	
	~vect(); //~vect(): деструктор, освобождает память, выделенную для массива elements
	
	
	vect(vect& x); //vect(vect &x): конструктор копирования, создает копию вектора x
	
	
	void print(); // void print(): функция печати элементов вектора

	vect operator +(const vect& r); /* vect operator +(const vect& r) : перегрузка оператора "+",
									возвращает сумму векторов*/
	
	
	vect operator -(const vect& r);	/*vect operator -(const vect &r): перегрузка оператора "-",
									возвращает разность векторов*/

	vect operator *(double c); /* vect operator *(double c): перегрузка оператора "*",
								возвращает вектор, умноженный на скаляр c*/
	
	vect operator /(double c);  /*vect operator /(double c): перегрузка оператора "/",
								возвращает вектор, разделенный на скаляр c*/

	double operator *(const vect& r); /*double operator *(const vect &r):
										перегрузка оператора ".", возвращает скалярное произведение
										векторов*/

	vect& operator =(const vect& r); /*vect& operator =(const vect &r): перегрузка оператора "=",
										присваивает вектору r*/
};


vect::vect()
{
	cout << "Created NULL vector\n";
}

vect::vect(int d)
{
	dim = d;
	elements = new double[dim];
	for (int i = 0; i < dim; i++)
		elements[i] = 0;
}

vect::vect(int d, double* x)
{
	dim = d;
	elements = new double[dim];
	for (int i = 0; i < dim; i++)
		elements[i] = x[i];
}

vect::~vect()
{
	delete[] elements;
}

vect::vect(vect& x)
{
	dim = x.dim;
	elements = new double[dim];
	for (int i = 0; i < dim; i++)
		elements[i] = x.elements[i];
}

void vect::print()
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

vect vect::operator +(const vect& r)
{
	vect tmp(dim);
	for (int i = 0; i < dim; i++)
		tmp.elements[i] = elements[i] + r.elements[i];

	return tmp;
}

vect vect::operator -(const vect& r)
{
	vect tmp(dim);
	for (int i = 0; i < dim; i++)
		tmp.elements[i] = elements[i] - r.elements[i];

	return tmp;
}

vect vect::operator *(double c)
{
	vect tmp(dim);
	for (int i = 0; i < dim; i++)
		tmp.elements[i] = c * elements[i];

	return tmp;
}

vect vect::operator /(double c)
{
	vect tmp(dim);
	for (int i = 0; i < dim; i++)
		tmp.elements[i] = elements[i] / c;

	return tmp;
}


double vect::operator *(const vect& r)
{
	vect tmp(r.dim);
	double p = 0;
	for (int i = 0; i < dim; i++)
		p = p + (elements[i] * r.elements[i]);
	return p;
}

vect& vect::operator =(const vect& r)
{
	this->dim = r.dim;
	this->elements = new double[r.dim];
	for (int i = 0; i < dim; i++)
		this->elements[i] = r.elements[i];

	return *this;
}


int main()
/*В функции main() создаются два вектора v1 и v2, вызываются функции для их печати
,нахождение скалярного произведения, суммы, разности, умножения и деления на скаляр.
Результат выполнения каждой функции печатается на экране*/
{
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
	cout << "\n";

}