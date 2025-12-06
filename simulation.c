#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for each task (node)
typedef struct Task {
    int id;
    char name[50];
    struct Task* next;
} Task;

Task* head = NULL;  // Start of linked list
int taskCounter = 1;

// Function to create a new task node
Task* createTask(char name[]) {
    Task* newTask = (Task*)malloc(sizeof(Task));
    newTask->id = taskCounter++;
    strcpy(newTask->name, name);
    newTask->next = NULL;
    return newTask;
}

// Add task to end of list
void addTask() {
    char name[50];
    printf("Enter task name: ");
    scanf(" %[^\n]", name);

    Task* newTask = createTask(name);

    if (head == NULL) {
        head = newTask;
    } else {
        Task* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newTask;
    }

    printf("Task added successfully!\n");
}

// Display all tasks
void displayTasks() {
    if (head == NULL) {
        printf("No tasks available.\n");
        return;
    }

    Task* temp = head;
    printf("\n--- To-Do List ---\n");
    while (temp != NULL) {
        printf("Task ID: %d | Task: %s\n", temp->id, temp->name);
        temp = temp->next;
    }
}

// Search a task by name
void searchTask() {
    char key[50];
    printf("Enter task name to search: ");
    scanf(" %[^\n]", key);

    Task* temp = head;
    while (temp != NULL) {
        if (strcmp(temp->name, key) == 0) {
            printf("Task found! ID: %d | Name: %s\n", temp->id, temp->name);
            return;
        }
        temp = temp->next;
    }
    printf("Task not found.\n");
}

// Delete a task by ID
void deleteTask() {
    int id;
    printf("Enter task ID to delete: ");
    scanf("%d", id);

    Task* temp = head;
    Task* prev = NULL;

    // Delete head
    if (temp != NULL && temp->id == id) {
        head = temp->next;
        free(temp);
        printf("Task deleted.\n");
        return;
    }

    // Search other nodes
    while (temp != NULL && temp->id != id) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Task not found.\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("Task deleted.\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n===== TO-DO LIST MANAGER =====\n");
        printf("1. Add Task\n");
        printf("2. Display Tasks\n");
        printf("3. Search Task\n");
        printf("4. Delete Task\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addTask(); break;
            case 2: displayTasks(); break;
            case 3: searchTask(); break;
            case 4: deleteTask(); break;
            case 5: exit(0);
            default: printf("Invalid choice!\n");
        }
    }
    return 0;
}