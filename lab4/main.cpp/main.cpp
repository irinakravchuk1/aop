#include <iostream>
#include <stdlib.h>
#include <ctime>

int main() {
    int arr[10][10];
    srand(static_cast<unsigned int>(time(0)));
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            arr[i][j] = rand() % 50;
            std::cout << arr[i][j] << ' ';
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    for (int i=0, k=9; i<5; ++i, k-=2)
    {
        for (int j=0; j<10; ++j)
        {
            arr[i+k][j]=arr[i][j];
        }
    }

    for (int i=0; i<10; ++i)
    {
        for (int j=0; j<10; ++j)
        {
            std::cout<<arr[i][j]<<' ';
        }
        std::cout<<std::endl;
    }
}