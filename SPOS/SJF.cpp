#include <iostream>
#include <algorithm>

#include <vector>
#include <queue>
#include <map>

#include "process.h"

class SJF
{
private:
    std::multimap<int, Process> proc_dictionary;
    std::queue<Process> done_queue;
    std::vector<Process> proc_vector;

public:
    SJF(){};
    ~SJF(){};
    int addProcess(Process process);
    void schedule();
    void display();
};

int SJF::addProcess(Process process)
{
    proc_vector.push_back(process);
    proc_dictionary.insert(std::pair<int, Process>(process.burst_time, process));
    return proc_vector.size();
}
void SJF::schedule()
{
    while (proc_vector.size() != 0)
    {
        std::pair<int, Process> min_burst_time_pair = *min_element(proc_dictionary.begin(), proc_dictionary.end());
        done_queue.push(min_burst_time_pair.second);
        proc_dictionary.erase(min_burst_time_pair.first);
    }
}
void SJF::display()
{
    while (done_queue.size() != 0)
    {
        std::cout << "Process " << done_queue.front().id << " : Burst Time : " << done_queue.front().burst_time << std::endl;
    }
}

int main()
{
    SJF sjf_scheduler;
    Process p1 = Process(1, 10, 0), p2 = Process(2, 8, 1), p3 = Process(3, 12, 2), p4 = Process(4, 10, 3), p5 = Process(5, 14, 5);
    sjf_scheduler.addProcess(p1);
    sjf_scheduler.addProcess(p2);
    sjf_scheduler.addProcess(p3);
    sjf_scheduler.addProcess(p4);
    sjf_scheduler.addProcess(p5);
    sjf_scheduler.schedule();
    return 0;
}