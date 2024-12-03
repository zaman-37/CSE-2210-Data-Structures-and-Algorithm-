*****************************************************************************************LIBRARY MANAGEMENT SYSTEM*******************************************************************************************

**Introduction**:
The Library Book Management System is a software solution developed to manage essential library operations such as storing book information, issuing and returning books, managing member details, and organizing library sections. The system uses fundamental data structures like arrays, stacks, queues, linked lists, and trees to efficiently manage these tasks, making it an excellent project for understanding data structures and algorithms in real-world applications.

**Key Features**:
The system integrates several features to manage library operations effectively:
**Book Cataloging**:
Books are stored using arrays or STL vectors, making it easy to add, delete, and view book details such as title, author, and ISBN.The cataloging process organizes book information efficiently for further operations.
**Sorting and Searching**:
Books can be sorted by title or ISBN using Quick Sort and Bubble Sort algorithms for better accessibility. Binary Search Tree (BST) allows fast searching of books by title, ensuring quick results even for large datasets.
**Borrowing and Returning Books**:
A stack tracks recent book transactions (borrowed or returned), providing a quick history of user activities. A queue manages reservations for books that are currently unavailable, ensuring fair distribution.
**Member Management**:
Linked lists store and manage member information, associating issued books with specific members.
**Library Hierarchy**:
Tree structures represent sections of the library (e.g., Fiction, Non-Fiction), aiding in the logical organization of books.
**User-Friendly Interface**:
The interactive menu guides users through various operations like viewing books, borrowing, returning, or searching with simple instructions.


# **Functionality:
This section explains how each feature of the system is implemented and functions in detail:

1.**Storing Books**:
	The store_books function takes user input to add book details such as title, author, and ISBN. These details are stored in a vector and also inserted into a BST for efficient searching.
	Example: Input six books, and they are stored in the vector and BST simultaneously.

2.	**Viewing Books**:
	The view_books function iterates through the vector, displaying the details of all stored books. It serves as a quick way to view the entire library collection.

3.	**Sorting Books**:
	By ISBN: Uses a Bubble Sort algorithm to arrange books in ascending order based on their ISBN.
	By Title: Quick Sort is used for more efficient sorting of books alphabetically by title. Once sorted, the catalog is displayed for users.

4.	**Searching Books**:
	The search_book function uses the BST to locate a book by title. If found, the book's details are displayed; otherwise, a "Book not found" message is shown.
	Example: Searching for "1984" will return its details if stored.


5.	**Borrowing Books**:
	The borrow_book function allows users to borrow books if available.
	If a book is already issued, the borrower's name is added to a reservation queue.
	The borrowed book is marked as "unavailable," and the transaction is pushed onto a stack for record-keeping.

6.	**Returning Books**:
	The return_book function updates the status of returned books to "available." If the book has a reservation queue, it assigns the book to the next person in the queue.
	The transaction is logged in the stack for traceability.

7.	**Recent Transactions**:
	The recent_transaction function uses a stack to display the most recent borrowing or returning transaction, providing a quick overview of user activity.


# **Discussion:
The Library Book Management System demonstrates a practical implementation of data structures in solving real-world problems. It efficiently handles operations like cataloging, searching, and borrowing books, offering a smooth experience for both librarians and users.
•	**Strengths**:
o	Effective use of data structures like stacks, queues, linked lists, and BSTs.
o	Modular code design ensures clarity and maintainability.
o	Sorting and searching improve accessibility and user experience.

•	**Limitations**:
o	Currently relies on in-memory storage, limiting scalability.
o	Error handling and input validation can be improved.
o	A graphical user interface (GUI) could make the system more user-friendly.
Future enhancements could include integrating a database for large-scale data management, implementing more advanced algorithms for operations, and adding a GUI for improved usability.

**Conclusion**:
The Library Book Management System is an effective tool for managing library operations, demonstrating the importance and application of data structures in software development. By integrating features such as book cataloging, searching, and transaction tracking, it provides a comprehensive solution for libraries. The project serves as a foundation for further exploration and development, offering opportunities for students and developers to enhance their skills in data structures and real-world problem-solving.














