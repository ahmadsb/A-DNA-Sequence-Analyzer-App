#ifndef NEW_COMMAND_H
#define NEW_COMMAND_H

#include "Command.h"
#include "../../Models/ModelsHeader/DNA.h"


/*> cmd >>> new <sequence> [@<sequence_name>]*/
class NewCmd : public Command
{
  public:
    std::string doCommand(std::vector<std::string> params);
};

#endif