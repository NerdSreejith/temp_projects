#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the File node structure
typedef struct File {
    char name[100];
    int size;
    struct File* next;
} File;

// Function to create a new file node
File* create_file(char* name, int size) {
    File* new_file = (File*)malloc(sizeof(File));
    strcpy(new_file->name, name);
    new_file->size = size;
    new_file->next = NULL;
    return new_file;
}

// Function to insert a file into the linked list
void insert_file(File** head, File* file) {
    if (*head == NULL) {
        *head = file;
    } else {
        file->next = *head;
        *head = file;
    }
}

// Function to delete a file from the linked list
void delete_file(File** head, char* name) {
    File* current = *head;
    File* previous = NULL;

    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            if (previous == NULL) {
                *head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }
}

// Function to display all files in the linked list
void display_files(File* head) {
    File* temp = head;
    while (temp != NULL) {
        printf("File Name: %s, Size: %d\n", temp->name, temp->size);
        temp = temp->next;
    }
}

int main() {
    File* head = NULL;

    // Example usage
    insert_file(&head, create_file("file1.txt", 1024));
    insert_file(&head, create_file("file2.doc", 2048));

    printf("Initial File List:\n");
    display_files(head);

    // Delete a file (e.g., "file1.txt")
    delete_file(&head, "file1.txt");

    printf("\nUpdated File List:\n");
    display_files(head);

    // Clean up memory (free linked list nodes)
    while (head != NULL) {
        File* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
