#include <SFML/Graphics.hpp>
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

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));
    sf::RenderWindow window(sf::VideoMode(W, H), "SFML");
    window.clear();
    smok(W / 2, H / 2, window);
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