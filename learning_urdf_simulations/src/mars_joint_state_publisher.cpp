/*
	*
	* Project Name: Medical Assistive Robotic System
	* Author List: 	Pankaj Patil
	* Filename: 	mars_joint_state_publisher.cpp
	* Functions: 	<Comma separated list of Functions defined in this file>
	* Global Variables:	<List of all the global variables defined in this file, None if no global 
	*			variables>
	*
*/

#include <iostream>
#include <ros/ros.h>
//Include joint state publisher sensor message to publish joint state publisher
#include <sensor_msgs/JointState.h>
// 
 int main(int argc, char** argv)
 {
     ros::init(argc,argv,"mars_joint_state_publisher");

     //instantiate ros node handler
     ros::NodeHandle joint_pub_nh;

     //Publisher variable-
     ros::Publisher joint_st_pub = joint_pub_nh.advertise<sensor_msgs::JointState>("/joint_states",115200);
     //Baud rate of the entire system must be 115200

     //Loop rate for this node:
     ros::Rate loop_rate(115200);

     //Object declarations for messages used:
     sensor_msgs::JointState joint_state_publisher;

     //.resize(n) 'n' tells us the no of joints from the urdf.
     joint_state_publisher.name.resize(15);
     joint_state_publisher.position.resize(15);


     //Specifying joint names-
     joint_state_publisher.name[0]="base_link_to_wheel1";
     joint_state_publisher.name[1]="base_link_to_wheel2";
     joint_state_publisher.name[2]="base_link_to_wheel3";
     joint_state_publisher.name[3]="base_link_to_wheel4";
     joint_state_publisher.name[4]="manipulator_to_base_link";
     joint_state_publisher.name[5]="base_cylinder_to_link2";
     joint_state_publisher.name[6]="link_2_to_link_3";
     joint_state_publisher.name[7]="link_3_to_link_4";
     joint_state_publisher.name[8]="link_4_to_gripper_base";
     joint_state_publisher.name[9]="gripper_base_to_finger_base1";
     joint_state_publisher.name[10]="finger_base1_to_finger_top1";
     joint_state_publisher.name[11]="gripper_base_to_finger_base2";
     joint_state_publisher.name[12]="finger_base2_to_finger_top2";
     joint_state_publisher.name[13]="gripper_base_to_finger_base3";
     joint_state_publisher.name[14]="finger_base3_to_finger_top3";
     while(ros::ok())
     {   
         
         //Time stamp for synchronization of joint states published.
         joint_state_publisher.header.stamp = ros::Time::now();
         
         //Update joint angles-
         joint_state_publisher.position[0]=0;
         joint_state_publisher.position[1]=0;
         joint_state_publisher.position[2]=0;
         joint_state_publisher.position[3]=0;
         joint_state_publisher.position[4]=0;
         joint_state_publisher.position[5]=1.2;
         joint_state_publisher.position[6]=0;
         joint_state_publisher.position[7]=0;
         joint_state_publisher.position[8]=0;
         joint_state_publisher.position[9]=0;
         joint_state_publisher.position[10]=0;
         joint_state_publisher.position[11]=0;
         joint_state_publisher.position[12]=0;
         joint_state_publisher.position[13]=0;
         joint_state_publisher.position[14]=0;

         //Publishing joint states-
         joint_st_pub.publish(joint_state_publisher);

         loop_rate.sleep();

     } 
     return 0;
 }