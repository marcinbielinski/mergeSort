#include <iostream>
#include <vector>
#include <deque>

template <typename T>
std::vector<T> mergeMeRee(const std::vector<T>& first, const std::vector<T>& second)
{
    std::vector<T> result;

    std::deque<T> my_deq_first;

    for (const auto& elem : first)
    {
        my_deq_first.emplace_back(elem);
    }

    std::deque<T> my_deq_second;

    for (const auto& elem : second)
    {
        my_deq_second.emplace_back(elem);
    }

    while (!my_deq_first.empty() && !my_deq_second.empty())
    {

        if (my_deq_first.front() <= my_deq_second.front())
        {
            result.emplace_back(my_deq_first.front());
            my_deq_first.pop_front();
        }
        else
        {
            result.emplace_back(my_deq_second.front());
            my_deq_second.pop_front();
        }
    }

    while (!my_deq_first.empty())
    {
        result.emplace_back(my_deq_first.front());
        my_deq_first.pop_front();
    }

    while (!my_deq_second.empty())
    {
        result.emplace_back(my_deq_second.front());
        my_deq_second.pop_front();
    }
    return result;
}

template <typename T>
std::vector<T> mergeSort (const std::vector<T>& to_sort)
{
    if (to_sort.size() <= 1)
    {
        return to_sort;
    }

    std::vector<T> helper1;
    std::vector<T> helper2;

    for (int i = 0; i < to_sort.size(); ++i)
    {
        if (i < (to_sort.size()/2))
        {
            helper1.emplace_back(to_sort[i]);
        }
        else
        {
            helper2.emplace_back(to_sort[i]);
        }
    }

    auto first_half = mergeSort((helper1));
    auto second_half = mergeSort((helper2));

    return mergeMeRee(first_half, second_half);
}

int main() {
    std::vector<int> my_vec {5, 6, 3, 1, 10};
    auto output = mergeSort(my_vec);

    for (auto& elem : output)
    {
        std::cout << elem << ',';
    }
    return 0;
}