#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void read_data( ifstream& input_file, int& m, int& n, vector<char>& height_map,
                pair<int, int> start, pair<int, int> end )
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

    read_data( input_file, m, n, height_map, start, end );

    return 0;
}