#include <iostream>
#include <vector>
#include <cstdlib>
#include "ttt_func.hpp"

int main() {
  int plr_input, plr_id;
  char plr_char;
  bool endgame = false;
  std::vector<char> data = create_array();
  
  srand(time(NULL));
  plr_id = rand() % 2;

  while (!endgame) {
    plr_char = player_symbol(plr_id);

    status(data);
    while (true) {
      std::cout << "> Player " << plr_char << ": ";
      std::cin >> plr_input;
      if (plr_input == 26) {
        endgame = true;
        break;
      } else if (plr_input >= 0 && plr_input <= 8) {
        data[plr_input] = plr_char;
        break;
      } else if (data[plr_input] == '_')  {
        std::cout << "Choose another index!\n";
      } else {
        std::cout << "Only accept number 0-8!\n";
      }
    }
    if (win_check(data, plr_char)) {
      std::cout << "Player " << plr_char << " won!\n";
      endgame = true;
    } else if (draw_check(data)) {
      std::cout << "Draw!\n";
      endgame = true;
    }
    plr_id = !plr_id;
  }
} 