// # 
// # Problem: Class Picture
// # Author: Aakarsh Rai (rai53)
// # It is ok to show my solution to others
// #

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>
// this function checks if the list of students is valid
// basically checks adjacent students don't hate each other
bool isCompatible(std::string& s, 
                    std::unordered_map<char, std::unordered_set<char>>& map) {
    for (int i = 0; i < s.length() - 1; i++) {
        if (map[s[i]].contains(s[i + 1]) || map[s[i + 1]].contains(s[i])) {
            return false;
        }
    }
    return true;
}

// This is the main backtracking function
// creates the permutations of students and also prunes branches that are invalid early
// it does it using the isCompatible function
bool doBacktrack(std::string&s, std::unordered_map<char, std::unordered_set<char>>&map, 
int cur_ind, std::string& cur, 
std::vector<bool>& used) {
    if (cur_ind == s.length()) {
        if (isCompatible(cur, map)) {

            return true;
        } 
        return false;
    }
    for (int i = 0; i < s.length(); i++) {
        // we don't want to reuse characaters 
        if (used[i]) {
            continue;
        }
        if (cur_ind == 0) {
            cur += s[i];
            used[i] = true;
            // if True is returned, we return true without going further 
            if (doBacktrack(s, map, cur_ind + 1, cur, used)) {
                return true;
            }
            used[i] = false;
            cur.pop_back();
            continue;
        }
        // checking if the last character in current string hates the new character
        if (!(map[cur.back()].contains(s[i]) || map[s[i]].contains(cur.back()))) {
            cur += s[i];
            used[i] = true;
            if (doBacktrack(s, map, cur_ind + 1, cur, used)) {
                return true;
            }
            used[i] = false;
            cur.pop_back();
        }
    }
    return false;
}
int main() {
    int n = 0;
    std::vector<std::string> vec;
    // character to string mapping
    std::vector<std::string> store(26, "");
    // string to character mapping
    std::unordered_map<std::string, char> store2;
    // hate container 
    std::unordered_map<char, std::unordered_set<char>> map;
    std::string str;

    std::string name1;
    std::string name2;
    bool done = false;
    while (std::cin >> n) {
        std::cin.ignore();
        map.clear();
        store2.clear();
        // std::fill(store.begin(), store.end(), "");
        store.clear();
        vec.clear();
        for (int i = 0; i < n; i++) {
            std::getline(std::cin, str);
            vec.push_back(str);
        }
    
        char c = 'a';
        // we're sorting the names since we need them sorted. 
        std::sort(vec.begin(), vec.end());
        std::string cur_str = "";
        // compressing the names to a single char for compressing.
        for (int i = 0; i < n; i++) {
            store[i] = vec[i];
            store2[vec[i]] = c;
            cur_str += c;
            c++;
        }
        std::cin >> n;
        std::cin.ignore();
        // storing the people who hate each other. 
        for (int i = 0; i < n; i++) {
            std::cin >> name1;
            std::cin >> name2;
            std::cin.ignore();
            map[store2[name1]].insert(store2[name2]);
        }
        std::string back_str = "";
        // used array that will track used characters
        std::vector<bool> used(cur_str.length(), false);
        done  = doBacktrack(cur_str, map, 0, back_str, used);
        cur_str = back_str;
        // If not done -> not found. 
        if (!done) {
            std::cout << "You all need therapy.\n";
            done = false;
            continue;
        }
        done = false;
        std::string final_string="";
        // This part creates the final string after converting 
        // the chars to the names. 
        for (int i = 0; i < cur_str.length(); i++) {
            if (i == (cur_str.length() - 1)) {
                final_string = final_string + store[cur_str[i] - 'a'];
                break;
            }
            final_string = final_string + store[cur_str[i] - 'a'] + ' ';
        }
        std::cout << final_string << std::endl;
    }   
}