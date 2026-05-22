#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/float32.hpp>
#include <termios.h>
#include <fcntl.h>
#include <unistd.h>

class ServoNode : public rclcpp::Node
{
public:
  ServoNode() : Node("servo_node")
  {
    this->declare_parameter("port", "/dev/ttyUSB0");
    std::string port = this->get_parameter("port").as_string();

    fd_ = open(port.c_str(), O_RDWR | O_NOCTTY);
    struct termios tty{};
    tcgetattr(fd_, &tty);
    cfsetspeed(&tty, B115200);
    cfmakeraw(&tty);
    tcsetattr(fd_, TCSANOW, &tty);

    sub_ = create_subscription<std_msgs::msg::Float32>(
      "servo/cmd_angle", 10,
      [this](std_msgs::msg::Float32::SharedPtr msg) {
        std::string cmd = std::to_string((int)msg->data) + "\n";
        write(fd_, cmd.c_str(), cmd.size());
      });
  }

  ~ServoNode() { close(fd_); }

private:
  int fd_;
  rclcpp::Subscription<std_msgs::msg::Float32>::SharedPtr sub_;
};

int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<ServoNode>());
  rclcpp::shutdown();
}