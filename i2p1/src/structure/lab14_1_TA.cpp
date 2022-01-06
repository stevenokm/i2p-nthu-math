#include <iostream>
#include <vector>
using namespace std;
typedef struct coo_sparse_matrix_struct
{
    unsigned long rows;
    unsigned long cols;
    std::vector<unsigned long> row_ind;
    std::vector<unsigned long> col_ind;
    std::vector<long> val;
} coo_sparse_matrix;

typedef struct matrix_struct
{
    unsigned long rows;
    unsigned long cols;
    std::vector< std::vector<long> > val;
} matrix;

void insert_coo_matrix_element(
    coo_sparse_matrix &coo_matrix,
    unsigned long row,
    unsigned long col,
    long val);
void sort_col_ind(coo_sparse_matrix &coo_matrix)
{
    for (int i = 0; i < coo_matrix.col_ind.size(); i++)
    {
        for (int j = i + 1; j < coo_matrix.col_ind.size(); j++)
        {
            if (coo_matrix.col_ind[i] > coo_matrix.col_ind[j])
            {
                swap(coo_matrix.col_ind[i], coo_matrix.col_ind[j]);
                swap(coo_matrix.row_ind[i], coo_matrix.row_ind[j]);
                swap(coo_matrix.val[i], coo_matrix.val[j]);
            }
        }
    }
}
void sort_row_ind(coo_sparse_matrix &coo_matrix)
{
    for (int i = 0; i < coo_matrix.row_ind.size(); i++)
    {
        for (int j = i + 1; j < coo_matrix.row_ind.size(); j++)
        {
            if (coo_matrix.row_ind[i] > coo_matrix.row_ind[j] ||
                (coo_matrix.row_ind[i] == coo_matrix.row_ind[j] &&
                 coo_matrix.col_ind[i] > coo_matrix.col_ind[j]))
            {
                swap(coo_matrix.row_ind[i], coo_matrix.row_ind[j]);
                swap(coo_matrix.col_ind[i], coo_matrix.col_ind[j]);
                swap(coo_matrix.val[i], coo_matrix.val[j]);
            }
        }
    }
}
void sort_coo_matrix(coo_sparse_matrix &coo_matrix)
{
    sort_col_ind(coo_matrix);
    sort_row_ind(coo_matrix);
}
void parse_coo_matrix(coo_sparse_matrix &coo_matrix);
void print_coo_matrix(const coo_sparse_matrix &coo_matrix);
matrix convert_coo_matrix_to_matrix(const coo_sparse_matrix &coo_matrix);
void print_matrix(const matrix &matrix);

int main()
{
    coo_sparse_matrix coo_matrix_M;
    parse_coo_matrix(coo_matrix_M);
    sort_coo_matrix(coo_matrix_M);
    std::cout << "The COO matrix is:" << std::endl;
    print_coo_matrix(coo_matrix_M);
    matrix matrix_M = convert_coo_matrix_to_matrix(coo_matrix_M);
    std::cout << "The matrix is:" << std::endl;
    print_matrix(matrix_M);
    return 0;
}

void parse_coo_matrix(coo_sparse_matrix &coo_matrix)
{
    int n; // n lines of inputs

    // Exceptions: rows and col can't be nonpositive, n can't be negative
    for (int i = 0; i < 3; i++)
    {
        int temp;
        cin >> temp;
        if (i == 0 && temp > 0)
        {
            coo_matrix.rows = temp;
            continue;
        }
        if (i == 1 && temp > 0)
        {
            coo_matrix.cols = temp;
            continue;
        }
        if (i == 2 && temp >= 0)
        {
            n = temp;
            continue;
        }
        cout << "Invalid matrix." << endl;
        exit(0);
    }

    // Start of Parsing
    while (n--)
    {
        unsigned long r, c;
        long v;
        cin >> r >> c >> v;

        // Exceptions: Index Out of Range
        if (r < 0 ||
            r >= coo_matrix.rows ||
            c < 0 ||
            c >= coo_matrix.cols)
        {
            cout << "Invalid matrix." << endl;
            exit(0);
        }

        // Store COO
        bool flag = false;
        for (int i = 0; i < coo_matrix.row_ind.size(); i++)
        {
            // Rewrite val if already exist
            if (r == coo_matrix.row_ind[i] && c == coo_matrix.col_ind[i])
            {
                if (v == 0) // Erase if val = 0
                {
                    coo_matrix.row_ind.erase(coo_matrix.row_ind.begin() + i);
                    coo_matrix.col_ind.erase(coo_matrix.col_ind.begin() + i);
                    coo_matrix.val.erase(coo_matrix.val.begin() + i);
                }
                else // Rewrite if val != 0
                    coo_matrix.val[i] = v;

                flag = true;
                break;
            }
        }

        // Push_back if not exists yet
        if (!flag && v != 0)
        {
            coo_matrix.row_ind.push_back(r);
            coo_matrix.col_ind.push_back(c);
            coo_matrix.val.push_back(v);
        }
    }
    // End of Parsing

    // Sorting
    sort_coo_matrix(coo_matrix);
}

matrix convert_coo_matrix_to_matrix(const coo_sparse_matrix &coo_matrix)
{
    matrix mtrx;
    mtrx.rows = coo_matrix.rows;
    mtrx.cols = coo_matrix.cols;

    for (unsigned long i = 0; i < mtrx.rows; i++)
        mtrx.val.push_back(vector<long>(mtrx.cols, 0));

    for (int i = 0; i < coo_matrix.row_ind.size(); i++)
    {
        unsigned long r = coo_matrix.row_ind[i], c = coo_matrix.col_ind[i];
        long v = coo_matrix.val[i];
        mtrx.val[r][c] = v;
    }

    return mtrx;
}

void print_matrix(const matrix &matrix)
{
    for (unsigned long i = 0; i < matrix.rows; i++)
    {
        for (unsigned long j = 0; j < matrix.cols; j++)
        {
            cout << matrix.val[i][j] << ' ';
        }
        cout << endl;
    }
}

void print_coo_matrix(const coo_sparse_matrix &coo_matrix)
{
    cout << coo_matrix.rows << '\n'
         << coo_matrix.cols << endl;
    for (unsigned long i = 0; i < coo_matrix.row_ind.size(); i++)
    {
        cout << coo_matrix.row_ind[i]
             << " "
             << coo_matrix.col_ind[i]
             << " "
             << coo_matrix.val[i]
             << endl;
    }
}