#ifndef TEST_FUNCTION_H
#define TEST_FUNCTION_H

#include "../Controller/ControllerHeader/NewCmd.h"
#include "../Controller/ControllerHeader/ListCmd.h"
#include "../Controller/ControllerHeader/LenCmd.h"

#include "../Models/ModelsHeader/DataStructure.h"
#include <iostream>
#include "gtest/gtest.h"

TEST(NewCommandTests, NewCommand)
{
   NewCmd *cmd = new NewCmd;
   std::vector<std::string> vec;
   std::string seqName = "@seq1", dna = "TTTT";
   vec.push_back(dna);
   vec.push_back(seqName);
   cmd->doCommand(vec);
   if (DataStructure::m_DataStructureNameId.find(seqName) == DataStructure::m_DataStructureNameId.end()) //not found
      ASSERT_TRUE(false);
   else
      ASSERT_TRUE(true);  
}

TEST(ListCommandTests, ListCommand)
{
   ListCmd *cmd1 = new ListCmd;

   NewCmd *cmd = new NewCmd;
   std::vector<std::string> vec;
   std::string seqName = "@seq2", dna = "TTTT";
   vec.push_back(dna);
   vec.push_back(seqName);
   cmd->doCommand(vec);

   std::string expected = cmd1->doCommand(vec);
   /*from above new commands provides [1] seq1 : TTTT\n */
   if (expected == "[1] seq1 : TTTT\n[2] seq2 : TTTT\n") 
      ASSERT_TRUE(true);
   else
      ASSERT_TRUE(false);  
}

TEST(LenCommandTests, LenCommand)
{ 
   LenCmd* cmd = new LenCmd;
   std::vector<std::string> vec;
   vec.push_back("1");/*param: id_seq = 1*/
   std::string expected = cmd->doCommand(vec);
   /*from above new commands provides [1] seq1 : TTTT\n */
   if (expected == "4") 
      ASSERT_TRUE(true);
   else
      ASSERT_TRUE(false);  
}

#endif