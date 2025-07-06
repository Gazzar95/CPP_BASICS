# 🐢 Turtle Autopilot – ROS 2 C++ Practice Project

## 📚 Overview

This is a beginner-friendly ROS 2 project designed to help you practice writing ROS 2 nodes in **modern C++ (rclcpp)** by controlling the [Turtlesim](https://github.com/ros/ros_tutorials/tree/rolling/turtlesim) simulator. The node publishes velocity commands to the turtle autonomously, simulating a basic “autopilot.”

This project reinforces key ROS 2 C++ concepts like:
- Writing a publisher node with `rclcpp`
- Publishing velocity commands (`geometry_msgs::msg::Twist`)
- Using timers for real-time behavior
- Calling services (e.g. `/reset`) from C++
- Optional: working with ROS 2 parameters

> 🎯 Goal: Write your own ROS 2 C++ node that moves the turtle in a defined pattern (circle, square, zigzag, etc.) without keyboard input.

---

## 🛠️ Scope of Work

### ✅ Core Requirements
- [x] Write a ROS 2 C++ node (`turtle_autopilot`) that:
  - Publishes to `/turtle1/cmd_vel`
  - Moves the turtle in a **circle** or **square**
  - Uses a **timer** to control motion at fixed intervals

### 🔁 Optional Extensions
- [ ] Add a **parameter** to choose the motion pattern (circle, square, etc.)
- [ ] Add a **service client** to reset the turtle using `/reset`
- [ ] Allow CLI-configurable speed or loop count

---

## 🧑‍💻 Why This Project?

This is the first “full ROS 2 project” where you:
- Write a complete working node in C++ from scratch
- Use **core ROS 2 APIs** that show up everywhere (pubs, timers, services)
- See **live results** in the turtlesim window
- Reinforce CMake setup, package structure, and ROS 2 launch basics
- Lay groundwork for controlling real robots later via `/cmd_vel`

It's intentionally scoped to be **small but complete** — enough to learn by building, without being overwhelming.

---

## 🚀 How to Run It

1. **Install turtlesim** (if not installed):
   ```bash
   sudo apt install ros-humble-turtlesim
