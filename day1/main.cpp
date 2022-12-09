#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main() {
  std::string str;
  int maxSum = 0;
  int currSum = 0;
  int i=0;

  std::ifstream File("input.txt");
  while (getline (File, str)) {
    if(str.length()==1){
      if(currSum>maxSum) maxSum = currSum;
      currSum = 0;
      continue;
    }

    currSum+=stoi(str);
  }
  File.close();
  
  std::cout << maxSum << std::endl;
}