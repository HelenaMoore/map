#include <atomic>
#include <iostream>
#include <chrono>
#include <thread>

void client(std::atomic <int>& counter, int max)
{
    while (counter < max)
    {
        counter.fetch_add(1, std::memory_order_relaxed);
        std::cout << "Клиентов в очереди: " << counter << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    } 
}

void operationist(std::atomic <int>& counter)
{
    while (counter > 0)
    {
        std::this_thread::sleep_for(std::chrono::seconds(2));
        counter.fetch_add(-1, std::memory_order_relaxed);
        std::cout << "Осталось клиентов: " << counter << std::endl;
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");

    std::atomic <int> counter;
    counter.store(0);

    int max = 6;

    std::thread t1(client, std::ref(counter), max);
    std::thread t2(operationist, std::ref(counter));

    t1.join();
    t2.join();

    return 0;
}