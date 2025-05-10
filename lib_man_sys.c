#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for a book
typedef struct {
    int id;
    char title[50];
    char author[50];
    int quantity;
    int issuedCount; // Field to track issued copies
} Book;

// Function prototypes
void displayMenu();
void addBook();
void viewAllBooks();
void searchBook();
void issueBook();
void returnBook();

int main() {
    int choice;
    do {
        displayMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                searchBook();
                break;
            case 3:
                issueBook();
                break;
            case 4:
                returnBook();
                break;
            case 5:
                viewAllBooks();
                break;
            case 6:
                printf("Exiting... Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);
    return 0;
}

// Function to display menu
void displayMenu() {
    printf("\n=== Library Management System ===\n");
    printf("1. Add Book\n");
    printf("2. Search Book\n");
    printf("3. Issue Book\n");
    printf("4. Return Book\n");
    printf("5. View All Books\n");
    printf("6. Exit\n");
    printf("Choose an option: ");
}

// Function to add a book
void addBook() {
    FILE *file = fopen("books.dat", "rb+"); // Open file in read-write binary mode
    if (file == NULL) {
        file = fopen("books.dat", "wb"); // Create the file if it doesn't exist
        if (file == NULL) {
            printf("Error opening file!\n");
            return;
        }
    }

    Book newBook;
    printf("Enter Book ID: ");
    scanf("%d", &newBook.id);

    // Check if ID already exists
    Book book;
    while (fread(&book, sizeof(Book), 1, file)) {
        if (book.id == newBook.id) {
            printf("Error: A book with ID %d already exists. Please use a different ID.\n", newBook.id);
            fclose(file);
            return;
        }
    }

    // Move to the end of the file to add a new book
    fseek(file, 0, SEEK_END);

    printf("Enter Book Title: ");
    getchar(); // Clear newline from buffer
    fgets(newBook.title, 50, stdin);
    strtok(newBook.title, "\n"); // Remove trailing newline
    printf("Enter Book Author: ");
    fgets(newBook.author, 50, stdin);
    strtok(newBook.author, "\n"); // Remove trailing newline

    // Check if the same title by the same author already exists
    rewind(file); // Reset file pointer to the beginning
    while (fread(&book, sizeof(Book), 1, file)) {
        if (strcasecmp(book.title, newBook.title) == 0 && strcasecmp(book.author, newBook.author) == 0) {
            printf("Error: A book titled \"%s\" by \"%s\" already exists.\n", newBook.title, newBook.author);
            fclose(file);
            return;
        }
    }

    printf("Enter Quantity: ");
    scanf("%d", &newBook.quantity);
    newBook.issuedCount = 0; // Initialize issued count

    fwrite(&newBook, sizeof(Book), 1, file); // Write book to file
    fclose(file);

    printf("Book added successfully!\n");
}



// Function to view all books
void viewAllBooks() {
    FILE *file = fopen("books.dat", "rb"); // Open file in read binary mode
    if (file == NULL) {
        printf("No books available.\n");
        return;
    }

    Book book;
    printf("\n=== All Books ===\n");
    while (fread(&book, sizeof(Book), 1, file)) {
        printf("ID: %d, Title: %s, Author: %s, Quantity: %d, Issued: %d\n",
               book.id, book.title, book.author, book.quantity, book.issuedCount);
    }
    fclose(file);
}

// Function to search for a book
void searchBook() {
    FILE *file = fopen("books.dat", "rb"); // Open file in read mode
    if (file == NULL) {
        printf("No books available.\n");
        return;
    }

    int searchOption, refineOption;
    Book book;
    char searchInput[50]; // For Title or Author input
    int bookID;
    Book matchedBooks[100]; // Temporary storage for matched books
    int matchedCount = 0;

    printf("\nSearch Book by:\n1. ID\n2. Title\n3. Author\nChoose an option: ");
    scanf("%d", &searchOption);

    if (searchOption == 1) {
        // Search by ID
        printf("Enter Book ID: ");
        scanf("%d", &bookID);

        while (fread(&book, sizeof(Book), 1, file)) {
            if (book.id == bookID) {
                printf("\nBook Found:\n");
                printf("ID: %d, Title: %s, Author: %s, Quantity: %d, Issued: %d\n",
                       book.id, book.title, book.author, book.quantity, book.issuedCount);
                fclose(file);
                return;
            }
        }
        printf("No book found with ID %d.\n", bookID);
    } else if (searchOption == 2 || searchOption == 3) {
        // Search by Title or Author
        if (searchOption == 2) {
            printf("Enter Book Title: ");
        } else {
            printf("Enter Book Author: ");
        }
        getchar(); // Clear newline from buffer
        fgets(searchInput, 50, stdin);
        strtok(searchInput, "\n"); // Remove trailing newline

        // Find all matching books
        while (fread(&book, sizeof(Book), 1, file)) {
            if ((searchOption == 2 && strcasecmp(book.title, searchInput) == 0) ||
                (searchOption == 3 && strcasecmp(book.author, searchInput) == 0)) {
                matchedBooks[matchedCount++] = book;
            }
        }

        if (matchedCount == 0) {
            printf("No books found matching the %s \"%s\".\n",
                   (searchOption == 2) ? "Title" : "Author", searchInput);
        } else if (matchedCount == 1) {
            printf("\nBook Found:\n");
            printf("ID: %d, Title: %s, Author: %s, Quantity: %d, Issued: %d\n",
                   matchedBooks[0].id, matchedBooks[0].title, matchedBooks[0].author,
                   matchedBooks[0].quantity, matchedBooks[0].issuedCount);
        } else {
            printf("\nMultiple books found:\n");
            for (int i = 0; i < matchedCount; i++) {
                printf("[%d] ID: %d, Title: %s, Author: %s, Quantity: %d, Issued: %d\n",
                       i + 1, matchedBooks[i].id, matchedBooks[i].title, matchedBooks[i].author,
                       matchedBooks[i].quantity, matchedBooks[i].issuedCount);
            }

            printf("\nRefine your search by:\n1. ID\n2. %s\nChoose an option: ",
                   (searchOption == 2) ? "Author" : "Title");
            scanf("%d", &refineOption);

            if (refineOption == 1) {
                printf("Enter Book ID: ");
                scanf("%d", &bookID);
                for (int i = 0; i < matchedCount; i++) {
                    if (matchedBooks[i].id == bookID) {
                        printf("\nBook Found:\n");
                        printf("ID: %d, Title: %s, Author: %s, Quantity: %d, Issued: %d\n",
                               matchedBooks[i].id, matchedBooks[i].title, matchedBooks[i].author,
                               matchedBooks[i].quantity, matchedBooks[i].issuedCount);
                        fclose(file);
                        return;
                    }
                }
                printf("No book found with ID %d in the refined search results.\n", bookID);
            } else if (refineOption == 2) {
                printf("Enter %s: ", (searchOption == 2) ? "Author" : "Title");
                getchar(); // Clear newline from buffer
                fgets(searchInput, 50, stdin);
                strtok(searchInput, "\n"); // Remove trailing newline

                for (int i = 0; i < matchedCount; i++) {
                    if ((searchOption == 2 && strcasecmp(matchedBooks[i].author, searchInput) == 0) ||
                        (searchOption == 3 && strcasecmp(matchedBooks[i].title, searchInput) == 0)) {
                        printf("\nBook Found:\n");
                        printf("ID: %d, Title: %s, Author: %s, Quantity: %d, Issued: %d\n",
                               matchedBooks[i].id, matchedBooks[i].title, matchedBooks[i].author,
                               matchedBooks[i].quantity, matchedBooks[i].issuedCount);
                        fclose(file);
                        return;
                    }
                }
                printf("No book found with the refined search parameter \"%s\".\n", searchInput);
            } else {
                printf("Invalid refine option. Returning to menu.\n");
            }
        }
    } else {
        printf("Invalid search option. Returning to menu.\n");
    }

    fclose(file);
}


// Function to issue a book
void issueBook() {
    FILE *file = fopen("books.dat", "rb+"); // Open file in read-write binary mode
    if (file == NULL) {
        printf("No books available.\n");
        return;
    }

    int searchOption;
    printf("\nIssue Book by:\n1. ID\n2. Title\n3. Author\nChoose an option: ");
    scanf("%d", &searchOption);

    Book book;
    int found = 0, bookID;
    char searchInput[50]; // For Title or Author input

    if (searchOption == 1) {
        // Issue by Book ID
        printf("Enter Book ID to issue: ");
        scanf("%d", &bookID);

        while (fread(&book, sizeof(Book), 1, file)) {
            if (book.id == bookID) {
                found = 1;
                if (book.quantity > 0) {
                    book.quantity--;
                    book.issuedCount++;
                    fseek(file, -sizeof(Book), SEEK_CUR);
                    fwrite(&book, sizeof(Book), 1, file);
                    printf("Book issued successfully! Remaining Quantity: %d\n", book.quantity);
                } else {
                    printf("Book is out of stock!\n");
                }
                break;
            }
        }

        if (!found) {
            printf("No book found with ID %d.\n", bookID);
        }
    } else if (searchOption == 2 || searchOption == 3) {
        // Issue by Title or Author
        if (searchOption == 2) {
            printf("Enter Book Title: ");
        } else {
            printf("Enter Book Author: ");
        }
        getchar(); // Clear newline from buffer
        fgets(searchInput, 50, stdin);
        strtok(searchInput, "\n"); // Remove trailing newline

        printf("\nMatching books:\n");
        Book matchedBooks[100]; // Temporary storage for matched books
        int matchedCount = 0;

        // Find all matching books
        while (fread(&book, sizeof(Book), 1, file)) {
            if ((searchOption == 2 && strcasecmp(book.title, searchInput) == 0) ||
                (searchOption == 3 && strcasecmp(book.author, searchInput) == 0)) {
                printf("[%d] Title: %s | Author: %s | Quantity: %d | Issued: %d\n",
                       matchedCount + 1, book.title, book.author, book.quantity, book.issuedCount);
                matchedBooks[matchedCount++] = book;
                found = 1;
            }
        }

        if (!found) {
            printf("No books found matching the %s \"%s\".\n",
                   (searchOption == 2) ? "Title" : "Author", searchInput);
        } else {
            printf("\nEnter the number of the book to issue: ");
            int choice;
            scanf("%d", &choice);

            if (choice > 0 && choice <= matchedCount) {
                book = matchedBooks[choice - 1];
                rewind(file); // Reset file pointer to find the selected book
                while (fread(&book, sizeof(Book), 1, file)) {
                    if (strcasecmp(book.title, matchedBooks[choice - 1].title) == 0 &&
                        strcasecmp(book.author, matchedBooks[choice - 1].author) == 0 &&
                        book.id == matchedBooks[choice - 1].id) {
                        if (book.quantity > 0) {
                            book.quantity--;
                            book.issuedCount++;
                            fseek(file, -sizeof(Book), SEEK_CUR);
                            fwrite(&book, sizeof(Book), 1, file);
                            printf("Book issued successfully! Remaining Quantity: %d\n", book.quantity);
                        } else {
                            printf("Book is out of stock!\n");
                        }
                        break;
                    }
                }
            } else {
                printf("Invalid choice. Returning to menu.\n");
            }
        }
    } else {
        printf("Invalid option. Returning to menu.\n");
    }

    fclose(file);
}


// Function to return a book
void returnBook() {
    FILE *file = fopen("books.dat", "rb+"); // Open file in read-write binary mode
    if (file == NULL) {
        printf("No books available.\n");
        return;
    }

    int bookID, found = 0;
    printf("Enter Book ID to return: ");
    scanf("%d", &bookID);

    Book book;
    while (fread(&book, sizeof(Book), 1, file)) {
        if (book.id == bookID) {
            found = 1;
            if (book.issuedCount > 0) {
                book.quantity++; // Increase quantity
                book.issuedCount--; // Decrement issued count
                fseek(file, -sizeof(Book), SEEK_CUR);
                fwrite(&book, sizeof(Book), 1, file);
                printf("Book returned successfully! Current Quantity: %d\n", book.quantity);
            } else {
                printf("No issued copies of this book to return!\n");
            }
            break;
        }
    }

    if (!found) {
        printf("No book found with ID %d.\n", bookID);
    }

    fclose(file);
}
