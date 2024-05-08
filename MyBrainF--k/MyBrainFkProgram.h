#pragma once 
#include <iostream>
#include <conio.h>
#include "InputOutputType.h"
#include "DebugLevel.h"

class MyBrainFkProgram
{
public:
    DebugLevel MyDebugLevel;
    InputOutputType InputType;
    InputOutputType OutputType;

    MyBrainFkProgram(std::string code, DebugLevel debugLevel = DebugLevel::NoDebug, InputOutputType inputType = InputOutputType::Pure, InputOutputType outputType = InputOutputType::Pure, unsigned int dataLength = 30000) :
        MyDebugLevel(debugLevel),
        InputType(inputType),
        OutputType(outputType),
        _code(code),
        _dataLength(dataLength)
    {
        for (int i = 0; i < _dataLength; i++)
        {
            _dataStart[i] = 0;
        }
    }

#pragma region GettersAndSetters
    std::string GetCode();
    void SetCode(std::string newCode);

    char& GetDataCell(unsigned int cellIndex);
    void SetDataCell(unsigned int cellIndex, char newValue);

    unsigned int GetDataLength();
    char* GetDataStart();

    unsigned int GetCodePoint();
    void SetCodePoint(unsigned int newCodePoint);
#pragma endregion
    
    int FindLoopEnd(int loopStartIndex);
    void Loop(int loopStartIndex);

    void Input();
    void Output();

    void NextStep();

    void Run();
private:
    std::string _code;
    unsigned int _dataLength;
    char *_dataStart = new char[_dataLength];
    char *_ptr = _dataStart;
    unsigned int _currentInstructionIndex = 0;
    bool _aaAAAAAAA = false;


    int FindLoopStart(int loopEndIndex);
};

