//
// Created by Toby Dragon on 10/24/16.
//

#ifndef LINKEDNODE_H
#define LINKEDNODE_H
#include<string>



class Book {

private:
    std::string title;
   // std::string author;
    int haveValue;
    int needValue;
    double price;
    Book* next;
    WaitList* waitList = new WaitList();


public:

    Book(std::string title, int have, int need, double price){
        this->title = title;
        this->haveValue = have;
        this->needValue = need;
        this->price = price;
        next = nullptr;
    }

    std::string getTitle(){
        return name;
    }

    void setTitle(std::string title){
        this.title = title;
    }

    int getHaveValue(){ return haveValue; }

    void changeHaveValue(int newValue){
        this->haveValue = newValue;
    }

    int getNeedValue(){ return needValue; }

    void changeNeedValue(int newValue){
        this->needValue = newValue;
    }

    void moreNeed(){ this->needValue++; }

    void addToWaitList(std::string nameToAdd){
        waitList->enqueue(nameToAdd);
    }

    void updatePrice(double newPrice){
        this->price = newPrice;
    }

    void sellBook(int amount){
        if(haveValue > amount){
            haveValue-=amount;
        } else {
            needValue += amount-haveValue;
            int need = amount-haveValue;
            haveValue = 0;
            std::string nameToAdd = std::cin << "Enter a name to add to Wait List: " << std::endl;
            for(int i = 0; i < need; i++){
                waitList->enqueue(nameToAdd);
            }

        }
    }

    Book* getNext(){
        return next;
    }

    void setNext(LinkedNode* newNext){
        next = newNext;
    }

    void getOrder(int newAmount){
        while(!waitList->isEmpty()){
            std::cout << waitList->dequeue() + this->name;
            newAmount--;
        }
        have = newAmount;
        needValue = 0;
    }

    void toString(){
        std::cout << title +  " " + haveValue + " " + price + " " + needValue <<std::endl;
    }


};


#endif //LINKEDNODE_H
