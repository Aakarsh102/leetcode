#include <cuda_runtime.h>

// Note: A, B, C are device pointers

__global__ void solution_kernel(const float* A, const float* B, float* C, size_t N, size_t K) {
    int i = blockDim.x * blockIdx.x + threadIdx.x;
    int n = (K - 1) / 2;

    if (i < N) {
        // float sum = 0.0f;
        C[i] = 0.0f;
        for (int j = -n; j <= n; j++) {
            if (0 <= i + j && i + j < N) {
                C[i] += B[j + n] * A[i + j];
            }
        }
        // C[i] = sum;
    }
}
extern "C" void solution(const float* A, const float* B, float* C, size_t N, size_t K) {
    int threadsPerBlock = 256;
    int numBlocks = (N + threadsPerBlock + 1) / threadsPerBlock;
    dim3 grid(numBlocks);
    solution_kernel<<<grid, threadsPerBlock>>>(A, B, C, N, K);
}