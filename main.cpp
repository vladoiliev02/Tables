#include <iostream>

#include "Table_File.h"
#include "Commands.h"

int main()
{
    Table_File tFile;
    bool exit;
    std::cout << "Use command \"new\", or \"open\", to begin your work! :)\n";

    while (true) {
        std::cout << "-----------------------\nEnter command: ";
        char cmd[150];
        std::cin.getline(cmd, 150, '\n');
        std::cout << "-----------------------\n";

        try {
            Command command(cmd);
            exit = command.execute(tFile);
            std::cout << "Command executed successfully\n";
            std::cout << "-----------------------\n";
            if (exit)
                break;
            if (tFile.table_is_open())
                tFile.getTable().print();
        } catch (std::invalid_argument& e) {
            std::cerr << e.what() << '\n';
        } catch (std::logic_error& e) {
            std::cerr << e.what() << '\n';
        } catch (std::bad_alloc& e) {
            std::cerr << e.what() << '\n';
            return 1;
        }
    }
    return 0;
}