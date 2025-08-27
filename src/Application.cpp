#include <Application.hpp>
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
        GLFWwindow* window;

        /* Initialize the library */
        if (!glfwInit())
            return -1;

        /* Create a windowed mode window and its OpenGL context */
        window = glfwCreateWindow(width, height, title, NULL, NULL);
        if (!window)
        {
            glfwTerminate();
            return -1;
        }

        /* Make the window's context current */
        glfwMakeContextCurrent(window);

        Start();
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

        glfwTerminate();
        return 0;
    }
}