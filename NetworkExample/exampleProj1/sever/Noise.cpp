#include "Noise.h"


Noise::Noise(int s){
    seed = s;
    size = 512;
    p = 0.5;
    n = 64;
}

int Noise::imageSize(){
    return size*size*3+18;
}


//Create a noise image...
unsigned char* Noise::createImage(float z){
    
    //horrible code to generate .tga header info
    unsigned char* data = new unsigned char[size*size*3+18];
    
    unsigned char* ptr = &data[0];

    for(int i =0; i < 18; ++i)
        ptr[i] = 0;
    ptr[2] = 2;
    ptr[16] = 24;
    
    ptr[12] = ptr[14] = (unsigned char)(size & 0X000000FF);
    ptr[13] = ptr[15] = (unsigned char)((size >> 8) & 0X000000FF);

    ptr = &data[18];
    
    
    // main loop -- /64 allows the image to be a bit more smooth
    for(int j = 0; j < size; j++){
        float y = (float)j/64;
        for(int i = 0; i < size; i++){
            float x = (float)i/64;
            //find noise at point x,y and z
            float n = octaves(x,y,z);
            
            n = n/2.0 + 0.5;
            
            unsigned char g = (unsigned char)(n*255);
            ptr[0] = ptr[1] = ptr[2] = g;
            ptr += 3;
        }
    }
    return data;
}

//http://freespace.virgin.net/hugo.elias/models/m_perlin.htm
float Noise::cosineInterpolate(float a,float b, float w){
    float f = (1-cos(w*3.14159265))/2;
    return  a*(1-f) + b*f;
}

//http://burtleburtle.net/bob/hash/integer.html 4 byte hash function
int Noise::hash32( unsigned int a)
{
    a = (a+0x7ed55d16) + (a<<12);
    a = (a^0xc761c23c) ^ (a>>19);
    a = (a+0x165667b1) + (a<<5);
    a = (a+0xd3a2646c) ^ (a<<9);
    a = (a+0xfd7046c5) + (a<<3);
    a = (a^0xb55a4f09) ^ (a>>16);
    return a;
}


//convert 3 ints into a "random" number 3 levels of hashing plus the seed as an offset
//make a float as a
float Noise::noise(int x, int y,int z){
    return  (float)(hash32(seed+(z + hash32(hash32(x + hash32(y))))))/(float)RAND_MAX;
}

//http://mrl.nyu.edu/~perlin/noise/
//and
//http://freespace.virgin.net/hugo.elias/models/m_perlin.htm

float Noise::interpolateNoise(float x,float y,float z){
    
    int X = int(x);
    int Y = int(y);
    int Z = int(z);
    
    
    float y1 = cosineInterpolate(noise(X,Y,  Z),noise(X+1,Y,  Z),x-X);
    float y2 = cosineInterpolate(noise(X,Y+1,Z),noise(X+1,Y+1,Z),x-X);

    float y3 = cosineInterpolate(noise(X,Y,  Z+1),noise(X+1,Y,  Z+1),x-X);
    float y4 = cosineInterpolate(noise(X,Y+1,Z+1),noise(X+1,Y+1,Z+1),x-X);

    float z5 = cosineInterpolate(y1,y2,y-Y);
    float z6 = cosineInterpolate(y3,y4,y-Y);

    return cosineInterpolate(z5,z6,z-Z);
}


//http://freespace.virgin.net/hugo.elias/models/m_perlin.htm
//Generate octaves of noise
//we use the same noise function for each level just chainging the frequency
// returns a floating point value between -1 and -1
float Noise::octaves(float x, float y,float z) {
    
    float value = 0;
    
    float frequency = 1;
    float amplitude = 1;
    
    float max = 0;
    
    for(int i =0 ; i< n; i++){
        value += interpolateNoise(frequency*x, frequency*y, frequency*z) * amplitude;
        max += amplitude;
        frequency *= 2;
        amplitude *= p;
    }
    return value/max;
}

