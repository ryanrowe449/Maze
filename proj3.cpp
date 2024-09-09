#include "Stack.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;
using namespace cop4530;
class node
{
private:
    int x;
    int y;
    int val;
    bool visited;

public:
    node(int xc, int yc, int val1)
    {
        x = xc;
        y = yc;
        val = val1;
        visited = false;
    }
    bool isVisited()
    {
        return visited;
    }
    bool makeTrue()
    {
        visited = true;
    }
    int getX()
    {
        return x;
    }
    int getY()
    {
        return y;
    }
    int getVal()
    {
        return val;
    }
};
// functions used in main
int getBin(int num)
{
    int binaryValue = 0;
    int base = 1;
    while (num > 0)
    {
        int digit = num % 2;
        binaryValue += digit * base;
        num /= 2;
        base *= 10;
    }
    return binaryValue;
}
bool northWall(int num)
{
    return num % 10 == 1;
}
bool eastWall(int num)
{
    num /= 10;
    return num % 10 == 1;
}
bool southWall(int num)
{
    num /= 100;
    return num % 10 == 1;
}
bool westWall(int num)
{
    num /= 1000;
    return num % 10 == 1;
}

int findNode(int x1, int y1, vector<node> mazeobj)
{
    int pos = 0;
    bool found = false;
    while (!found)
    {
        if (mazeobj[pos].getX() == x1 && mazeobj[pos].getY() == y1)
            return pos;
        pos++;
    }
}

int main()
{
    char dig;
    string numTemp = "";
    int num;
    int totalRows;
    int totalCols;
    int startx;
    int starty;
    int endx;
    int endy;
    int row = 0;
    int col = 0;
    int count = 0;
    int count2 = 0;
    // getting the total rows and cols and creating the array
    while (cin.get(dig))
    {
        if (isdigit(dig))
        {
            count++;
            numTemp += dig;
        }
        else if (count > 0)
        {
            num = stoi(numTemp);
            numTemp = "";
            count = 0;
            count2++;
            if (count2 == 1)
            {
                totalRows = num;
            }
            else if (count2 == 2)
            {
                totalCols = num;
                break;
            }
        }
    }
    numTemp = "";
    count = 0;
    count2 = 0;
    int maze[totalRows][totalCols];
    int size = (totalRows - 1) * (totalCols - 1);
    // adding numbers to array
    while (cin.get(dig))
    {
        if (isdigit(dig))
        {
            numTemp += dig;
            count++;
        }
        else if (count > 0)
        {
            num = stoi(numTemp);
            numTemp = "";
            count = 0;
            if (row < totalRows)
            {
                maze[row][col] = num;
                col++;
                if (col == totalCols)
                {
                    col = 0;
                    row++;
                }
            }
            else
                count2++; // getting the starting and ending points
            if (count2 == 1)
            {
                startx = num;
                numTemp = "";
            }
            else if (count2 == 2)
                starty = num;
            else if (count2 == 3)
                endx = num;
            else if (count2 == 4)
            {
                endy = num;
                break;
            }
        }
    }

    // Store elements from maze in vector mazeobj
    vector<node> mazeobj;
    for (int i = 0; i < totalRows; i++)
    {
        for (int j = 0; j < totalCols; j++)
        {
            node element(i, j, maze[i][j]);
            mazeobj.push_back(element);
        }
    }
    // Depth first search to find the path to the goal node (exit of the maze)
    Stack<node> path;
    Stack<node> print;
    // find start node
    int start = findNode(startx, starty, mazeobj);
    int end = findNode(endx, endy, mazeobj);
    mazeobj[start].makeTrue();
    path.push(mazeobj[start]);
    int success = 0;

    // start the search
    while (!path.empty())
    {
        row = path.top().getX();
        col = path.top().getY();
        int pos = findNode(row, col, mazeobj);
        if (path.top().getX() == mazeobj[end].getX() && path.top().getY() == mazeobj[end].getY())
        {
            // success
            while (!path.empty())
            {
                print.push(path.top());
                path.pop();
            }
            while (!print.empty())
            {
                cout << "(" << print.top().getX() << "," << print.top().getY() << ")\n";
                print.pop();
            }
            success = 1;
            break;
        }
        // if there is no north wall on the current node, and the north node has not been visited...
        else if (!northWall(getBin(mazeobj[pos].getVal())) && !mazeobj[findNode(row - 1, col, mazeobj)].isVisited())
        {
            row--;
            mazeobj[findNode(row, col, mazeobj)].makeTrue();
            path.push(mazeobj[findNode(row, col, mazeobj)]);
        }
        else if (!eastWall(getBin(mazeobj[pos].getVal())) && !mazeobj[findNode(row, col + 1, mazeobj)].isVisited())
        {
            col++;
            mazeobj[findNode(row, col, mazeobj)].makeTrue();
            path.push(mazeobj[findNode(row, col, mazeobj)]);
        }
        else if (!southWall(getBin(mazeobj[pos].getVal())) && !mazeobj[findNode(row + 1, col, mazeobj)].isVisited())
        {
            row++;
            mazeobj[findNode(row, col, mazeobj)].makeTrue();
            path.push(mazeobj[findNode(row, col, mazeobj)]);
        }
        else if (!westWall(getBin(mazeobj[pos].getVal())) && !mazeobj[findNode(row, col - 1, mazeobj)].isVisited())
        {
            col--;
            mazeobj[findNode(row, col, mazeobj)].makeTrue();
            path.push(mazeobj[findNode(row, col, mazeobj)]);
        }
        else
        {
            // backtrack
            while (!path.empty() && (northWall(getBin(path.top().getVal())) || mazeobj[findNode(row - 1, col, mazeobj)].isVisited()) && (eastWall(getBin(path.top().getVal())) || mazeobj[findNode(row, col + 1, mazeobj)].isVisited()) && (southWall(getBin(path.top().getVal())) || mazeobj[findNode(row + 1, col, mazeobj)].isVisited()) && (westWall(getBin(path.top().getVal())) || mazeobj[findNode(row, col - 1, mazeobj)].isVisited()))
            {
                path.pop();
                row = path.top().getX();
                col = path.top().getY();
            }
        }
    }
    if (success != 1)
        cout << "Please take care of Leonetta for me.\n";
}