# ros2_ws — My ROS 2 Jazzy Learning Workspace

ROS 2 Jazzy Jalisco | Ubuntu 24.04 (WSL2) | Built with colcon

## Packages

| Package | Description |
|---|---|
| `cpp_pubsub` | Publisher / subscriber basics |
| `cpp_server_client` | Service (server) client basics |
| `custom_interfaces` | Creating custom messages / service |
| `custom_cpp_client_server` | Client / server with custom service |

## Build

```bash
source /opt/ros/jazzy/setup.bash
colcon build --symlink-install
source install/setup.bash
```

## Requirements
- ROS 2 Jazzy Jalisco
- Ubuntu 24.04
