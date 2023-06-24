#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

int main(){

    int cum = 0;
    std::string line;
    std::ifstream File("input.txt");

    while (getline(File, line)){
        std::string assignments1 = line.substr(0, line.find(','));
        std::string assignments2 = line.substr(line.find(',')+1);

        int range1_start = stoi(assignments1.substr(0, assignments1.find('-')));
        int range2_start = stoi(assignments2.substr(0, assignments2.find('-')));

        if(range1_start==range2_start){
            cum++;
        } else {
            int range1_end = stoi(assignments1.substr(assignments1.find('-')+1));
            int range2_end = stoi(assignments2.substr(assignments2.find('-')+1));
            if(range1_start<range2_start){
                if(range1_end>=range2_end){
                    cum++;
                }
            } else {
                if(range2_end>=range1_end){
                    cum++;
                }
            }
        }
    }

    std::cout << "PART1\nCum pairs: " << cum << std::endl;
    
    // PART2
    cum=0;
    File.clear();
    File.seekg(0);

    while (getline(File, line)){
        std::string assignments1 = line.substr(0, line.find(','));
        std::string assignments2 = line.substr(line.find(',')+1);

        int range1_start = stoi(assignments1.substr(0, assignments1.find('-')));
        int range2_start = stoi(assignments2.substr(0, assignments2.find('-')));
        int range1_end = stoi(assignments1.substr(assignments1.find('-')+1));
        int range2_end = stoi(assignments2.substr(assignments2.find('-')+1));

        if((range1_start<=range2_start&&range1_end>=range2_start)||(range2_start<=range1_start&&range2_end>=range1_start)){
            cum++;
        }
    }
    File.close();

    std::cout << "PART2\nCum pairs: " << cum;

    return 0;
}