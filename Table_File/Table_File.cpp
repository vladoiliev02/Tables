#include "Table_File.h"
#include "Commands.h"

Table_File::Table_File(const std::string& path)
        : path(path)
{
    std::ifstream file(path);
    if (!file.is_open())
        throw std::logic_error(path + " could not be opened.");
    table = new Table(1);
    file >> *table;
    file.close();
}

void Table_File::open(const std::string& path)
{
    if (table)
        throw std::logic_error("A table is already opened, please close it first.\n You can use \"close\"");
    std::ifstream file(path);
    if (!file.is_open())
        throw std::logic_error(path + " could not be opened.");
    this->table = new Table(1);
    this->path = path;
    file >> *table;
    file.close();
    is_saved = true;
}

void Table_File::close(bool askUserToSave)
{
    if (!table_is_open())
        throw std::logic_error("No table opened.\nUse \"new\" or \"open <path>\", to open a file.");
    if (askUserToSave && !is_saved)
        askToSaveFile();
    delete table;
    path.clear();
    table = nullptr;
    is_saved = true;
}

Table_File::~Table_File()
{
    delete table;
    path.clear();
    table = nullptr;
}

void Table_File::save()
{
    if (!table_is_open())
        throw std::logic_error("No table opened.\nUse \"new\" or \"open <path>\", to open a file.");
    if (path.empty())
        throw std::logic_error("File does not exist.\nUse saveas <path> to save it");
    std::ofstream file(path);
    if (!file.is_open())
        throw std::logic_error(path + " could not be opened.\nTable not saved.\nTry again");
    file << *table;
    file.flush();
    file.close();
    is_saved = true;
}

void Table_File::edit()
{
    is_saved = false;
}

void Table_File::save_as(const std::string& path)
{
    if (!table)
        throw std::logic_error("No file opened.\nUse \"new\" or \"open <path>\", to open a file.");
    std::ofstream save_file(path);
    if (!save_file.is_open())
        throw std::logic_error("File could not be opened");
    save_file << *table;
    save_file.flush();
    save_file.close();
    this->path = path;
    is_saved = true;
}

bool Table_File::table_is_open()
{
    return table != nullptr;
}

Table& Table_File::getTable()
{
    if (!table)
        throw std::logic_error("No file opened.\nUse \"new\" or \"open <path>\", to open a file.");
    return *table;
}

void Table_File::askToSaveFile()
{
    bool exit = false;
    while (!exit) {
        std::cerr << "File not saved, do you want to save?\n1. Save\n2. Do not save\n";
        std::cout << "Enter choice: ";
        int choice;
        std::cin >> choice;
        std::cin.ignore();
        switch (choice) {
            case 1: {
                try {
                    if (path.empty()) {
                        std::cout << "File does not exist.\nPlease enter file name or path:\n";
                        char _path[256];
                        std::cin.getline(_path, 256, '\n');
                        Command saveas(std::string("saveas ") + _path);
                        saveas.execute(*this);
                        std::cout << "File saved\n";
                        exit = true;
                    } else {
                        Command command("save");
                        command.execute(*this);
                        std::cout << "File saved\n";
                    }
                } catch (std::logic_error& e) {
                    std::cerr << e.what() << '\n';
                    std::cout << "Do you want to try again?\n1. Yes\n2. No\n";
                    std::cout << "Your choice: ";
                    std::cin >> choice;
                    switch (choice) {
                        case 2: {
                            exit = true;
                            break;
                        }
                        case 1:
                        default: {
                            exit = false;
                            break;
                        }
                    }
                }
                break;
            }
            case 2: {
                exit = true;
                break;
            }
            default:
                exit = false;
        }
    }

}

void Table_File::newFile()
{
    if (table)
        throw std::logic_error("A file is already opened.\nClose it before opening a new one.\n");
    table = new Table(1);
    is_saved = false;
}
