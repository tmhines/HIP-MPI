#include <iostream>
#include <hip/hip_runtime.h>
#include <mpi.h>

__global__ void hi()
{
	printf("Hello from the GPU\n");
}

int main()
{
	MPI_Init(nullptr, nullptr);
	
	int rank,size;
	
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	
	std::cout << "Hello from the CPU on " << rank << " of " << size << std::endl;
	
	hi<<<1,8>>>();
	hipDeviceSynchronize();
	
	MPI_Finalize();
}
