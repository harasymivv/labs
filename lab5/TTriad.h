#ifndef TTRIAD_H
#define TTRIAD_H
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

class TTriad
{

protected:
  int a;
  int b;
  int c;

public:
  void increment(int &minutes);
  void decrement(int &days);

  virtual void generate_rand_num() = 0;
  virtual void print() = 0;
  virtual void permissible_value_check() = 0;
};

#endif 