#include <algorithm>
#include <iostream>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n, m, k;
        std::cin >> n >> m >> k;
        int string[17];
        for (int i = 0; i < n; i++)
            string[i] = 0;
        for (int i = n; i < m + n; i++)
            string[i] = 1;
        int count = 0;
        do {
            count++;
            if (count == k) {
                for (int i = 0; i < n + m; i++)
                    std::cout << string[i];
                std::cout << std::endl;
                break;
            }
        } while (std::next_permutation(string, string + n + m));
        if (k > count)
            std::cout << "Impossible" << std::endl;
    }
    return 0;
}
