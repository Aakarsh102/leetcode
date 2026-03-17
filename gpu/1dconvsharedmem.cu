#include <cuda_runtime.h>

// Note: A, B, C are device pointers

__global__ void solution_kernel(const float* A, const float* B, float* C, size_t N, size_t K) {
    size_t i = blockDim.x * blockIdx.x + threadIdx.x;
    
    // Using your exact r formula
    int r = (K - 1) / 2; 
    extern __shared__ float sharedArr[];
    

    for (int j = threadIdx.x; j < blockDim.x + K - 1; j += blockDim.x) {

        long long global_idx = (long long)(blockDim.x * blockIdx.x) - r + j;
        
        if (global_idx >= 0 && global_idx < N) {
            sharedArr[j] = A[global_idx];
        } else {
            sharedArr[j] = 0.0f; // Zero padding for out-of-bounds
        }
    }
    
    __syncthreads();


    if (i < N) {
        float sum = 0.0f;
        for (int j = 0; j < K; j++) {
            sum += B[j] * sharedArr[threadIdx.x + j];
        }
        C[i] = sum;
    }
}
extern "C" void solution(const float* A, const float* B, float* C, size_t N, size_t K) {
    int threadsPerBlock = 256;
    int numBlocks = (N + threadsPerBlock - 1) / threadsPerBlock;
    dim3 grid(numBlocks);
    size_t sharedMem = (threadsPerBlock + 2 * ((K - 1)/2)) * sizeof(float); 
    solution_kernel<<<grid, threadsPerBlock, sharedMem>>>(A, B, C, N, K);
}