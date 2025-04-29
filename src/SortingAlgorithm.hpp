#pragma once

#include <iostream>
#include <vector>

using namespace std;

namespace SortLibrary {

    template<typename T>
    concept Sortable = requires(T& t) {
        {t < t} -> std::convertible_to<bool>;
    };
    

    template<Sortable T>
    void BubbleSort(std::vector<T>& v)
    {
        const unsigned int n = v.size();

        for(unsigned int i = 0; i <= n - 2; i++){
            for(unsigned int j = i + 1; j <= n - 1; j++){
                if(v[j] < v[i]){
                    std::swap(v[i], v[j]);
                }
            }
        }
    }
    

    template<typename T>
    void heapify(std::vector<T>& v, int n, int i){

        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && v[left] > v[largest]){
            largest = left;
        }

        if (right < n && v[right] > v[largest]){
            largest = right;
        }

        if (largest != i){
            std::swap(v[i], v[largest]);
            heapify(v, n, largest);
        }
    }


    template<typename T>
    void HeapSort(std::vector<T>& v){

        const unsigned int n = v.size();

        for (int i = n / 2; i >= 0; --i){
            heapify(v, n, i);
        }

        for (int i = n - 1; i > 0; --i){
            std::swap(v[0], v[i]);
            heapify(v, i, 0);
        }
    }
}
    