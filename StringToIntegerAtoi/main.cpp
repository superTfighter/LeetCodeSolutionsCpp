#include "iostream"
#include "string"
#include <vector>
#include <limits.h>

using namespace std;

class StringToIntConverter
{

private:
    string input;

    void removeLeadingWhitespaces()
    {
        int index = 0;

        for (char &c : input)
        {
            int asciiValue = (int)c;

            if (asciiValue == 32)
            {
                input.erase(index, 1);

                removeLeadingWhitespaces();

                break;
            }
            else
            {
                break;
            }

            index++;
        }
    }

    bool positiveOrNegative()
    {
        int asciiValue = (int)input[0];

        if (asciiValue == 43)
        {
            input.erase(0, 1);
            return false;
        }
        else if (asciiValue == 45)
        {
            input.erase(0, 1);
            return true;
        }
        else if (asciiValue <= 57 && asciiValue >= 48)
        {
            return false;
        }
        else
        {
            throw "Non numeric value encountered!";
        }
    }

    double convertToNumericValue()
    {
        bool isNegative = this->positiveOrNegative();

        vector<int> asciiValues;

        for (char &c : input)
        {
            int asciiValue = (int)c;

            if (asciiValue <= 57 && asciiValue >= 48)
            {
                asciiValues.push_back(asciiValue);
            }
            else
            {
                break;
            }
        }

        double result = 0;
        double notation = 1;

        for (int i = asciiValues.size() - 1; i >= 0; i--)
        {          
            
            int valueKey = asciiValues[i];

            int value = getNumericValue(valueKey);

            result = result + (value * notation);

            notation *= 10;
            
        }
        
        if (isNegative)
            result *= -1;

        return result;
    }

    int clampResult(double numeric)
    {
        if (numeric >= double(INT_MAX))
        {
            return INT_MAX;
        }

        if (numeric <= double(INT_MIN))
        {
            return INT_MIN;
        }

        return (int)numeric;
    }

    bool canContinue()
    {

        int leadingCharacter = (int)input[0];

        if ((leadingCharacter == 43 || leadingCharacter == 45 || (leadingCharacter <= 57 && leadingCharacter >= 48)) && input.length() > 0)
        {
            return true;
        }

        return false;
    }

    int getNumericValue(int ascii)
    {
        switch (ascii)
        {
        case 48:
            return 0;
            break;
        case 49:
            return 1;
            break;
        case 50:
            return 2;
            break;
        case 51:
            return 3;
            break;
        case 52:
            return 4;
            break;
        case 53:
            return 5;
            break;
        case 54:
            return 6;
            break;
        case 55:
            return 7;
            break;
        case 56:
            return 8;
            break;
        case 57:
            return 9;
            break;
        default:
            throw "Unknown character encountered!";
            break;
        }
    }

public:
    StringToIntConverter(string input)
    {
        this->input = input;
    }

    int convert()
    {
        this->removeLeadingWhitespaces();

        if (!canContinue())
        {
            return 0;
        }

        return clampResult(this->convertToNumericValue());
    }
};

class Solution
{
public:
    int myAtoi(string s)
    {
        StringToIntConverter converter(s);

        return converter.convert();
    }
};

int main()
{

    string input1 = "0032";
    string input2 = "  -10";
    string input3 = "asdsdasdasd asdasdasd asasdasd";
    string input4 = "words and 987";
    string input5 = "-000000000000000000000000000000000000000000000000001";
    string input6 = "2147483646";

    Solution s;

    int result = s.myAtoi(input6);

    std::cout << std::endl
              << "Result: " << result << std::endl;

    return 0;
}