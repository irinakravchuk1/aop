#include <iostream>
#include <stdlib.h>
#include <ctime>

int main() {
    int arr [10][10];
    srand(static_cast<unsigned int>(time(0)));
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            arr[i][j] = rand() % 50;
            std::cout << arr[i][j] << ' ';
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    int arr_new [10][10];

    for (int i=0; i<10; ++i)
    {
        for (int j=0; j<10; ++j)
        {
            arr_new[j][9-i]=arr[i][j];
        }
    }

    for (int i=0; i<10; ++i)
    {
        for (int j=0; j<10; ++j)
        {
            std::cout<<arr_new[i][j]<<' ';
        }
        std::cout<<std::endl;
    }


}
