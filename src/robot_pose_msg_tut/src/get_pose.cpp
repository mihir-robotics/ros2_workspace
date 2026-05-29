#include <functional>
#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "robot_pose_msg_tut/msg/robot_pose.hpp"                               

using std::placeholders::_1;

class RobotPoseSubscriber : public rclcpp::Node
{
public:
  RobotPoseSubscriber()
  : Node("get_pose")
  {
    auto topic_callback = [this](const robot_pose_msg_tut::msg::RobotPose & msg)
    {
    RCLCPP_INFO_STREAM(
        this->get_logger(),
        "{" << msg.joint_name << ":" << static_cast<int>(msg.joint_angle) << ":" << static_cast<float>(msg.joint_velocity) << "}"
    );
    };

    subscription_ = this->create_subscription<robot_pose_msg_tut::msg::RobotPose>(    
      "robot_pose", 10, topic_callback);
  }

private:
  rclcpp::Subscription<robot_pose_msg_tut::msg::RobotPose>::SharedPtr subscription_;  
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<RobotPoseSubscriber>());
  rclcpp::shutdown();
  return 0;
}