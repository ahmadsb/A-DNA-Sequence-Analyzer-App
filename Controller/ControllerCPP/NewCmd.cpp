#include "../ControllerHeader/NewCmd.h"
#include "../../Models/ModelsHeader/DNA.h"
#include "../../Models/ModelsHeader/Nucleotide.h"
#include "../../Models/ModelsHeader/DataStructure.h"
#include <sstream>
/*> cmd >>> new <sequence> [@<sequence_name>]*/

std::string NewCmd::doCommand(std::vector<std::string> params)
{
    if (2 == params.size() || 1 == params.size())
    {

        try
        {
            DNA *dnaSeq = new DNA(params[0]);
            std::string temp = "";
            if (2 == params.size())
            {
                if (1 == params[1].length() && '@' == params[1][0])
                {
                    return "invalid name";
                }
                return DataStructure().addItem(params[0], params[1], dnaSeq);
            }
            else if (1 == params.size())
            {
                return DataStructure().addItem(params[0], temp, dnaSeq);
            }
        }
        catch (std::exception &e)
        {
            std::stringstream out;
            out << e.what();
            return out.str() + " :'" + params.front() + "'";
        }
    }

    return "Usage: new <sequence> [@<sequence_name>]";
}
