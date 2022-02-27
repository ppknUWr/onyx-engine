#include <iostream>

#include "Window.hpp"
#include "MouseInput.hpp"

Window::Window(const std::string &windowName)
  : m_window(sf::VideoMode(800, 600, 32), windowName, sf::Style::Titlebar)
{
}

Window::~Window() {}

void Window::Update()
{
  sf::Event event;

  if (m_window.pollEvent(event))
  {
    if (event.type == sf::Event::Closed)
    {
      m_window.close();
    }

    if (event.type == sf::Event::MouseButtonReleased)
    {
      if (event.key.code == sf::Mouse::Left)
      {
        std::cout << "[INFO] Left was released.\n";
        MouseInput::GetInstance().SetMouseReleasedEvent(MouseInput::MouseButton::Left, true);
      }
    }
  }
}

void Window::BeginDraw()
{
  m_window.clear(sf::Color::Black);
}

void Window::Draw(const sf::Drawable &drawable)
{
  m_window.draw(drawable);
}

void Window::EndDraw()
{
  m_window.display();
}

void Window::ProcessEvent(sf::Event &event)
{
}

bool Window::IsOpen() const
{
  return m_window.isOpen();
}

sf::RenderWindow* Window::GetWindow()
{
  return &m_window;
}

sf::Vector2u Window::GetWindowSize() const
{
  return m_window.getSize();
}

void Window::Exit()
{
  m_window.close();
}
