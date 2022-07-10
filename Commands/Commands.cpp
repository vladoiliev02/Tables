#include "Commands.h"
#include "Table_File.h"
#include "StringNumber.h"

#include <cstring>
#include <stdexcept>

char Command::toLower(char a)
{
    if ('A' <= a && a <= 'Z')
        return (char) (a - 'A' + 'a');
    return a;
}

CMD_TYPE Command::deduceType()
{
    const short available_commands = 7;
    const char* types[available_commands] =
            {"edit",
             "open",
             "new",
             "close",
             "save",
             "saveas",
             "exit"};
    for (short i = 0; i < available_commands; ++i)
        if (strcmp(cmd.c_str(), types[i]) == 0)
            return (CMD_TYPE) i;
    throw std::invalid_argument("Unknown command");
}

std::string Command::extractArgument(const std::string& cmd, size_t& pos, size_t len, char (* charManipulator)(char))
{
    std::string argument;
    while (pos < len && cmd[pos] == ' ') //This loop skips the spaces
        ++pos;
    if (charManipulator) {
        if (pos < len && cmd[pos] == '"') { // Extract argument with blank spaces.
            pos++;
            while (pos < len && cmd[pos] != '"') {
                argument.push_back(charManipulator(cmd[pos]));
                pos++;
            }
            if (pos == len && cmd[pos-1] != '"')
                throw std::logic_error("\" \" not closed properly.");
        } else if (pos < len && cmd[pos] != '"') {
            while (pos < len && cmd[pos] != ' ') { // Extract argument without blank spaces.
                argument.push_back(charManipulator(cmd[pos]));
                pos++;
            }
        }
    } else {
        if (pos < len && cmd[pos] == '"') { // Extract argument with blank spaces.
            pos++;
            while (pos < len && cmd[pos] != '"') { //
                argument.push_back(cmd[pos]);
                pos++;
            }
            if (pos == len && cmd[pos-1] != '"')
                throw std::logic_error("\" \" not closed properly.");
        } else if (pos < len && cmd[pos] != '"') {
            while (pos < len && cmd[pos] != ' ') { // Extract argument without blank spaces.
                argument.push_back(cmd[pos]);
                pos++;
            }
        }
    }
    if (argument.empty())
        throw std::invalid_argument("Empty argument");
    return argument;
}

Command::Command(const std::string& cmd)
{
    if (cmd.empty())
        throw std::invalid_argument("Invalid command.\nCommand cannot be empty.");
    size_t pos = 0; //Passed as a reference to functions
    size_t len = cmd.length();
    this->cmd = extractArgument(cmd, pos, len, toLower);
    type = deduceType();
    while (pos < len) {
        try {
            arguments.push_back(extractArgument(cmd, pos, len));
        } catch (std::invalid_argument&) {
            //If the function throws the argument is not pushed back;
        }
    }
}

bool Command::execute(Table_File& tFile)
{
    switch (type) {
        case CMD_TYPE::EDIT: {
            edit(tFile.getTable());
            tFile.edit();
            break;
        }
        case CMD_TYPE::OPEN: {
            openTable(tFile);
            break;
        }
        case CMD_TYPE::NEW: {
            newFile(tFile);
            break;
        }
        case CMD_TYPE::CLOSE: {
            closeTable(tFile);
            break;
        }
        case CMD_TYPE::SAVE: // Fallthrough because the function is the same.
        case CMD_TYPE::SAVE_AS: {
            saveTable(tFile);
            break;
        }
        case CMD_TYPE::EXIT : {
            exit(tFile);
            return true;
            break;
        }
        case CMD_TYPE::UNKNOWN: {
            throw std::invalid_argument("Unknown command");
        }
    }
    return false;
}

void Command::edit(Table& table)
{
    if (arguments.size() != 2)
        throw std::invalid_argument("Invalid arguments.\nCorrect use:\nedit <cell> <content>");
    if (StringNumber::isNumber(arguments[1])) {
        if (StringNumber::isDouble(arguments[1])) {
            table.editCell(arguments[0], std::strtod(arguments[1].c_str(), nullptr));
        } else { //the number is int
            table.editCell(arguments[0], std::atoi(arguments[1].c_str()));
        }
    } else { // The argument is a string
        table.editCell(arguments[0], arguments[1]);
    }
}

void Command::openTable(Table_File& file)
{
    if (arguments.size() != 1)
        throw std::invalid_argument("Invalid arguments.\nCorrect use:\nopen <path>");
    file.open(arguments[0]);
}

void Command::closeTable(Table_File& file)
{
    if (!arguments.empty())
        throw std::invalid_argument("Invalid arguments.\nCorrect use:\nclose <No arguments>");
    file.close();
}

void Command::saveTable(Table_File& file)
{
    if (arguments.empty() && type == CMD_TYPE::SAVE)
        file.save();
    else if (arguments.size() == 1 && type == CMD_TYPE::SAVE_AS)
        file.save_as(arguments[0]);
    else
        throw std::invalid_argument("Invalid arguments.\nCorrect use:\nsave <No arguments>\nor\nsaveas <path>");
}

void Command::exit(Table_File& file)
{
    if (!arguments.empty())
        throw std::invalid_argument("Invalid arguments.\nCorrect use:\nexit <No arguments>");
    if (file.table_is_open())
        file.close();
}

void Command::newFile(Table_File& file)
{
    if (!arguments.empty())
        throw std::invalid_argument("Invalid arguments.\nCorrect use:\nnew <No arguments>");
    file.newFile();
}

