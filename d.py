from collections import deque
# ROW = 9
# COL = 10
 
# To store matrix cell coordinates
class Point:
    def __init__(self,x: int, y: int):
        self.x = x
        self.y = y
 
# A data structure for queue used in BFS
class queueNode:
    def __init__(self,pt: Point, dist: int):
        self.pt = pt  # The coordinates of the cell
        self.dist = dist  # Cell's distance from the source
 
# Check whether given cell(row,col)
# is a valid cell or not
def isValid(row: int, col: int,n,m):
    return (row >= 0) and (row < n) and (col >= 0) and (col < m)
 
# These arrays are used to get row and column
# numbers of 4 neighbours of a given cell
rowNum = [-1, 0, 0, 1]
colNum = [0, -1, 1, 0]
 
# Function to find the shortest path between
# a given source cell to a destination cell.
def BFS(mat, src: Point, dest: Point,n,m):
     
    # check source and destination cell
    # of the matrix have value 1
    if mat[src.x][src.y]==0 or mat[dest.x][dest.y]==0:
        return 500
     
    # visited = [[False for i in range(m)] for j in range(n)]
    visited=[]
    for i in range(n):
        a=[]
        for j in range(m):
            a.append(False)
        visited.append(a)
     
    # Mark the source cell as visited
    visited[src.x][src.y] = True
     
    # Create a queue for BFS
    q = deque()
    # q=[]
     
    # Distance of source cell is 0
    s = queueNode(src,1)
    q.append(s) #  Enqueue source cell
     
    # Do a BFS starting from source cell
    while q:
 
        curr = q.popleft() # Dequeue the front cell
         
        # If we have reached the destination cell,
        # we are done
        pt = curr.pt
        if pt.x == dest.x and pt.y == dest.y:
            return curr.dist
         
        # Otherwise enqueue its adjacent cells
        for i in range(4):
            row = pt.x + rowNum[i]
            col = pt.y + colNum[i]
             
            # if adjacent cell is valid, has path 
            # and not visited yet, enqueue it.
            if (isValid(row,col,n,m) and mat[row][col] == 1 and visited[row][col]==False):
                visited[row][col] = True
                Adjcell = queueNode(Point(row,col),curr.dist+1)
                q.append(Adjcell)
     
    # Return -1 if destination cannot be reached
    return 500
def solution(map):
    n=len(map)
    m=len(map[0])
    for i in range(n):
        for j in range(m):
           map[i][j]=1-map[i][j]
    source = Point(0,0)
    dest = Point(n-1,m-1)
    ans=BFS(map,source,dest,n,m)
    print("printing map",map)
    # if(ans==n+m-1):
    #     return ans
    for i in range(n):
        for j in range(m): 
            if(map[i][j]==0):
                map[i][j]=1
                print("printing map",map)
                ans=min(ans,BFS(map,source,dest,n,m))
                # if(ans==n+m-1):
                #     return ans
                map[i][j]=0
    return ans

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