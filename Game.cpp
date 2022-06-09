#include "Game.h"

inline sf::Vector2f FindMouseCoords(sf::RenderWindow* windowToFindCursorPosition)
{
    return sf::Vector2f(windowToFindCursorPosition->mapPixelToCoords
    (sf::Vector2i
    (sf::Mouse::getPosition(*windowToFindCursorPosition).x,
        sf::Mouse::getPosition(*windowToFindCursorPosition).y)
    ).x,
        windowToFindCursorPosition->mapPixelToCoords
        (sf::Vector2i
        (sf::Mouse::getPosition(*windowToFindCursorPosition).x,
            sf::Mouse::getPosition(*windowToFindCursorPosition).y)
        ).y);
}

void Game::Run()
{
    sf::RenderWindow window(sf::VideoMode(900, 900), "SFML works!");
    window.setFramerateLimit(60);

    sf::Texture PoleTexture;
    PoleTexture.loadFromFile("Pole.png");
    sf::Sprite PoleSprite(PoleTexture);

    sf::Texture XTexture;
    XTexture.loadFromFile("X.png");
    sf::Sprite XSprite(XTexture);
    XSprite.setOrigin(sf::Vector2f(140, 140));

    sf::Texture OTexture;
    OTexture.loadFromFile("O.png");
    sf::Sprite OSprite(OTexture);
    OSprite.setOrigin(sf::Vector2f(140, 140));

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
            {
                sf::Vector2f MouseCoords = FindMouseCoords(&window);
                // Change step
                bool WasStep = false;

                if (MouseCoords.x < 300 && MouseCoords.y < 300 && Cells[0] == 0)
                {
                    if (IsFirstPlayerStep)
                        Cells[0] = 1;
                    else Cells[0] = 2;
                    WasStep = true;
                }
                   
                if (MouseCoords.x < 300 && MouseCoords.y >= 300 && MouseCoords.y < 600 && Cells[1] == 0)
                {
                    if (IsFirstPlayerStep)
                        Cells[1] = 1;
                    else Cells[1] = 2;
                    WasStep = true;
                }

                if (MouseCoords.x < 300 && MouseCoords.y >= 600 && Cells[2] == 0)
                {
                    if (IsFirstPlayerStep)
                        Cells[2] = 1;
                    else Cells[2] = 2;
                    WasStep = true;
                }

                if (MouseCoords.x >= 300 && MouseCoords.x < 600 && MouseCoords.y < 300 && Cells[3] == 0)
                {
                    if (IsFirstPlayerStep)
                        Cells[3] = 1;
                    else Cells[3] = 2;
                    WasStep = true;
                }

                if (MouseCoords.x >= 300 && MouseCoords.x < 600 && MouseCoords.y >= 300 && MouseCoords.y < 600 && Cells[4] == 0)
                {
                    if (IsFirstPlayerStep)
                        Cells[4] = 1;
                    else Cells[4] = 2;
                    WasStep = true;
                }

                if (MouseCoords.x >= 300 && MouseCoords.x < 600 && MouseCoords.y >= 600 && Cells[5] == 0)
                {
                    if (IsFirstPlayerStep)
                        Cells[5] = 1;
                    else Cells[5] = 2;
                    WasStep = true;
                }
            
                if (MouseCoords.x >= 600 && MouseCoords.y < 300 && Cells[6] == 0)
                {
                    if (IsFirstPlayerStep)
                        Cells[6] = 1;
                    else Cells[6] = 2;
                    WasStep = true;
                }

                if (MouseCoords.x >= 600 && MouseCoords.y >= 300 && MouseCoords.y < 600 && Cells[7] == 0)
                {
                    if (IsFirstPlayerStep)
                        Cells[7] = 1;
                    else Cells[7] = 2;
                    WasStep = true;
                }

                if (MouseCoords.x >= 600 && MouseCoords.y >= 600 && Cells[8] == 0)
                {
                    if (IsFirstPlayerStep)
                        Cells[8] = 1;
                    else Cells[8] = 2;
                    WasStep = true;
                }
            
                if (WasStep)
                {
                    if (IsFirstPlayerStep)
                        IsFirstPlayerStep = false;
                    else IsFirstPlayerStep = true;

                    // Check someone win
                    if (Cells[0] * Cells[1] * Cells[2] == 1 || Cells[3] * Cells[4] * Cells[5] == 1 || Cells[6] * Cells[7] * Cells[8] == 1 ||
                        Cells[0] * Cells[3] * Cells[6] == 1 || Cells[1] * Cells[4] * Cells[7] == 1 || Cells[2] * Cells[5] * Cells[8] == 1 ||
                        Cells[0] * Cells[4] * Cells[8] == 1 || Cells[2] * Cells[4] * Cells[6] == 1 ||
                        Cells[0] * Cells[1] * Cells[2] == 8 || Cells[3] * Cells[4] * Cells[5] == 8 || Cells[6] * Cells[7] * Cells[8] == 8 ||
                        Cells[0] * Cells[3] * Cells[6] == 8 || Cells[1] * Cells[4] * Cells[7] == 8 || Cells[2] * Cells[5] * Cells[8] == 8 ||
                        Cells[0] * Cells[4] * Cells[8] == 8 || Cells[2] * Cells[4] * Cells[6] == 8)
                    {
                        IsFirstPlayerStep = true;
                        for (int i = 0; i < 9; i++)
                        {
                            Cells[i] = 0;
                        }
                    }

                    // Check ability of continue game
                    bool IsFull = true;
                    for (int i = 0; i < 9; i++)
                    {
                        if (Cells[i] == 0)
                            IsFull = false;
                    }

                    if (IsFull)
                    {
                        IsFirstPlayerStep = true;
                        for (int i = 0; i < 9; i++)
                        {
                            Cells[i] = 0;
                        }
                    }
                }
            }
        }

        window.clear();
        window.draw(PoleSprite);
        for (int i = 0; i < 9; i++)
        {
            switch (Cells[i])
            {
            case 1:
                XSprite.setPosition(150 + 300 * (i / 3), 150 + 300 * (i % 3));
                window.draw(XSprite);
                break;
            case 2:
                OSprite.setPosition(150 + 300 * (i / 3), 150 + 300 * (i % 3));
                window.draw(OSprite);
                break;
            }
        }
        window.display();
    }
}
