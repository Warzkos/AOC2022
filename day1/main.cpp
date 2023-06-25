#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main() {
  std::string str;
  int maxSum = 0;
  int currSum = 0;
  int Sum2=0;
  int Sum3=0;

  std::ifstream File("input.txt");
  while (getline (File, str)) {
    if(str.length()==0){
      if(currSum>maxSum) {
        maxSum = currSum;
      }// else if (currSum>Sum2){
      //   Sum2=currSum;
      // } else if (currSum>Sum3){
      //   Sum3=currSum;
      // }
      currSum = 0;
      continue;
    }
    currSum+=stoi(str);
  }
  File.clear();
  File.seekg(0);
  while (getline (File, str)) {
    if(str.length()==0){
      if(currSum>Sum2 && currSum<maxSum) {
        Sum2 = currSum;
      }// else if (currSum>Sum2){
      //   Sum2=currSum;
      // } else if (currSum>Sum3){
      //   Sum3=currSum;
      // }
      currSum = 0;
      continue;
    }
    currSum+=stoi(str);
  }
  File.clear();
  File.seekg(0);
  while (getline (File, str)) {
    if(str.length()==0){
      if(currSum>Sum3 && currSum<Sum2) {
        Sum3 = currSum;
      }// else if (currSum>Sum2){
      //   Sum2=currSum;
      // } else if (currSum>Sum3){
      //   Sum3=currSum;
      // }
      currSum = 0;
      continue;
    }
    currSum+=stoi(str);
  }
  File.close();
  
  std::cout << maxSum << std::endl;
  std::cout << Sum2 << std::endl;
  std::cout << Sum3 << std::endl;
  std::cout << maxSum+Sum2+Sum3 << std::endl;
}