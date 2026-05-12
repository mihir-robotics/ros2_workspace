cmake_minimum_required(VERSION 3.8)
project(cpp_parameters_example)

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)

add_executable(parameter_node src/parameter_node.cpp)
ament_target_dependencies(parameter_node rclcpp)

install(TARGETS
    parameter_node
  DESTINATION lib/${PROJECT_NAME}
)

install(
  DIRECTORY launch
  DESTINATION share/${PROJECT_NAME}
)
ament_package()
