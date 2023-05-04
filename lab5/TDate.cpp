#include "TDate.h"


    void TDate::generate_rand_num() {
        a = 1 + (rand() % 60);
        b = 1 + (rand() % 24);
        c = 1 + (rand() % 10000);
    }

    void TDate::print(){
        cout << "Day: " << a << " \\ Month: " << b << " \\ Year: " << c << "   |   ";
    }

    void TDate::permissible_value_check(){
        if ((b > 12 || (c > 9999 || c < 1000)) || (b > 12 && (c > 9999 || c < 1000))) {
            if (a > 5) {
                decrement(a);
            }
            else {
                a = 5 - a;
                b -= 1;
                if (b == 1 || b == 3 || b == 5 || b == 7 || b == 8 || b == 10 || b == 12) {
                    a = 31 - a;
                }
                else if (b == 2) {
                    a = 29 - a;
                }
                else {
                    a = 30 - a;
                }
            }
        }
        else {
            if (c % 4 == 0 && (c % 100 != 0 || c % 400 == 0)) { //leap year
                if (b == 2) {
                    if (a > 29) {
                        decrement(a);
                    }
                }
            }
            else {
                if (b == 1 || b == 3 || b == 5 || b == 7 || b == 8 || b == 10 || b == 12) {
                    if (a > 31) {
                        decrement(a);
                    }
                }
                else if (b == 2) {
                    if (a > 28) {
                        decrement(a);
                    }
                }
                else {
                    if (a > 30) {
                        decrement(a);
                    }
                }
            }
        }
    }

