// type_traits.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

template <typename T1, typename T2>
auto add(T1 t1, T2 t2) -> decltype(t1 + t2)
{
  return t1 + t2;
}

template <typename T1, typename T2>
auto mul(T1 t1, T2 t2) -> decltype(t1 * t2)
{
  static_assert(std::is_integral<T1>::value, "Type T1 must be integral");
  static_assert(std::is_integral<T2>::value, "Type T2 must be integral");

  return t1 * t2;
}

int main()
{
  std::cout << add(1, 2) << std::endl;
  std::cout << add("abc", 2) << std::endl;

  std::cout << mul(1, 2) << std::endl;
  //std::cout << mul("abc", 2) << std::endl;  // static_assert

  return 0;
}

