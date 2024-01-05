#include <iostream>
#include <vector>
#include <algorithm>

void tumCiftlesemeler(std::vector<int>& dizi, std::vector<std::vector<int>>& tumCiftlesemelerVec, int index = 0) {
    if (index == dizi.size() - 1) {
        if (dizi[0] == 0) {
            for (int eleman : dizi) {
                std::cout << eleman << " ";
            }
            std::cout << std::endl;

            // 2D vektöre ekle
            tumCiftlesemelerVec.push_back(dizi);
        }
        return;
    }

    // Dizideki her bir eleman için tekrar et
    for (int i = index; i < dizi.size(); ++i) {
        // Swap işlemi yapmadan önce, aynı elemanın dizide başka bir yere gelmediğinden emin ol
        if (std::find(dizi.begin() + index, dizi.begin() + i, dizi[i]) == dizi.begin() + i) {
            std::swap(dizi[index], dizi[i]);
            tumCiftlesemeler(dizi, tumCiftlesemelerVec, index + 1);
            std::swap(dizi[index], dizi[i]);  // Backtrack
        }
    }
}

int main() {
    // Örnek bir dizi
    std::vector<int> dizi = {0, 1, 2, 3, 4, 5};

    // Tüm mümkün çiftleşmeleri bul ve 2D vektöre at
    std::vector<std::vector<int>> a;
    tumCiftlesemeler(dizi, a);

    // 2D vektörü yazdır
    for (const auto& ciftleseme : a) {
        for (int eleman : ciftleseme) {
            std::cout << eleman << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
