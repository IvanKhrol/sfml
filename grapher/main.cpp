#include "graphics.hpp"

int main() {
	
	int scrX = 0.95 * GetSystemMetrics(SM_CXSCREEN); //Разрешение экрана по X
	int scrY = 0.95 * GetSystemMetrics(SM_CYSCREEN); //Разрешение экрана по Y
	sf::RenderWindow window(sf::VideoMode(scrX, scrY), "Brand new Grapher");
	
	int firstPlotColor = 0x000000;

	Vector_t firstOrdinate (0.05 * scrX, 0.85 * scrY, 0, -0.8 * scrY);
	Vector_t firstAbscissa (0.05 * scrX, 0.85 * scrY, 0.4 * scrX, 0);
	Plot_t firstPlot(&firstAbscissa, &firstOrdinate,  0, 0, firstPlotColor);


	Vector_t secondOrdinate (0.55 * scrX, 0.85 * scrY, 0, -0.8 * scrY);
	Vector_t secondAbscissa (0.55 * scrX, 0.85 * scrY, 0.4 * scrX, 0);
	Plot_t secondPlot(&secondAbscissa, &secondOrdinate, 0, 0, firstPlotColor);
	
	
	while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::White);
		firstPlot.Draw(&window);
		secondPlot.Draw(&window);
        window.display();
    }

    return 0;
}
