#include "MyBrainFkProgram.h"
#include <string>
#include <iostream>


#pragma region GettersAndSetters
std::string MyBrainFkProgram::GetCode()
{
    return _code;
}

void MyBrainFkProgram::SetCode(std::string newCode)
{
    _code = newCode;
}

char& MyBrainFkProgram::GetDataCell(unsigned int cellIndex)
{
    return *(_dataStart + cellIndex * sizeof(char));
}

void MyBrainFkProgram::SetDataCell(unsigned int cellIndex, char newValue)
{
    *(_dataStart + cellIndex * sizeof(char)) = newValue;
}

unsigned int MyBrainFkProgram::GetDataLength()
{
    return _dataLength;
}

char* MyBrainFkProgram::GetDataStart()
{
    return _dataStart;
}

unsigned int MyBrainFkProgram::GetCodePoint()
{
    return _currentInstructionIndex;
}

void MyBrainFkProgram::SetCodePoint(unsigned int newCodePoint)
{
    _currentInstructionIndex = newCodePoint;
}
#pragma endregion


int MyBrainFkProgram::FindLoopEnd(int loopStartIndex)
{
    unsigned int nestedLoopsDepth = 0;
    bool foundLoopEnd = false;
    for (int i = loopStartIndex + 1; !foundLoopEnd; i++)
    {
        switch (_code[i])
        {
        case '[':
            nestedLoopsDepth++;
            break;
        case ']':
            if (nestedLoopsDepth == 0)
                return i;

            nestedLoopsDepth--;
            break;
        }
    }
}

void MyBrainFkProgram::Loop(int loopStartIndex)
{
    if (*_ptr == 0)
    {
        _currentInstructionIndex = FindLoopEnd(loopStartIndex);
        return;
    }

    unsigned int nestedLoopsDepth = 0;
    _currentInstructionIndex++;

    while (true)
    {
        if (_code[_currentInstructionIndex] == '[')
            nestedLoopsDepth++;

        if (_code[_currentInstructionIndex] == ']')
        {
            if (nestedLoopsDepth == 0)
            {
                _currentInstructionIndex = loopStartIndex - 1;
                return;
            }

            nestedLoopsDepth--;
        }

        NextStep();
    }
}

void MyBrainFkProgram::Input()
{
    switch (InputType)
    {
    case InputOutputType::Pure:
        *_ptr = _getch();
        break;

    case InputOutputType::Hexadecimal:
    {
        std::string inputHex;
        std::cin >> inputHex;

        *_ptr = std::stoi(inputHex, 0, 16);
    }
        break;

    case InputOutputType::Decimal:
    {
        std::string inputDecimal;
        std::cin >> inputDecimal;

        *_ptr = std::stoi(inputDecimal);
    }
        break;

    case InputOutputType::Binary:
    {
        std::string inputBinary;
        std::cin >> inputBinary;

        *_ptr = std::stoi(inputBinary, 0, 2);
    }
        break;
    }
}

void MyBrainFkProgram::Output()
{
    switch (InputType)
    {
    case InputOutputType::Pure:
        std::cout << *_ptr;
        break;

    case InputOutputType::Hexadecimal:
    {
        /*std::string out;
        std::sprintf(out, "%X", *_ptr);*/
    }
    break;

    case InputOutputType::Decimal:
    {
    }
    break;

    case InputOutputType::Binary:
    {
    }
    break;
    }
}

void MyBrainFkProgram::NextStep()
{
    //std::cout << (int)_dataStart[0] << " ";
    //std::cout << (int)_dataStart[1] << std::endl;
    //std::cout << _code[_currentInstructionIndex] << std::endl;
    switch (_code[_currentInstructionIndex])
    {
    case '>':
        _ptr++;
        break;
    case '<':
        _ptr--;
        break;
    case '+':
        (*_ptr)++;
        break;
    case '-':
        (*_ptr)--;
        break;
    case '.':
        std::cout << *_ptr;
        break;
    case ',':
        Input();
        break;
    case '[':
        Loop(_currentInstructionIndex);
        break;
    //case ']':
    //    if (*_ptr == 0)
    //        Loop(_currentInstructionIndex);
    //    break;
    }
    _currentInstructionIndex++;
}

void MyBrainFkProgram::Run()
{
    while (_currentInstructionIndex < _code.length())
    {
        NextStep();
    }
}
