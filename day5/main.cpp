#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <vector>

#define PART1 1
#define PART2 0

int main(){
    int stack_num = 1;

    std::string line;
    std::ifstream File("input.txt");
    while(getline(File, line)){
        if(line.find('1') != std::string::npos){
            while(stack_num++){
                char num[3];
                itoa(stack_num, num, 10);
                if(line.find(num)==std::string::npos){
                    stack_num--;
                    break;
                }
            }
            break;
        }
    }
    File.clear();
    File.seekg(0);

    // sanity check
    // std::cout << stack_num << std::endl;

    std::vector<std::vector<char>> stacks;

    for(int i = 0; i<stack_num; i++){
        std::vector<char> stack = {};
        while(getline(File, line)){
            if(isdigit(line[i*4+1])){
                break;
            }
            if(line[i*4+1]!=' '){
                stack.insert(stack.begin(), line[i*4+1]);
            } 
        }
        stacks.emplace_back(stack);
        if (stack_num-1==i) break;
        File.clear();
        File.seekg(0);
    }

    // sanity check
    // for(int i=0; i<stacks.size(); i++){
    //     std::cout << i+1 << " elements: " << stacks[i].size() << std::endl;
    // }

    getline(File, line);

    // sanity check
    // std::cout << line;

    // for (int i=0; i<stacks.size(); i++){
    //     //std::cout << "last element of " << i+1 << " stack is: " << stacks[i].back() << std::endl;
    //     //std::cout << stacks[i].back();
    //     for (int j=0; j<stacks[i].size(); j++){
    //         std::cout << stacks[i][j];
    //     }
    //     std::cout << std::endl;
    // }

    while(getline(File, line)){
        int move = stoi(line.substr(line.find("move")+5, line.find("from")-1-line.find("move")+5));
        int from = stoi(line.substr(line.find("from")+5, line.find("to")-1-line.find("from")+5));
        int to   = stoi(line.substr(line.find("to")+3));

        #if PART2 == 1
        stacks[to-1].insert(stacks[to-1].end(), stacks[from-1].end()-move, stacks[from-1].end());
        stacks[from-1].erase(stacks[from-1].end()-move, stacks[from-1].end());
        #endif
        #if PART1 == 1
        for(int i=0; i<move; i++){
            stacks[to-1].push_back(stacks[from-1].back());
            stacks[from-1].pop_back();
        }
        #endif
        //  sanity check
        // for(int i=0; i<stacks[to-1].size(); i++)
        //     std::cout << stacks[to-1][i];
        // std::cout << std::endl;

        

        // sanity check
        // for(int i=0; i<stacks[from-1].size(); i++)
        //     std::cout << stacks[from-1][i];
        // std::cout << std::endl;
        // std::cout << "move " << move << " from " << from << " to " << to << std::endl;
        // for (int i=0; i<stacks.size(); i++){
        //     //std::cout << "last element of " << i+1 << " stack is: " << stacks[i].back() << std::endl;
        //     //std::cout << stacks[i].back();
        //     for (int j=0; j<stacks[i].size(); j++){
        //         std::cout << stacks[i][j];
        //     }
        //     std::cout << std::endl;
        // }


    }

    for (int i=0; i<stacks.size(); i++){
        //std::cout << "last element of " << i+1 << " stack is: " << stacks[i].back() << std::endl;
        std::cout << stacks[i].back();
    }

    return 0;
}