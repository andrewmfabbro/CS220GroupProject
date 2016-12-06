//
// Created by Toby Dragon on 10/24/16.
//

#ifndef LINKEDNODE_H
#define LINKEDNODE_H
#include<string>
#include "WaitList.h"
#include<iostream>



class Book {

private:
    std::string title;
   // std::string author;
    int haveValue;
    int wantValue;
    //double price;
    Book* next;
    WaitList* waitList = new WaitList();


public:

    Book(std::string title, int have, int need){
        this->title = title;
        this->haveValue = have;
        this->wantValue = need;
        //this->price = price;
        next = nullptr;
    }

    ~Book(){
        delete waitList;
    }

    std::string getTitle(){
        return title;
    }

    void setTitle(std::string title){
        title = title;
    }

    int getHaveValue(){ return haveValue; }

    void changeHaveValue(int newValue){
        this->haveValue = newValue;
    }

    int getNeedValue(){ return wantValue; }

    void changeNeedValue(int newValue){
        this->wantValue = newValue;
    }

    void moreNeed(){ this->wantValue++; }

    void addToWaitList(std::string nameToAdd){
        waitList->enqueue(nameToAdd);
    }

 /*   void updatePrice(double newPrice){
        this->price = newPrice;
    }*/

    void sellBook(int amount){
        if(haveValue >= amount){
            haveValue-=amount;
        } else {
            wantValue += amount-haveValue;
            int need = amount-haveValue;
            haveValue = 0;
            std::string nameToAdd;
            std::cout << "Enter a name to add to Wait List: ";
            std::cin >> nameToAdd;
            for(int i = 0; i < need; i++){
                waitList->enqueue(nameToAdd);
            }
            waitList->printList();

        }
    }

    Book* getNext(){
        return next;
    }

    void setNext(Book* newNext){
        next = newNext;
    }

    void getOrder(int newAmount){
        while(!waitList->isEmpty()){
            std::cout << waitList->dequeue() + this->title;
            newAmount--;
        }
        this->haveValue = newAmount;
        wantValue = 0;
    }

    void toString(){
        std::cout << "Title: " << title <<  " Have: " << haveValue << " Want: " << wantValue << std::endl;
        if(waitList->isActive()) {
            std::cout << "Wait List: " << std::endl;
            waitList->printList();
        }
    }

    std::string toFile(){
        std::string toFileString = title + "," + std::to_string(haveValue) + "," + std::to_string(wantValue);
        return toFileString;
    }

    bool hasWaitList(){
        return waitList->isActive();
    }

    std::string waitListToFile(){
        return title + waitList->list();
    }

};


#endif //LINKEDNODE_H
