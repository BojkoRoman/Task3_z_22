/**
*@file Task3_z_22
*@brief solution (C++ code) of Task3.22 GL 
* (��������� �������, ��� �������� ��������� ������� ���� ������� ������ �����, �������� �������.
* �� ����� ���������� ������� ��������� ������ ���� ����� ������� ������� ������ �����, ��������� ������� ���� ���������.
* ������� ������ �������� ��� ����� � ����������� ����������� �������.)
*Copyright 2014 by Roman Bojko
*/

#include <iostream>
#include <ctime> 
using namespace std;

/**
  * @brief	������� ������� ��������� ������� ���� �������
  * @param	[in]    vec1 �������� �� ������ ������
  * @param	[in]    vec2 �������� �� ������ ������
  * @param	[in]    vecSize ����� ���� �������
  * @return	������� ��������� �������
  */
float scalarProduct(float *vec1, float *vec2, unsigned vecSize);

/**
  * @brief	������� ���� ������ ���� � ��������� ��������� ��������
  * @param	[in,out]    matrix ������ ������� ������
  * @param	[in]		rows ʳ������ ����� � �������
  * @param	[in]		columns ʳ������ �������� � �������
  * @return	void
  */
void swapRowsWithLargestScalarProduct(float **matrix, unsigned rows, unsigned columns);

int main()
{
	setlocale(LC_ALL,"Ukrainian");
	srand(time(0));
	unsigned rows, columns;

	cout << "������ ����� ����� � �������� � �������:" << endl;
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

	cout << "��������� ������� ��� ��������� ����������� ������� �� 0 �� 9" << endl;
	cout<<"--------------"<<endl;
	for(unsigned i = 0; i < rows; i++)
	{
		for(unsigned j = 0; j < columns; j++)

			cout << matrix[i][j] << " ";
		cout << endl;
	}
	cout<<"--------------"<<endl;

	swapRowsWithLargestScalarProduct(matrix, rows, columns);

	cout << "����������� �������:" << endl;
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

	// ����������� ������������� ���������� ������� ���� �������  � ���� ������� �����
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

	// ���� �������
	cout << "����� � ��������� ��������� �������� �:" << endl;
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
	// ���� ������ �������� ��� ����� 
	for(unsigned i = 0; i < columns; i++)
	{
		float temp = matrix[row2][i];
		matrix[row2][i] = matrix[row1][i];
		matrix[row1][i] = temp;
	}
}