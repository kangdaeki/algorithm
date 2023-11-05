class Node:
    def __init__(self, number, distance):
        self.number=number
        self.distance=distance
    def __lt__(self, other):
        return self.distance<other.distance

class Edge:
    def __init__(self, u, v, weight):
        self.u=u
        self.v=v
        self.weight=weight

# Read data
import sys
f_name=open(sys.argv[1],mode='r')
no_nodes=int(f_name.readline())
V=[]
heap_q=[]
visited=[]
import sys
import heapq
for i in range(no_nodes):
    if i==0:
        node=Node(i+1,0)
    else:
        node=Node(i+1,sys.maxsize)
    V.append(node)
    heapq.heappush(heap_q,node)
    visited.append(False)

E=[]
a_dict={} # adjacency list
# Python 3.8
while line:=f_name.readline():
    numbers=line.split()
    u=int(numbers[0])
    v=int(numbers[1])
    w=int(numbers[2])
    n_edge=Edge(u,v,w)
    E.append(n_edge)
    if u in a_dict:
        l=a_dict[u]
        l.append(n_edge)
    else:
        a_dict[u]=[n_edge]
    if v in a_dict:
        l=a_dict[v]
        l.append(n_edge)
    else:
        a_dict[v]=[n_edge]

mst=[]
last_relaxation = [0 for i in range(no_nodes)]
while heap_q:
    node=heapq.heappop(heap_q)
    visited[node.number-1]=True
    mst.append(node)
    if node.number in a_dict:
        l=a_dict[node.number]
        for neighbor in l:
            if node.number==neighbor.u:
                if not visited[neighbor.v-1]:
                    if neighbor.weight < V[neighbor.v-1].distance:
                        V[neighbor.v-1].distance=neighbor.weight
                        last_relaxation[neighbor.v-1]=node.number
            else:
                if not visited[neighbor.u-1]:
                    if neighbor.weight < V[neighbor.u-1].distance:
                        V[neighbor.u-1].distance=neighbor.weight
                        last_relaxation[neighbor.u-1]=node.number
    heapq.heapify(heap_q)

for i in range(1,no_nodes):
    print(last_relaxation[mst[i].number-1], "---", mst[i].number, ":", mst[i].distance)
