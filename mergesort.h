#ifndef MERGE_SORT
#define MERGE_SORT

#include <vector>

namespace mySorts{
    template <typename T> std::vector<T> merge(
        std::vector<T> leftValues,
        std::vector<T> rightValues)
        {
        std::vector<T> mergedValues(leftValues.size() + rightValues.size());
        auto leftIterator = leftValues.begin();
        auto rightIterator = rightValues.begin();
        auto mergedIterator = mergedValues.begin();

        while(leftIterator!= leftValues.end() && rightIterator != rightValues.end()){
                bool comparison = *leftIterator <= *rightIterator;
                *mergedIterator = comparison ? *leftIterator : *rightIterator;
                comparison ? leftIterator++ : rightIterator++;  
                mergedIterator++;
        }

        while(leftIterator != leftValues.end()){
            *mergedIterator = *leftIterator;
            mergedIterator++;
            leftIterator++;
        }

        while(rightIterator != rightValues.end()){
            *mergedIterator = *rightIterator;
            mergedIterator++;
            rightIterator++;
        }

        return mergedValues;
        }

    template <typename T> std::vector<T> mergeSort(std::vector<T> values){
        int valuesSize = values.size();

        if(valuesSize <=1) return values;

        int middleIndex = valuesSize/2;
        
        std::vector<T> leftValues(values.begin(), values.begin()+middleIndex);
        std::vector<T> rightValues(values.begin()+middleIndex, values.end());

        return merge(mergeSort(leftValues), mergeSort(rightValues));
    }
}

#endif 