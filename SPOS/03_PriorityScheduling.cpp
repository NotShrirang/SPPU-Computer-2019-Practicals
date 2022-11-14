#include <iostream>
#include <algorithm>

#include <vector>
#include <queue>
#include <map>

#include "process.h"

class PriorityScheduling
{
private:
    std::multimap<int, Process> proc_dictionary;
    std::queue<Process> done_queue;
    std::vector<Process> proc_vector;

public:
    PriorityScheduling(){};
    ~PriorityScheduling(){};
    int addProcess(Process process);
    void schedule();
    void display();
};
int PriorityScheduling::addProcess(Process process)
{
    proc_vector.push_back(process);
    proc_dictionary.insert(std::pair<int, Process>(process.priority, process));
    return proc_vector.size();
}
void PriorityScheduling::schedule()
{
    while (proc_dictionary.size() != 0)
    {
        auto itr = proc_dictionary.begin();
        Process min_pri_process = itr->second;
        done_queue.push(min_pri_process);
        proc_dictionary.erase(itr->first);
    }
}
void PriorityScheduling::display()
{
    std::cout << "### Schedule ###" << std::endl;
    while (done_queue.size() != 0)
    {
        std::cout << "Process " << done_queue.front().id << " : Priority - " << done_queue.front().priority << std::endl;
        done_queue.pop();
    }
}

int main()
{
    PriorityScheduling PriorityScheduling_scheduler;
    Process p1 = Process(1, 10, 0, 5), p2 = Process(2, 8, 1, 2), p3 = Process(3, 12, 2, 8), p4 = Process(4, 10, 3, 4), p5 = Process(5, 14, 5, 6);
    PriorityScheduling_scheduler.addProcess(p1);
    PriorityScheduling_scheduler.addProcess(p2);
    PriorityScheduling_scheduler.addProcess(p3);
    PriorityScheduling_scheduler.addProcess(p4);
    PriorityScheduling_scheduler.addProcess(p5);
    PriorityScheduling_scheduler.schedule();
    PriorityScheduling_scheduler.display();
    return 0;
}