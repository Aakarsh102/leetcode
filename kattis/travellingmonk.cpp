#include <iostream>
#include <vector>
#include <iomanip>
bool simulate(std::vector<std::pair<int, int> >& ascent, std::vector<std::pair<int, int> >& descent, double time, double height) {
    double a = 0;
    double d = 0;
    int i = 0;
    double a_dist = 0;
    double d_dist = 0;
    while ((i < ascent.size()) && (a + ascent[i].second < time)) {
        a_dist += ascent[i].first;
        a += ascent[i].second;
        i++;
    }
    if (i < ascent.size() && a < time) {
        a_dist += ascent[i].first * ((double) (time - a)) / ascent[i].second;
    }
    i = 0;
    while ((i < descent.size()) && (d + descent[i].second < time)) {
        d_dist += descent[i].first;
        d += descent[i].second;
        i++;
    }
    if (i < descent.size() && d < time) {
        d_dist += descent[i].first * ((double) (time - d)) / descent[i].second;
    }
    if (a_dist < (height - d_dist)) {
        return false;
    } else {
        return true;
    }

}

int main() {
    int a;
    int d;
    std::cin >> a;
    std::cin >> d;
    std::cin.ignore();
    std::vector<std::pair<int, int> > ascent;
    std::vector<std::pair<int, int> > descent;
    int h;
    int t;
    double height = 0;
    for (int i = 0; i < a; i++) {
        // std::cout << a;
        std::cin >> h;
        std::cin >> t;
        height += h;
        std::cin.ignore();
        ascent.push_back({h, t});
    }
    for (int i = 0; i < d; i++) {
        // std::cout << d;
        std::cin >> h;
        std::cin >> t;
        std::cin.ignore();
        descent.push_back({h, t});
    }
    double l = 0;
    double r = 500000;
    for (int i = 0; i < 50; i++) {
            double mid = l + (r - l)/2;
            if (simulate(ascent, descent, mid, height)) {
                r = mid;
            } else {
                l = mid;
            }
    }
    std::cout << std::fixed << std::setprecision(6) << ((double)l) << std::endl;
    return 0;

}