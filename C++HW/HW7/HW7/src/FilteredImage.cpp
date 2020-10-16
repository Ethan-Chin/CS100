#include "FilteredImage.hpp"
#include <iostream>


FilteredImage::FilteredImage(Image& img) : _img(img)
{
}

Image& FilteredImage::get(int type)
{
	std::map<int, std::shared_ptr<Image>>::iterator it;
	it = _filteredImages.find(type);
	if (it != _filteredImages.end())
	{
		return *(it -> second);
	}
    switch(type)
    {
        case BLUR:
        {
			std::shared_ptr<Image> output_b = std::make_shared<Image>(_img.rows(), _img.cols());
            Kernel K_blur(5, 5);
			K_blur<<(2.0f/159.0f), ( 4.0f/159.0f), ( 5.0f/159.0f), ( 4.0f/159.0f), (2.0f/159.0f),
					(4.0f/159.0f), ( 9.0f/159.0f), (12.0f/159.0f), ( 9.0f/159.0f), (4.0f/159.0f),
					(5.0f/159.0f), (12.0f/159.0f), (15.0f/159.0f), (12.0f/159.0f), (5.0f/159.0f),
					(4.0f/159.0f), ( 9.0f/159.0f), (12.0f/159.0f), ( 9.0f/159.0f), (4.0f/159.0f),
					(2.0f/159.0f), ( 4.0f/159.0f), ( 5.0f/159.0f), ( 4.0f/159.0f), (2.0f/159.0f);
			applyKernel(_img, *output_b, K_blur);
			_filteredImages[BLUR] = output_b;
            return *output_b;
        }
        case DER_X:
        {
			std::shared_ptr<Image> output_x = std::make_shared<Image>(_img.rows(), _img.cols());
			Kernel K_der_x(3, 3);
			K_der_x<<-1.0f, 0.0f, 1.0f,
					-2.0f, 0.0f, 2.0f,
					-1.0f, 0.0f, 1.0f;
			applyKernel(_img, *output_x, K_der_x);
			_filteredImages[DER_X] = output_x;
            return *output_x;
        }
        case DER_Y:
        {
        	std::shared_ptr<Image> output_y = std::make_shared<Image>(_img.rows(), _img.cols());
			Kernel K_der_y(3, 3);
			K_der_y<<-1.0f, -2.0f, -1.0f,
					0.0f,  0.0f,  0.0f,
					1.0f,  2.0f,  1.0f; 
			applyKernel(_img, *output_y, K_der_y);
			_filteredImages[DER_Y] = output_y;
            return *output_y;
        }
        case DER_MAG:
        {
			std::shared_ptr<Image> output_m = std::make_shared<Image>(_img.rows(), _img.cols());
			Image dxRes = this->get(DER_X), dyRes = this->get(DER_Y);
			for (int i = 0; i < _img.rows(); i++)
			{
				for (int j = 0; j < _img.cols(); j++)
				{
					(*output_m)(i, j) = sqrt(pow(dxRes(i, j), 2) + pow(dyRes(i, j), 2));
				}
			}
			_filteredImages[DER_MAG] = output_m;
            return *output_m;
        }
        default:
        {
            std::cout << "Error: unrecognized kernel option\n";
        }
    }
    return _img;
}

void FilteredImage::applyKernel(Image& input, Image& output, Kernel& K)
{
	int w = (K.cols() - 1) / 2, h = (K.rows() - 1) / 2, x = input.rows(), y = input.cols();
    output = Image::Zero(x, y);
	for (int i = h; i < x - h; i++)
	{
		for (int j = w; j < y - w; j++)
		{
            output(i, j) = (input.block(i - h, j - w, 2 * h + 1, 2 * w + 1) * K).sum();
		}
	}
}