// override_final.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

class A
{
public:
  virtual void f(int) { std::cout << "A::f" << std::endl; }
  virtual void g() const { std::cout << "A::g" << std::endl; };
  virtual void q() const { std::cout << "A::q" << std::endl; };
};

class B : public A
{
public:
  virtual void f(int) override /* final */ /* keyword will cause compilation error if uncomment */ { std::cout << "B::f" << std::endl; }
  virtual void g() /* override */ /* keyword will cause compilation error if uncomment */ { std::cout << "B::g" << std::endl; };
  virtual void q() const override { std::cout << "B::q" << std::endl; };
};

class C : public B
{
public:
  virtual void f(int) override { std::cout << "C::f" << std::endl; }
};

int main()
{
  A a;
  B b;
  C c;

  A *p = &c;

  a.f(10);
  b.f(11);
  c.f(12);

  p->f(10);

  p->g(); // will print A::g as expected

  p->q(); // will print B::q as expected

  return 0;
}

