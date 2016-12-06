//
// Created by Toby Dragon on 10/21/16.
//

#include <iostream>
#include "WaitList.h"

WaitList::WaitList(){
    currCapacity = 20;
    array;
    currItemCount=0;
    totalLinesRun=3;
    active = false;
}

WaitList::~WaitList(){
    delete[] array;
    active = false;
}

void WaitList::enqueue(std::string item){
    if(!active){
        array = new std::string[currCapacity];
        active = true;
    }
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
    if(isEmpty()){
        delete array;
    }
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

void WaitList::printList(){
    for(int i = 0; i < currItemCount; i++){
        std::cout << *(array+i) << std::endl;
    }
}

bool WaitList::isActive(){
    return active;
}

std::string WaitList::list(){
    std::string stringToReturn;
    for(int i = 0; i < currItemCount; i++){
        stringToReturn += ("," + *(array+i));
    }
    return stringToReturn;
}
