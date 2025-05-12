#include <stdio.h>

struct Process {
    int id;         // ID c?a ti?n tr�nh
    int burstTime;  // Th?i gian x? l� CPU
    int arrivalTime; // Th?i gian d?n
    int waitingTime; // Th?i gian ch?
    int turnaroundTime; // Th?i gian quay v�ng
};

void calculateAverageTimes(struct Process processes[], int n) {
    int totalWaitingTime = 0;
    int totalTurnaroundTime = 0;

    // T�nh to�n th?i gian ch? v� th?i gian quay v�ng cho t?ng ti?n tr�nh
    for (int i = 0; i < n; i++) {
        processes[i].turnaroundTime = processes[i].waitingTime + processes[i].burstTime;
        totalTurnaroundTime += processes[i].turnaroundTime;
        totalWaitingTime += processes[i].waitingTime;
    }

    printf("Th?i gian ch? trung b�nh: %.2f\n", (float)totalWaitingTime / n);
    printf("Th?i gian quay v�ng trung b�nh: %.2f\n", (float)totalTurnaroundTime / n);
}

void sjfScheduling(struct Process processes[], int n) {
    int completed = 0, currentTime = 0;
    int minIndex;
    int isCompleted[n];

    // Kh?i t?o m?ng isCompleted
    for (int i = 0; i < n; i++) {
        isCompleted[i] = 0;
        processes[i].waitingTime = 0; // Kh?i t?o th?i gian ch?
    }

    while (completed < n) {
        minIndex = -1;
        int minBurstTime = 9999;

        // T�m ti?n tr�nh c� th?i gian x? l� ng?n nh?t trong s? c�c ti?n tr�nh d� d?n
        for (int i = 0; i < n; i++) {
            if (processes[i].arrivalTime <= currentTime && !isCompleted[i] && processes[i].burstTime < minBurstTime) {
                minBurstTime = processes[i].burstTime;
                minIndex = i;
            }
        }

        // N?u kh�ng c� ti?n tr�nh n�o c� th? th?c hi?n, tang th?i gian hi?n t?i
        if (minIndex == -1) {
            currentTime++;
        } else {
            // C?p nh?t th?i gian ch? cho ti?n tr�nh du?c ch?n
            processes[minIndex].waitingTime = currentTime - processes[minIndex].arrivalTime;
            currentTime += processes[minIndex].burstTime;
            isCompleted[minIndex] = 1; // ��nh d?u ti?n tr�nh d� ho�n th�nh
            completed++;
        }
    }

    calculateAverageTimes(processes, n);
}

int main() {
    struct Process processes[] = {
        {1, 6, 2}, // P1
        {2, 2, 3}, // P2
        {3, 8, 1}, // P3
        {4, 5, 0}, // P4
        {5, 10, 4} // P5
    };
    int n = sizeof(processes) / sizeof(processes[0]);

    sjfScheduling(processes, n);

    return 0;
}
