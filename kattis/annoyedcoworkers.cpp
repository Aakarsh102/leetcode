#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>

struct comp {
    bool operator() (const std::pair<long long, long long>& a, const std::pair<long long,long long>& b) const {
        return (a.first + a.second) > (b.first + b.second);    
    }
};
int main() {
    std::priority_queue<std::pair<long long,long long>, std::vector<std::pair<long long,long long> >, comp> pq;
    int n;
    int helps;
    std::cin >> helps;
    std::cin >> n;
    
    std::cin.ignore();
    long long a;
    long long d;
    for (int i = 0; i < n; i++) {
        std::cin >> a;
        std::cin >> d;
        std::cin.ignore();
        pq.push({a, d});
    }
    long long max_anger = 0;
    std::pair<long long, long long> cur;
    while (helps > 0) {
        cur = pq.top();
        pq.pop();
        max_anger = std::max(max_anger, cur.first + cur.second);
        cur.first = cur.first + cur.second;
        pq.push(cur);
        helps--;
    }
    std::cout << max_anger;
    return 0;
    
}




