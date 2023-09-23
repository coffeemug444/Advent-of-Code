#include "../../generic_includes.hpp"
#include "../../helper_functions.hpp"



enum Move
{
   ROCK = 1,
   PAPER = 2,
   SCISSORS = 3
};

unsigned get_score(Move opponent_move, Move your_move)
{
   if (your_move == opponent_move) 
   {
      return 3 + static_cast<unsigned>(your_move);
   }

   // you didn't draw ie. sombody won.
   // If your opponent did not win then you did.
   if (opponent_move == ROCK and your_move == SCISSORS) return your_move;
   if (opponent_move == PAPER and your_move == ROCK) return your_move;
   if (opponent_move == SCISSORS and your_move == PAPER) return your_move;

   return 6 + your_move;
}

Move get_opponent_move(char c)
{
   switch (c)
   {
   case 'A': return ROCK;
   case 'B': return PAPER;
   case 'C': return SCISSORS;
   }
   assert(false && "Invalid move");
}

Move get_your_move(Move opponent_move, char c)
{
   switch (c)
   {   
   case 'X': return Move(((opponent_move + 1) % 3) + 1); // lose
   case 'Y': return opponent_move; // draw
   case 'Z': return Move(opponent_move % 3 + 1); // win
   }
   assert(false && "Invalid move");
}


int main()
{
   std::vector<std::string> lines = open_lines("data.dat");
   unsigned total_score = 0;
   for (auto& line : lines)
   {
      Move opponent_move = get_opponent_move(line.at(0));
      Move your_move = get_your_move(opponent_move, line.at(2));
      total_score += get_score(opponent_move, your_move);
   }

   std::cout << total_score << std::endl;
}
