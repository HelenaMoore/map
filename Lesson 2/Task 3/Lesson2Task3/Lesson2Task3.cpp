#include <iostream>
#include <mutex>
#include <thread>

class Data
{
public:
    int x = 0;
    Data(int x) : x(x) {}
    std::mutex m;
};

void lockSwap(Data& d1, Data& d2)
{
    lock(d1.m, d2.m);
    std::lock_guard<std::mutex> lgrd_d1(d1.m, std::adopt_lock);
    std::lock_guard<std::mutex> lgrd_d2(d2.m, std::adopt_lock);
    Data temp(0);
    temp.x = d1.x;
    d1.x = d2.x;
    d2.x = temp.x;
}

void scopedLockSwap(Data& d1, Data& d2)
{
    std::scoped_lock scl(d1.m, d2.m); 
    Data temp(0);
    temp.x = d1.x;
    d1.x = d2.x;
    d2.x = temp.x;
}

void uniqueLockSwap(Data& d1, Data& d2)
{
    std::unique_lock<std::mutex> unl_d1(d1.m, std::defer_lock);
    std::unique_lock<std::mutex> unl_d2(d2.m, std::defer_lock);
    std::lock(unl_d1, unl_d2);
    Data temp(0);
    temp.x = d1.x;
    d1.x = d2.x;
    d2.x = temp.x;
}

int main()
{
    Data d1(5);
    Data d2(8);

    std::cout << "Before swap: " << d1.x << " " << d2.x << std::endl;

    lockSwap(d1, d2);
    std::cout << "After lock swap: " << d1.x << " " << d2.x << std::endl;

    scopedLockSwap(d1, d2);
    std::cout << "After scoped_lock swap: " << d1.x << " " << d2.x << std::endl;
    
    uniqueLockSwap(d1, d2);
    std::cout << "After unique_lock swap: " << d1.x << " " << d2.x << std::endl;

    return 0;
}
