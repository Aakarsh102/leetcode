#include <iostream>
#include <vector>

int main() {
    int n;
    int h;
    std::cin >> n;
    std::cin >> h;
    int a;
    std::vector<int> m;
    std::vector<int> t;
    bool even = true;
    for (int i = 0; i < n; i++) {
        std::cin >> a;
        if (even) {
            m.push_back(a);
        } else {
            t.push_back(a);
        }
        even = !even;
    }
    std::vector<int> m_h(h + 1, 0);
    std::vector<int> t_h(h + 1, 0);
    for (int i = 0; i < m.size(); i++) {
        m_h[m[i]]++;
        t_h[t[i]]++;
    }
    for (int i = h - 1; i >= 0; i--) {
        m_h[i] += m_h[i + 1];
        t_h[i] += t_h[i + 1];
    }
    int min_val = 200000;
    int count = 0;
    for (int i = 1; i <= h; i++) {
        if (m_h[i] + t_h[h - i + 1] < min_val) {
            min_val = m_h[i] + t_h[h - i + 1];
            count = 1;
        }
        else if (m_h[i] + t_h[h - i + 1] == min_val) {
            count++;
        }
    }
    std::cout << min_val << " " << count << std::endl;
}