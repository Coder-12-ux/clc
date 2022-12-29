#include <iostream>
#include "expression.h"

int main(int argc, char **argv)
{   std::string help = "CLC\nDescription: Evaluates arithmetic expressions\n"
                       "Author: Vipul Kumar\n"
                       "commands:\n\thelp: !help\n\texit: !exit";

    if (argc >= 2)
    {
        std::string expression_str;
        for (int i = 1; i < argc; i++)
            expression_str += argv[i];

        if(expression_str == "!help")
        {
            std::cout << help << std::endl;
            return 0;
        }

        if(expression_str == "!exit")
        {
            std::cout << "Bye!!" << std::endl;
            return 0;
        }

        expression e(expression_str);
        e.evaluate();
        std::cout << e.result << std::endl;
    }

    else
    {
        std::string input;
        std::cout << "type !help for help\n";

        while (true)
        {
            std::cout << "expression > ";
            std::getline(std::cin, input);

            // command block
            if (input[0] == '!')
            {
                if (input.substr(1) == "help")
                    std::cout << help << std::endl;

                else if (input.substr(1) == "exit")
                {
                    std::cout << "Bye!!" << std::endl;
                    exit(0);
                }
                continue;
            }

            expression e(input);
            e.evaluate();
            std::cout << e.result << std::endl;
        }
    }

    return 0;
}
