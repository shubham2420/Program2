//
// Created by Yusuf Pisan on 4/18/18.
//

#include <fstream>
#include <iostream>
#include "maze.h"

using namespace std;

//overrides output operator for maze
ostream &operator<<(ostream &Out, const Maze &Maze) {
  for (int Row = 0; Row < Maze.Height; ++Row) {
    for (int Col = 0; Col < Maze.Width; ++Col) {
      Out << Maze.Field[Row][Col];
    }
    Out << endl;
  }
  Out << endl;
  return Out;
}

// For Clion, need the following line in CMakeLists.txt so maze.txt is found
// at the same location as the cpp files
// # need to load data files from current directory as cpp files
// set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
Maze::Maze(const string &FileName) {
  ifstream InFile;
  InFile.open(FileName);
  if (!InFile) {
    cout << "Unable to open file";
    exit(1); // terminate with error
  }
  InFile >> Width >> Height;
  InFile >> ExitRow >> ExitColumn;
  string Str;
  getline(InFile, Str);
  for (int Row = 0; Row < Height; ++Row) {
    for (int Col = 0; Col < Width; ++Col) {
      InFile.get(Field[Row][Col]);
      // cout << Row << ", " << col << ": " << field[Row][col] << endl;
    }
    getline(InFile, Str);
  }

}

//gets the exit row of the maze 
int Maze::getExitRow() const {
  return ExitRow;
}

//gets the exit column for the maze 
int Maze::getExitColumn() const {
  return ExitColumn;
}

//checks if the next spot to move is clear 
bool Maze::isClear(int Row, int Col) const {
  return Field[Row][Col] == ' ';
}

//marks the path with a star in maze
void Maze::markAsPath(int Row, int Col) {
  Field[Row][Col] = '*';
}

//marks the past with a plus if it is visited 
void Maze::markAsVisited(int Row, int Col) {
  Field[Row][Col] = '+';
}

//gets the width of the maze 
int Maze:: getWidth() const{
  return Width;
}

//gets the height of the maze 
int Maze:: getHeight() const{
  return Height;
}

//Checks if the spot is a wall
bool Maze::isWall(int Row, int Col){
  return Field[Row][Col] == 'X';
}

//checks is the spot is a path marked with star 
bool Maze::isPath(int Row, int Col){
  return Field[Row][Col] == '*';
}

//checks if the spot is visited with a plus 
bool Maze::isVisited(int Row, int Col){
  return Field[Row][Col] == '+';
}