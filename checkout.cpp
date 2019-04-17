// Rushi Sharma
// Section #03
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "person.cpp"
#include "book.cpp"

using namespace std;

void printMenu() {
    cout << "----------Library Book Rental System----------" << endl;
    cout << "1.  Book checkout" << endl;
    cout << "2.  Book return" << endl;
    cout << "3.  View all available books" << endl;
    cout << "4.  View all outstanding rentals" << endl;
    cout << "5.  View outstanding rentals for a cardholder" << endl;
    cout << "6.  Open new library card" << endl;
    cout << "7.  Close library card" << endl;
    cout << "8.  Exit system" << endl;
    cout << "Please enter a choice: ";
}

void readBooks(vector<Book *> & myBooks) {

    string bookName, auth, cat;
    int id;
    string line;

    ifstream inFile;

    inFile.open("books.txt");

    if(inFile.is_open())
      {

        while(!inFile.eof())
        {

          getline(inFile, line);
          getline(inFile, bookName);
          getline(inFile, auth);
          getline(inFile, cat);
          getline(inFile, id);
          getline(inFile, line);

          Book * bPtr = nullptr;
          bPtr = new Book(bookName, auth, cat, id);
          myBooks.push_back(bPtr);

        }
      }

        inFile.close();
    return;
}


int readPersons(vector<Person *> & myCardholders) {

    string fName, lName;
    int cardNo;
    bool act;
    string line;


    ifstream inFile;

    inFile.open("persons.txt");

    if(inFile.is_open())
      {

        while(!inFile.eof())
        {

          inFile >> fName;
          inFile >> lName;
          inFile >> cardNo;
          inFile >> act;
          getline(inFile, line);

          Person.pPtr = nullptr;
          pPtr = new Person(fName, lName, cardNo, act);
          myCardholders.push_back(pPtr);

          inFile >> fName;
        }
      }
        inFile.close();

    return myCardholders.back() -> getId();
}


void readRentals(vector<Book *> & myBooks, vector<Person *> myCardholders) {

    //string cursor;
    int cardID, bookID;

    ifstream inFile;

    inFile.open("rentals.txt");

    if(inFile.is_open())
      {

      while(!inFile.eof())
      {

          inFile >> cardID;
          inFile >> bookID;

          int m = myBooks.size();
          int n = myCardholders.size();

          for (int i = 0; i < m; i++)
            {

              if(myBooks.at(i) -> getId() == bookID)
              {
                myBooks.at(i) -> setPersonPtr(pPtr);
              }

            }

           for (int j = 0; j < n; j++)
              {

                if(myCardholders.at(j) -> getId() == cardID)
                {
                  myCardholders.at(j) -> setPersonPtr(pPtr);
                }

              }

        }

        }

    inFile.close();
    return;
}


void openCard(vector<Person *> & myCardholders, int nextID) {


    string fName, lName;
    int id;
    int size = myCardholders.size();
    ofstream inFile;
    inFile.open("persons.txt");

      if(inFile.is_open())
      {
        while (id > size)
        {
          PERSON person;
          person.fName = firstName;
          person.lName = lastName;
          nextID = size + 1;
          person.cardNo = cardID;
          myCardholders.push_back(person);
        }


        inFile.close();
      }
    return;
}



/*Book * searchBook(vector<Book *> myBooks, int id) {
    return nullptr;
}*/



int main()
{
    vector<Book *> books;
    vector<Person *> cardholders;

    int choice;
    do
    {
        // If you use cin anywhere, don't forget that you have to handle the <ENTER> key that
        // the user pressed when entering a menu option. This is still in the input stream.
        printMenu();
        cin >> choice;
        switch(choice)
        {
            case 1:
                // Book checkout
                break;

            case 2:
                // Book return
                break;

            case 3:
                // View all available books
                break;

            case 4:
                // View all outstanding rentals
                break;

            case 5:
                // View outstanding rentals for a cardholder
                break;

            case 6:
                // Open new library card
                openCard(cardholders, nextID);
                break;

            case 7:
                // Close library card
                break;

            case 8:
                // Must update records in files here before exiting the program
                break;

            default:
                cout << "Invalid entry" << endl;
                break;
        }
        cout << endl;
   } while(choice != 8);
      return 0;
}
