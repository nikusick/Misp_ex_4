#include <iostream>
#include <vector>
#include <iterator>

int main() {
    int N, num;
    std::cin >> N;
    std::vector<int> nums;
    for (int i = 0; i < N; ++i) {
        std::cin >> num;
        nums.push_back(num);
    }
    auto maxElIt = std::max_element(nums.begin(), nums.end());

    auto is_even = [](int i){ return i % 2 == 0; };
    auto elForDelIt = std::find_if(maxElIt + 1, nums.end(), is_even);

    auto index = std::distance(nums.begin(), elForDelIt);
    if (elForDelIt != nums.end()) {
        std::cout << "Позиция элемента: " << index << std::endl;
        std::cout << "Значение элемента: " << *elForDelIt << std::endl;
        nums.erase(elForDelIt);
        std::cout << "Массив после удаления элемента: ";
        std::copy(nums.begin(), nums.end(), std::ostream_iterator<int>(std::cout, " "));
    }
    else {
        std::cout << "Такого элемента нет!";
    }
    return 0;
}
