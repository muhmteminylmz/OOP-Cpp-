#include <iostream>
#include <ctime>

class Kronometre
{
private:
    clock_t start_time;
    clock_t elapsed_time;
    bool running;

public:
    Kronometre()
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
            std::cout << "Geçen Süre: " << static_cast<double>(current_time) / CLOCKS_PER_SEC << " saniye\n";
        }
        else
        {
            std::cout << "Geçen Süre: " << static_cast<double>(elapsed_time) / CLOCKS_PER_SEC << " saniye\n";
        }
    }
};

int main()
{
    Kronometre kronometre;

    while (true)
    {
        std::cout << "Kronometre Uygulaması" << std::endl;
        std::cout << "1. Baslat" << std::endl;
        std::cout << "2. Durdur" << std::endl;
        std::cout << "3. Goster" << std::endl;
        std::cout << "4. Cıkıs" << std::endl;

        int secim;
        std::cin >> secim;

        switch (secim)
        {
        case 1:
            kronometre.start();
            std::cout << "Kronometre başlatıldı." << std::endl;
            break;
        case 2:
            kronometre.stop();
            std::cout << "Kronometre durduruldu." << std::endl;
            break;
        case 3:
            kronometre.show();
            break;
        case 4:
            return 0;
        default:
            std::cout << "Geçersiz seçim. Lütfen tekrar deneyin." << std::endl;
        }
    }

    return 0;
}
