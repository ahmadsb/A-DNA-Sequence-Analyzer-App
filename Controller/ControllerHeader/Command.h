#ifndef COMMAND_H
#define COMMAND_H

#include <vector>
#include <iostream>

class Command
{
public:
  virtual std::string doCommand(std::vector<std::string> params) = 0;
};

#endif