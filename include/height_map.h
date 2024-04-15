#pragma once 

#include <vector>
#include <fstream>

//! Structure representing a single cell on a height map.
struct Point
{
    int x;      //!< x coordinate
    int y;      //!< y coordinate
    char val;   //!< value (height) of the cell
};

//! Function for reading data from an input file. 
void read_data( std::ifstream& input_file,  //!< input stream containing data to be read
                std::vector<Point>& height_map, //!< vector to store cells of the height map
                Point& start,   //!< starting point of the height map
                Point& end, //!< ending point of the height map
                int& m, //!< number of rows in the map
                int& n );   //!< number of columns in the map

//! BFS algorithm to find the shortest path from the start point to the end point.
std::vector<Point> BFS ( std::vector<Point>& height_map,    //!< vector of the map where we search for the path
                         Point start,   //!< starting point of the height map
                         Point end, //!< ending point of the height map
                         int m, //!< number of rows in the map
                         int n );   //!< number of columns in the map

//! Function to write the found path. 
void write_path( std::vector<Point> height_map, //!< vector of the height map
                 std::vector<Point> shortest_path, //!< shortest path
                 int n );   //!< number of columns in the map
