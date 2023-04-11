#include "class.h"
#include <iostream>
#include <cmath>

using namespace std;

// Конструктор за замовчуванням
Vector3D::Vector3D()
{
  x = 0.0;
  y = 0.0;
  z = 0.0;
  max_index = -1;
  vectors = nullptr; // ініціалізація масиву векторів
}

// Конструктор з параметрами
Vector3D::Vector3D(double _x, double _y, double _z)
{
  x = _x;
  y = _y;
  z = _z;
  max_index = -1;
  vectors = nullptr; // ініціалізація масиву векторів
}

// Деструктор
Vector3D::~Vector3D()
{
  delete[] vectors; // звільнення пам'яті, виділеної під масив vectors
}

// Метод для отримання масиву векторів заданого розміру
void Vector3D::get_array_of_vectors(int n)
{
  vectors = new Vector3D[n]; // виділення пам'яті під масив vectors
  for (int i = 0; i < n; i++)
  {
    double x, y, z;
    cout << "Enter x, y, and z values for vector " << i + 1 << ": ";
    cin >> x >> y >> z;
    vectors[i] = Vector3D(x, y, z); // створення об'єкту Vector3D та додавання його до масиву vectors
  }
}

// Метод для обчислення довжини вектора
double Vector3D::length()
{
  return sqrt(x * x + y * y + z * z);
}

// Метод для виведення довжини кожного вектора у масиві vectors
void Vector3D::output_lenght(int n)
{
  for (int i = 0; i < n; i++)
  {
    cout << "length of " << i + 1 << " vector = " << vectors[i].length() << endl;
  }
}

// Метод для знаходження вектора з максимальною довжиною у масиві vectors
void Vector3D::find_max_length(int n)
{
  if (vectors != nullptr) // перевірка, що масив vectors не порожній
  {
    double max_length = 0.0;
    for (int i = 0; i < n; i++)
    {
      double length = vectors[i].length();
      if (length > max_length)
      {
        max_length = length;
        max_index = i;
      }
    }
  }
}

// Метод для виведення на екран вектора з максимальною довжиною
void Vector3D::print_max_length()
{
  if (max_index >= 0) // перевірка, що індекс вектора з максимальною довжиною є дійсним
  {
    cout << "Vector with max length: (" << vectors[max_index].x << ", "
         << vectors[max_index].y << ", " << vectors[max_index].z << ")" << endl; // виведення вектора з максимальною довжиною на екран
  }
  else
  {
    cout << "Array is empty." << endl; // виведення повідомлення про те, що масив vectors порожній
  }
}