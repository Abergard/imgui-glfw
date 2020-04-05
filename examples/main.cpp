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

        window = glfwCreateWindow(640, 480, "Only4Test", nullptr, nullptr);
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

    // Our state
    bool show_demo_window = true;
    bool show_another_window = false;
    ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

    while (window.is_open())
    {
        window.handle_events();
        window.draw([&]() {
            ui.draw([&]() {
                static float f = 0.0f;
                static int counter = 0;

                ImGui::Begin("Hello, world!"); // Create a window called "Hello,
                                               // world!" and append into it.

                ImGui::Text("This is some useful text.");          // Display some text (you can
                                                                   // use a format strings too)
                ImGui::Checkbox("Demo Window", &show_demo_window); // Edit bools storing our
                                                                   // window open/close state
                ImGui::Checkbox("Another Window", &show_another_window);
                ImGui::SliderFloat("float", &f, 0.0f, 1.0f); // Edit 1 float using a slider from 0.0f to 1.0f
                ImGui::ColorEdit3("clear color", (float*)&clear_color); // Edit 3 floats representing a
                                                                        // color

                if (ImGui::Button("Button")) // Buttons return true when
                                             // clicked (most widgets return
                                             // true when edited/activated)
                {
                    counter++;
                }
                ImGui::SameLine();
                ImGui::Text("counter = %d", counter);

                ImGui::Text("Application average %.3f ms/frame (%.1f FPS)",
                            1000.0f / ImGui::GetIO().Framerate,
                            ImGui::GetIO().Framerate);
                ImGui::End();
            });
        });
    }
}
