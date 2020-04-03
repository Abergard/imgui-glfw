#include "imgui-glfw/imgui-glfw.hpp"

#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

ImGuiGlfw::ImGuiGlfw(GLFWwindow* window)
{
    ImGui::CreateContext();
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init(nullptr);
}

ImGuiGlfw::~ImGuiGlfw()
{
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
}

void ImGuiGlfw::draw(std::function<void()> frame) const
{
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();
    frame();
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}
