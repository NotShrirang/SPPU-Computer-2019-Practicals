/* Class for Process */

class Process
{
public:
    int id = -1, burst_time = -1, arrival_time = -1, priority = -1;
    Process(int id, int burst_time, int arrival_time, int priority = -1)
    {
        this->id = id;
        this->burst_time = burst_time;
        this->arrival_time = arrival_time;
        if (priority != -1)
        {
            if (priority > 0 && priority < 10)
            {
                this->priority = priority;
            }
            else
            {
                std::cout << "ERROR: "
                          << "while allocating Process " << this->id << "\nPriorityError: Priority should be between 1 and 10." << std::endl;
                exit(1);
            }
        }
        else
        {
            this->priority = priority;
        }
    };
    ~Process(){};
};