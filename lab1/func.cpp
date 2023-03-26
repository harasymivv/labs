#include <iostream>
#include <fstream>
#include <conio.h>
#include <ctype.h>
#include <cstring>
#include <sstream>
#include <string>

// підключаємо бібліотеки

using namespace std;

// Функції FileStream

// Зчитуємо назву файлу і добавляємо ".txt"
void name_of_file(string &filename)
{
    getline(cin, filename);
    filename.append(".txt");
}

// Функція для того, щоб прибрати односимвольні слова
void removeSingleCharWords(string &str, int &count)
{
    int i = 0;
    while (i < str.size())
    {
        // Якщо поточний символ не є пробілом, він є частиною слова
        if (str[i] != ' ')
        {
            // Відстежуєм початок і кінець поточного слова
            int start = i;
            int end = i;
            while (end < str.size() && str[end] != ' ')
            {
                end++;
            }
            // Якщо довжина поточного слова дорівнює 1, видалимо його з рядка
            if (end - start == 1)
            {
                str.erase(start, 1);
                count++;
                // Перемістімо індекс назад, оскільки поточний символ було стерто
                i--;
            }
            // Оновимо індекс до кінця поточного слова
            i = end;
        }
        // Якщо поточний символ є пробілом, перейдемо до наступного символу
        else
        {
            i++;
        }
    }
}

// Функція для видалення послідовних знаків пунктуації та пробілів
void removeSequentialPunctuation(string &result, int &spacesRemoved, int &commasRemoved, int &periodsRemoved)
{
    for (int i = 0; i < result.length() - 1; i++)
    {
        // Перевіряємо, чи наступний символ також є знаком пунктуації або пробілом
        if (ispunct(result[i]) && ispunct(result[i + 1]) || isspace(result[i]) && isspace(result[i + 1]))
        {
            // Якщо поточний символ - пробіл, збільшуємо лічильник видалених пробілів
            if (isspace(result[i]))
            {
                spacesRemoved++;
            }
            // Якщо поточний символ - кома, збільшуємо лічильник видалених ком
            else if (result[i] == ',')
            {
                commasRemoved++;
            }
            // Якщо поточний символ - крапка, збільшуємо лічильник видалених крапок
            else if (result[i] == '.')
            {
                periodsRemoved++;
            }
            // Видаляємо поточний символ
            result.erase(i, 1);
            i--;
        }
    }
}

// Функція для видалення односимвольних слів після яких йде пунктуаційний знак
void removeSingleCharWordWithPunctuation(string &str, int &removedWordsWithpunct)
{
    string result;
    string delimiters = " .,!?:;"; // список розділових знаків і пробілів

    // Розбиремо введений рядок на слова
    int start = 0, end = 0;
    while ((end = str.find_first_of(delimiters, start)) != string::npos)
    {
        string word = str.substr(start, end - start);

        // Перевіримо, чи слово складається з одного символу, а після нього немає розділових знаків
        if (word.length() == 1 && (end == str.length() || delimiters.find(str[end]) != string::npos))
        {
            // Нічого не робити, пропустити це слово
            removedWordsWithpunct++; // збільшити лічильник видалених слів
        }
        else
        {
            // Додамо слово до рядка результату
            result += word;
            if (end != str.length())
            {
                result += str[end]; // Додамо роздільник
            }
        }

        start = end + 1;
    }

    // Додайте останнє слово (якщо є)
    string lastWord = str.substr(start);
    if (lastWord.length() > 0)
    {
        result += lastWord;
    }

    str = result;
}

// Функція для видалення лишніх пробілів
void removeSpace(string &result, int &spacesRemoved)
{
    for (int i = 0; i < result.length() - 1; i++)
    {
        // Перевіряємо, чи наступний символ також є знаком пунктуації або пробілом
        if (isspace(result[i]) && isspace(result[i + 1]))
        {
            // Якщо поточний символ - пробіл, збільшуємо лічильник видалених пробілів
            // if (isspace(result[i]))
            // {
            //     spacesRemoved++;
            // }

            // Видаляємо поточний символ
            result.erase(i, 1);
            i--;
        }
    }
}

// Функція для порядкового перероблення тексту
void removeSingleCharWordsFromFile(const string &filename, int &removedWords, int &removedWordsWithpunct, int &spacesRemoved, int &commasRemoved, int &periodsRemoved)
{
    // Відкриваємо файл для читання
    ifstream infile(filename);
    if (!infile)
    {
        cout << "Error: unable to open input file " << filename << endl;
    }
    // Відкриваємо файл для запису
    ofstream outfile("output.txt");
    if (!outfile)
    {
        cout << "Error: unable to open output file" << endl;
    }
    string line;

    // Зчитуємо кожен рядок з файлу
    while (getline(infile, line))
    {
        // Видаляємо слова з одним символом
        removeSingleCharWords(line, removedWords);
        // Видаляємо послідовності знаків пунктуації та пробілів
        removeSequentialPunctuation(line, spacesRemoved, commasRemoved, periodsRemoved);
        // Видаляємо слова з одним символом та знаком пунктуації
        removeSingleCharWordWithPunctuation(line, removedWordsWithpunct);
        // Записуємо змінений рядок в файл
        removeSpace(line, spacesRemoved);
        outfile << line << endl;
        // Очищуємо рядок
        line.clear();
    }
    // Закриваємо файли
    infile.close();
    outfile.close();
}

// Функція для запису до вихідного файлу результатів видалення слів та знаків пунктуації
void writeToOutputFile(string filename, int removedWords, int removedWordsWithpunct, int spacesRemoved, int commasRemoved, int periodsRemoved)
{
    // Відкриваємо файл для дозапису
    ofstream outputFile(filename, ios_base::app);
    // Перевіряємо, чи вдалося відкрити файл
    if (!outputFile.is_open())
    {
        cout << "Error: Unable to open file " << filename << endl;
        return;
    }

    // Записуємо кількість видалених символів
    outputFile << "Removed characters: " << removedWords + removedWordsWithpunct << endl;
    // Записуємо кількість видалених пробілів
    outputFile << "Removed spaces: " << spacesRemoved << endl;
    // Записуємо кількість видалених ком у тексті
    outputFile << "Removed commas: " << commasRemoved << endl;
    // Записуємо кількість видалених крапок у тексті
    outputFile << "Removed periods: " << periodsRemoved << endl;
    // Закриваємо файл
    outputFile.close();
}

// Функція додавання тексту у файл
void append_text_to_file(string filename)
{
    string input;
    // Відкриття файлу для додання тексту в нього
    ofstream outfile(filename, ios::app);

    cout << "\nEnter some text:\n";

    // Зчитувати рядки та додавати їх у файл, поки користувач не натисне двічі enter
    while (getline(cin, input))
    {
        if (input.empty())
        {
            break;
        }
        outfile << input << endl; // додаємо рядок до кінця файлу
    }

    outfile.close(); // закриваємо файл
}

// Функція для створення текстового файлу з заданим ім'ям
void create_text_file(string filename)
{
    // Створюємо файл з заданим ім'ям
    ofstream file(filename);
    // Закриваємо файл
    file.close();
    // Виводимо повідомлення про успішне створення файлу
    cout << "File created successfully!" << endl;
}


// Функції FilePointer

// Функція для отримання імені файлу від користувача
void name_of_file(char *filename)
{
    // Отримуємо ім'я файлу від користувача
    fgets(filename, 100, stdin);
    // Видаляємо символ переносу рядка з кінця введення
    filename[strcspn(filename, "\n")] = '\0';
    // Додаємо розширення .txt до імені файлу
    strcat(filename, ".txt");
}

// Функція для того, щоб прибрати односимвольні слова
void removeSingleCharWords(char* str, int& count) {
    int i = 0;
    while (str[i] != '\0') {
        // If the current character is not a space, it is part of a word
        if (str[i] != ' ') {
            // Keep track of the start and end of the current word
            int start = i;
            int end = i;
            while (str[end] != '\0' && str[end] != ' ') {
                end++;
            }
            // If the length of the current word is 1, remove it from the string
            if (end - start == 1) {
                for (int j = start; str[j] != '\0'; j++) {
                    str[j] = str[j+1];
                }
                count++;
                // Move the index back one because the current character was erased
                i--;
            }
            // Update the index to the end of the current word
            i = end;
        }
        // If the current character is a space, move to the next character
        else {
            i++;
        }
    }
}

// Функція для видалення лишніх пробілів
void removeSpace(char *result, int& spacesRemoved)
{
    int len = strlen(result);
    int i = 0;
    while (i < len - 1)
    {
        if (isspace(result[i]) && isspace(result[i + 1]))
        {
            // if (isspace(result[i]))
            // {
            //     spacesRemoved++;
            // }
            
            // викорситаємо memmove для переміщення блоку пам'яті з одного місця в інше
            memmove(result + i, result + i + 1, len - i - 1); 
            result[len - 1] = '\0';
            len--;  // Update the length of the string
        }
        else
        {
            i++;  // Move to the next character
        }
    }
}

// Функція для видалення послідовних знаків пунктуації та пробілів з рядка
void removeSequentialPunctuation(char *result, int& spacesRemoved, int& commasRemoved, int& periodsRemoved)
{
    // Отримуємо довжину рядка
    int len = strlen(result);
    // Ініціалізуємо змінну-лічильник
    int i = 0;
    while (i < len - 1)
    {
        // Перевіряємо, чи є поточний та наступний символи знаками пунктуації або пробілами
        if ((ispunct(result[i]) && ispunct(result[i + 1])) || (isspace(result[i]) && isspace(result[i + 1])))
        {
            // Якщо поточний та наступний символи - пробіли, то збільшуємо лічильник видалених пробілів
            if (isspace(result[i]))
            {
                spacesRemoved++; // збільшення лічильника видалених пробілів
            }
            // Якщо поточний та наступний символи - коми, то збільшуємо лічильник видалених ком
            else if (result[i] == ',')
            {
                commasRemoved++; // збільшення лічильника видалених ком
            }
            // Якщо поточний та наступний символи - крапки, то збільшуємо лічильник видалених крапок
            else if (result[i] == '.')
            {
                periodsRemoved++; // збільшення лічильника видалених крапок
            }
            memmove(result + i, result + i + 1, len - i - 1); // видалення символу з рядка
            result[len - 1] = '\0';                           // встановлення кінця рядка
            len--;                                            // зменшення довжини рядка
        }
        else
        // якщо символ не є крапкою, перейти до наступного символу
        {
            i++;
        }
    }
}

// Функція для видалення односимвольних слів після яких йде пунктуаційний знак
void removeSingleCharWordWithPunctuation(char* str, int& removedWordsWithpunct) {
    char result[1000] = ""; // initialize an empty result string
    char delimiters[] = " .,!?:;"; // list of punctuation marks and whitespace
    int start = 0, end = 0;
    
    // Split the input string into words
    while (str[start]) {
        end = strcspn(&str[start], delimiters) + start; // find the next delimiter
        int wordLen = end - start;
        char* word = (char*) malloc(sizeof(char) * (wordLen + 1)); // allocate memory for the word buffer
        strncpy(word, &str[start], wordLen); // copy the word to a temporary buffer
        word[wordLen] = '\0'; // null-terminate the string
        
        // Check if the word is a single character and not followed by punctuation
        if (wordLen == 1 && (str[end] == '\0' || strchr(delimiters, str[end]) != NULL)) {
            // Do nothing, skip this word
            removedWordsWithpunct++; // increment removed words counter
        } else {
            // Add the word to the result string
            strcat(result, word);
            if (str[end]) {
                char delimiter[2] = {str[end], '\0'};
                strcat(result, delimiter); // Add the delimiter
            }
        }
        start = end + 1;
        free(word); // free the memory allocated for the word buffer
    }
    
    // Copy the result back to the input string
    strcpy(str, result);
}

// Функція для видалення останього односимвольного слова
void remove_last_character(char* str, int& count){
    if (isalpha(str[strlen(str) - 2]) && isspace(str[strlen(str) - 3])) {
    str[strlen(str) - 2] = '\0';
    }
}

// Функція для порядкового перероблення тексту
void removeSingleCharWordsFromFile(const char *filename, int& removedWords, int&removedWordsWithpunct, int& spacesRemoved, int& commasRemoved, int& periodsRemoved) // функція видалення слів з одним символом з файлу
{
    FILE *infile = fopen(filename, "r"); // відкриття файлу для читання
    if (!infile)                         // перевірка чи файл існує
    {
        cout << "Error: unable to open input file " << filename << endl; // повідомлення про помилку відкриття файлу
        return;
    }
    FILE *outfile = fopen("output.txt", "w"); // відкриття файлу для запису результату
    if (!outfile)                             // перевірка чи файл існує
    {
        cout << "Error: unable to open output file" << endl; // повідомлення про помилку відкриття файлу
        return;
    }
    char line[1024]; // масив символів для збереження рядка з файлу

    while (fgets(line, 1024, infile)) // прохід по всім рядкам файлу
    {
        removeSequentialPunctuation(line, spacesRemoved, commasRemoved, periodsRemoved); // виклик функції для видалення послідовних пунктуаційних знаків
        removeSingleCharWords(line, removedWords);                                       // виклик функції для видалення слів з одним символом
        removeSingleCharWordWithPunctuation(line, removedWordsWithpunct);                // виклик функції для видалення слів з одним символом та пунктуацією
        remove_last_character (line, removedWordsWithpunct);                             // виклик функції для видалення останього односимвольного знаку
        removeSpace(line, spacesRemoved);                                                // виклик функції для видалення лишніх пробілів
        line[strlen(line) - 1] = '\0';                                                   // встановлення кінця рядка
        fprintf(outfile, "%s\n", line);                                                  // запис рядка до вихідного файлу
        memset(line, 0, sizeof(line));                                                   // очищення масиву символів
    }
    fclose(infile);  // закриття вхідного файлу
    fclose(outfile); // закриття вихідного файлу
}

// Відкриваємо файл для записування результатів та передаємо інформацію про видалені слова та пунктуацію
void writeToOutputFile(const char *filename, int removedWords, int removedWordsWithpunct, int spacesRemoved, int commasRemoved, int periodsRemoved)
{
    FILE *outputFile;
    outputFile = fopen(filename, "a");
    if (!outputFile)
    {
        cout << "Error: Unable to open file " << filename << endl;
        return;
    }
    // Записуємо кількість видалених символів, пробілів, ком та крапок
    fprintf(outputFile, "\nRemoved characters: %d\n", removedWords + removedWordsWithpunct);
    fprintf(outputFile, "Removed spaces: %d\n", spacesRemoved);
    fprintf(outputFile, "Removed commas: %d\n", commasRemoved);
    fprintf(outputFile, "Removed periods: %d\n", periodsRemoved);
    // закриваємо файл
    fclose(outputFile);
}

// Функція додавання тексту у файл
void append_text_to_file(const char *filename)
{
    char input[1024];
    FILE *outfile = fopen(filename, "a");
    if (!outfile)
    {
        cout << "Error: Unable to open file: " << filename << endl;
        return;
    }
    cout << "\nEnter some text:\n";

    // Зчитувати рядки та додавати їх у файл, поки користувач не натисне двічі enter
    while (fgets(input, 1024, stdin))
    {
        if (strcmp(input, "\n") == 0)
        {
            break;
        }
        fputs(input, outfile); // додаємо рядок до кінця файлу
    }

    fclose(outfile); // закриваємо файл
}

// Функція для створення текстового файлу з заданим ім'ям
void create_text_file(const char *filename)
{
    // створюємо текстовий файл
    FILE *file = fopen(filename, "w");
    fclose(file);
    cout << "File created successfully!" << endl;
}


// main
// Виводимо дані з файлу
void printFileContents() {
    ifstream file("output.txt");
    if (file) {
        string line;
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();
    }
}

// Перевіряємо, чи вказаний режим виконання програми
bool isMode(const char *modeValue, int argc, char *argv[])
{
    // Проходимо по всіх аргументах командного рядка
    for (int i = 1; i < argc; i++)
    {
        // Якщо зустрічаємо аргумент "-mode" та наступний аргумент дорівнює modeValue, повертаємо true
        if (strcmp(argv[i], "-mode") == 0 && i + 1 < argc)
        {
            return strcmp(argv[i + 1], modeValue) == 0;
        }
    }
    // Якщо режим не був знайдений, повертаємо false
    return false;
}