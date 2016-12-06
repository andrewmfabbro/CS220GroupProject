#include <iostream>
#include<string>
#include "BookStore.h"

BookStore* myStore = new BookStore();

bool interface = true;

void inquire(std::string title);
void add(std::string title);
void sell(std::string title);
void modify(std::string title);

void help() { //summary of all available commands
    std::cout << std::endl;
    std::cout << "Tutorial:" << std::endl;
    std::cout << "Press the 'I' key for information on a book." << std::endl;
    std::cout << "Press the 'L' key for a list of books in the inventory." << std::endl;
    std::cout << "Press the 'A' key to add a book to the inventory." << std::endl;
    std::cout << "Press the 'M' key to modify the demand for a book." << std::endl;
    std::cout << "Press the 'S' key to sell a book, or otherwise decrease inventory." << std::endl;
    std::cout << "Press the 'O' key to create a bulk purchase order." << std::endl;
    std::cout << "Press the 'D' key to input delivery information to the inventory." << std::endl;
    std::cout << "Press the 'R' key to write a return invoice." << std::endl;
    std::cout << "Press the 'H' key for help." << std::endl;
    std::cout << "Press the 'Q' key to quit program & save." << std::endl;
    std::cout << std::endl;
}

void inquire(){
    std::string title;
    std::cout << "What title would you like to inquire about? ";
    getline(std::cin, title);
    inquire(title);
}

void inquire(std::string title) { //display information on a certain title
    Book* bookToInquire = myStore->getBook(title);
    bookToInquire->toString();
}
void list(){ //list all titles
    myStore->toString();
}

void add(){
    std::string title;
    std::cout << "What title would you like to add? ";
    getline(std::cin, title);
    add(title);
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

void modify(){
    std::string title;
    std::cout << "What title would you like to modify? ";
    getline(std::cin, title);
    modify(title);
}

void modify(std::string title) { //modify the want values
    Book* bookToModify = myStore->getBook(title);
    int newWant;
    std::cout << "Current Have: " << bookToModify->getHaveValue() << " Current Want: " << bookToModify->getNeedValue() << std::endl;
    std::cout << "Enter a new Want Value: ";

    std::cin >> newWant;
    bookToModify->changeNeedValue(newWant);
}

void sell(){
    std::string title;
    std::cout << "What title would you like to sell? ";
    getline(std::cin, title);
    sell(title);
}

void sell(std::string title) { //decrease count for title by 1
    Book* bookToSell = myStore->getBook(title);
    bookToSell->sellBook(1);

}
void order(){} //purchase more books

void delivery(){} //read from file, then add books from file to store

void invoice(){} //return books, make have value match want value

void quit(){
    //TODO: add file save
    interface = false;
}



void Interface(){
    std::cout << "Welcome to the CS220 Library." << std::endl;
    std::cout << "Please enter a command. Enter H for help." << std::endl;

    std::string input = ""; //our input variable

    char myChar  = {0};
    while(true) {
        std::cout << "Please enter a 1 character command: ";
        getline(std::cin, input);

        if (input.length() == 1) {
            myChar = input[0];
            break;
        } else {
            std::cout << "Invalid character, please try again" << std::endl;
        }
    }
    std::cout << "You entered: " << myChar << std::endl << std::endl;

    if(input=="H"||input=="h"){
        //list available commands
        help();
    }else if(input=="I"||input=="i"){
        //display info on a title
        inquire();
    }else if(input=="L"||input=="l"){
        //list titles
        list();
    }else if(input=="A"||input=="a"){
        //add a title
        add();
    }else if(input=="M"||input=="m"){
        //change the want value
        modify();
    }else if(input=="S"||input=="s"){
        sell();
    }else if(input=="O"||input=="o"){
        order();
    }else if(input=="D"||input=="d"){
        delivery();
    }else if(input=="R"||input=="r"){
        invoice();
    }else if(input=="Q"||input=="q"){
        quit();
    }else{
        std::cout << "Invalid command, please try another." << std::endl;
    }

}




int main() {

    while(interface){
        Interface();
    }

   return 0;
}
