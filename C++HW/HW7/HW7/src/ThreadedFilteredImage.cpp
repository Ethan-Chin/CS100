#include "ThreadedFilteredImage.hpp"
#include <vector>
#include <thread>

ThreadedFilteredImage::ThreadedFilteredImage(Image& img, int numberThreads) : FilteredImage(img), _numberThreads(numberThreads)
{
}

void ThreadedFilteredImage::applyKernel(Image& input, Image& output, Kernel& K)
{
    vector<thread> threadMass;
    int blockedCols = input.cols() / _numberThreads;
    output = Image::Zero(input.rows(), input.cols());
    for (int i = 0; i < _numberThreads; i++)
    {
        threadMass.push_back(thread(bind(&ThreadedFilteredImage::applyKernelThread, this, i * blockedCols, ref(input), ref(output), ref(K))));
    }
    for (int i = 0; i < _numberThreads; i++)
    {
        if (threadMass[i].joinable())
        {
            threadMass[i].join();
        }
    }
}

void ThreadedFilteredImage::applyKernelThread(int startingCol, Image& input, Image& output, Kernel& K)
{
    int w = (K.cols() - 1) / 2, h = (K.rows() - 1) / 2, x = input.rows(), y = input.cols();
	for (int i = h; i < x - h; i++)
	{
        for (int j = startingCol; j < startingCol + input.cols() / _numberThreads; j++)
		{
            if (j >= w && j < (y - w))
            {
                output(i, j) = (input.block(i - h, j - w, 2 * h + 1, 2 * w + 1) * K).sum();
            }
		}
	}
}