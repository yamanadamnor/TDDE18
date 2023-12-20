#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

void printError(const string &message) { cerr << message << endl; }

unsigned int getLargestWidth(const vector<string> &text) {
  unsigned int largest_width{0};
  for_each(text.begin(), text.end(), [&largest_width](const auto &word) {
    word.size() > largest_width ? largest_width = word.size() : largest_width;
  });
  return largest_width;
}

map<string, int> getWordFrequencyMap(vector<string> &text) {
  map<string, int> word_frequency;

  // Fill the map with every unique occurance of eache word in text vector
  for_each(text.begin(), text.end(), [&word_frequency](const auto &word) {
    auto already_present{word_frequency.count(word)};

    // Add word if not present in word_frequency otherwise increment the value
    // of the key == word
    already_present == 0 ? word_frequency[word] = 1 : word_frequency[word]++;
  });
  return word_frequency;
}

// Prints every element in text vector with space as delimiter
void print(const vector<string> &text) {
  for_each(text.begin(), text.end(),
           [](const string &word) { cout << word << " "; });
  cout << endl;
}

// Prints every element in word_frequency map of type <string, int>
void print(const vector<string> &text, const map<string, int> &word_frequency,
           bool left_alignment = true) {
  unsigned int width{getLargestWidth(text)};
  const auto alignment{left_alignment ? left : right};
  for_each(word_frequency.begin(), word_frequency.end(),
           [&width, &alignment](const auto word) {
             cout << alignment << setw(width);
             cout << word.first << " ";
             cout << word.second;
             cout << endl;
           });
}

// Prints every element in word_frequency vector containing elements of type
// pair<string, int>
void print(const vector<string> &text,
           const vector<pair<string, int>> &word_frequency,
           bool left_alignment = true) {
  unsigned int width{getLargestWidth(text)};
  const auto alignment{left_alignment ? left : right};
  for_each(word_frequency.begin(), word_frequency.end(),
           [&width, &alignment](const auto word) {
             cout << alignment << setw(width);
             cout << word.first << " ";
             cout << word.second;
             cout << endl;
           });
}

void remove(vector<string> &text, const string &remove_word) {
  auto iterator{std::remove(text.begin(), text.end(), remove_word)};
  text.erase(iterator, text.end());
};

vector<pair<string, int>>
getSortedMapByValues(map<string, int> &word_frequency) {
  vector<pair<string, int>> sorted_by_value;
  copy(word_frequency.begin(), word_frequency.end(),
       back_inserter(sorted_by_value));

  sort(sorted_by_value.begin(), sorted_by_value.end(),
       [](const auto &left, const auto &right) {
         return left.second > right.second;
       });
  return sorted_by_value;
}

void frequency(vector<string> &text) {
  map<string, int> word_frequency{getWordFrequencyMap(text)};
  vector<pair<string, int>> sorted_word_frequency{
      getSortedMapByValues(word_frequency)};
  print(text, sorted_word_frequency, false);
}

void table(vector<string> &text) {
  map<string, int> word_frequency{getWordFrequencyMap(text)};
  print(text, word_frequency);
}

void substitute(vector<string> &text, const string &parameter) {
  string::size_type split_at{parameter.find('+')};
  bool found_plus{split_at != string::npos};

  // Set oldWord to parameter if parameter has no + char
  const string oldWord{found_plus ? parameter.substr(0, split_at) : parameter};

  // Set newWord to empty string if no new word is provided which will look
  // like remove()
  const string newWord{
      found_plus ? parameter.substr(split_at + 1, parameter.size()) : ""};
  replace(text.begin(), text.end(), oldWord, newWord);
}

void executeOperation(vector<string> &text, const string &flag,
                      const string &parameter) {

  // cout << "flag: " << flag << endl;
  // cout << "parameter: " << parameter << endl;

  if (flag == "--print") {
    print(text);
  } else if (flag == "--frequency") {
    frequency(text);
  } else if (flag == "--table") {
    table(text);
  } else if (flag == "--substitute") {
    substitute(text, parameter);
  } else if (flag == "--remove") {
    remove(text, parameter);
  } else {
  };
}

int main(int argc, char *argv[]) {
  // TODO: Open the files that is
  // specified as the first command line argument
  string filename{argv[1]};
  vector<string> arguments{argv + 2, argv + argc};

  // cout << "filename: " << filename << endl;

  fstream filestream{filename};
  if (!filestream.is_open()) {
    printError("Failed to open file");
    return -1;
  }

  vector<string> text;
  istream_iterator<string> input(filestream);
  istream_iterator<string> end;

  copy(input, end, back_inserter(text));

  auto handle_arguments = [&text](string &arg) {
    string::size_type split_at{arg.find('=')};
    bool found_equal = split_at != string::npos;
    const string flag{found_equal ? arg.substr(0, split_at) : arg};
    const string param{found_equal ? arg.substr(split_at + 1, arg.size()) : ""};
    executeOperation(text, flag, param);
  };

  // Run corrosponding function to the each flag from command line arguments
  for_each(arguments.begin(), arguments.end(), handle_arguments);

  filestream.close();
  return 0;
}
