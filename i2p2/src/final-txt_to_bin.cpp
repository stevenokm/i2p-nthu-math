/*** convert text version input to binary version input ***/
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

// error and exit
void error_and_exit()
{
    cout << "Error: Invalid input" << endl;
    exit(1);
}

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        cout << "Usage: txt_to_bin <input_file> <output_file>" << endl;
        return 1;
    }

    ifstream input_file(argv[1]);
    ofstream output_file(argv[2], ios::binary | ios::trunc);

    if (!input_file.is_open())
    {
        cout << "Could not open input file" << endl;
        return 1;
    }

    if (!output_file.is_open())
    {
        cout << "Could not open output file" << endl;
        return 1;
    }

    string line, temp;
    unsigned num_of_vertices = 1;
    // read dimensions
    getline(input_file, line);
    unsigned num_of_dimensions = stoul(line);
    // write dimensions
    output_file.write((char *)&num_of_dimensions, sizeof(unsigned));
    while (getline(input_file, line))
    {
        // check the geometry type
        switch (line[0])
        {
        case 't':
        case 'p':
        case 'l':
            // get the number of vertices from the next line
            getline(input_file, temp);
            num_of_vertices = stoul(temp);
            break;
        default:
            error_and_exit();
        }
        // write the geometry type
        char geometry_type = line[0];
        output_file.write(&geometry_type, 1);
        // write the number of vertices
        if (line[0] == 't' || line[0] == 'p' || line[0] == 'l')
        {
            output_file.write((char *)&num_of_vertices, sizeof(unsigned));
        }
        // convert the lines to binary
        for (int i = 0; i < num_of_vertices; i++)
        {
            getline(input_file, line);
            stringstream ss(line);
            for (int j = 0; j < num_of_dimensions; j++)
            {
                getline(ss, temp, ',');
                double value = stod(temp);
                output_file.write((char *)&value, sizeof(double));
            }
        }
    }

    input_file.close();
    output_file.close();

    return 0;
}