#include <functional>
#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "more_custom_interfaces/msg/address_book.hpp"                                 

using std::placeholders::_1;

class MinimalSubscriber : public rclcpp::Node
{
public:
  MinimalSubscriber()
  : Node("get_address")
  {
    auto topic_callback = [this](const more_custom_interfaces::msg::AddressBook & msg)
    {
    RCLCPP_INFO_STREAM(
        this->get_logger(),
        "{" << msg.first_name << ":" << msg.last_name << ":" << msg.phone_number << ":" << static_cast<int>(msg.phone_type) << "}"
    );
    };

    subscription_ = this->create_subscription<more_custom_interfaces::msg::AddressBook>(    
      "address_book", 10, topic_callback);
  }

private:
  rclcpp::Subscription<more_custom_interfaces::msg::AddressBook>::SharedPtr subscription_;  
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<MinimalSubscriber>());
  rclcpp::shutdown();
  return 0;
}