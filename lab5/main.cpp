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
  cout << "./a.out <input file> FLAGS" << endl;

  cout << left << setw(35);
  cout << "FLAGS: " << endl;
  cout << setw(35);
  cout << "--print";
  cout << "Prints every word in <input file> separated by spaces" << endl;

  cout << setw(35);
  cout << "--frequency";
  cout << "Prints frequency table of <input file> in descending order of "
          "occurance"
       << endl;

  cout << setw(35);
  cout << "--table";
  cout << "Prints frequency table of <input file> in lexicographical order"
       << endl;

  cout << setw(35);
  cout << "--substitute=<oldWord>+<newWord>";
  cout << "Substitutes every occurance of <oldWord> by <newWord> in content "
          "provided by <input file>"
       << endl;

  cout << setw(35);
  cout << "--remove=<word>";
  cout
      << "Removes every occurance of <word> in content provided by <input file>"
      << endl;
}

void printError(const string &message) {
  cerr << message << endl;
  cerr << endl;
  printHelp();
}

// Return the size of the longest word from text vector of strings
unsigned long getLargestWidth(const map<string, int> &word_frequency) {
  auto longestComp = [](const auto &left, const auto &right) {
    return right.first.size() > left.first.size();
  };

  // Find the longest word
  auto longestWord{
      max_element(word_frequency.begin(), word_frequency.end(), longestComp)};

  return longestWord->first.size();
}

map<string, int> getWordFrequencyMap(const vector<string> &text) {
  map<string, int> word_frequency;

  // Fill the map with every unique occurance of eache word in text vector
  for_each(text.begin(), text.end(),
           [&word_frequency](const auto &word) { word_frequency[word]++; });
  return word_frequency;
}

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

// Prints every element in text vector with space as delimiter
void print(const vector<string> &text) {
  copy(text.begin(), text.end(), ostream_iterator<string>(cout, " "));
}

// Prints every element in word_frequency map in lexicographical order by
// default
void print(const map<string, int> &word_frequency, bool left_alignment = true,
           bool sort_by_value = false) {

  unsigned long width{getLargestWidth(word_frequency)};
  const auto alignment{left_alignment ? left : right};
  vector<pair<string, int>> word_frequency_vector;

  // Copy the content of word_frequency to word_frequency_vector
  copy(word_frequency.begin(), word_frequency.end(),
       back_inserter(word_frequency_vector));

  if (sort_by_value) {
    sort(word_frequency_vector.begin(), word_frequency_vector.end(),
         [](const auto &left, const auto &right) {
           return left.second > right.second;
         });
  }

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
}

void frequency(vector<string> &text) {
  map<string, int> word_frequency{getWordFrequencyMap(text)};
  print(word_frequency, false, true);
}

void table(vector<string> &text) {
  map<string, int> word_frequency{getWordFrequencyMap(text)};
  print(word_frequency);
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

  if (!found_plus || newWord == "") {
    throw invalid_argument(
        "--substitute requires two arguments: <oldWord>+<newWord>");
  }

  replace(text.begin(), text.end(), oldWord, newWord);
}

void executeOperation(vector<string> &text, const string &flag,
                      const string &parameter) {

  if (flag == "--print" && parameter == "") {
    print(text);
  } else if (flag == "--frequency" && parameter == "") {
    frequency(text);
  } else if (flag == "--table" && parameter == "") {
    table(text);
  } else if (flag == "--substitute" && parameter != "") {
    substitute(text, parameter);
  } else if (flag == "--remove" && parameter != "") {
    remove(text, parameter);
  } else {
    const string argument{parameter != "" ? flag + "=" + parameter : flag};
    throw invalid_argument(argument + " is not a valid argument");
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
