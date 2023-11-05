def my_dfs(index:int):
    if False==visited[index]:
        print(index,end=',')
        visited[index]=True
        for j in range(N):
            if 1==my_graph[index][j] and False==visited[j]:
                my_dfs(j)

if __name__ == '__main__':
    my_graph=[
        # adjacency graph
        #0, 1, 2, 3, 4
        [0, 0, 1, 1, 1],  # 0
        [0, 0, 1, 0, 0],  # 1
        [1, 1, 0, 1, 0],  # 2
        [1, 0, 1, 0, 0],  # 3
        [1, 0, 0, 0, 0],  # 4
    ]
    visited=[] # 방문했는지 여부 저장
    N=5
    for i in range(N):
        visited.append(False)
    # 실제 DFS 코드 시작
    for i in range(N):
        if False==visited[i]:
            my_dfs(i)
    print()

