#pragma once
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include "../utils/FontMgr.h"
#include <functional>

class LevelUpMenu
{
public:
    struct PassiveSkillStruct
    {
        sf::Text skillText;
        sf::Sprite sprite;
        sf::RectangleShape shape;
        std::function<void()> sendOnUpdate = nullptr;
    };
    void Init();
    void HandlEvent(sf::Event event);
    void Draw(sf::RenderWindow& window);
    void RefreshColors();

private:
    void InitResources();
    void connectSignals();
    void setShape();
    void setText(sf::Text& text,
                 const sf::Color& color = sf::Color::Black,
                 const sf::Vector2f& scale = {0.7f,0.7f} );
private:
    int totalPoints = 0;
    sf::Text levelPoints;
    std::vector<PassiveSkillStruct> skillsContainer;
};
