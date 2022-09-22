#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

#define CIRCLE_RADIUS   100.f

int main()
{
	int x = 0, y = 0;

	
	// 마우스 이동시 따라 움직일 Circle 객체

	CircleShape circle_shape(CIRCLE_RADIUS);
	circle_shape.setFillColor(Color::Green);

	circle_shape.setRadius(CIRCLE_RADIUS);
	circle_shape.setOutlineColor(sf::Color::Red);
	//circle_shape.getOutlineThickness(20);
	circle_shape.setPosition(x, y);

	cout << "프로그램이 시작되었습니다." << endl;

	//화면 크기, 캡션 이름 설정
	RenderWindow app(VideoMode(504, 504), "https://maincodes.tistroy.com/");
	app.setFramerateLimit(60); //프레임 비율 설정
	
	while (app.isOpen())
	{
		Event event;

		while (app.pollEvent(event))
		{
			if (event.type == Event::EventType::Closed)
			{
				app.close();
				cout << "프로그램이 종료되었습니다." << endl;
			}

			// 마우스 눌림 (Pressed) 이벤트
			if (event.type == Event::MouseButtonPressed)
			{
				switch (event.key.code)
				{
					case Mouse::Left:
					{
						circle_shape.setFillColor(Color::Yellow);
						Vector2i pos = Mouse::getPosition(app);
						cout << "왼쪽 버튼 눌림 : pos.x = " << pos.x << " pos.y = " << pos.y << endl;
						break;
					}

					case Mouse::Right:
					{
						circle_shape.setFillColor(Color::Magenta);
						Vector2i pos = Mouse::getPosition(app);
						cout << "오른쪽 버튼 눌림 : pos.x = " << pos.x << " pos.y = " << pos.y << endl;
						break;
					}
				
					case Mouse::Middle:
					{
						circle_shape.setFillColor(Color::Black);
						Vector2i pos = Mouse::getPosition(app);
						cout << "중간 버튼 눌림 : pos.x = " <<  pos.x << " pos.y = " << pos.y << endl;
						break;
					}
				}
			}

			//마우스 버튼 똄 이벤트
			if (event.type == Event::MouseButtonReleased)
			{
				switch (event.key.code)
				{
					case Mouse::Left: 
					{
						Vector2i pos = Mouse::getPosition(app);
						cout << "왼쪽 버튼 뗌 : pos.x = " << pos.x << " pos.y = " << pos.y << endl;
						circle_shape.setFillColor(Color::Green);
						break;
					}
					case Mouse::Right:
					{
						Vector2i pos = Mouse::getPosition(app);
						cout << "오른쪽 버튼 뗌 : pos.x = " << pos.x << " pos.y = " << pos.y << endl;
						circle_shape.setFillColor(Color::Green);
						break;
					}
					case Mouse::Middle:
					{
						Vector2i pos = Mouse::getPosition(app);
						cout << "중간 버튼 뗌 : pos.x = " << pos.x << " pos.y = " << pos.y << endl;
						circle_shape.setFillColor(Color::Green);
						break;
					}
				}
			}

			// 마우스 움직임 이벤트
			switch (event.type)
			{
				case Event::MouseMoved: 
				{
					Vector2i pos = Mouse::getPosition(app);
					cout << "이동 : pos.x = " << pos.x << " pos.y = " << pos.y << endl;
					x = pos.x;
					y = pos.y;
					break;
				}
				
				case Event::MouseWheelMoved: 
				{
					Vector2i pos = Mouse::getPosition(app);
					cout << "휠 이동 : pos.x = " << pos.x << " pos.y = " << pos.y << endl;
					break;
				}

				case Event::MouseWheelScrolled:
				{
					Vector2i pos = Mouse::getPosition(app);
					cout << "휠 스크롤 : pos.x = " << pos.x << " pos.y = " << pos.y << endl;
					break;
				}
			}
		}

		// 배경화면 흰색
		app.clear(Color::White);

		//Circloe 위치 보정
		circle_shape.setPosition(Vector2f(x - 100.f, y - 100.f));
		app.draw(circle_shape);

		//프레임을 스크린에 출력
		app.display();
	}
	
	return 0;
}