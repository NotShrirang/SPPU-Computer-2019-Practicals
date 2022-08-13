class Process():
    def __init__(self, name: str, arrivalTime:int , burstTime: int, priority: int) -> None:
        if (priority<1 or priority>10):
            raise(Exception("Priority Value is always between 1 to 10"))
        self.name = name
        self.arrivalTime = arrivalTime
        self.burstTime = burstTime
        self.priority = priority

class Queue():
    def __init__(self, total_processes: int) -> None:
        self.total_processes = total_processes
        self.processes: list[Process] = []

    def remove(self) -> Process:
        return self.processes.pop(0)

    def insert(self, val: Process) -> None:
        self.processes.append(val)

    def display(self) -> None:
        print("\n#### Queue ####")
        for p in self.processes:
            print(p.name, p.arrivalTime, p.burstTime)
        print("###############")

class Scheduler():
    def __init__(self, type: str = "priority") -> None:
        self.process_done_queue: list[str] = []
        self.schedulerType = type

    def schedule(self, queue: Queue) -> None:
        self.process_done_queue.append(queue.processes[0].name)
        queue.remove()
        while len(queue.processes) != 0:
            min_pri: int = 10
            min_proc_index: int = 0
            i = 0
            for proc in queue.processes:
                if(proc.priority < min_pri):
                    min_proc_index = i
                    min_pri = proc.priority
                i += 1
            self.process_done_queue.append(queue.processes[min_proc_index].name)
            queue.processes.pop(min_proc_index)
        print(self.process_done_queue)

if __name__ == "__main__":
    i = int(input("Total processes : "))
    q = Queue(i)
    for n in range(i):
        name = input(f"\nProcess name {n+1}: ")
        arrivalTime = int(input("ArrivalTime : "))
        burstTime = int(input("BurstTime : "))
        priority = int(input("Priority : "))
        proc = Process(name, arrivalTime, burstTime, priority)
        q.insert(proc)
    scheduler = Scheduler()
    scheduler.schedule(q)
