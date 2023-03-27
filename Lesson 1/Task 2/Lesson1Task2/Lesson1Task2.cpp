#include <iostream>
#include <thread>
#include <chrono>
#include <vector>

void sum(std::vector<int> v1, std::vector<int> v2, std::vector<int> v_sum, int core_number, int thread_number)
{
    size_t i = 0, j = 0;

    if (core_number == 1 || thread_number == 1)
    {
        j = v1.size() / core_number;
    }
    else if (core_number == thread_number)
    {
        i = v1.size() / core_number * (thread_number - 1);
        j = v1.size();
    }
    else {
        i = v1.size() / core_number * (thread_number - 1);
        j = v1.size() / core_number * thread_number;
    }
    
    for (i; i < j; ++i)
    {
        v_sum[i] = v1[i] + v2[i];
    }
}

double time(std::vector<int> v1, std::vector<int> v2, std::vector<int> v_sum, int core_number)
{
    auto start = std::chrono::steady_clock::now();
    std::vector<std::thread> v_thread;
    for (int i = 1; i <= core_number; ++i)
    {
        v_thread.push_back(std::thread(sum, v1, v2, v_sum, core_number, i));
    }
    for (auto& t : v_thread)
    {
        t.join();
    }

    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> duration = end - start;

    return duration.count();
}

void execution(int core_number)
{
    std::cout << core_number << " потоков\t";
    
    for (int i = 1000; i <= 1000000; i *= 10)
    {
        std::vector<int> v1(i, 1);
        std::vector<int> v2(i, 1);
        std::vector<int> v_sum(i, 0);

        std::cout << time(v1, v2, v_sum, core_number) << "s\t";
    }

    std::cout << std::endl;
}

int main()
{
    setlocale(LC_ALL, "Russian");

    std::cout << "Количество аппаратных ядер - " << std::thread::hardware_concurrency() << std::endl;
    std::cout << std::endl;
    std::cout << "\t\t" << "1000\t\t" << "10000\t\t" << "100000\t\t" << "1000000\t" << std::endl;

    for (int i = 1; i <= 16; i *= 2)
    {
        execution(i);
    }

    return 0;
}