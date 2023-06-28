#pragma once
#include <unordered_map>
#include <string>
#include "imgui.h"

class Fonts
{
public:
    // Using this you can get any font by name
    ImFont* GetFontByString(const char* name)
    {
        return fonts.at(name);
    }

    // You can get any font by index, doesn't matter if you used the normal AddFont functions or the ones in this class!
    ImFont* GetFontByIndex(int index)
    {
        return ImGui::GetIO().Fonts->Fonts[index];
    }

    // This adds a font the normal way but adding it to the fonts map to later be used to get fonts by string using the GetFont(...) function
    void AddFontFromMemoryCompressedTTF(const char* keyname, const void* compressed_ttf_data, int compressed_ttf_size, float size_pixels, const ImFontConfig* font_cfg_template = 0, const ImWchar* glyph_ranges = 0)
    {
        ImGuiIO& io = ImGui::GetIO();
        ImFont* font = io.Fonts->AddFontFromMemoryCompressedTTF(compressed_ttf_data, compressed_ttf_size, size_pixels, font_cfg_template, glyph_ranges);

        if (font)
            fonts.insert({ keyname, font });
    }

    // This adds a font the normal way but adding it to the fonts map to later be used to get fonts by string using the GetFont(...) function
    void AddFontFromFileTTF(const char* keyname, const char* filename, float size_pixels, const ImFontConfig* font_cfg_template = 0, const ImWchar* glyph_ranges = 0)
    {
        ImGuiIO& io = ImGui::GetIO();
        ImFont* font = io.Fonts->AddFontFromFileTTF(filename, size_pixels, font_cfg_template, glyph_ranges);

        if (font)
            fonts.insert({ keyname, font });
    }
private:
    std::unordered_map<const char*, ImFont*> fonts; // Get fonts by string
};

