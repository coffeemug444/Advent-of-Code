#include "../../generic_includes.hpp"
#include "../../helper_functions.hpp"

const unsigned NUMBER_OF_COLS = 9;


std::array<std::vector<char>, NUMBER_OF_COLS> parse_initial(const std::vector<std::string>& initial)
{
   std::array<std::vector<char>, NUMBER_OF_COLS> box_stacks {};
   for (auto& row : initial)
   {
      for (size_t col = 0; col < NUMBER_OF_COLS; col++)
      {
         char c = row.at(1 + 4*col);
         if (c == ' ') continue;
         box_stacks.at(col).insert(box_stacks.at(col).begin(), c);
      }
   }

   return box_stacks;
}

std::tuple<unsigned, unsigned, unsigned> parse_command(std::string_view command)
{
   auto words = split(command, ' ');
   unsigned count = std::stoul(words.at(1));

   // subtract 1 from these as we're using 0 indexing not 1
   unsigned from = std::stoul(words.at(3)) - 1;
   unsigned to = std::stoul(words.at(5)) - 1;
   return {count, from, to};
}


int main()
{
   std::vector<std::string> lines = open_lines("data.dat");

   // end of the starting stack in the input data
   auto end_of_initial = std::find(lines.begin(), lines.end(), "");
   std::vector<std::string> initial;
   std::copy(lines.begin(), end_of_initial, std::back_inserter(initial));
   lines.erase(lines.begin(), ++end_of_initial);
   initial.pop_back(); // this is just numbering the columms, not needed

   std::array<std::vector<char>, NUMBER_OF_COLS> box_stacks = parse_initial(initial);

   for (std::string_view command : lines)
   {
      auto [count, from, to] = parse_command(command);
      for (unsigned i = 0; i < count; i++)
      {
         box_stacks.at(to).push_back(box_stacks.at(from).back());
         box_stacks.at(from).pop_back();
      }
   }

   for (auto& box_stack : box_stacks) std::cout << box_stack.back();
   std::cout << std::endl;
}