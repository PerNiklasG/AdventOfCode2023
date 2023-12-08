#include <stdio.h>
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>



struct gear_t
{
    std::vector<int> row;
    std::vector<int> column;
    int value;
    bool is_valid_number;
};

struct input
{
    int row;
    int column;
    bool is_symbol=false;
    std::vector<gear_t> adjacent_gears;
    int num_of_adjacent_gears;
};

using input_t = std::vector<input>;

int part1(input_t& input, const std::vector<gear_t>& numbers, int row_width);

int part2(const input& input);

bool alreadyExists(const input &in, const gear_t &gear);

int processInput(const std::string& file)
{   
    int sum;
    input_t ret;
    std::ifstream input_file(file);
    std::string line;
    int row_width = 0;
    std::vector<gear_t> numbers;
    int i = 0;
    while(std::getline(input_file, line))
    {
        std::string found_number = "";
        input in;
        
        gear_t gear;

        row_width = line.length();

        for (int j = 0; j < line.length(); j++)
        {
            bool is_symbol = false;

            if(line[j] != '.' && !isdigit(line[j]))
            {
                is_symbol = true;
            }
            ret.push_back({j, i, is_symbol});

            if(isdigit(line[j]))
            {
             found_number += line[j];
             gear.row.push_back(j);
             gear.column.push_back(i);
             if(j == line.length() - 1)
             {
                 gear.value = std::stoi(found_number);
                 gear.is_valid_number = true;
                 numbers.push_back(gear);
                 found_number = "";
                 gear.row.clear();
                 gear.column.clear();
             }
            }
            else if(found_number != "")
            {
                // std::cout << "Found number: " << found_number << " Row: ";
                // for (int i = 0; i < gear.row.size(); i++)
                // {
                //     std::cout << gear.row[i];
                // }

                // std::cout << " Column: ";

                // for (int i = 0; i < gear.column.size(); i++)
                // {
                //     std::cout << gear.column[i];
                // }

                // std::cout << std::endl;
                
                gear.value = std::stoi(found_number);
                gear.is_valid_number = true;
                numbers.push_back(gear);
                found_number = "";
                gear.row.clear();
                gear.column.clear();
            }
        }
        i++;
    }

    sum = part1(ret, numbers, row_width);
    int sum2 = 0;
    for(auto& i : ret)
    {
        if(i.is_symbol && i.adjacent_gears.size() == 2)
        {
            sum2 += part2(i);
        }
    }
    std::cout << "Sum2: " << sum2 << std::endl;
    return sum;
}

int part1(input_t& input, const std::vector<gear_t>& numbers, int row_width)
{
    int sum = 0;
    
    std::cout << "Row width: " << row_width << std::endl;
    for (auto &i : numbers)
    {
        // std::cout << "Value: " << i.value << std::endl;

        std::cout << "Value: " << i.value << " Row: ";
        for (int k = 0; k < i.row.size(); k++)
        {
            std::cout << i.row[k];
        }

        std::cout << " Column: ";

        for (int k = 0; k < i.column.size(); k++)
        {
            std::cout << i.column[k];
        }

        std::cout << std::endl;

        bool is_valid = false;
        for(int j = 0; j < i.row.size(); j++)
        {
            int temp = (i.column[j]) * row_width;
            int cords = temp + i.row[j];
            // std::cout << "Coords: " << cords << " temp: " << temp << " j: " << j << " row: " << i.row[j] << " column: " << i.column[j] << std::endl;
            // std::cout << "Input : " << input[cords].row << " " << input[cords].column << std::endl;
            if (input[cords - row_width + 1].is_symbol == true)
            {
                std::cout << "2Found symbol: " << input[cords - row_width + 1].row << " " << input[cords - row_width + 1].column << std::endl;
                if(!alreadyExists(input[cords - row_width + 1], i))
                {
                    input[cords - row_width + 1].adjacent_gears.push_back(i);
                }
                is_valid = true;
            }
            else if (input[cords - row_width].is_symbol == true)
            {
                std::cout << "2Found symbol: " << input[cords - row_width].row << " " << input[cords - row_width].column << std::endl;
                if(!alreadyExists(input[cords - row_width], i))
                {
                    input[cords - row_width].adjacent_gears.push_back(i);
                }
                is_valid = true;
            }
            else if (input[cords - row_width - 1].is_symbol == true)
            {
                std::cout << "3Found symbol: " << input[cords - row_width - 1].row << " " << input[cords - row_width - 1].column << std::endl;
                if(!alreadyExists(input[cords - row_width - 1], i))
                {
                    input[cords - row_width - 1].adjacent_gears.push_back(i);
                }
                is_valid = true;
            }
            else if (input[cords - 1].is_symbol == true)
            {
                std::cout << "4Found symbol: " << input[cords - 1].row << " " << input[cords - 1].column << std::endl;
                if(!alreadyExists(input[cords - 1], i))
                {
                    input[cords - 1].adjacent_gears.push_back(i);
                }
                is_valid = true;
            }
            else if (input[cords + 1].is_symbol == true)
            {
                std::cout << "5Found symbol: " << input[cords + 1].row << " " << input[cords + 1].column << std::endl;
                if(!alreadyExists(input[cords + 1], i))
                {
                    input[cords + 1].adjacent_gears.push_back(i);
                }
                is_valid = true;
            }
            else if (input[cords + row_width - 1].is_symbol == true)
            {
                std::cout << "6Found symbol: " << input[cords + row_width - 1].row << " " << input[cords + row_width - 1].column << std::endl;
                if(!alreadyExists(input[cords + row_width - 1], i))
                {
                    input[cords + row_width - 1].adjacent_gears.push_back(i);
                }
                is_valid = true;
            }
            else if (input[cords + row_width].is_symbol == true)
            {
                std::cout << "7Found symbol: " << input[cords + row_width].row << " " << input[cords + row_width].column << std::endl;
                if(!alreadyExists(input[cords + row_width], i))
                {
                    input[cords + row_width].adjacent_gears.push_back(i);
                }
                is_valid = true;
            }
            else if (input[cords + row_width + 1].is_symbol == true)
            {
                std::cout << "8Found symbol: " << input[cords + row_width + 1].row << " " << input[cords + row_width + 1].column << std::endl;
                if(!alreadyExists(input[cords + row_width + 1], i))
                {
                    input[cords + row_width + 1].adjacent_gears.push_back(i);
                }
                is_valid = true;
            }
        }
        if(is_valid) {
            std::cout << "Found valid number: " << i.value << std::endl;
            sum += i.value;
        }
    }
    return sum;
}

int part2(const input& in)
{
    int sum = 1;
    for(auto& i : in.adjacent_gears)
    {
        sum *= i.value;
    }
    return sum;
}

bool alreadyExists(const input& in, const gear_t& gear)
{
    for(auto& i : in.adjacent_gears)
    {
        if(i.row == gear.row && i.column == gear.column && i.value == gear.value)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    //int test_values = processInput("sample.txt");
    int actual_values = processInput("gearratios_input.txt");

    //std::cout << "part1: " << test_values << std::endl;
    std::cout << "part1: " << actual_values << std::endl;

    //std::cout << "part2: " << part2(input_t) << std::endl;
}