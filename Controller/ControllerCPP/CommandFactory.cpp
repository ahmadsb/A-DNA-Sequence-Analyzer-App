#include "../ControllerHeader/CommandFactory.h"
CommandFactory::CommandFactory()
{
    m_commands["new"] = new NewCmd;
    m_commands["load"] = new LoadCmd;
    m_commands["save"] = new SaveCmd;
    m_commands["list"] = new ListCmd;
    m_commands["len"] = new LenCmd;
    m_commands["pair"] = new PairCmd;
}
Command *CommandFactory::create(const std::string &cmd)
{
    if (m_commands.find(cmd) != m_commands.end())
    {
        return m_commands[cmd];
    }
    return NULL;
}
