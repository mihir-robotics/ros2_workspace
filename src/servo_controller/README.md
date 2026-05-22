## Description:
ROS2 C++ node to control an MG90 servo connected to Arduino Nano via Serial port.

## Important Commands:

### Attaching the Serial Port to WSL:
```powershell
winget install usbipd        # only needed once
 
usbipd list                  # find your Arduino's BUSID e.g. 2-1
usbipd bind --busid 2-1      # only needed once per device
usbipd attach --wsl --busid 2-1
```

```bash
ls /dev/ttyUSB* /dev/ttyACM*
```

> Re-run `usbipd attach` every time you unplug the Arduino or restart WSL.

### Running the Node / Publishing data:
```bash
ros2 run servo_controller servo_node --ros-args -p port:=/dev/ttyUSB0

# Move to 90 degrees (continuously, servo holds position)
ros2 topic pub /servo/cmd_angle std_msgs/msg/Float32 "data: 90.0"
 
# One-shot (servo may reset to 0 after — use continuous pub instead)
ros2 topic pub --once /servo/cmd_angle std_msgs/msg/Float32 "data: 90.0"

# Echo the topic
ros2 topic echo /servo/cmd_angle
```