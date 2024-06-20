#include <stdio.h>

struct process
{
    int pid, arrival_time, burst_time, completion_time, turnaround_time, waiting_time, priority, temp;
};

signed main()
{
    int num;
    float total_wt = 0, total_tat = 0, avg_wt, avg_tat;
    printf("Number of processes: ");
    scanf("%d", &num);
    struct process process_arr[num + 1];

    for (int i = 0; i < num; ++i)
    {
        printf("\nDetails for process %d:\n", i + 1);
        printf("Arrival Time: ");
        scanf("%d", &process_arr[i].arrival_time);
        printf("Burst Time: ");
        scanf("%d", &process_arr[i].burst_time);
        process_arr[i].temp = process_arr[i].burst_time;
        printf("Priority: ");
        scanf("%d", &process_arr[i].priority);
    }

    process_arr[num].priority = 1e9;
    int count = 0;
    for (int i = 0; count < num; ++i)
    {
        int now = num;
        for (int j = 0; j < num; ++j)
        {
            if (process_arr[now].priority > process_arr[j].priority && process_arr[j].arrival_time <= i && process_arr[j].burst_time > 0)
            {
                now = j;
            }
        }

        process_arr[now].burst_time--;

        if (process_arr[now].burst_time == 0)
        {
            count++;
            process_arr[now].turnaround_time = i + 1 - process_arr[now].arrival_time - process_arr[now].temp;
            process_arr[now].waiting_time = i + 1 - process_arr[now].arrival_time;
            process_arr[now].completion_time = i + 1;
        }
    }

    printf("PID\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < num; ++i)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", i + 1, process_arr[i].arrival_time, process_arr[i].temp, process_arr[i].completion_time, process_arr[i].waiting_time, process_arr[i].turnaround_time);
    }
}