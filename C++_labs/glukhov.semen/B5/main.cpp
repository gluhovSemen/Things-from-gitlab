#include "algoritm.h"

int main()
{
  std::vector<DataStruct> arr;
  try {
    fillVector(arr, std::cin);
    sortVector(arr);
    printVector(arr, std::cout);
  }
  catch (std::exception &exc)
  {
    std::cerr << exc.what();
    return 1;
  }
  return 0;
}

