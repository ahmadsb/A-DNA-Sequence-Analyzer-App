#include "../ControllerHeader/LenCmd.h"
#include "../../Models/ModelsHeader/DataStructure.h"
#include <sstream>
#include <string>
std::string LenCmd::doCommand(std::vector<std::string> params)
{
    if (1 == params.size())
    {
        if (DataStructure().m_DataStructureIdDna.find("#"+params[0]) != DataStructure().m_DataStructureIdDna.end()) //found
        {
            std::stringstream out;
            out << DataStructure().m_DataStructureIdDna["#"+params[0]]->size();
            return out.str();
        }
        return "seq_id not exists";
    }

    return "Usage: len <id_sequence>";
}