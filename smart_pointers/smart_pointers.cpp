// smartpointers.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

void foo(int* ptr)
{
  std::cout << *ptr << std::endl;
}

void bar(std::shared_ptr<int> p)
{
  ++(*p);
}

void foo_bad(std::shared_ptr<int> p, int init)
{
  *p = init;
}

int main()
{
  std::unique_ptr<int> ptr1(new int(1));
  std::unique_ptr<int> ptr2 = std::move(ptr1); // transfer ownership, move ctor is called

  if (ptr1)
  {
    foo(ptr1.get());
  }

  (*ptr2)++;

  if (ptr2)
  {
    foo(ptr2.get());
  }

  std::shared_ptr<int> ptr3(new int(1));
  std::shared_ptr<int> ptr4 = ptr3;

  bar(ptr4);
  foo(ptr3.get());

  // bad practice, rand may throw exception

  foo_bad(std::shared_ptr<int>(new int(1)), rand());

  // good practice

  auto ptr5 = std::make_shared<int>(1);
  std::weak_ptr<int> wptr = ptr5;

  do {
    auto sp = wptr.lock();
    std::cout << *sp << std::endl;
  } while (0);

  ptr5.reset();

  if (wptr.expired())
  {
    std::cout << "expired" << std::endl;
  }

  return 0;
}

