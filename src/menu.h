#pragma once
#include <d3d11.h>

// imgui includes
#include "imgui.h"
#include "imgui_internal.h"
#include "custom.h"

// fonts includes!
#include "fonts/fonts.h"
#include "fonts/josefin_sans.h"

class Menu
{
public:
    Menu(ID3D11Device* pDevice)
    {
        this->pDevice = pDevice; // might be required for later when rendering things like images!
    }

    ~Menu() = default;

    void Render();

    void InitFonts() noexcept
    {
        fonts.AddFontFromMemoryCompressedTTF("standard", Josefin_sans_compressed_data, Josefin_sans_compressed_size, 14.f);
    }

    void InitStyle() noexcept
    {
        ImGuiStyle& style = ImGui::GetStyle();
        ImVec4* colors = style.Colors;

        // Set like this colors!
        // style.Colors[ImGuiCol_WindowBg] = ImColor(255, 255, 255, 255);
    }

private:
    // Configuration
    ImGuiWindowFlags windowFlags = ImGuiWindowFlags_NoTitleBar;
    ImVec2 startup_size = ImVec2(500, 500);

    // use these when needed e.g adding fonts or adding images!
    Fonts fonts;
    ID3D11Device* pDevice;
};

