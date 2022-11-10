#include <iostream>
#include <ctime>
#include <stdlib.h>

int main() {
    int arr[100];
    srand(static_cast<unsigned int>(time(0)));
    for (int i=0; i<100; ++i)
    {
        arr[i]=rand()%100 - 50;
        std::cout<<arr[i]<<' ';
    }
    std::cout<<std::endl;

    int pair=0;
    for (int i=0; i<49; ++i)
    {
        if (arr[i]==arr[i+1])
        {
            ++pair;
        }
    }
    std::cout<<pair;
}
