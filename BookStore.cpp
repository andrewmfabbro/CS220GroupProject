//
// Created by Eric Ghaly on 10/31/16.
//

#include <iostream>
#include "BookStore.h"
#include<string>



BookStore::BookStore() {
    this->capacity = 0;
    this->totalLinesRun = 1;
    this->start = nullptr;
    this->end = nullptr;
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

void BookStore::add(std::string titleToAdd, int have, int want) {
    if(find(titleToAdd)){
        std::cout << "This book is already in your bookstore!" << std::endl;
        return;
    }
    Book* bookToAdd = new Book(titleToAdd, have, want);
    if(capacity == 0){
        start = bookToAdd;
        capacity++;
    } else if(capacity == 1){
        if(compareBooks(start->getTitle(), titleToAdd)){
            end = start;
            start = bookToAdd;
            bookToAdd->setNext(end);
            capacity++;
        } else {
            start->setNext(bookToAdd);
            end = bookToAdd;
            capacity++;
        }
    } else {
        Book* currBook = start;
        Book* oldBook = currBook->getNext();
        for(int i = 0; i < capacity; i++){
            if(compareBooks(currBook->getTitle(), titleToAdd)){
                bookToAdd->setNext(currBook);
                oldBook->setNext(bookToAdd);
                capacity+=1;
                return;
            } else {
                oldBook = currBook;
                currBook = currBook->getNext();
            }
        }
        end->setNext(bookToAdd);
        end = bookToAdd;
        capacity+=1;
    }
}

std::string BookStore::remove(std::string title){
    if(capacity == 0) {
        return "There are currently no books to remove!";
    }
    else if(capacity == 1){
        if(start->getTitle() == title){
            std::string deletedTitle = start->getTitle();
            delete start;
            start = nullptr;
            capacity--;
            return deletedTitle;
        } else {
            return title + " is not in your bookstore!";
        }
    } else if(capacity == 2){
        if(start->getTitle() == title){
            std::string deletedTitle = start->getTitle();
            delete start;
            start = end;
            end = nullptr;
            capacity--;
            return deletedTitle;
        } else if(end->getTitle() == title){
            std::string deletedTitle = end->getTitle();
            delete end;
            end = nullptr;
            start->setNext(nullptr);
            capacity--;
            return deletedTitle;
        } else {
            return title + " is not in your bookstore!";
        }
    } else {
        if(start->getTitle() == title){
            Book* nextBook = start->getNext();
            std::string deletedTitle = start->getTitle();
            delete start;
            start = nextBook;
            capacity--;
            return deletedTitle;
        }
        Book* prevBook = start;
        Book* currBook = prevBook->getNext();
        Book* nextBook = currBook->getNext();
        std::string deletedTitle = title + " is not in your bookstore!";
        for(int i = 0; i < capacity; i++){
            if(currBook->getTitle() == title){
                deletedTitle = currBook->getTitle();
                delete currBook;
                prevBook->setNext(nextBook);
                capacity--;
                return deletedTitle;
            } else {
                prevBook = currBook;
                currBook = nextBook;
                nextBook = nextBook->getNext();
            }
        }
        return deletedTitle;
    }
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

void BookStore::toString(){
//    std::cout << capacity << std::endl;
    Book* bookToPrint = start;
    for(int i = 0; i < capacity; i++){
        bookToPrint->toString();
        bookToPrint = bookToPrint->getNext();
    }
}

bool BookStore::find(std::string itemToFind) {
    bool bookFound = false;
    Book* bookToSearch = start;
    totalLinesRun+=4;
    for(int i = 0; i < capacity; i++){
        totalLinesRun+=3;
        if(bookToSearch->getTitle() == itemToFind){
            totalLinesRun+=2;
            bookFound = true;
            return bookFound;
        }
        bookToSearch = bookToSearch->getNext();
    }
    totalLinesRun+=1;
    return bookFound;
}

Book* BookStore::getBook(std::string title){
    Book* bookToSearch = start;
    for(int i = 0; i < capacity; i++){
        if(bookToSearch->getTitle() == title){
            return bookToSearch;
        } else {
            bookToSearch = bookToSearch->getNext();
        }
    }
    std::cout << "The requested title is not in your bookstore!" << std::endl;
    return nullptr;
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


/*int main(){
    BookStore* newStore = new BookStore();

    newStore->add("c",10,0);
    newStore->add("a",10,0);
    newStore->add("g",10,0);
    newStore->add("d",10,0);
    newStore->add("f",10,0);
    newStore->add("e",10,0);
    newStore->add("b",10,0);
    newStore->add("i",10,0);
    newStore->add("h",10,0);
    newStore->add("j",10,0);
    newStore->add("k",10,0);


   // std::cout << newStore->remove("a") << std::endl;
    newStore->remove("k");
    newStore->toString();

    printf("\n");
    std::cout<< newStore->find("w") << std::endl;
    std::cout<< newStore->find("c") << std::endl;


}*/



