#include <iostream>
#include <vector>
#include <unordered_map>

std::string dnc(std::vector<unsigned long long>& vec, bool start, unsigned long long i, int index ) {
    if (index <= 1) {
        return index == 0 ? "N" : "A";
    }
    if (i < vec[index - 2]) {
        return dnc(vec, start, i, index - 2);
    } else {
        return dnc(vec, start, i - vec[index - 2], index - 1);
    }
}

int main() {
    int n;
    
    unsigned long long k;
    std::cin >> n;
    std::cin >> k;
    if (n == 1) {
        std::cout << "N";
        return 0;
    }
    if (n == 2) {
        std::cout << "A";
        return 0;
    }
    k--;
    std::vector<unsigned long long> vec(n, 0);
    unsigned long long a;

    vec[0] = 1;
    vec[1] = 1;
    int i = 2;
    for (i = 2; i < n; i++) {
        if (vec[i - 1] + vec[i - 2] > k){
            vec[i] = k + 1;
            i++;
            break;
        }
        vec[i] = vec[i - 1] + vec[i - 2];
    }
    std:: cout << dnc(vec, true, k, i - 1);


}
// #include <bits/stdc++.h>
// using namespace std;

// const unsigned long long LIM = 1000000000000000000ULL; // 1e18

// char dnc(const vector<unsigned long long>& vec, unsigned long long pos, int idx) {
//     // stop when we know which base string we are in
//     if (idx == 0) return 'N';
//     if (idx == 1) return 'A';

//     if (pos < vec[idx - 2]) {
//         return dnc(vec, pos, idx - 2);
//     } else {
//         return dnc(vec, pos - vec[idx - 2], idx - 1);
//     }
// }

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int n;
//     unsigned long long k_input;
//     if (!(cin >> n >> k_input)) return 0;
//     if (n <= 0) return 0;

//     // make k zero-indexed
//     if (k_input == 0) {
//         // problem likely 1-based K; if K==0 input is weird, but handle gracefully
//         cout << 'N' << '\n';
//         return 0;
//     }
//     unsigned long long k = k_input - 1;

//     if (n == 1) { cout << 'N' << '\n'; return 0; }
//     if (n == 2) { cout << 'A' << '\n'; return 0; }

//     vector<unsigned long long> vec(n, 0);
//     vec[0] = 1;
//     vec[1] = 1;

//     // build lengths but clamp them to at most k+1 (we only need to distinguish <k)
//     unsigned long long cap = min(LIM, k + 1);
//     for (int i = 2; i < n; ++i) {
//         unsigned long long s = vec[i - 1] + vec[i - 2];
//         if (s > cap) s = cap;
//         vec[i] = s;
//     }

//     cout << dnc(vec, k, n - 1) << '\n';
//     return 0;
// }
