#include <vector>

std::vector<char> create_array();
char player_symbol(int player_id);
void status(std::vector<char> data);
bool win_check(std::vector<char> data, char player_char);
bool draw_check(std::vector<char> data);