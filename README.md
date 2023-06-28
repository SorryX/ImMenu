# ImMenu
Think it is boring to clone, modify and then start writing your menus? This is the perfect option for you to get started directly instead of spending precious time on setting up!

## Steps

- Start by cloning the project
  - ```git clone https://github.com/SorryX/ImMenu```
- Open the project with the .vcxproj
- Start writing your menu!

## Fonts

The project includes a class called Fonts which is something useful to get fonts by string instead of ids, hence when adding fonts you can write a string
which later can be used to get that font, remember you can always just use the default way!

using `fonts` instance you can access all fonts by string
```cpp
fonts.GetFontByString("small_font"); 
```
and you can use this to render different fonts on different element!
