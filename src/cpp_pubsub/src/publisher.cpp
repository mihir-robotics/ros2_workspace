#include <chrono>
#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "custom_interfaces/msg/num.hpp"                                            

using namespace std::chrono_literals;

class MinimalPublisher : public rclcpp::Node
{
public:
  MinimalPublisher()
  : Node("minimal_publisher"), count_(0)
  {
    publisher_ = this->create_publisher<custom_interfaces::msg::Num>("topic", 10);  

    auto timer_callback = [this](){
      auto message = custom_interfaces::msg::Num();                                   
      message.num = this->count_++;                                                     
      RCLCPP_INFO_STREAM(this->get_logger(), "Publishing: '" << message.num << "'");    
      publisher_->publish(message);
    };
    timer_ = this->create_wall_timer(500ms, timer_callback);
  }

private:
  rclcpp::TimerBase::SharedPtr timer_;
  rclcpp::Publisher<custom_interfaces::msg::Num>::SharedPtr publisher_;             
  size_t count_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<MinimalPublisher>());
  rclcpp::shutdown();
  return 0;
}