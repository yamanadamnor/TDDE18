#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  fstream fs;
  string word;
  string longest = "";
  string shortest = "";
  float average = 0.0;
  int wordCount = 0;

  fs.open("input.txt");

  if (!fs)
  {
    cout << "No such file exists" << endl;
  }
  else
  {

    while (fs >> word)
    {
      if (wordCount == 0)
      {
        shortest = word;
      }
      if (word.length() > longest.length())
      {
        longest = word;
      }
      else if (word.length() < shortest.length())
      {
        shortest = word;
      }

      wordCount++;
      average += word.length();
    }
  }
  fs.close();
  cout << "There are " << wordCount << " words in the file." << endl;
  cout << "The shortest word was \"" << shortest << "\" with " << shortest.length() << " charachter(s)" << endl;
  cout << "The longest word was \"" << longest << "\" with " << longest.length() << " charachter(s)" << endl;
  cout << "The average length was " << setprecision(2) << fixed << average / wordCount << " charachter(s)" << endl;
}
