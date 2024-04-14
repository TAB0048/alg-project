#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Point
{
    int x;
    int y;
    char val;
};

void read_data( ifstream& input_file, vector<Point>& height_map, Point& start, Point& end, int& m, int& n )
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

vector<Point> BFS ( vector<Point>& height_map, Point start, Point end, int m, int n )
{
    // initialize queue
    queue<Point> q;
    vector<bool> visited ( m * n, false );

    // initialize previously visited nodes
    vector<Point> previous ( m * n, {-1, -1} );

    // add start to the queue
    q.push( start );
    visited[ start.x * n + start.y ] = true;

    // moves: up, down, left, right
    vector<pair<int, int>> moves = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

    while ( !q.empty() ) {
        Point current = q.front();
        q.pop();

        // if at end, return distance
        if ( current.x == end.x && current.y == end.y ) {
            vector<Point> path;
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

void write_path( vector<Point> height_map, vector<Point> shortest_path, int n )
{
    cout << "Shortest path: " << endl;
    for ( const auto& step : shortest_path )
    {
        cout << "[" << step.x << ", " << step.y << "], height: " << height_map[ step.x * n + step.y ].val << endl;
    }
}


int main()
{
    ifstream input_file ( "HeightMap1.txt" );
    if ( !input_file ) {
        cerr << "Couldn't open input file." << endl;
        return -1;
    }

    int m, n;
    vector<Point> height_map;
    Point start, end;

    read_data( input_file, height_map, start, end, m, n );

    vector<Point> shortest_path = BFS( height_map, start, end, m, n );
    
    write_path( height_map, shortest_path, n );
    
    cout << "Path length: " << shortest_path.size() - 1 << endl;

    return 0;
}