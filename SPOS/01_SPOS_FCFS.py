class FCFS():
	def __init__(self, n: int)->None:			
		self.n = n
		self.processMatrix = [{} for _ in range(n)]		
		self.totalProcesses = [i for i in range(n)]		
		self.avgWaitingTime = 0
		self.avgTurnAroundTime = 0

	def addProcess(self, name: str, burstTime: int, arrivalTime: int) -> int:
		if arrivalTime == 1:
			process = {"Process" : name, "burstTime" : burstTime, "arrivalTime" : arrivalTime, "waitingTime" : 0, "turnAroundTime" : burstTime}
			self.processMatrix[arrivalTime-1] = process
		else:
			process = {"Process" : name, "burstTime" : burstTime, "arrivalTime" : arrivalTime, "waitingTime" : 0, "turnAroundTime" : 0}
			self.processMatrix[arrivalTime-1] = process
		return self.totalProcesses

	def calculate(self) -> None:
		totalWaitingTime = self.processMatrix[0]["waitingTime"]
		totalTATime = self.processMatrix[0]["turnAroundTime"]
		for i in range(1, self.n):
			prevProc = self.processMatrix[i-1]
			self.processMatrix[i]["waitingTime"] = prevProc["turnAroundTime"]
			self.processMatrix[i]["turnAroundTime"] = self.processMatrix[i]["waitingTime"] + self.processMatrix[i]["burstTime"]
			totalWaitingTime = totalWaitingTime + self.processMatrix[i]["waitingTime"]
			totalTATime = totalTATime + self.processMatrix[i]["turnAroundTime"]
		self.avgWaitingTime = totalWaitingTime/self.n
		self.avgTurnAroundTime = totalTATime/self.n

	def display(self) -> None:
		print("\n===================== Process Scheduler ======================\n")
		for i in range(self.n):
			print(self.processMatrix[i], "\n")
		print("Avg. waiting time : ", self.avgWaitingTime)
		print("Avg. turn around time : ", self.avgTurnAroundTime)	
		print("\n==============================================================\n")

if __name__ == "__main__":
	i = int(input("Total processes : "))
	f = FCFS(n = i)
	for n in range(i):
		name = input(f"\nProcess name {n+1}: ")
		BurstTime = int(input("BurstTime : "))
		ArrivalTime = int(input("ArrivalTime : "))
		f.addProcess(name = name, burstTime = BurstTime, arrivalTime = ArrivalTime)
	f.calculate()
	f.display()
