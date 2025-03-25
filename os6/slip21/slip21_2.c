#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000

int main(int argc, char *argv[])
{
    int rank, size;
    int numbers[SIZE], local_sum = 0, total_sum = 0;
    int chunk_size;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    chunk_size = SIZE / size; // Each process handles an equal portion

    int *sub_array = (int *)malloc(chunk_size * sizeof(int));

    if (rank == 0)
    {
        srand(time(NULL));
        for (int i = 0; i < SIZE; i++)
        {
            numbers[i] = rand() % 1000; // Generate random numbers (0-999)
        }
        printf("Generated numbers: \n");
        for (int i = 0; i < SIZE; i++)
        {
            printf("%d ", numbers[i]);
        }
        printf("\n");
    }

    // Scatter data to all processes
    MPI_Scatter(numbers, chunk_size, MPI_INT, sub_array, chunk_size, MPI_INT, 0, MPI_COMM_WORLD);

    // Calculate local sum of even numbers
    for (int i = 0; i < chunk_size; i++)
    {
        if (sub_array[i] % 2 == 0)
        {
            local_sum += sub_array[i];
        }
    }

    // Reduce to get the total sum at root process
    MPI_Reduce(&local_sum, &total_sum, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

    if (rank == 0)
    {
        printf("Total sum of even numbers: %d\n", total_sum);
    }

    free(sub_array);
    MPI_Finalize();
    return 0;
}
