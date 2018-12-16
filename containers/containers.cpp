// containers.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int main()
{

  // map

  std::map<int, std::string> oism = { { 1, "one" },{ 2, "two" },{ 3, "three" } };
  std::map<int, std::string> oism2 = oism;
  std::map<int, std::string> oism3 = std::move(oism2);

  for (const auto &kvp : oism3)
  {
    std::cout << kvp.first << std::endl;
    for (auto v : kvp.second)
    {
      std::cout << v << std::endl;
    }
  }

  std::multimap<int, std::string> oismm = { { 1, "one" }, { 2, "two" }, { 3, "three" }, { 1, "one" }, { 2, "two" }, { 3, "three" } };
  std::multimap<int, std::string> oismm2 = oismm;
  std::multimap<int, std::string> oismm3 = std::move(oismm2);

  for (const auto &kvp : oismm3)
  {
    std::cout << kvp.first << std::endl;
    for (auto v : kvp.second)
    {
      std::cout << v << std::endl;
    }
  }

  std::unordered_map<int, std::string> uism = { { 1, "one" },{ 2, "two" },{ 3, "three" } };
  std::unordered_map<int, std::string> uism2 = uism;
  std::unordered_map<int, std::string> uism3 = std::move(uism2);

  for (const auto &kvp : uism3)
  {
    std::cout << kvp.first << std::endl;
    for (auto v : kvp.second)
    {
      std::cout << v << std::endl;
    }
  }

  std::unordered_multimap<int, std::string> uismm = { { 1, "one" }, { 2, "two" }, { 3, "three" }, { 1, "one" }, { 2, "two" }, { 3, "three" } };
  std::unordered_multimap<int, std::string> uismm2 = uismm;
  std::unordered_multimap<int, std::string> uismm3 = std::move(uismm2);

  for (const auto &kvp : uismm3)
  {
    std::cout << kvp.first << std::endl;
    for (auto v : kvp.second)
    {
      std::cout << v << std::endl;
    }
  }

  // set

  std::set<int> ois = { 1, 2, 3 };
  std::set<int> ois2 = ois;
  std::set<int> ois3 = std::move(ois2);

  for (const auto &kvp : ois3)
  {
    std::cout << kvp << std::endl;
  }

  std::multiset<int> oism_ = { 1, 2, 3, 1, 2, 3 };
  std::multiset<int> oism2_ = oism_;
  std::multiset<int> ois3m_ = std::move(oism2_);

  for (const auto &kvp : ois3m_)
  {
    std::cout << kvp << std::endl;
  }

  std::unordered_set<int> uis = { 1, 2, 3 };
  std::unordered_set<int> uis2 = uis;
  std::unordered_set<int> uis3 = std::move(uis2);

  for (const auto &kvp : uis3)
  {
    std::cout << kvp << std::endl;
  }

  std::unordered_multiset<int> uism_ = { 1, 2, 3, 1, 2, 3 };
  std::unordered_multiset<int> uism2_ = uism_;
  std::unordered_multiset<int> uis3m_ = std::move(uism2_);

  for (const auto &kvp : uis3m_)
  {
    std::cout << kvp << std::endl;
  }


  return 0;
}

