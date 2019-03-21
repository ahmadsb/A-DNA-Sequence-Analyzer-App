#ifndef LEN_COMMAND_H
#define LEN_COMMAND_H

#include "Command.h"
#include "../../Models/ModelsHeader/DNA.h"

/*> cmd >>> load <file_name>  [@<sequence_name>] */
class LenCmd : public Command
{
  public:
    std::string doCommand(std::vector<std::string> params);
};

#endif