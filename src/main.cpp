#include <iostream>
#include "../crow/amalgamate/crow_all.h"
#include "http_get.hxx"

using std::cout;
using std::cerr;
using std::endl;

constexpr const static unsigned short cores{8};
constexpr const static unsigned short port{
#ifdef PORT
    PORT
#else
    8080
#endif
};

static inline const char* resp(
    const std::string& user,
    const std::string& repo,
    const std::string& branch,
    const std::string& file) noexcept {
  return (user + repo + branch + file).c_str();
}

int main() noexcept {
  {
    crow::SimpleApp app{};
    CROW_ROUTE(app, "/<string>/<string>/<string>/<string>")(resp);

    app
        .port(port)
        .bindaddr("0.0.0.0")
        .concurrency(cores)
        .multithreaded()
        .run();
  }

  return EXIT_SUCCESS;
}