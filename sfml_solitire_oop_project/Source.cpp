//SFML VERSION 2.6.1 (x64) for visual studio 2022
#include <sstream>
#include <SFML/Graphics.hpp>    
#include <iostream>

using namespace std;

sf::RenderWindow window(sf::VideoMode(1280, 720), "Solitaire");

void background()
{
	sf::RectangleShape bkgrndimg1(sf::Vector2f(1280, 720));
	sf::Texture bkgrndtex1;
	bkgrndtex1.loadFromFile("Screenshot (19).png");
	bkgrndimg1.setTexture(&bkgrndtex1);
	window.draw(bkgrndimg1);
}

void emptyslot(int x, int y)
{
	sf::RectangleShape card;
	card.setPosition(sf::Vector2f(x, y));
	card.setSize(sf::Vector2f(120, 190));
	card.setFillColor(sf::Color::Transparent);
	card.setOutlineThickness(5);
	card.setOutlineColor(sf::Color::Black);
	window.draw(card);
}



class PlayingCard
{
private:
	int rank; //integer 1 – 13
	int suit; //integer 0 – 3
	char color; // red or black - ‘b’ for black , ‘r’ for red
	bool faceup;
	bool top;
public:
	static const int Diamond;
	static const int Heart;
	static const int Spade;
	static const int Club;

	PlayingCard()
	{
		rank = 0;
		suit = 0;
		color = ' ';
		faceup = true;
		top = -1;
	}

	PlayingCard(int rank, int suit)
	{
		this->rank = rank;
		this->suit = suit;
		color = ' ';
		if (suit == 2 || suit == 3)
		{
			color = 'b';
		}
		else if (suit == 0 || suit == 1)
		{
			color = 'r';
		}
		faceup = true;
		top = true;
	}

	PlayingCard(const PlayingCard& pl)
	{
		rank = pl.rank;
		suit = pl.suit;
		color = pl.color;
		faceup = pl.faceup;
		top = pl.top;
	}

	int getsuit()
	{
		return suit;
	}

	int getrank()
	{
		return rank;
	}

	char getcolor()
	{
		return color;
	}

	bool isFaceUp()
	{
		return faceup;
	}

	void setFaceUp(bool fc)
	{
		faceup = fc;
	}

	bool istop()
	{
		return top;
	}

	void settop(bool t)
	{
		top = t;
	}

	void display(float x, float y)//x=200  ,  y=100
	{
		sf::RectangleShape card;
		sf::Vector2f rectanglePosition(x, y);
		card.setPosition(rectanglePosition);
		card.setSize(sf::Vector2f(120, 190));
		card.setFillColor(sf::Color::White);
		card.setOutlineColor(sf::Color(255, 255, 255));

		window.draw(card);
		sf::RectangleShape back(sf::Vector2f(120.0f, 190.0f));
		back.setPosition(rectanglePosition);
		sf::Texture backtex;
		backtex.loadFromFile("Screenshot 2025-06-13 042831.png");
		back.setTexture(&backtex);
		window.draw(back);

		if (faceup == false)
		{
			window.draw(card);
			sf::RectangleShape back(sf::Vector2f(120.0f, 190.0f));
			sf::Vector2f rectanglePosition(x, y);
			back.setPosition(rectanglePosition);
			sf::Texture backtex;
			backtex.loadFromFile("Screenshot (28).png");
			back.setTexture(&backtex);
			window.draw(back);

		}


		else if (faceup == true)
		{
			if (suit == 0)
			{
				window.draw(card);
				if (rank != 10)
				{
					sf::RectangleShape diamondimg1(sf::Vector2f(25.0f, 25.0f));
					diamondimg1.setPosition(x + 22, y + 6);
					sf::Texture diamondtex1;
					diamondtex1.loadFromFile("IMG-20230507-WA0005.jpg");
					diamondimg1.setTexture(&diamondtex1);

					sf::RectangleShape diamondimg2(sf::Vector2f(25.0f, 25.0f));
					diamondimg2.setPosition(x + 73, y + 156);
					sf::Texture diamondtex2;
					diamondtex2.loadFromFile("IMG-20230507-WA0005.jpg");
					diamondimg2.setTexture(&diamondtex2);
					window.draw(diamondimg1);
					window.draw(diamondimg2);

					if (rank >= 2 && rank < 10)
					{
						stringstream s1;
						s1 << rank;

						sf::Font font1;
						font1.loadFromFile("OpenSans-Bold.ttf");
						sf::Text numb1;
						numb1.setFont(font1);
						numb1.setString(s1.str());
						numb1.setFillColor(sf::Color::Red);
						numb1.setCharacterSize(27);
						numb1.setPosition(sf::Vector2f(x + 2, y + 2));

						sf::Font font2;
						font2.loadFromFile("OpenSans-Bold.ttf");
						sf::Text numb2;
						numb2.setFont(font2);
						numb2.setString(s1.str());
						numb2.setFillColor(sf::Color::Red);
						numb2.setCharacterSize(27);
						numb2.setPosition(sf::Vector2f(x + 100, y + 152));

						window.draw(numb1);
						window.draw(numb2);
					}
					if (rank == 1)
					{
						sf::Font font1;
						font1.loadFromFile("OpenSans-Bold.ttf");
						sf::Text numb1;
						numb1.setFont(font1);
						numb1.setString("A");
						numb1.setFillColor(sf::Color::Red);
						numb1.setCharacterSize(27);
						numb1.setPosition(sf::Vector2f(x + 2, y + 2));

						sf::Font font2;
						font2.loadFromFile("OpenSans-Bold.ttf");
						sf::Text numb2;
						numb2.setFont(font2);
						numb2.setString("A");
						numb2.setFillColor(sf::Color::Red);
						numb2.setCharacterSize(27);
						numb2.setPosition(sf::Vector2f(x + 100, y + 152));

						window.draw(numb1);
						window.draw(numb2);
					}
					if (rank == 11)
					{
						sf::RectangleShape diamondj(sf::Vector2f(25.0f, 25.0f));
						diamondj.setPosition(x + 10, y + 33);
						diamondj.setSize(sf::Vector2f(100, 120));
						sf::Texture diamondtexj;
						diamondtexj.loadFromFile("jofDiamond.png");
						diamondj.setTexture(&diamondtexj);
						window.draw(diamondj);

						sf::Font font1;
						font1.loadFromFile("OpenSans-Bold.ttf");
						sf::Text numb1;
						numb1.setFont(font1);
						numb1.setString("J");
						numb1.setFillColor(sf::Color::Red);
						numb1.setCharacterSize(27);
						numb1.setPosition(sf::Vector2f(x + 8, y + 2));

						sf::Font font2;
						font2.loadFromFile("OpenSans-Bold.ttf");
						sf::Text numb2;
						numb2.setFont(font2);
						numb2.setString("J");
						numb2.setFillColor(sf::Color::Red);
						numb2.setCharacterSize(27);
						numb2.setPosition(sf::Vector2f(x + 103, y + 152));

						window.draw(numb1);
						window.draw(numb2);
					}
					if (rank == 12)
					{
						sf::RectangleShape diamondq(sf::Vector2f(25.0f, 25.0f));
						diamondq.setPosition(x + 10, y + 33);
						diamondq.setSize(sf::Vector2f(100, 120));
						sf::Texture diamondtexq;
						diamondtexq.loadFromFile("qofdiamond.png");
						diamondq.setTexture(&diamondtexq);
						window.draw(diamondq);

						sf::Font font1;
						font1.loadFromFile("OpenSans-Bold.ttf");
						sf::Text numb1;
						numb1.setFont(font1);
						numb1.setString("Q");
						numb1.setFillColor(sf::Color::Red);
						numb1.setCharacterSize(27);
						numb1.setPosition(sf::Vector2f(x, y + 2));

						sf::Font font2;
						font2.loadFromFile("OpenSans-Bold.ttf");
						sf::Text numb2;
						numb2.setFont(font2);
						numb2.setString("Q");
						numb2.setFillColor(sf::Color::Red);
						numb2.setCharacterSize(27);
						numb2.setPosition(sf::Vector2f(x + 98, y + 152));

						window.draw(numb1);
						window.draw(numb2);
					}
					if (rank == 13)
					{
						sf::RectangleShape diamondK(sf::Vector2f(25.0f, 25.0f));
						diamondK.setPosition(x + 10, y + 33);
						diamondK.setSize(sf::Vector2f(100, 120));
						sf::Texture diamondtexK;
						diamondtexK.loadFromFile("kofdiamond.png");
						diamondK.setTexture(&diamondtexK);
						window.draw(diamondK);

						sf::Font font1;
						font1.loadFromFile("OpenSans-Bold.ttf");
						sf::Text numb1;
						numb1.setFont(font1);
						numb1.setString("K");
						numb1.setFillColor(sf::Color::Red);
						numb1.setCharacterSize(27);
						numb1.setPosition(sf::Vector2f(x + 2, y + 2));

						sf::Font font2;
						font2.loadFromFile("OpenSans-Bold.ttf");
						sf::Text numb2;
						numb2.setFont(font2);
						numb2.setString("K");
						numb2.setFillColor(sf::Color::Red);
						numb2.setCharacterSize(27);
						numb2.setPosition(sf::Vector2f(x + 100, y + 152));

						window.draw(numb1);
						window.draw(numb2);
					}
				}

				if (rank == 10)
				{
					sf::RectangleShape diamondimg1(sf::Vector2f(25.0f, 25.0f));
					diamondimg1.setPosition(x + 35, y + 6);
					sf::Texture diamondtex1;
					diamondtex1.loadFromFile("IMG-20230507-WA0005.jpg");
					diamondimg1.setTexture(&diamondtex1);

					sf::RectangleShape diamondimg2(sf::Vector2f(25.0f, 25.0f));
					diamondimg2.setPosition(x + 64, y + 156);
					sf::Texture diamondtex2;
					diamondtex2.loadFromFile("IMG-20230507-WA0005.jpg");
					diamondimg2.setTexture(&diamondtex2);
					window.draw(diamondimg1);
					window.draw(diamondimg2);

					stringstream s1;
					s1 << rank;

					sf::Font font1;
					font1.loadFromFile("OpenSans-Bold.ttf");
					sf::Text numb1;
					numb1.setFont(font1);
					numb1.setString(s1.str());
					numb1.setFillColor(sf::Color::Red);
					numb1.setCharacterSize(27);
					numb1.setPosition(sf::Vector2f(x + 2, y + 2));

					sf::Font font2;
					font2.loadFromFile("OpenSans-Bold.ttf");
					sf::Text numb2;
					numb2.setFont(font2);
					numb2.setString(s1.str());
					numb2.setFillColor(sf::Color::Red);
					numb2.setCharacterSize(27);
					numb2.setPosition(sf::Vector2f(x + 89, y + 152));

					window.draw(numb1);
					window.draw(numb2);
				}
			}

			if (suit == 1)
			{
				window.draw(card);
				if (rank != 10)
				{
					sf::RectangleShape heartimg1(sf::Vector2f(25.0f, 25.0f));
					heartimg1.setPosition(x + 22, y + 8);
					sf::Texture hearttex1;
					hearttex1.loadFromFile("IMG-20230507-WA0002.jpg");
					heartimg1.setTexture(&hearttex1);

					sf::RectangleShape heartimg2(sf::Vector2f(25.0f, 25.0f));
					heartimg2.setPosition(x + 73, y + 158);
					sf::Texture hearttex2;
					hearttex2.loadFromFile("IMG-20230507-WA0002.jpg");
					heartimg2.setTexture(&hearttex2);
					window.draw(heartimg1);
					window.draw(heartimg2);

					if (rank >= 2 && rank < 10)
					{
						stringstream s1;
						s1 << rank;

						sf::Font font1;
						font1.loadFromFile("OpenSans-Bold.ttf");
						sf::Text numb1;
						numb1.setFont(font1);
						numb1.setString(s1.str());
						numb1.setFillColor(sf::Color::Red);
						numb1.setCharacterSize(27);
						numb1.setPosition(sf::Vector2f(x + 2, y + 2));

						sf::Font font2;
						font2.loadFromFile("OpenSans-Bold.ttf");
						sf::Text numb2;
						numb2.setFont(font2);
						numb2.setString(s1.str());
						numb2.setFillColor(sf::Color::Red);
						numb2.setCharacterSize(27);
						numb2.setPosition(sf::Vector2f(x + 100, y + 152));

						window.draw(numb1);
						window.draw(numb2);
					}
				}
				if (rank == 1)
				{
					sf::Font font1;
					font1.loadFromFile("OpenSans-Bold.ttf");
					sf::Text numb1;
					numb1.setFont(font1);
					numb1.setString("A");
					numb1.setFillColor(sf::Color::Red);
					numb1.setCharacterSize(27);
					numb1.setPosition(sf::Vector2f(x + 2, y + 2));

					sf::Font font2;
					font2.loadFromFile("OpenSans-Bold.ttf");
					sf::Text numb2;
					numb2.setFont(font2);
					numb2.setString("A");
					numb2.setFillColor(sf::Color::Red);
					numb2.setCharacterSize(27);
					numb2.setPosition(sf::Vector2f(x + 100, y + 152));

					window.draw(numb1);
					window.draw(numb2);
				}

				if (rank == 11)
				{
					sf::RectangleShape heartj(sf::Vector2f(25.0f, 25.0f));
					heartj.setPosition(x + 10, y + 33);
					heartj.setSize(sf::Vector2f(100, 120));
					sf::Texture hearttexj;
					hearttexj.loadFromFile("JofHEART.png");
					heartj.setTexture(&hearttexj);
					window.draw(heartj);


					sf::Font font1;
					font1.loadFromFile("OpenSans-Bold.ttf");
					sf::Text numb1;
					numb1.setFont(font1);
					numb1.setString("J");
					numb1.setFillColor(sf::Color::Red);
					numb1.setCharacterSize(27);
					numb1.setPosition(sf::Vector2f(x + 8, y + 2));

					sf::Font font2;
					font2.loadFromFile("OpenSans-Bold.ttf");
					sf::Text numb2;
					numb2.setFont(font2);
					numb2.setString("J");
					numb2.setFillColor(sf::Color::Red);
					numb2.setCharacterSize(27);
					numb2.setPosition(sf::Vector2f(x + 103, y + 152));

					window.draw(numb1);
					window.draw(numb2);
				}

				if (rank == 12)
				{
					sf::RectangleShape heartq(sf::Vector2f(25.0f, 25.0f));
					heartq.setPosition(x + 10, y + 33);
					heartq.setSize(sf::Vector2f(100, 120));
					sf::Texture hearttexq;
					hearttexq.loadFromFile("Qofheart.png");
					heartq.setTexture(&hearttexq);
					window.draw(heartq);


					sf::Font font1;
					font1.loadFromFile("OpenSans-Bold.ttf");
					sf::Text numb1;
					numb1.setFont(font1);
					numb1.setString("Q");
					numb1.setFillColor(sf::Color::Red);
					numb1.setCharacterSize(27);
					numb1.setPosition(sf::Vector2f(x, y + 2));

					sf::Font font2;
					font2.loadFromFile("OpenSans-Bold.ttf");
					sf::Text numb2;
					numb2.setFont(font2);
					numb2.setString("Q");
					numb2.setFillColor(sf::Color::Red);
					numb2.setCharacterSize(27);
					numb2.setPosition(sf::Vector2f(x + 98, y + 152));

					window.draw(numb1);
					window.draw(numb2);
				}
				if (rank == 13)
				{
					sf::RectangleShape heartK(sf::Vector2f(25.0f, 25.0f));
					heartK.setPosition(x + 10, y + 33);
					heartK.setSize(sf::Vector2f(100, 120));
					sf::Texture hearttexK;
					hearttexK.loadFromFile("kofheart.png");
					heartK.setTexture(&hearttexK);
					window.draw(heartK);

					sf::Font font1;
					font1.loadFromFile("OpenSans-Bold.ttf");
					sf::Text numb1;
					numb1.setFont(font1);
					numb1.setString("K");
					numb1.setFillColor(sf::Color::Red);
					numb1.setCharacterSize(27);
					numb1.setPosition(sf::Vector2f(x + 2, y + 2));

					sf::Font font2;
					font2.loadFromFile("OpenSans-Bold.ttf");
					sf::Text numb2;
					numb2.setFont(font2);
					numb2.setString("K");
					numb2.setFillColor(sf::Color::Red);
					numb2.setCharacterSize(27);
					numb2.setPosition(sf::Vector2f(x + 100, y + 152));

					window.draw(numb1);
					window.draw(numb2);
				}

				else if (rank == 10)
				{
					sf::RectangleShape heartimg1(sf::Vector2f(25.0f, 25.0f));
					heartimg1.setPosition(x + 35, y + 8);
					sf::Texture hearttex1;
					hearttex1.loadFromFile("IMG-20230507-WA0002.jpg");
					heartimg1.setTexture(&hearttex1);

					sf::RectangleShape heartimg2(sf::Vector2f(25.0f, 25.0f));
					heartimg2.setPosition(x + 64, y + 158);
					sf::Texture hearttex2;
					hearttex2.loadFromFile("IMG-20230507-WA0002.jpg");
					heartimg2.setTexture(&hearttex2);
					window.draw(heartimg1);
					window.draw(heartimg2);

					stringstream s1;
					s1 << rank;

					sf::Font font1;
					font1.loadFromFile("OpenSans-Bold.ttf");
					sf::Text numb1;
					numb1.setFont(font1);
					numb1.setString(s1.str());
					numb1.setFillColor(sf::Color::Red);
					numb1.setCharacterSize(27);
					numb1.setPosition(sf::Vector2f(x + 2, y + 2));

					sf::Font font2;
					font2.loadFromFile("OpenSans-Bold.ttf");
					sf::Text numb2;
					numb2.setFont(font2);
					numb2.setString(s1.str());
					numb2.setFillColor(sf::Color::Red);
					numb2.setCharacterSize(27);
					numb2.setPosition(sf::Vector2f(x + 89, y + 152));

					window.draw(numb1);
					window.draw(numb2);
				}
			}

			if (suit == 2)
			{
				window.draw(card);
				if (rank != 10)
				{
					sf::RectangleShape spadeimg1(sf::Vector2f(25.0f, 25.0f));
					spadeimg1.setPosition(x + 22, y + 5);
					sf::Texture spadetex1;
					spadetex1.loadFromFile("IMG-20230507-WA0003.jpg");
					spadeimg1.setTexture(&spadetex1);

					sf::RectangleShape spadeimg2(sf::Vector2f(25.0f, 25.0f));
					spadeimg2.setPosition(x + 73, y + 155);
					sf::Texture spadetex2;
					spadetex2.loadFromFile("IMG-20230507-WA0003.jpg");
					spadeimg2.setTexture(&spadetex2);
					window.draw(spadeimg1);
					window.draw(spadeimg2);

					if (rank >= 2 && rank < 10)
					{
						stringstream s1;
						s1 << rank;

						sf::Font font1;
						font1.loadFromFile("OpenSans-Bold.ttf");
						sf::Text numb1;
						numb1.setFont(font1);
						numb1.setString(s1.str());
						numb1.setFillColor(sf::Color::Black);
						numb1.setCharacterSize(27);
						numb1.setPosition(sf::Vector2f(x + 2, y + 2));

						sf::Font font2;
						font2.loadFromFile("OpenSans-Bold.ttf");
						sf::Text numb2;
						numb2.setFont(font2);
						numb2.setString(s1.str());
						numb2.setFillColor(sf::Color::Black);
						numb2.setCharacterSize(27);
						numb2.setPosition(sf::Vector2f(x + 100, y + 152));

						window.draw(numb1);
						window.draw(numb2);
					}
				}

				if (rank == 1)
				{
					sf::Font font1;
					font1.loadFromFile("OpenSans-Bold.ttf");
					sf::Text numb1;
					numb1.setFont(font1);
					numb1.setString("A");
					numb1.setFillColor(sf::Color::Black);
					numb1.setCharacterSize(27);
					numb1.setPosition(sf::Vector2f(x + 2, y + 2));

					sf::Font font2;
					font2.loadFromFile("OpenSans-Bold.ttf");
					sf::Text numb2;
					numb2.setFont(font2);
					numb2.setString("A");
					numb2.setFillColor(sf::Color::Black);
					numb2.setCharacterSize(27);
					numb2.setPosition(sf::Vector2f(x + 100, y + 152));

					window.draw(numb1);
					window.draw(numb2);
				}

				if (rank == 11)
				{
					sf::RectangleShape spadej(sf::Vector2f(25.0f, 25.0f));
					spadej.setPosition(x + 10, y + 33);
					spadej.setSize(sf::Vector2f(100, 120));
					sf::Texture spadetexj;
					spadetexj.loadFromFile("Jofspade.png");
					spadej.setTexture(&spadetexj);
					window.draw(spadej);


					sf::Font font1;
					font1.loadFromFile("OpenSans-Bold.ttf");
					sf::Text numb1;
					numb1.setFont(font1);
					numb1.setString("J");
					numb1.setFillColor(sf::Color::Black);
					numb1.setCharacterSize(27);
					numb1.setPosition(sf::Vector2f(x + 8, y + 2));

					sf::Font font2;
					font2.loadFromFile("OpenSans-Bold.ttf");
					sf::Text numb2;
					numb2.setFont(font2);
					numb2.setString("J");
					numb2.setFillColor(sf::Color::Black);
					numb2.setCharacterSize(27);
					numb2.setPosition(sf::Vector2f(x + 103, y + 152));

					window.draw(numb1);
					window.draw(numb2);
				}

				if (rank == 12)
				{
					sf::RectangleShape spadeq(sf::Vector2f(25.0f, 25.0f));
					spadeq.setPosition(x + 10, y + 33);
					spadeq.setSize(sf::Vector2f(100, 120));
					sf::Texture spadetexq;
					spadetexq.loadFromFile("Qofspae.png");
					spadeq.setTexture(&spadetexq);
					window.draw(spadeq);


					sf::Font font1;
					font1.loadFromFile("OpenSans-Bold.ttf");
					sf::Text numb1;
					numb1.setFont(font1);
					numb1.setString("Q");
					numb1.setFillColor(sf::Color::Black);
					numb1.setCharacterSize(27);
					numb1.setPosition(sf::Vector2f(x, y + 2));

					sf::Font font2;
					font2.loadFromFile("OpenSans-Bold.ttf");
					sf::Text numb2;
					numb2.setFont(font2);
					numb2.setString("Q");
					numb2.setFillColor(sf::Color::Black);
					numb2.setCharacterSize(27);
					numb2.setPosition(sf::Vector2f(x + 98, y + 152));

					window.draw(numb1);
					window.draw(numb2);
				}

				if (rank == 13)
				{
					sf::RectangleShape spadeK(sf::Vector2f(25.0f, 25.0f));
					spadeK.setPosition(x + 10, y + 33);
					spadeK.setSize(sf::Vector2f(100, 120));
					sf::Texture spadetexK;
					spadetexK.loadFromFile("kofspade.png");
					spadeK.setTexture(&spadetexK);
					window.draw(spadeK);

					sf::Font font1;
					font1.loadFromFile("OpenSans-Bold.ttf");
					sf::Text numb1;
					numb1.setFont(font1);
					numb1.setString("K");
					numb1.setFillColor(sf::Color::Black);
					numb1.setCharacterSize(27);
					numb1.setPosition(sf::Vector2f(x + 2, y + 2));

					sf::Font font2;
					font2.loadFromFile("OpenSans-Bold.ttf");
					sf::Text numb2;
					numb2.setFont(font2);
					numb2.setString("K");
					numb2.setFillColor(sf::Color::Black);
					numb2.setCharacterSize(27);
					numb2.setPosition(sf::Vector2f(x + 100, y + 152));

					window.draw(numb1);
					window.draw(numb2);
				}

				else if (rank == 10)
				{
					sf::RectangleShape spadeimg1(sf::Vector2f(25.0f, 25.0f));
					spadeimg1.setPosition(x + 35, y + 6);
					sf::Texture spadetex1;
					spadetex1.loadFromFile("IMG-20230507-WA0003.jpg");
					spadeimg1.setTexture(&spadetex1);

					sf::RectangleShape spadeimg2(sf::Vector2f(25.0f, 25.0f));
					spadeimg2.setPosition(x + 64, y + 156);
					sf::Texture spadetex2;
					spadetex2.loadFromFile("IMG-20230507-WA0003.jpg");
					spadeimg2.setTexture(&spadetex2);
					window.draw(spadeimg1);
					window.draw(spadeimg2);

					stringstream s1;
					s1 << rank;

					sf::Font font1;
					font1.loadFromFile("OpenSans-Bold.ttf");
					sf::Text numb1;
					numb1.setFont(font1);
					numb1.setString(s1.str());
					numb1.setFillColor(sf::Color::Black);
					numb1.setCharacterSize(27);
					numb1.setPosition(sf::Vector2f(x + 2, y + 2));

					sf::Font font2;
					font2.loadFromFile("OpenSans-Bold.ttf");
					sf::Text numb2;
					numb2.setFont(font2);
					numb2.setString(s1.str());
					numb2.setFillColor(sf::Color::Black);
					numb2.setCharacterSize(27);
					numb2.setPosition(sf::Vector2f(x + 89, y + 152));

					window.draw(numb1);
					window.draw(numb2);
				}
			}

			if (suit == 3)
			{
				window.draw(card);
				if (rank != 10)
				{
					sf::RectangleShape clubimg1(sf::Vector2f(25.0f, 25.0f));
					clubimg1.setPosition(x + 22, y + 7);
					sf::Texture clubtex1;
					clubtex1.loadFromFile("IMG-20230507-WA0004.jpg");
					clubimg1.setTexture(&clubtex1);

					sf::RectangleShape clubimg2(sf::Vector2f(25.0f, 25.0f));
					clubimg2.setPosition(x + 73, y + 157);
					sf::Texture hearttex2;
					hearttex2.loadFromFile("IMG-20230507-WA0004.jpg");
					clubimg2.setTexture(&hearttex2);
					window.draw(clubimg1);
					window.draw(clubimg2);

					if (rank >= 2 && rank < 10)
					{
						stringstream s1;
						s1 << rank;

						sf::Font font1;
						font1.loadFromFile("OpenSans-Bold.ttf");
						sf::Text numb1;
						numb1.setFont(font1);
						numb1.setString(s1.str());
						numb1.setFillColor(sf::Color::Black);
						numb1.setCharacterSize(27);
						numb1.setPosition(sf::Vector2f(x + 2, y + 2));

						sf::Font font2;
						font2.loadFromFile("OpenSans-Bold.ttf");
						sf::Text numb2;
						numb2.setFont(font2);
						numb2.setString(s1.str());
						numb2.setFillColor(sf::Color::Black);
						numb2.setCharacterSize(27);
						numb2.setPosition(sf::Vector2f(x + 100, y + 152));

						window.draw(numb1);
						window.draw(numb2);
					}
				}

				if (rank == 1)
				{
					sf::Font font1;
					font1.loadFromFile("OpenSans-Bold.ttf");
					sf::Text numb1;
					numb1.setFont(font1);
					numb1.setString("A");
					numb1.setFillColor(sf::Color::Black);
					numb1.setCharacterSize(27);
					numb1.setPosition(sf::Vector2f(x + 2, y + 2));

					sf::Font font2;
					font2.loadFromFile("OpenSans-Bold.ttf");
					sf::Text numb2;
					numb2.setFont(font2);
					numb2.setString("A");
					numb2.setFillColor(sf::Color::Black);
					numb2.setCharacterSize(27);
					numb2.setPosition(sf::Vector2f(x + 100, y + 152));

					window.draw(numb1);
					window.draw(numb2);
				}

				if (rank == 11)
				{
					sf::RectangleShape clubj(sf::Vector2f(25.0f, 25.0f));
					clubj.setPosition(x + 10, y + 34);
					clubj.setSize(sf::Vector2f(100, 120));
					sf::Texture clubtexj;
					clubtexj.loadFromFile("JofClub.png");
					clubj.setTexture(&clubtexj);
					window.draw(clubj);

					sf::Font font1;
					font1.loadFromFile("OpenSans-Bold.ttf");
					sf::Text numb1;
					numb1.setFont(font1);
					numb1.setString("J");
					numb1.setFillColor(sf::Color::Black);
					numb1.setCharacterSize(27);
					numb1.setPosition(sf::Vector2f(x + 8, y + 2));

					sf::Font font2;
					font2.loadFromFile("OpenSans-Bold.ttf");
					sf::Text numb2;
					numb2.setFont(font2);
					numb2.setString("J");
					numb2.setFillColor(sf::Color::Black);
					numb2.setCharacterSize(27);
					numb2.setPosition(sf::Vector2f(x + 103, y + 152));

					window.draw(numb1);
					window.draw(numb2);
				}

				if (rank == 12)
				{
					sf::RectangleShape clubq(sf::Vector2f(25.0f, 25.0f));
					clubq.setPosition(x + 10, y + 34);
					clubq.setSize(sf::Vector2f(100, 120));
					sf::Texture clubtexq;
					clubtexq.loadFromFile("qofclub.png");
					clubq.setTexture(&clubtexq);
					window.draw(clubq);

					sf::Font font1;
					font1.loadFromFile("OpenSans-Bold.ttf");
					sf::Text numb1;
					numb1.setFont(font1);
					numb1.setString("Q");
					numb1.setFillColor(sf::Color::Black);
					numb1.setCharacterSize(27);
					numb1.setPosition(sf::Vector2f(x, y + 2));

					sf::Font font2;
					font2.loadFromFile("OpenSans-Bold.ttf");
					sf::Text numb2;
					numb2.setFont(font2);
					numb2.setString("Q");
					numb2.setFillColor(sf::Color::Black);
					numb2.setCharacterSize(27);
					numb2.setPosition(sf::Vector2f(x + 98, y + 152));

					window.draw(numb1);
					window.draw(numb2);
				}

				if (rank == 13)
				{
					sf::RectangleShape clubK(sf::Vector2f(25.0f, 25.0f));
					clubK.setPosition(x + 10, y + 34);
					clubK.setSize(sf::Vector2f(100, 120));
					sf::Texture clubtexK;
					clubtexK.loadFromFile("kofclub.png");
					clubK.setTexture(&clubtexK);
					window.draw(clubK);

					sf::Font font1;
					font1.loadFromFile("OpenSans-Bold.ttf");
					sf::Text numb1;
					numb1.setFont(font1);
					numb1.setString("K");
					numb1.setFillColor(sf::Color::Black);
					numb1.setCharacterSize(27);
					numb1.setPosition(sf::Vector2f(x + 2, y + 2));

					sf::Font font2;
					font2.loadFromFile("OpenSans-Bold.ttf");
					sf::Text numb2;
					numb2.setFont(font2);
					numb2.setString("K");
					numb2.setFillColor(sf::Color::Black);
					numb2.setCharacterSize(27);
					numb2.setPosition(sf::Vector2f(x + 100, y + 152));

					window.draw(numb1);
					window.draw(numb2);
				}

				else if (rank == 10)
				{
					sf::RectangleShape clubimg1(sf::Vector2f(25.0f, 25.0f));
					clubimg1.setPosition(x + 35, y + 6);
					sf::Texture clubtex1;
					clubtex1.loadFromFile("IMG-20230507-WA0004.jpg");
					clubimg1.setTexture(&clubtex1);

					sf::RectangleShape clubimg2(sf::Vector2f(25.0f, 25.0f));
					clubimg2.setPosition(x + 64, y + 156);
					sf::Texture clubtex2;
					clubtex2.loadFromFile("IMG-20230507-WA0004.jpg");
					clubimg2.setTexture(&clubtex2);
					window.draw(clubimg1);
					window.draw(clubimg2);

					stringstream s1;
					s1 << rank;

					sf::Font font1;
					font1.loadFromFile("OpenSans-Bold.ttf");
					sf::Text numb1;
					numb1.setFont(font1);
					numb1.setString(s1.str());
					numb1.setFillColor(sf::Color::Black);
					numb1.setCharacterSize(27);
					numb1.setPosition(sf::Vector2f(x + 2, y + 2));

					sf::Font font2;
					font2.loadFromFile("OpenSans-Bold.ttf");
					sf::Text numb2;
					numb2.setFont(font2);
					numb2.setString(s1.str());
					numb2.setFillColor(sf::Color::Black);
					numb2.setCharacterSize(27);
					numb2.setPosition(sf::Vector2f(x + 89, y + 152));

					window.draw(numb1);
					window.draw(numb2);
				}
			}
		}
	}
};

const int PlayingCard::Diamond = 0;
const int PlayingCard::Heart = 1;
const int PlayingCard::Spade = 2;
const int PlayingCard::Club = 3;

class PileofCards
{
private:
	PlayingCard* pile;
	int top;
	int size;
	int startPt;
	int endPt;
public:
	PileofCards(int s)
	{
		size = s;
		top = -1;
		pile = new PlayingCard[size];
		startPt = 0;
		endPt = 0;
	}
	PileofCards()
	{
		top = -1;
		size = 0;
		startPt = 0;
		endPt = 0;
		pile = new PlayingCard[size];
	}
	~PileofCards()
	{
		delete[] pile;
	}
	int getTop()
	{
		return top;
	}
	int getsize()
	{
		return size;
	}
	void setStartPt(int x)
	{
		startPt = x;
	}
	int getStartPt()
	{
		return startPt;
	}
	void setEndPt(int x)
	{
		endPt = x;
	}
	int getEndPt()
	{
		return endPt;
	}
	PileofCards& operator=(const PileofCards& poc)
	{
		PileofCards temp(poc.size);
		temp.top = poc.top;
		temp.size = poc.size;
		temp.startPt = poc.startPt;
		temp.endPt = poc.endPt;
		temp.pile = poc.pile;
		//temp = poc;
		return temp;
	}
	PlayingCard viewCard(int i)
	{
		return pile[i];
	}
	void SimpleDisplay(int x, int y)
	{
		if (top == -1)
		{
			emptyslot(x, y);
		}

		else
		{
			pile[top].display(x, y);
		}
	}
	void CascadingDisplay(int x, int y)
	{
		if (top == -1)
		{
			emptyslot(x, y);
		}
		else
		{
			for (int i = 0; i < top + 1; i++)
			{
				pile[i].display(x, y);
				x = x + 8;
				y = y + 30;
			}
		}
	}
	PlayingCard Peek()
	{
		return pile[top];
	}
	PlayingCard* Remove()
	{
		PlayingCard temp = pile[top];
		top--;
		return &temp;

	}
	PlayingCard Removecard()
	{
		PlayingCard temp = pile[top];
		top--;
		return temp;
	}
	void Add(PlayingCard pl)
	{
		if (top + 1 <= size - 1)
		{
			pile[top + 1] = pl;
			top++;
		}
	}
	bool IsEmpty()
	{
		if (top == -1)
			return true;
		else
			return false;
	}
	bool IsFull()
	{
		if (top == size)
			return true;
		else
			return false;
	}
	void display(int x, int y)
	{
		for (int i = 0; i < size; i++)
		{
			pile[i].display(x, y);
			x = x + 150;
		}
	}
};

class Deck
{
private:
	PlayingCard* deck[52];
	int size;
public:
	Deck()
	{
		int j = 0;
		for (int i = 1; i <= 13; i++)
		{
			deck[j] = new PlayingCard(i, PlayingCard::Diamond);
			j++;
		}
		for (int i = 1; i <= 13; i++)
		{
			deck[j] = new PlayingCard(i, PlayingCard::Heart);
			j++;
		}
		for (int i = 1; i <= 13; i++)
		{
			deck[j] = new PlayingCard(i, PlayingCard::Spade);
			j++;
		}
		for (int i = 1; i <= 13; i++)
		{
			deck[j] = new PlayingCard(i, PlayingCard::Club);
			j++;
		}
		size = 52;
	}
	int getSize()
	{
		return size;
	}
	bool IsEmpty()
	{
		if (size < 1)
		{
			return true;
		}
		else
			return false;
	}
	PlayingCard Remove(int i)
	{
		PlayingCard temp(0, 0);
		if (size != 0)
		{
			PlayingCard temp = *deck[i];

			for (int j = i + 1; j < size; j++)
			{
				deck[i] = NULL;
				deck[i] = deck[j];
				i++;
			}
			size--;
			return temp;
		}
		else
		{
			return temp;
		}
	}
	~Deck()
	{
		for (int i = 0; i < 52; i++)
		{
			delete deck[i];
		}
	}
	void display(int x, int y)
	{
		int x1 = x;
		int y1 = y;

		int x2 = x1 + 300;
		int y2 = y;

		int x3 = x2 + 300;
		int y3 = y;

		int x4 = x3 + 300;
		int y4 = y;
		for (int i = 0; i < size; i++)
		{
			if (deck[i]->getsuit() == 0)
			{
				deck[i]->display(x1, y1);
				x1 = x1 + 10;
				y1 = y1 + 40;
			}
			else if (deck[i]->getsuit() == 1)
			{
				deck[i]->display(x2, y2);
				x2 = x2 + 10;
				y2 = y2 + 40;
			}
			else if (deck[i]->getsuit() == 2)
			{
				deck[i]->display(x3, y3);
				x3 = x3 + 10;
				y3 = y3 + 40;
			}
			else if (deck[i]->getsuit() == 3)
			{
				deck[i]->display(x4, y4);
				x4 = x4 + 10;
				y4 = y4 + 40;
			}
		}
	}
};

class Solitaire
{
private:
	Deck deckofCards;
	PileofCards stock;
	PileofCards waste;
	PileofCards home[4];
	PileofCards playingPile[7];

public:
	Solitaire() :stock(52), waste(52), home{ 13, 13, 13, 13 }, playingPile{ 13,13,13,13,13,13,13 }
	{}
	void Shuffle()
	{
		srand(time(0));
		int i = 0;
		while (!deckofCards.IsEmpty())
		{
			i = rand() % deckofCards.getSize();
			PlayingCard c = deckofCards.Remove(i);
			c.setFaceUp(false);
			stock.Add(c);
		}
	}
	void dealToPlayingPiles()
	{
		PlayingCard temp[28];
		int j = 0;
		for (int i = 0; i < 7; i++)
		{
			if (i == 0)
			{
				temp[j] = stock.Removecard();
				temp[j].setFaceUp(true);
				playingPile[i].Add(temp[j]);
				j++;
			}
			else if (i == 1)
			{
				temp[j] = stock.Removecard();
				temp[j].setFaceUp(false);
				playingPile[i].Add(temp[j]);
				j++;
				temp[j] = stock.Removecard();
				temp[j].setFaceUp(true);
				playingPile[i].Add(temp[j]);
				j++;
			}
			else if (i == 2)
			{
				temp[j] = stock.Removecard();
				temp[j].setFaceUp(false);
				playingPile[i].Add(temp[j]);
				j++;
				temp[j] = stock.Removecard();
				temp[j].setFaceUp(false);
				playingPile[i].Add(temp[j]);
				j++;
				temp[j] = stock.Removecard();
				temp[j].setFaceUp(true);
				playingPile[i].Add(temp[j]);
				j++;
			}
			else if (i == 3)
			{
				temp[j] = stock.Removecard();
				temp[j].setFaceUp(false);
				playingPile[i].Add(temp[j]);
				j++;
				temp[j] = stock.Removecard();
				temp[j].setFaceUp(false);
				playingPile[i].Add(temp[j]);
				j++;
				temp[j] = stock.Removecard();
				temp[j].setFaceUp(false);
				playingPile[i].Add(temp[j]);
				j++;
				temp[j] = stock.Removecard();
				temp[j].setFaceUp(true);
				playingPile[i].Add(temp[j]);
				j++;
			}
			else if (i == 4)
			{
				temp[j] = stock.Removecard();
				temp[j].setFaceUp(false);
				playingPile[i].Add(temp[j]);
				j++;
				temp[j] = stock.Removecard();
				temp[j].setFaceUp(false);
				playingPile[i].Add(temp[j]);
				j++;
				temp[j] = stock.Removecard();
				temp[j].setFaceUp(false);
				playingPile[i].Add(temp[j]);
				j++;
				temp[j] = stock.Removecard();
				temp[j].setFaceUp(false);
				playingPile[i].Add(temp[j]);
				j++;
				temp[j] = stock.Removecard();
				temp[j].setFaceUp(true);
				playingPile[i].Add(temp[j]);
				j++;
			}
			else if (i == 5)
			{
				temp[j] = stock.Removecard();
				temp[j].setFaceUp(false);
				playingPile[i].Add(temp[j]);
				j++;
				temp[j] = stock.Removecard();
				temp[j].setFaceUp(false);
				playingPile[i].Add(temp[j]);
				j++;
				temp[j] = stock.Removecard();
				temp[j].setFaceUp(false);
				playingPile[i].Add(temp[j]);
				j++;
				temp[j] = stock.Removecard();
				temp[j].setFaceUp(false);
				playingPile[i].Add(temp[j]);
				j++;
				temp[j] = stock.Removecard();
				temp[j].setFaceUp(false);
				playingPile[i].Add(temp[j]);
				j++;
				temp[j] = stock.Removecard();
				temp[j].setFaceUp(true);
				playingPile[i].Add(temp[j]);
				j++;
			}
			else if (i == 6)
			{
				temp[j] = stock.Removecard();
				temp[j].setFaceUp(false);
				playingPile[i].Add(temp[j]);
				j++;
				temp[j] = stock.Removecard();
				temp[j].setFaceUp(false);
				playingPile[i].Add(temp[j]);
				j++;
				temp[j] = stock.Removecard();
				temp[j].setFaceUp(false);
				playingPile[i].Add(temp[j]);
				j++;
				temp[j] = stock.Removecard();
				temp[j].setFaceUp(false);
				playingPile[i].Add(temp[j]);
				j++;
				temp[j] = stock.Removecard();
				temp[j].setFaceUp(false);
				playingPile[i].Add(temp[j]);
				j++;
				temp[j] = stock.Removecard();
				temp[j].setFaceUp(false);
				playingPile[i].Add(temp[j]);
				j++;
				temp[j] = stock.Removecard();
				temp[j].setFaceUp(true);
				playingPile[i].Add(temp[j]);
				j++;
			}
		}
	}
	void DisplayGame()
	{
		stock.SimpleDisplay(20, 50);
		int x = 20;
		int y = 300;
		for (int i = 0; i < 7; i++)
		{
			playingPile[i].CascadingDisplay(x, y);
			x = x + 175;

		}
		waste.SimpleDisplay(200, 50);
		int xh = 545;
		int yh = 50;
		for (int i = 0; i < 4; i++)
		{
			home[i].SimpleDisplay(xh, yh);
			xh = xh + 175;

		}
	}
	~Solitaire()
	{
	}
};


int main()
{
	sf::RectangleShape loadingScreen(sf::Vector2f(1280, 720));
	sf::Texture loadtex;
	loadtex.loadFromFile("loadingscrn.png");
	loadingScreen.setTexture(&loadtex);

	sf::RectangleShape loadingBar(sf::Vector2f(500, 20));
	loadingBar.setFillColor(sf::Color::Black);
	loadingBar.setPosition(350, 600);

	sf::Font font;
	font.loadFromFile("OpenSans-Bold.ttf");
	sf::Text loadingText("LOADING ...", font, 30);
	loadingText.setFillColor(sf::Color::White);
	loadingText.setPosition(520, 650);

	bool isLoadingComplete = false;
	float loadingProgress = 0.0f;

	Solitaire S;
	S.Shuffle();
	S.dealToPlayingPiles();
	S.DisplayGame();

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		background();

		if (!isLoadingComplete)
		{
			window.draw(loadingScreen);
			window.draw(loadingText);
			window.draw(loadingText);
			loadingProgress += 0.1f;
			if (loadingProgress >= 1.0f)
			{
				isLoadingComplete = true;
			}
			sf::sleep(sf::milliseconds(100));
			sf::RectangleShape progressBar(sf::Vector2f(loadingBar.getSize().x * loadingProgress, loadingBar.getSize().y));
			progressBar.setFillColor(sf::Color::Red);
			progressBar.setPosition(loadingBar.getPosition());
			window.draw(loadingBar);
			window.draw(progressBar);
		}
		else
		{
			S.DisplayGame();
		}
		window.display();
		window.clear(sf::Color::White);
	}

	return 0;
}