
import copy

def chessMoves(board: list[list[int]], piece: str, r: int, c: int) -> list[list[int]]:
    #Problem 28.1 - Chess Moves
    
    oneMoveOccupySquare = []
    
    if piece[0] == 'k' and piece[1] == 'i':
        leftDirection = [r, c - 1]
        leftUpDiagonalDirection = [r - 1, c - 1]
        upDirection = [r - 1, c]
        rightUpDiagonalDirection = [r - 1, c + 1]
        rightDirection = [r , c + 1]
        rightDownDiagonalDirection = [r + 1, c + 1]
        downDirection = [r + 1, c]
        leftDownDiagonalDirection = [r + 1, c - 1]
        
        if leftDirection[1] > -1 and board[leftDirection[0]][leftDirection[1]] == 0:
            oneMoveOccupySquare.append(leftDirection)
        
        if (leftUpDiagonalDirection[0] > -1 and 
            leftUpDiagonalDirection[1] > -1 and
            board[leftUpDiagonalDirection[0]][leftUpDiagonalDirection[1]] == 0):
            oneMoveOccupySquare.append(leftUpDiagonalDirection)
        
        if upDirection[0] > -1 and board[upDirection[0]][upDirection[1]] == 0:
            oneMoveOccupySquare.append(upDirection)
        
        if (rightUpDiagonalDirection[0] > -1 and 
            rightUpDiagonalDirection[1] < len(board[0]) and
            board[rightUpDiagonalDirection[0]][rightUpDiagonalDirection[1]] == 0):
            oneMoveOccupySquare.append(rightUpDiagonalDirection)
        
        if rightDirection[1] < len(board[0]) and board[rightDirection[0]][rightDirection[1]] == 0:
            oneMoveOccupySquare.append(rightDirection)
        
        if (rightDownDiagonalDirection[0] < len(board) and
            rightDownDiagonalDirection[1] < len(board[0])and
            board[rightDownDiagonalDirection[0]][rightDownDiagonalDirection[1]] == 0):
            oneMoveOccupySquare.append(rightDownDiagonalDirection)
        
        if downDirection[0] < len(board) and board[downDirection[0]][downDirection[1]] == 0:
            oneMoveOccupySquare.append(downDirection)
        
        if (leftDownDiagonalDirection[0] < len(board) and
            leftDownDiagonalDirection[1] > -1 and 
            board[leftDownDiagonalDirection[0]][leftDownDiagonalDirection[1]] == 0):
            oneMoveOccupySquare.append(leftDownDiagonalDirection)
    elif piece[0] == 'q':
        row = r
        column = c
        
        #Left
        while True:
            column -= 1
            if column < 0 or board[row][column] == 1:
                break
            oneMoveOccupySquare.append([row, column])
        
        column = c
        
        #LeftUpDiagonal
        while True:
            column -= 1
            row -= 1
            if column < 0 or row < 0 or board[row][column] == 1:
                break
            oneMoveOccupySquare.append([row, column])
        
        row = r
        column = c
        
        #Up
        while True:
            row -= 1
            if row < 0 or board[row][column] == 1:
                break
            oneMoveOccupySquare.append([row, column])
        
        row = r
        
        #RightUp
        while True:
            row -= 1
            column += 1
            if row < 0 or column > len(board[0]) - 1 or board[row][column] == 1:
                break
            oneMoveOccupySquare.append([row, column])
        
        row = r
        column = c
        
        #Right
        while True:
            column += 1
            if column > len(board[0]) - 1 or board[row][column] == 1:
                break
            oneMoveOccupySquare.append([row, column])
        
        column = c
        
        #RighDown
        while True:
            row += 1
            column += 1
            if row > len(board) - 1 or column > len(board[0]) - 1 or board[row][column] == 1:
                break
            oneMoveOccupySquare.append([row, column])
        
        row = r
        column = c
        
        #Down
        while True:
            row += 1
            if row > len(board) - 1 or board[row][column] == 1:
                break
            oneMoveOccupySquare.append([row, column])
        
        row = r
        
        #LeftDown
        while True:
            row += 1
            column -= 1
            if row > len(board) - 1 or column < 0 or board[row][column] == 1:
                break
            oneMoveOccupySquare.append([row, column])
    else:
        upLeftDown = [r - 1, c - 2]
        upLeftUp = [r - 2, c - 1]
        upRightUp = [r - 2, c + 1]
        upRightDown = [r - 1, c + 2]
        downRightUp = [r + 1, c + 2]
        downRightDown = [r + 2, c + 1]
        downLeftDown = [r + 2, c - 1]
        downLeftUp = [r + 1, c - 2]
        
        if (upLeftDown[0] > -1 and
            upLeftDown[1] > -1 and
            board[upLeftDown[0]][upLeftDown[1]] == 0):
            oneMoveOccupySquare.append(upLeftDown)
        
        if (upLeftUp[0] > -1 and
            upLeftUp[1] > -1 and
            board[upLeftUp[0]][upLeftUp[1]] == 0):
            oneMoveOccupySquare.append(upLeftUp)
        
        if (upRightUp[0] > -1 and
            upRightUp[1] < len(board[0]) and
            board[upRightUp[0]][upRightUp[1]] == 0):
            oneMoveOccupySquare.append(upRightUp)
        
        if (upRightDown[0] > -1 and
            upRightDown[1] < len(board[0]) and
            board[upRightDown[0]][upRightDown[1]] == 0):
            oneMoveOccupySquare.append(upRightDown)
        
        if(downRightUp[0] < len(board) and
           downRightUp[1] < len(board[0]) and 
           board[downRightUp[0]][downRightUp[1]] == 0):
            oneMoveOccupySquare.append(downRightUp)
        
        if(downRightDown[0] < len(board) and
           downRightDown[1] < len(board[0]) and 
           board[downRightDown[0]][downRightDown[1]] == 0):
            oneMoveOccupySquare.append(downRightDown)
        
        if(downLeftDown[0] < len(board) and
           downLeftDown[1] > -1  and 
           board[downLeftDown[0]][downLeftDown[1]] == 0):
            oneMoveOccupySquare.append(downLeftDown)
        
        if(downLeftUp[0] < len(board) and
           downLeftUp[1] > -1  and 
           board[downLeftUp[0]][downLeftUp[1]] == 0):
            oneMoveOccupySquare.append(downLeftUp)
        
    return oneMoveOccupySquare

def safeCells(board: list[list[int]]):
    #Problem 28.2 - Queen's Reach
    
    queenPosition = []
    
    for index in range(len(board)):
        for index1 in range(len(board[0])):
            if board[index][index1] == 1:
                queenPosition.append([index, index1])
    
    for square in queenPosition:
        row, column = square
        
        #Left
        while True:
            column -= 1
            if column < 0:
                break
            board[row][column] = 1
            
        column = square[1]
        
        #LeftUpDiagonal
        while True:
            column -= 1
            row -= 1
            if column < 0 or row < 0:
                break
            board[row][column] = 1
        
        row = square[0]
        column = square[1]
        
        #Up
        while True:
            row -= 1
            if row < 0:
                break
            board[row][column] = 1
        
        row = square[0]
        
        #RightUp
        while True:
            row -= 1
            column += 1
            if row < 0 or column > len(board[0]) - 1:
                break
            board[row][column] = 1
        
        row = square[0]
        column = square[1]
        
        #Right
        while True:
            column += 1
            if column > len(board[0]) - 1:
                break
            board[row][column] = 1
            
        column = square[1]
        
        #RighDown
        while True:
            row += 1
            column += 1
            if row > len(board) - 1 or column > len(board[0]) - 1:
                break
            board[row][column] = 1
        
        row = square[0]
        column = square[1]
        
        #Down
        while True:
            row += 1
            if row > len(board) - 1:
                break
            board[row][column] = 1
        
        row = square[0]
        
        #LeftDown
        while True:
            row += 1
            column -= 1
            if row > len(board) - 1 or column < 0:
                break
            board[row][column] = 1
    
    return board

def spiral(matrixDimension: int) -> list[list[int]]:
    #Problem 28.3 - Spiral Order
    
    matrix = [[0 for square in range(matrixDimension)] for row in range(matrixDimension)]
    
    number = matrixDimension * matrixDimension - 1
    
    square = [matrixDimension - 1, matrixDimension - 1]
    center = [matrixDimension//2, matrixDimension//2]
    
    upLimit = 0
    leftLimit = 0
    downLimit = matrixDimension - 1
    rightLimit = matrixDimension - 2
    
    while square != center:
        while square[0] >= upLimit:
            matrix[square[0]][square[1]] = number
            number -=1
            square[0] -= 1
        
        upLimit += 1
        square[1] -= 1
        square[0] += 1
        
        while square[1] >= leftLimit:
            matrix[square[0]][square[1]] = number
            number -= 1
            square[1] -= 1
        
        leftLimit += 1
        square[1] += 1
        square[0] += 1
        
        while square[0] <= downLimit:
            matrix[square[0]][square[1]] = number
            number -= 1
            square[0] += 1
        
        downLimit -= 1
        square[1] += 1
        square[0] -= 1
        
        while square[1] <= rightLimit:
            matrix[square[0]][square[1]] = number
            number -= 1
            square[1] += 1
        
        rightLimit -= 1
        square[1] -= 1
        square[0] -= 1
    
    return matrix

def distanceToRiver(field: list[list[int]]) -> int:
    #Problem 28.4 - Snowprints
    
    currentFootPrintLocation = None
    
    for index in range(len(field)):
        if field[index][0] == 1:
            currentFootPrintLocation = [index, 0]
            break
    
    closestToTheWaterRow = currentFootPrintLocation[0]
    
    while currentFootPrintLocation[1] < len(field[0]) - 1:
        rightUp = [currentFootPrintLocation[0] - 1, currentFootPrintLocation[1] + 1]
        right = [currentFootPrintLocation[0], currentFootPrintLocation[1] + 1]
        rightDown = [currentFootPrintLocation[0] + 1, currentFootPrintLocation[1] + 1]
        
        if rightUp[0] > -1 and field[rightUp[0]][rightUp[1]] == 1:
            currentFootPrintLocation = rightUp
            closestToTheWaterRow = rightUp[0]
        elif field[right[0]][right[1]] == 1:
            currentFootPrintLocation = right
        elif rightDown[0] < len(field):
            currentFootPrintLocation = rightDown

    return closestToTheWaterRow

def validSudoku(board: list[list[int]]) -> bool:
    #Problem 28.5 - Valid Sudoku
    
    for index in range(9):
        numberSeenSet = set()
        for index1 in range(9):
            if board[index][index1] != 0 and board[index][index1] in numberSeenSet:
                return False
            numberSeenSet.add(board[index][index1])
    
    for index2 in range(9):
        numberSeenSet1 = set()
        for index3 in range(9):
            if board[index3][index2] != 0 and board[index3][index2] in numberSeenSet1:
                return False
            numberSeenSet1.add(board[index3][index2])
    
    startingPoints = [[0, 0], [0, 3], [0, 6], [3, 0], [3, 3], [3, 6], [6, 0,], [6, 3], [6, 6]]
    
    for startingPoint in startingPoints:
        numberSeenSet2 = set()
        for index4 in range(startingPoint[0], startingPoint[0] + 3):
            for index5 in range(startingPoint[1], startingPoint[1] + 3):
                if board[index4][index5] != 0 and board[index4][index5] in numberSeenSet2:
                    return False
                numberSeenSet2.add(board[index4][index5])
    
    return True

def subgridMaximums(grid: list[list[int]]) -> list[list[int]]:
    #Problem 28.6 Subgrid Maximums
    
    newGrid = copy.deepcopy(grid)
    
    for row in range(len(grid) - 1, -1, -1):
        for column in range(len(grid[0]) - 1, -1, -1):
            if row + 1 < len(grid):
                newGrid[row][column] = max(newGrid[row][column], newGrid[row + 1][column])
            
            if column + 1 < len(grid[0]):
                newGrid[row][column] = max(newGrid[row][column], newGrid[row][column + 1])
    
    return newGrid

def subgridSums(grid: list[list[int]]) -> list[list[int]]:
    #Problem #28.7 Subgrid Sums
    
    newGrid = copy.deepcopy(grid)
    
    for row in range(len(grid) - 1, -1, -1):
        for column in range(len(grid[0]) - 1, -1, -1):
            if column < len(grid[0]) - 1 and row < len(grid) - 1:
                newGrid[row][column] += newGrid[row][column + 1] + newGrid[row + 1][column] - newGrid[row + 1][column + 1]
            elif row == len(grid) - 1 and column < len(grid[0]) - 1:
                newGrid[row][column] += newGrid[row][column + 1]
            elif column == len(grid[0]) - 1 and row < len(grid) - 1:
                newGrid[row][column] += newGrid[row + 1][column]
    
    return newGrid 
                
class MatrixOperations:
    #Problem 28.8 Matrix Operations
    
    def __init__(self, grid: list[list[int]]):
        self.matrix = grid
        
    def transpose(self):
        for row in range(len(self.matrix)):
            for column in range(row + 1, len(self.matrix[0])):
                self.matrix[row][column], self.matrix[column][row] = self.matrix[column][row], self.matrix[row][column]
    def reflectHorizontally(self):
        for row in self.matrix:
            row.reverse()
    def reflectVertically(self):
        self.matrix.reverse()
    def rotateClockwise(self):
        self.transpose()
        self.reflectHorizontally()
    def rotateCounterclockwise(self):
        self.transpose()
        self.reflectVertically()

#TESTS
def runChessMovesTests():
    tests = [
        # Example 1 from the book - king moves
        ([[0, 0, 0, 1, 0, 0],
            [0, 1, 1, 1, 0, 0],
            [0, 1, 0, 1, 1, 0],
            [1, 1, 1, 1, 0, 0],
            [0, 0, 0, 0, 0, 0],
            [0, 1, 0, 0, 0, 0]], "king", 3, 5,
            [[2, 5], [3, 4], [4, 4], [4, 5]]),
        # Example 2 from the book - knight moves
        ([[0, 0, 0, 1, 0, 0],
            [0, 1, 1, 1, 0, 0],
            [0, 1, 0, 1, 1, 0],
            [1, 1, 1, 1, 0, 0],
            [0, 0, 0, 0, 0, 0],
            [0, 1, 0, 0, 0, 0]], "knight", 4, 3,
        [[2, 2], [3, 5], [5, 5]]),
        # Example 3 from the book - queen moves
        ([[0, 0, 0, 1, 0, 0],
            [0, 1, 1, 1, 0, 0],
            [0, 1, 0, 1, 1, 0],
            [1, 1, 1, 1, 0, 0],
            [0, 0, 0, 0, 0, 0],
            [0, 1, 0, 0, 0, 0]], "queen", 4, 4,
        [[3, 4], [3, 5], [4, 0], [4, 1], [4, 2], [4, 3], [4, 5],
            [5, 3], [5, 4], [5, 5]]),
        # Edge case - 1x1 board
        ([[0]], "queen", 0, 0, []),
        # Edge case - all occupied except current position
        ([[1, 1], [1, 0]], "knight", 1, 1, []),
    ]

    for board, piece, r, c, want in tests:
        got = chessMoves(board, piece, r, c)
        # Sort both lists for consistent comparison
        got.sort()
        want.sort()
        assert got == want, (f"\nchess_moves({board}, {piece}, {r}, {c}): "
                            f"got: {got}, want: {want}\n")

    print("ALL CHESS MOVES TEST PROVIDED PASSED.")

def runSafeCellsTests():
    tests = [
      ([[0, 0, 0, 1],
        [0, 0, 0, 0],
        [0, 0, 0, 0],
        [1, 0, 0, 0]],
       [[1, 1, 1, 1],
        [1, 0, 1, 1],
        [1, 1, 0, 1],
        [1, 1, 1, 1]]),
      # Edge case - 1x1 board with queen
      ([[1]], [[1]]),
      # Edge case - 1x1 board without queen
      ([[0]], [[0]]),
      # Edge case - no queens
      ([[0, 0], [0, 0]], [[0, 0], [0, 0]]),
    ]

    for board, want in tests:
        got = safeCells(board)
        assert got == want, f"\nsafe_cells({board}): got: {got}, want: {want}\n"

    print("ALL SAFE CELLS TEST PROVIDED PASSED.")

def runSpiralOrderTests():
    tests = [
      # Example from book
      (5, [
          [16, 17, 18, 19, 20],
          [15, 4, 5, 6, 21],
          [14, 3, 0, 7, 22],
          [13, 2, 1, 8, 23],
          [12, 11, 10, 9, 24]
      ]),
      # Edge case - 1x1
      (1, [[0]]),
      # Edge case - 3x3
      (3, [
          [4, 5, 6],
          [3, 0, 7],
          [2, 1, 8]
      ]),
    ]

    for n, want in tests:
        got = spiral(n)
        assert got == want, f"\nspiral({n}): got: {got}, want: {want}\n"

    print("ALL SPIRAL ORDER TEST PROVIDED PASSED.")

def runSnowPrintsTests():
    tests = [
        # Example from book
      ([[0, 0, 0, 0, 0, 0],
        [0, 0, 1, 0, 0, 0],
        [1, 1, 0, 1, 0, 0],
        [0, 0, 0, 0, 1, 1]], 1),
      # Edge case - top of grid
      ([[1, 1, 1, 1],
        [0, 0, 0, 0],
        [0, 0, 0, 0]], 0),
      # Edge case - bottom of grid
      ([[0, 0, 0, 0],
        [0, 0, 0, 0],
        [1, 1, 1, 1]], 2),
      # Edge case - single column
      ([[0], [1], [0]], 1),
      # Edge case - single row
      ([[1]], 0),
      # Edge case - zigzag path
      ([[0, 0, 0, 0],
        [1, 0, 0, 0],
        [0, 1, 0, 0],
        [0, 0, 1, 1]], 1),
      # Test max up/down movement
      ([[0, 0, 0, 0],
        [1, 0, 0, 0],
        [0, 1, 0, 0],
        [0, 0, 1, 0],
        [0, 0, 0, 1]], 1),
      # Test staying at same level
      ([[0, 0, 0, 0],
        [1, 1, 1, 1],
        [0, 0, 0, 0]], 1),
      # Test going up then down
      ([[0, 0, 0, 0],
        [1, 0, 0, 0],
        [0, 1, 1, 0],
        [0, 0, 0, 1]], 1)
    ]

    for field, want in tests:
        got = distanceToRiver(field)
        assert got == want, f"\ndistance_to_river({field}): got: {
            got}, want: {want}\n"

    print("ALL SNOWPRINTS TEST PROVIDED PASSED.")

def runValidSudokuTests():
    tests = [
        # Example 1 from book - valid sudoku
        ([[5, 0, 0, 0, 0, 0, 0, 0, 6],
        [0, 0, 9, 0, 5, 0, 3, 0, 0],
        [0, 3, 0, 0, 0, 2, 0, 0, 0],
        [8, 0, 0, 7, 0, 0, 0, 0, 9],
        [0, 0, 2, 0, 0, 0, 8, 0, 0],
        [4, 0, 0, 0, 0, 6, 0, 0, 3],
        [0, 0, 0, 3, 0, 0, 0, 4, 0],
        [0, 0, 3, 0, 8, 0, 2, 0, 0],
        [9, 0, 0, 0, 0, 0, 0, 0, 7]], True),
        # Example 2 from book - invalid sudoku (duplicate 7 in bottom right subgrid)
        ([[5, 0, 0, 0, 0, 0, 0, 0, 6],
        [0, 0, 9, 0, 5, 0, 3, 0, 0],
        [0, 3, 0, 0, 0, 2, 0, 0, 0],
        [8, 0, 0, 7, 0, 0, 0, 0, 9],
        [0, 0, 2, 0, 0, 0, 8, 0, 0],
        [4, 0, 0, 0, 0, 6, 0, 0, 3],
        [0, 0, 0, 3, 0, 0, 0, 4, 0],
        [0, 0, 3, 0, 8, 0, 7, 0, 0],
        [9, 0, 0, 0, 0, 0, 0, 0, 7]], False),
        # Edge case - empty board
        ([[0] * 9 for _ in range(9)], True),
        # Edge case - full valid board
        ([[1, 2, 3, 4, 5, 6, 7, 8, 9],
        [4, 5, 6, 7, 8, 9, 1, 2, 3],
        [7, 8, 9, 1, 2, 3, 4, 5, 6],
        [2, 3, 1, 5, 6, 4, 8, 9, 7],
        [5, 6, 4, 8, 9, 7, 2, 3, 1],
        [8, 9, 7, 2, 3, 1, 5, 6, 4],
        [3, 1, 2, 6, 4, 5, 9, 7, 8],
        [6, 4, 5, 9, 7, 8, 3, 1, 2],
        [9, 7, 8, 3, 1, 2, 6, 4, 5]], True),
  ]

    for board, want in tests:
        got = validSudoku(board)
        assert got == want, f"\nsolve({board}): got: {got}, want: {want}\n"

    print("ALL VALID SUDOKU TEST PROVIDED PASSED.")

def runSubgridMaximumsTests():
    tests = [
    # Example from book
    ([[1, 5, 3],
        [4, -1, 0],
        [2, 0, 2]],
       [[5, 5, 3],
        [4, 2, 2],
        [2, 2, 2]]),
      # Edge case - 1x1 grid
      ([[5]], [[5]]),
      # Edge case - single row
      ([[1, 2, 3]], [[3, 3, 3]]),
      # Edge case - single column
      ([[1], [2], [3]], [[3], [3], [3]]),
      # Edge case - negative numbers
      ([[-1, -2],
        [-3, -4]],
       [[-1, -2],
        [-3, -4]]),
    ]

    for grid, want in tests:
        got = subgridMaximums(grid)
        assert got == want, f"\nsubgrid_maximums({grid}): got: {
            got}, want: {want}\n"

    print("ALL SUBGRID MAXIMUMS TEST PROVIDED PASSED.")

def runSubgridSumsTests():
    tests = [
        # Example from book
        ([[-1, 2, 3],
          [4, 0, 0],
          [-2, 0, 9]],
       [[15, 14, 12],
        [11, 9, 9],
        [7, 9, 9]]),
      # Edge case - 1x1 grid
      ([[5]], [[5]]),
      # Edge case - single row
      ([[1, 2, 3]], [[6, 5, 3]]),
      # Edge case - single column
      ([[1], [2], [3]], [[6], [5], [3]]),
      # Edge case - all zeros
      ([[0, 0],
        [0, 0]],
       [[0, 0],
        [0, 0]]),
    ]

    for grid, want in tests:
        got = subgridSums(grid)
        assert got == want, f"\nsubgrid_sums({grid}): got: {got}, want: {want}\n"

    print("ALL SUBGRID SUMS TEST PROVIDED PASSED.")

def runMatrixOperationsTests():
  tests = [
      # Test transpose
      ([[1, 2], [3, 4]], "transpose", [[1, 3], [2, 4]]),
      # Test horizontal reflection
      ([[1, 2], [3, 4]], "reflectHorizontally", [[2, 1], [4, 3]]),
      # Test vertical reflection
      ([[1, 2], [3, 4]], "reflectVertically", [[3, 4], [1, 2]]),
      # Test clockwise rotation
      ([[1, 2], [3, 4]], "rotateClockwise", [[3, 1], [4, 2]]),
      # Test counterclockwise rotation
      ([[1, 2], [3, 4]], "rotateCounterclockwise", [[2, 4], [1, 3]]),
      # Edge case - 1x1 matrix
      ([[5]], "transpose", [[5]]),
      # Edge case - 3x3 matrix
      ([[1, 2, 3],
        [4, 5, 6],
        [7, 8, 9]], "rotateClockwise",
       [[7, 4, 1],
        [8, 5, 2],
        [9, 6, 3]]),
  ]

  for grid, operation, want in tests:
    matrix = MatrixOperations(grid)
    getattr(matrix, operation)()
    got = matrix.matrix
    assert got == want, (f"\nMatrix({grid}).{operation}(): "
                         f"got: {got}, want: {want}\n")
  
  print("ALL MATRIX OPERATIONS TESTS PASSED.")
  
if __name__ == "__main__":
    # grid = [
    #     [1, 2, 3],
    #     [4, 5, 6],
    #     [7, 8, 9]
    # ]
    
    # transposing = MatrixOperations(grid)
    
    # getattr(transposing, "reflectHorizontally")()
    
    # print(transposing.matrix)
    
    runMatrixOperationsTests()