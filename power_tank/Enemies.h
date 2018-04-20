#pragma once
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Graphics/CircleShape.hpp"
#include "Ball.h"
#include "EnemyGotHit.h"

class Enemies
{
public:
    void Init();
    void Update(float dt);
    std::vector<Ball>& GetEnemies();
    void Draw(sf::RenderWindow& window);
private:
    EnemyGotHit m_enemyGotHit;

    static constexpr int health = 5;
    static constexpr int max_split_count = 3;
    static constexpr float spawn_rate = 1000.0f;
    static constexpr float max_split_radius = 10.0f;

    float spawn_elapsed = 0.0f;
    int max_enemies = 30;

    void cleanUpDeadEnemies();
    bool HandleSpawn(const Ball& self);
    void SpawnEnemy(glm::vec2 pos, float r);
    void SpawnEnemy();

    std::vector<Ball> m_enemies;
};
