
#include <stdio.h>
#include <stdlib.h>

typedef enum language {
    English = 1,
    French = 2,
    Ukrainian = 3
} Language;

typedef struct book {
    char name[50];
    float price; //in grn.
    unsigned int page_num;
    Language lang;
    float weight; //in grams
    unsigned int year_published;
} Book;

typedef struct node {
    struct book *book;
    struct node *next;
} Node;

void add_last(Node *head, Book *book) {
    Node *current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = (Node *) malloc(sizeof(Node));
    current->next->book = book;
    current->next->next = NULL;
}

void print_book_info(Book *book) {
    printf("----------------------------\n");
    printf("Name: %s\n", book->name);
    printf("Price (in grn.): %0.2f\n", book->price);
    printf("Page number: %u\n", book->page_num);
    printf("Language code: %d\n", book->lang);
    printf("Weight (in grams): %0.2f\n", book->weight);
    printf("Publishing year: %u\n", book->year_published);
}

int main()
{
    
    // Create 7 books
    Book books[7] = {{"Pride and Prejudice", 130.11, 180, English, 400, 1813},
                    {"To Kill a Mockingbird", 953.8, 200, French, 400, 1960},
                    {"The Book Thief", 328.30, 120, Ukrainian, 300, 2005},
                    {"Animal Farm", 644.19, 110, English, 290, 1945},
                    {"The Chronicles of Narnia", 1982.0, 400, French, 800, 1956},
                    {"The Picture of Dorian Gray", 843.19, 370, English, 300, 1890},
                    {"Gone with the Wind", 938.06, 600, English, 1200, 1936}};
    
    // Initialize list
    Node *head = NULL;
    head = (Node *) malloc(sizeof(Node));
    if (head == NULL) {
        return 1;
    }
    
    // Add books to the list
    head->book = &books[0];
    head->next = NULL;
    
    for(int i = 1; i < 7; i++) {
        add_last(head, &books[i]);
    }

    // Print list to the console
    Node *current = head;
    while(current != NULL) {
        print_book_info(current->book);
        current = current->next;
    }
    
    return 0;
}


