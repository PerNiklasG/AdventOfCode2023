#include <iostream>
#include <fstream>
#include <string>

bool checkIfTooMany(std::string s, int n);

int main()
{
    std::ifstream infile("sample.txt");
    std::string line;
    int res;

    if (infile.is_open())
    {
        while (getline(infile, line))   // read each line from file
        {                                                
            std::string::size_type pos = line.find(':'); // Find first ':', i.e. position of where the first "pair" starts
            std::string game = line.substr(0, pos + 1);
            std::cout << "line: " << line << std::endl;

            std::string game_num;
            for(int i = 0; i < game.length(); i++)
            {
                if(isdigit(game[i]))
                {
                    game_num += game[i];
                }
            }
            
            int num = std::stoi(game_num);
            std::cout << "Game num: " << num << std::endl;

            
            
            std::string set = line.substr(pos + 1);
    
            std::cout << "Set is: " << set << std::endl;
            
            for(int i = 0; i < set.length(); i++)
            {
                static std::string number;
                static std::string color;
     
                while (set[i] != ',' || i < set.length())
                {
                    if(isdigit(set[i]))
                    {
                        num += set[i];
                    }
                    else if(isalpha(set[i]))
                    {
                        color += set[i];
                    }
                    i++;
                    //std::cout << "num: " << number << " color: " << color << std::endl;
                }
                std::cout << "num: " << number << " color: " << color << std::endl;
            }

            // for(int i = 0; i < pair.length(); i++)
            // {
            //     if(isdigit(line[i]))
            //     {
            //         std::string number = "";
            //         number = line[i];
            //         current_pair = stoi(number);
            //     }
            // }

            // std::cout << "pair: " << current_pair << " pair: " << pair << std::endl;
            // for (int i = 0; i < pair.length(); i++) // iterate through each char
            // {
            //     if (ispunct(pair[i])) // new pair
            //     {
            //         std::cout << "pair: " << pair << " num: " << num << std::endl;
            //         is_valid = checkIfTooMany(pair, num);
            //         pair = "";
            //     }
            //     else if (isdigit(pair[i])) // Find integer
            //     { 
            //         std::cout << "Num found: " << num << std::endl;
            //         num = static_cast<int>(pair[i]);
            //     }
            //     else if(isalpha(pair[i]))
            //     {
            //         pair += pair[i];
            //     }
            // }

            // if(is_valid)
            // {
            //     res += current_pair;
            // }
        }
    }
}

bool checkIfTooMany(std::string s, int n)
{
    if (s == "red")
    {
        if (n <= 12)
        {
            return true;
        }
    }
    else if (s == "green")
    {
        if (n <= 13)
        {
            return true;
        }
    }
    else if (s == "blue")
    {
        if (n <= 14)
        {
            return true;
        }
    }
    return false;
}