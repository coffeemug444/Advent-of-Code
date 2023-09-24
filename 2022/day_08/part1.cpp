#include "../../generic_includes.hpp"
#include "../../helper_functions.hpp"


using vec1d = std::vector<unsigned>;
using vec2d = std::vector<vec1d>;


vec2d get_data()
{
   std::vector<std::string> lines = open_lines("data.dat");
   vec2d data;
   for (auto& line : lines)
   {
      data.push_back(vec1d{});
      std::transform(line.begin(), line.end(), 
                     std::back_inserter(data.back()), [](unsigned char c) { return c - '0'; });
   }
   return data;
}

bool tree_is_visible(unsigned y, unsigned x, vec2d trees)
{
   const unsigned ROWS = trees.size();
   const unsigned COLS = trees.at(0).size();

   unsigned tree_height = trees.at(y).at(x);

   auto check_y = [&](unsigned i) { return trees.at(i).at(x) < tree_height; };
   auto check_x = [&](unsigned i) { return trees.at(y).at(i) < tree_height; };

   // check north
   auto north_y_indices = std::views::iota(0u, y);
   if (std::all_of(north_y_indices.begin(), north_y_indices.end(), check_y)) return true;

   // check south
   auto south_y_indices = std::views::iota(y+1, ROWS);
   if (std::all_of(south_y_indices.begin(), south_y_indices.end(), check_y)) return true;

   // check west
   auto west_x_indices = std::views::iota(0u, x);
   if (std::all_of(west_x_indices.begin(), west_x_indices.end(), check_x)) return true;
   
   // check east
   auto east_x_indices = std::views::iota(x+1, COLS);
   if (std::all_of(east_x_indices.begin(), east_x_indices.end(), check_x)) return true;

   return false;
}

int main()
{
   vec2d data = get_data();

   const unsigned ROWS = data.size();
   const unsigned COLS = data.at(0).size();

   unsigned count = 0;
   for (unsigned row = 0; row < ROWS; row++)
   {
      for (unsigned col = 0; col < COLS; col++)
      {
         if (tree_is_visible(row, col, data)) count++;
      }
   }

   std::cout << count << std::endl;
}
