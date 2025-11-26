def solution(map):
    # Calculate map stats
    m = len(map[0])
    n = len(map) # width and height
    
    # The current minimal solution
    ans = 500
    # Iterate over all possible inputs (by replacing 1s with 0s).
    for m_0 in all_maps(map):
        
        # Find the minimal path length
        ans = min(get_min(m_0, m, n), ans)
        # Optimization: Minimal solution?
        if ans == m + n - 1:
            return ans
        
    return ans
def get_min(map, m, n):
    '''Takes a map m and returns the minimal path
    from the start to the end node. Also pass width and height.
    '''
        
    # Initialize dictionary of path lengths
    # integer: {(i,j), ...} (Set of nodes (i,j) with this integer path length)
    d = {1: {(0,0)}}
    # Expand "fringe" successively
    path_length = 2
    while path_length < 500 and d[path_length-1]:
        # Fill fringe
        fringe = set()
        for x in d[path_length-1]:
            
            # Expand node x (all neighbors) and exclude already visited
            expand_x = {y for y in neighbors(x,map) if not any(y in visited for visited in d.values())}
            fringe = fringe | expand_x
            
        # Have we found min path of exit node?
        if (n-1, m-1) in fringe:
            return path_length
        
        # Store new fring of minimal-path nodes
        d[path_length] = fringe
        # Find nodes with next-higher path_length
        path_length += 1
    return 500 # Infinite path length  
        
def neighbors(x, map):
    '''Returns a set of nodes (as tuples) that are neighbors of node x in m.'''
    i, j = x
    m = len(map[0])
    n = len(map)
    candidates = {(i-1,j), (i+1,j), (i,j-1), (i,j+1)}
    neighbors = set()
    for y in candidates:
        i, j = y
        if i>=0 and i<n and j>=0 and j<m and map[i][j] == 0:
            neighbors.add(y)
    
    return neighbors
def all_maps(map):
    '''Returns an iterator for memory efficiency
    over all maps that arise by replacing a '1' with a '0' value.'''
    # Unchanged map is a valid solution
    yield map
    for i in range(len(map)):
        for j in range(len(map[i])):
            if map[i][j]:
                # Copy the map
                cmap = [[col for col in row] for row in map]
                # Replace 1 by 0 and yield new map
                cmap[i][j] = 0
                yield cmap
def main():
    # map=[[0, 1, 1, 0], [0, 0, 0, 1], [1, 1, 0, 0], [1, 1, 1, 0]]
    # map=[[0,0,0,0],[1,1,0,0],[1,0,0,1],[1,1,0,0]]
    # map=[[0,1],[1,0],[1,0]]
    map=[[0,0,1,1],[1,0,0,1],[1,0,0,1],[1,1,0,1]]
    # map=[[0,0,0,0],[1,1,1,1],[1,1,0,1],[0,0,0,0]]
    # map=[[0,1],[1,1],[1,0]]
    # map=[[0,0,0,0,0,0],[0,0,1,0,0,0]]
    # map=[]
    # for i in range(20):
    #     a=[]
    #     for j in range(20):
    #         a.append(0)
    #     map.append(a)
    # for j in range(20):
    #     map[1][j]=1
    # map=[[0,0,0,0,0,0],[1,1,1,1,1,0],[1,1,1,1,1,0],[0,0,0,0,0,0],[0,1,1,1,1,1],[0,0,0,0,0,0]]
    # map=[[0, 0, 0, 0, 0, 0], [1, 1, 1, 1, 1, 0], [0, 0, 0, 0, 0, 0], [0, 1, 1, 1, 1, 1], [0, 1, 1, 1, 1, 1], [0, 0, 0, 0, 0, 0]]
    print(solution(map))
    # Your code here
main()