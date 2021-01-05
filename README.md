# Program2

CSS342-Program2

Goal: Understanding Recursion

Problem: Design and implement an algorithm for solving a maze . Produce ASCII output indicating path.

The problem description is taken from Carrano Chapter 5 Problem 9 (Carrano Chapter 5, Problem 4 in 6th edition)

Starter Code for this problem is available at Course Google Drive (Links to an external site.)

The maze is provided by a text file in the following format:

20 7 0 18 xxxxxxxxxxxxxxxxxx x x x xxxx x x xxxxx xxxxx xx x x xxxxx xxxxxxx xx x x x xx xx x x xxxxxxxxxx xx x xxxxxxxxxxxxxxxxxxxx

The first 2 numbers are: width-of-maze, height-of-maze The next 2 numbers are: row-exit column-exit x represents wall space represents movable space Unlike the textbook version, the entrance to the Maze is not specified as part of the maze.txt file but will be provided by Creature's location

When maze is printed, you should also add

part of the path to exit
visited square not part of the path to exit When the solved maze is printed, you should get (without color)
Path: EEENNNEEEEEESEESSSEEENNNNN xxxxxxxxxxxxxxxxxxx x xxxxxx x xxxxxxxxxxxxx x xxxxxxxxxxxxxxx x x++++++xxxxx x xxxxxxxxxx+xx***x xxxxxxxxxxxxxxxxxxxx Above maze has "red *" to indicate path, "green star" to indicate starting location and "+" to indicate explored areas that are not part of the final path to exit. The ASCII representation of the maze is important for debugging, but does not have to be exactly as above. The Path string has to exactly match the solution.

You can assume that mazes will have less than 100 rows and 100 columns.

You need to submit program2.zip with the following files in it. Put all the files below into a folder called "program2", create a zip file of the folder and submit it. Do not submit executables or other files from IDE.

maze.h, maze.cpp - modify as needed creature.h, creature.cpp - implement functions and modify as needed main.cpp - add your own tests maze.txt - original sample maze file (do not modify) maze1.txt, maze2.txt maze3.txt - 3 different mazes that your main.cpp uses to test your program output.txt - Shows the output from compiling and running your program on CSS Linux Labs. Can be generated using simplecompile.sh README.md - make changes as needed to describe your program simplecompile.sh - easy way to compile, test and run your program (you do not need to modify it) Important: All the file names are in lowercase which may not be the default for your IDE. Configure your IDE to create lowercase files for classes.

Implement the following class functions in Creature class:

Creature(int Row, int Col); // returns a string in the form of NNEEN // (where N means North, E means East, etc) string solve(Maze &Maze); bool atExit(const Maze &Maze) const; Go in a specific direction -- these 4 functions will be similar string goNorth(Maze &Maze); string goSouth(Maze &Maze); string goEast(Maze &Maze); string goWest(Maze &Maze); // prints current location of creature, for example C(7,3) ostream &operator<<(ostream &out, const Creature &creature);

You may choose to have additional public or private functions as needed.

All functions in the .h file and in the .cpp files MUST have at least one line of documentation. Your code should not go over 80 columns. Should not have to scroll left-right to read it.

Grading Rubric If the program does not compile and run on CSS Linux Lab, the maximum mark is 50%. This can be due to a missing semicolon, a function, pragmas that do not work in CSS Linux Lab or a variety of other reasons. Testing your final version in CSS Linux Lab is important. Completeness and correctness (50%) Passes all tests > Minor Errors > Major Errors > Wont Run > Wont Compile Good programming practices (30%) Efficient, modular, Object oriented valgrind reports memory leaks compiler gives warnings (when compiled with -Wall -Wextra -Wno-sign-compare)
lack of tests Documentation and understandability (20%) All lines less than 80 characters long All functions documented in header AND implementation file Code is properly and consistently indented README file is informative on what the code does overall, how to compile and run it.
