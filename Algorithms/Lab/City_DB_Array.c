#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX_CITIES 1000
// Structure to represent a city
struct City
{
    char name[100];
    int x;
    int y;
};
// Array to store the city records
struct City cityDatabase[MAX_CITIES];
int numCities = 0;
// Function to insert a record into the array-based city database
void insertRecordArray(const char *name, int x, int y)
{
    if (numCities < MAX_CITIES)
    {
        strcpy(cityDatabase[numCities].name, name);
        cityDatabase[numCities].x = x;
        cityDatabase[numCities].y = y;
        numCities++;
        printf("Record inserted successfully.\n");
    }
    else
    {
        printf("City database is full. Cannot insert more records.\n");
    }
}
// Function to delete a record by name from the array-based city database
void deleteRecordByNameArray(const char *name)
{
    int found = 0;
    for (int i = 0; i < numCities; i++)
    {
        if (strcmp(cityDatabase[i].name, name) == 0)
        {
            found = 1;
            for (int j = i; j < numCities - 1; j++)
            {
                cityDatabase[j] = cityDatabase[j + 1];
            }
            numCities--;
            printf("Record deleted successfully.\n");
            break;
        }
    }
    if (!found)
    {
        printf("Record not found.\n");
    }
}
// Function to delete a record by coordinates from the array-based city database
void deleteRecordByCoordinatesArray(int x, int y)
{
    int found = 0;
    for (int i = 0; i < numCities; i++)
    {
        if (cityDatabase[i].x == x && cityDatabase[i].y == y)
        {
            found = 1;
            for (int j = i; j < numCities - 1; j++)
            {
                cityDatabase[j] = cityDatabase[j + 1];
            }
            numCities--;
            printf("Record deleted successfully.\n");
            break;
        }
    }
    if (!found)
    {
        printf("Record not found.\n");
    }
}
// Function to search for a record by name in the array-based city database
void searchRecordByNameArray(const char *name)
{
    int found = 0;
    for (int i = 0; i < numCities; i++)
    {
        if (strcmp(cityDatabase[i].name, name) == 0)
        {
            found = 1;
            printf("Record found: %s (%d, %d)\n", cityDatabase[i].name, cityDatabase[i].x,
                   cityDatabase[i].y);
            break;
        }
    }
    if (!found)
    {
        printf("Record not found.\n");
    }
}
// Function to search for a record by coordinates in the array-based city database
void searchRecordByCoordinatesArray(int x, int y)
{
    int found = 0;
    for (int i = 0; i < numCities; i++)
    {
        if (cityDatabase[i].x == x && cityDatabase[i].y == y)
        {
            found = 1;
            printf("Record found: %s (%d, %d)\n", cityDatabase[i].name, cityDatabase[i].x,
                   cityDatabase[i].y);
            break;
        }
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
// Function to print all records within a given distance of a specified point in the array-based city
database void printRecordsWithinDistanceArray(int x, int y, double distance)
{
    printf("Records within distance %.2f of (%d, %d):\n", distance, x, y);
    for (int i = 0; i < numCities; i++)
    {
        double dist = calculateDistance(x, y, cityDatabase[i].x, cityDatabase[i].y);
        if (dist <= distance)
        {
            printf("%s (%d, %d) - Distance: %.2f\n", cityDatabase[i].name, cityDatabase[i].x,
                   cityDatabase[i].y, dist);
        }
    }
}
int main()
{
    // Example usage of array-based city database
    insertRecordArray("New York", 10, 20);
    insertRecordArray("Los Angeles", 30, 40);
    insertRecordArray("Chicago", 50, 60);
    searchRecordByNameArray("Los Angeles");
    searchRecordByCoordinatesArray(50, 60);
    deleteRecordByNameArray("Los Angeles");
    deleteRecordByCoordinatesArray(10, 20);
    printRecordsWithinDistanceArray(30, 40, 10.0);
    return 0;
}