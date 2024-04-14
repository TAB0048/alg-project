#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void read_data( ifstream& input_file, vector<char>& height_map,pair<int, int>& start, pair<int, int>& end,
                int& m, int& n )
{
    input_file >> m >> n;

    for ( int i = 0; i < m * n; i++ ) {
        char c;
        input_file >> c;

        if ( c == 'S' ) {
            c = 'a';
            start = {i / n, i % n };
        }
        
        if ( c == 'E' ) {
            c = 'z';
            end = {i / n, i % n };
        }

        height_map.push_back(c);
    }
}

vector<pair<int, int>> BFS ( vector<char>& height_map, pair<int, int> start, pair<int, int> end, int m, int n )
{
    // initialize queue
    queue<pair<int, int>> q;
    vector<bool> visited ( m * n, false );

    // initialize previously visited nodes
    vector<pair<int, int>> previous ( m * n, {-1, -1} );

    // add start to the queue
    q.push( start );
    visited[ start.first * n + start.second ] = true;

    // moves: up, down, left, right
    vector<pair<int, int>> moves = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

    while ( !q.empty() ) {
        pair<int, int> current = q.front();
        q.pop();

        // if at end, return distance
        if ( current == end ) {
            vector<pair<int, int>> path;
            while ( current != start ) {
                path.push_back(current);
                current = previous[ current.first * n + current.second ];
            }
            path.push_back(start);
            reverse( path.begin(), path.end() );
            return path;
        }

        // otherwise process neighbours
        for ( const auto& move : moves ) {
            int row = current.first + move.first;
            int col = current.second + move.second;

            int new_idx = row * n + col;
            int curr_idx = current.first * n + current.second;

            if ( row >= 0 && row < m && col >= 0 && col < n 
                && ( height_map[ new_idx ] == height_map[ curr_idx ]
                  || height_map[ new_idx ] - height_map[ curr_idx ] == 1 ) 
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


int main()
{
    ifstream input_file ( "HeightMap1.txt" );
    if ( !input_file ) {
        cerr << "Couldn't open input file." << endl;
        return -1;
    }

    int m, n;
    vector<char> height_map;
    pair<int, int> start, end;

    read_data( input_file, height_map, start, end, m, n );

    vector<pair<int, int>> shortest_path = BFS( height_map, start, end, m, n );
    cout << shortest_path.size() - 1 << endl;

    return 0;
}