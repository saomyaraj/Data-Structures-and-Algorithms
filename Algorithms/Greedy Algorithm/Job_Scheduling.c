#include<stdio.h>
#include<stdlib.h>

//Structure to represent the job
struct Job {
    int id; //Job id
    int start; //start time of the job
    int finish; //finish time of the job
};

// Function to compare two jobs based on their finish times
int compare(const void* a, const void*b) {
    return ((struct Job*)a)->finish - ((struct Job*)b)->finish;
}

// Function to schedule jobs and print the schedule
void scheduleJobs(struct Job jobs[], int n) {
    //Sort jobs based on their finish times
    qsort(jobs, n, sizeof(struct Job), compare);

    //initialize variables
    int prevFinish = jobs[0].finish;
    printf("Scheduled Jobs:\n");
    printf("Job ID\tStart Time\tFinish Time\n");
    printf("%d\t%d\t\t%d\n", jobs[0].id, jobs[0].start, jobs[0].finish);

    //iterate through the remaining jobs
    for (int i=1; i<n; i++) {
        //if the start time of the current job is greater than or equal to the finish time of the previous job, schedule the current job abd update prevfinish
        if (jobs[i].start >= prevFinish) {
            printf("%d\t%d\t\t%d\n", jobs[i].id, jobs[i].start, jobs[i].finish);
            prevFinish = jobs[i].finish;
        }
    }
}

int main() {
    //example array of jobs
    struct Job jobs[] = { {1, 1, 2}, {2, 3, 4}, {3, 0, 6}, {4, 5, 7}, {5, 8, 9} };
    int n = sizeof(jobs) / sizeof(jobs[0]);

    //schedule jobs and print the schedule
    scheduleJobs(jobs, n);

    return 0;
}