#include <chrono>
#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "more_custom_interfaces/msg/address_book.hpp"

using namespace std::chrono_literals;

class AddressBookPublisher : public rclcpp::Node
{
public:
  AddressBookPublisher()
  : Node("address_book_publisher")
  {
    address_book_publisher_ =
      this->create_publisher<more_custom_interfaces::msg::AddressBook>("address_book", 10);

    auto publish_msg = [this]() -> void {
        auto message = more_custom_interfaces::msg::AddressBook();

        message.first_name = "Goober";
        message.last_name = "Collins";
        message.phone_number = "818-434-9867";
        message.phone_type = message.PHONE_TYPE_WORK;

        std::cout << "{"<< message.first_name <<":"<< message.last_name <<":"<< message.phone_number<< ":" << static_cast<int>(message.phone_type) << "}" << std::endl;

        this->address_book_publisher_->publish(message);
      };
    timer_ = this->create_wall_timer(1s, publish_msg);
  }

private:
  rclcpp::Publisher<more_custom_interfaces::msg::AddressBook>::SharedPtr address_book_publisher_;
  rclcpp::TimerBase::SharedPtr timer_;
};


int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<AddressBookPublisher>());
  rclcpp::shutdown();

  return 0;
}