#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include "turtlesim/Pose.h"
#include <sstream>
using namespace std;

ros::Publisher velocity_publisher;
ros::Subscriber pose_subscriber;
turtlesim::Pose turtlesim_pose;
const double PI = 3.14;
void move(double speed,double distance,bool isforward);
void rotate (double angular_speed , double relative_angle,bool clockwise);
double degrees2radians(double angle_in_degrees);
double setDesiredOrientaion(double desired_angle_radian);
void poseCallback(const turtlesim::Pose::ConstPtr & pose_message){
    
    turtlesim_pose.x =pose_message->x;
    turtlesim_pose.y =pose_message->y;
    turtlesim_pose.theta =pose_message->theta;

}
double getDistance(double x1, double y1, double x2, double y2);
void movetoGoal(turtlesim::Pose goal_pose , double distance_tolerance);
void gridClean();
void spiralClean();

int main(int argc, char **argv)
{
    ros::init(argc,argv,"turtlesim_clean");
    ros::NodeHandle node;
    double speed,distance;
    bool isforward;
    double angle_speed,angle;
    bool clockwise;    

    velocity_publisher = node.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel",100);
    pose_subscriber = node.subscribe("/turtle1/pose",100,poseCallback);

/*
    cout<<"enter speed: ";
	cin>>speed;
	cout<<"enter distance: ";
	cin>>distance;
	cout<<"forward?: ";
	cin>>isforward;
	move(speed, distance, isforward);
    
	cout<<"enter angular velocity (degree/sec): ";
	cin>>angle_speed;
	cout<<"enter desired angle (degrees): ";
	cin>>angle;
	cout<<"clockwise ?: ";
	cin>>clockwise;
	rotate(degrees2radians(angle_speed), degrees2radians(angle), clockwise);
*/
	ros::Rate loop_rate(0.5);
	ros::Rate loop(.5);

    gridClean();
  //  spiralClean();

	ros::spin();

	return 0;	 
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

void rotate (double angular_speed , double relative_angle,bool clockwise){ 


    geometry_msgs::Twist vel_msgs;
    vel_msgs.linear.x=0;    
    vel_msgs.linear.y=0;
    vel_msgs.linear.z=0;
    vel_msgs.angular.x =0;
    vel_msgs.angular.y =0;    

    if(clockwise)
        vel_msgs.angular.z=-abs(angular_speed);
    else
        vel_msgs.angular.z=abs(angular_speed);

    double t0=ros::Time::now().toSec();
    double current_angle = 0;
    ros::Rate loop_rate(10);
    do{
        velocity_publisher.publish(vel_msgs);
        double t1 =ros::Time::now().toSec();
        current_angle=angular_speed*(t1-t0);
        ros::spinOnce();
        loop_rate.sleep();

    } while (current_angle<relative_angle);
    vel_msgs.linear.z=0;
    velocity_publisher.publish(vel_msgs);
}

double degrees2radians(double angle_in_degrees){
	return angle_in_degrees *PI /180.0;
}

double setDesiredOrientaion(double desired_angle_radian)
{
    double relative_desired_angle = desired_angle_radian - turtlesim_pose.theta ;
    bool clockwise = ((relative_desired_angle<0)?true:false);
    rotate(degrees2radians(10),abs(relative_desired_angle),clockwise);
}
double getDistance(double x1, double y1, double x2, double y2){
	return sqrt(pow((x1-x2),2)+pow((y1-y2),2));
}
void movetoGoal(turtlesim::Pose goal_pose , double distance_tolerance)
{
    geometry_msgs::Twist vel_msg;
 	ros::Rate loop_rate(100);

 
    do{
        double e=getDistance(turtlesim_pose.x,turtlesim_pose.y,goal_pose.x,goal_pose.y);
        vel_msg.linear.x=(e);
        vel_msg.linear.y=0;
        vel_msg.linear.z=0;
        vel_msg.angular.x=0;
        vel_msg.angular.y=0;    
		vel_msg.angular.z =4*(atan2(goal_pose.y-turtlesim_pose.y, goal_pose.x-turtlesim_pose.x)-turtlesim_pose.theta);

		velocity_publisher.publish(vel_msg);
		
        ros::spinOnce();
		loop_rate.sleep();        
	
    }while(getDistance(turtlesim_pose.x, turtlesim_pose.y, goal_pose.x, goal_pose.y)>distance_tolerance);
	cout<<"end move goal"<<endl;
	vel_msg.linear.x =0;
	vel_msg.angular.z = 0;
	velocity_publisher.publish(vel_msg);

}

void gridClean(){

	ros::Rate loop(0.5);
	turtlesim::Pose pose;
	pose.x=2;
	pose.y=2;
	pose.theta=0;
	movetoGoal(pose, 0.01);
	loop.sleep();
	/*setDesiredOrientaion(0);
	loop.sleep();

	rotate(degrees2radians(10), degrees2radians(90), false);
	loop.sleep();
	move(2.0, 1.0, true);
	rotate(degrees2radians(10), degrees2radians(90), false);
	loop.sleep();
	move(2.0, 9.0, true);
	//double distance = getDistance(turtlesim_pose.x, turtlesim_pose.y, x_max, y_max);
*/
	pose.x=5;
	pose.y=5;
	pose.theta=0;
	movetoGoal(pose, 0.01);
    loop.sleep();
    setDesiredOrientaion(1.55);
    //rotate(degrees2radians(10), degrees2radians(40), false);
    //loop.sleep();
    move(1, 4, true);
    //loop.sleep();
    rotate(degrees2radians(15), degrees2radians(90), false);
    move(1, 4, true);
    rotate(degrees2radians(15), degrees2radians(125), false);
    move(1, 9, true);
	pose.x=6;
	pose.y=6;
	pose.theta=0;
	movetoGoal(pose, 0.01);
}


void spiralClean(){
	geometry_msgs::Twist vel_msg;
	double count =0;
	double x = 0.5;
	ros::Rate loop(1);

	do{
		x=x+1.0;
		vel_msg.linear.x =x;
		vel_msg.linear.y =0;
		vel_msg.linear.z =0;

		vel_msg.angular.x = 0;
		vel_msg.angular.y = 0;
		vel_msg.angular.z =4;

		cout<<"vel_msg.linear.x = "<<vel_msg.linear.x<<endl;
		cout<<"vel_msg.angular.z = "<<vel_msg.angular.z<<endl;
		velocity_publisher.publish(vel_msg);
		ros::spinOnce();

		loop.sleep();
	}while((turtlesim_pose.x<10)&&(turtlesim_pose.y<10));
	vel_msg.linear.x =0;
    vel_msg.angular.z =0;
	velocity_publisher.publish(vel_msg);
}


