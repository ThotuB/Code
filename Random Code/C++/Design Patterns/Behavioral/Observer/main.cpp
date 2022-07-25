#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

class EventListener {
public:
    virtual void onEvent() = 0;
};

class EventManager {
private:
    std::unordered_map<std::string, EventListener*> events;

public:
    void addEvent(std::string on, EventListener *listener) {
        events[on] = listener;
    }

    void removeEvent(std::string on) {
        events.erase(on);
    }

    void triggerEvent(std::string on) {
        events[on]->onEvent();
    }
};

int main() {}