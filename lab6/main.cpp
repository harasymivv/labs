#include "class.h"

using namespace std;

int main() {
    int type_of_key;
    int type_of_value;

    do {
        cout << "1. int\n2. double\n3. char\n4. string\n" << endl;
        cout << "Enter the number corresponding to the type you want to use for the key: ";
        cin >> type_of_key;
    } while (type_of_key > 4 || type_of_key < 1);

    do {
        cout << "Enter the number corresponding to the type you want to use for the value: ";
        cin >> type_of_value;
    } while (type_of_value > 4 || type_of_value < 1);

    if (type_of_key == 1) {
        if (type_of_value == 1) {
            LinkedListMap<int, int> arr;
            arr.main_method();
        } else if (type_of_value == 2) {
            LinkedListMap<int, double> arr;
            arr.main_method();
        } else if (type_of_value == 3) {
            LinkedListMap<int, char> arr;
            arr.main_method();
        } else if (type_of_value == 4) {
            LinkedListMap<int, string> arr;
            arr.main_method();
        }
    } else if (type_of_key == 2) {
        if (type_of_value == 1) {
            LinkedListMap<double, int> arr;
            arr.main_method();
        } else if (type_of_value == 2) {
            LinkedListMap<double, double> arr;
            arr.main_method();
        } else if (type_of_value == 3) {
            LinkedListMap<double, char> arr;
            arr.main_method();
        } else if (type_of_value == 4) {
            LinkedListMap<double, string> arr;
            arr.main_method();
        }
    } else if (type_of_key == 3) {
        if (type_of_value == 1) {
            LinkedListMap<char, int> arr;
            arr.main_method();
        } else if (type_of_value == 2) {
            LinkedListMap<char, double> arr;
            arr.main_method();
        } else if (type_of_value == 3) {
            LinkedListMap<char, char> arr;
            arr.main_method();
        } else if (type_of_value == 4) {
            LinkedListMap<char, string> arr;
            arr.main_method();
        }
    } else if (type_of_key == 4) {
        if (type_of_value == 1) {
            LinkedListMap<string, int> arr;
            arr.main_method();
        } else if (type_of_value == 2) {
            LinkedListMap<string, double> arr;
            arr.main_method();
        } else if (type_of_value == 3) {
            LinkedListMap<string, char> arr;
            arr.main_method();
        } else if (type_of_value == 4) {
            LinkedListMap<string, string> arr;
            arr.main_method();
        }
    }

    return 0;
}