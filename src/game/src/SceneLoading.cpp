#include <iostream>

#include "SceneLoading.hpp"
#include "AssetsManager.hpp"
#include "Game.hpp"
#include "File.hpp"

SceneLoading::SceneLoading(Window *window)
  : m_window(window)
{
}  

SceneLoading::~SceneLoading()
{
}

void SceneLoading::OnCreate()
{
  AssetsManager::GetInstance().LoadFont("../assets/fonts/GoudyBookletter.dat", true);
  CreateGUI();
}

void SceneLoading::OnDestroy()
{

}

void SceneLoading::Update(float deltaTime)
{
    m_guiManager.Update(deltaTime);

    std::string loadingProcess = "~~ Loading (" + std::to_string(AssetsManager::GetInstance().GetAssetsLoadedCount()) + " / " + std::to_string(AssetsManager::GetInstance().GetAssetsCount()) + ")~~ ";
    m_loadingText -> SetText(loadingProcess);
}

void SceneLoading::LateUpdate(float deltaTime)
{
}
  
void SceneLoading::Draw(Window &window)
{
  m_guiManager.Draw(window);
}

void SceneLoading::CreateGUI()
{
  m_loadingLayout = std::make_shared<GuiLayoutVertical>(m_window);
  m_loadingText = std::make_shared<GuiTextWidget>(m_window);
  m_loadingText -> SetColor(sf::Color::White);
  m_loadingText -> SetCharacterSize(24);
  m_loadingText -> SetText("~~ Loading (0 / 0) --");
  m_loadingText -> SetAlign(GuiAlign::AlignCenter);

  m_loadingLayout -> SetRelativeSize(100, 0);
  m_loadingLayout -> SetRelativePosition(0, 25);
  m_loadingLayout -> AddWidget(m_loadingText);

  m_guiManager.AddLayout(GuiManager::LayoutLevel::Level1, m_loadingLayout);
}