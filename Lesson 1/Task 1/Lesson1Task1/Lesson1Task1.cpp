#include <iostream>
#include <chrono>
#include <thread>

void client(int &counter, int max)
{
    while (counter < max)
    {
        ++counter;
        std::cout << "Клиентов в очереди: " << counter << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

void operationist(int &counter)
{
    while (counter > 0)
    {
        std::this_thread::sleep_for(std::chrono::seconds(2));
        --counter;
        std::cout << "Осталось клиентов: " << counter << std::endl;
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    
    int counter = 0, max = 10;

    std::thread t1(client, std::ref(counter), max);
    std::thread t2(operationist, std::ref(counter));

    t1.join();
    t2.join();

    return 0;
}