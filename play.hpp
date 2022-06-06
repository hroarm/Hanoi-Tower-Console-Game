#ifndef PLAY_HPP
#define PLAY_HPP

/*
 *brief: puts disks at starting position (at 1st tower)
 */
void starting_position(int);

/*
 *brief: function for printing the interface of 'Play' section with disks and towers
 */
void printplay();

/*
 *brief: function for moving disks between two towers
 */
void move(int, int, int);

/*
 *brief: shows records
 */
void showRecords();

/*
 *brief: function for the play section to start the game and play it with the selected amount of disks
 */
void play(int);

/*
 *brief: auto solver of hanoi tower 
 */
void solver(int);

#endif // Play_HPP
