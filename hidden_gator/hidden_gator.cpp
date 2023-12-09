#include <algorithm>
#include <iostream>
#include <iterator>
#include <map>
#include <set>
#include <sstream>
#include <vector>

/*
Problem:
  In the Marston Science Library, there are n students labeled from 1 to n. There is a rumor that one of these students is secretly a gator.

  If the gator exists, then:
    - The gator knows nobody.
    - Everybody (except for the gator) knows the gator.

There is at most one student who could be a gator and satisfies both properties.
*/

int hiddenGator(int n, std::vector<std::vector<int> > know)
{
  // Use a sort of adjacency list with set as the value of map instead of vector
  std::map<int, std::set<int> > knowledge;

  // Initialize knowledge relations in adjacency list
  for (auto& vect : know) {
    // Make sure that knowledge relations exist
    if (vect.size() != 0) {
      if (knowledge.find(vect[0]) == knowledge.end()) {
        knowledge[vect[0]] = std::set<int>();
      }
      knowledge[vect[0]].insert(vect[1]);
    }
  }

  // Find possible gators
  std::vector<int> gators;
  for (int i = 1; i <= n; i++) {
    if (knowledge.find(i) == knowledge.end()) {
      gators.push_back(i);
    }
  }
  // Make sure there is only one possible gator, return false if more
  if (gators.size() != 1) {
    return -1;
  }
  int gator = gators[0];

  // Check to make sure everybody knows the gator
  for (auto& relations : knowledge) {
    // If somebody doesn't know the gator, return false
    if (relations.second.find(gator) == relations.second.end()) {
      return -1;
    }
  }

  // If everyobody knows the possible gator and there is only one, it must be a valid gator
  return gator;
}
