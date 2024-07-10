#include <stdio.h>

// Structure to represent an activity
struct Activity {
  int start;
  int finish;
};

// Function to compare two activities based on their finishing time
int compareActivities(const void* a, const void* b) {
  struct Activity* activity1 = (struct Activity*)a;
  struct Activity* activity2 = (struct Activity*)b;
  return activity1->finish - activity2->finish;
}

// Function to print selected activities
void printActivities(struct Activity activities[], int n) {
  printf("Selected Activities are:\n");
  printf("Start Time  \tFinish Time\n");
  for (int i = 0; i < n; i++) {
    printf("%d \t\t %d\n", activities[i].start, activities[i].finish);
  }
}

// Activity selection algorithm
void selectActivities(struct Activity activities[], int n) {
  // Sort activities by their finishing time
  qsort(activities, n, sizeof(struct Activity), compareActivities);

  // Include the first activity in the solution
  int i = 0;
  printf("Following activities can be done without conflict:\n");

  // Traverse through the remaining activities
  for (int j = 1; j < n; j++) {
    // If this activity is not conflicting with the previous activity, add it to the solution
    if (activities[j].start >= activities[i].finish) {
      printf("(%d , %d) ", activities[j].start, activities[j].finish);
      i = j;
    }
  }
  printf("\n");
}

int main() {
  int n;
  printf("Enter the number of activities: ");
  scanf("%d", &n);

  struct Activity activities[n];
  printf("Enter start and finish times for each activity:\n");
  for (int i = 0; i < n; i++) {
    scanf("%d %d", &activities[i].start, &activities[i].finish);
  }

  selectActivities(activities, n);

  return 0;
}