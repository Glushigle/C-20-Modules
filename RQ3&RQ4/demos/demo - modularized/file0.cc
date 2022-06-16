module;
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <string>

export module file0;
export void print_results(const char *input) {
  std::cout << input << std::endl;
  // std::cout << "haha!" << std::endl;
}

class myobj {
private:
  int val = 0;

public:
  myobj(int a) { val = a; }
};

void foo() {
  for (int i = 0; i < 150; ++i) {
    myobj obj = myobj(i); // unnecessary assignment operation
    // do something with obj
  }
}