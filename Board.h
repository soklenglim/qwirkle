
#ifndef ASSIGN2_BOARD_H
#define ASSIGN2_BOARD_H

#include <iostream>
#include <vector>
#include "Tile.h"
#include <memory>
#include <string>
#include "Player.h"
#include "Type.h"
#include <sstream>

class Board
{
    public:
        Board();
        Board(std::vector< std::shared_ptr<Tile> > board, int boardRow, int boardCol);
        ~Board();

        void addTile(shared_ptr<Tile> tile);
        void printBoard();
        int getLength();
        std::string printBoardSave();
        bool placeTile(shared_ptr<Tile> tile);
        int calculatePoints(Row tileRow, Col tileCol);
        int boardRow;
        int boardCol;

    private:
        std::shared_ptr<Tile> array[BOARD_SIZE][BOARD_SIZE];
        std::vector< shared_ptr<Tile> > board;
        
        void expandBoard(Row rowTile, Col colTile);
        bool validMove(shared_ptr<Tile> tile);
        bool exist(Row tileRow, Col tileCol);
        std::string tilePosition(char row, int col);
        int checkQwirkle(int score);
        int getRow(Row row);
};


#endif // ASSIGN2_BOARD_H