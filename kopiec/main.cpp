#include <iostream>

#include "heap_test.h"
#include "kopiec.h"
#include <ctime>

int main(void){
    srand(time(NULL));
    Heap<int> h1(0);    // kopiec minimalny
    test_insert(h1);
    std::cout<<"\n";
    std::cout<<"-=-=-==-=-=-=-=-=-=-=-=\n";
    //test_pop(h1);
    //h1.writeOut();
    h1.pop();
    std::cout<<"\n\n";
    h1.writeOut();
    h1.pop();
    std::cout<<"\n\n";
    h1.writeOut();
    h1.pop();
    std::cout<<"\n\n";
    h1.writeOut();
    h1.pop();
    while(h1.getSize()>0){
        std::cout<<"\n\n";
        h1.writeOut();
        h1.pop();
    }
    h1.pop();
    h1.pop();
    h1.writeOut();
    return 0;
}