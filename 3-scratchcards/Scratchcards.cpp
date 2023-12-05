
#include <vector>
#include <iostream>
#include <fstream>
#include <string>

struct game_t{
    int id;
    std::vector<int> winning;
    std::vector<int> numbers;
    int winning_numbers;
};

using games_t = std::vector<game_t>;

games_t load_input(const std::string& file) {
    games_t ret;
    std::ifstream input(file);
    std::string line;
    int res = 0;
    while(std::getline(input,line)) {
        game_t game;
        sscanf_s(line.c_str(), "Card %d", &game.id);
        
        std::string set = line.substr(line.find(":") + 1);
        bool passed = false;
        for (int i = 0; i <= set.length(); i++)
        {
            static std::string s = "";
            if(i == set.length() && s != "")
            {
                game.numbers.push_back(std::stoi(s));
                s = "";
            }
            else if(isdigit(set[i]))
            {
                s += set[i];
            }
            else if (set[i] == '|')
            {
                passed = true;
            }
            else if (!isdigit(set[i]) && s != "")
            {
                if(passed)
                {
                    game.numbers.push_back(std::stoi(s));
                    s = "";
                }
                else
                {
                    game.winning.push_back(std::stoi(s));
                    s = "";
                }
            }   
            else
            {
               // std::cout << "error, set[i] = " << set[i] << std::endl;
            }
        }
        int round = 0;
        for (auto& i : game.numbers)
        {
            //std::cout << "i: " << i << std::endl;
            for (auto& j : game.winning)
            {
                if (i == j)
                {
                    //std::cout << "i: " << i << " j: " << j << std::endl;
                    round++;
                }
            }

        }
        game.winning_numbers = round;
        res += round;

        ret.push_back(game);
    }
    std::cout << "res: " <<  res << std::endl;
    return ret;
}

int part1(const games_t& games)
{
    int sum = 0;
    for(auto& game : games){
        int temp = 0;
        for(int i = 0; i < game.winning_numbers; i++)
        {
            if(i == 0)
            {
                temp++;
            }
            else 
            {
                temp *= 2;
            }
        }
        sum += temp;
    }
    return sum;
}

int main()
{
    auto test_values = load_input("scratchcards_input.txt");

    std::cout << "part1: " << part1(test_values) << std::endl;

    return 0;
}