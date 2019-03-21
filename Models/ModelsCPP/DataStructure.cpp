#include "../ModelsHeader/DataStructure.h"
#include <iostream>
#include <sstream>

int DataStructure::index = 1;
DataIdDna DataStructure::m_DataStructureIdDna;

DataIdName DataStructure::m_DataStructureIdName;
DataIdName DataStructure::m_DataStructureNameId;

int DataStructure::defualtIndex = 1;

std::string DataStructure::addItem(std::string &arg1, std::string &arg2, DNA *sequence)
{
    std::string sequenceId = arg1;
    std::string sequenceName = arg2;
    setSeqNameOption(sequenceName); /*if [@sequanceName] isn't  used*/
    setSeqNamePair(sequenceId, sequenceName);

    if (dataIsExists(sequenceName)) //not found
    {
        return "already exists";
    }
    else
    {
        return Add(sequenceName, sequence);
    }
}

/*private function*/
void DataStructure::setSeqNamePair(std::string &seqId, std::string &seqName)
{
    if (2 == seqName.length() && '@' == seqName[0] && '@' == seqName[1])
    {
        seqName = m_DataStructureIdName[seqId];
        int count = 1;

        while (dataIsExists(seqName))
        {
            std::stringstream countStr;
            countStr.str("");
            countStr << count;
            seqName = seqName + "_p" + countStr.str();
            ++count;

            seqName = seqName.substr(0, seqName.size() - 1);
            seqName += countStr.str();
        }
    }
}
std::string DataStructure::getSeqId()
{
    std::stringstream indexStr;
    indexStr << "#" << index;
    return indexStr.str();
}
std::string DataStructure::Add(std::string sequenceName, DNA *sequence)
{
    std::string seqId = getSeqId();
    m_DataStructureIdDna[seqId] = sequence;
    m_DataStructureIdName[seqId] = sequenceName;
    m_DataStructureNameId[sequenceName] = seqId;

    std::stringstream indexStr;
    indexStr.str("");
    indexStr << "[" << index << "] " << sequenceName << ": " << *sequence;
    ++index;
    return indexStr.str();
}

void DataStructure::setSeqNameOption(std::string &sequenceName)
{

    if (sequenceName.empty())
    {
        std::stringstream indexStr;
        indexStr << defualtIndex;
        ++defualtIndex;
        sequenceName = "@seq" + indexStr.str();
    }
}

bool DataStructure::dataIsExists(std::string sequenceName)
{
    return !(m_DataStructureNameId.find(sequenceName) == m_DataStructureNameId.end());
}