//
// Created by Toby Dragon on 10/21/16.
//

#ifndef STACKSANDQUEUES_ARRAYQUEUE_H
#define STACKSANDQUEUES_ARRAYQUEUE_H

#include "Queue.h"
#include<string>

class WaitList : public Queue {

private:
    std::string* array;
    int currCapacity;
    int currItemCount;
    bool active;
    int totalLinesRun;

public:
    WaitList();
    ~WaitList();

    void enqueue(std::string item);
    std::string dequeue();
    bool isEmpty();

    long getTotalLinesRun();
    void resetTotalLinesRun();
    int calcSizeOf();

    void printList();

    bool isActive();

    std::string list();
};

#endif //STACKSANDQUEUES_ARRAYQUEUE_H
