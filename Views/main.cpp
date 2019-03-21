#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <sstream>
#include "../Controller/ControllerHeader/CommandFactory.h"
// sudo apt-get install libboost -all-dev

std::vector<std::string> parsing(std::string s)
{
    std::string buf; // Have a buffer string
    char str[s.length() + 1];
    strcpy(str, s.c_str());
    std::stringstream ss(str);
    std::vector<std::string> tokens;
    while (getline(ss, buf, ' '))
        tokens.push_back(buf);
    return tokens;
}
inline std::string commandsCli()
{
    char *command = NULL;
    std::string input;
    std::getline(std::cin, input, '\n');
    return input;
}

void prompt()
{
    std::cout << "> cmd >>> ";
}
void messageCommandNotFound(std::string msg)
{
    std::cout << msg << ": command not found" << std::endl;
}
void messageToPrint(std::string msg)
{
    std::vector<std::string> vecRes = parsing(msg);
    int i = 0, j = 0;
    std::stringstream out;
    for (i = 0; i < vecRes.size(); ++i)
    {
        if (vecRes[i].length() >= 40)
        {
            for (j = 0; j < 10; ++j)
                out << vecRes[i][j];

            out << "...";
            for (j = 1; j <= 3; ++j)
                out << vecRes[i][vecRes[i].length() - j];
        }
        else
        {
            out << vecRes[i] << " ";
        }
    }
    std::cout << out.str() << std::endl;
}
bool executeCmd(std::vector<std::string> vecCmd)
{
    std::vector<std::string> params;
    int index = 1;
    for (index = 1; index < vecCmd.size(); ++index)
        params.push_back(vecCmd.at(index));

    CommandFactory cmdFactory;
    Command *command = cmdFactory.create(vecCmd.at(0));

    if (command)
    {
        std::string resultCmd = command->doCommand(params);
        messageToPrint(resultCmd);
        return true;
    }
    return false;
}

int main()
{
    std::vector<std::string> vecCmd;
    std::string cmd;
    while (true)
    {
        prompt();
        cmd = commandsCli();
        vecCmd = parsing(cmd);

        if (0 == vecCmd.size() || vecCmd.at(0).empty()) /*input : ok or space*/
        {
            continue;
        }

        if ("quit" == vecCmd.at(0))
        {
            break;
        }
        else
        {
            if (true == executeCmd(vecCmd))
            {
                continue;
            }
            else
            {
                messageCommandNotFound(vecCmd.at(0));
            }
        }
    }

    return 0;
}
