#include "../ControllerHeader/SaveCmd.h"
#include <fstream>
#include <sstream>
#include "../../Models/ModelsHeader/DataStructure.h"
/*> cmd >>> save <seq> [<filename>]*/

std::string SaveCmd::doCommand(std::vector<std::string> params)
{
    if (2 == params.size() || 1 == params.size())
    {
        char hasId = 0;
        std::string idDna;
        if ('#' == params[0][0])
        {
            idDna = params[0];
            hasId = 1;
        }
        else if ('@' == params[0][0])
        {
            if (DataStructure::m_DataStructureNameId.find(params[0]) != DataStructure::m_DataStructureNameId.end()) //found
            {
                idDna = DataStructure::m_DataStructureNameId[params[0]];
            }
            else
            {
                return "not found in data";
            }
        }

        if (DataStructure::m_DataStructureIdDna.find(idDna) != DataStructure::m_DataStructureIdDna.end()) //found
        {
            std::string nameFile;
            std::string path;
            if (2 == params.size())
            {
                nameFile = params[1];
            }
            else
            {
                std::string name = "";
                if (hasId)
                    name = DataStructure::m_DataStructureIdName[idDna];
                else
                    name = params[0].erase(0, 1);
                std::cout << name << std::endl;
                nameFile = name + ".rawdna";
            }

            path = "../Models/Files/" + nameFile; /*create file with path from file of run*/

            std::ofstream myfile(path.c_str(), std::ios::app);
            if (myfile.is_open()) /*Returns true in the same cases as bad()*/
            {
                myfile << *DataStructure::m_DataStructureIdDna[idDna] << "\n";
                myfile.close();
                return "successfully save command";
            }
            else
            {
                return "the file already exists";
            }
        }
        else
            return "not found in data";
    }

    return "Usage:  save <seq> [<filename>]";
}
