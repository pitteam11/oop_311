#include <iostream>
#include <conio.h>

using namespace std;

class Array
{
	int size;
	int* array;
public:
	Array(int size = 10);
	~Array();
	int getSize() const;
	int getValue(int index) const;
	void setValue(int index, int value);
	void display(int index) const;
};
Array::Array(int size)
{
	Array::size = size;
	array = new int[size];
}
Array::~Array()
{
	delete[] array;
}
int Array::getSize() const
{
	return size;
}
int Array::getValue(int index) const
{
	return array[index];
}
void Array::setValue(int index, int value)
{
	array[index] = value;
}
void Array::display(int index) const
{
	cout << array[index] << " ";
}

void display(const Array& array)
{
	for (int i = 0; i < array.getSize(); i++)
	{
		array.display(i);
	}
	cout << endl;
}

int main()
{
	cout << "Dynamic integer array" << endl;
	int size = 4;
	Array array(size);
	for (int i = 0; i < size; i++)
	{
		array.setValue(i, size - i);
	}
	display(array);
	cout << "!!!" << endl;
	display(Array(3));
	_getch();
	return 0;
}