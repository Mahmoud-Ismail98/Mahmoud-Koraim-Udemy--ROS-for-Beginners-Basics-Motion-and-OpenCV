#!/usr/bin/env python

import sys
import rospy

from ros_basics_toturials.srv import AddTwoInts
from ros_basics_toturials.srv import AddTwoIntsRequest
from ros_basics_toturials.srv import AddTwoIntsResponse

def add_two_inits_client(x,y): 
    rospy.wait_for_service('add_two_ints')
    try:
        #add_two_inits = rospy.ServiceProxy('add_two_ints', AddTwoInts)
        #resp=add_two_inits(x,y)
        resp=rospy.ServiceProxy('add_two_ints', AddTwoInts)(x,y)
        return resp.sum
    except rospy.ServiceException,e:
        print "service call faild %s"%e 

def not_enough_parm():
    return "%s is not enough parameter plz enter [x y]"%sys.argv[1]

if __name__=="__main__": 
    if len(sys.argv) == 3:
        x = int(sys.argv[1])
        y = int(sys.argv[2])
    else:
        print not_enough_parm()
        sys.exit(1)

    print "requesting %s+%s"%(x,y)
    s =add_two_inits_client(x,y)
    print"%s+%s=%s"%(x,y,s)    