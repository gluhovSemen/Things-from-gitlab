#include "OutputTask.hpp"
#include <list>

void printLine (std::ostream & out, const std::list<element_t> & line)
{
  for (auto iter = line.begin(); iter != line.end(); iter++)
  {
    out << (*iter).value;
  }
  out << std::endl;
}

int reorganizeLine (std::ostream & out, std::list<element_t> & line)
{
  std::size_t width = 0;
  std::list<element_t> newLine;
  while (!line.empty())
  {
    newLine.push_front(line.back());
    width += line.back().value.size();
    line.pop_back();
    if (newLine.front().type == element_t::WORD || newLine.front().type == element_t::NUMBER)
    {
      break;
    }
  }
  printLine(out, line);
  line = newLine;
  return width;
}

void formatText (std::ostream & out, unsigned int width, const std::list<element_t> & vector)
{
  std::size_t currentWidth = 0;
  std::list<element_t> line;
  for(auto iter = vector.begin(); iter != vector.end(); iter++)
  {
    switch((*iter).type)
    {
    case element_t::MARK:
      if(currentWidth + 1 > width)
      {
        currentWidth = reorganizeLine(out, line);
      }
      line.push_back(*iter);
      currentWidth += (*iter).value.size();
      break;
    
    case element_t::DASH:
      if(currentWidth + 4 > width)
      {
        currentWidth = reorganizeLine(out, line);
      }
      line.push_back(element_t { " ", element_t::SPACE });
      line.push_back(*iter);
      currentWidth += (*iter).value.size() + 1;
      break;
    
    case element_t::WORD:

    case element_t::NUMBER:
      if(currentWidth + (*iter).value.size() + 1 > width)
      {
        printLine(out, line);
        line.clear();
        currentWidth = 0;
      }
      else if(!line.empty())
      {
        line.push_back(element_t { " ", element_t::SPACE });
        currentWidth++;
      }
      line.push_back(*iter);
      currentWidth += (*iter).value.size();
      break;

    case element_t::SPACE:
      break;
    }

  }
  if(!line.empty())
  {
    printLine(out, line);
  }
}

bool trueOrder(const std::list<element_t> & vector)
{
  if(!vector.empty() && (vector.front().type != element_t::WORD) && (vector.front().type != element_t::NUMBER))
  {
    return false;
  }
  for(auto iter = vector.begin(); iter != vector.end(); iter++)
  {
    switch((*iter).type)
    {
    case element_t::WORD:

    case element_t::NUMBER:
      if((*iter).value.size() > 20)
      {
        return false;
      }
      break;

    case element_t::DASH:
      if((*iter).value.size() != 3)
      {
        return false;
      }
      if(iter != vector.begin())
      {
        const element_t &prev = *std::prev(iter);
        if((prev.type == element_t::DASH) || ((prev.type == element_t::MARK) && (prev.value != ",")))
        {
          return false;
        }
      }
      break;

    case element_t::MARK:
      if(iter != vector.begin())
      {
        const element_t &prev = *std::prev(iter);
        if((prev.type == element_t::DASH) || (prev.type == element_t::MARK))
        {
          return false;
        }
      }
      break;
      
    case element_t::SPACE:
      break;
    }
  }
  return true;
}
