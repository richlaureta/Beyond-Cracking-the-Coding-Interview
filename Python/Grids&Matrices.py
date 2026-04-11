

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
        pass
    
    return oneMoveOccupySquare

if __name__ == "__main__":
    # board = [
    #     [0, 0, 0, 1, 0, 0],
    #     [0, 1, 1, 1, 0, 0],
    #     [0, 1, 0, 1, 1, 0],
    #     [1, 1, 1, 1, 0, 0],
    #     [0, 0, 0, 0, 0, 0],
    #     [0, 1, 0, 0, 0, 0]]
    
    # piece = "king"
    
    # r = 5
    # c = 5
    # board = [
    #     [0, 0, 0, 1, 0, 0],
    #     [0, 1, 1, 1, 0, 0],
    #     [0, 1, 0, 1, 1, 0],
    #     [1, 1, 1, 1, 0, 0],
    #     [0, 0, 0, 0, 0, 0],
    #     [0, 1, 0, 0, 0, 0]]
    
    # piece = "queen"
    
    # r = 0
    # c = 5
    
    print(chessMoves(board, piece, r, c))