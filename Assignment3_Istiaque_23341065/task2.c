#include <stdio.h>

struct process
{
    int pid, burst_time, remaining_time, completion_time, turnaround_time, waiting_time, ok;
};

signed main()
{
    int num, time_quantum;
    printf("Number of processes: ");
    scanf("%d", &num);
    printf("Time quantum: ");
    scanf("%d", &time_quantum);
    struct process process_arr[num];
    for (int i = 0; i < num; ++i)
    {
        printf("Burst time of process %d: ", i + 1);
        scanf("%d", &process_arr[i].burst_time);
        process_arr[i].pid = i + 1;
        process_arr[i].remaining_time = process_arr[i].burst_time;
        process_arr[i].ok=0;
    }

    int time = 0;
    while (1)
    {
        int now = 1;
        for (int i = 0; i < num; ++i)
        {
            if (!process_arr[i].ok)
            {
                now = 0;
                if (process_arr[i].remaining_time > time_quantum)
                {
                    process_arr[i].remaining_time -= time_quantum;
                    time += time_quantum;
                }
                else
                {
                    time += process_arr[i].remaining_time;
                    process_arr[i].remaining_time = 0;
                    process_arr[i].ok = 1;
                    process_arr[i].completion_time = time;
                    process_arr[i].turnaround_time = process_arr[i].completion_time;
                    process_arr[i].waiting_time = process_arr[i].turnaround_time - process_arr[i].burst_time;
                }
            }
        }
        if (now)
            break;
    }

    printf("\n");
    printf("process\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < num; ++i)
    {
        printf("%d\t%d\t%d\t%d\t%d\n", process_arr[i].pid, process_arr[i].burst_time, process_arr[i].completion_time, process_arr[i].turnaround_time, process_arr[i].waiting_time);
    }
}