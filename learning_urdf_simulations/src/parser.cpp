#include <urdf/model.h>
#include "ros/ros.h"
#include <iostream>

int main(int argc, char **argv)
{
ros::init(argc, argv, "hello_parser");
if(argc!=2)
    {
        ROS_ERROR("Need a urdf file");
        return -1;
    }
    std::string urdf_file = argv[1];

    urdf::Model model;
    if(!model.initFile(urdf_file))
    {
        ROS_ERROR("Failed to parse urfd");
        return -1;
    }
    ROS_INFO("Successfully parsed urdf");
    return 0;
}
