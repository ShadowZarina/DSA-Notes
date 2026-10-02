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

```
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
} BookType, *BookNode;

typedef struct {
    BookNode books[10];
} BookShelf;


/* Function Prototypes */
int Hash(String genre);
void initHash(BookShelf *D);
void insert(BookShelf *D, Book toInsert);
void displayHash(BookShelf D);


/* --------------------------------
   HASH FUNCTION
   -------------------------------- */
int Hash(String genre) {

    if (strcmp(genre, "Design") == 0)
        return 0;

    else if (strcmp(genre, "Manga") == 0)
        return 1;

    else if (strcmp(genre, "Fantasy") == 0)
        return 2;

    else if (strcmp(genre, "Romance") == 0)
        return 3;

    else if (strcmp(genre, "Horror") == 0)
        return 4;

    else if (strcmp(genre, "YoungAdult") == 0)
        return 5;

    else if (strcmp(genre, "SciFi") == 0)
        return 6;

    else if (strcmp(genre, "NonFiction") == 0)
        return 7;

    else if (strcmp(genre, "Thriller") == 0)
        return 8;

    else if (strcmp(genre, "Comics") == 0)
        return 9;

    return -1;
}


/* --------------------------------
   INITIALIZE HASH TABLE
   -------------------------------- */
void initHash(BookShelf *D) {

    int i;

    for (i = 0; i < 10; i++) {
        D->books[i] = NULL;
    }
}


/* --------------------------------
   INSERT BOOK
   -------------------------------- */
void insert(BookShelf *D, Book toInsert) {

    int index;
    BookNode newNode;

    /* Get hash index from genre */
    index = Hash(toInsert.genre);

    /* Invalid genre */
    if (index == -1) {
        printf("Invalid genre: %s\n", toInsert.genre);
        return;
    }

    /* Allocate memory for new node */
    newNode = malloc(sizeof(BookType));

    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    /* Store the book */
    newNode->elem = toInsert;

    /*
       Insert at the front of the
       linked list.
    */
    newNode->next = D->books[index];
    D->books[index] = newNode;
}


/* --------------------------------
   DISPLAY HASH TABLE
   -------------------------------- */
void displayHash(BookShelf D) {

    int i;
    BookNode trav;

    String genres[10] = {
        "Design",
        "Manga",
        "Fantasy",
        "Romance",
        "Horror",
        "YoungAdult",
        "SciFi",
        "NonFiction",
        "Thriller",
        "Comics"
    };

    printf("\n========== BOOK HASH TABLE ==========\n");

    for (i = 0; i < 10; i++) {

        printf("\n[%d] %s\n", i, genres[i]);

        trav = D.books[i];

        if (trav == NULL) {
            printf("    NULL");
        }

        while (trav != NULL) {

            printf("    -> %s", trav->elem.bookName);

            trav = trav->next;
        }

        printf("\n");
    }
}


/* --------------------------------
   MAIN
   -------------------------------- */
int main(void) {

    BookShelf shelf;

    Book books[15] = {

        {
            "The Design of Everyday Things",
            "Don Norman",
            "Design",
            "Basic Books",
            2013,
            368
        },

        {
            "One Piece",
            "Eiichiro Oda",
            "Manga",
            "Shueisha",
            1997,
            200
        },

        {
            "The Hobbit",
            "J.R.R. Tolkien",
            "Fantasy",
            "George Allen",
            1937,
            310
        },

        {
            "The Name of the Wind",
            "Patrick Rothfuss",
            "Fantasy",
            "DAW Books",
            2007,
            662
        },

        {
            "Pride and Prejudice",
            "Jane Austen",
            "Romance",
            "T. Egerton",
            1813,
            432
        },

        {
            "The Shining",
            "Stephen King",
            "Horror",
            "Doubleday",
            1977,
            447
        },

        {
            "It",
            "Stephen King",
            "Horror",
            "Viking Press",
            1986,
            1138
        },

        {
            "The Hunger Games",
            "Suzanne Collins",
            "YoungAdult",
            "Scholastic",
            2008,
            374
        },

        {
            "Dune",
            "Frank Herbert",
            "SciFi",
            "Chilton Books",
            1965,
            412
        },

        {
            "Ender's Game",
            "Orson Scott Card",
            "SciFi",
            "Tor Books",
            1985,
            324
        },

        {
            "Sapiens",
            "Yuval Noah Harari",
            "NonFiction",
            "Harper",
            2015,
            443
        },

        {
            "Gone Girl",
            "Gillian Flynn",
            "Thriller",
            "Crown Publishing",
            2012,
            419
        },

        {
            "The Silent Patient",
            "Alex Michaelides",
            "Thriller",
            "Celadon Books",
            2019,
            336
        },

        {
            "The Girl with the Dragon Tattoo",
            "Stieg Larsson",
            "Thriller",
            "Norstedts",
            2005,
            465
        },

        {
            "Batman: Year One",
            "Frank Miller",
            "Comics",
            "DC Comics",
            1987,
            144
        }
    };


    /* Initialize hash table */
    initHash(&shelf);


    /* Insert all 15 books */
    for (int i = 0; i < 15; i++) {
        insert(&shelf, books[i]);
    }


    /* Display the resulting hash table */
    displayHash(shelf);


    return 0;
}
```
