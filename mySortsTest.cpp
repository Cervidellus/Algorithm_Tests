#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

#include "mergeSort.h"
#include "quicksort.h"
#include "scoped_timer.h"
#include "selectionSort.h"

using namespace std;

std::vector<int> randomIntVector(int length){
    std::vector<int> result(length);
    std::random_device randomDevice;
    std::mt19937 randomEngine(randomDevice());
    std::uniform_int_distribution<int> distribution_1_100(1, 100);

    for(auto it = result.begin(); it != result.end(); it++){
        *it = distribution_1_100(randomEngine);
    }
    std::cout << "Produced vector of size:" << result.size() << "\n";
    return result;
}

int main(){
    int vectorSize = 50000;
    auto myValues = randomIntVector(vectorSize);
    std::vector<int> newVector;
    
    // {
    //     ScopedTimer timer("Mergesort With Random Int");
    //     newVector = mySorts::mergeSort(myValues);
    // }

    // {
    //     ScopedTimer timer("SelectionSort");
    //     newVector = mySorts::selectionSort(myValues);
    // }
    
    {
        ScopedTimer timer("with std::sort");
        std::sort(myValues.begin(), myValues.end());
    }

    {
        ScopedTimer timer("QuickSort");
        newVector = myValues;
        mySorts::arrayQuickSort(newVector.data(), 0, newVector.size() -1);
    }
    // for (auto value : newVector){
    //         std::cout << value << "\n";
    // }
}