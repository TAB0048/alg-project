#include "height_map.h"

#include <iostream>
#include <queue>
#include <algorithm>

std::string get_file_name() {
    std::string file_name;
    
    std::cout << "Enter a file name: " << std::endl;
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

std::vector<Point> BFS ( std::vector<Point>& height_map, Point start, Point end, int m, int n )
{
    // initialize queue
    std::queue<Point> q;
    std::vector<bool> visited ( m * n, false );

    // initialize previously visited nodes
    std::vector<Point> previous ( m * n, {-1, -1} );

    // add start to the queue
    q.push( start );
    visited[ start.x * n + start.y ] = true;

    // moves: up, down, left, right
    std::vector<std::pair<int, int>> moves = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

    while ( !q.empty() ) {
        Point current = q.front();
        q.pop();

        // if at end, return distance
        if ( current.x == end.x && current.y == end.y ) {
            std::vector<Point> path;
            while ( current.x != start.x || current.y != start.y ) {
                path.push_back(current);
                current = previous[ current.x * n + current.y ];
            }
            path.push_back(start);
            reverse( path.begin(), path.end() );
            return path;
        }

        // otherwise process neighbours
        for ( const auto& move : moves ) {
            int row = current.x + move.first;
            int col = current.y + move.second;

            int new_idx = row * n + col;
            int curr_idx = current.x * n + current.y;

            if ( row >= 0 && row < m && col >= 0 && col < n 
                && ( height_map[ new_idx ].val == height_map[ curr_idx ].val
                  || height_map[ new_idx ].val - height_map[ curr_idx ].val == 1 ) 
                && visited[ new_idx ] == false ) {
                
                q.push( {row, col} ); // add to the queue
                visited[ new_idx ] = true; // mark as visited
                previous[ new_idx ] = current; // update previous node
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

void get_path_length( std::vector<Point> shortest_path )
{
    if ( shortest_path.size() == 0 )
        std::cout << "Path length: 0" << std::endl;
    else
        std::cout << "Path length: " << shortest_path.size() - 1 << std::endl;
}