#include "../../generic_includes.hpp"
#include "../../helper_functions.hpp"



std::pair<unsigned, unsigned> string_to_range(std::string_view input)
{
   std::vector<std::string> range = split(input, '-');
   return {std::stoul(range.at(0)), std::stoul(range.at(1))};
}

bool val_in_range(unsigned val, unsigned start, unsigned end)
{
   return val >= start and val <= end;
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
      if (val_in_range(start_1, start_2, end_2) or val_in_range(end_1, start_2, end_2) or
          val_in_range(start_2, start_1, end_1) or val_in_range(end_2, start_1, end_1))
      {
         total++;
      }
   }


   std::cout << total << std::endl;
}
