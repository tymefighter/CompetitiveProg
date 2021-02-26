from random import randint
import copy

def generate_random(n):
    arr = [[None for i in range(n)] for i in range(n)]

    for i in range(n):
        for j in range(n):
            arr[i][j] = randint(0, 1)

    return arr

test_cases = [
    [[0, 0, 1, 0, 1, 0, 0], [0, 0, 1, 0, 1, 1, 1], [0, 0, 1, 1, 0, 0, 1], [1, 1, 1, 0, 0, 1, 0], [0, 1, 0, 0, 0, 1, 0], [1, 0, 0, 1, 0, 1, 1], [0, 0, 0, 0, 1, 1, 0]]
]

fl = open('log.txt', 'w')

def computeNumSq(arr):
    n = len(arr)
    numSq = 0

    for i in range(n - 1):
        for j in range(n - 1):
            if (
                arr[i][j] == 0
                and
                arr[i][j + 1] == 1
                and
                arr[i + 1][j] == 1
                and
                arr[i + 1][j + 1] == 0
            ):
                numSq += 1

    return numSq

def query(arr, i, j):
    arr[i][j] = 1 - arr[i][j]
    k = computeNumSq(arr)
    print(k)

def isEqual(arr1, arr2):
    n = len(arr1)
    for i in range(n):
        for j in range(n):
            if arr1[i][j] != arr2[i][j]:
                return False
    
    return True

def finalQuery(initArr, arr):
    n = len(arr)
    inputArr = []

    for i in range(n):
        line = input().split()
        inputArr.append([int(x) for x in line])

    if isEqual(arr, inputArr):
        print(1)
    else:
        print(-1)
        fl.write(str(inputArr) + '\n')
        fl.write(str(arr) + '\n')
        fl.write(str(initArr) + '\n')
        fl.write('Fail - Wrong Answer')
        exit(0)

def performInteraction(arr, q, k):

    initArr = copy.deepcopy(arr)

    while True:
        line = input().split()

        if line[0] == '1':
            if q <= 0:
                print('-1')
                fl.write('Fail - Out of Queries')
                exit(0)
            
            query(arr, int(line[1]) - 1, int(line[2]) - 1)
            q -= 1
        
        else:
            finalQuery(initArr, arr)
            break

def main():
    
    t = len(test_cases)
    print(t)

    for arr in test_cases:
        n = len(arr)
        q = 4 * n * n
        k = computeNumSq(arr)

        print(n, q, k)
        performInteraction(arr, q, k)

        fl.write('Pass\n')
    
    fl.close()

if __name__ == '__main__':
    main()
