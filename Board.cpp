#include "Board.h"

Board::Board(){
    boardCol = 6;
    boardRow = 6;
}

Board::~Board(){}

void Board::addTile(std::shared_ptr<Tile> tile){
    this->board.push_back(tile);
}

int Board::getLength(){
    return this->board.size();
}

void Board::printBoard(){
    char row = A_CHAR;
    printf("%2c", ' ');
    // Prints the column number
    for(int j = 0; j < boardCol; j++)
    {
        printf("%3d", j);
    }
    std::cout << "\n";
    // Prints the line under the column numbers
    printf("%2c%s\n", ' ',std::string((boardCol*COLWID) + 1,'-').c_str());

    // Prints the tiles and row letter on the board
    for(int i = 0; i < boardRow; i++)
    {
        std::cout << row << " |";
        for(int j = 0; j < boardCol; j++)
        {
            // Gets the tile position
            std::cout << tilePosition(row, j) << "|"; 
        }
        std::cout << "\n";
        row++;
    }
}

// Checks the tile position and prints a tile it's on that position a space
std::string Board::tilePosition(char row, int col)
{
    std::string tilePos;
    // Loops through the tile bag
    for(uint32_t k = 0; k < this->board.size(); k++)
    {
        // Gets tile from the board
        std::shared_ptr<Tile> tile = this->board.at(k);
        Row tileRow = tile->row;
        Col tileCol = tile->col; 

        // Checks if the tile is at the row col
        if(tileRow == row && tileCol == col)
        {
            // Sets the string to the tile
            tilePos = tile->colour + std::to_string(tile->shape);
        }   
    }
    // Prints a space if no tile exists in the current square
    if(tilePos.empty())
    {
        tilePos = "  ";
    }

    return tilePos;
}

// Places a tile on the board
bool Board::placeTile(std::shared_ptr<Tile> tile){
    bool placed = false;
    // Checks if the board is empty
    if(this->board.empty())
    {
        // Places the tile on the board
        addTile(tile);
        // Checks if the board needs to be expanded
        expandBoard(tile->row, tile->col);
        placed = true;
    }
    else
    {
        // Checks if the tile exists on the board and if valid move
        if(!exist(tile->row, tile->col) && validMove(tile))
        {
            // Places the tile on the board
            addTile(tile);
            // Checks if the board needs to be expanded
            expandBoard(tile->row, tile->col);
            placed = true;
        }
    }
    return placed;
}

void Board::expandBoard(Row rowTile, Col colTile){
    // Minus A from the current Row entered gives you an int that is useable
    int row = rowTile - A_CHAR;
    //std::cout << "this is the rowTile in expand: " << rowTile << std::endl;
    // Expands the Row of the board
    if(row == (this->boardRow -1))this->boardRow+=2 ;

    // Expands the Col of the board
    if(colTile == (this->boardCol -1))this->boardCol+=2;
}


bool Board::validMove(std::shared_ptr<Tile> tile){
    bool validMove = false;

    // check sideways
    Col tileCol = tile->col;
    Row tileRow = tile->row;

    bool validRight = false;
    bool validLeft = false;
    bool validUp = false;
    bool validDown = false;

    int colourMatch = 1;
    int shapeMatch = 1;
  
    //check for valid tile on the right side, if exist, it will keep checking
    while(exist(tileRow, tileCol+1)){
        tileCol++;
        std::string tileAtPos = tilePosition(tileRow, tileCol);

        if(tile->colour != tileAtPos[0]){
            colourMatch = -1;
        }
        if(std::to_string(tile->shape) != std::string(1, tileAtPos[1])){
            shapeMatch = -1;
        } 
        if (tile->colour == tileAtPos[0] && std::to_string(tile->shape) == std::string(1, tileAtPos[1])) {
            colourMatch = -1;
            shapeMatch = -1;
        }
    }

    if(colourMatch != -1 || shapeMatch != -1) {
        validRight = true;
    }

    //check for valid tile on the left side, if exist, it will keep checking
    tileCol = tile->col;
    tileRow = tile->row;
    colourMatch = 1;
    shapeMatch = 1;

    while(exist(tileRow, tileCol-1)){
        tileCol--;
        
        std::string tileAtPos = tilePosition(tileRow, tileCol);
        
        if(tile->colour != tileAtPos[0]){
            colourMatch = -1;
        }
        if(std::to_string(tile->shape) != std::string(1, tileAtPos[1])){
            shapeMatch = -1;
        } 
        if (tile->colour == tileAtPos[0] && std::to_string(tile->shape) == std::string(1, tileAtPos[1])) {
            colourMatch = -1;
            shapeMatch = -1;
        }
    }

    if(colourMatch != -1 || shapeMatch != -1) {
        validLeft = true;
    }

    //check for valid tile down direction, if exist, it will keep checking
    tileCol = tile->col;
    tileRow = tile->row;
    colourMatch = 1;
    shapeMatch = 1;

    while(exist(tileRow + 1, tileCol)){
        tileRow++;
        
        std::string tileAtPos = tilePosition(tileRow, tileCol);
        
        if(tile->colour != tileAtPos[0]){
            colourMatch = -1;
        }
        if(std::to_string(tile->shape) != std::string(1, tileAtPos[1])){
            shapeMatch = -1;
        } 
        if (tile->colour == tileAtPos[0] && std::to_string(tile->shape) == std::string(1, tileAtPos[1])) {
            colourMatch = -1;
            shapeMatch = -1;
        }
    }

    if(colourMatch != -1 || shapeMatch != -1) {
        validDown = true;
    }

    //check for valid tile up direction, if exist, it will keep checking
    tileCol = tile->col;
    tileRow = tile->row;
    colourMatch = 1;
    shapeMatch = 1;

    while(exist(tileRow - 1, tileCol)){
        tileRow--;
    
        std::string tileAtPos = tilePosition(tileRow, tileCol);
        
        if(tile->colour != tileAtPos[0]){
            colourMatch = -1;
        }
        if(std::to_string(tile->shape) != std::string(1, tileAtPos[1])){
            shapeMatch = -1;
        } 
        if (tile->colour == tileAtPos[0] && std::to_string(tile->shape) == std::string(1, tileAtPos[1])) {
            colourMatch = -1;
            shapeMatch = -1;
        }
    }

    if(colourMatch != -1 || shapeMatch != -1) {
        validUp = true;
    }

    //if no match, validMove will return false and print an error message
    tileCol = tile->col;
    tileRow = tile->row;

    if (!exist(tileRow - 1, tileCol) && !exist(tileRow + 1, tileCol) && !exist(tileRow, tileCol - 1) && !exist(tileRow, tileCol + 1)){
        validMove = false;
    }
    else if (validLeft && validRight && validUp && validDown) {
        validMove = true;
    }
    else {
        std::cout << "This is not a valid move" << std::endl;
    }

    return validMove;
}

bool Board::exist(Row tileRow, Col tileCol){
    // Checks if the a tile is placed at the position the user has entered 
    bool exists = false;
    // loops through all the tiles in the board
    for(uint32_t k = 0; k < this->board.size(); k++)
    {
        
        Row row = this->board.at(k)->row;
        Col col = this->board.at(k)->col;

        // Checks if the tile exists at the Col and Row
        if(tileCol == col && tileRow == row)
        {
            exists = true;
        }
    }
    return exists;
}

// Creats a string for the current board state and returns it
std::string Board::printBoardSave(){
    std::string board;
    for(uint32_t i = 0; i < this->board.size(); i++)
    {
        std::shared_ptr<Tile> tile = this->board.at(i);
        if(i == (this->board.size() - 1))
        {
            board+= tile->colour;
            board+= std::to_string(tile->shape);
            board+= "@";
            board+= tile->row;
            board+= std::to_string(tile->col);
        }
        else
        {   
            board+= tile->colour;
            board+= std::to_string(tile->shape);
            board+= "@";
            board+= tile->row;
            board+= std::to_string(tile->col);
            board+= ", ";
        }
    }
    return board;
}   

//calculation of players' scores
int Board::calculatePoints(Row tileRow, Col tileCol){
    int score = 0;
    int tempScore = 0;
    int leftScore = 0;
    int rightScore = 0;
    int upScore = 0;
    int downScore = 0;

    //check the board for current tile
    for(uint32_t k = 0; k < this->board.size(); k++){
        Row row = this->board.at(k)->row;
        Col col = this->board.at(k)->col;
        int tempRow = row;
        int tempCol = col;
        if(tileCol == col && tileRow == row){
            bool endWhile = false;
            if(k==0){
                score++;
            }
            // check right
            if(exist(row, col+1)){
                tempScore++;
                while(exist(row, col+1) && endWhile == false){ 
                    col++;
                    tempScore++;
                    rightScore += tempScore;
                    rightScore += checkQwirkle(rightScore);
                    tempScore = 0;
                    if(exist(row, col+1) == false){
                        col = tempCol;
                        endWhile = true;
                    }
                }
                endWhile = false;
            }
            // check left
            if(exist(row, col-1)){
                tempScore++;
                while(exist(row, col-1) && endWhile == false){ 
                    col--;
                    tempScore++;
                    leftScore += tempScore;
                    leftScore += checkQwirkle(leftScore);
                    tempScore = 0;
                    if(exist(row, col-1) == false){
                        col = tempCol;
                        endWhile = true;
                    }
                }
                endWhile = false;
            }
            // check up
            if(exist(row+1, col)){
                tempScore++;
                while(exist(row+1, col) && endWhile == false){ 
                    row++;
                    tempScore++;
                    upScore += tempScore;
                    upScore += checkQwirkle(upScore);
                    tempScore = 0;
                    if(exist(row+1, col) == false){
                        row = tempRow;
                        endWhile = true;
                    }
                }
                endWhile = false;
                
            }
            // check down
            if(exist(row-1, col)){
                tempScore++;
                while(exist(row-1, col) && endWhile == false){ 
                    row--;
                    tempScore++;
                    downScore += tempScore;
                    downScore += checkQwirkle(downScore);
                    tempScore = 0;
                    if(exist(row-1, col) == false){
                        row = tempRow;
                        endWhile = true;
                    }
                }
                endWhile = false;
            }
            
            //check if all direction exists or just up and down or just left and right
            if(exist(row, col-1) && exist(row, col+1) && exist(row-1, col) && exist(row+1, col)){
                tempScore = upScore + downScore;
                tempScore--;
                score += checkQwirkle(tempScore) + tempScore;
                tempScore = leftScore + rightScore;
                tempScore--;
                score += checkQwirkle(tempScore) + tempScore;
            } else if(exist(row, col-1) && exist(row, col+1)){
                tempScore = leftScore + rightScore;
                tempScore--;
                score += checkQwirkle(tempScore) + tempScore + upScore + downScore;
            } else if(exist(row-1, col) && exist(row+1, col)){
                tempScore = upScore + downScore;
                tempScore--;
                score += checkQwirkle(tempScore) + tempScore + leftScore + rightScore;
            } else {
                score += leftScore + rightScore + upScore + downScore;
            }

        }
    }
    //return score after calculation
    return score;
}

//check if it is a qwirkle
int Board::checkQwirkle(int score){
    if(score==6) std::cout << "Qwirkle!!!" << std::endl;
    else  score = 0;

    return score;
    
}