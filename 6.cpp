#include "perceptron.hpp"
#include <png++/png.hpp>

using namespace std;

int main(int argc, char *argv[])
{
    if(argc!=2)
    {
        cout<<"Így használd: ./perc bemenet.png"<<endl;
        return -1;
    }
    png::image<png::rgb_pixel> png_img(argv[1]);
    int s = png_img.get_width()*png_img.get_height();

    Perceptron* p = new Perceptron(3,s,256,1);

    double* image = new double[s];

    for(int i=0;i<png_img.get_width();i++)
    {
        for(int j=0;j<png_img.get_height();j++)
        {
            image[i*png_img.get_width()+j]=png_img[j][i].red;
        }
    }

    double val = (*p)(image);
    cout<<val<<endl;
    delete [] image;
    delete p;
    return 0;
}       