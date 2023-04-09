#include <future>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

template<typename Iterator, typename T>
void parallelForEach(Iterator first, Iterator last, T* function)
{
    unsigned int const length = std::distance(first, last);
    unsigned int const max = 1;
 

    if (length <= max) 
    {
        function(*first);
    }
    else
    {
        Iterator middle = first;
        std::advance(middle, length / 2);
        std::future<void> first_half_result = std::async(parallelForEach<Iterator, T>, first, middle, function);
        std::future<void> second_half_result = std::async(parallelForEach<Iterator, T>, middle, last, function);
    }
}

void printX(int x) 
{   
    std::string result = std::to_string(x) + " ";
    std::cout << result;
}

int main()
{
    std::vector<int> v;
    int n = 100;
    for (int i = 0; i < n; ++i)
    {
        v.push_back(i);
    }

    for (int i = 0; i < n; ++i)
    {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
    
    parallelForEach(v.begin(), v.end(), &printX);

    return 0;
}