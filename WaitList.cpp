//
// Created by Toby Dragon on 10/21/16.
//

#include "WaitList.h"


WaitList::WaitList(){
    currCapacity = 20;
    array = new std::string[currCapacity];
    currItemCount=0;
    totalLinesRun=3;
}

WaitList::~WaitList(){
    delete[] array;
}

void WaitList::enqueue(std::string item){
    array[currItemCount] = item;
    currItemCount++;
    totalLinesRun+=2;
}

std::string WaitList::dequeue(){
    std::string item = array[0];
    totalLinesRun+=3;
    for (int i=0; i<currItemCount-1; i++){
        totalLinesRun+=3;
        array[i]=array[i+1];
    }
    currItemCount--;
    totalLinesRun+=2;
    return item;
}

bool WaitList::isEmpty(){
    totalLinesRun++;
    return currItemCount == 0;
}

long WaitList::getTotalLinesRun() {
    return totalLinesRun;
}

void WaitList::resetTotalLinesRun() {
    totalLinesRun=0;
}

int WaitList::calcSizeOf() {
    return sizeof(array) + (sizeof(*array)*currCapacity) + sizeof(currCapacity) + sizeof(currItemCount);
}
