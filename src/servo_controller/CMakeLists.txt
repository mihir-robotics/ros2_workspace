cmake_minimum_required(VERSION 3.8)
project(servo_controller)

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

add_executable(servo_node src/servo_node.cpp)
ament_target_dependencies(servo_node rclcpp std_msgs)
install(TARGETS servo_node DESTINATION lib/${PROJECT_NAME})

ament_package()
