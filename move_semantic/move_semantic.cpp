// move_semantic.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


template <typename T>
class Array
{
  std::string          name_;
  size_t               size_;
  std::unique_ptr<T[]> buffer_;

public:
  // default constructor
  Array() :
    size_(16),
    buffer_(new T[16])
  {}

  // constructor
  Array(const std::string& name, size_t size) :
    name_(name),
    size_(size),
    buffer_(new T[size])
  {}

  // copy constructor
  Array(const Array& copy) :
    name_(copy.name_),
    size_(copy.size_),
    buffer_(new T[copy.size_])
  {
    T* source = copy.buffer_.get();
    T* dest = buffer_.get();
    memcpy(dest, source, copy.size_);
  }

  // copy assignment operator
  Array& operator=(const Array& copy)
  {
    if (this != &copy)
    {
      name_ = copy.name_;

      if (size_ != copy.size_)
      {
        buffer_ = nullptr;
        size_ = copy.size_;
        buffer_ = (size_ > 0) ? new T[size_] : nullptr;
      }

      T* source = copy.buffer_.get();
      T* dest = buffer_.get();
      memcpy(dest, source, copy.size_);
    }

    return *this;
  }

  // move constructor
  Array(Array&& temp) :
    name_(std::move(temp.name_)),
    size_(temp.size_),
    buffer_(std::move(temp.buffer_))
  {
    temp.buffer_ = nullptr;
    temp.size_ = 0;
  }

  // move assignment operator
  Array& operator=(Array&& temp)
  {
    assert(this != &temp); // assert if this is not a temporary

    buffer_ = nullptr;
    size_ = temp.size_;
    buffer_ = std::move(temp.buffer_);

    name_ = std::move(temp.name_);

    temp.buffer_ = nullptr;
    temp.size_ = 0;

    return *this;
  }
};

template <typename T>
Array<T> getArray(const std::string& name)
{
  Array<T> b(name, 128);
  return b;
}
int main()
{
  Array<int> b1;
  Array<int> b2("buf2", 64);
  Array<int> b3 = b2;
  Array<int> b4 = getArray<int>("buf4");
  b1 = getArray<int>("buf5");
  return 0;
}

