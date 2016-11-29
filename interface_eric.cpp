#include <iostream>
#include<string>
#include "BookStore.h"

BookStore* myStore = new BookStore();

void help(); //summary of all available commands

void inquire(std::string title); //display information on a certain title

void list(){ //list all titles
    myStore->toString();
}

void add(std::string title) { //add a new title alphabetically
    int newWant;
    int newHave;
    std::cout << "Enter a Want Value: ";
    std::cin >> newWant;
    std::cout << "Enter a Have Value: ";
    std::cin >> newHave;
    myStore->add(title, newHave, newWant);
}

void modify(std::string title) { //modify the want values
    Book* bookToModify = myStore->getBook(title);
    int newWant;
    std::cout << "Current Have: " << bookToModify->getHaveValue() << " Current Want: " << bookToModify->getNeedValue() << std::endl;
    std::cout << "Enter a new Want Value: ";
    std::cin >> newWant;
    bookToModify->changeNeedValue(newWant);
}
void sell(std::string title) { //decrease count for title by 1
    Book* bookToSell = myStore->getBook(title);
    bookToSell->sellBook(1);

}
void order(); //purchase more books

void delivery();

void ret();

void quit();


int main() {

    add("a");
    modify("a");
    sell("a");
    sell("a");
    list();


   return 0;
}
