#pragma once

#include <string>

struct GLFWwindow;

namespace BloxoffEngine {
    class Window {
    public:
        Window(std::string title, const unsigned int width, const unsigned int height);
        ~Window();

        Window(const Window&) = delete;
        Window(Window&&) = delete;
        Window& operator = (const Window&) = delete;
        Window& operator = (Window&&) = delete;

        unsigned int get_width() const { return m_width; };
        unsigned int get_height() const { return m_height; };

        void update();
    private:
        int init();
        void shotdown();
        
        GLFWwindow* m_pWindow;
        std::string m_title;
        unsigned int m_width;
        unsigned int m_height;
    };
}