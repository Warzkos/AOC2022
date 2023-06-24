#include <iostream>
#include <fstream>
#include <string>

int main(){

    int cumPriority = 0;
    std::string items;

    std::ifstream File("input.txt");
    while (getline (File, items)){
        for(int i=0; i<items.length()/2; i++){
            for(int j=items.length()/2; j<items.length(); j++){
                if(items[i]==items[j]){
                    int priority=items[i];
                    if(priority<91){
                        cumPriority+=priority-38;
                    }
                    else {
                        cumPriority+=priority-96;
                    }
                    goto endlooppt1;
                }
            }
        }
        endlooppt1:
        continue;
    }

    std::cout << "PART1\nCumulated priority: " << cumPriority << std::endl;

    std::string items2;
    std::string items3;
    cumPriority = 0;
    File.clear();
    File.seekg(0);
    while (getline(File, items) && getline(File, items2) && getline(File, items3)){
        for(int i=0; i<items.length(); i++){
            for(int j=0; j<items2.length(); j++){
                if(items[i]==items2[j]){
                    for(int k=0; k<items3.length(); k++){
                        if(items2[j]==items3[k]){
                            int priority=items3[k];
                            if(priority<91){
                                cumPriority+=priority-38;
                            }
                            else {
                                cumPriority+=priority-96;
                            }
                            goto endlooppt2;
                        }
                    }
                }
            }
        }
        endlooppt2:
        continue;
    }
    File.close();
    
    std::cout << "PART2\nCumulated priority: " << cumPriority;

    return 0;
}