/**
 * Description: Implementation for Creature 
 * @author: Shubham Kamboj 
 * @version date: October 29, 2020 
 * */
#include "creature.h"

//Overrides the default ouput for creature object 
std::ostream &operator<<(std::ostream &Out, const Creature &Creature) {
  Out << "Creature is located at " << Creature.Row << ", " << Creature.Col << endl;
  return Out;
}

//creature constructor with two arguments: Row, Col 
Creature::Creature(int Row, int Col) : Row(Row), Col(Col) {
  Path = "";
}

//Checks if the creature is at exit 
bool Creature::atExit(const Maze &Maze) const {
  if(Maze.getExitColumn() == Col & Maze.getExitRow() == Row){
    return true;
  }
  return false;
}

//solves the maze 
string Creature::solve(Maze &Maze) {
  Maze.markAsPath(Row, Col);
    if (!atExit(Maze)) {
        if (goNorth(Maze)) {
            goNorth(Maze);
        }
        if (goWest(Maze)) {
            goWest(Maze);
        }
        if (goEast(Maze)) {
            goEast(Maze);
        }
        if (goSouth(Maze)) {
            goSouth(Maze);
        }

    }
    if (!atExit(Maze)) {
        Path.append("X");
    }
    return Path;

}

//recursive functionf for going north 
bool Creature::goNorth(Maze &Maze) {
  bool reached = false;
  if(Maze.isClear(Row - 1, Col)){
    Row = Row - 1;
    Path.append("N");
    Maze.markAsPath(Row, Col);
      if(atExit(Maze)){
        reached = true;
      } else {
            reached = goNorth(Maze);
            if (!reached) {
                reached = goWest(Maze);
                if (!reached) {
                    reached = goEast(Maze);
                    if (!reached) {
                        Maze.markAsVisited(Row, Col);
                        Row = Row + 1;
                        Path.pop_back();
                    }
                }
            }
        }
    }
    return reached;
}

//recursive function for going west 
bool Creature::goWest(Maze &Maze) {
  bool reached = false;
  if(Maze.isClear(Row, Col -1) ){
    Col = Col - 1;
    Path.append("W");
    Maze.markAsPath(Row, Col);
      if(atExit(Maze)){
        reached = true;
      } else {
            reached = goWest(Maze);
            if (!reached) {
                reached = goSouth(Maze);
                if (!reached) {
                    reached = goNorth(Maze);
                    if (!reached) {
                        Maze.markAsVisited(Row, Col);
                        Col = Col + 1;
                        Path.pop_back();
                    }
                }
            }
        }
    }
    return reached;
}

//recursive function for going east 
bool Creature::goEast(Maze &Maze) {
  bool reached = false;
  if(Maze.isClear(Row , Col + 1) ){
    Col = Col + 1;
    Path.append("E");
    Maze.markAsPath(Row, Col );
      if(atExit(Maze)){
        reached = true;
      } else {
            reached = goEast(Maze);
            if (!reached) {
                reached = goNorth(Maze);
                if (!reached) {
                    reached = goSouth(Maze);
                    if (!reached) {
                        Maze.markAsVisited(Row, Col);
                        Col = Col - 1;
                        Path.pop_back();
                    }
                }
            }
        }
    }
    return reached;
}

//recursive function for goimg south 
bool Creature::goSouth(Maze &Maze) {
  bool reached = false;
  if(Maze.isClear(Row +1, Col)){
    Row = Row + 1;
    Path.append("S");
    Maze.markAsPath(Row, Col);
      if(atExit(Maze)){
        reached = true;
      } else {
            reached = goSouth(Maze);
            if (!reached) {
                reached = goEast(Maze);
                if (!reached) {
                    reached = goWest(Maze);
                    if (!reached) {
                        Maze.markAsVisited(Row, Col);
                        Row = Row - 1;
                        Path.pop_back();
                    }
                }
            }
        }
    }
    return reached;
}