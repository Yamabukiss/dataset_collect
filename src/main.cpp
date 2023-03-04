#include "ros/ros.h"
#include "cv_bridge/cv_bridge.h"
#include "opencv2/opencv.hpp"

std::string g_code = "yamabukiss"; // you can write any words you want but be sure different to others
std::string g_path = "/home/yamabuki/detect_ws/src/dataset_collect/dataset/"; // the path you want to save the image to
int g_num = 1;

void receiveFromCam(const sensor_msgs::ImageConstPtr& image_ptr)
{
    auto img=boost::make_shared<cv_bridge::CvImage>(*cv_bridge::toCvShare(image_ptr, image_ptr->encoding));
    cv::imwrite(g_path+g_code+"_"+std::to_string(g_num)+".jpg",img->image);
    std::cout<<g_code+"_"+std::to_string(g_num)+".jpg"+" saved"<<std::endl;
    cv::waitKey(250);// ms
    g_num++;
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "dataset_collect_node");
    ros::NodeHandle nh;
    auto subscriber= nh.subscribe("/hk_camera/image_raw", 1, &receiveFromCam);

    while (ros::ok())
    {
        ros::spinOnce();
    }

}
