#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000

// Function to generate random numbers in an array
void generate_random_numbers(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 1000; // Random number between 0 and 999
    }
}

// Function to calculate sum of odd numbers
int sum_of_odds(int *arr, int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] % 2 != 0)
        {
            sum += arr[i];
        }
    }
    return sum;
}

int main(int argc, char *argv[])
{
    int rank, size;
    int numbers[SIZE];
    int local_sum = 0, total_sum = 0;
    int chunk_size;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    chunk_size = SIZE / size; // Divide array among processes
    int *sub_array = (int *)malloc(chunk_size * sizeof(int));

    if (rank == 0)
    {
        srand(time(NULL));
        generate_random_numbers(numbers, SIZE);
        printf("Generated numbers: ");
        for (int i = 0; i < SIZE; i++)
        {
            printf("%d ", numbers[i]);
        }
        printf("\n");
    }

    // Distribute parts of the array to all processes
    MPI_Scatter(numbers, chunk_size, MPI_INT, sub_array, chunk_size, MPI_INT, 0, MPI_COMM_WORLD);

    // Each process calculates the sum of its odd numbers
    local_sum = sum_of_odds(sub_array, chunk_size);

    // Reduce local sums into total_sum at the root process
    MPI_Reduce(&local_sum, &total_sum, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

    if (rank == 0)
    {
        printf("Total sum of odd numbers: %d\n", total_sum);
    }

    free(sub_array);
    MPI_Finalize();
    return 0;
}
