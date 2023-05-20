#pragma once

#include "Input/KeyboardInput.hpp"
#include "Input/MouseInput.hpp"

class EventHandler
{

public:

  ~EventHandler();

  static EventHandler &GetInstance();
  KeyboardInput &GetKeyboardInput();
  MouseInput &GetMouseInput();

  void ProcessEvent(const sf::Event &event);

private:

  EventHandler();

private:

  KeyboardInput m_keyboardInput;
  MouseInput m_mouseInput;

  static std::unique_ptr<EventHandler> s_instance;

};