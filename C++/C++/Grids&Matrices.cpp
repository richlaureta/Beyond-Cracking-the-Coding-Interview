//
//  Grids&Matrices.cpp
//  C++
//
//  Created by Richmond Laureta on 4/10/26.
//

#include "Header.hpp"

vector<vector<int>> chessMoves(const vector<vector<int>> &board, const string &piece, int r, int c)
{
    //Problem 28.1 Queen's Reach
    
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
