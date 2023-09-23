#include "../../generic_includes.hpp"
#include "../../helper_functions.hpp"




unsigned priority(char c)
{
   if ('a' <= c and c <= 'z') return 1 + (c - 'a');
   if ('A' <= c and c <= 'Z') return 27 + (c - 'A');
   assert(false && "Bad char");
}

char common_char(std::string_view first, std::string_view second, std::string_view third)
{
   for (char c : first)
   {
      if (second.find(c) != std::string::npos and third.find(c) != std::string::npos) return c;
   }
   assert(false && "No char appears in all three groups");
}


int main()
{
   std::vector<std::string> lines = open_lines("data.dat");

   assert(lines.size() % 3 == 0 && "Input must be lines in groups of three");

   unsigned total = 0;
   for (size_t i = 0; i < lines.size() / 3; i++)
   {
      total += priority(common_char(lines.at(3*i), lines.at(3*i+1), lines.at(3*i+2)));
   }

   std::cout << total << std::endl;
}
