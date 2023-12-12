# Maze
A University project in which I defined and implemented a stack class and used it to conduct a depth-first search
# Usage
To run this program yourself, download the source code files, type 'make' into the command line, and direct the test cases (the ones provided are maze0, maze1...) into proj3.x (e.g. proj3.x < maze3).
# How it Works
The runnable program reads a maze and creates a vector holding objects representing each point in the maze. Each object 'node' holds the x and y coordinates of the node, the value of the node (is used to determine what walls a point in the maze has), and a boolean to determine whether the node has been visited or not. To find the path through a given maze, the program uses the stack template I implemented to conduct a depth-first search on the vector. If a path is found, the program spits out the x and y coordinates of each point in the path stored in the stack. If not, a failure message is printed.
# Format of Mazes
The first line of a maze file is the number of columns, then rows. The following rows*columns numbers represent each point in a maze. Each number is between 0-15, representing a 4-digit binary number. If a digit is 1, there is a wall there; if it is a 0, there is no wall. 1's bit = north wall, 2's bit = east wall, 4's bit = south wall, and 8's bit = west wall (e.g. 1101 has north, south, and west walls but no east wall). Finally, the last four digits: the first two are the x and y coordinates of the starting point of the maze, and the last two are the x and y coordinates of the end point.
