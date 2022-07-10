#pragma once

#include <string>
#include <vector>
#include <Table_File.h>

#include "Table.h"

// Enum class with all available commands.

enum class CMD_TYPE {
    UNKNOWN = -1,
    EDIT,
    OPEN,
    NEW,
    CLOSE,
    SAVE,
    SAVE_AS,
    EXIT
};

// This class handles command execution

class Command {
    std::string cmd;                    // Actual command.
    std::vector<std::string> arguments; // The arguments for the command.
    CMD_TYPE type;                      // Type of the command.

private:
    // If the char is an uppercase letter,
    // it is transformed to lowercase.
    // only used for the command (cmd);
    static char toLower(char a);

    // Returns the command type.
    // If type is unknown throws an exception.
    CMD_TYPE deduceType();

    // Separates the passed string into
    // command and arguments.
    // The charManipulation() pointer is used
    // only to turn the command all to lowercase,
    // so that it can be properly validated.
    static std::string extractArgument(const std::string& cmd, size_t& pos, size_t len, char (*charManipulator)(char a) = nullptr);

    // Available commands
    void newFile(Table_File& file);
    void openTable(Table_File& file);
    void closeTable(Table_File& file);
    void saveTable(Table_File& file);
    void exit(Table_File& file);

public:
    explicit Command(const std::string& cmd);

    // Executes the command.
    // Returns true if the command is "exit",
    // otherwise the program continues.
    bool execute(Table_File& tFile);

    // Edit can be used without a file loaded,
    // so it is kept public.
    void edit(Table& table);

};