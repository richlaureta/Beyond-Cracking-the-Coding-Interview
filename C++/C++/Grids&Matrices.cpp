//
//  Grids&Matrices.cpp
//  C++
//
//  Created by Richmond Laureta on 4/10/26.
//

#include "Header.hpp"

vector<vector<int>> chessMoves(const vector<vector<int>> &board, const string &piece, int r, int c)
{
    //Problem 28.1 - Queen's Reach
    
    vector<vector<int>> oneMoveOccupySquare = {};
    
    if(piece[0] == 'k' and piece[1] == 'i')
    {
        pair<int, int> leftDirection = {r, c - 1};
        pair <int, int> leftUpDiagonalDirection = {r - 1, c - 1};
        pair<int, int> upDirection = {r - 1, c};
        pair<int, int> rightUpDiagonalDirection = {r - 1, c + 1};
        pair<int, int> rightDirection = {r , c + 1};
        pair<int, int> rightDownDiagonalDirection = {r + 1, c + 1};
        pair<int, int> downDirection = {r + 1, c};
        pair<int, int> leftDownDiagonalDirection = {r + 1, c - 1};
        
        if ( leftDirection.second > -1 and board[leftDirection.first][leftDirection.second] == 0) oneMoveOccupySquare.push_back({leftDirection.first, leftDirection.second});
        
        if (leftUpDiagonalDirection.first > -1 and
            leftUpDiagonalDirection.second > -1 and
            board[leftUpDiagonalDirection.first][leftUpDiagonalDirection.second] == 0) oneMoveOccupySquare.push_back({leftUpDiagonalDirection.first, leftUpDiagonalDirection.second});
        
        if (upDirection.first > -1 and board[upDirection.first][upDirection.second] == 0) oneMoveOccupySquare.push_back({upDirection.first, upDirection.second});
        
        if (rightUpDiagonalDirection.first > -1 and
            rightUpDiagonalDirection.second < (int) board[0].size() and
            board[rightUpDiagonalDirection.first][rightUpDiagonalDirection.second] == 0) oneMoveOccupySquare.push_back({rightUpDiagonalDirection.first, rightUpDiagonalDirection.second});
        
        if (rightDirection.second < (int) board[0].size() and board[rightDirection.first][rightDirection.second] == 0) oneMoveOccupySquare.push_back({rightDirection.first, rightDirection.second});
        
        if (rightDownDiagonalDirection.first < (int) board.size() and
            rightDownDiagonalDirection.second < (int) board[0].size() and
            board[rightDownDiagonalDirection.first][rightDownDiagonalDirection.second] == 0) oneMoveOccupySquare.push_back({rightDownDiagonalDirection.first, rightDownDiagonalDirection.second});
        
        if (downDirection.first < (int) board.size() and board[downDirection.first][downDirection.second] == 0) oneMoveOccupySquare.push_back({downDirection.first, downDirection.second});
        
        if (leftDownDiagonalDirection.first < (int) board.size() and
            leftDownDiagonalDirection.second > -1 and
            board[leftDownDiagonalDirection.first][leftDownDiagonalDirection.second] == 0) oneMoveOccupySquare.push_back({leftDownDiagonalDirection.first, leftDownDiagonalDirection.second});
    }
    else if(piece[0] == 'q')
    {
        int row = r;
        int column = c;
        
        //Left
        while (true){
            column--;
            if (column < 0 or board[row][column] == 1) break;
            oneMoveOccupySquare.push_back({row, column});
        }
        
        column = c;
        
        //LeftUpDiagonal
        while (true){
            column--;
            row--;
            if (column < 0 or row < 0 or board[row][column] == 1) break;
            oneMoveOccupySquare.push_back({row, column});
        }
        
        row = r;
        column = c;
        
        //Up
        while (true){
            row--;
            if (row < 0 or board[row][column] == 1) break;
            oneMoveOccupySquare.push_back({row, column});
        }
        
        row = r;
        
        //RightUp
        while (true){
            row--;
            column++;
            if (row < 0 or column > (int) board[0].size() - 1 or board[row][column] == 1) break;
            oneMoveOccupySquare.push_back({row, column});
        }
        
        row = r;
        column = c;
        
        //Right
        while (true){
            column++;
            if( column > (int) board[0].size() - 1 or board[row][column] == 1) break;
            oneMoveOccupySquare.push_back({row, column});
        }
        column = c;
        
        //RighDown
        while (true){
            row++;
            column++;
            if( row > (int) board.size() - 1 or column > (int) board[0].size() - 1 or board[row][column] == 1) break;
            oneMoveOccupySquare.push_back({row, column});
        }
        
        row = r;
        column = c;
        
        //Down
        while (true){
            row++;
            if( row > (int) board.size() - 1 or board[row][column] == 1) break;
            oneMoveOccupySquare.push_back({row, column});
        }
        
        row = r;
        
        //LeftDown
        while (true){
            row++;
            column--;
            if( row > (int) board.size() - 1 or column < 0 or board[row][column] == 1) break;
            oneMoveOccupySquare.push_back({row, column});
        }
    }
    else
    {
        pair<int, int> upLeftDown = {r - 1, c - 2};
        pair<int, int> upLeftUp = {r - 2, c - 1};
        pair<int, int> upRightUp = {r - 2, c + 1};
        pair<int, int> upRightDown = {r - 1, c + 2};
        pair<int, int> downRightUp = {r + 1, c + 2};
        pair<int, int> downRightDown = {r + 2, c + 1};
        pair<int, int> downLeftDown = {r + 2, c - 1};
        pair<int, int> downLeftUp = {r + 1, c - 2};
        
        if (upLeftDown.first > -1 and
            upLeftDown.second > -1 and
            board[upLeftDown.first][upLeftDown.second] == 0) oneMoveOccupySquare.push_back({upLeftDown.first, upLeftDown.second});
        
        if (upLeftUp.first > -1 and
            upLeftUp.second > -1 and
            board[upLeftUp.first][upLeftUp.second] == 0) oneMoveOccupySquare.push_back({upLeftUp.first, upLeftUp.second});
        
        if (upRightUp.first > -1 and
            upRightUp.second < (int) board[0].size() and
            board[upRightUp.first][upRightUp.second] == 0) oneMoveOccupySquare.push_back({upRightUp.first, upRightUp.second});
        
        if (upRightDown.first > -1 and
            upRightDown.second < (int) board[0].size() and
            board[upRightDown.first][upRightDown.second] == 0) oneMoveOccupySquare.push_back({upRightDown.first, upRightDown.second});
        
        if(downRightUp.first < (int) board.size() and
           downRightUp.second < (int) board[0].size() and
           board[downRightUp.first][downRightUp.second] == 0) oneMoveOccupySquare.push_back({downRightUp.first, downRightUp.second});
        
        if(downRightDown.first < (int) board.size() and
           downRightDown.second < (int) board[0].size() and
           board[downRightDown.first][downRightDown.second] == 0) oneMoveOccupySquare.push_back({downRightDown.first, downRightDown.second});
        
        if(downLeftDown.first < (int) board.size() and
           downLeftDown.second > -1  and
           board[downLeftDown.first][downLeftDown.second] == 0) oneMoveOccupySquare.push_back({downLeftDown.first, downLeftDown.second});
        
        if(downLeftUp.first < (int) board.size() and
           downLeftUp.second > -1  and
           board[downLeftUp.first][downLeftUp.second] == 0) oneMoveOccupySquare.push_back({downLeftUp.first, downLeftUp.second});
    }
    
    return oneMoveOccupySquare;
}

vector<vector<int>> safeCells(const vector<vector<int>> &board)
{
    //Problem 28.2 - Queen's Reach
    
    vector<vector<int>> queenPosition = {};
    vector<vector<int>> boardCopy(board);
    
    for(int index = 0; index < board.size(); index++)
    {
        for(int index1 = 0; index1 < board[0].size(); index1++)
        {
            if(board[index][index1] == 1) queenPosition.push_back({index, index1});
        }
    }
    
    for(int index2 = 0; index2 < (int) queenPosition.size(); index2++)
    {
        int row = queenPosition[index2][0];
        int column = queenPosition[index2][1];
        
        //Left
        while (true){
            column--;
            if (column < 0) break;
            boardCopy[row][column] = 1;
        }
        column = queenPosition[index2][1];

        //LeftUpDiagonal
        while (true){
            column--;
            row--;
            if(column < 0 or row < 0) break;
            boardCopy[row][column] = 1;
        }
        
        row = queenPosition[index2][0];
        column = queenPosition[index2][1];

        //Up
        while (true){
            row--;
            if(row < 0) break;
            boardCopy[row][column] = 1;
        }
        row = queenPosition[index2][0];

        //RightUp
        while (true){
            row--;
            column++;
            if (row < 0 or column > (int) board[0].size() - 1) break;
            boardCopy[row][column] = 1;
        }
        
        row = queenPosition[index2][0];
        column = queenPosition[index2][1];

        //Right
        while (true){
            column++;
            if(column > (int)board[0].size() - 1) break;
            boardCopy[row][column] = 1;
        }
        
        column = queenPosition[index2][1];

        //RighDown
        while (true){
            row++;
            column++;
            if( row > (int)board.size() - 1 or column > (int)board[0].size() - 1) break;
            boardCopy[row][column] = 1;
        }
        row = queenPosition[index2][0];
        column = queenPosition[index2][1];

        //Down
        while (true){
            row++;
            if (row > (int) board.size() - 1) break;
            boardCopy[row][column] = 1;
        }
        
        row = queenPosition[index2][0];

        //LeftDown
        while (true){
            row++;
            column--;
            if (row > (int) board.size() - 1 or column < 0) break;
            boardCopy[row][column] = 1;
        }
    }
    
    return boardCopy;
}

vector<vector<int>> spiral(int matrixDimension)
{
    //Problem 28.3 - Spiral Order
    
    vector<vector<int>> matrix(matrixDimension, vector<int>(matrixDimension, 0));
    
    int number = matrixDimension * matrixDimension - 1;
    
    pair<int, int> square = {matrixDimension - 1, matrixDimension - 1};
    pair<int, int> center = {matrixDimension/2, matrixDimension/2};
    
    int upLimit = 0;
    int leftLimit = 0;
    int downLimit = matrixDimension - 1;
    int rightLimit = matrixDimension - 2;
    
    while(square != center)
    {
        while(square.first >= upLimit)
        {
            matrix[square.first][square.second] = number;
            number--;
            square.first--;
        }
        
        upLimit++;
        square.second--;
        square.first++;
        
        while(square.second >= leftLimit)
        {
            matrix[square.first][square.second] = number;
            number--;
            square.second--;
        }
        
        leftLimit++;
        square.second++;
        square.first++;
        
        while(square.first <= downLimit)
        {
            matrix[square.first][square.second] = number;
            number--;
            square.first++;
        }
        
        downLimit--;
        square.second++;
        square.first--;
        
        while(square.second <= rightLimit)
        {
            matrix[square.first][square.second] = number;
            number--;
            square.second++;
        }
        
        rightLimit--;
        square.second--;
        square.first--;
    }
    
    return matrix;
}

int distanceToRiver(const vector<vector<int>> &field)
{
    //Problem 28.4 - Snowprints
    
    pair<int, int> currentFootPrintLocation = {};
    
    for(int index = 0; index < (int) field.size(); index++)
    {
        if(field[index][0] == 1)
        {
            currentFootPrintLocation = {index, 0};
            break;
        }
    }
    
    int closesToTheWaterRow = currentFootPrintLocation.first;
    
    while(currentFootPrintLocation.second < (int) field[0].size() - 1)
    {
        pair<int, int> rightUp = {currentFootPrintLocation.first - 1, currentFootPrintLocation.second + 1};
        pair<int, int> right = {currentFootPrintLocation.first, currentFootPrintLocation.second + 1};
        pair<int, int> rightDown = {currentFootPrintLocation.first + 1, currentFootPrintLocation.second + 1};
        
        if(rightUp.first > -1 and field[rightUp.first][rightUp.second] == 1)
        {
            currentFootPrintLocation = rightUp;
            closesToTheWaterRow = rightUp.first;
        }
        else if(field[right.first][right.second] == 1) currentFootPrintLocation = right;
        else if(rightDown.first < (int) field.size()) currentFootPrintLocation = rightDown;
    }
    
    return closesToTheWaterRow;
}

bool validSudoku(vector<vector<int>> board)
{
    //Problem 28.5 - Valid Sudoku
    
    for(int index = 0; index < 9; index++)
    {
        unordered_set<int> numberSeenSet = {};
        for(int index1 = 0; index1 < 9; index1++)
        {
            if(board[index][index1] != 0 and numberSeenSet.find(board[index][index1]) != numberSeenSet.end()) return false;
            numberSeenSet.insert(board[index][index1]);
        }
    }
    
    for(int index2 = 0; index2 < 9; index2++)
    {
        unordered_set<int> numberSeenSet1 = {};
        for(int index3 = 0; index3 < 9; index3++)
        {
            if(board[index3][index2] != 0 and numberSeenSet1.find(board[index3][index2]) != numberSeenSet1.end()) return false;
            numberSeenSet1.insert(board[index3][index2]);
        }
    }
    
    vector<pair<int,int>> startingPoints = {{0, 0}, {0, 3}, {0, 6}, {3, 0}, {3, 3}, {3, 6}, {6, 0}, {6, 3}, {6, 6}};
    
    for(pair<int, int> startingPoint: startingPoints)
    {
        unordered_set<int> numberSeenSet2 = {};
        for(int index4 = startingPoint.first; index4 < startingPoint.first + 3; index4++)
        {
            for(int index5 = startingPoint.second; index5 < startingPoint.second + 3; index5++)
            {
                if(board[index4][index5] != 0 and numberSeenSet2.find(board[index4][index5]) != numberSeenSet2.end()) return false;
                numberSeenSet2.insert(board[index4][index5]);
            }
        }
    }
    
    return true;
}

vector<vector<int>> subgridMaximums(const vector<vector<int>> &grid)
{
    //Problem 28.6 Subgrid Maximums
    
    vector<vector<int>> newGrid = grid;
    
    for(int row = (int)grid.size() - 1; row > -1; row--)
    {
        for(int column = (int)grid[0].size() - 1; column > -1; column--)
        {
            if (column + 1 < (int)grid[0].size()) newGrid[row][column] = max(newGrid[row][column], newGrid[row][column + 1]);
            if (row + 1 < (int)grid.size()) newGrid[row][column] = max(newGrid[row][column], newGrid[row + 1][column]);
        }
    }
    
    return newGrid;
}

vector<vector<int>> subgridSums(const vector<vector<int>> &grid)
{
    //Problem 28.7 Subgrid Sums
    
    vector<vector<int>> newGrid = grid;
    
    for(int row = (int)grid.size() - 1; row > -1; row--)
    {
        for(int column = (int)grid[0].size() - 1; column > -1; column--)
        {
            if(column < (int)grid[0].size() - 1 and row < (int)grid.size() - 1) newGrid[row][column] += newGrid[row][column + 1] + newGrid[row + 1][column] - newGrid[row + 1][column + 1];
            else if(row == (int)grid.size() - 1 and column < (int)grid[0].size() - 1) newGrid[row][column] += newGrid[row][column + 1];
            else if(column == (int)grid[0].size() - 1 and row < (int)grid.size() - 1) newGrid[row][column] += newGrid[row + 1][column];
        }
    }
    
    return newGrid;
}

MatrixOperations::MatrixOperations(const vector<vector<double>> &grid) : matrix(grid)
{
    
}

void MatrixOperations::transpose()
{
    for(int row = 0; row < (int)matrix.size(); row++)
    {
        for(int column = row + 1; column < (int)matrix[0].size(); column++)
        {
            swap(matrix[row][column], matrix[column][row]);
        }
    }
}

void MatrixOperations::reflectHorizontally()
{
    for(int index = 0; index < (int)matrix.size(); index++) reverse(matrix[index].begin(), matrix[index].end());
}

void MatrixOperations::reflectVertically()
{
    reverse(matrix.begin(), matrix.end());
}

void MatrixOperations::rotateClockwise()
{
    transpose();
    reflectHorizontally();
}

void MatrixOperations::rotateCounterclockwise()
{
    transpose();
    reflectVertically();
}

const vector<vector<double>>& MatrixOperations::getMatrix() const
{
    return matrix;
}
