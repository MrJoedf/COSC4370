#include <iostream>
#include "BMP.h"
#include <cmath>

using namespace std;
int main() {
  
    BMP bmpNew(1920,1920,false);
    bmpNew.fill_region(0, 0, 1920, 1920, 0, 0, 0, 0);
    //cout<<bmpNew.bmp_info_header.width<<std::endl;

    /*calculated standard form: (x^2/589824) (y^2/147456)=1
    Vertices: -768, 768 | -384, 384

    Formula for curvature of an ellipse is 
    f(x) = b (half of height) / a (half of width) multiplied by the square root of (a^2 + x^2)

    Width = 768*2 = 1536 | Height = 384* = 768
*/ 
    int b = 384, a = 768; //half of width and height

    /* Using the for loop to draw can only make one half of the ellipse at a time, unless two set_pixel functions are called.
    
    Within the for loop, make both halves of the ellipse by using two set_pixel calls.
    Canvas size (header_width) is 1920, so we iterate over half of the canvas size since we are working with halves of the ellipse.

    To get the desired rise and run for the curves of the ellipse halves:
    -- Subtracting i (iteration variable) from 960 simulates operations in the negative X coordinate on a graph (left of 0). 
    -- Adding i to 960 simulates operations to the right of 0 on a graph. Note that 960 will serve as 0 (the midpoint) of our simulated graph.
    */

    for(int i=0;i<960;i++){
       
       //create the left half of the ellipse
        bmpNew.set_pixel(960-i, (1.0*b/a)*(sqrt((a*a)-(i*i)))+960, 255, 255, 255, 0);
        //create right half of ellipse
        bmpNew.set_pixel(960+i, (1.0*b/a)*(sqrt((a*a)-(i*i)))+960, 255, 255, 255, 0);
    }
   
    bmpNew.write("output.bmp");

}
