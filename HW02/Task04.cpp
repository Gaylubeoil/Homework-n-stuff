#include <iostream>
void InputMatrix(int** matrix, int size) {
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++) {
            std::cout << "Enter matrix [" << i << "][" << j << "]: ";
            std::cin >> matrix[i][j];
        }
    }
}
void DisplayMatrix(int** matrix, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            std::cout << matrix[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}
bool Evaluate(int** matrix, int size) {
    int up = 0, right=0, down=0, left=0;
    int up_ins = 0, left_ins = 0, down_ins = 0, right_ins = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (i == 0 && (j >= 1 && j < size - 1))
            {
                up += matrix[i][j];
            }
            if (i ==size - 1 && (j >=1 && j < size-1))
            {
                down += matrix[i][j];
            }
            if (j == size - 1 && i >= 1 && i < size - 1)
            {
                right += matrix[i][j];
            }
            if (j ==0 && i >= 1 && i < size-1 )
            {
                left += matrix[i][j];
            }

            if (i == 1 && j >= 2 && j < size - 2) up_ins += matrix[i][j];

            if (i == size - 2 && j >= 2 && j < size - 2) down_ins += matrix[i][j];

            if (j == 1 && i >= 2 && i < size - 2) left_ins += matrix[i][j];

            if (j == size - 2 && i >= 2 && i < size - 2) right_ins += matrix[i][j];
        }
    }
    if ((up == right && right == down && down == left) && (up_ins == right_ins && right_ins == down_ins && down_ins == left_ins))
    {
        return 1;
    }
    else return 0;
    
}

int main()
{
    int size;
    std::cin >> size;
    while (size < 3)
    {
        std::cout << "Size must be greater or equal to 3! \nInput size: ";
        std::cin >> size;
    }
    int** matrix = new int* [size];
    for (int i = 0; i < size; ++i)
        matrix[i] = new int[size];
    InputMatrix(matrix, size);
    DisplayMatrix(matrix, size);
    std::cout << Evaluate(matrix, size);


    for (int i = 0; i < size; ++i)
        delete[] matrix[i];
    delete[] matrix;
    matrix = nullptr;
    return 0;
}
