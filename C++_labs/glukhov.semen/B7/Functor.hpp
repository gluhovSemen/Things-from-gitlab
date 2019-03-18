#ifndef FUNCTOR_HPP
#define FUNCTOR_HPP

#include <iostream>

class Functor
{
public:
  Functor(std::ostream & ostream);

  Functor(const Functor & func);
  Functor & operator=(const Functor & func);

  ~Functor ();

  void operator ()(int x);

  friend std::ostream & operator<< (std::ostream & ostream, Functor & func);

private:
  int max_, min_, positive_, negative_, elements_, first_;
  long long int sum_, oddS_, evenS_;
  bool wasFirst_, isFirstEqualLast_;
  std::ostream *ostream_;
  bool isCopy_;
};

#endif //FUNCTOR_HPP

