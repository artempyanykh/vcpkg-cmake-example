#include "CLI/App.hpp"
#include "CLI/Config.hpp"
#include "CLI/Formatter.hpp"
#include <fmt/ranges.h>
#include <vector>

// Forward declarations
void demo1Handler();
void demo2Handler();

int main(int argc, char **argv) {
  CLI::App app{"Template project with cmake and vcpkg"};
  app.require_subcommand();

  auto demo1 = app.add_subcommand("demo1", "Demo 1");
  auto demo2 = app.add_subcommand("demo2", "Demo 2");

  CLI11_PARSE(app, argc, argv);

  if (demo1->parsed()) {
    demo1Handler();
  }

  if (demo2->parsed()) {
    demo2Handler();
  }

  return 0;
}

void demo1Handler() {
  fmt::print("Welcome to Demo 1!\n\n");

  std::vector<int> vec{1, 2, 3, 4};
  fmt::print("Vec: {}\n", vec);

  vec.push_back(5);
  fmt::print("Vec: {}\n", vec);

  auto closure = [vec](int n) mutable {
    vec.push_back(n);
    fmt::print("Closure vec: {}\n", vec);
  };
  closure(6);
  closure(7);

  fmt::print("Vec: {}\n", vec);
}

void demo2Handler() {
  const auto msg = R"(Welcome to Demo 2!
There's nothing here currently.
)";
  fmt::print(msg);
}
