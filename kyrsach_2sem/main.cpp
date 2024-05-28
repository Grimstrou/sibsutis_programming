#include <SFML/Graphics.hpp>
#include <vector>
#include "zombie.h"
#include "pushka.h"
#include "pula.h"

int z_1[] = { 140, 300, 460, 620 };
int p_1[] = { 160, 320, 480, 640 };

using namespace sf;

void InitText(Text& mtext, float xpos, float ypos, String str, int size_font = 60,
    Color menu_text_color = Color::White, int bord = 0, Color border_color = Color::Black);

int main()
{
    RenderWindow window(sf::VideoMode(1280, 720), L"plants vs zombies by Артемий"); //создание окна
    int ras = 0;
    std::vector<zombie> z;
    for (int i = 140; i < 700; i += 160) {
        z.push_back(zombie(i));
    }

    std::vector<pushka> p;
    for (int i = 140; i < 700; i += 160) {
        p.push_back(pushka(i));
    }
    p[0].swap(140);
    std::vector <pula> w;

    sf::Clock clock; // создать объект clock
    sf::Time kd = clock.getElapsedTime();
    float kkd = clock.getElapsedTime().asSeconds();

    int money = 0;

    //панель покупок
    Texture TexturInfoPanel;
    TexturInfoPanel.loadFromFile("Image/panel.png");
    RectangleShape GameInfoPanel(Vector2f(1280, 113));
    GameInfoPanel.setTexture(&TexturInfoPanel);
    GameInfoPanel.setPosition(Vector2f(0, 0));
    Texture kolba;
    kolba.loadFromFile("Image/kolba.png");
    RectangleShape Pkolba(Vector2f(170, 110));
    Pkolba.setTexture(&kolba);
    Pkolba.setPosition(Vector2f(0, 0));


    //Игровое поле 
    Texture TexturePole;
    TexturePole.loadFromFile("Image/icon.jpg");
    RectangleShape gamingBackground(Vector2f(1280, 720));
    gamingBackground.setTexture(&TexturePole);

    Font font;
    font.loadFromFile("D:\\sfml_project1\\gamesfml\\Roboto-Black.ttf");
    Text mon(std::to_string(money), font, 40);

    mon.setPosition(1150, 45);
    mon.setFillColor(Color::Red);

    // Текст сообщения о проигрыше
    Text loseText("You are lose", font, 80);
    loseText.setPosition(400, 300);
    loseText.setFillColor(Color::Red);

    //игровой цикл
    while (window.isOpen())
    {
        sf::Event event;
        //привязка игрового процесса к времени

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed) {
                if ((event.key.code == Keyboard::Space)) {
                    sf::Time new_time = clock.getElapsedTime();
                    if (new_time.asSeconds() - kd.asSeconds() > 1) {
                        if (ras == 0)
                            w.push_back(pula(160));
                        else if (ras == 1)
                            w.push_back(pula(320));
                        else if (ras == 2)
                            w.push_back(pula(480));
                        else if (ras == 3)
                            w.push_back(pula(640));
                        kd = new_time;

                    }
                }
                if ((event.key.code == Keyboard::W)) {
                    if (ras > 0) {
                        p[ras].swap(z_1[ras]);
                        ras -= 1;
                        p[ras].swap(z_1[ras]);
                    }
                }
                if ((event.key.code == Keyboard::S)) {
                    if (ras < 3) {
                        p[ras].swap(z_1[ras]);
                        ras += 1;
                        p[ras].swap(z_1[ras]);
                    }
                }
            }
        }

        window.clear();
        window.draw(gamingBackground);

        for (int i = 0; i < w.size(); i++) {
            for (int j = 0; j < z.size(); j++) {
                if (w[i].getImage().getGlobalBounds().intersects(z[j].getImage().getGlobalBounds())) {
                    if (z[j].getHealth() == 0) {
                        money += 20;
                        mon.setString(std::to_string(money));
                        z.erase(z.begin() + j);
                        int rand_z = rand() % 4;
                        z.push_back(zombie(z_1[rand_z]));
                        break;
                    }
                    else {
                        z[j].damage();
                        w[i].del();

                        w.erase(w.begin() + i);
                        break;
                    }
                }
            }
        }

        if (Mouse::isButtonPressed(Mouse::Left)) {
            Vector2f t = window.mapPixelToCoords(Mouse::getPosition(window));
            if (Pkolba.getGlobalBounds().contains(t)) {
                if (money >= 40) {

                    for (int i = 0; i < z.size(); i++) {
                        z[i].del();
                    }
                    z.clear();

                    for (int i = 140; i < 700; i += 160) {
                        z.push_back(zombie(i));
                    }
                    money -= 40;
                    mon.setString(std::to_string(money));
                }
            }

        }

        for (int i = 0; i < w.size(); i++) {

            if (w[i].getX() > 1281) {
                w[i].del();
                w.erase(w.begin() + i);
                break;
            }
        }

        for (int i = 0; i < w.size(); i++) {
            w[i].move();
            window.draw(w[i].getImage());
        }

        for (int i = 0; i < p.size(); i++) {
            window.draw(p[i].getImage());
        }
        float rrr;
        bool flag = true;
        for (int i = 0; i < z.size(); i++) {
            for (int j = 0; j < p.size(); j++) {
                rrr = clock.getElapsedTime().asSeconds();
                if (z[i].getImage().getGlobalBounds().intersects(p[j].getImage().getGlobalBounds())) {
                    if (rrr - kkd > 5) {
                        flag = false;
                        money -= 15;
                        mon.setString(std::to_string(money));

                    }
                }
            }
        }
        if (!flag) {
            kkd = rrr;
        }
        for (int i = 0; i < z.size(); i++) {
            bool flag = true;
            for (int j = 0; j < p.size(); j++) {
                if (z[i].getImage().getGlobalBounds().intersects(p[j].getImage().getGlobalBounds())) {
                    flag = false;

                    break;
                }
            }
            if (flag) {
                z[i].move();
            }
            window.draw(z[i].getImage());
            if (z[i].getX() < 0) {
                z[i].del();
                z.erase(z.begin() + i);
                int rand_z = rand() % 4;
                z.push_back(zombie(z_1[rand_z]));
                break;
            }
        }

        if (money <= -20) {
            // Отображаем сообщение о проигрыше
            window.clear();
            window.draw(gamingBackground);
            window.draw(loseText);
            window.display();

            // Ждем нажатия клавиши для закрытия окна
            while (true) {
                while (window.pollEvent(event)) {
                    if (event.type == sf::Event::Closed || event.type == sf::Event::KeyPressed) {
                        window.close();
                        break;
                    }
                }
                if (!window.isOpen()) break;
            }
            break;
        }

        window.draw(GameInfoPanel);

        window.draw(Pkolba);
        window.draw(mon);

        window.display();
    }
    return 0;
}
