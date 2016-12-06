//
// Created by Toby Dragon on 9/30/16.
//

#ifndef FINALSOLN_BOOKSTORE_H
#define FINALSOLN_BOOKSTORE_H

#include <stdexcept>
#include<string>

//#include "List.h"
#include "Book.h"

class BookStore{
private:
    Book* start;
    Book* end;
    int capacity;
    long totalLinesRun;

public:
    //creates an empty LinkedList
    BookStore();

    //Destructor
    ~BookStore();

    bool compareBooks(std::string existing, std::string newBook);

    //inserts the new item into the list at the specified index
    //if the index is invalid (< 0 or > currItemCount), throws an out_of_range exception
    void add(std::string titleToAdd, int have, int want);

    //removes the item at index from the list, then returns a copy of that item
    //if the index is invalid, throws an out_of_range exception
    std::string remove(std::string title);

    //returns true if there are no valid items in the list, false otherwise
    bool isEmpty();

    //returns the number of valid items in the list
    int size();

    //makes the list entirely empty of valid items (does not change totalLinesRun)
    void clearList();

    //returns the index of the first occurrence of itemToFind in the list, or -1 if not present
    bool find(std::string itemToFind);

    Book* getBook(std::string title);

    //returns a string representing the given list in the exact format shown below
    // {1, 2, 3, 4, 5}
    void toString();

    //returns the total number of lines run by this object
    long getTotalLinesRun();

    //resets the value of totalLinesRun to 0
    void resetTotalLinesRun();

    //returns the minimum size of the object in bytes
    int calcSizeOf();

    void makeOrder();

    void returnBooks();

    void takeDelivery();

    void printToFile(std::string fileName);
    void addFromBookFile(std::string line);
    void addFromListFile(std::string line);
    void loadBookFile(std::string filename);
    void loadListFile(std::string filename);
};


#endif //LAB7SOLN_LINKEDLIST_H
