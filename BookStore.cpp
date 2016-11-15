//
// Created by Eric Ghaly on 10/31/16.
//

#include <iostream>
#include "BookStore.h"
#include<string>



BookStore::BookStore() {
    this->capacity = 0;
    this->totalLinesRun = 1;
}

BookStore::~BookStore() {
    clearList();
}

bool BookStore::compareBooks(std::string existing, std::string newBook){
    //existing.toLower();
    //newBook.tolower();
    long el = existing.length();
    long nl = newBook.length();
    long cl = 0;
    if(el > nl){
        cl = nl;
    } else {
        cl = el;
    }
    for(int i = 0; i <= cl; i++){
        if(existing[i] > newBook[i]){
            return true;
        } else if(existing[i] < newBook[i]){
            return false;
        }
    }
    return false;
}

void BookStore::add(int itemToAdd, int index) {
    //TODO: add add function
}

std::string BookStore::remove(std::string title){
    //TODO: add remove function
}

bool BookStore::isEmpty() {
    if(capacity > 0){
        totalLinesRun+=2;
        return false;
    } else {
        totalLinesRun+=2;
        return true;
    }
}

int BookStore::size() {
    totalLinesRun+=1;
    return capacity;
}

void BookStore::clearList() {
    Book* currNode = start;
    totalLinesRun+=3;
    while(currNode != nullptr) {
        Book *toDelete = currNode;
        currNode = currNode->getNext();
        delete toDelete;
        totalLinesRun+=4;
    }
    capacity = 0;
}

std::string BookStore::toString(){
    return "no";
}

void BookStore::find(std::string itemToFind) {
    std::string indexToFind = "Book Not Found!";
    Book* nodeToSearch = start;
    totalLinesRun+=4;
    for(int i = 0; i < capacity; i++){
        totalLinesRun+=3;
        if(nodeToSearch->getTitle() == itemToFind){
            indexToFind = i;
            totalLinesRun+=2;
            nodeToSearch->toString();
            i = capacity;
        }
        nodeToSearch = nodeToSearch->getNext();
    }
    totalLinesRun+=1;
    std::cout << indexToFind << std::endl;
}


long BookStore::getTotalLinesRun() { return totalLinesRun; }

void BookStore::resetTotalLinesRun() { totalLinesRun = 0; }

int BookStore::calcSizeOf() {
    return (sizeof(Book)*size());
}

void BookStore::makeOrder(){

}

void BookStore::takeDelivery(){

}

void BookStore::returnBooks(){

}



