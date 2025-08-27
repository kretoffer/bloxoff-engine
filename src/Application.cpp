#include <Application.hpp>
#include <Logger.hpp>
#include <GLFW/glfw3.h>

namespace BloxoffEngine {
    Application::Application()
    {

    }

    Application::~Application()
    {
        
    }

    int Application::run(unsigned int width, unsigned int height, const char* title)
    {
        Awake();
        LOG_INFO("Awake worked correctly");
        GLFWwindow* window;

        /* Initialize the library */
        if (!glfwInit())
        {
            LOG_CRIT("glfw wasn't initialized");
            return -1;
        }
        LOG_INFO("glfw was initialized");
        /* Create a windowed mode window and its OpenGL context */
        window = glfwCreateWindow(width, height, title, NULL, NULL);
        if (!window)
        {
            LOG_CRIT("window wasn't created");
            glfwTerminate();
            return -1;
        }
        LOG_INFO("window was created");

        /* Make the window's context current */
        glfwMakeContextCurrent(window);

        Start();
        LOG_INFO("Start worked correctly");
        /* Loop until the user closes the window */
        while (!glfwWindowShouldClose(window))
        {
            /* Render here */
            //glClear(GL_COLOR_BUFFER_BIT);

            /* Swap front and back buffers */
            glfwSwapBuffers(window);

            /* Poll for and process events */
            glfwPollEvents();
            Update();
        }

        LOG_INFO("programm was stoped");
        glfwTerminate();
        return 0;
    }
}