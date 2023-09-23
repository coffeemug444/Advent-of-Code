#include "../../generic_includes.hpp"
#include "../../helper_functions.hpp"



int main()
{
   std::vector<std::string> lines = open_lines("data.dat");

   std::array<unsigned, 3> top_three {};
   unsigned total = 0;
   for (auto& line : lines)
   {
      if (line == "")
      {
         unsigned& worst_elf = *std::min_element(top_three.begin(), top_three.end());
         worst_elf = std::max(worst_elf, total);
         total = 0;
         continue;
      }

      total += std::stoi(line);
   }

   unsigned worst_elf = *std::min_element(top_three.begin(), top_three.end());
   worst_elf = std::max(worst_elf, total);

   total = std::accumulate(top_three.begin(), top_three.end(), 0u);

   std::cout << "The total food carried by the best 3 elfs is: " << total << std::endl; 
}
