#include <iostream>
#define MAXSIZE 128
void Sort(int* arr[], int size) {
    int counter = 0;
    int temp = 0;
    for (int k = 0; k < 3; k++) // change '3' to the number of arrays passed to the function
    {
        for (int i = 0; i < size - 1; i++)
        {
            for (int j = 0; j < size - 1; j++)
            {
                if ( *(arr[k] + j) > *(arr[k]+j+1) ) {
                    counter++;
                    temp = *(arr[k] + j);
                    *(arr[k]+j) = *(arr[k]+j+1);
                    *(arr[k] + j + 1) = temp;
                }
            }
        }
        std::cout << std::endl;
        std::cout << "t" << k + 1 << " counter = " << counter << ";";
        counter = 0;
    }
    std::cout << std::endl;

    for(int i = 0; i < 3; i++)// change '3' to the number of arrays passed to the function
    {
        std::cout << "t" << i + 1 << ": ";
        for (int j = 0; j < MAXSIZE; j++)
        {
            if (*(arr[i] + j) != NULL)std::cout << *(arr[i] + j) << ' ';
        }
        std::cout << std::endl;
    }
    std::cout << "The best sorted array is the one with the lowest counter \nThe worst sorted array is the one with the highest counter";
}
int main()
{
    int t1[MAXSIZE] = { 111, 453, -1, 23, -2, 4 };
    int t2[MAXSIZE] = { 1, 2, 5, 132, 4, -2 };
    int t3[MAXSIZE] = {1, -354, 5, 354, 756, 1 };
    int* arr[] = { t1,t2,t3 };
    for (int i = 0; i < 3; i++)// change '3' to the number of arrays passed to the function
    { 
        std::cout << "t" << i + 1 << ": ";
        for (int j = 0; j < MAXSIZE; j++)
        {
            if (  *(arr[i]+j) != NULL)std::cout << *(arr[i] + j) << ' ';
        }
        std::cout << std::endl;
    }
    Sort(arr, 6); //change '6' to the number of elements in the arrays
    return 0;
}

