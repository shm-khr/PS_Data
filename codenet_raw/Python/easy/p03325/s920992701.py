import math
import copy
import sys
import fractions
import numpy as np
from functools import reduce
import statistics


# ===FUNCTION===

def getInputInt():
    inputNum = int(input())
    return inputNum


def getInputListInt():
    outputData = []
    inputData = input().split()
    outputData = [int(n) for n in inputData]

    return outputData


def getSomeInputInt(n):
    outputDataList = []
    for i in range(n):
        inputData = int(input())
        outputDataList.append(inputData)

    return outputDataList


def getSomeInputListInt(n):
    inputDataList = []
    outputDataList = []
    for i in range(n):
        inputData = input().split()
        inputDataList = [int(n) for n in inputData]
        outputDataList.append(inputDataList)

    return outputDataList


# ===CODE===

def gettwice(n, cnt):
    if n % 2 == 1:
       return cnt

    return gettwice(n/2, cnt+1)

n = getInputInt()
data = getInputListInt()

ans = 0
tmpans = 0

oddData = []
evenData = []

for i in range(len(data)):
    if data[i] % 2 == 0:
        evenData.append(data[i])
    else:
        oddData.append((data[i]))

maxOddNum = max(oddData)

for i in range(len(evenData)):
        tmpans += gettwice(evenData[i], 0)

# counter = 0
# for i in range(int(tmpans)):
#     maxOddNum = maxOddNum * 3
#     if maxOddNum > 1000000000:
#         break
#     counter = i+1

# ans = min(tmpans, counter)

print(tmpans)