#include <iostream>
#include "BMP.h"
#include <cmath>
using namespace std;

int main() {
  
    BMP bmpNew(1536,1536,false);
    bmpNew.fill_region(0, 0, 1536, 1536, 0, 0, 0, 0);
    //cout<<bmpNew.bmp_info_header.width<<std::endl;

    /*Calculated standard form: (x^2/589824) (y^2/147456)=1
    Vertices: -768, 768 | -384, 384

    Formula for curvature of an ellipse is 
    f(x) = b (half of height) / a (half of width) multiplied by the square root of (a^2 + x^2)

    Width = 768*2 = 1536 | Height = 384* = 768
*/ 
    int b = 384, a = 768; //half of width and height

    /* Using the for loop to draw can only make one half of the ellipse at a time, unless two set_pixel functions are called.
    
    Within the for loop, make both halves of the ellipse by using two set_pixel calls.
    Canvas size (header_width) is 1536, so we iterate over half of the canvas size since we are working with halves of the ellipse.

    To achieve the desired rise and run for the curves of the ellipse halves, subtracting i (iteration variable) from 768 simulates operations in the negative X coordinate on a graph (left of 0). Adding i to 768 simulates operations to the right of 0 on a graph. Note that 768 will serve as 0 (the midpoint) of our simulated graph.
    */


    /*Store x-y pairs to track gaps. since the set_pixel function uses integers instead of doubles, many values are approximated and rounded, so there is some inaccuracy that leads to gaps.
    */
    vector<int> arr(768,0); 

    for(int i=0;i<768;i++){
       //Create the left half of the ellipse
        bmpNew.set_pixel(768-i, (1.0*b/a)*(sqrt((a*a)-(i*i)))+768, 255, 255, 255, 0);
       
       //store the x-y pair
       arr[i]= (int((1.0*b/a)*(sqrt((a*a)-(i*i)))+768));

       cout<<"X: "<<arr[i]<<" | "<<(768-i)<<endl;;
        //Create right half of ellipse
        bmpNew.set_pixel(768+i, (1.0*b/a)*(sqrt((a*a)-(i*i)))+768, 255, 255, 255, 0);
    }

//Now a final for loop to fill gaps within the arc, using the value pairs stored earlier
    for(int m=0; m<768; m++){
      if(arr[m-1]-arr[m]>1){
      for(int i=arr[m]; i<arr[m-1]; i++){
          bmpNew.set_pixel(768-m, i, 255, 255, 255, 0);
          bmpNew.set_pixel(768+m, i, 255, 255, 255, 0);
        }
        }
      }
    
   
    bmpNew.write("output.bmp");

}
