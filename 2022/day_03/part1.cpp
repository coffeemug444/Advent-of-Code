#include "../../generic_includes.hpp"
#include "../../helper_functions.hpp"




unsigned priority(char c)
{
   if ('a' <= c and c <= 'z') return 1 + (c - 'a');
   if ('A' <= c and c <= 'Z') return 27 + (c - 'A');
   assert(false && "Bad char");
}

char common_char(std::string_view left, std::string_view right)
{
   for (char c : left)
   {
      if (right.find(c) != std::string::npos) return c;
   }
   assert(false && "No char in left appears in right");
}


int main()
{
   std::vector<std::string> lines = open_lines("data.dat");


   unsigned total = 0;
   for (auto& line : lines)
   {
      size_t line_len = line.size();
      total += priority(common_char(line.substr(0, line_len / 2), line.substr(line_len/2)));
   }

   std::cout << total << std::endl;
}
