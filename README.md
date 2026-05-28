# ros2_ws — My ROS 2 Jazzy Learning Workspace

ROS 2 Jazzy Jalisco | Ubuntu 24.04 (WSL2) | Built with colcon

## Packages

| Package | Description | Difficulty |
|---|---|---|
| `cpp_pubsub` | Publisher / subscriber basics | <span style="color:#22c55e">Easy</span> |
| `cpp_server_client` | Service (server) client basics | <span style="color:#22c55e">Easy</span> |
| `custom_interfaces` | Creating custom messages / service | <span style="color:#22c55e">Easy</span> |
| `custom_cpp_client_server` | Client / server with custom service | <span style="color:#22c55e">Easy</span> |
| `more_custom_interfaces` | Custom Address book msg with Pub/Sub | <span style="color:#22c55e">Easy</span> |
| `polygon / polygon_plugins` | Custom Plugins for Polygons | <span style="color:#22c55e">Easy</span> |
| `servo_controller` | Control MG90 servo connected to Arduino via Serial | <span style="color:#22c55e">Mini-project</span> |
| `custom_actions / custom_action_cpp` | Custom Action interface for computing Fibonacci series | <span style="color:#EAB308">Intermediate</span> |

## Build

```bash
# Creating a new package
cd src
ros2 pkg create --build-type ament_cmake --license Apache-2.0 --dependencies <dependencies>  <package_name>

# Building the package
cd ~/ros2_ws
source install/setup.bash 
colcon build --packages-select <package_name>
```

## Requirements
- ROS 2 Jazzy Jalisco
- Ubuntu 24.04
