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

//! Function to get the name of the file with testing data. 
std::string get_file_name();

//! Function for reading data from an input file and initializing the height map.
/*!
  \param input_file Input stream containing data to be read.
  \param height_map Vector to store cells of the height map.
  \param start Starting point of the height map.
  \param end Ending point of the height map.
  \param m Number of rows in the height map.
  \param n Number of columns in the height map.
*/ 
void read_data( std::ifstream& input_file, std::vector<Point>& height_map, Point& start, Point& end, int& m, int& n );


//! BFS algorithm to find the shortest path from the start point to the end point on the height map.
/*!
  \param height_map Vector representing the height map where we search for the path.
  \param start Starting point of the height map.
  \param end Ending point of the height map.
  \param m Number of rows in the height map.
  \param n Number of columns in the height map.
  \return The shortest path as a vector of Points.
*/
std::vector<Point> BFS ( std::vector<Point>& height_map, Point start, Point end, int m, int n );


//! Function to write the found path on the height map.
/*!
  \param height_map Vector representing the height map.
  \param shortest_path Vector representing the shortest path.
  \param n Number of columns in the height map.
*/
void write_path( std::vector<Point> height_map, std::vector<Point> shortest_path, int n );
