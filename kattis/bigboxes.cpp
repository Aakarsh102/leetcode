
// # 
// # Problem: Big Boxes
// # Author: Aakarsh Rai (rai53)
// # It is ok to show my solution to others
// #
#include <iostream>
#include <vector>

//Keep adding items to current box.
// If adding next item exceeds m, start a new box.
// if more thatn k boxes are needed, return false. Otherwise, return true.
bool possible(std::vector<int>& weights, int m, int k) {
    int cur_weight = 0;
    int boxes = 1;
    int i = 0;
    while (i < weights.size()) {
        if (weights[i] > m) {
            return false;
        }
        if ((cur_weight + weights[i]) > m) {
            cur_weight = 0;
            if (boxes < k) {
                boxes ++;
            } else {
                return false;
            }
        }
        cur_weight += weights[i];
        i++;
    }
    return true;
}

int main() {
    int n;
    int k;
    std::cin >> n;
    std::cin >> k;
    std::cin.ignore();
    std::vector<int> weights;
    int w;
    for (int i = 0; i < n; i++) {
        std::cin >> w;
        weights.push_back(w);
    }
    int l = 0;
    // h is not included we're doing the [) version of bin search
    int h = 1000000001;
    int m = 0;
    while (l < h) {
        m = l + (h - l)/2;
        if (possible(weights, m, k)) {
            // if possible then the answer is less than or equal to m. 
            h = m;
        } else {
            // if not, then the answer must be greater than m.
            l = m + 1;
        }
    }
    std::cout << l;
}