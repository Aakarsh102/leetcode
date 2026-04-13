#include <cuda_runtime.h>

// Note: input, output are device pointers
__global__ void sol(const float* __restrict__ input, float* output, size_t n, size_t m) {
    int idx = blockDim.x * blockIdx.x + threadIdx.x;

    if (idx < n * m) {
        output [idx] = 1 / (1 + exp(-input[idx]));
    }

}
extern "C" void solution(const float* input, float* output, size_t n, size_t m) {
    dim3 block(256);
    dim3 grid((n * m + 255) / 256 );
    sol<<<grid, block>>>(input, output, n, m);
}

