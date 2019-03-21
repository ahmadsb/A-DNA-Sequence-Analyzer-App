
#ifndef DESIGN_PATTERNS_FACTORY_H
#define DESIGN_PATTERNS_FACTORY_H

#include "Command.h"
#include "NewCmd.h"
#include "LoadCmd.h"
#include "SaveCmd.h"
#include "ListCmd.h"
#include "LenCmd.h"
#include "PairCmd.h"
#include<map>

typedef std::map<std::string, Command *> Commands;

class CommandFactory
{
public:
  CommandFactory();
  Command *create(const std::string &cmd);
private:
  Commands m_commands;
};

#endif