#include "InputTask.hpp"
#include <locale>

InputParser::InputParser(std::istream & in) :
  in_(in)
{}

void InputParser::parseInput()
{
  while(in_)
  {
    readElement();
  }
}

std::list<element_t>::iterator InputParser::begin()
{
  return text_.begin();
}

std::list<element_t>::iterator InputParser::end()
{
  return text_.end();
}

void InputParser::readWord()
{
  element_t el { "", element_t::WORD };
  do
  {
    char c = in_.get();
    el.value.push_back(c);
    
    if(c == '-' && in_.peek() == '-')
    {
      el.value.pop_back();
      in_.unget();
      break;
    }
    
  } while ((std::isalpha<char>(in_.peek(), std::locale())) || (in_.peek() == '-'));
  text_.push_back(el);
}

void InputParser::readNumber()
{
  element_t el { "", element_t::NUMBER };
  char point = std::use_facet<std::numpunct<char>>(std::locale()).decimal_point();
  bool pointRead = false;
  do
  {
    char c = in_.get();
    if(c == point)
    {
      if(pointRead)
      {
        in_.unget();
        break;
      }
      pointRead = true;
    }
    el.value.push_back(c);
  } while((std::isdigit<char>(in_.peek(), std::locale()) || (in_.peek() == point)));

  text_.push_back(el);
}

void InputParser::readDash()
{
  element_t el{ "", element_t::DASH };
  while(in_.peek() == '-')
  {
    char c = in_.get();
    el.value.push_back(c);
  }
  text_.push_back(el);
}

void InputParser::readElement()
{
  char c = in_.get();
  while(std::isspace(c, std::locale()))
  {
    c = in_.get();
  }
  
  if (isalpha(c, std::locale()))
  {
    in_.unget();
    readWord();
  }
  else if (c == '-')
  {
    if (in_.peek() == '-')
    {
      in_.unget();
      readDash();
    }
    else
    {
      in_.unget();
      readNumber();
    }
  }
  else if ((c == '+' || (isdigit(c, std::locale()))))
  {
    in_.unget();
    readNumber();
  }
  else if (ispunct(c, std::locale()))
  {
    element_t el{ "", element_t::MARK };
    el.value.push_back(c);
    text_.push_back(el);
  }
}
