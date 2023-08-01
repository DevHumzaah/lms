#include <iostream>
#include <string>
#include<cstdlib>
using namespace std;

struct Book
{

    string bookName;
    string authorName;
    int bookId;
    int noOfCopies;

    struct Book *next;
};
struct Book *BookHead = 0;

struct Student
{

    string studentName;
    int studentId;

    string borrowedBookName;
    int borrowedBookid;

    struct Student *next;
};
struct Student *StudentHead = 0;


//Function to add a new Book in book linkedlist
void addBook(string bookName, string authorName, int bookId, int noOfCopies)
{

    struct Book *temp, *newBook;

    newBook = new Book();  //creating a new node

    (*newBook).authorName = authorName;
    (*newBook).bookName = bookName;
    (*newBook).bookId = bookId;
    (*newBook).noOfCopies = noOfCopies;
    (*newBook).next = 0;  //storing 0 in the next part of created node

    temp = BookHead;
    
 //if book linkedlist is empty
    if (BookHead == 0)  
    {

        BookHead = newBook;
    }

//if book list has some nodes available
    else
    {

        //traversing the list till last node
        while ((*temp).next != 0)
        {
            temp = (*temp).next;
        }
        (*temp).next = newBook;
    }
}


//Function to delete a specific book from book list
void deleteBook(int id)
{
    int flag = 0;
    struct Book *temp;
    temp = BookHead;
    
//if there is no node present in the list
    if (temp == 0)
    {
        cout << "Book List is not available\n";
    }
    
//    if bookid in the headnode become equal to the bookid that user want to delete
    else if ((*temp).bookId == id)
    {

        BookHead = (*temp).next;
        free(temp);
        cout << "Book is deleted successfully!!!\n";
        
        
    }
    else
    {
        struct Book *prev;
        prev = temp;
        temp = (*temp).next;
        
//        traversing the list till last node
        while (temp != 0)
        {

//        if bookid in temp node become equal to the bookid that user want to delete
            if ((*temp).bookId == id)
            {

                (*prev).next = (*temp).next;
                free(temp);
                
                flag = 1;
                break;
            }
            prev = temp;
            temp = (*temp).next;
        }


        if (flag == 1)
        {
            cout << "Book is deleted successfully!!!\n";
        }
        else if (flag == 0)
        {
            cout << "Book not found!!!\n";
        }
    }
}


//Function to modify a specific book
void modifyBook(int id)
{

    int flag = 0;
    struct Book *temp;
    temp = BookHead;

//If there is no node present in the list
    if (temp == 0)
    {
        cout << "Book List is not available\n";
    }
    
    
    else
    {
    	
//    	traversing the list till last node
        while (temp != 0)
        {


//      if bookid in temp node become equal to the book id that user want to modify 
            if ((*temp).bookId == id)
            {
            	
//            	modifying book data

                cout << "Enter Book Name:";
                fflush(stdin);
                getline(cin, (*temp).bookName);

                cout << "Enter Author Name:";
                fflush(stdin);
                getline(cin, (*temp).authorName);

                cout << "Enter no of Copies available:";
                cin >> (*temp).noOfCopies;

                flag = 1;
                break;
            }
            temp = (*temp).next;
        }

        if (flag == 1)
        {
            cout << "Book is modified successfully!!!\n";
        }
        else if (flag == 0)
        {
            cout << "Book not found!!!\n";
        }
    }
}


//Function to add a student in student list
void addStudent(string bookName, string studentName, int bookId, int studentId)
{

    struct Student *temp, *newStudent;

    newStudent = new Student();  //creating a new student node

    (*newStudent).studentName = studentName;
    (*newStudent).studentId = studentId;
    (*newStudent).borrowedBookName = bookName;
    (*newStudent).borrowedBookid = bookId;
    (*newStudent).next = 0;  //storing 0 in the next part of created node

    temp = StudentHead;


//if there is no node in the list
    if (temp == 0)
    {

        StudentHead = newStudent;
    }

    else
    {

//      traversing student list till last node
        while ((*temp).next != 0)
        {
            temp = (*temp).next;
        }
        (*temp).next = newStudent;
    }
}


//Function to delete a specific student from the student list
int deleteStudent(int studentId, int bookId)
{
    int flag = 0;
    struct Student *temp;
    temp = StudentHead;


//if there is no node in student list
    if (temp == 0)
    {
        flag = 0; 
    }
    
//    if stdId and bookId in headnode become equal to stdId and BookId that user want to delete
    else if ((*temp).studentId == studentId && (*temp).borrowedBookid == bookId)
    {

        StudentHead = (*temp).next;
        free(temp);
        flag = 1;
    }
    else
    {
        struct Student *prev;
        prev = temp;
        temp = (*temp).next;
        
//        traversing student list till last node
        while (temp != 0)
        {

//    if stdId and bookId in tempnode become equal to stdId and BookId that user want to delete
            if ((*temp).studentId == studentId && (*temp).borrowedBookid == bookId)
            {
                (*prev).next = (*temp).next;
               free(temp);
                flag = 1;
                break;
            }
            prev = temp;
            temp = (*temp).next;
        }

        if (flag == 0)
        {
            return 0;
        }
        else if (flag == 1)
        {
            return 1;
        }
    }
}


//function to borrow a specific book from library
void borrowBook(int id)
{

    string studentName;
    int studentId;
    int flag = 0;

    struct Book *temp;
    temp = BookHead;

//if there is no book present in bookList
    if (temp == 0)
    {
        cout << "BookList not available!!!\n";
    }
    else
    {
    	
//    	traversing the booklist till last node
        while (temp != 0)
        {


//      if bookid in tempnode become equal to bookid that user want to borrow
            if ((*temp).bookId == id)
            {

//          getting student data who wants to borrow the book
                cout << "Enter your name:";
                fflush(stdin);
                getline(cin, studentName);

                cout << "Enter your id:";
                cin >> studentId;

//          adding student in student list
                addStudent((*temp).bookName, studentName, (*temp).bookId, studentId);
                
//                decrement a copy of book that student borrowed
                (*temp).noOfCopies = (*temp).noOfCopies - 1;

                flag = 1;
                break;
            }

            temp = (*temp).next;
        }

        if (flag == 1)
        {
            cout << "Book is successfully borrowed!!!\n";
        }
        else if (flag == 0)
        {
            cout << "Book not found!!!\n";
        }
    }
}


//function to return a specific book
void returnBook(int studentId, int bookId)
{

//passing studentId and bookId to deleteStudent function to delete that student from studentList
    int deleteStd = deleteStudent(studentId, bookId);


//if student is deleted from studentList
    if (deleteStd == 1)
    {

        struct Book *temp;
        temp = BookHead;

//traversing the booklist till last node
        while (temp != 0)
        {
            if ((*temp).bookId == bookId)
            {
            	
//            	increment a copy of book that student return
                (*temp).noOfCopies = (*temp).noOfCopies + 1;
            }
            temp = (*temp).next;
        }

        cout << "Book is successfully returned!!!\n";
    }
    else
    {
        cout << "Invalid studentID or bookID!!!\n";
    }
}


//function to search a specific book
void searchBook(int bookId)
{

    int flag = 0;
    struct Book *temp;
    temp = BookHead;

//traverse booklist till last node
    while (temp != 0)
    {
    	
//    	if bookid in temp node become equal to bookid that student/librarian searched for
        if ((*temp).bookId == bookId)
        {
            flag = 1;
            
//            displaying searched book details
            cout << "\n\t\t\t\t\t*******Book Found*******\n";
            cout << "\n";
            cout<<"\t--------------------------------------------------------------------------------------------------\n";
            cout << "\t\tBookName"<< "\t\t    AuthorName "<< "\t\t   NoOfCopies" << "\t\t\tBookID  \n\n";
            cout<<"\t--------------------------------------------------------------------------------------------------\n";
            cout <<"\t"<< (*temp).bookName << "\t|\t" << (*temp).authorName << "\t|\t" << (*temp).noOfCopies << "\t|\t\t" << (*temp).bookId << "\n";
            cout << "\n";
            cout<<"\t--------------------------------------------------------------------------------------------------\n\n";
            break;
        }

        temp = (*temp).next;
    }

    if (flag == 0)
    {
        cout << "Book not found!!!!\n";
    }
}


//function to display book linkedlist
void viewBookList()
{

    struct Book *temp;
    temp = BookHead;


//if there is no book available in book linkedlist
    if (temp == 0)
    {
        cout << "No Books are available in Stock!!!\n";
    }
    else
    {
        cout << "\n";
        cout<<"\t--------------------------------------------------------------------------------------------------\n";
        cout << "\t\tBookName"<< "\t\t    AuthorName "<< "\t\t   NoOfCopies" << "\t\t\tBookID  \n\n";
        
        cout<<"\t--------------------------------------------------------------------------------------------------\n";

        while (temp != 0)
        {

            cout <<"\t"<< (*temp).bookName << "\t|\t" << (*temp).authorName << "\t|\t" << (*temp).noOfCopies << "\t|\t\t" << (*temp).bookId << "\n";
            temp = (*temp).next;
        }
        cout << "\n";
         cout<<"\t--------------------------------------------------------------------------------------------------\n\n";
    }
}


//function to display student linkedlist
void viewStudentList()
{
    struct Student *temp;
    temp = StudentHead;


//if there is no student in student list
    if (temp == 0)
    {
        cout << "No student list available!!!\n";
    }
    else
    {
        cout << "\n";
         cout<<"\t--------------------------------------------------------------------------------------------------\n";
		cout << "\t\tStudent Name "<< "\t\tStudent ID "<< "\t\tBorrowed Book Name"<< "\t  Borrowed Book ID\n\n";
		 cout<<"\t--------------------------------------------------------------------------------------------------\n";

        while (temp != 0)
        {

            cout <<"\t\t"<< (*temp).studentName<<"\t|\t  "<< (*temp).studentId<<"\t|\t\t"<< (*temp).borrowedBookName<<"\t|\t"<< (*temp).borrowedBookid << "\n";
            temp = (*temp).next;
        }
        cout << "\n";
         cout<<"\t--------------------------------------------------------------------------------------------------\n\n";

    }
}


//Driver function to test the functionality of library management system
int main()
{
 
    addBook(" A FareWell To Arms  ", "Ernest Hemingway ", 3371, 5);
    addBook(" The Grapes of Wrath ", " John Steinbeck  ", 3379, 5);
    addBook("  Lord Of The Files  ", " William Golding ", 3343, 5);
    addBook(" The Secret History  ", "   Donna Tartt   ", 4234, 5);
    addBook("   Changing Places   ", "   David Lodge   ", 3311, 5);
    addBook("   Norwegian Wood    ", " Haruki Murakami ", 4231, 5);

    int loginChoice;
    int stdChoice;
    int librarianChoice;

    while (true)
    {

        cout << "\n";
        cout << "                      ****************************************************************************\n";
        cout << "                      ****************************************************************************\n\n";
        cout << "                                                  LIBRARY MANAGEMENT SYSTEM                        \n\n";
        cout << "                      ****************************************************************************\n";
        cout << "                      ****************************************************************************\n";

        cout << "\n";

        cout << " << Please Login to The System\n\n";
        cout << " 1. Student Login\n";
        cout << " 2. Librarian Login\n";
        cout << " 0. Close Application\n";
        cout << " Please Choose One Option:";
        cin >> loginChoice;

        if (loginChoice == 0)
        {
            return 0;
        }
        else if (loginChoice == 1)
        {
            cout << "\n";

            cout << "                   ****************************************************************************\n";
            cout << "                   ****************************************************************************\n\n";
            cout << "                                               Student Login                                   \n\n";
            cout << "                   ****************************************************************************\n";
            cout << "                   ****************************************************************************\n";

            cout << "\n";

            while (true)
            {
                cout << "\n";
                cout << " 1. View BookList\n";
                cout << " 2. Search a Book\n";
                cout << " 3. Borrow a Book\n";
                cout << " 4. Return a Book\n";
                cout << " 5. Go to MainMenu\n";
                cout << " 0. Close Application\n";
                cout << " Please Choose One Option ";
                cin >> stdChoice;

                cout<<"\n";

                if (stdChoice == 1)
                {
                    viewBookList();
                }

                else if (stdChoice == 2)
                {
                    int bookId;
                    cout << "Enter book id you want to search:";
                    cin >> bookId;
                    searchBook(bookId);
                }
                else if (stdChoice == 3)
                {
                    int bookId;
                    cout << "Enter book id you want to borrow:";
                    cin >> bookId;
                    borrowBook(bookId);
                }
                else if (stdChoice == 4)
                {
                    int bookId, stdId;
                    cout << "Enter your ID:";
                    cin >> stdId;
                    cout << "Enter book id you want to return:";
                    cin >> bookId;

                    cout << "\n";
                    returnBook(stdId, bookId);
                }
                else if (stdChoice == 5)
                {

                    break;
                }
                else if (stdChoice == 0)
                {

                    return 0;
                }
            }
        }

        else if (loginChoice == 2)
        {
            cout << "\n";

            cout << "                   ****************************************************************************\n";
            cout << "                   ****************************************************************************\n\n";
            cout << "                                               Librarian Login                                   \n\n";
            cout << "                   ****************************************************************************\n";
            cout << "                   ****************************************************************************\n";

            cout << "\n";

            while (true)
            {
                cout << "\n";
                cout << "                  1. View BookList\n";
                cout << "                  2. Add a Book\n";
                cout << "                  3. Delete a Book\n";
                cout << "                  4. Modify Book\n";
                cout << "                  5. View Student List\n";
                cout << "                  6. Search a Book\n";
                cout << "                  7. Go to MainMenu\n";
                cout << "                  0. Close Application\n";
                cout << "                 Please Choose One Option ";
                cin >> librarianChoice;
                cout<<"\n";

                if (librarianChoice == 1)
                {
                    viewBookList();
                }

                else if (librarianChoice == 2)
                {
                    string bookName;
                    string authorName;
                    int bookId;
                    int noOfCopies;

                    cout<<"Enter bookName:";
                    fflush(stdin);
                    getline(cin,bookName);

                    cout<<"Enter authorName:";
                    fflush(stdin);
                    getline(cin,authorName);

                    cout<<"Enter bookID:";
                    cin>>bookId;

                    cout<<"Enter no of Copies:";
                    cin>>noOfCopies;

                    addBook(bookName,authorName,bookId,noOfCopies);
                }
                else if (librarianChoice == 3)
                {
                     int bookId;
                    cout << "Enter book id you want to delete:";
                    cin >> bookId;
                    deleteBook(bookId);
                }
                else if(librarianChoice==4){
                	
                	 int bookId;
                    cout << "Enter book id you want to modify:";
                    cin >> bookId;
                    modifyBook(bookId);
				}
                else if (librarianChoice == 5)
                {

                    viewStudentList();
                }
                else if (librarianChoice == 6)
                {

                     int bookId;
                    cout << "Enter book id you want to search:";
                    cin >> bookId;
                    searchBook(bookId);
                }
                else if (librarianChoice == 7)
                {

                    break;
                }
                else if (librarianChoice == 0)
                {

                    return 0;
                }
            }
        }

        else
        {
            cout << "Invalid Choice entered!!!!!!\n";
        }
    }
}
