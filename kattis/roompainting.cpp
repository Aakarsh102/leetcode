#include <iostream>
#include <vector>

int upper_bound(std::vector<int>& vec, int target) {
    int l = 0;
    int r = vec.size();
    int mid = 0;
    while (l < r) {
        mid = l + (r - l)/2;
        if (vec[mid] < target) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    return l;
}
int main() {
    int m;
    int n;
    std::cin >> n;
    std::cin >> m;
    std::cin.ignore();
    std::vector<int> sizes;
    std::vector<int> reqs;
    int a;
    for (int i = 0; i < n; i++) {
        std::cin >> a;
        std::cin.ignore();
        sizes.push_back(a);
    }
    std::sort(sizes.begin(), sizes.end());
    for (int i = 0; i < m; i++) {
        std::cin >> a;
        std::cin.ignore();
        reqs.push_back(a);
    }
    long long loss= 0;
    int index = 0;

    for (int i = 0; i < m; i++) {
        index = upper_bound(sizes, reqs[i]);

        loss += sizes[index] - reqs[i];
    }
    std::cout << loss;

}