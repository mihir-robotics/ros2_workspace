cmake_minimum_required(VERSION 3.8)
project(cpp_server_client)

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(example_interfaces REQUIRED)

# Add server executable
add_executable(server src/add_two_ints_server.cpp)
ament_target_dependencies(server rclcpp example_interfaces)

# Add client executable
add_executable(client src/add_two_ints_client.cpp)
ament_target_dependencies(client rclcpp example_interfaces)

# So that ROS2 can find the executable
install(TARGETS
    server
    client
  DESTINATION lib/${PROJECT_NAME})

ament_package()