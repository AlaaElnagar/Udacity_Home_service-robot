# Home service robot project 
## As shown the project main idea is to get target from specific place and put it into another place after creating map for undefined zone

![](ros.gif)

## project packages 
1. add_markers : used to add new virtual objects to rviz  
2. slam_gmapping : used to create map after moving trough an unknown area and making loop closure 
3. teleop_twist_keyboard : used provide robot manual control
4. turtlebot_simulator : contains turtlebot_gazebo for making stable localization using Amcl algorithm also contain turtlebot and my world 
5. turtlebot_interactions : contain  rviz file which configured with the map to be able to test my map using 2d nav goal 
6. pick_objects : help to give the robot to different places pick and drop 


## My steps:
1. adding both my gazebo world and turtlebot together through ``` turtlebot_world.launch```file
2. starting to implementing slam and generating map through moving manually using ```turtlebot_key``` and ```slam_gmaping``` 
3. moving through the map in rviz using 2d navgoal tool and showing trajectory ```view_navigation.launch``` and Amcl algorithm usign ```test_navigation.sh```
4. moving to two different places in ```pick_objects node``` after running ```pick_objects.sh```
5. making cube markers which appear each 5 seconds using ```add_markers```pkg
6. starting to pick and drop the markers seemingly after getting my odom and target position difference using both ```pick_objects```and ```add_markers```pkg


