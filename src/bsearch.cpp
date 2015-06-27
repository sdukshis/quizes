#include <vector>

int bsearch(std::vector<int> a, int key) {
    int low = 0, high = a.size() - 1, mid;
    do {
        mid = (low + high) / 2;

        if (key < a[mid]) {
            high = mid;
        } else {
            low = mid + 1;
        }
    } while ((low <= high) && (key != a[mid]));

    return (low <= high) ? mid : -1;
}
