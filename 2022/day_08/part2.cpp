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

unsigned scenic_score(unsigned y, unsigned x, vec2d trees)
{
   const unsigned ROWS = trees.size();
   const unsigned COLS = trees.at(0).size();

   unsigned tree_height = trees.at(y).at(x);

   unsigned north = 0;
   unsigned south = 0;
   unsigned east = 0;
   unsigned west = 0;

   for (unsigned i = 1; y >= i; i++)   
   {
      north++;
      if (trees.at(y-i).at(x) >= tree_height) break;
   }
   for (unsigned i = 1; y + i < ROWS; i++) 
   {
      south++;
      if (trees.at(y+i).at(x) >= tree_height) break;
   }
   for (unsigned i = 1; x >= i; i++)
   {
      west++;
      if (trees.at(y).at(x-i) >= tree_height) break;
   }
   for (unsigned i = 1; x + i < COLS; i++) 
   {
      east++;
      if (trees.at(y).at(x+east) >= tree_height) break;
   }

   return north*south*east*west;
}

int main()
{
   vec2d data = get_data();

   const unsigned ROWS = data.size();
   const unsigned COLS = data.at(0).size();

   unsigned best_score = 0;
   for (unsigned row = 0; row < ROWS; row++)
   {
      for (unsigned col = 0; col < COLS; col++)
      {
         unsigned score = scenic_score(row, col, data);
         best_score = std::max(best_score, score);
      }
   }

   std::cout << best_score << std::endl;
}
