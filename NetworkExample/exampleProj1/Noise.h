#ifndef NOISE__H
#define NOISE__H

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>

using namespace std;

class Noise{
	public:
		Noise(int s);
        unsigned char* createImage(float z);
    int imageSize();
private:
		int hash32(unsigned int a);
		float noise(int x,int y,int z);
    float cosineInterpolate(float a,float b, float w);
		float interpolateNoise(float x,float y,float z);
		float octaves(float x,float y,float z);
		int seed;
        int size;
		int n;
		float p;
};


#endif
