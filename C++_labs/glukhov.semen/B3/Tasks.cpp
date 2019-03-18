#include "Tasks.hpp"
#include "QueueWirhPriority.hpp"

void Tasks::task1()
{
  QueueWithPriority<std::string> queue;

  std::string line;
  while (std::getline(std::cin, line)) {
    std::stringstream ss(line);
    std::string action;
    ss >> action;

    if (action == "add") {
      std::string priority;
      ss >> priority;

      ss.ignore();
      std::string data;
      std::getline(ss, data);

      if (data.empty()) {
        std::cout << "<INVALID COMMAND>" << '\n';
      } else if (priority == "high") {
        queue.add(data, ElementPriority::high);
      } else if (priority == "normal") {
        queue.add(data, ElementPriority::normal);
      } else if (priority == "low") {
        queue.add(data, ElementPriority::low);
      } else {
        std::cout << "<INVALID COMMAND>" << '\n';
      }
    } else if (action == "accelerate") {
      queue.accelerate();
    } else if (action == "get") {
      try {
        std::cout << queue.get() << '\n';
      } catch (const std::exception &exception) {
        std::cout << exception.what() << '\n';
      }
    } else {
      std::cout << "<INVALID COMMAND>" << '\n';
    }
  }
}

void Tasks::task2()
{
  std::list<int> list;

  int num;
  while (std::cin >> num) {
    if ((num < 1) || (num > 20)) {
      throw std::out_of_range("Out of range");
    }
    list.push_back(num);
  }

  if (!std::cin.eof()) {
    throw std::invalid_argument("Incorrect");
  }

  if (list.size() > 20) {
    throw std::invalid_argument("Too many");
  }

  auto left = list.begin();
  auto right = list.rbegin();

  auto pivot = list.begin();
  std::advance(pivot, list.size() / 2);

  while (left != pivot) {
    std::cout << *left++ << ' ' << *right++ << ' ';
  }

  if (list.size() % 2 == 1) {
    std::cout << *pivot;
  }
  std::cout << '\n';
}

