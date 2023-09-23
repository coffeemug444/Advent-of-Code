#include "../../generic_includes.hpp"
#include "../../helper_functions.hpp"


const unsigned MARKER_LEN = 4;


bool is_marker(unsigned pos, std::string_view message)
{
   std::set<char> chars;
   for (unsigned i = 0; i < MARKER_LEN; i++) chars.insert(message.at(pos - i));
   return chars.size() == MARKER_LEN;
}

int main()
{
   std::string message = open_lines("data.dat").front();

   unsigned pos = MARKER_LEN;
   while (not is_marker(pos, message))
   {
      pos++;
      assert(pos < message.size() && "No marker found");
   }

   std::cout << pos + 1 << std::endl;
}
