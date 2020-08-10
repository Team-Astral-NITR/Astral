#ASTRAL INTELLIGENT PICKING GAZEBO SIMULATION

## Prerequisites
- Ubuntu 16.04 or newer (Ubuntu 18.04 recommended)
- [ROS Kinetic ](http://wiki.ros.org/kinetic/Installation/Ubuntu) (Ubuntu 16.04) or [ROS Melodic ](http://wiki.ros.org/melodic/Installation/Ubuntu) (Ubuntu 16.04)
- [Catkin Tools](https://catkin-tools.readthedocs.io/en/latest/installing.html)

## Build
Build all the packages by running this inside your workspace
```sh
$ catkin build astral_gazebo
$ source devel/setup.bash
```

## Extract model files
Extract models.zip to home/.gazebo/
```sh
$ roscd astral_gazebo
$ unzip models.zip -d ~/.gazebo/models/
```

### View of arena

![Head view][https://github.com/Team-Astral-NITR/Astral/tree/master/astral_gazebo/utils/head_view.png]
![Side view][https://github.com/Team-Astral-NITR/Astral/tree/master/astral_gazebo/utils/side_view.png]

### Todos

 -Plugins for robotic arm and omni wheel based
 -link with rrt and image segmentation module for simulation
