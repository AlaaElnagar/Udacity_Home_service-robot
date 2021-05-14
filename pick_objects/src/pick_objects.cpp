#include <ros/ros.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>

// Define a client for to send goal requests to the move_base server through a SimpleActionClient
typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;

int main(int argc, char** argv){
  // Initialize the simple_navigation_goals node
  ros::init(argc, argv, "pick_objects");
  ros::NodeHandle n;
  ros::Publisher goal_pub = n.advertise<geometry_msgs::Pose>("/target",20);


  //tell the action client that we want to spin a thread by default
  MoveBaseClient ac("move_base", true);

  // Wait 5 sec for move_base action server to come up
  while(!ac.waitForServer(ros::Duration(5.0))){
    ROS_INFO("Waiting for the move_base action server to come up");
  }

  move_base_msgs::MoveBaseGoal goal;

  // set up the frame parameters
  goal.target_pose.header.frame_id = "map";
  goal.target_pose.header.stamp = ros::Time::now();

  // Define a position and orientation for the robot to reach
  goal.target_pose.pose.position.x = 1;
  goal.target_pose.pose.position.y = -1;
  goal.target_pose.pose.orientation.w = -1.57;

   // Send the goal position and orientation for the robot to reach
  ROS_INFO("Sending goal.....GOing to get it and pick up ");


  geometry_msgs::Pose msg;
  msg.position.x = 1.;
  msg.position.y = -1.;
  msg.position.z = 0.0;
  msg.orientation.x = 0.0;
  msg.orientation.y = 0.0;
  msg.orientation.z = 0.0;
  msg.orientation.w = -1.57;
  goal_pub.publish(msg);

  ac.sendGoal(goal);

  // Wait an infinite time for the results
  ac.waitForResult();

  // Check if the robot reached its goal
  if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED){
    ROS_INFO("Hooray, the base moved  to get it --->pick up location <----->>lets wait 5 sec..");
    ros::Duration(5.0).sleep();
}
  else
    ROS_INFO("Sorry i can't move for  some reason");

 move_base_msgs::MoveBaseGoal Drop;
 Drop.target_pose.header.frame_id = "map";
 Drop.target_pose.header.stamp = ros::Time::now();

  Drop.target_pose.pose.position.x = -5
;
  Drop.target_pose.pose.position.y = 1.6;
  Drop.target_pose.pose.orientation.w = 1.8;



  geometry_msgs::Pose msg2;
  msg2.position.x = -5;
  msg2.position.y = 1.6;
  msg2.position.z = 0.0;
  msg2.orientation.x = 0.0;
  msg2.orientation.y = 0.0;
  msg2.orientation.z = 0.0;
  msg2.orientation.w = 1.8;
  goal_pub.publish(msg2);

  ac.sendGoal(Drop);

  ROS_INFO("Sending Drop.....GOing to Drop it .... ");



  ac.sendGoal(Drop);	
  ac.waitForResult();

  if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED){
    ROS_INFO("Done its Droped----->>l..");
    ros::Duration(5.0).sleep();
}
  else
    ROS_INFO("Sorry i can't reach to drop zone  for  some reason");
  

  return 0;
  

}
