# imgui-glfw

[![Build status](https://ci.appveyor.com/api/projects/status/evthrhj6y8iv0m4q?svg=true)](https://ci.appveyor.com/project/Abergard/imgui-glfw)
[![Build Status](https://travis-ci.org/Abergard/imgui-glfw.svg?branch=master)](https://travis-ci.org/Abergard/imgui-glfw)

Easy and fast setup, just pass pointer to `GLFWwindow` to `ImGuiGlfw` constructor and draw the ui interface.
It prepares and initializes ImGui at construct and deinitializes at destruct time. [Example here!](examples/main.cpp)

```cpp
int main()
{
    // ...
    // setup
    ImGuiGlfw ui{/* GLFWwindow* */ window};
 
    // ...
    // in a loop
    ui.draw([&]() {
        ImGui::Begin("Hello, world!");
        ImGui::Text("This is some useful text.");
        ImGui::End();
    });
}

```
![](https://i.imgur.com/mtCBEul.png)
