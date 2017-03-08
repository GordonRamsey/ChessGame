#include "Noise.h"
#include <cstdio>

int main(){
    //create a noise object with seed 915
	Noise perlin(915);
    
    //will create a noise image of the default size at z=0
    //your server should upate the value sent to create Image
    //img is a pointer to a byte array which is a full featured .tga file
    unsigned char* img = perlin.createImage(0);
    
    //get the total size of the image including .tga header infor
    int size = perlin.imageSize();
    
    //open a file and just dump out the bytes
    FILE* outFile = fopen("loud.tga","wb");
	fwrite(img,1,size,outFile);
	fclose(outFile);
    
    //should delete img
    return 0;
}
