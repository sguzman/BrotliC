#include <iostream>
#include "../crow/amalgamate/crow_all.h"
#include "http_get.hxx"

using std::cout;
using std::cerr;
using std::endl;

constexpr const static unsigned short cores{8};

int main() noexcept {
  cout << "Hello world" << endl;

  cout << Curl::get("https://raw.githubusercontent.com/sguzman/BrotliEncoderService/master/build.sc") << endl;

  return EXIT_SUCCESS;
}