#include <chrono>
#include <functional>
#include <string>

#include <rclcpp/rclcpp.hpp>

using namespace std::chrono_literals;

class MinimalParam : public rclcpp::Node
{
public:
  MinimalParam()
  : Node("parameter_node")
  {
    auto param_desc = rcl_interfaces::msg::ParameterDescriptor{};
    param_desc.description = "This parameter is mine!";
    
    this->declare_parameter("new_param", "World", param_desc);

    auto timer_callback = [this](){
      std::string my_param = this->get_parameter("new_param").as_string();

      RCLCPP_INFO(this->get_logger(), "Hello %s!", my_param.c_str());

      std::vector<rclcpp::Parameter> all_new_parameters{rclcpp::Parameter("new_param", "world")};
      this->set_parameters(all_new_parameters);
    };
    timer_ = this->create_wall_timer(1000ms, timer_callback);
  }

private:
  rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<MinimalParam>());
  rclcpp::shutdown();
  return 0;
}