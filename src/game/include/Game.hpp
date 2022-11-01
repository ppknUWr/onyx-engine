#pragma once

#include "Window.hpp"
#include "SceneStateMachine.hpp"
#include "SceneGame.hpp"
#include "SceneMenu.hpp"
#include "SceneLoading.hpp"

class Game
{

public:

  Game();
  ~Game();

  void GameLoop();

  void Update();
  void LateUpdate();
  void Draw();
  void CalculateDeltaTime();
  bool IsRunning() const;

  void CreateScenesAfterLoading();

  void LoadAssets();

private:

  Window m_window;
  SceneStateMachine m_sceneManager;

  sf::Clock m_clock;
  float m_deltaTime;
};
