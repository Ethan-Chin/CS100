
#include "ThreadedFilteredImage.hpp"
#include <vector>
#include <thread>

ThreadedFilteredImage::ThreadedFilteredImage( Image & img, int numberThreads ):FilteredImage(img){
  _numberThreads=numberThreads;
  ////////////////////////// YOUR CODE HERE ////////////////////////////////
}
 
void
ThreadedFilteredImage::applyKernel( Image & input, Image & output, Kernel & K ) {	
  int r2=input.rows();
  int c2=input.cols(); 
  std::vector<std::thread> t; 
  output=Image::Zero(r2,c2);
  for(int i=0;i<_numberThreads;i++){
    t.push_back(std::thread(&ThreadedFilteredImage::applyKernelThread,this,i*c2/_numberThreads,std::ref(input),std::ref(output),std::ref(K)));
  }
  for(int i=0;i<_numberThreads;i++){
	if(t[i].joinable()){
		t[i].join();
	}
} 
}

 void
ThreadedFilteredImage::applyKernelThread( int startingCol, Image & input, Image & output, Kernel & K ) {
  int r1=K.rows();
  int r2=input.rows();
  int c1=K.cols();
  int c2=input.cols();
  int c=startingCol+c2/_numberThreads; 
  if(startingCol!=0)startingCol-=(c1-1)/2;
  if(c!=c2){
  for(int i=0;i<r2-(r1-1);i++){
  	for(int j=startingCol;j<c;j++){
  		output(i+(r1-1)/2,j+(c1-1)/2)=(input.block(i,j,r1,c1)*K).sum();
	}
  }
  }else{
  	for(int i=0;i<r2-(r1-1);i++){
  	for(int j=startingCol;j<c-(c1-1)/2;j++){
  		output(i+(r1-1)/2,j+(c1-1)/2)=(input.block(i,j,r1,c1)*K).sum();
	}
  }
  	
  }
}

