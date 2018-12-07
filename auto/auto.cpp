// auto.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

template <typename A, typename B>
auto additive(A a, B b) -> decltype(a + b) // inspects the declared type of an entity or the type and value category of an expression.
{
  return a + b;
}

enum class Options { None, One, All };

int main()
{
  // simple variable 
  auto i = 0x555;

  auto ptr = nullptr;

  // strongly typed enum

  Options o = Options::All;
  auto en = Options::All;

  int temp = (int)en;

  // container value 

  std::map<std::string, std::vector<std::string>> map = { { "x0", { { "Alpha" }, { "Beta" } } } , { "y0",{ { "Gamma" },{ "Delta" } } } };

  for (auto &it1 = map.begin(); it1 != map.end(); ++it1)
  {
    for (auto &it2 = std::begin(it1->second); it2 != std::end(it1->second); ++it2)
    {
      std::cout << *it2 << " ";
    }

    std::cout << "\n";
  }

  // decltype

  auto add = additive(0, 0.5);

  std::cout << add << "\n";

  auto func_a = [](int a, int b) -> int
  {
    return a * b;
  };

  i = func_a(1, 2);

  decltype(func_a) func_b = func_a; // the type of a lambda function is unique and unnamed

  std::cout << "i = " << i << ", " << "j = " << func_b(3, 4) << '\n';

  return 0;
}

