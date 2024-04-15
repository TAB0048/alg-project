#include "height_map.h"
#include <iostream>
using namespace std;

int main()
{
    string file_name = get_file_name();

    ifstream input_file ( file_name );
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