/*
Degree of String Problem:
  Given a string str, the degree of this string is defined as the maximum frequency of any one of its characters.
  Your task is to find the minimum length of a contiguous substring of str, that has the same degree as str.
*/

#include <iostream>
#include <iterator>
#include <map>
#include <string>

/*
getDegreeOfString: Returns degree of the string 'str'
Time Complexity:   O(n), n = length of string
Explanation:       Function iterates over every character in string (n)
*/
int getDegreeOfString(std::string str)
{
  // Find the frequency of each char in string
  std::map<char, int> char_degrees;
  for (auto c : str) {
    char_degrees[c] += 1;
  }

  // Find character with maximum frequency
  int string_degree = 0;
  std::map<char, int>::iterator itr = char_degrees.begin();
  while (itr != char_degrees.end()) {
    if (itr->second >= string_degree) {
      string_degree = itr->second;
    }
    itr++;
  }

  // Return the degree of the string
  return string_degree;
}

/*
degreeOfString:    Returns the minumum length of a substring of 'str' that has the same degree of 'str'
Time Complexity:   O(n^3), n = length of string
Explanation:       Iterates over every possible sustring (O(n^2)) and to this substring, calls getDegreeOfString which is O(n)
*/
int degreeOfString(std::string str)
{
  // Use 'str' length as initial minimum size value
  int min_size = str.size();
  // Get degree of 'str'
  int string_degree = getDegreeOfString(str);

  // Iterate over every substring of 'str'
  for (int i = 0; i < str.size(); i++) {
    for (int j = i + 1; j <= str.size(); j++) {
      // Get substring
      std::string substring = str.substr(i, j - i + 1);
      // Get degree of substring
      int substr_degree = getDegreeOfString(substring);
      // Check of substring has same degree as 'str' and if length of substring is the current shortest
      if (substr_degree == string_degree) {
        if (substring.size() < min_size) {
          min_size = substring.size();
        }
      }
    }
  }
  // Return resulting minumum size
  return min_size;
}

int main()
{
  // Test function
  std::cout << degreeOfString("fl1pthat") << "\n";
  return 0;
}
