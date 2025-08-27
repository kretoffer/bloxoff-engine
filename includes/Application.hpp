#pragma once

namespace BloxoffEngine {
    class Application {
    public:
        Application();
        virtual ~Application();

        Application(const Application&) = delete;
        Application(Application&&) = delete;
        Application& operator = (const Application&) = delete;
        Application& operator = (Application&&) = delete;

        virtual void Start() {}
        virtual void Awake() {}
        virtual int run(unsigned int width, unsigned int height, const char* title);

        virtual void Update() {}
    };
}