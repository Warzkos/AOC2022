#include <iostream>
#include <fstream>

int main(){

    int distinct_chars = 14; // PART1 4; PART2 14;

    char chars[distinct_chars];
    std::fstream File("input.txt", std::fstream::in);
    for(int i=0; i<distinct_chars-1; i++){
        File >> chars[i];
    }
    int marker = distinct_chars-1;
    while (File >> chars[marker%distinct_chars]) {
        marker++;
        for(int i=1; i<distinct_chars; i++){
            for(int j=0; j<i; j++){
                if(chars[i]==chars[j]){
                    goto continue_loop;
                }
            }
        }
        break;
        continue_loop:
        continue;
    }

    std::cout << marker;

    return 0;
}