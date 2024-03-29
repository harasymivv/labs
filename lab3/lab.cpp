#include <iostream>
#include "class.h"
// Підключається власний заголовочний файл, де оголошено клас Vector3D.

using namespace std;


int main() {
   // Змінна n - кількість векторів, яку вводить користувач.
    int n;
    // Виводиться повідомлення про введення кількості векторів.
    cout << "Enter number of vectors: ";
    // Вводиться кількість векторів.
    cin >> n;
    cout << '\n';
    // Створюється об'єкт класу Vector3D.
    Vector3D vector;
    // Викликається метод класу Vector3D, що заповнює масив векторів введеними користувачем значеннями.
    vector.get_array_of_vectors(n);
    cout << "\n---------------------------------" << endl;
    // Викликається метод класу Vector3D, що виводить довжини кожного вектора.
    vector.output_lenght(n);
    cout << '\n';
    // Викликається метод класу Vector3D, що знаходить вектор з максимальною довжиною.
    vector.find_max_length(n); 
    // Викликається метод класу Vector3D, що виводить вектор з максимальною довжиною.
    vector.print_max_length();
    cout << "---------------------------------" << endl;
    
    return 0;
}