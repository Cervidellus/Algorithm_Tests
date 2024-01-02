#ifndef SELECTION_SORT
#define SELECTION_SORT

#include <vector>

namespace mySorts{

         template <typename T> 
     int selectSmallestIndex(std::vector<T> values){
        int smallestIndex = 0;
        
        //can skip first index
        for(int i = 1; i < values.size(); i++){
            if (values[i] < values[smallestIndex]) smallestIndex = i;
        }

        return smallestIndex;
    }

    template <typename T> 
    std::vector<T> selectionSort(std::vector<T> unSorted){
        std::vector<T> sortedValues(unSorted.size());

        for (T sortedValue : sortedValues){
            int smallest = selectSmallestIndex(unSorted);
            sortedValue = unSorted.at(smallest);
            unSorted.erase(unSorted.begin() + smallest);
        }

        return sortedValues;
    }

}

#endif