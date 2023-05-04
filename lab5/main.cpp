#include "TTriad.h"
#include "TTime.h"
#include "TDate.h"

using namespace std;

int main(){

    int m, n;
    srand(time(0));

    cout << "How many date objects do you want to generate: ";
    cin >> n;
    cout << "How many time objects do you want to generate: ";
    cin >> m;


    TTriad* p = new TDate[n]; // масив об'єктів TDate
    

    cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~TDate objects~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

    cout << "       Date before changes                      Date after changes";
    cout << "\n-----------------------------------------------------------------------------" << endl;
    for (int i = 0; i < n; i++) {
        cout << "| ";
        p -> generate_rand_num();
        p -> print();
        p -> permissible_value_check();
        p -> print();
        cout << "\n-----------------------------------------------------------------------------" << endl;
    }
    delete[] p;

    p = new TTime[m]; // масив об'єктів TTime
    cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~TTime objects~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

    cout << "        Time before changes                      Time after changes";
    cout << "\n----------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < m; i++) {
        cout << "| ";
        p -> generate_rand_num();
        p -> print();
        p -> permissible_value_check();
        p -> print();
        cout << "\n----------------------------------------------------------------------------------" << endl;
    }

    delete[] p;

    return 0;
}