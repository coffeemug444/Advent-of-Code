#include "../../generic_includes.hpp"
#include "../../helper_functions.hpp"



int main()
{
   std::vector<std::string> lines = open_lines("data.dat");

   unsigned max = 0;
   unsigned total = 0;
   for (auto& line : lines)
   {
      if (line == "")
      {
         max = std::max(total, max);
         total = 0;
         continue;
      }

      total += std::stoi(line);
   }

   max = std::max(total, max);

   std::cout << "The most an elf is carrying is: " << max << std::endl; 
}
