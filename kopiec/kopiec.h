#ifndef KOPIEC_H
#define KOPIEC_H

#include <iostream>
#include <vector>

template <typename ValueType>
class Heap{
private:
    std::vector<ValueType> heap;
    short heapType; // 0 - minimalny; 1 - maksymalny
    int size;


public:
    Heap(short heapT):
    heap(0),
    heapType(heapT),
    size(0)
    {

    }

    void push(ValueType element){
        heap.push_back(element);
        ++size;
        repair_heap_up(size-1);
    }

    int getSize(){
        return size;
    }

    ValueType pop(){
        if(size>0){
            std::swap(heap[0], heap[size - 1]);

            repair_heap_down(0);
            ValueType& popEl = heap[size-1];
            heap.erase(heap.end() - 1);
            --size;
            return popEl;
        }
    }

    void writeOut(){
        for(typename std::vector<ValueType>::iterator i = heap.begin(); i < heap.end(); ++i){
            std::cout<<*i<<" ";

        }
    }

private:
    void repair_heap_up(int k_el){
        if(if_swap(k_el, (k_el-1)/2)){
            std::swap(heap[k_el], heap[(k_el-1)/2]);
            return repair_heap_up((k_el-1)/2);
        }
    }

    void repair_heap_down(int k_el){
        short which = if_swap_right_or_left(k_el);
        if(which == 1){
            return repair_heap_down(2*k_el+1);
        }else if(which == 2){
            return repair_heap_down(2*k_el +2);
        }else return;
    }

    short if_swap_right_or_left(int k_el){
        if(!if_leaf(k_el)){
                short which = which_max_or_min(k_el);
                if(which == 1){
                    std::swap(heap[k_el], heap[2*k_el +1]);
                    return 1;
                }else if(which == 2){
                    std::swap(heap[k_el], heap[2*k_el +2] );
                    return 2;
                    
                }

        }
        return 0;
    }

    short which_max_or_min(int k_el){
        if(compare(heap[k_el], heap[2*k_el +1]) && compare(heap[k_el], heap[2*k_el+2])){  // rodzic spelnia warunek kopca
            return 0;
        }else if(compare(heap[2*k_el+1], heap[2*k_el +2])){ // niespelniony warunek kopca, lewe dziecko powinno zajac miejsce k_el
            return 1;
        }else return 2;     // prawe dziecko powinno zajac miejsce rodzica
    }

    bool have_left_child(int k){
        return 2*k+1<size;
    }

    bool have_right_child(int k){
        return 2*k+2<size;
    }

    bool compare(ValueType i, ValueType j){
        if(heapType == 0){
            return i<j;
        }else if (heapType == 1)
        {
            return i>j;
        }
        return true;
    }

    bool if_swap(int k_el, int child_k_el){
        if(heapType == 0 && heap[k_el] != heap[0]){
            return heap[k_el] < heap[child_k_el];
        }
        if(heapType == 0 && heap[k_el] != heap[0]){
            return heap[k_el] > heap[child_k_el];
        }
    }

    bool if_leaf(int k_el){
        if(2*k_el + 2 > size) return true;
        return false;
    }


};

#endif