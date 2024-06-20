#include <stdio.h>

struct process
{
    int pid, arrival_time, burst_time, remaining_time, completion_time, turnaround_time, waiting_time;
};

signed main()
{
    int num;
    printf("Number of processes: ");
    scanf("%d", &num);
    struct process process_arr[num];
    for (int i = 0; i < num; ++i)
    {
        process_arr[i].pid = i + 1;
        printf("Details for process %d:\n", process_arr[i].pid);
        printf("Arrival Time: ");
        scanf("%d", &process_arr[i].arrival_time);
        printf("Burst Time: ");
        scanf("%d", &process_arr[i].burst_time);
        process_arr[i].remaining_time = process_arr[i].burst_time;
    }

    int time = 0;
    while (1)
    {
        int rem_time = 1e9, idx = -1;

        for (int i = 0; i < num; ++i)
        {
            if (process_arr[i].arrival_time <= time && process_arr[i].remaining_time < rem_time && process_arr[i].remaining_time > 0)
            {
                rem_time = process_arr[i].remaining_time;
                idx = i;
            }
        }

        if (idx == -1)
            break;

        process_arr[idx].remaining_time--;
        time++;

        if (process_arr[idx].remaining_time == 0)
        {
            process_arr[idx].completion_time = time;
            process_arr[idx].turnaround_time = process_arr[idx].completion_time - process_arr[idx].arrival_time;
            process_arr[idx].waiting_time = process_arr[idx].turnaround_time - process_arr[idx].burst_time;
        }
    }

    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < num; ++i)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", process_arr[i].pid, process_arr[i].arrival_time, process_arr[i].burst_time, process_arr[i].completion_time, process_arr[i].turnaround_time, process_arr[i].waiting_time);
    }

    float avg_turnaround_time = 0, avg_waiting_time = 0;
    for (int i = 0; i < num; ++i)
    {
        avg_turnaround_time += process_arr[i].turnaround_time;
        avg_waiting_time += process_arr[i].waiting_time;
    }
    avg_turnaround_time /= num;
    avg_waiting_time /= num;
    printf("\nAverage turnaround time: %.2f\nAverage waiting time: %.2f\n", avg_turnaround_time, avg_waiting_time);
}