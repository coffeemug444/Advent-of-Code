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

   const unsigned TOTAL_DISK = 70'000'000;
   const unsigned SPACE_NEEDED = 30'000'000;
   const unsigned CURRENTLY_FREE = TOTAL_DISK - dir_sizes.at("/");
   const unsigned NEED_TO_FREE = SPACE_NEEDED - CURRENTLY_FREE;

   // need to find the smallest dir that's bigger than NEED_TO_FREE

   unsigned smallest = dir_sizes.at("/");
   for (auto& [name, size] : dir_sizes)
   {
      if (size < NEED_TO_FREE) continue;
      smallest = std::min(smallest, size);
   }

   std::cout << smallest << std::endl;
}
