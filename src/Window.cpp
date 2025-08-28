#include <Window.hpp>
#include <Logger.hpp>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace BloxoffEngine {

    static bool s_GLFW_initialized = false;

    Window::Window(std::string title, const unsigned int width, const unsigned int height)
        : m_title(std::move(title)),
        m_width(width),
        m_height(height)
    {
        int resCode = init();
    }
    Window::~Window(){
        shotdown();
    }

    int Window::init(){
        //Awake();
        LOG_INFO("Awake worked correctly");

        /* Initialize the library */
        if (!glfwInit())
        {
            LOG_CRIT("glfw wasn't initialized");
            return -1;
        }
        s_GLFW_initialized = true;
        LOG_INFO("glfw was initialized");
        /* Create a windowed mode window and its OpenGL context */
        m_pWindow = glfwCreateWindow(m_width, m_height, m_title.c_str(), nullptr, nullptr);
        if (!m_pWindow)
        {
            LOG_CRIT("window wasn't created");
            glfwTerminate();
            return -1;
        }
        LOG_INFO("window was created");

        /* Make the window's context current */
        glfwMakeContextCurrent(m_pWindow);


        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        {
            LOG_CRIT("glad wasn't initialized");
            glfwTerminate();
            return -1;
        }
        LOG_INFO("glad was initialized");


        //Start();
        LOG_INFO("Start worked correctly");

        return 0;
    }

    void Window::update(){
        glClearColor(0.133, 0.137, 0.188, 0);
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(m_pWindow);
        glfwPollEvents();
    }

    void Window::shotdown(){
        LOG_INFO("programm was stoped");
        glfwDestroyWindow(m_pWindow);
        glfwTerminate();
    }
}