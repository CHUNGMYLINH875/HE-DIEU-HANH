#include <stdio.h>

typedef struct {
    int pid;
    int arrival_time;
    int burst_time;
    int waiting_time;
    int turnaround_time;
    int completed;
} Process;

int main() {
    int n = 5;
    Process p[] = {
        {1, 2, 6, 0, 0, 0},
        {2, 3, 2, 0, 0, 0},
        {3, 1, 8, 0, 0, 0},
        {4, 0, 5, 0, 0, 0},
        {5, 4, 10, 0, 0, 0}
    };
    
    int time = 0, completed = 0;
    float total_waiting_time = 0, total_turnaround_time = 0;
    
    printf("Gantt Chart: ");
    while (completed < n) {
        int idx = -1;
        int min_burst = 1e9;
        for (int i = 0; i < n; i++) {
            if (p[i].arrival_time <= time && p[i].completed == 0) {
                if (p[i].burst_time < min_burst) {
                    min_burst = p[i].burst_time;
                    idx = i;
                }
                else if (p[i].burst_time == min_burst) {
                    if (p[i].arrival_time < p[idx].arrival_time) {
                        idx = i;
                    }
                }
            }
        }

        if (idx != -1) {
            p[idx].waiting_time = time - p[idx].arrival_time;
            time += p[idx].burst_time;
            p[idx].turnaround_time = p[idx].waiting_time + p[idx].burst_time;
            p[idx].completed = 1;
            completed++;
            printf("P%d ", p[idx].pid);
            
            total_waiting_time += p[idx].waiting_time;
            total_turnaround_time += p[idx].turnaround_time;
        } else {
            time++;
        }
    }
    
    printf("\n\nProcess\tArrival\tBurst\tWaiting\tTurnaround\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].arrival_time, p[i].burst_time, p[i].waiting_time, p[i].turnaround_time);
    }
    
    printf("\nAverage Waiting Time = %.2f\n", total_waiting_time / n);
    printf("Average Turnaround Time = %.2f\n", total_turnaround_time / n);
    
    return 0;
}
