cmake_minimum_required(VERSION 3.8)
project(robot_pose_msg_tut)

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rosidl_default_generators REQUIRED)

set(msg_files
  "msg/RobotPose.msg"
)

rosidl_generate_interfaces(${PROJECT_NAME}
  ${msg_files}
)
ament_export_dependencies(rosidl_default_runtime)


add_executable(publish_pose src/publish_pose.cpp)
ament_target_dependencies(publish_pose rclcpp)

add_executable(get_pose src/get_pose.cpp)
ament_target_dependencies(get_pose rclcpp)

rosidl_get_typesupport_target(cpp_typesupport_target
  ${PROJECT_NAME} rosidl_typesupport_cpp)

target_link_libraries(publish_pose "${cpp_typesupport_target}")
target_link_libraries(get_pose "${cpp_typesupport_target}")



install(TARGETS
    publish_pose
    get_pose
  DESTINATION lib/${PROJECT_NAME})

ament_package()
