#include <iostream>

#include "creature.h"
#include "maze.h"


void test() {
    Maze M("maze.txt");
    cout << M << endl;
    Creature C(4, 4);
    cout << C << endl;
    cout << "Path: " << C.solve(M) << endl;
    cout << M << endl;
}

void test1() {
    Maze M("maze1.txt");
    cout << M << endl;
    Creature C1(3, 3);
    cout << C1 << endl;
    cout << "Path: " << C1.solve(M) << endl;
    cout << M << endl;
}
void test2() {
    Maze M("maze2.txt");
    cout << M << endl;
    Creature C2(3, 3);
    cout << C2 << endl;
    cout << "Path: " << C2.solve(M) << endl;
    cout << M << endl;
}

void test3() {
    Maze M("maze3.txt");
    cout << M << endl;
    Creature C3(0, 1);
    cout << C3 << endl;
    cout << "Path: " << C3.solve(M) << endl;
    cout << M << endl;
}

int main() {
    test();
    cout << "--------------------------------------" << endl;
    test1();
    cout << "--------------------------------------" << endl;
    test2();
    cout << "--------------------------------------" << endl;
    test3();
    cout << "--------------------------------------" << endl;
    cout << "Done!" << std::endl;
    return 0;
}
