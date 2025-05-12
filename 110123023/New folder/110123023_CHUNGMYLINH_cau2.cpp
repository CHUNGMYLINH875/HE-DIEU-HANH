#include <stdio.h>

typedef struct {
    int pid;
    int arrival_time;
    int burst_time;
    int remaining_time;
    int waiting_time;
    int turnaround_time;
    int completion_time;
} Process;

int main() {
    int n = 5;
    Process p[] = {
        {1, 2, 6, 6, 0, 0, 0},
        {2, 3, 2, 2, 0, 0, 0},
        {3, 1, 8, 8, 0, 0, 0},
        {4, 0, 5, 5, 0, 0, 0},
        {5, 4, 10, 10, 0, 0, 0}
    };
    
    int complete = 0, time = 0, minm = 1e9;
    int shortest = -1, finish_time;
    int check = 0;
    float total_waiting_time = 0, total_turnaround_time = 0;
    
    printf("Gantt Chart: ");
    while (complete != n) {
        minm = 1e9;
        shortest = -1;
        
        for (int j = 0; j < n; j++) {
            if (p[j].arrival_time <= time && p[j].remaining_time > 0 && p[j].remaining_time < minm) {
                minm = p[j].remaining_time;
                shortest = j;
                check = 1;
            }
        }

        if (check == 0) {
            time++;
            continue;
        }
        
        printf("P%d ", p[shortest].pid);
        
        p[shortest].remaining_time--;

        if (p[shortest].remaining_time == 0) {
            complete++;
            finish_time = time + 1;
            p[shortest].completion_time = finish_time;
            p[shortest].waiting_time = finish_time - p[shortest].burst_time - p[shortest].arrival_time;
            if (p[shortest].waiting_time < 0)
                p[shortest].waiting_time = 0;
        }
        time++;
    }
    
    for (int i = 0; i < n; i++) {
        p[i].turnaround_time = p[i].burst_time + p[i].waiting_time;
        total_waiting_time += p[i].waiting_time;
        total_turnaround_time += p[i].turnaround_time;
    }
    
    printf("\n\nProcess\tArrival\tBurst\tWaiting\tTurnaround\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].arrival_time, p[i].burst_time, p[i].waiting_time, p[i].turnaround_time);
    }
    
    printf("\nAverage Waiting Time = %.2f\n", total_waiting_time / n);
    printf("Average Turnaround Time = %.2f\n", total_turnaround_time / n);
    
    return 0;
}
