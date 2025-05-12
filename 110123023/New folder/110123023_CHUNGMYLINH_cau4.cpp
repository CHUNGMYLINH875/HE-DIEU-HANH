#include <stdio.h>

struct Process {
    int id;
    int burst_time;
    int priority;
    int waiting_time;
    int turnaround_time;
};

void sortByPriority(struct Process p[], int n) {
    struct Process temp;
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (p[i].priority > p[j].priority) {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
}

int main() {
    int n = 4;
    struct Process p[] = {
        {1, 4, 1},
        {2, 3, 3},
        {3, 17, 4},
        {4, 5, 2}
    };

    sortByPriority(p, n);

   
    p[0].waiting_time = 0;
    for (int i = 1; i < n; i++) {
        p[i].waiting_time = 0;
        for (int j = 0; j < i; j++) {
            p[i].waiting_time += p[j].burst_time;
        }
    }

    
    for (int i = 0; i < n; i++) {
        p[i].turnaround_time = p[i].waiting_time + p[i].burst_time;
    }

    
    printf("Process\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\n", p[i].id, p[i].burst_time, p[i].priority, p[i].waiting_time, p[i].turnaround_time);
    }

   
    float avg_wait = 0, avg_turnaround = 0;
    for (int i = 0; i < n; i++) {
        avg_wait += p[i].waiting_time;
        avg_turnaround += p[i].turnaround_time;
    }

    printf("Average Waiting Time = %.2f\n", avg_wait / n);
    printf("Average Turnaround Time = %.2f\n", avg_turnaround / n);

    return 0;
}

