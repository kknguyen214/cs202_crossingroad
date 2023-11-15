#include "LoadRandom.h"

int randomNum(int range)
{
	random_device rd;
	mt19937 generator(rd());

	uniform_int_distribution<int> distribution(1, range);
	return distribution(generator);
}

void delayFunction() {
    // Simulate a function that takes one second to execute
    auto start = std::chrono::high_resolution_clock::now();
	while (std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - start).count() < 50) {
        // Do some non-blocking work here
    }
}

void loadGrass()
{
    sf::RenderWindow window(sf::VideoMode(1280, 640), "MyProgram");
    window.setFramerateLimit(60);
    auto start = std::chrono::high_resolution_clock::now();


    Sprite grass[11];
    Texture _grass[11];

    Sprite grassTmp;

    for (int i = 0; i < 11; i++)
    {
        int rd = randomNum(4);
        string pos = "resource/tiles/grass";
        pos += to_string(rd);
        pos += ".png";
        _grass[i].loadFromFile(pos);
        grassTmp.setTexture(_grass[i]);
        grass[i] = grassTmp;
        grass[i].setPosition(Vector2f(0, i * 64));
        //  window.draw(grass);
    }

    //  grass.setPosition(Vector2f(0, 0));
    //  grass.scale(Vector2f(5, 2));

    while (window.isOpen())
    {
        window.clear();
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) window.close();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) window.close();
        }

        for (int i = 0; i < 11; i++)
        {
            if (grass[i].getPosition().y >= 639) {
                grass[i].setPosition(Vector2f(0, -63));
            }
            else
                grass[i].setPosition(Vector2f(0, (grass[i].getPosition().y + 1)));

            window.draw(grass[i]);
        }

        window.display();

        while (std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - start).count() < 100) {}
    }

}
