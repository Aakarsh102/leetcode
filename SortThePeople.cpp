#include <iostream>
#include <vector>
#include <algorithm>

class Solution {

public:
    void QuickSort(std::vector<std::string>& names, std::vector<int>& heights, int low, int high) {
        if (low < high) {
            int j = high;
            int i = low;
            while (i < j) {
                while (heights[i] <= heights[low]) {
                    i++;
                }
                while (heights[j] > heights[low]) {
                    j--;
                }
                if (i < j) {
                    std::swap(names[i], names[j]);
                    std::swap(heights[i], heights[j]);
                }
            }
            std::swap(names[j], names[low]);
            std::swap(heights[j], heights[low]);
            int location = j;
            QuickSort(names, heights, low, location - 1);
            QuickSort(names, heights, location + 1, high);
        }
    }

    std::vector<std::string> sortPeople(std::vector<std::string>& names, std::vector<int>& heights) {
        if (heights.size() == 1) {
            return names;
        }
        QuickSort(names, heights, 0, heights.size() - 1);
        return names;  
    }
};

int main() {
    Solution s;
    std::vector<std::string> names;
    names.push_back("Alex");
    names.push_back("Charlie");
    names.push_back("Michael");
    // names.push_back("Ryan");
    // names.push_back("Zoe");

    std::vector<int> heights;
    heights.push_back(180);
    heights.push_back(165);
    heights.push_back(170);
    // heights.push_back(135);
    // heights.push_back(10);
    std::vector<std::string> result = s.sortPeople(names, heights);
    for (int i = 0; i < result.size(); i++) {
        std::cout << result[i] << " ";
    }
    return 0;

}