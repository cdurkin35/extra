#include <iostream>
#include <iterator>
#include <set>
#include <string>
#include <vector>

/*
Problem:
You are given a string digits, where each character represents an integer. You need to find all unique integers that follow the given
requirements:
  - The integer consists of the concatenation of four characters from digits in any arbitrary order
  - The integer does not have any leading zeros
  - The integer is odd
  - Each digit in the input integer can only be used once in the output integer
*/

std::vector<int> fourDigitNumbers(std::string str)
{
  // Create vector to hold each digit
  std::vector<int> digits;
  // Create set for valid combinations
  std::set<int> combinations;
  // Create set for unused digits (use their indices in case of duplicate integers)
  std::set<int> indicies;
  // Initialize indicies set and digits vector
  for (int i = 0; i < str.size(); i++) {
    indicies.insert(i);
    digits.push_back(int(str[i] - '0'));
  }

  // Iterate over all possible combinations of digits
  for (auto index1 : indicies) {
    // Check if leading 0, if so, skip all of these combinations
    if (digits[index1] == 0) {
      continue;
    }
    // Create duplicate set and remove index1
    std::set<int> indicies1(indicies);
    indicies1.erase(index1);
    for (auto index2 : indicies1) {
      // Create duplicate set and remove index 2
      std::set<int> indicies2(indicies1);
      indicies2.erase(index2);
      for (auto index3 : indicies2) {
        // Create duplicate set and remove index 3
        std::set<int> indicies3(indicies2);
        indicies3.erase(index3);
        for (auto index4 : indicies3) {
          // Check if even, if so, skip this combination
          if (digits[index4] % 2 == 0) {
            continue;
          }
          // Add combination to set
          combinations.insert((digits[index1] * 1000) + (digits[index2] * 100) + (digits[index3] * 10) + (digits[index4] * 1));
        }
      }
    }
  }
  std::vector<int> returnVec(combinations.begin(), combinations.end());
  return returnVec;
}

int main()
{
  std::vector<int> result = fourDigitNumbers("0123");
  for (auto in : result) {
    std::cout << in << " ";
  }
}
