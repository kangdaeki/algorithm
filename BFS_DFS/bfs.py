my_graph=[ # a list of sets for adjacent nodes
    {1,4}, # 0
    {0,2,5}, # 1
    {1,3,6}, # 2
    {2,7}, # 3
    {0,8}, # 4
    {1,6,10}, # 5
    {2,5,11}, # 6
    {3,12}, # 7
    {4,9}, # 8
    {8,10}, # 9
    {5,9,11}, # 10
    {6,10,12}, # 11
    {7,11}, # 12
    ]
N=13
visited=[]
for i in range(N):
    visited.append(False)
from collections import deque
dequeue1=deque()
# 실제 BFS 코드 시작
visited[0]=True
dequeue1.append(0)
while dequeue1: # while dequeue1 is not empty
    index=dequeue1.popleft()
    print(index,end='->')
    for node in my_graph[index]:
        if False==visited[node]:
            visited[node]=True
            dequeue1.append(node)
print()



