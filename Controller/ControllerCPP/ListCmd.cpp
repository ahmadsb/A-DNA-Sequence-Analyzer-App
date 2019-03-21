#include "../ControllerHeader/ListCmd.h"
#include "../../Models/ModelsHeader/DataStructure.h"
#include <fstream>
#include <sstream>
#include <string>
std::string ListCmd::doCommand(std::vector<std::string> params)
{

    std::map<std::string, DNA *>::iterator it;
    std::stringstream resultList;
    if(DataStructure::m_DataStructureIdDna.begin() == DataStructure::m_DataStructureIdDna.end())
    {
            return "not found data in data structure";

    }
    
    for (it = DataStructure::m_DataStructureIdDna.begin(); it != DataStructure::m_DataStructureIdDna.end(); ++it)
    {
    
        resultList << '[' << it->first.substr(1) << "] " // string (key)
                << DataStructure::m_DataStructureIdName[it->first.substr(1)]
                << DataStructure::m_DataStructureIdName[it->first].substr(1) 
                << " : "<< *it->second // string's value
                << std::endl;
    }
    return resultList.str();
    
}
