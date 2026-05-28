#include <chrono>
#include <memory>
#include <random>
#include "rclcpp/rclcpp.hpp"
#include "robot_pose_msg_tut/msg/robot_pose.hpp"

#define TOPIC_NAME "robot_pose"
#define QUEUE_SIZE 10

using namespace std::chrono_literals;

class RobotPosePublisher : public rclcpp::Node {
    public:
        RobotPosePublisher() : Node("robot_pose_publisher") {
            robot_pose_publisher_ = this->create_publisher<robot_pose_msg_tut::msg::RobotPose>(TOPIC_NAME, QUEUE_SIZE);
            
            auto publish_msg = [this]() -> void {
                // Message for Base joint
                auto message = robot_pose_msg_tut::msg::RobotPose();
                
                message.joint_name = "base_joint";
                message.joint_angle = this->dist_(this->rng_);
                message.joint_velocity = 15.0;

                this->robot_pose_publisher_->publish(message);


                // Message for elbow joint
                auto elbow_message = robot_pose_msg_tut::msg::RobotPose();
                
                elbow_message.joint_name = "elbow_joint";
                elbow_message.joint_angle = this->dist_(this->rng_);
                elbow_message.joint_velocity = 20.0;

                this->robot_pose_publisher_->publish(elbow_message);
            };
            timer_ = this->create_wall_timer(1s, publish_msg);
        }
    
    private:
       rclcpp::Publisher<robot_pose_msg_tut::msg::RobotPose>::SharedPtr robot_pose_publisher_;
       rclcpp::TimerBase::SharedPtr timer_;

       // Send a random joint angle, between 0 and 180 degrees
       std::mt19937 rng_{std::random_device{}()};
       std::uniform_int_distribution<int> dist_{0, 180};
};

int main(int argc, char * argv[]) {

    rclcpp::init(argc,argv);
    rclcpp::spin(std::make_shared<RobotPosePublisher>());
    rclcpp::shutdown();

    return 0;

}
