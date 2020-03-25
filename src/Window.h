#ifndef _WINDOW_H
#define _WINDOW_H
#include <string>

namespace Antix
{
    struct Window
    {
        std::string name;
        int width, height;
        int x_pos, y_pos;
        bool isReshapable;

        Window()
        {
            name = "---- Antix Game Engine ----";
            width = 1280;
            height = 800;
            x_pos = 500;
            y_pos = 500;
            isReshapable = true;

        }

        Window(std::string name, int start_pos_x, int start_pos_y, int width, int height, bool is_Reshapable)
        {
            this->name = name;
            this->x_pos = start_pos_x;
            this->y_pos = start_pos_y;
            
            this->width = width;
            this->height = height;
            this->isReshapable = is_Reshapable;
        }

        void operator=(const Window& window)
        {
            name = window.name;
            x_pos = window.x_pos;
            y_pos = window.y_pos;

            width = window.width;
            height = window.height;
            isReshapable = window.isReshapable;
        }
    };
}

#endif