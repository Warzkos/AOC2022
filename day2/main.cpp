#include <iostream>
#include <fstream>
#include <string>

int main() {
  std::string str;
  std::ifstream File("input.txt");
  int points = 0;
//pt1
  while (getline (File, str)) {
    char action = str.substr(0,1)[0];
    char response = str.substr(2,1)[0];

    points+=(int(response)-int(action)+2)%3*3+int(response)%4+1;
  }
  std::cout << "part 1: " << points << std::endl;
  points=0;
  File.clear();
  File.seekg(0);
//pt2
  while (getline (File, str)) {
    char action = str.substr(0,1)[0];
    char result = str.substr(2,1)[0];

    points+=int(result)%4*3+(int(action)-2-(int(result)-89)*2)%3+1;
  }
  File.close();
  std::cout << "part 2: " << points << std::endl;

}