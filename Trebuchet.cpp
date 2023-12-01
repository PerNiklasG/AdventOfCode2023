#include <iostream>
#include <fstream>
#include <string>

int findFirstNumber(std::string s);
int findLastNumber(std::string s);
int isNumber(std::string s);

int main()
{
    std::string line;
    std::ifstream file("Trebuchet_input.txt");
    std::string rowDigit;
    int firstNumber = 0;
    int lastNumber = 0;
    int res = 0;

    if(file.is_open())
    {
        while(std::getline(file, line))
        {
            firstNumber = findFirstNumber(line);
            lastNumber = findLastNumber(line);

            // std::cout << "firstNumber is : " << firstNumber << std::endl;
            // std::cout << "lastNumber is : " << lastNumber << std::endl;

            res += stoi(std::to_string(firstNumber) + std::to_string(lastNumber));
        }
        std::cout << "res is : " << res << std::endl;

        file.close();
    }
    else
    {
        std::cout << "Unable to open file" << std::endl;
    }
    
    return 0;
}

int findFirstNumber(std::string s)
{
    std::string stringNumber = "";
    int it = 0;
    while (!isdigit(s[it]))
    {
        stringNumber += s[it];
        it++;
        if(isNumber(stringNumber) > 0)
        {
            // std::cout << "firstStringNumber is : " << isNumber(stringNumber) << std::endl;
            return isNumber(stringNumber);
        }
    }

    stringNumber = s[it];
    return stoi(stringNumber);
}

int findLastNumber(std::string s)
{
    std::string stringNumber;
    int it = s.length() - 1;
    while (!isdigit(s[it]))
    {
        stringNumber.insert(0, 1, s[it]);
        it--;
        if(isNumber(stringNumber) > 0)
        {
            // std::cout << "lastStringNumber is : " << isNumber(stringNumber) << std::endl;
            return isNumber(stringNumber);
        }
    }

    stringNumber = s[it];
    return stoi(stringNumber);
}

int isNumber(std::string s)
{
    std::size_t found = s.find("one");
    if(found != std::string::npos)
    {
        //std::cout << "s is : " << s << std::endl;
        return 1;
    }
    found = s.find("two");
    if(found != std::string::npos)
    {
        //std::cout << "s is : " << s << std::endl;
        return 2;
    }
    found = s.find("three");
    if(found != std::string::npos)
    {
        //std::cout << "s is : " << s << std::endl;
        return 3;
    }
    found = s.find("four");
    if(found != std::string::npos)
    {
        //std::cout << "s is : " << s << std::endl;
        return 4;
    }
    found = s.find("five");
    if(found != std::string::npos)
    {
        //std::cout << "s is : " << s << std::endl;
        return 5;
    }
    found = s.find("six");
    if(found != std::string::npos)
    {
        //std::cout << "s is : " << s << std::endl;
        return 6;
    }
    found = s.find("seven");
    if(found != std::string::npos)
    {
        //std::cout << "s is : " << s << std::endl;
        return 7;
    }
    found = s.find("eight");
    if(found != std::string::npos)
    {
        //std::cout << "s is : " << s << std::endl;
        return 8;
    }
    found = s.find("nine");
    if(found != std::string::npos)
    {
        //std::cout << "s is : " << s << std::endl;
        return 9;
    }
    return 0;
}