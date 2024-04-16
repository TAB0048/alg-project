#include "height_map.h"

#include <iostream>
#include <queue>
#include <algorithm>

std::string get_file_name() {
    std::string file_name;
    
    std::cout << "Enter a file name (e.g. HeightMap1.txt): " << std::endl;
    std::cin >> file_name;

    file_name = "../tests/" + file_name;
    return file_name;
}


void read_data( std::ifstream& input_file, std::vector<Point>& height_map, Point& start, Point& end, int& m, int& n )
{
    input_file >> m >> n;

    for ( int i = 0; i < m; i++ ) {
        for ( int j = 0; j < n; j++ ) {
            char c;
            input_file >> c;

            if ( c == 'S' ) {
                c = 'a';
                start = {i, j, 'a'};
            }
        
            if ( c == 'E' ) {
                c = 'z';
                end = {i, j, 'z'};
            }

            height_map.push_back( {i, j, c} );
        }
    }
}


int get_index ( int x, int y, int cols ) 
{
    return x * cols + y;
}


bool equal_coordinates ( Point a, Point b ) 
{
    if ( a.x == b.x && a.y == b.y )
        return true;
    else
        return false;
}


bool valid_coordinates ( int x, int y, int rows, int cols )
{
    if ( x >= 0 && x < rows && y >= 0 && y < cols ) 
        return true;
    else
        return false;
}


bool allowed_height_difference ( std::vector<Point>& height_map, int curr_idx, int new_idx )
{
    if ( height_map[ new_idx ].val == height_map[ curr_idx ].val
      || height_map[ new_idx ].val - height_map[ curr_idx ].val == 1 ) 
      return true;
    else 
        return false;
}

std::vector<Point> BFS ( std::vector<Point>& height_map, Point start, Point end, int m, int n )
{
    // initialize queue
    std::queue<Point> q;
    std::vector<bool> visited ( m * n, false );

    // initialize previously visited Points
    std::vector<Point> previous ( m * n, {-1, -1} );

    // add start to the queue
    q.push( start );
    int idx = get_index( start.x, start.y, n );
    visited[ idx ] = true;

    // moves: up, down, left, right
    std::vector<std::pair<int, int>> moves = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

    while ( !q.empty() ) {
        Point current = q.front();
        q.pop();

        // if at end, return distance
        if ( equal_coordinates( current, end ) ) {
            std::vector<Point> path;

            while ( !equal_coordinates( current, start ) ) {
                path.push_back(current);
                int curr_idx = get_index( current.x, current.y, n );
                current = previous[ curr_idx ];
            }
            
            path.push_back(start);
            reverse( path.begin(), path.end() );
            return path;
        }

        // otherwise process neighbours
        for ( const auto& move : moves ) {
            int row = current.x + move.first;
            int col = current.y + move.second;

            int new_idx = get_index( current.x + move.first, current.y + move.second, n );
            int curr_idx = get_index( current.x, current.y, n );

            if ( valid_coordinates( row, col, m, n ) 
              && allowed_height_difference( height_map, curr_idx, new_idx )
              && !visited[ new_idx ] ) {
                
                q.push( {row, col} ); // add to the queue
                visited[ new_idx ] = true; // mark as visited
                previous[ new_idx ] = current; // update previous Point
            }
        }
    }

    // return empty vector if not found
    return {};
}


void write_path( std::vector<Point> height_map, std::vector<Point> shortest_path, int n )
{
    std::cout << "Shortest path: " << std::endl;
    
    if ( shortest_path.size() == 0 ) {
        std::cout << "Path doesn't exist." << std::endl;
        return;
    }

    for ( const auto& point : shortest_path )
    {
        std::cout << "[" << point.x << ", " << point.y << "], height: " 
             << height_map[ point.x * n + point.y ].val << std::endl;
    }
}

void write_path_length( std::vector<Point> shortest_path )
{
    if ( shortest_path.size() == 0 )
        std::cout << "Path length: 0" << std::endl;
    else
        std::cout << "Path length: " << shortest_path.size() - 1 << std::endl;
}