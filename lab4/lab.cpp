#include <iostream>
#include "class.h"

using namespace std;

int main() {

    int n;

    bool* input_data = get_data_from_user(n);

    BooleanVector B1(n);

    BooleanVector B2(input_data, n);

    cout << "\nB1: ";
    B1.print_array();
    cout << "B2: ";
    B2.print_array();

    ~B1;
    cout << "\nB1 complement: ";
    B1.print_array();
    cout << endl;
    BooleanVector B3;

    // Compute conjunction of B1c and B2
    B3 = B1 & B2;
    
    cout << "B3: ";
    B3.print_array();

    cout << "B3 weight: " << B3.getWeight() << endl;
    cout << endl;

    delete[] input_data;

    return 0;
}
