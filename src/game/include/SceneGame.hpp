#pragma once

#include <SFML/Graphics.hpp>

#include "Scene.hpp"
#include "KeyboardInput.hpp"
#include "Object.hpp"
#include "C_Sprite.hpp"
#include "C_KeyboardMovement.hpp"
#include "C_Animation.hpp"
#include "C_Velocity.hpp"
#include "C_MovementAnimation.hpp"

class SceneGame : public Scene
{

public:

  SceneGame();
  ~SceneGame();

  void OnCreate() override;
  void OnDestroy() override;

  void Update(float deltaTime) override;
  void Draw(Window &window) override;

private:

  std::shared_ptr<Object> m_player;

  KeyboardInput m_keyboardInput;

  sf::CircleShape m_testShape;

};
