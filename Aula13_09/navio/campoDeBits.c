#include <stdio.h>

typedef struct{
    unsigned int red  ;
    unsigned int green;
    unsigned int blue ;
}RGB;

//economia de memoria
typedef struct{
    int red     : 10;
    int green   : 10;
    int blue    : 10;
}RGBbf;

int main(int argc, char const * argv[]){
    RGB mRGB;
    RGBbf bfRGB;

    mRGB.red = 0;
    mRGB.green = 0;
    mRGB.blue = 0;

    bfRGB.red = 0;
    bfRGB.green = 0;
    bfRGB.blue = 0;

    for (int i = 0; i < 100; i++)
    {
        
        mRGB.red    += 100;
        mRGB.green  += 100;
        mRGB.blue   += 100;

        bfRGB.red   += 100;
        bfRGB.green += 100;
        bfRGB.blue  += 100;

        printf("cor (r (%d), g (%d), b (%d))\n", mRGB.red, mRGB.green, mRGB.blue);
        printf("cor bf (r (%d), g (%d), b (%d))\n", bfRGB.red, bfRGB.green, bfRGB.blue);
        
    }
    printf("cor - sof(%d)\n", sizeof(mRGB));
    printf("cor bf - sof(%d)\n", sizeof(bfRGB));
    

}