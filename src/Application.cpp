#include <Application.hpp>
#include <Logger.hpp>
#include <Window.hpp>

namespace BloxoffEngine {
    Application::Application()
    {
        Awake();
    }

    Application::~Application()
    {
        
    }

    int Application::run(unsigned int width, unsigned int height, const char* title)
    {
        m_pWindow = std::make_unique<Window>(title, width, height);
        m_pWindow->set_event_callback(
            [](Event& event)
            {
                LOG_INFO("[EVENT]");
            }
        );

        while (true)
        {
            m_pWindow->update();
            Update();
        }
        

        return 0;
    }
}