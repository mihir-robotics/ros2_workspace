```bash
# Quick reference commands

# Round and Round
ros2 topic pub --once /cmd_vel geometry_msgs/Twist "{linear: {x: 0.1, y: 0.9, z: 0.0}, angular: {x: 0.5, y: 0.0, z: 0.9}}"

# Stop!!
ros2 topic pub --once /cmd_vel geometry_msgs/Twist "{linear: {x: 0.0, y: 0.0, z: 0.0}, angular: {x: 0.0, y: 0.0, z: 0.0}}"
```