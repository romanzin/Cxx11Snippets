// lambda.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

int main()
{
  std::vector<int> v = { 1, 2, 3 };

  std::for_each(std::begin(v), std::end(v), [](int n) { std::cout << n << std::endl; });

  auto is_odd = [](int n) {return n % 2 == 1; };
  auto pos = std::find_if(std::begin(v), std::end(v), is_odd);
  if (pos != std::end(v))
  {
    std::cout << *pos << std::endl;
  }

  std::function<int(int)> fib = [&fib](int n) { return n < 2 ? 1 : fib(n - 1) + fib(n - 2); };

  std::cout << fib(5) << std::endl;

  return 0;
}

