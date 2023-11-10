#include <iostream>
#include<ctime>

using namespace std;

class StopWatch
{
private:
    clock_t start_time;
    clock_t elapsed_time;
    bool running;

public:
    StopWatch()
    {
        start_time = 0;
        elapsed_time = 0;
        running = false;
    }

    void start()
    {
        if (!running)
        {
            start_time = clock() - elapsed_time;
            running = true;
        }
    }

    void stop()
    {
        if (running)
        {
            elapsed_time = clock() - start_time;
            running = false;
        }
    }

    void show()
    {
        if (running)
        {
            clock_t current_time = clock() - start_time;
            std::cout << "Gecen Sure: " << static_cast<double>(current_time) / CLOCKS_PER_SEC << " saniye\n";
        }
        else
        {
            std::cout << "Gecen Sure: " << static_cast<double>(elapsed_time) / CLOCKS_PER_SEC << " saniye\n";
        }
    }

    ~StopWatch()
    {
        std::cout << "Kronometre kapandi." << std::endl;
        show();
    }
};



int main()
{
    std::cout << "Kronometreye hos geldiniz." << std::endl;
    StopWatch sw;
    std::cout << "Kronometreyi baslatmak icin 's' durdurmak icin 'p' zamani gostermek icin 'h' cikmak icin 'q' ya basiniz" << std::endl;

    char choose = 'a';

    while(choose != 'q'){

    std::cin >> choose;    
    
    switch (choose)
    {
    case 's':
        sw.start();
        break;
    case 'p':
        sw.stop();
        break;
    case 'h':
        sw.show();
        break;
    case 'q':
        continue;    
    default:
        std::cout << "Hatali tuslama lutfen tekrar dene" << std::endl;
    }

    }
}