from launch import LaunchDescription
from launch_ros.actions import Node


def generate_launch_description():
    return LaunchDescription([
        Node(
            package='cpp_parameters_example',
            executable='parameter_node',
            name='parameter_node',
            output='screen',
            emulate_tty=True,
            parameters=[
                {'new_param': 'earth'}
            ]
        )
    ])