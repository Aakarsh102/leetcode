#include <iostream>
#include <string>
#include <cstdlib>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;

    while (t--) {
        int n;
        std::cin >> n;

        std::string a, b;
        std::cin >> a >> b;

        int count = 0;
        bool flag = false;

        // Process even positions
        int a_ptr = 0;
        int b_ptr = 0;

        while (b_ptr < n) {
            if (b[b_ptr] == '1') {
                while (a_ptr < n && a[a_ptr] != '1') {
                    a_ptr += 2;
                }

                if (a_ptr >= n) {
                    flag = true;
                    break;
                }

                count += abs(a_ptr - b_ptr) / 2;
                a_ptr += 2;
            }

            b_ptr += 2;
        }

        // Check for extra 1s in a
        if (!flag) {
            while (a_ptr < n && a[a_ptr] != '1') {
                a_ptr += 2;
            }

            if (a_ptr < n) {
                flag = true;
            }
        }

        // Process odd positions
        if (!flag) {
            a_ptr = 1;
            b_ptr = 1;

            while (b_ptr < n) {
                if (b[b_ptr] == '1') {
                    while (a_ptr < n && a[a_ptr] != '1') {
                        a_ptr += 2;
                    }

                    if (a_ptr >= n) {
                        flag = true;
                        break;
                    }

                    count += abs(a_ptr - b_ptr) / 2;
                    a_ptr += 2;
                }

                b_ptr += 2;
            }
        }

        // Check for extra 1s in a
        if (!flag) {
            while (a_ptr < n && a[a_ptr] != '1') {
                a_ptr += 2;
            }

            if (a_ptr < n) {
                flag = true;
            }
        }

        if (flag)
            std::cout << -1 << '\n';
        else
            std::cout << count << '\n';
    }

    return 0;
}