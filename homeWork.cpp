#include <iostream>
#include <vector>
#include <algorithm>
#include <Windows.h>

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    const int months = 12;
    std::vector<int> profit(months);

    std::cout << "¬ведите прибыль за каждый из 12 мес€цев:\n";
    for (int i = 0; i < months; ++i) {
        std::cout << "ћес€ц " << i + 1 << ": ";
        std::cin >> profit[i];
    }

    int startMonth, endMonth;
    std::cout << "¬ведите начальный мес€ц диапазона (от 1 до 12): ";
    std::cin >> startMonth;
    std::cout << "¬ведите конечный мес€ц диапазона (от 1 до 12): ";
    std::cin >> endMonth;

    if (startMonth < 1 || endMonth > 12 || startMonth > endMonth) {
        std::cout << "Ќекорректный диапазон диапазона.\n";
        return 1;
    }

    auto range_start = profit.begin() + startMonth - 1;
    auto range_end = profit.begin() + endMonth;

    auto max_it = std::max_element(range_start, range_end);
    auto min_it = std::min_element(range_start, range_end);

    int max_month = std::distance(profit.begin(), max_it) + 1;
    int min_month = std::distance(profit.begin(), min_it) + 1;

    std::cout << "ћес€ц с максимальной прибылью: " << max_month << " (" << *max_it << ")\n";
    std::cout << "ћес€ц с минимальной прибылью: " << min_month << " (" << *min_it << ")\n";

    return 0;
}
