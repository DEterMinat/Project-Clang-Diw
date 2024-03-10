#include  <stdio.h> 
#include  <stdlib.h> 
#include  <string.h> 
typedef struct Node  
  
{ 
    int id; 
    char title[256]; 
    char author[256]; 
    int year; 
    int status; 
    struct Node *next; 
} Node; 

void addBook(Node **head, int id, char *title, char *author, int year, int status) 
{ 
    Node *newNode = (Node *)malloc(sizeof(Node));  
    if (!newNode) 
    { 
        printf("Memory allocation failed.\n"); 
        exit(EXIT_FAILURE); 
    } 
    // ก าหนดค่าให้กับแต่ละสมาชิกในโหนดใหม่ 
    newNode->id = id; 
    strcpy(newNode->title, title); 
    strcpy(newNode->author, author); 
    newNode->year = year; 
    newNode->status = status; 
    newNode->next = *head; 

 
   
 
    *head = newNode; 
    saveFile(*head); 
} 

 
void removeBook(Node **head, int id) 
{ 
    Node *temp = *head, *prev = NULL; 
  
    if (temp != NULL && temp->id == id) 
    { 
        *head = temp->next; 
        free(temp); 
        saveFile(*head); 
        return; 
    } 
  
    while (temp != NULL && temp->id != id) 
    { 
        prev = temp; 
        temp = temp->next; 
    } 
  
    if (temp == NULL) 
    { 
        printf("No book with this id exists.\n"); 
        return; 
    } 
  
    prev->next = temp->next; 
    free(temp); 
    saveFile(*head); 
} 

void modifyBook(Node *head, int id) 
{ 
    Node *temp = head; 
  
    while (temp != NULL) 
    { 
        if (temp->id == id) 
        { 
            printf("Enter new title: "); 

 
   
 
            fgets(temp->title, sizeof(temp->title), 
stdin); 
            temp->title[strlen(temp->title) - 1] = 
'\0'; 
  
            printf("Enter new author: "); 
            fgets(temp->author, sizeof(temp->author), stdin); 
            temp->author[strlen(temp->author) - 
1] = '\0'; 
  
            printf("Enter new year: "); 
            scanf("%d", &temp->year); 
  
            printf("Enter new status (0 for not borrowed, 1 for borrowed): "); 
            scanf("%d", &temp->status); 
  
            saveFile(head); 
            return; 
        } 
        temp = temp->next; 
    } 
  
    printf("No book with this id exists.\n"); 
} 

void displayBooks(Node *head) 
{ 
    Node *temp = head; 
  
    while (temp != NULL) 
    { 
        printf("ID: %d\n", temp->id); 
        printf("Title: %s\n", temp->title); 
        printf("Author: %s\n", temp->author); 
        printf("Year: %d\n", temp->year); 
        printf("Status: %s\n", temp->status? 
"Borrowed": "Not Borrowed"); 
        printf("\n"); 
  
        temp = temp->next; 
    } 
} 



void saveFile(Node *head)  { 
    FILE *file;  
    Node *temp = head; 
  
    file = fopen("books.txt", "a");  if (file == NULL) 
    { 
        printf("Could not open the file.\n"); 
        return; 
    } 
  
    while (temp!= NULL) 
    { 
        fprintf(file, "ID: %d\nTitle: %s\nAuthor: %s\nYear: %d\nStatus: %d\n", temp->id, temp->title, temp->author, temp->year, temp->status); 
        temp = temp->next; 
    } 
  
    fclose(file); 
} 

int main () 
{ 
    Node *head = NULL; 
    int choice; 
    do 
    {    
        printf("MENU BOOK\n"); 
        printf("1. Add Book\n"); 
        printf("2. Remove Book\n"); 
        printf("3. Modify Book\n"); 
        printf("4. Display Books\n"); 
        printf("5. Exit\n"); 
        printf("Enter your choice: "); 
        scanf("%d", &choice); 
  
        switch (choice)  
        { 
        case 1: 
        { 
            int id; 
            char title [256]; 
            char author [256]; 
 
            int year; 
            int status; 
  
            printf("Enter id: "); 
            scanf("%d", &id); 
  
            printf("Enter title: "); 
            getchar();  
            fgets(title, sizeof(title), stdin); 
            title[strlen(title) - 1] = '\0'; 
  
            printf("Enter author: "); 
            fgets(author, sizeof(author), stdin); 
            author[strlen(author) - 1] = '\0'; 
  
            printf("Enter year: "); 
            scanf("%d", &year); 
  
            printf("Enter status (0 for not borrowed, 1 for borrowed): "); 
            scanf("%d", &status); 
  
            addBook(&head, id, title, author, year, status); 
            break; 
        } 
        case 2: 
        { 
            int id; 
            printf("Enter id: "); 
            scanf("%d", &id); 
            removeBook(&head, id); 
            break; 
        } 
        case 3: 
        { 
            int id; 
            printf("Enter id: "); 
            scanf("%d", &id); 
            modifyBook(head, id); 
            break; 
        } 
        case 4: 
        { 

            displayBooks(head); 
            break; 
        } 
        case 5: 
        {    
            return 0; 
        } 
        default: 
        { 
            printf("Invalid choice.\n"); 
            break; 
        } 
        } 
    } while (choice!= 0); 
}