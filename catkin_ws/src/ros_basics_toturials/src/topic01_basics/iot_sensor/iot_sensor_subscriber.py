#!/usr/bin/env python
import rospy
from ros_basics_toturials.msg import IoTSensor
def iot_sensor_callback(iot_sensor_message):
    rospy.loginfo("I heard IoT data %d,%s,%.2f,%.2f",
        iot_sensor_message.id,iot_sensor_message.name,
        iot_sensor_message.temperature,iot_sensor_message.humidity)

rospy.Subscriber("iot_sensor_topic",IoTSensor,iot_sensor_callback)
rospy.init_node('iot_sensor_subscriber_node' , anonymous=True)
          
rospy.spin()