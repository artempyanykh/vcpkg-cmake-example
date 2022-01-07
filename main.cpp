#include <fmt/ranges.h>
#include <vector>

int main(int argc, char **argv) {
  fmt::print("Hello CPP\n");

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
