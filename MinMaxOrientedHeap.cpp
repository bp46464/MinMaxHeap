#include <iostream>
#include <string>
#include <ctime>
#include <time.h>
#include "binary_heap.h"
#include "max_binary_heap.h"

int main()
{
    srand(time(NULL));
    binary_heap<int>* bh = new binary_heap<int>();
    max_binary_heap<int>* mbh = new max_binary_heap<int>();

    
    int n = 10000000;
    for (int o = 1; o < 7; o++)
    {
        clock_t start = clock();
        for (int i = 0; i < n; i++)
        {
            int x = abs((rand() << 15 + rand()) % 90000000);
            //bh->insert(x);
            mbh->insert(x);
        }
        clock_t t1 = clock();
        std::cout << "Time:" << (float)(t1 - start) / (float)CLOCKS_PER_SEC << std::endl;
        std::cout << "Time for element:" << (float)(t1 - start) / (float)CLOCKS_PER_SEC / n << std::endl << std::endl;

        clock_t t2 = clock();
        for (int i = 0; i < n; i++)
        {
            int l;
            l = mbh->poll();
            //std::cout << l << std::endl;
        }
        clock_t t3 = clock();
        std::cout << "Time:" << (float)(t3 - t2) / (float)CLOCKS_PER_SEC << std::endl;
        std::cout << "Time for element:" << (float)(t3 - t2) / (float)CLOCKS_PER_SEC / n << std::endl;

        mbh->clear();
    }

    delete mbh;
    return 0;
}

