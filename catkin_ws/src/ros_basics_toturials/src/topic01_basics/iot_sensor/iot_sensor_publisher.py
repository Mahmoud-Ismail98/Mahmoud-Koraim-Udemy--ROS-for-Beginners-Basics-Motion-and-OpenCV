#!/usr/bin/env python
# license removed for brevity
import rospy
from ros_basics_toturials.msg import IoTSensor
import random

pub = rospy.Publisher('iot_sensor_topic',IoTSensor,queue_size=10)
rospy.init_node('iot_sensor_publisher_node',anonymous=True)

rate = rospy.Rate(1)

i = 0
while not rospy.is_shutdown():
    iot_sensor = IoTSensor()
    iot_sensor.id = 1
    iot_sensor.name="iot_Sensor1"
    iot_sensor.temperature=24+(random.random()*2)
    iot_sensor.humidity=30+(random.random()*2)
    rospy.loginfo("i publish")
    rospy.loginfo(iot_sensor)
    pub.publish(iot_sensor)
    rate.sleep()
    i = i+1
 