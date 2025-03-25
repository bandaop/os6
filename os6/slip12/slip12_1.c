#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

#define ARRAY_SIZE 1000

int main(int argc, char **argv)
{
    int rank, size;
    int i, local_sum = 0, global_sum = 0;
    int arr[ARRAY_SIZE];

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    // Seed the random number generator differently on each process
    srand(42 + rank); // Ensure different seeds

    // Generate random numbers and compute local sum
    for (i = 0; i < ARRAY_SIZE; i++)
    {
        arr[i] = rand() % 100;
        local_sum += arr[i];
    }

    // Reduce local sums to a global sum
    MPI_Reduce(&local_sum, &global_sum, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

    if (rank == 0)
    {
        printf("Total sum of array elements across all processes = %d\n", global_sum);
    }

    MPI_Finalize();

    return 0;
}
