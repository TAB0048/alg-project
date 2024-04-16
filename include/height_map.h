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
/*!
  \return Name of the file with corresponding "prefix" (path).
*/ 
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


//! Function to calculate the corresponding index for x, y coordinates. 
/*!
  \param x The x coordinate. 
  \param y The y coordinate.
  \param cols The number of columns (width) of an array/vector. 
  \return Calculated index as a single integer. 
*/ 
int get_index ( int x, int y, int cols );


//! Function to check if two points have the same coordinates. 
/*!
  \param a The first Point.  
  \param b The second Point. 
  \return True if the coordinates of given Points are the same, false otherwise. 
*/ 
bool equal_coordinates ( Point a, Point b );


//! Function to check if given coordinates are valid. 
/*!
  \param x The current x coordinate. 
  \param y The current y coordinate.
  \param rows The total number of rows. 
  \param cols The total number of columns. 
  \return True if coordinates are valid, false otherwise. 
*/ 
bool valid_coordinates ( int x, int y, int rows, int cols );


//! Function to check if two Points on a height map have allowed height difference. 
/*!
  \param height_map The height map. 
  \param curr_idx The current index of a Point on a height map. 
  \param new_indx The index of a next Point on a height map.
  \return True if the height of next Point is bigger by 1 or the same, false otherwise. 
*/ 
bool allowed_height_difference ( std::vector<Point>& height_map, int curr_idx, int new_idx );


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


//! Function to write the length of the shortest path. 
/*!
  \param shortest_path Vector representing the shortest path.
*/
void write_path_length( std::vector<Point> shortest_path );