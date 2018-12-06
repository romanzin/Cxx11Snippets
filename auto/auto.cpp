// auto.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <map>
#include <vector>
#include <string>

template <typename A, typename B>
auto additive(A a, B b) -> decltype(a + b) 
{
  return a + b;
}

int main()
{
  /* Simple variable */
  auto i = 0x555;

  auto ptr = nullptr;

  /* Container value */

  std::map<std::string, std::vector<std::string>> map = { { "x0", { { "Alpha" }, { "Beta" } } } , { "y0",{ { "Gamma" },{ "Delta" } } } };

  for (auto &it1 = map.begin(); it1 != map.end(); ++it1)
  {
    for (auto &it2 = std::begin(it1->second); it2 != std::end(it1->second); ++it2)
    {
      std::cout << *it2 << " ";
    }

    std::cout << "\n";
  }

  auto add = additive(0, 0.5);

  std::cout << add << "\n";

  return 0;
}

