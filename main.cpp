#include <iostream>
BookStore* myStore = new BookStore();

void help(){
    std::cout<<std::endl;
    std::cout<<"Tutorial:"<<std::endl;
    std::cout<<"Press the 'I' key for information on a book."<<std::endl;
    std::cout<<"Press the 'L' key for a list of books in the inventory."<<std::endl;
    std::cout<<"Press the 'A' key to add a book to the inventory."<<std::endl;
    std::cout<<"Press the 'M' key to modify the demand for a book."<<std::endl;
    std::cout<<"Press the 'S' key to sell a book, or otherwise decrease inventory."<<std::endl;
    std::cout<<"Press the 'O' key to create a bulk purchase order."<<std::endl;
    std::cout<<"Press the 'D' key to input delivery information to the inventory."<<std::endl;
    std::cout<<"Press the 'R' key to write a return invoice."<<std::endl;
    std::cout<<"Press the 'H' key for help."<<std::endl;
    std::cout<<"Press the 'Q' key to quit program & save."<<std::endl;
    std::cout<<std::endl;
}


void inquire(std::string title){
    //std::cout<<"title, haveValue, price, needValue:"<<std::endl;
    myStore->find(title);
}

void list(){
    myStore->toString();
}

void add(std::string title){}

void modify(std::string title){}

void sell(std::string title){}

void order(/*filename*/){}

void delivery(/*filename*/){}

void invoice (/*filename*/){}

void quit(){}

void takeInput(){
    std::cout<<"Enter a command"<<std::endl;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
