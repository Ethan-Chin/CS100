#include "image_io.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;


Image loadImage(const std::string& pathToRaw)
{
    ifstream input(pathToRaw);
    int row, col;
    input>>row>>col;
    Image outImage(row, col);
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            float temp;
            input>>temp;
            temp = temp / 255.0f;
            outImage(i, j) = temp;
        } 
    }
    input.close();
    return outImage;
}

void saveImage(Image& img, const std::string& pathToRaw)
{
    ofstream output(pathToRaw); 
    for (int i = 0; i < img.rows(); i++)
    {
        for (int j = 0; j < img.cols(); j++)
        {
            float n;
            n = img(i, j);
            output<<n;
            if (j == img.cols() - 1)
            {
                if (i != img.rows() - 1)
                {
                    output<<"\n";
                }
                break;
            }
            output<<' ';
        }
    }
    output.close();
}