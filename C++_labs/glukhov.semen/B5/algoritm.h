#ifndef _ALGORITM_H_
#define _ALGORITM_H_
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

struct DataStruct
{
  int key1;
  int key2;
  std::string str;
};

void fillVector(std::vector<DataStruct> & arr, std::istream &stream);
void sortVector(std::vector<DataStruct> &arr);
void printVector(const std::vector<DataStruct> & arr, std::ostream &stream);

#endif
