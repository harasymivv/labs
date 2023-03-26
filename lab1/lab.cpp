#include <iostream>
#include <fstream>
#include <conio.h>
#include <ctype.h>
#include <cstring>
#include <sstream>
#include <string>
#include "func.h"
// підключаємо бібліотеки

using namespace std;

// Оголошення головної функції
int main(int argc, char *argv[])
{

    if (isMode("FileStream", argc, argv))
    {
        cout << "Using FileStream mode" << endl;
        // Оголошення змінних
        string filename;
        char check;

        // Запит ім'я файлу
        cout << "Enter file name: ";

        name_of_file(filename);
        // Створення файлу
        create_text_file(filename);

        do
        {
            append_text_to_file(filename);

            // Додавання тексту до файлу та його обробка
            int removedWords = 0;
            int spacesRemoved = 0;
            int commasRemoved = 0;
            int periodsRemoved = 0;
            int removedWordsWithpunct = 0;

            // Виклик функції для обробки тексту
            removeSingleCharWordsFromFile(filename, removedWords, removedWordsWithpunct, spacesRemoved, commasRemoved, periodsRemoved);
            // Запис результатів в файл output.txt
            writeToOutputFile("output.txt", removedWords, removedWordsWithpunct, spacesRemoved, commasRemoved, periodsRemoved);


            cout << "\nOutput File: " << endl; 
            cout << "---------------------------------------" << endl;
            printFileContents();
            cout << "---------------------------------------\n" << endl;

            // Запит користувача щодо додавання ще тексту
            cout << "Do you want to appent some text?" << endl;
            check = getch();

        } while (check == '\r');
    }
    // Перевірка режиму FilePointer
    else if (isMode("FilePointer", argc, argv))
    {
        cout << "Using FilePointer mode" << endl;
        // Оголошення змінної
        char filename[100];

        char check;

         // Запит ім'я файлу
        cout << "Enter file name: ";
        name_of_file(filename);
        // Створення файлу
        create_text_file(filename);
        // Додавання тексту до файлу та його обробка
        do
        {
            append_text_to_file(filename);
            // Оголошення змінних для зберігання інформації про обробку тексту
            int removedWords = 0;
            int spacesRemoved = 0;
            int commasRemoved = 0;
            int periodsRemoved = 0;
            int removedWordsWithpunct = 0;

            // Виклик функції для обробки тексту
            removeSingleCharWordsFromFile(filename, removedWords, removedWordsWithpunct, spacesRemoved, commasRemoved, periodsRemoved);
            // Запис результатів в файл output.txt
            writeToOutputFile("output.txt", removedWords, removedWordsWithpunct, spacesRemoved, commasRemoved, periodsRemoved);
            

            cout << "\nOutput File: " << endl; 
            cout << "---------------------------------------" << endl;
            printFileContents();
            cout << "---------------------------------------\n" << endl;
            // Запит користувача щодо додавання ще тексту
            cout << "Do you want to appent some text?" << endl;
            check = getch();

        } while (check == '\r');
    }
    return 0;
}