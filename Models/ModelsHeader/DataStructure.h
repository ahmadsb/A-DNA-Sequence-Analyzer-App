#ifndef DATA_STRUCTURE_H
#define DATA_STRUCTURE_H

#include <map>
#include "DNA.h"

typedef std::map<std::string, DNA *> DataIdDna;
typedef std::map<std::string, std::string> DataIdName;

class DataStructure
{
public:
  static int index;
  static int defualtIndex;

  static DataIdDna m_DataStructureIdDna;   /*id dna*/
  static DataIdName m_DataStructureIdName; /*id name*/
  static DataIdName m_DataStructureNameId; /*name id*/

  std::string addItem(std::string& arg1, std::string &seqName, DNA *sequence);

private:

  std::string Add(std::string seqName, DNA *sequence);
  void setSeqNameOption(std::string &seqName);
  void setSeqNamePair(std::string &seqId, std::string &seqName);
  bool dataIsExists(std::string seqName);
  std::string getSeqId();
  
};

#endif