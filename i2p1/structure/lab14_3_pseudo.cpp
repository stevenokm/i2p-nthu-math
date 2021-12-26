#include <iostream>
#include <vector>

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
    std::vector<std::vector<long> > val;
} matrix;

void sort_col_ind(coo_sparse_matrix &coo_matrix)
{
    for (i = 0; i < coo_matrix.col_ind.size(); i++)
    {
        for (j = i + 1; j < coo_matrix.col_ind.size(); j++)
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
    for (i = 0; i < coo_matrix.row_ind.size(); i++)
    {
        for (j = i + 1; j < coo_matrix.row_ind.size(); j++)
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
coo_sparse_matrix mult_coo_matrix(
    const coo_sparse_matrix &coo_matrix_M,
    const coo_sparse_matrix &coo_matrix_N);
matrix convert_coo_matrix_to_matrix(const coo_sparse_matrix &coo_matrix);
void print_matrix(const matrix &matrix);

int main()
{
    coo_sparse_matrix coo_matrix_M, coo_matrix_N, coo_matrix_P;
    std::cout << "Input COO matrix M:" << std::endl;
    parse_coo_matrix(coo_matrix_M);
    std::cout << "The COO matrix M is:" << std::endl;
    print_coo_matrix(coo_matrix_M);
    std::cout << "Input COO matrix N:" << std::endl;
    parse_coo_matrix(coo_matrix_N);
    std::cout << "The COO matrix N is:" << std::endl;
    print_coo_matrix(coo_matrix_N);
    coo_matrix_P = mult_coo_matrix(coo_matrix_M, coo_matrix_N);
    std::cout << "The COO matrix P = M * N is:" << std::endl;
    print_coo_matrix(coo_matrix_P);
    matrix matrix_P = convert_coo_matrix_to_matrix(coo_matrix_P);
    std::cout << "The matrix P is:" << std::endl;
    print_matrix(matrix_P);
    return 0;
}