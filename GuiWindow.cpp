#include <GuiWindow.h>

#include <imgui.h>

tl::GuiWindow::GuiWindow(const std::string& x)
{
  ImGui::Begin(x.c_str());
}

tl::GuiWindow::~GuiWindow()
{
  ImGui::End();
}

void tl::GuiWindow::addText(const std::string& x)
{
  ImGui::Text(x.c_str());
}
