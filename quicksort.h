#ifndef MY_QUICK_SORT
#define MY_QUICK_SORT

// #include <iostream>
#include <utility>
#include <vector>

namespace mySorts{
    //I want to pass in a std::vector, but work on the underlying data so I need a wrapper function.

    //The meat of teh function partions the data into above and below the pivot. 

    //The implementation method takes a pointer to a c-style array, a pointer to the start of the subarray, 
    //and a pointer to the end of the subbarray. 
    //It selects a pivot, which at first I will do by just grabbing hte rightmost value.
    //It has two iterators.. 
    //one for comparing each value to the pivot. 
    //A second for determining teh last value that was less than the pivot.
    //If less than the pivot, we do nothing.
    //If greater than the pivot...

    // std::vector<int> quickSort(const std::vector<int> unsorted){
    //     std::vector<int> working = unsorted;
    //     const int* unsortedData = unsorted.data();
    //     arrayQuickSort(const int* data, unsorted.size(), )

    //     return working;
    // }

    int quickSortPartition(int* data, const int startIndex, const int finishIndex){
        int smallerIndex = startIndex -1;
        int pivot = data[finishIndex];

        for (int i = startIndex; i < finishIndex; i++){
            // std::cout << "comparing " << data[i] << " with pivot " << pivot << "\n";
            if(data[i] < pivot){
                smallerIndex++;
                std::swap(data[i], data[smallerIndex]);
            }
        }

        // std::cout << "after finding pivot location\n";
        // for (int i = 0; i < finishIndex - startIndex + 1; i++){
        //     std::cout << data[i] << std::endl;
        // }

        std::swap(data[finishIndex], data[smallerIndex+1]);

        // std::cout << "after swapping pivot\n";
        // for (int i = 0; i < finishIndex - startIndex + 1; i++){
        //     std::cout << data[i] << std::endl;
        // }

        return smallerIndex+1;//pivot location
    }

    void arrayQuickSort(int* data, const int startIndex, const int finishIndex){
        // std::cout << "starting quicksort\n";
        // if(startIndex == finishIndex) return;//base condition
        // for (int i = startIndex; i <= finishIndex; i++){
        //     std::cout << data[i] << std::endl;
        // }

        //TODO wrong pivot index returned
        int newPivotIndex = quickSortPartition(data, startIndex, finishIndex);
        //print out the array for debugging

        // std::cout << "After partition\n";
        // for (int i = startIndex; i <= finishIndex; i++){
        //     std::cout << data[i] << std::endl;
        // }
        if(!(newPivotIndex <= startIndex+1))arrayQuickSort(data, startIndex, newPivotIndex -1);
        if(!(newPivotIndex >= finishIndex-1))arrayQuickSort(data, newPivotIndex+1, finishIndex);
    }
}

#endif