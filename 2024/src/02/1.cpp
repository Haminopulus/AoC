#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <variant>
#include <vector>

#define NOT_SET -1
#define GREATER 1 
#define LESS 2

// converts each line into vector<int>, there is probably an easier way to do that
void parseToVec(std::string str, std::vector<int> &vec) {
  int n, spc_indx;
  while (str.length() > 0) {
    spc_indx = str.find_first_of(" ");
    
    n = std::stoi(str.substr(0, spc_indx));
    vec.push_back(n);
    str = (spc_indx != std::variant_npos) ? str.substr(spc_indx+1, str.size()) :  "";
  }
}

// simply checks the whether the distance between two levels is in [1,3]
bool checkGradual(int a, int b) {
  int delta = abs(a-b);
  return (delta <= 3) && (delta != 0);
}

bool checkValid(std::vector<int> vec) {
  // Checks Monotony
  // flag to save if the report seems to be increasing (=LESS) or decreasing (=GREATER)
  int flag = NOT_SET; 
  
  if (vec.front() > vec.back()) {flag = GREATER;}
  else if (vec.front() != vec.back()) {flag = LESS;}
  else {return false;}

  // all possible reasons a report could be unsafe
  for (int i = 1; i < vec.size(); i++) {
    if ((vec[i-1] > vec[i] && flag == LESS) 
      || (vec[i-1] < vec[i] && flag == GREATER)
      || !checkGradual(vec[i-1], vec[i]))
    {
      return false;
    }
  }
  return true;
}

bool checkReport(std::string &str) {
  std::vector<int> lineNums;
  std::vector<int> tmp;
  parseToVec(str, lineNums);
  return checkValid(lineNums);
}

int main() {
  std::ifstream file("./input.txt");
  std::string str;
  int count = 0;

  while (file.good()) {
    getline(file, str);
    if (file.good()) {
      if (checkReport(str)) {count++;}
    }
  }
  std::cout << "Number of Safe Reports: " << count << "\n";
}

