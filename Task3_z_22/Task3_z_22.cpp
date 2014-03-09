/**
*@file Task3_z_22
*@brief solution (C++ code) of Task3.22 GL 
* (Розробити функцію, яка обчислює скалярний добуток двох векторів дійсних чисел, однакової довжини.
* На основі розробленої функції визначити номери двох рядків введеної матриці дійсних чисел, скалярний добуток яких найбільший.
* Поміняти місцями елементи цих рядків і надрукувати результуючу матрицю.)
*Copyright 2014 by Roman Bojko
*/

#include <iostream>
#include <ctime> 
using namespace std;

/**
  * @brief	Функція визначає скалярний добуток двох векторів
  * @param	[in]    vec1 Вказівник на перший вектор
  * @param	[in]    vec2 Вказівник на другий вектор
  * @param	[in]    vecSize Розмір обох векторів
  * @return	Повертає скалярний добуток
  */
float scalarProduct(float *vec1, float *vec2, unsigned vecSize);

/**
  * @brief	Функція міняє місцями ряди з найбільшим скалярним добутком
  * @param	[in,out]    matrix Задана матриця масиву
  * @param	[in]		rows Кількість рядків в матриці
  * @param	[in]		columns Кількість стовпців в матриці
  * @return	void
  */
void swapRowsWithLargestScalarProduct(float **matrix, unsigned rows, unsigned columns);

int main()
{
	setlocale(LC_ALL,"Ukrainian");
	srand(time(0));
	unsigned rows, columns;

	cout << "Введіть число рядків і стовпців у матриці:" << endl;
	cin >> rows >> columns;
	
	float **matrix = new float*[rows];
	for(unsigned i = 0; i < rows; i++)
	{
		matrix[i] = new float[columns];

		for(unsigned j = 0; j < columns; j++){
			matrix[i][j] = rand()%10;

			/*cout << "Enter " << i + 1 << " row" << endl;  
		    for(unsigned j = 0; j < columns; j++)
			cin >> matrix[i][j];*/
		}
	}

	cout << "Початкова Матриця яка зоповнена випадковими числами від 0 до 9" << endl;
	cout<<"--------------"<<endl;
	for(unsigned i = 0; i < rows; i++)
	{
		for(unsigned j = 0; j < columns; j++)

			cout << matrix[i][j] << " ";
		cout << endl;
	}
	cout<<"--------------"<<endl;

	swapRowsWithLargestScalarProduct(matrix, rows, columns);

	cout << "Результуюча Матриця:" << endl;
	cout<<"--------------"<<endl;
	for(unsigned i = 0; i < rows; i++)
	{
		for(unsigned j = 0; j < columns; j++)

			cout << matrix[i][j] << " ";
		cout << endl;
	}
	cout<<"--------------"<<endl;
	for(unsigned i = 0; i < rows; i++)
		delete[] matrix[i];
	delete[] matrix;
	system("pause");
	return 0;
}

float scalarProduct(float *vec1, float *vec2, unsigned vecSize)
{
	if(!vec1 || !vec2)
		return 0.0f;

	float result = 0.0f;

	for(unsigned i = 0; i < vecSize; i++)
	{
		result += vec1[i] * vec2[i];
	}

	return result;
}

void swapRowsWithLargestScalarProduct(float **matrix, unsigned rows, unsigned columns)
{
	if(!matrix || !columns || !rows)
		return;

	float max = 0.0f;
	unsigned row1 = 0, row2 = 0;

	// Знаходження максимального скалярного добутку двох векторів  і зміна позиції рядків
	for(unsigned i = 0; i < rows - 1; i++)
	{
		for(unsigned j = i + 1; j < rows; j++)
		{
			float scalar = scalarProduct(matrix[i], matrix[j], columns);

			if(scalar > max)
			{
				max = scalar;
				row1 = i;
				row2 = j;
			}
		}
	}

	// Друк векторів
	cout << "Рядки з найбільшим скалярним добутком є:" << endl;
	cout<<"--------------"<<endl;
	cout << row1 + 1 << ": ( ";
	for(unsigned i = 0; i < columns; i++)
		cout << matrix[row1][i] << " ";
	cout << ")" << endl;

	cout << row2 + 1 << ": ( ";
	for(unsigned i = 0; i < columns; i++)
		cout << matrix[row2][i] << " ";
	cout << ")" << endl;
	cout<<"--------------"<<endl;
	// Зміна місцями елементів цих рядків 
	for(unsigned i = 0; i < columns; i++)
	{
		float temp = matrix[row2][i];
		matrix[row2][i] = matrix[row1][i];
		matrix[row1][i] = temp;
	}
}