#include <string>

void replace_text(std::string &text, int start, int end) {
  for (int i = start; i < end; i++) {
    text[i] = '*';
  }
}

void bleep(std::string word, std::string &text) {
  int loop_time = text.size() - (word.size() - 1);
  for (int i = 0; i <= loop_time; i++) {
    int checkpoint = 0;
    for (int j = i; j < i + word.size(); j++) {
      if (text[j] == word[j - i]) {
        checkpoint++;
        if (checkpoint == word.size()) {
          replace_text(text, i, i + word.size());
        }
      }
    }
  }
}