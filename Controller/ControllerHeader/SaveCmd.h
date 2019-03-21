#ifndef SAVE_COMMAND_H
#define SAVE_COMMAND_H

#include "Command.h"
#include "../../Models/ModelsHeader/DNA.h"


/*> cmd >>> save <seq> [<filename>]*/
class SaveCmd : public Command
{
  public:
    std::string doCommand(std::vector<std::string> params);
};

#endif