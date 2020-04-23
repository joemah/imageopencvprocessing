// we are gonna filter images

#include <iostream>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <stdio.h>
#include <bits/stdtr1c++.h>
#include <vector>

// constants
int dellay = 5;
int max_kernel_size = 10;
double sigma  = 2;
int i  = 1;
// set the maxmum  kernel length

////////// FUNCTIONS TO PERFORM THE FILTERING PART ///////
/* HERE WE'RE GONNA AllOW You to Denoise your IMAGE USING OPENCV AND C++, WHATCH OUT! */

void usage(char **argv); // funtion prototypes declared here so  that the main function knows what they are when one envokes them!

int dist_delay(int delay);

std::vector<cv::Mat> v;

std::string windows[6] = {"MyImage", "MyFilter","MyFilte", "MyFilt", "MyFil", "MyFi" };

// the main function 
int main(int argc, char** argv)
{   
    usage(argv);

    if (argc != 2)
    {
        std::cout << "\n Error: You had too few parrameters.\n" << std::endl;
        return -1; // returns this if the program  encounters an error
    }

    cv::Mat image0;
    v.push_back(image0);
    cv::Mat gaussiann;
    v.push_back(gaussiann);
    cv::Mat gaussian;
    v.push_back(gaussian);
    cv::Mat gaussia;
    v.push_back(gaussia);
    cv::Mat gaussi;
    v.push_back(gaussi);
    cv::Mat gauss;
    v.push_back(gauss);
    
    v.front() = cv::imread( argv[1], cv::IMREAD_COLOR ); // display the file you  wanna filter 

    if (v.front().empty())
    {
        std::cout << "load again a new image the one you loaded is not an image" << std::endl;
        return -1; // returns this if the program  encounters an error
    }
    
    for (int i = 0; i < 6; i++)
    {
        for (std::size_t j = 0; j < v.size(); j++)
        {
           for (int k = 1; k < max_kernel_size; k+2)
           {
               if (k%2 != 0)
               {

                    GaussianBlur(v.front(),v[j], cv::Size(k, k), 0, 0);
                    if( dist_delay( dellay ) != 0 ) { return 0; } 
               }    
                     
           } 
            cv::namedWindow(windows[i]);
            cv::imshow(windows[i],  v[j]); 
            cv::waitKey(0);
        }
     }
    
    return 0;
}
void usage(char **argv) // This function instuct how the program runs
{
    std::cout << "This program removes noise from a given corrupt image\n"
            <<"To  load the image, navigate to  the path where your image is\n"
            << argv[0] << " <path/imgagename>\n\n"
            << "For example: ./"<< argv[0] << "../image.jpg" 
            <<std::endl;

}
int dist_delay(int delay )
{
    for (int i = 0; i < 6; i++)
    {
        cv::namedWindow(windows[i]);
        cv::imshow( windows[i], v[i] );
        int c = cv::waitKey ( delay );
        if( c >= 0 ) { return -1; }
        return 0;
    }
}
