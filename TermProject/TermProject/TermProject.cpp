#include<iostream>
#include<fstream>
#include<string>	
#include <vector>

using namespace std;

void myTermProject();
void addNewBookFunction();
void showbookrecordsfunction();
void checkavailabilityfunction();
void deletefunction();
void modifyfunction();
void modifyingfunc();
void deleteavailabilityfunc();

int main() {


    myTermProject();

}


void myTermProject()
{

    int operation;

    do {
        cout << "*********************************************" << endl;
        cout << "***************  WELCOME TO *****************" << endl;
        cout << "********* LIBRARY MANAGEMENT SYSTEM *********" << endl;
        cout << "*********************************************" << endl;
        cout << "*********************************************" << endl;

        cout << "Please select an operation to continue(0-5):" << endl;
        cout << "1) Add New Book" << endl;
        cout << "2) Show Book Record" << endl;
        cout << "3) Modify Book Record" << endl;
        cout << "4) Delete a Book Record" << endl;
        cout << "5) Check Availability" << endl;
        cout << "6) Delete Availability Records" << endl;

        cout << "0) Exit" << endl;

        cout << "Operation: ";
        cin >> operation;

        system("cls");


        if ((operation >= 1 && operation <= 6) || operation == 0)
        {

            if (operation == 1)
            {
                addNewBookFunction();

            }
            else if (operation == 2)
            {

                showbookrecordsfunction();
            }
            else if (operation == 3)
            {
                modifyfunction();
            }
            else if (operation == 4)
            {
                deletefunction();
            }
            else if (operation == 5)
            {
                checkavailabilityfunction();
            }
            else if (operation == 6)
            {
                deleteavailabilityfunc();
            }
            cout << "My selected operation is " << operation << endl << endl;
        }
        else {
            cout << "Please select a valid operation" << endl << endl;
        }


    } while (operation != 0);


}

int stock;
int booknumber;

void addNewBookFunction()
{
    string bookName;
    string authorName;

    

    cout << "Please provide the following details for the new book:" << endl;
    cout << "Book Name: ";

    cin.ignore();
    getline(cin, bookName);

    cout << "Author Name: ";
    getline(cin, authorName);




    cout << "Stock: ";
    cin >> stock;


    ofstream out;
    out.open("termproject.txt", fstream::app);

    out << bookName << "\t\t" << authorName << "\t\t" << stock << "\t\t" << endl;

    out.close();

    if (stock > 0) {


        ofstream out;
        out.open("AvailableBooks.txt", fstream::app);

        out << bookName << "\t\t" << authorName << "\t\t" << stock << "\t\t" << "AVAILABLE" << "\t\t" << endl;

        out.close();
    }
    else if (stock <= 0) {
        ofstream out;
        out.open("AvailableBooks.txt", fstream::app);

        out << bookName << "\t\t" << authorName << "\t\t" << stock << "\t\t" << "UNAVAILABLE" << "\t\t" << endl;

        out.close();
    }
    system("cls");
    cout << "New book is already added to the database" << endl;

}



void showbookrecordsfunction() {

    vector<string> records;
    string line;
    ifstream records_input("termproject.txt"); 
    while (getline(records_input, line)) 
    {
        records.push_back(line);
    }

    records_input.close(); 
    size_t recno = records.size(); 

    cout << "These are the records" << endl;
    for (size_t i = 0; i < recno; ++i) 
    {
        cout << records[i] << endl;
    }

}


void checkavailabilityfunction() {

    vector<string> records;
    string line;
    ifstream records_input("AvailableBooks.txt"); 
    while (getline(records_input, line)) 
    {
        records.push_back(line);
    }

    records_input.close(); 
    size_t recno = records.size(); 


   
        cout << "These are the Available Books" << endl;

        
        for (size_t i = 0; i < recno; ++i) 
            {   
                
                cout << records[i] << endl;

            }
        
    


}

void deletefunction() {
    vector<string> records;
    string line;
    ifstream records_input("termproject.txt"); 
    while (getline(records_input, line)) 
    {
        records.push_back(line);
    }

    records_input.close(); 
    size_t recno = records.size(); 

    cout << "These are the records" << endl;
    for (size_t i = 0; i < recno; ++i) 
    {
        cout << i << ": " << records[i] << endl;
    }

    size_t recno1 = 0;
    cout << "Which record would you like to delete?" << endl;
    cin >> recno1; 

    if (recno1 < 0 || recno1 >= recno) 
    {
        cout << "Invalid choice" << endl;
    }
    else
    {

        cout << "You have chosen to delete record " << recno1 << ": " << records[recno1] << endl;
        records.erase(records.begin() + recno1); 
        recno = records.size(); 

        
    }

    ofstream records_output("termproject.txt"); 
    cout << "These are the records" << endl;
    for (size_t i = 0; i < recno; ++i) 
    {
        cout << i << ": " << records[i] << endl;
        records_output << records[i] << endl;
    }

    
    records_output.close(); 
   
    
}


   
void modifyfunction() {
    vector<string> records;
    string line;
    ifstream records_input("termproject.txt"); 
    while (getline(records_input, line)) 
    {
        records.push_back(line);
    }

    records_input.close(); 
    size_t recno = records.size(); 

    cout << "These are the records" << endl;
    for (size_t i = 0; i < recno; ++i) 
    {
        cout << i << ": " << records[i] << endl;
    }

    size_t recno1 = 0;
    cout << "Which record would you like to Modify?" << endl;
    cin >> recno1; 

    if (recno1 < 0 || recno1 >= recno) 
    {
        cout << "Invalid choice" << endl;

       
    }
    else
    {
        cout << "You have chosen to modify record " << recno1 << ": " << records[recno1] << endl;
        records.erase(records.begin() + recno1); 
        recno = records.size(); 
        
        
    }

 

   
    ofstream records_output("termproject.txt"); 
    modifyingfunc();
    cout << "These are the records" << endl;
    for (size_t i = 0; i < recno; ++i) 
    {
        cout << i << ": " << records[i] << endl;
        records_output << records[i] << endl;
    }


    records_output.close();

   
   

    

}

void modifyingfunc()
{
    string bookName;
    string authorName;



    cout << "Please provide the following details for the book:" << endl;
    cout << "Book Name: ";

    cin.ignore();
    getline(cin, bookName);

    cout << "Author Name: ";
    getline(cin, authorName);

    cout << "Stock: ";
    cin >> stock;


   


    ofstream out;
    out.open("termproject.txt");

    out << bookName << "\t\t" << authorName << "\t\t" << stock << "\t\t" << endl;

    out.close();



    system("cls");
    cout << "The book is already added to the database" << endl;

    if (stock > 0) {

        ofstream o;
        o.open("AvailableBooks.txt", fstream::app);

        o << bookName << "\t\t" << authorName << "\t\t" << stock << "\t\t" << "AVAILABLE" << "\t\t" << endl;

        o.close();
    }
    else if (stock <= 0) {

        ofstream o;
        o.open("AvailableBooks.txt", fstream::app);

        o << bookName << "\t\t" << authorName << "\t\t" << stock << "\t\t" << "UNAVAILABLE" << "\t\t" << endl;

        o.close();
    }

}

void deleteavailabilityfunc() {

    vector<string> records;
    string line;
   
    ifstream records_input("AvailableBooks.txt"); 
    while (getline(records_input, line)) 
    {
        records.push_back(line);
    }

    records_input.close(); 
    size_t recno = records.size(); 

    cout << "These are the records" << endl;
    for (size_t i = 0; i < recno; ++i) 
    {
        cout << i << ": " << records[i] << endl;
    }

    size_t recno1 = 0;
    cout << "Which record would you like to delete?" << endl;
    cin >> recno1; 
    
    if (recno1 < 0 || recno1 >= recno) 
    {
        cout << "Invalid choice" << endl;
    }
    else
    {

        cout << "You have chosen to delete record " << recno1 << ": " << records[recno1] << endl;
        records.erase(records.begin() + recno1); 
        recno = records.size(); 


    }

      
    ofstream records_output("AvailableBooks.txt"); 
    cout << "These are the records" << endl;
    for (size_t i = 0; i < recno; ++i) 
    {
        cout << i << ": " << records[i] << endl;
        records_output << records[i] << endl;
    }


    records_output.close();

}



