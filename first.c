#include <stdio.h>
#include <cuda_runtime.h>
bool InitCUDA()
{
    int count;
    cudaGetDeviceCount(&count);
    if(count == 0)
    {
        fprintf(stderr, "There is no device.\n");
        return false;
    }

    int i = 0;
    for (; i < count; ++i)
    {
        cudaDeviceProp prop;
        if(cudaGetDeviceProperties(&prop, i) == cudaSuccess)
        {
            if(prop.major >= 1)
            {
                printDevice(prop);
                break;
            }

        }
    }

    if(i == count){
        fprintf(stderr, "There is no device supporting CUDA.\n");
        return false;
    }
    cudaSetDevice(i);

    return true;
}

int main(int argc, char const *argv[])
{
    if(InitCUDA())
    {
        printf("CUDA initialized.\n");
    }
    return 0;
}