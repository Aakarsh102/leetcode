#include <iostream>
#include <vector> 
#include <string> 
#include <algorithm>


int main() {
    std::vector<std::string> lines;
    std::string l;
    while (getline(std::cin, l)) {
        lines.push_back(l);
    }
    int count = 0;
    int c = 0;
    int len = 0;
    std::string line;
    std::string store;
    for (int i = 0; i < lines.size(); i++) {
        store = "";
        line = lines[i];
        if (line == "") {
            count = 0;
        }
        len = line.length();
        c = std::count(line.begin(), line.end(), '*');
        for (int j = 0; j < len; j++) {
            if (j < len - c - count) {
                store += '.';
            } else if (j < len - count) {
                store += '*';
            } else {
                store += '.';
            }
        }
        std::cout << store << std::endl;
        count += c;
    }
}