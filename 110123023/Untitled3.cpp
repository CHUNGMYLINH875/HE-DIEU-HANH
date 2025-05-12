#include <stdio.h>

#define MAX 10

// �?nh nghia c?u tr�c d? luu th�ng tin c?a ti?n tr�nh
struct Process {
    int burst_time;   // Th?i gian x? l�
    int arrival_time; // Th?i gian d?n
    int waiting_time; // Th?i gian ch?
    int turnaround_time; // Th?i gian quay v�ng
};

// H�m t�nh th?i gian ch? (waiting time)
void findWaitingTime(struct Process p[], int n) {
    // Th?i gian ch? c?a ti?n tr�nh d?u ti�n lu�n l� 0
    p[0].waiting_time = 0;

    // T�nh to�n th?i gian ch? cho c�c ti?n tr�nh c�n l?i
    for (int i = 1; i < n; i++) {
        p[i].waiting_time = p[i - 1].waiting_time + p[i - 1].burst_time;
    }
}

// H�m t�nh th?i gian quay v�ng (turnaround time)
void findTurnaroundTime(struct Process p[], int n) {
    // T�nh to�n th?i gian quay v�ng cho t?t c? c�c ti?n tr�nh
    for (int i = 0; i < n; i++) {
        p[i].turnaround_time = p[i].waiting_time + p[i].burst_time;
    }
}

// H�m t�nh th?i gian ch? v� quay v�ng trung b�nh
void findAverageTime(struct Process p[], int n) {
    int total_waiting_time = 0;  // T?ng th?i gian ch?
    int total_turnaround_time = 0; // T?ng th?i gian quay v�ng

    // T�nh t?ng th?i gian ch? v� th?i gian quay v�ng
    for (int i = 0; i < n; i++) {
        total_waiting_time += p[i].waiting_time;
        total_turnaround_time += p[i].turnaround_time;
    }

    // T�nh th?i gian ch? trung b�nh v� th?i gian quay v�ng trung b�nh
    float avg_waiting_time = (float) total_waiting_time / n;
    float avg_turnaround_time = (float) total_turnaround_time / n;

    // In k?t qu?
    printf("\nTh?i gian ch? trung b�nh: %.2f", avg_waiting_time);
    printf("\nTh?i gian quay v�ng trung b�nh: %.2f", avg_turnaround_time);
}

int main() {
    int n;
    
    // Nh?p s? lu?ng ti?n tr�nh
    printf("Nh?p s? lu?ng ti?n tr�nh: ");
    scanf("%d", &n);

    struct Process p[n];
    
    // Nh?p th�ng tin cho t?ng ti?n tr�nh
    for (int i = 0; i < n; i++) {
        printf("\nNh?p th?i gian x? l� v� th?i gian d?n cho ti?n tr�nh P%d: ", i + 1);
        scanf("%d %d", &p[i].burst_time, &p[i].arrival_time);
    }

    // T�nh to�n th?i gian ch? v� th?i gian quay v�ng
    findWaitingTime(p, n);
    findTurnaroundTime(p, n);

    // In ra b?ng k?t qu?
    printf("\nTi?n tr�nh\tTh?i gian x? l�\tTh?i gian d?n\tTh?i gian ch?\tTh?i gian quay v�ng\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, p[i].burst_time, p[i].arrival_time, p[i].waiting_time, p[i].turnaround_time);
    }

    // T�nh to�n v� in ra th?i gian ch? trung b�nh v� th?i gian quay v�ng trung b�nh
    findAverageTime(p, n);

    return 0;
}

