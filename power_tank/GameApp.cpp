#include "GameApp.h"
#include "views/PowerTankView.h"
#include "views/LevelUpView.h"
#include "views/BoidsExampleView.h"
#include "views/TestView.h"
#include "libs/Binder/Binder.h"
#include "Window.h"

void GameApp::Init()
{
//    m_views["main_menu_view"] = std::make_shared<MainMenuView>();
    m_views["game_play_view"] = std::make_shared<PowerTankView>();
    m_views["level_up_view"]  = std::make_shared<LevelUpView>();
    m_views["boids_example_view"]   = std::make_shared<BoidsExampleView>();
    m_views["test_view"] = std::make_shared<TestView>();

    for(auto& p : m_views)
    {
        p.second->Init();
    }

    GetBinder().ConnectSlot("level_up", [this]()
    {
        m_currentView = "level_up_view";
    });

    GetBinder().ConnectSlot("pause_game", [this]()
    {
        pause = !pause;
        GetBinder().DispatchSignal("draw_pause", pause);
    });
}

void GameApp::Update(float dt)
{
    if (pause)
    {
        return;
    }

    m_views.at(m_currentView)->Update(dt);
}

void GameApp::Draw(sf::RenderWindow &window)
{
    m_views.at(m_currentView)->Draw(window);
}

void GameApp::ChangeView(const std::string &viewName)
{
    auto iter = m_views.find(viewName);
    if( iter == m_views.end() )
    {
        return;
    }

    auto view = m_views.at(m_currentView);
    view->Hide();

    m_currentView = viewName;
    m_views.at(m_currentView)->Show();
}
