#include <iostream>
#include <vector>
#include <ctime>
#include <stdlib.h>
//#include <algorithm>

void vector_sort(std::vector<int*> &v)
{
    for (int i=0; i<v.size()-1; ++i)
    {
        for(int j=v.size()-1; j>i; --j ) {
            if (*v[j] < *v[j - 1]) {
                std::swap(v[j], v[j - 1]);
            }
        }
    }
}

int main() {
    int arr[200];
    srand(static_cast<unsigned int>(time(0)));
    for (int i=0; i<200; ++i)
    {
        arr[i]=rand()%200 - 100;
        std::cout<<arr[i]<<' ';
    }
    std::cout<<std::endl;

    std::vector<int*> var;
    for (int i=0, j=1; i<199; ++i) {
        if (arr[i] >= 0 && arr[i + j] >= 0) {
            var.push_back(&arr[i]);
            while (arr[i + j] >= 0 && i + j < 200) {
                var.push_back(&arr[i + j]);
                ++j;
            }

            int ave = 0;
            for (int k = 0; k < j; ++k) {
                ave += *var[k];
            }
            ave/=j;
            //std::sort(*var.begin(), *var.end());
            vector_sort(var);
            *var[0]=ave;
            *var[j-1]=ave;
            var.clear();
            i+=j;
            j=1;
        }
    }

    for (int i=0; i<200; ++i)
    {
        std::cout<<arr[i]<<' ';
    }
}
