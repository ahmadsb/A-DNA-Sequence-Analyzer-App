#include "../ControllerHeader/LoadCmd.h"
#include "../../Models/ModelsHeader/DataStructure.h"
#include <fstream>
#include <sstream>

/*> cmd >>> load <file_name>  [@<sequence_name>]*/
std::string LoadCmd::doCommand(std::vector<std::string> params)
{

    if (2 == params.size() || 1 == params.size())
    {
        std::string nameFile;
        std::string path;

        nameFile = params[0];
        path = "../Models/Files/" + nameFile; /*create file with path from file of run*/

        std::string line;
        std::ifstream myfile(path.c_str());
        if (myfile.is_open())
        {
            while (getline(myfile, line))
            {
                try
                {
                    DNA *dnaSeq = new DNA(line);
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

                myfile.close();
                return "successfully load command";
            }

            return "Unable to open file";
        }

        return "Usage:  save <seq> [<filename>]";
    }
}
