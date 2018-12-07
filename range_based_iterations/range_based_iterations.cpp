// range_based_iterations.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

int main()
{
  int arr[] = { 1, 2, 3, 4, 5 };

  for (int &e : arr)
  {
    e *= e;
  }


  std::map<std::string, std::vector<int>> map = { { "x0",{ { 0 },{ 1 } } } ,{ "y0",{ { 2 },{ 3 } } } };

  for (const auto &kvp : map)
  {
    std::cout << kvp.first << std::endl;
    for (auto v : kvp.second)
    {
      std::cout << v << std::endl;
    }
  }

  return 0;
}

