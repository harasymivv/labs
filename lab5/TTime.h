#ifndef TIME_H
#define TIME_H

#include "TTriad.h"

class TTime:public TTriad {
public:
  void generate_rand_num() override;
  void print() override;
  void permissible_value_check() override;
};

#endif