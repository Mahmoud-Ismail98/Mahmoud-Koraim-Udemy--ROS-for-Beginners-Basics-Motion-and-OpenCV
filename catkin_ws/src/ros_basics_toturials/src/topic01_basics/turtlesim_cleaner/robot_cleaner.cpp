#include "ros/ros.h"
#include "geometry_msgs/Twist.h"

#include <sstream>
using namespace std;

ros::Publisher velocity_publisher;

void move(double speed,double distance,bool isforward);
int main(int argc, char **argv)
{
    ros::init(argc,argv,"turtlesim_cleaner");
    ros::NodeHandle node;
    double speed,distance;
    bool isforward;

    velocity_publisher = node.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel",100);
	cout<<"enter speed: ";
	cin>>speed;
	cout<<"enter distance: ";
	cin>>distance;
	cout<<"forward?: ";
	cin>>isforward;
	move(speed, distance, isforward);

}    



void move(double speed,double distance,bool isforward)
{
    geometry_msgs::Twist vel_msg;
    if (isforward)
        vel_msg.linear.x=abs(speed);
    else
        vel_msg.linear.x=-abs(speed);
        
    vel_msg.linear.y=0;
    vel_msg.linear.z=0;    
    vel_msg.angular.x=0;
    vel_msg.angular.y=0;
    vel_msg.angular.z=0;

    double t0=ros::Time::now().toSec();
    double current_distance = 0;
    ros::Rate loop_rate(100);
    do{
        velocity_publisher.publish(vel_msg);
        double t1 =ros::Time::now().toSec();
        current_distance=speed*(t1-t0);
        ros::spinOnce();
        loop_rate.sleep();

    } while (current_distance<distance);
    vel_msg.linear.x=0;
    velocity_publisher.publish(vel_msg);
    

}
