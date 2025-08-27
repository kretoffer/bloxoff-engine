#include <Application.hpp>
#include <GLFW/glfw3.h>
#include <spdlog/spdlog.h>

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
        spdlog::info("Awake worked correctly");
        GLFWwindow* window;

        /* Initialize the library */
        if (!glfwInit())
            spdlog::error("glfw wasn't initialized");
            return -1;
        spdlog::info("glfw was initialized");
        /* Create a windowed mode window and its OpenGL context */
        window = glfwCreateWindow(width, height, title, NULL, NULL);
        if (!window)
        {
            spdlog::error("window wasn't created");
            glfwTerminate();
            return -1;
        }
        spdlog::info("window was created");

        /* Make the window's context current */
        glfwMakeContextCurrent(window);

        Start();
        spdlog::info("Start worked correctly");
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

        spdlog::info("programm was stoped");
        glfwTerminate();
        return 0;
    }
}