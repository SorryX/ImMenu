#include "menu.h"

void Menu::Render()
{
    ImGui::SetNextWindowSize(startup_size, ImGuiCond_FirstUseEver);
    ImGui::Begin("whatever", nullptr, windowFlags);
    {
        ImGui::CustomCheckbox("test", nullptr); // and this is how you can use custom elements!
    }
    ImGui::End();
}
