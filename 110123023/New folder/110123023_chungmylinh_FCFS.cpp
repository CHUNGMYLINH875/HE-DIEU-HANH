#include <stdio.h>

#define MAX 10


struct Process {
    int burst_time;   
    int arrival_time; 
    int waiting_time;
    int turnaround_time; 
};


void findWaitingTime(struct Process p[], int n) {
   
    p[0].waiting_time = 0;

 
    for (int i = 1; i < n; i++) {
        p[i].waiting_time = p[i - 1].waiting_time + p[i - 1].burst_time;
    }
}


void findTurnaroundTime(struct Process p[], int n) {
   
    for (int i = 0; i < n; i++) {
        p[i].turnaround_time = p[i].waiting_time + p[i].burst_time;
    }
}


void findAverageTime(struct Process p[], int n) {
    int total_waiting_time = 0;  
    int total_turnaround_time = 0; 

   
    for (int i = 0; i < n; i++) {
        total_waiting_time += p[i].waiting_time;
        total_turnaround_time += p[i].turnaround_time;
    }

    float avg_waiting_time = (float) total_waiting_time / n;
    float avg_turnaround_time = (float) total_turnaround_time / n;

   
    printf("\nThoi gian cho trung binh: %.2f", avg_waiting_time);
    printf("\nThoi gian quay vong trung binh: %.2f", avg_turnaround_time);
}

int main() {
    int n;
    
    printf("Nhap so long tien trinh: ");
    scanf("%d", &n);

    struct Process p[n];
    
  
    for (int i = 0; i < n; i++) {
        printf("\nNhap thoi gian xu ly và thoi gian den cho tien trinh P%d: ", i + 1);
        scanf("%d %d", &p[i].burst_time, &p[i].arrival_time);
    }

   
    findWaitingTime(p, n);
    findTurnaroundTime(p, n);

   
    printf("\nTien Trinh\tThoi gian xu ly\tThoi gian den\tThoi gian cho\tThoi gian quay vong\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, p[i].burst_time, p[i].arrival_time, p[i].waiting_time, p[i].turnaround_time);
    }

    findAverageTime(p, n);

    return 0;
}

