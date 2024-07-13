#include <iostream>
#include <vector>

// In ra debug
bool print_debug = false;
void debug(std::string text) {
  if (print_debug) {
    std::cout << text;
  }
}

// Tạo mảng chứa dữ liệu chơi
std::vector<char> create_array() {
  std::vector<char> data;
  int size = 3 * 3;
  // Thêm kí tự trống vào mảng
  for (int i = 0; i < size; i++) {
    data.push_back('_');
  }
  return data;
}

// In ra tiến trình trò chơi
void status(std::vector<char> data) {
  int index = 0;
  for (int j = 0; j < 3; j++) {
    for (int k = 0; k < 3; k++) {
      std::cout << data[k + index] << "    ";
    }
    index += 3;
    std::cout << "\n\n";
  }
}

// Xác định ký tự từ id người chơi
char player_symbol(int player_id) {
  if (player_id == 0) {
    return 'O';
  } else {
    return 'X';
  }
}

// Kiểm tra từng hàng và trả về kết quả kiểm tra
bool rows_check(std::vector<char> data, std::string win_row) {
  std::string row;
  for (int i = 0; i < 7 ; i += 3) {
    debug(std::to_string(i) + ") Row Check: ");
    for (int j = 0; j < 3; j++) {
      row += data[i + j];
      debug(std::to_string(i + j) + "(" + data[i + j] + ")" + " ");
    }
    if (row == win_row) {
      return true;
    }
    debug("\n");
  }
  return false;
}

// Kiểm tra từng cột và trả về kết quả kiểm tra
bool columns_check(std::vector<char> data, std::string win_row) {
  std::string column;
  for (int i = 0; i < 3; i++) {
    debug(std::to_string(i) + ") Column Check: ");
    for (int j = i; j < data.size(); j += 3) {
      column += data[j];
      debug(std::to_string(j) + "(" + data[j] + ")" + " ");
    }
    if (column == win_row) {
      return true;
    }
    debug("\n");
  }
  return false;
}

// Kiểm tra hai đường chéo và trả kết quả kiểm tra
bool cross_check(std::vector<char> data, std::string win_row) {
  std::string cross;
  debug("Cross Right-Left Check: ");
  for (int i = 0; i < 9; i += 4) {
    cross += data[i];
    debug(std::to_string(i) + "(" + data[i] + ")" + " ");
  }
  debug("\n");

  if (cross == win_row) {
    return true;
  }

  debug("Cross Left-Right Check: ");
  cross = "";
  for (int j = 2; j < 7; j += 2) {
    cross += data[j];
    debug(std::to_string(j) + "(" + data[j] + ")" + " ");
  }
  debug("\n");
  return cross == win_row;
}

// Kiểm tra người chơi nào dành chiến thắng
bool win_check(std::vector<char> data, char player_char) {
  std::string win_row(3, player_char);
  bool row_c =  rows_check(data, win_row);
  bool col_c = columns_check(data, win_row);
  bool cro_c = cross_check(data, win_row);
  return row_c || col_c || cro_c;
}

// Kiểm tra hòa nhau
bool draw_check(std::vector<char> data) {
  for (int i = 0; i < data.size(); i++) {
    if (data[i] == '_') {
      return false;
    };
  }
  return true;
}