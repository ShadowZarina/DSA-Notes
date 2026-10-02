// Problem Provided by Miss Sabado

# CODING PROBLEM: Book Genre Hash Table with Separate Chaining

Implement a hash table of books grouped by genre using separate chaining to handle collisions.

The hash table has 10 positions (0–9). Each position represents a book genre. Since multiple books can belong to the same genre, each position may contain a linked list of books.

1. Given Data Structures

Use the following definitions:
```
#define MAX 30

typedef char String[50];

typedef struct {
    String bookName;
    String authorName;
    String genre;
    String publishingHouse;
    int publishingYear;
    int totalPageNum;
} Book;

typedef struct node {
    Book elem;
    struct node *next;
} BookNode, *BookType;

typedef struct {
    BookType books[10];
} BookShelf;
```
What each structure represents
Book — stores information about one book.
BookNode — a linked-list node containing a Book.
BookType — pointer to a BookNode.
BookShelf — the hash table containing 10 buckets.

The important part is:

`BookType books[10];`

This means each hash position contains a pointer to the first node of a linked list.

2. Hash Table

The hash table has indexes 0–9:
```
| Index | Genre      |
| ----: | ---------- |
|     0 | Design     |
|     1 | Manga      |
|     2 | Fantasy    |
|     3 | Romance    |
|     4 | Horror     |
|     5 | YoungAdult |
|     6 | SciFi      |
|     7 | NonFiction |
|     8 | Thriller   |
|     9 | Comics     |
```
  2. Initialize the Hash Table

Create a function that initializes all 10 positions of the hash table.

Function prototype<br>
`void initHash(BookShelf *D);`

All positions must initially contain no books.

3. Insert a Book

Create a function that inserts a Book into the hash table according to its genre.

Function prototype<br>
`void insert(BookShelf *D, Book toInsert);`

The function must:
- Determine the book's hash index using its genre.
- Insert the book into the corresponding position.
- Use a linked list for each hash position.
- Allow multiple books to occupy the same hash position.
- Handle collisions using separate chaining.
- Insert the new book at the first position of the linked list.

4. Simulate the Hash Table

Create 15 book records containing:

- Book title
- Author
- Genre
- Publishing house
- Publishing year
- Total number of pages

Insert all 15 books into the hash table.

Your 15 books must include books from the provided genres, with some genres having more than one book so that collisions and linked-list chaining can be demonstrated.

5. Display the Hash Table

Create a function to display the contents of the hash table.

Function prototype<br>
`void displayHash(BookShelf D);`

The display should show:
- The hash index
- The genre/category represented by that index
- Every book stored at that index
- The linked-list order of books within the bucket

6. Required Hash Table Structure

After inserting the 15 books, your hash table should have the following 10 buckets:
```
0 → Design
1 → Manga
2 → Fantasy
3 → Romance
4 → Horror
5 → YoungAdult
6 → SciFi
7 → NonFiction
8 → Thriller
9 → Comics
```
Each bucket should contain either:
- No book, or
- A linked list containing one or more books.

Books belonging to the same genre must be stored in the same bucket and connected using the next pointer.

Required Functions

Your program must contain at least the following function prototypes:
```
int Hash(String genre);

void initHash(BookShelf *D);

void insert(BookShelf *D, Book toInsert);

void displayHash(BookShelf D);
```
Use the provided structures and implement the hash table using linked lists and separate chaining.

# ANSWER
