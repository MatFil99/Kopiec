#ifndef HEAP_TEST_H
#define HEAP_TEST_H
#include "kopiec.h"

template <typename ValueType>
void test_insert(Heap<ValueType>& heap_Test){
    unsigned long int randNumb =0;
    for(int i = 0; i< 20; ++i){
        randNumb = rand()%100;
        heap_Test.push(randNumb);
    }
    heap_Test.writeOut();
}

template <typename ValueType>
void test_pop(Heap<ValueType>& heap_Test){
    for(int i = 0; i< 10; ++i){
        int popEl = heap_Test.pop();
        std::cout<<"Usunieto:\t"<<popEl<<"\n_  _  _  _  _  _  _  _\n";
        heap_Test.writeOut();
        std::cout<<std::endl<<std::endl;
    }
}

#endif //