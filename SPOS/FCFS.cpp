#include <iostream>
#include <queue>

#include "process.h"

class FCFS
{
private:
    std::queue<Process> proc_queue;

public:
    int addProcess(Process process);
    void schedule();
};

int FCFS::addProcess(Process process)
{
    proc_queue.push(process);
    return proc_queue.size();
}

void FCFS::schedule()
{
    std::cout << "### Schudule ###" << std::endl;
    while (proc_queue.size() != 0)
    {
        Process process = proc_queue.front();
        std::cout << "Process " << process.id << " : \n\tExecuted in " << process.burst_time << " s\n";
        proc_queue.pop();
    }
}

int main()
{
    FCFS fcfs_scheduler;
    Process p1 = Process(1, 5, 0), p2 = Process(2, 10, 1), p3 = Process(3, 5, 2), p4 = Process(4, 8, 3), p5 = Process(5, 15, 5);
    fcfs_scheduler.addProcess(p1);
    fcfs_scheduler.addProcess(p2);
    fcfs_scheduler.addProcess(p3);
    fcfs_scheduler.addProcess(p4);
    fcfs_scheduler.addProcess(p5);
    fcfs_scheduler.schedule();
    return 0;
}