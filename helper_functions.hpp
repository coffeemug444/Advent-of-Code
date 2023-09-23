#pragma once

#include <string>
#include <vector>
#include <fstream>
#include <cassert>

std::vector<std::string> split(std::string_view input, char c)
{
   std::vector<std::string> result;
   size_t start = 0;
   size_t end = input.find(c);

   while (end != std::string_view::npos) {
      result.push_back(std::string(input.substr(start, end - start)));
      start = end + 1;
      end = input.find(c, start);
   }

   if (start < input.length()) {
      result.push_back(std::string(input.substr(start)));
   }

   return result;
}

std::vector<std::string> split(std::string_view input, std::string_view delim)
{
   std::vector<std::string> result;
   size_t start = 0;
   size_t end = input.find(delim);

   while (end != std::string_view::npos) {
      result.emplace_back(input.substr(start, end - start));
      start = end + delim.length();
      end = input.find(delim, start);
   }

   result.emplace_back(input.substr(start));

   return result;
}

std::vector<std::string> open_lines(std::string_view file_path)
{
   std::vector<std::string> lines;
   std::ifstream input_file(file_path.data());

   assert(input_file.is_open() && "Failed to open the file.");

   std::string line;
   while (std::getline(input_file, line))
   {
      lines.push_back(line);
   }

   return lines;
}
