#include "TTime.h"

void TTime::generate_rand_num() {
  a = 1 + (rand() % 60);
  b = 1 + (rand() % 160);
  c = 1 + (rand() % 160);
}

void TTime::print() {
  cout << "Hour: " << a << " \\ Minute: " << b << " \\ Second: " << c << "   |   ";
}

void TTime::permissible_value_check(){
  if (a <= 0 || a > 24) {
    increment(b);
  }
  else if (b <= 0 || b > 60) {
    increment(b);
  }
  else if (c <= 0 || c > 60){
    increment(b);
  }
}
