#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>  
char create_hash(std::string& str) {
    char hash = 0;
    for (int i = 0; i < str.length(); i++) {
        hash = hash ^ str[i];
    }
    return hash;
}
int main() {
    int n;
    while (std::cin >> n) {
        if (n == 0) {
            break;
        }
        std::cin.ignore();

        std::vector<char> vec;
        std::vector<std::string> strings;
        std::string str;
        for (int i = 0; i < n; i++) {
            std::getline(std::cin, str);
            vec.push_back(create_hash(str));
            strings.push_back(str);
        }
        int unique = 0;
        int collisions = 0;
        std::unordered_set<std::string> seen;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (vec[j] == vec[i] && strings[j] != strings[i]) {
                    collisions ++;
                }
            }
            seen.insert(strings[i]);
        }
        std::cout << seen.size();
        std::cout << " ";
        std::cout << collisions << std::endl;
        if (n == 0) {
            break;
        }
    }
    
    
}
