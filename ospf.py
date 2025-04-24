import heapq

def ospf_simulation(graph, start):
    # Dijkstra's algorithm
    queue = [(0, start)]
    visited = set()
    shortest_paths = {node: (float('inf'), []) for node in graph}
    shortest_paths[start] = (0, [start])
    
    while queue:
        (cost, node) = heapq.heappop(queue)
        if node in visited:
            continue
        visited.add(node)

        for neighbor, weight in graph[node].items():
            new_cost = cost + weight
            if new_cost < shortest_paths[neighbor][0]:
                shortest_paths[neighbor] = (new_cost, shortest_paths[node][1] + [neighbor])
                heapq.heappush(queue, (new_cost, neighbor))
    
    return shortest_paths

# Example network (graph): router connections with assigned cost
network = {
    'R1': {'R2': 2, 'R3': 5},
    'R2': {'R1': 2, 'R3': 1, 'R4': 2},
    'R3': {'R1': 5, 'R2': 1, 'R4': 3},
    'R4': {'R2': 2, 'R3': 3}
}

start_router = 'R1'
routes = ospf_simulation(network, start_router)

print(f"OSPF Routing Table from {start_router}:\n")
for dest, (cost, path) in routes.items():
    print(f"To {dest}: Path = {' -> '.join(path)}, Total Cost = {cost}")
