#include <iostream>
#include <vector>
#include <algorithm>

double calc(int r, int w) {
    return std::sqrt((double)(r * r) - (double)(w * w) / 4.0);
}

int main() {
    int n;
    int l;
    int w;
    while (std::cin >> n) {

        std::cin >> l;
        std::cin >> w;
        std::cin.ignore();
        double a;
        double b;
        std::vector<std::pair<double,double> > vec;
        for (int i = 0; i < n; i++) {
            std::cin >> a;
            std::cin >> b;
            std::cin.ignore();
            if (b * 2 >= w) {
                vec.push_back({a, b});
            }
        }


        // sort by (first + second)
        std::sort(vec.begin(), vec.end(),
            [&](const std::pair<double,double>& a, const std::pair<double,double>& b) {
                return (a.first - calc(a.second, w)) < (b.first - calc(b.second, w));
            });

        a = 0;
        b = 0;
        double x;
        double r;
        int count = 0;
        for (int i = 0; i < vec.size(); i++) {
            if (b >= l) {
                //std::cout << count << std::endl;
                break;
            }
            x = vec[i].first;
            r = vec[i].second;
            if (i == 0 && (x - calc(r, w) > 0)) {
                //std::cout << -1 << std::endl;
                break;
            }
            if (x - calc(r, w) > b) {
                //std::cout << -1 << std::endl;
                break;
            }
            if (x + calc(r, w) > b) {
                a = b;
                while (i < vec.size() && ((vec[i].first - calc(vec[i].second, w)) <= a)) {
                    if (vec[i].first + calc(vec[i].second, w) > b) {
                        b = std::max(vec[i].first + calc(vec[i].second, w), b);
                    }
                    i++;
                }
                i--;
                count++;
                // a = vec[i - 1].first - vec[i-1].second;

                // if (x - r <= b_old) {
                //     b = x + r;
                //     continue;
                // }
                // if (x - r > a) {
                //     count++;
                //     a = std::max(x - r, 0);
                // }
                // b_old = b; 
                // b = x + r;
            }
        }
        if (b >= l) {
            std::cout << count << std::endl;
            continue;
        }
        std::cout << -1 << std::endl;
        
    }
    return 0;
}