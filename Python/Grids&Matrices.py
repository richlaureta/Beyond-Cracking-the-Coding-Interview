

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
    #Problem 28.3 Spiral
    
    matrix = [[0 for square in range(matrixDimension)] for row in range(matrixDimension)]
    
    number = matrixDimension * matrixDimension - 1
    square = [matrixDimension - 1, matrixDimension - 1]
    upLimit = 0
    leftLimit = 0
    downLimit = matrixDimension - 1
    rightLimit = matrixDimension - 2
     
    while square != [matrixDimension//2, matrixDimension//2]:
        
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

def runSpiralTests():
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

    print("ALL SPIRAL TEST PROVIDED PASSED.")
    
if __name__ == "__main__":
    runSpiralTests()