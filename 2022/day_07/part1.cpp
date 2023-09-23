#include "../../generic_includes.hpp"
#include "../../helper_functions.hpp"


bool is_number(std::string_view s)
{
   if (s.empty()) return false;
   return std::all_of(s.begin(), s.end(), [](unsigned char c){ return std::isdigit(c);});
}



int main()
{
   std::vector<std::string> lines = open_lines("data.dat");

   std::map<std::string, unsigned> dir_sizes {{"", 0}};
   std::vector<std::string> current_path {""};

   for (std::string_view line : lines)
   {
      std::vector<std::string> words = split(line, ' ');
      if (words.at(0) == "$" and words.at(1) == "cd")
      {
         if (words.at(2) == "..") current_path.pop_back();
         else current_path.push_back(current_path.back() + words.at(2));
         if (dir_sizes.find(current_path.back()) == dir_sizes.end())
         {
            dir_sizes[current_path.back()] = 0;
         }
      }
      if (is_number(words.at(0)))
      {
         unsigned file_size = std::stoul(words.at(0));
         for (std::string& dir : current_path)
         {
            dir_sizes.at(dir) += file_size;
         }
      }
   }

   unsigned total = 0;
   for (auto& [name, size] : dir_sizes)
   {
      if (size <= 100'000) total += size;
   }

   std::cout << total << std::endl;
}
