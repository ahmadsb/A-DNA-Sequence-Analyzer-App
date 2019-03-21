#ifndef LIST_COMMAND_H
#define LIST_COMMAND_H

#include "Command.h"
#include "../../Models/ModelsHeader/DNA.h"

/*> cmd >>> load <file_name>  [@<sequence_name>] */
class ListCmd : public Command
{
  public:
    std::string doCommand(std::vector<std::string> params);
};

#endif