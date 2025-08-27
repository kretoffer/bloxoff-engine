#include <Application.hpp>
#include <memory>

class MyApp: public BloxoffEngine::Application
{

};

int main()
{
    auto app = std::make_unique<MyApp>();

    int returnCode = app -> run(1024, 512, "hello");

    return returnCode;
}