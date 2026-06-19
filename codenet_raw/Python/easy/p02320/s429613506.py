def loadItemsWithLimit():
	items = {
		"value": [],
		"weight": [],
		"limit": []
	}
	line = input().strip().split(" ")
	N, maxW = int(line[0]), int(line[1])
	while True:
		info = input().strip().split(" ")
		items["value"].append(int(info[0]))
		items["weight"].append(int(info[1]))
		items["limit"].append(int(info[2]))
		if len(items["value"]) == N: break
	return items, N, maxW

def knapsackWithLimit():
	memo = [-1 for i in range(maxW+1)]
	memo[0] = 0
	for idx, itr in enumerate(items["limit"]):
		weight, value = items["weight"][idx], items["value"][idx]
		for _ in range(itr):
			for i in reversed(range(maxW+1)):
				if memo[i-weight] != -1: pass
				else: continue
				if 0 <= i-weight <= maxW:
					memo[i] = max(memo[i], memo[i-weight] + value)
	print(max(memo))

import math
items, N, maxW = loadItemsWithLimit()
knapsackWithLimit()