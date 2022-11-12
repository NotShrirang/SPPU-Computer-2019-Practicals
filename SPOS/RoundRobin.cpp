#include <iostream>
#include <deque>

#include "process.h"

class RoundRobin
{
private:
    std::deque<Process> proc_deque;
    std::deque<Process> done_deque;

public:
    int time_slice = 0;
    RoundRobin(int time_slice)
    {
        this->time_slice = time_slice;
    };
    ~RoundRobin(){};
    int addProcess(Process process);
    void schedule();
};

int RoundRobin::addProcess(Process process)
{
    proc_deque.push_back(process);
    return proc_deque.size();
}
void RoundRobin::schedule()
{
    while (this->proc_deque.size() != 0)
    {
        if (proc_deque.front().burst_time > time_slice)
        {
            Process proc = proc_deque.front();
            proc.burst_time = proc.burst_time - time_slice;
            proc_deque.pop_front();
            proc_deque.push_back(proc);
            std::cout << "Process " << proc.id << " : " << proc.burst_time << " seconds remaining..." << std::endl;
        }
        else
        {
            Process proc = proc_deque.front();
            proc_deque.pop_front();
            done_deque.push_back(proc);
        }
    }
    std::cout << "\n### Schudule ###" << std::endl;
    int proc_no = 1;
    while (done_deque.size() != 0)
    {
        Process process = done_deque.front();
        std::cout << proc_no << ")"
                  << "Process " << process.id << "\n";
        done_deque.pop_front();
        proc_no++;
    }
}

int main()
{
    RoundRobin rr_scheduler = RoundRobin(2);
    Process p1 = Process(1, 10, 0), p2 = Process(2, 8, 1), p3 = Process(3, 12, 2), p4 = Process(4, 10, 3), p5 = Process(5, 14, 5);
    rr_scheduler.addProcess(p1);
    rr_scheduler.addProcess(p2);
    rr_scheduler.addProcess(p3);
    rr_scheduler.addProcess(p4);
    rr_scheduler.addProcess(p5);
    rr_scheduler.schedule();
    return 0;
}