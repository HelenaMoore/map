#include <chrono>
#include <iostream>
#include <mutex>
#include <vector>
#include <Windows.h>

class consol_parameter
{
public:
    static void SetColor(int text, int background)
    {
        SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
    }
    static void SetPosition(int x, int y)
    {
        COORD point;
        point.X = x;
        point.Y = y;
        SetConsoleCursorPosition(hStdOut, point);
    }
private:
    static HANDLE hStdOut;
};
HANDLE consol_parameter::hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

class Timer
{
private:
    using clock_t = std::chrono::high_resolution_clock;
    using second_t = std::chrono::duration<double, std::ratio<1> >;

    std::string m_name;
    std::chrono::time_point<clock_t> m_beg;
    double elapsed() const
    {
        return std::chrono::duration_cast<second_t>(clock_t::now() - m_beg).count();
    }

public:
    Timer() : m_beg(clock_t::now()) { }
    Timer(std::string name) : m_name(name), m_beg(clock_t::now()) { }

    void start(std::string name) {
        m_name = name;
        m_beg = clock_t::now();
    }
    void print() const {
        std::cout << m_name << ":\t" << elapsed() * 1000 << " ms" << '\n';
    }
};

std::mutex m;

void progressBar(int length, int thread_number)
{
    std::unique_lock<std::mutex> l(m, std::defer_lock);
    Timer timer;
    int x = 0;
    consol_parameter parameter;
    int timeout = 1000 / (1 + thread_number) + (thread_number * 200);
    l.lock();
    parameter.SetPosition(0, thread_number * 3);
    std::cout << "Номер потока: " << thread_number + 1 << "; " << "Идентификатор потока: " << std::this_thread::get_id() << "; ";
    l.unlock();

    while (x < length)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(timeout));
        l.lock();
        ++x;
        parameter.SetPosition(x, (thread_number) * 3 + 1);
        std::cout << "|";
        l.unlock();
    }

    parameter.SetPosition(x+1, (thread_number) * 3 + 1);
    timer.print();
}

int main()
{
    setlocale(LC_ALL, "Russian");

    int length = 10, thread_number = 5;

    std::vector<std::thread> v_thread;
    for (int i = 0; i < thread_number; ++i)
    {
        v_thread.push_back(std::thread(progressBar, length, i));
    }

    for (auto& t : v_thread)
    {
        t.join();
    }

    std::cout << std::endl;

    return 0;
}