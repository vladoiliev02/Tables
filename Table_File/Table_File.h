#include <fstream>
#include "Table.h"

#pragma once

// This class opens and closes the files and loads
// the tables in the memory.

class Table_File {
    bool is_saved = true;     // Keeps track if the file has been edited
    Table* table = nullptr;   // Currently loaded table
    std::string path;         // Path to the file

private:
    // If a file is closed before being saved,
    // ask the user if he wants to save the file.
    void askToSaveFile();

public:
    Table_File() = default;
    Table_File(const std::string& path);
    Table_File(const Table_File&) = delete;
    Table_File(Table_File&&) = delete;
    Table_File& operator=(const Table_File&) = delete;
    Table_File& operator=(Table_File&&) = delete;
    ~Table_File();

    // The different available actions.
    void open(const std::string& path);
    void newFile();

    // The boolean askUserToSave in close() is used to know,
    // if the user wants to be warned, when they are
    // closing an unsaved file.
    void close(bool askUserToSave = true);
    void save();
    void save_as(const std::string& path);
    void edit();

    // Checks if a table is currently loaded
    bool table_is_open();

    // Returns the table,
    // so that it can be edited;
    Table& getTable();
};