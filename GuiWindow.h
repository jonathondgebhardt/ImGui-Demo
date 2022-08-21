#pragma once

#include <string>

namespace tl
{
  class GuiWindow
  {
  public:
    GuiWindow(const std::string& x);
    virtual ~GuiWindow();

    void addText(const std::string& x);

  private:
    GuiWindow() = delete;
    GuiWindow(const GuiWindow&) = delete;
    GuiWindow& operator=(const GuiWindow&) = delete;
  };
} // namespace tl
