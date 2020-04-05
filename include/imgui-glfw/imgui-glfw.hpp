#pragma once

#include <functional>

struct GLFWwindow;

class ImGuiGlfw
{
public:
    explicit ImGuiGlfw(GLFWwindow*);
    ~ImGuiGlfw();

    void draw(std::function<void()> frame) const;
};
