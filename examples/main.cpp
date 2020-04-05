#include <glad/glad.h>

#define GLFW_INCLUDE_NONE

#include <GLFW/glfw3.h>
#include <functional>
#include <imgui-glfw/imgui-glfw.hpp>
#include <imgui.h>
#include <stdexcept>

using namespace std;

class GlfwWindow
{
public:
    GlfwWindow()
    {
        if (!glfwInit())
        {
            throw std::runtime_error{"Cannot initialize GLFW"};
        }

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

        window = glfwCreateWindow(640, 480, "ImGuiGlfwOpengl3", nullptr, nullptr);
        if (!window)
        {
            glfwTerminate();
            throw std::runtime_error{"Cannot create GLFW window"};
        }

        glfwMakeContextCurrent(window);
        gladLoadGL();
        glfwSwapInterval(1); // Enable vsync
    }

    GLFWwindow* data()
    {
        return window;
    }

    void draw(std::function<void()> frame)
    {
        glClear(GL_COLOR_BUFFER_BIT);
        frame();
        glfwSwapBuffers(window);
    }

    void handle_events()
    {
        glfwPollEvents();
    }

    bool is_open() const
    {
        return !glfwWindowShouldClose(window);
    }

    ~GlfwWindow()
    {
        glfwDestroyWindow(window);
        glfwTerminate();
    }

private:
    GLFWwindow* window;
};

int main()
{
    GlfwWindow window;
    ImGuiGlfw ui{window.data()};

    while (window.is_open())
    {
        window.handle_events();
        window.draw([&]() {
            ui.draw([&]() {

                ImGui::Begin("Hello, world!"); // Create a window called "Hello,
                                               // world!" and append into it.

                ImGui::Text("This is some useful text.");          // Display some text (you can
                ImGui::End();
            });
        });
    }
}
