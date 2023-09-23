#include "../../generic_includes.hpp"
#include "../../helper_functions.hpp"



std::pair<unsigned, unsigned> string_to_range(std::string_view input)
{
   std::vector<std::string> range = split(input, '-');
   return {std::stoul(range.at(0)), std::stoul(range.at(1))};
}


int main()
{
   std::vector<std::string> lines = open_lines("data.dat");

   unsigned total = 0;
   for (auto& line : lines)
   {
      std::vector<std::string> pair = split(line, ',');
      auto [start_1, end_1] = string_to_range(pair.at(0));
      auto [start_2, end_2] = string_to_range(pair.at(1));
      if ((start_1 <= start_2 and end_1 >= end_2) or 
          (start_1 >= start_2 and end_1 <= end_2))
      {
         total++;
      } 
   }


   std::cout << total << std::endl;
}
