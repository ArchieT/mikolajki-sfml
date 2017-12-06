#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
//#include <cstdlib>
//#include <ctime>
//#include <cmath>

#define N 100000
#define W 800
#define H 600

using namespace std;

void smok(int xs, int ys, sf::RenderWindow &window) {
    long double x = 1, y = 1;
    long int i;
    int a;
    srand(static_cast<unsigned int>(time(nullptr)));
    sf::CircleShape s(1);
    for (i = 0; i < N; i++) {
        a = rand() % 2;
        if (a == 1) {
            x = -0.4 * x - 1;
            y = -0.4 * y + 0.1;
        } else {
            x = 0.76 * x - 0.4 * y;
            y = 0.4 * x + 0.76 * y;
        }
        //putpixel(x*400+xs,y*400+ys,rand()%15);
        s.setPosition(static_cast<float>(x * 400 + xs), static_cast<float>(y * 400 + ys));
        window.draw(s);
        //window.display();
    }
}

void kolko(sf::RenderWindow &window) {
    sf::CircleShape big(300);
    big.setPosition(100,0);
    big.setFillColor(sf::Color(255,50,200,220));
    window.draw(big);
}

typedef std::tuple<double,double> point;
typedef std::tuple<point,point,point> three_points;

void sierpinski(three_points p, sf::RenderWindow &window) {
    sf::Vertex line[4];
    line[0].position = sf::Vector2<double>(p[0][0],p[0][1]);
    line[0].color = sf::Color::Red;
    line[1].position = sf::Vector2<double>(p[1][0],p[1][1]);
    line[1].color = sf::Color::Green;
    line[2].position = sf::Vector2<double>(p[2][0],p[2][1]);
    line[2].color = sf::Color::Blue;
    line[3].position = sf::Vector2<double>(p[3][0],p[3][1]);
    line[3].color = sf::Color::Red;
    sierpinski({{(p[0][0]+p[1][0])/2, (p[0][1]+p[1][1])/2},
               {(p[1][0]+p[2][0])/2, (p[1][1]+p[2][1])/2},
               {(p[2][0]+p[3][0])/2, (p[2][1]+p[3][1])/2}},window);
}

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));
    sf::RenderWindow window(sf::VideoMode(W, H), "SFML");
    window.clear();
    smok(W / 2, H / 2, window);
    kolko(window);
    window.display();
    while (window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
    }
    cin.sync();
    cin.get();
    return 0;
}