class SJF():
    def __init__(self, n: int) -> None:
        self.n = n
        self.processMatrix = [{} for i in range(n)]		
        self.totalProcesses = [i for i in range(n)]		
        self.avgWaitingTime = 0
        self.avgTurnAroundTime = 0
        self.burstTimeDict = {}
        self.SJFQueue = []
    
    def addProcess(self, name: str, burstTime: int, arrivalTime: int) -> int:
        if arrivalTime == 1:
            process = {"Process" : name, "burstTime" : burstTime, "arrivalTime" : arrivalTime, "waitingTime" : 0, "turnAroundTime" : burstTime}
            self.processMatrix[arrivalTime-1] = process
            self.burstTimeDict[burstTime] = name
        else:
            process = {"Process" : name, "burstTime" : burstTime, "arrivalTime" : arrivalTime, "waitingTime" : 0, "turnAroundTime" : 0}
            self.processMatrix[arrivalTime-1] = process
            self.burstTimeDict[burstTime] = name
        return self.totalProcesses
    
    def sort(self) -> None:
        for _ in range(self.n):
            min_burst_time: int = min(self.burstTimeDict.keys())
            min_process_name: str = self.burstTimeDict[min_burst_time]
            self.SJFQueue.append((min_process_name, min_burst_time))
            self.burstTimeDict.pop(min_burst_time)

    def display(self) -> None:
        print(self.SJFQueue, sep=" ")

if __name__ == "__main__":
    i = int(input("Total processes : "))
    f = SJF(n = i)
    for n in range(i):
        name = input(f"\nProcess name {n+1}: ")
        BurstTime = int(input("BurstTime : "))
        ArrivalTime = int(input("ArrivalTime : "))
        f.addProcess(name = name, burstTime = BurstTime, arrivalTime = ArrivalTime)

    f.sort()
    f.display()
