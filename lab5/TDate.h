#ifndef DATE_H
#define DATE_H

#include "TTriad.h"

class TDate:public TTriad {
public:
  void generate_rand_num() override;
  void print() override;
  void permissible_value_check() override;
};

#endif