#include <cstdlib>
#include <cmath>
#include "grapher.cpp"

int main() {
	
	int scrX = 0.95 * GetSystemMetrics(SM_CXSCREEN); //Разрешение экрана по X
	int scrY = 0.95 * GetSystemMetrics(SM_CYSCREEN); //Разрешение экрана по Y
	sf::RenderWindow window(sf::VideoMode(scrX, scrY), "Brand new Grapher");
	
	int firstPlotColor = 0x000000;

	Vector_t firstOrdinate (0.05 * scrX, 0.85 * scrY, 0.05 * scrX, 0.05 * scrY);
	Vector_t firstAbscissa (0.05 * scrX, 0.85 * scrY, 0.45 * scrX, 0.85 * scrY);
	Plot_t firstPlot(firstOrdinate, firstAbscissa, firstPlotColor);

	Vector_t secondOrdinate (0.55 * scrX, 0.85 * scrY, 0.55 * scrX, 0.05 * scrY);
	Vector_t secondAbscissa (0.55 * scrX, 0.85 * scrY, 0.95 * scrX, 0.85 * scrY);
	
	//Plot_t firstPlot (&firstCentre,  &firstAbscissa,  &firstOrdinate,  0xffffff);
	//Plot_t secondPlot(&secondCentre, &secondAbscissa, &secondOrdinate, 0xffffff);
	
	
	while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::White);

		//firstPlot.Draw(&window);
		//secondPlot.Draw(&window);

        window.display();
    }

    return 0;*/
}
