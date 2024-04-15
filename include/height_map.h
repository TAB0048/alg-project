#pragma once 

#include <vector>
#include <fstream>

struct Point
{
    int x;
    int y;
    char val;
};

void read_data( std::ifstream& input_file, std::vector<Point>& height_map, Point& start, Point& end, int& m, int& n );

std::vector<Point> BFS ( std::vector<Point>& height_map, Point start, Point end, int m, int n );

void write_path( std::vector<Point> height_map, std::vector<Point> shortest_path, int n );
