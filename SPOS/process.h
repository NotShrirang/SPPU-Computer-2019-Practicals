/* Class for Process */

class Process
{
public:
    int id = -1, burst_time = -1, arrival_time = -1, priority = -1;
    Process(int id, int burst_time, int arrival_time, int priority = -1)
    {
        this->id = id;
        this->burst_time = burst_time;
        this->priority = priority;
        this->arrival_time = arrival_time;
    };
    ~Process(){};
};