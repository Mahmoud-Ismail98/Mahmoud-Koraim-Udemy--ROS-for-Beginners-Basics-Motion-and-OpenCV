#!/usr/bin/env python


from ros_basics_toturials.srv import AddTwoInts
from ros_basics_toturials.srv import AddTwoIntsRequest
from ros_basics_toturials.srv import AddTwoIntsResponse
import rospy

def handle_add_two_ints(req):
    print "returning[%s+%s=%s]"%(req.a,req.b,(req.a+req.b))
    return AddTwoIntsResponse(req.a+req.b)

def add_two_ints_Server():
    rospy.init_node('add_two_ints_server')
    ser = rospy.Service('add_two_ints',AddTwoInts,handle_add_two_ints)
    print "ready to add two ints."
    rospy.spin()

if __name__ =="__main__":
    add_two_ints_Server()    