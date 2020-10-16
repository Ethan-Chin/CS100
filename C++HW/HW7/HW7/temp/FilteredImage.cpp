
#include "FilteredImage.hpp"
#include "image_io.hpp"
#include <iostream>
#include <math.h>

FilteredImage::FilteredImage( Image & img ):_img(img){
  //////////////////////////// YOUR CODE HERE ////////////////////////////////
}

Image &
FilteredImage::get( int type ) {
  if(this->_filteredImages.count(type)!=0){ 
    return *_filteredImages[type];
  }

  switch( type ) {
    case BLUR: {
      Kernel K_blur(5,5);
K_blur << (2.0f/159.0f), ( 4.0f/159.0f), ( 5.0f/159.0f), (
4.0f/159.0f), (2.0f/159.0f),
 (4.0f/159.0f), ( 9.0f/159.0f), (12.0f/159.0f), (
9.0f/159.0f), (4.0f/159.0f),
 (5.0f/159.0f), (12.0f/159.0f), (15.0f/159.0f),
(12.0f/159.0f), (5.0f/159.0f),
 (4.0f/159.0f), ( 9.0f/159.0f), (12.0f/159.0f), (
9.0f/159.0f), (4.0f/159.0f),
 (2.0f/159.0f), ( 4.0f/159.0f), ( 5.0f/159.0f), (
4.0f/159.0f), (2.0f/159.0f);
  Image *outImg=new Image(_img.rows(),_img.cols());
    applyKernel(_img, *outImg, K_blur);
    _filteredImages[type]=std::shared_ptr<Image>(outImg);
      ////////////////////////// YOUR CODE HERE ////////////////////////////////
      return *outImg/* Your result */;
    }
    case DER_X: {
      
  Kernel K_der_x(3,3);
      K_der_x << -1.0f, 0.0f, 1.0f,
      -2.0f, 0.0f, 2.0f,
      -1.0f, 0.0f, 1.0f;
      Image *outImg=new Image(_img.rows(),_img.cols());
      applyKernel(_img, *outImg,K_der_x);
      _filteredImages[type]=std::shared_ptr<Image>(outImg);
      ////////////////////////// YOUR CODE HERE ////////////////////////////////
      return *outImg/* Your result */;
    }
    case DER_Y: {
      Kernel K_der_y(3,3);
      K_der_y << -1.0f, -2.0f, -1.0f,
      0.0f, 0.0f, 0.0f,
      1.0f, 2.0f, 1.0f;
      Image *outImg=new Image(_img.rows(),_img.cols());
      applyKernel(_img, *outImg, K_der_y);
      _filteredImages[type]=std::shared_ptr<Image>(outImg);
      ////////////////////////// YOUR CODE HERE ////////////////////////////////
      return *outImg/* Your result */;
    }
    case DER_MAG: {    
      Kernel K_der_x(3,3);
      K_der_x << -1.0f, 0.0f, 1.0f,
      -2.0f, 0.0f, 2.0f,
      -1.0f, 0.0f, 1.0f;
      Kernel K_der_y(3,3);
      K_der_y << -1.0f, -2.0f, -1.0f,
      0.0f, 0.0f, 0.0f,
      1.0f, 2.0f, 1.0f;
      Image dxRes(_img.rows(),_img.cols());
      applyKernel( _img, dxRes, K_der_x );
      Image dyRes(_img.rows(),_img.cols());
      applyKernel( _img, dyRes, K_der_y );
        Image *outImg=new Image(_img.rows(),_img.cols());
      *outImg=sqrt(dxRes*dxRes+dyRes*dyRes);
      _filteredImages[type]=std::shared_ptr<Image>(outImg);
      ////////////////////////// YOUR CODE HERE ////////////////////////////////
      return *outImg/* Your result */;
    }
    default: {
      std::cout << "Error: unrecognized kernel option\n";
    }
  }
  return _img;
}

void FilteredImage::applyKernel( Image & input, Image & output, Kernel & K ) {
  int r1=K.rows();
  int r2=input.rows();
  int c1=K.cols();
  int c2=input.cols();
  int r3=r1+r2-1;
  int c3=c1+c2-1;
  for(int i=0;i<r2-(r1-1);i++){
    for(int j=0;j<c2-(c1-1);j++){
      output(i+(r1-1)/2,j+(c1-1)/2)=(input.block(i,j,r1,c1)*K).sum();
    }
  } 
  /////////std::cout<<m1;////std::cout<<m;///////////// YOUR CODE HERE ////////////////////////////////
}

