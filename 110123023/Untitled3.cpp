#include <stdio.h>

#define MAX 10

// Ð?nh nghia c?u trúc d? luu thông tin c?a ti?n trình
struct Process {
    int burst_time;   // Th?i gian x? lý
    int arrival_time; // Th?i gian d?n
    int waiting_time; // Th?i gian ch?
    int turnaround_time; // Th?i gian quay vòng
};

// Hàm tính th?i gian ch? (waiting time)
void findWaitingTime(struct Process p[], int n) {
    // Th?i gian ch? c?a ti?n trình d?u tiên luôn là 0
    p[0].waiting_time = 0;

    // Tính toán th?i gian ch? cho các ti?n trình còn l?i
    for (int i = 1; i < n; i++) {
        p[i].waiting_time = p[i - 1].waiting_time + p[i - 1].burst_time;
    }
}

// Hàm tính th?i gian quay vòng (turnaround time)
void findTurnaroundTime(struct Process p[], int n) {
    // Tính toán th?i gian quay vòng cho t?t c? các ti?n trình
    for (int i = 0; i < n; i++) {
        p[i].turnaround_time = p[i].waiting_time + p[i].burst_time;
    }
}

// Hàm tính th?i gian ch? và quay vòng trung bình
void findAverageTime(struct Process p[], int n) {
    int total_waiting_time = 0;  // T?ng th?i gian ch?
    int total_turnaround_time = 0; // T?ng th?i gian quay vòng

    // Tính t?ng th?i gian ch? và th?i gian quay vòng
    for (int i = 0; i < n; i++) {
        total_waiting_time += p[i].waiting_time;
        total_turnaround_time += p[i].turnaround_time;
    }

    // Tính th?i gian ch? trung bình và th?i gian quay vòng trung bình
    float avg_waiting_time = (float) total_waiting_time / n;
    float avg_turnaround_time = (float) total_turnaround_time / n;

    // In k?t qu?
    printf("\nTh?i gian ch? trung bình: %.2f", avg_waiting_time);
    printf("\nTh?i gian quay vòng trung bình: %.2f", avg_turnaround_time);
}

int main() {
    int n;
    
    // Nh?p s? lu?ng ti?n trình
    printf("Nh?p s? lu?ng ti?n trình: ");
    scanf("%d", &n);

    struct Process p[n];
    
    // Nh?p thông tin cho t?ng ti?n trình
    for (int i = 0; i < n; i++) {
        printf("\nNh?p th?i gian x? lý và th?i gian d?n cho ti?n trình P%d: ", i + 1);
        scanf("%d %d", &p[i].burst_time, &p[i].arrival_time);
    }

    // Tính toán th?i gian ch? và th?i gian quay vòng
    findWaitingTime(p, n);
    findTurnaroundTime(p, n);

    // In ra b?ng k?t qu?
    printf("\nTi?n trình\tTh?i gian x? lý\tTh?i gian d?n\tTh?i gian ch?\tTh?i gian quay vòng\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, p[i].burst_time, p[i].arrival_time, p[i].waiting_time, p[i].turnaround_time);
    }

    // Tính toán và in ra th?i gian ch? trung bình và th?i gian quay vòng trung bình
    findAverageTime(p, n);

    return 0;
}

