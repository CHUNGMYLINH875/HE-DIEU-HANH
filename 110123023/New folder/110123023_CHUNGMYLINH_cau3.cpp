#include <stdio.h>

int main() {
    int n = 3; 
    int burst_time[] = {4, 3, 10};
    int remaining_time[] = {4, 3, 10};
    int wait_time[3] = {0, 0, 0};
    int turnaround_time[3] = {0, 0, 0};
    int quantum = 2;
    int time = 0; 
    int done;

    do {
        done = 1;
        for (int i = 0; i < n; i++) {
            if (remaining_time[i] > 0) {
                done = 0;
                if (remaining_time[i] > quantum) {
                    time += quantum;
                    remaining_time[i] -= quantum;
                } else {
                    time += remaining_time[i];
                    wait_time[i] = time - burst_time[i];
                    remaining_time[i] = 0;
                }
            }
        }
    } while (!done);

    
    for (int i = 0; i < n; i++) {
        turnaround_time[i] = burst_time[i] + wait_time[i];
    }

 
    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\n", i+1, burst_time[i], wait_time[i], turnaround_time[i]);
    }

   
    float avg_wait = 0, avg_turnaround = 0;
    for (int i = 0; i < n; i++) {
        avg_wait += wait_time[i];
        avg_turnaround += turnaround_time[i];
    }
    printf("Average waiting time = %.2f\n", avg_wait / n);
    printf("Average turnaround time = %.2f\n", avg_turnaround / n);

    return 0;
}
					
				
