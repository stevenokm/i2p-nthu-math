/*** convert binary version input to human-readable input & dump hex file ***/
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>

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
        cout << "Usage: bin_to_txt <input_file> <output_file>" << endl;
        return 1;
    }

    ifstream input_file(argv[1], ios::binary);
    ofstream output_file(argv[2], ios::trunc);

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

    char input;
    unsigned num_of_vertices = 1;
    // read dimensions
    unsigned num_of_dimensions = 2;
    input_file.read((char *)&num_of_dimensions, sizeof(unsigned));
    // write dimensions
    output_file << "# " << num_of_dimensions << endl;
    while (input_file.get(input))
    {
        // check the geometry type
        switch (input)
        {
        case 't':
        case 'p':
        case 'l':
            // get the number of vertices from the next line
            input_file.read((char *)&num_of_vertices, sizeof(unsigned));
            break;
        default:
            error_and_exit();
        }
        // write the geometry type
        char geometry_type = input;
        output_file << "# " << geometry_type << endl;
        // write the number of vertices
        if (geometry_type == 't' || geometry_type == 'p' || geometry_type == 'l')
        {
            output_file << "# " << num_of_vertices << endl;
        }
        // convert the lines to human-readable format
        for (int i = 0; i < num_of_vertices; i++)
        {
            output_file << "# " << setprecision(15) << fixed;
            for (int j = 0; j < num_of_dimensions; j++)
            {
                double temp;
                input_file.read((char *)&temp, sizeof(double));
                if (j != 0)
                {
                    output_file << ",";
                }
                output_file << temp;
            }
            output_file << endl;
        }
    }

    input_file.close();

    input_file.open(argv[1], ios::binary);
    output_file << "# Hex dump" << endl;

    char file_block = 0;
    unsigned offset_count = 0;

    input_file.read(&file_block, 1);
    while (!input_file.eof())
    {
        int z = file_block & 0xff;
        output_file << std::hex
                    << std::setfill('0')
                    << std::setw(2)
                    << z
                    << " ";
        offset_count++;
        if (offset_count % 16 == 0)
        {
            output_file << endl;
        }
        input_file.read(&file_block, 1);
    }
    output_file << endl;
    output_file.close();

    return 0;
}
