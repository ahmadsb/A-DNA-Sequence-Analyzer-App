#ifndef LOAD_COMMAND_H
#define LOAD_COMMAND_H

#include "Command.h"
#include "../../Models/ModelsHeader/DNA.h"

using std::vector;
/*> cmd >>> load <file_name>  [@<sequence_name>] */
class LoadCmd : public Command
{
  public:
    std::string doCommand(std::vector<std::string> params);
};

#endif