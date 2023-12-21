#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <stdexcept>
#include <string>
#include <vector>
using namespace std;

void printHelp() {
  cerr << "./a.out <input file> FLAGS" << endl;

  cerr << left << setw(35);
  cerr << "FLAGS: " << endl;
  cerr << setw(35);
  cerr << "--print";
  cerr << "Prints every word in <input file> separated by spaces" << endl;

  cerr << setw(35);
  cerr << "--frequency";
  cerr << "Prints frequency table of <input file> in descending order of "
          "occurance"
       << endl;

  cerr << setw(35);
  cerr << "--table";
  cerr << "Prints frequency table of <input file> in lexicographical order"
       << endl;

  cerr << setw(35);
  cerr << "--substitute=<oldWord>+<newWord>";
  cerr << "Substitutes every occurance of <oldWord> by <newWord> in content "
          "provided by <input file>"
       << endl;

  cerr << setw(35);
  cerr << "--remove=<word>";
  cerr
      << "Removes every occurance of <word> in content provided by <input file>"
      << endl;
}

void printError(const string &message) {
  cerr << message << endl;
  cerr << endl;
  printHelp();
}

// Return the size of the longest word from text vector of strings
unsigned long getLargestWidth(const vector<string> &text) {
  auto longestComp = [](const string &left, const string &right) {
    return right.size() > left.size();
  };

  // Find the longest word
  auto longestWord{max_element(text.begin(), text.end(), longestComp)};

  return longestWord->size();
}

map<string, int> getWordFrequencyMap(const vector<string> &text) {
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
  unsigned long width{getLargestWidth(text)};
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
  unsigned long width{getLargestWidth(text)};
  const auto alignment{left_alignment ? left : right};
  for_each(word_frequency.begin(), word_frequency.end(),
           [&width, &alignment](const auto word) {
             cout << alignment << setw(width);
             cout << word.first << " ";
             cout << word.second;
             cout << endl;
           });
}

// Remove every instance of word in text vector of strings
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
    throw invalid_argument("Please provide a valid FLAG");
  };
}

int main(int argc, char *argv[]) {
  if (argc < 3) {
    printError("Please provide an input file and atleast on FLAG");
    return -1;
  }

  string filename{argv[1]};
  vector<string> arguments{argv + 2, argv + argc};

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

  try {
    // Run corrosponding function to the each flag from command line arguments
    for_each(arguments.begin(), arguments.end(), handle_arguments);
  } catch (invalid_argument &e) {
    printError(e.what());
    return -1;
  }

  filestream.close();
  return 0;
}
