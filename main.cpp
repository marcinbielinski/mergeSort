#include <iostream>
#include <vector>
#include <deque>

struct Card
{
    Card(int value, std::string col) : val(value), color(std::move(col))
    {

    }
    int getVal() const
    {
        return val;
    }

    std::string getColor() const
    {
        return color;
    }

private:
    int val;
    std::string color;
};


template <typename T, typename C>
void mergeMeRee(std::vector<T>& to_sort, const std::vector<T>& first, const std::vector<T>& second, C&& comparator)
{
    std::size_t v1idx = 0;
    std::size_t v2idx = 0;

    auto size1 = first.size();
    auto size2 = second.size();

    while (v1idx < size1 && v2idx < size2)
    {
        if (comparator(first[v1idx], second[v2idx]))
        {
            to_sort.push_back(first[v1idx]);
            v1idx++;
        }
        else
        {
            to_sort.push_back(second[v2idx]);
            v2idx++;
        }
    }
    while (v1idx < size1)
    {
        to_sort.push_back(first[v1idx]);
        v1idx++;
    }

    while (v2idx < size2)
    {
        to_sort.push_back(second[v2idx]);
        v2idx++;
    }
}

template <typename T, typename C>
void mergeSort (std::vector<T>& to_sort, C&& comparator)
{
    if (to_sort.size() <= 1)
    {
        return;
    }

    auto it = begin(to_sort) + to_sort.size() / 2;

    std::vector<T> helper1 (begin(to_sort), it);
    std::vector<T> helper2 (it, end(to_sort));

    mergeSort(helper1, comparator);
    mergeSort(helper2, comparator);

    to_sort.clear();

    mergeMeRee(to_sort, helper1, helper2, comparator);
}

template <typename T>
void printMe(const std::vector<T>& to_print)
{
    for (auto& elem : to_print)
    {
        std::cout << elem << ", ";
    }
    std::cout << std::endl;
}

template <typename T>
void printMe2(const std::vector<T>& to_print)
{
    for (const auto& elem : to_print)
    {
        std::cout << elem.getVal() << " : " << elem.getColor() << ", ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> my_vec {5, 6, 3, 1, 10, -40};

    printMe(my_vec);

    mergeSort(my_vec, [](auto& first, auto& second){ return first < second; });

    printMe(my_vec);

    Card card1 {10, "Pik"};
    Card card2 {5, "Kier"};
    Card card3 {7, "Trefl"};

    std::vector<Card> my_vec2 {card1, card2, card3};

    printMe2(my_vec2);

    mergeSort(my_vec2, [](auto& first, auto& second){ return first.getVal() < second.getVal(); });

    printMe2(my_vec2);

    return 0;
}