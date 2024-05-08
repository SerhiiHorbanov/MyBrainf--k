#include <iostream>
#include <fstream>
#include <conio.h>
#include "MyBrainFkProgram.h"
#include "InputOutputType.h"
#include "DebugLevel.h"


int main()
{
    std::cout << "Hello World!" << std::endl;
    std::cout << "would you like to enter file's name and then run code in it, or run code entered in console? (f for file, c for code in console)" << std::endl;


    std::ifstream stream = std::ifstream("Config\\DebugLevel.txt");
    DebugLevel debugLevel = (DebugLevel)(stream.get() - '0');
    stream = std::ifstream("Config\\InputType.txt");
    InputOutputType inputType = (InputOutputType)(stream.get() - '0');
    stream = std::ifstream("Config\\OutputType.txt");
    InputOutputType outputType = (InputOutputType)(stream.get() - '0');


    std::string code = "";

    char in = _getch();
    if (in == 'f' || in == 'F')
    {
        std::cout << "enter file name: ";
        std::string fileName = "";
        std::cin >> fileName;
        std::ifstream stream = std::ifstream(fileName);

        while (stream)
        {
            code += stream.get();
        }
    }
    else
    {
        std::cout << "enter your code: ";
        std::cin >> code;
    }

    MyBrainFkProgram program = MyBrainFkProgram(code, debugLevel, inputType, outputType);
    program.Run();


}

// ++++++++++
// .+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.+.
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++.
//>>+++++[<+++++>-][<+++++>-].
//