#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

int func() {
    return 0;
}

int main() {
    std::vector<int> data = {1, 21, 31, 41, 51, 61, 71, 81};
    std::ostream_iterator<int> dataIter(std::cout, ", ");
    std::copy(data.begin(), data.end(), dataIter);
    return 0;
}
