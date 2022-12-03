#include <iostream>

#include "FileLog.hpp"
#include "ConsoleLog.hpp"
#include "EventHandler.hpp"

std::unique_ptr<EventHandler> EventHandler::s_instance = nullptr;

EventHandler::EventHandler()
{
}

EventHandler::~EventHandler()
{
}

EventHandler &EventHandler::GetInstance()
{
  if (EventHandler::s_instance == nullptr)
  {
    EventHandler::s_instance = std::unique_ptr<EventHandler>(new EventHandler);
  }

  return *s_instance;
}

// FIXME: Fix C4715 warning.

KeyboardInput &EventHandler::GetKeyboardInput()
{
  if (s_instance == nullptr)
  {
    FILE_LOG_ERROR("debug.txt", "[EventHandler] You've to use GetKeyboardInput on instance of EventHandler.");
  }
  else
  {
    return m_keyboardInput;
  }
}

MouseInput &EventHandler::GetMouseInput()
{
  if (s_instance == nullptr)
  {
    FILE_LOG_ERROR("debug.txt", "[EventHandler] You've to use GetKeyboardInput on instance of EventHandler.");
  }
  else
  {
    return m_mouseInput;
  }
}

void EventHandler::ProcessEvent(const sf::Event &event)
{
  if (event.type == sf::Event::KeyPressed)
  {
    m_keyboardInput.UpdateKeyPressed(event.key.code);
  }
  
  if (event.type == sf::Event::KeyReleased)
  {
    m_keyboardInput.UpdateKeyReleased(event.key.code);
  }

  if (event.type == sf::Event::MouseButtonPressed)
  {
    m_mouseInput.UpdateKeyPressed(event.mouseButton.button);
  }

  if (event.type == sf::Event::MouseButtonReleased)
  {
    m_mouseInput.UpdateKeyReleased(event.mouseButton.button);
  }

  if (event.type == sf::Event::LostFocus)
  {
    CONSOLE_LOG_INFO("[EventHandler] Reporting that Window has lost focus.");

    /*
    TODO: Implement a game freeze, and show of the pause menu when it will be implemented.
    */

  }

  if (event.type == sf::Event::GainedFocus)
  {
    CONSOLE_LOG_INFO("[EventHandler] Reporting that Window has gained focus.");

    /*
    TODO: Unfreeze the game.
    */

  }

  /*
  TODO: Add support for joysticks.
  */

}