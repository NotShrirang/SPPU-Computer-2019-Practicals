class Process():
    def __init__(self, name: str, arrivalTime:int , burstTime: int) -> None:
        self.name = name
        self.arrivalTime = arrivalTime
        self.burstTime = burstTime 


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
    def __init__(self, type: str = "roundrobin") -> None:
        self.process_queue: list[str] = []
        self.process_done_queue: list[str] = []
        self.scheduler = type

    def schedule(self, queue: Queue, timeSlice: int = 5) -> None:
        while len(queue.processes) != 0:
            if queue.processes[0].burstTime > timeSlice:
                queue.processes[0].burstTime = queue.processes[0].burstTime - timeSlice
                print(f"{queue.processes[0].name} - {queue.processes[0].burstTime}")
                self.process_queue.append(queue.processes[0].name)
                process = queue.remove()
                queue.insert(process)
            else:
                print(f"{queue.processes[0].name} removed!")
                self.process_queue.append(queue.processes[0].name)
                self.process_done_queue.append(queue.processes[0].name)
                queue.remove()
        print(self.process_queue)
        print(self.process_done_queue)


if __name__ == "__main__":
    p1 = Process(name="p1", arrivalTime=0, burstTime=5)
    p2 = Process(name="p2", arrivalTime=1, burstTime=6)
    p3 = Process(name="p3", arrivalTime=2, burstTime=3)
    p4 = Process(name="p4", arrivalTime=3, burstTime=1)
    p5 = Process(name="p5", arrivalTime=4, burstTime=5)
    p6 = Process(name="p6", arrivalTime=5, burstTime=4)

    q = Queue(total_processes=6)
    q.insert(p1)
    q.insert(p2)
    q.insert(p3)
    q.insert(p4)
    q.insert(p5)
    q.insert(p6)
    q.display()

    s = Scheduler()
    s.schedule(q, timeSlice=2)
