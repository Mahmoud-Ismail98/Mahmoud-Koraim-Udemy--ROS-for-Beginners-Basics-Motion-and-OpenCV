#!/usr/bin/env python
import rospy
from std_msgs.msg import String
def chatter_callback(message):
    rospy.loginfo(rospy.get_caller_id()+"I heard %s",message.data)

def listener():

    # In ROS, nodes are uniquely named. If two nodes with the same
    # node are launched, the previous one is kicked off. The
    # anonymous=True flag means that rospy will choose a unique
    # name for our 'listener' node so that multiple listeners can
    # run simultaneously.
    rospy.Subscriber("chatter",String,chatter_callback)
    rospy.init_node('listener' , anonymous=True)
              
    rospy.spin()

if __name__ == "__main__":
    listener()