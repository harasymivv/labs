// Захист від множинного включення
#pragma once

// Оголошення класу Vector3D
class Vector3D
{
private:
  double x, y, z;    // Координати вектора
  int max_index;     // Максимальний індекс
  Vector3D *vectors; // Вказівник на масив векторів

public:
  Vector3D();                                // Конструктор за замовчуванням
  Vector3D(double _x, double _y, double _z); // Конструктор з параметрами
  ~Vector3D();                               // Деструктор
  void get_array_of_vectors(int n);          // Метод отримання масиву векторів
  double length();                           // Метод обчислення довжини вектора
  void output_lenght(int n);                 // Метод виведення довжин векторів
  void find_max_length(int n);               // Метод знаходження вектора максимальної довжини з n перших векторів
  void print_max_length();                   // Метод виведення вектора максимальної довжини
};