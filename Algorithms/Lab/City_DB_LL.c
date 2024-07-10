#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
// Structure to represent a city
struct City
{
    char name[100];
    int x;
    int y;
    struct City *next;
};
// Function to insert a record into the linked list-based city database
void insertRecordLinkedList(struct City **head, const char *name, int x, int y)
{
    struct City *newCity = (struct City *)malloc(sizeof(struct City));
    strcpy(newCity->name, name);
    newCity->x = x;
    newCity->y = y;
    newCity->next = *head;
    *head = newCity;
    printf("Record inserted successfully.\n");
}
// Function to delete a record by name from the linked list-based city database
void deleteRecordByNameLinkedList(struct City **head, const char *name)
{
    struct City *temp = *head;
    struct City *prev = NULL;
    int found = 0;
    while (temp != NULL)
    {
        if (strcmp(temp->name, name) == 0)
        {
            found = 1;
            if (prev == NULL)
            {
                *head = temp->next;
            }
            else
            {
                prev->next = temp->next;
            }
            free(temp);
            printf("Record deleted successfully.\n");
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    if (!found)
    {
        printf("Record not found.\n");
    }
}
// Function to delete a record by coordinates from the linked list-based city database
void deleteRecordByCoordinatesLinkedList(struct City **head, int x, int y)
{
    struct City *temp = *head;
    struct City *prev = NULL;
    int found = 0;
    while (temp != NULL)
    {
        if (temp->x == x && temp->y == y)
        {
            found = 1;
            if (prev == NULL)
            {
                *head = temp->next;
            }
            else
            {
                prev->next = temp->next;
            }
            free(temp);
            printf("Record deleted successfully.\n");
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    if (!found)
    {
        printf("Record not found.\n");
    }
}
// Function to search for a record by name in the linked list-based city database
void searchRecordByNameLinkedList(struct City *head, const char *name)
{
    struct City *temp = head;
    int found = 0;
    while (temp != NULL)
    {
        if (strcmp(temp->name, name) == 0)
        {
            found = 1;
            printf("Record found: %s (%d, %d)\n", temp->name, temp->x, temp->y);
            break;
        }
        temp =
            temp->next;
    }
    if (!found)
    {
        printf("Record not found.\n");
    }
}
// Function to search for a record by coordinates in the linked list-based city database
void searchRecordByCoordinatesLinkedList(struct City *head, int x, int y)
{
    struct City *temp = head;
    int found = 0;
    while (temp != NULL)
    {
        if (temp->x == x && temp->y == y)
        {
            found = 1;
            printf("Record found: %s (%d, %d)\n", temp->name, temp->x, temp->y);
            break;
        }
        temp =
            temp->next;
    }
    if (!found)
    {
        printf("Record not found.\n");
    }
}
// Function to calculate the Euclidean distance between two points
double calculateDistance(int x1, int y1, int x2, int y2)
{
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}
// Function to print all records within a given distance of a specified point in the linked list-based city
database void printRecordsWithinDistanceLinkedList(struct City *head, int x, int y, double distance)
{
    printf("Records within distance %.2f of (%d, %d):\n", distance, x, y);
    struct City *temp = head;
    while (temp != NULL)
    {
        double dist = calculateDistance(x, y, temp->x, temp->y);
        if (dist <= distance)
        {
            printf("%s (%d, %d) - Distance: %.2f\n", temp->name, temp->x, temp->y, dist);
        }
        temp =
            temp->next;
    }
}
int main()
{
    // Example usage of linked list-based city database
    struct City *head = NULL;
    insertRecordLinkedList(&head, "New York", 10, 20);
    insertRecordLinkedList(&head, "Los Angeles", 30, 40);
    insertRecordLinkedList(&head, "Chicago", 50, 60);
    searchRecordByNameLinkedList(head, "Los Angeles");
    searchRecordByCoordinatesLinkedList(head, 50, 60);
    deleteRecordByNameLinkedList(&head, "Los Angeles");
    deleteRecordByCoordinatesLinkedList(&head, 10, 20);
    printRecordsWithinDistanceLinkedList(head, 30, 40, 10.0);
    return 0;
}