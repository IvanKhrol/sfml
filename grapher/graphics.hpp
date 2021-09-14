#include <SFML/Graphics.hpp>
#include <Windows.h>

#include <iostream>
#include <cmath>

#include "vector.hpp"

sf::VertexArray *CreateSegment(Point_t *First, Point_t *Second, int color);
sf::VertexArray *CreateSegment (Vector_t *vector, int color);

void DrowVector(Vector_t *vector, sf::RenderWindow *window, int color, double fracion);

class Plot_t {
	public:
		Draw();

	private:
		Vector_t *Ordinate;
		Vector_t *Abscissa;
		int MaxElemX;
		int MaxElemY;
		int Color;
};

sf::VertexArray *CreateSegment (Point_t *First, Point_t *Second, int color) {
	sf::VertexArray *segment = nullptr;
	try {
		segment = new sf::VertexArray(sf::Lines, 2);
	}
	catch (std::bad_alloc) {
		perror("Bad allocation");
	}
	(*segment)[0].position = sf::Vector2f(First->x,   First->y);
	(*segment)[0].color = sf::Color(color & 0xFF0000, color & 0xFF00, color & 0xFF);
	
	(*segment)[1].position = sf::Vector2f(Second->x, Second->y);
	(*segment)[1].color = sf::Color(color & 0xFF0000, color & 0xFF00, color & 0xFF);
	return segment;
}

void DrawVector(Vector_t *vector, sf::RenderWindow *window,int color, double fraction) {
	double lambda = (fraction != 1) ? fraction / (1 - fraction) : 1;

	Point_t endingPoint  (vector->GetX() + vector->GetStartingPoint()->x,
					 	  vector->GetY() + vector->GetStartingPoint()->y);
	Point_t startingPoint(vector->GetStartingPoint()->x, 
						  vector->GetStartingPoint()->y);

	Vector_t firstPart (endingPoint, (startingPoint.x + lambda * endingPoint.x) / (1 + lambda), 
						  			 (startingPoint.y + lambda * endingPoint.y) / (1 + lambda));
	Vector_t secondPart(endingPoint, (startingPoint.x + lambda * endingPoint.x) / (1 + lambda), 
									 (startingPoint.y + lambda * endingPoint.y) / (1 + lambda)); 
	firstPart.RightRotate(M_PI / 6);
	secondPart.RightRotate(M_PI / 3);

	Point_t result_1(firstPart.GetX()  + firstPart.GetStartingPoint()->x,
					 firstPart.GetY()  + firstPart.GetStartingPoint()->y);
	Point_t result_2(secondPart.GetX() + secondPart.GetStartingPoint()->x,
					 secondPart.GetY() + secondPart.GetStartingPoint()->y);

	sf::VertexArray *segmentArrow1 = CreateSegment(firstPart.GetStartingPoint() , &result_1   , color);
	sf::VertexArray *segmentArrow2 = CreateSegment(secondPart.GetStartingPoint(), &result_2   , color);
	sf::VertexArray *segmentMain   = CreateSegment(&startingPoint				, &endingPoint, color);

	window->draw(*segmentArrow1);
	window->draw(*segmentArrow2);
	window->draw(*segmentMain);

	delete segmentArrow1;
	delete segmentArrow2;
	delete segmentMain;
}

int main() {
	sf::RenderWindow window(sf::VideoMode(1000, 1000), "Brand new Grapher");
	Vector_t result(100, 100, 100, 0);
	while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::White);

		DrawVector(&result, &window, 0x000000, 0.2);

        window.display();
    }
	return 0;
}