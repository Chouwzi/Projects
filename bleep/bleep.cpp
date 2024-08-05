#include <iostream>
#include <string>
#include "bleep_funcs.hpp"

int main() {
  std::string word = "broccoli";
  std::string text = " broccoli.";
  bleep(word, text);
  std::cout << text;
}