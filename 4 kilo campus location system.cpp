#include <SFML/Graphics.hpp>
#include <TGUI/TGUI.hpp>
#include <iostream>
using namespace std;
using namespace sf;
#define         ARROW_SPEED        1.0
int main()
{
	sf::RenderWindow mainWindow(sf::VideoMode(800, 600), "4-KILO CAMPUS MAP SAMPLE APP");
	mainWindow.setVerticalSyncEnabled(true);
	mainWindow.setKeyRepeatEnabled(false);

	sf::Texture ui, a4, tMap, tArrow, tTheme, a4theme, tBackground, tFeedbackPage, tLocationIcon, tSettingPage, tAboutUsPage, tChechForUpdatePage;
	tAboutUsPage.loadFromFile("about.jpg");
	tChechForUpdatePage.loadFromFile("check.jpg");
	ui.loadFromFile("ui.png");
	tArrow.loadFromFile("arrow.jpg");
	tLocationIcon.loadFromFile("location_icon.png");
	tFeedbackPage.loadFromFile("feedbackPage.png");
	tSettingPage.loadFromFile("Setting1.jpg");
	tBackground.loadFromFile("blur.jpg");
	tTheme.loadFromFile("theme.png");
	tMap.loadFromFile("maps1.jpg");
	a4.loadFromFile("a4.png");
	a4theme.loadFromFile("a4theme.png");



	sf::Sprite sprite_UI(ui), theme(tTheme), arrow(tArrow), location(tLocationIcon);
	sf::RectangleShape   a4_Rec(sf::Vector2f(195, 445)), rAboutUsPage(sf::Vector2f(255, 445)), rCheckForUpdatePage(sf::Vector2f(255, 445)), rFeedbackPage(sf::Vector2f(255, 445)), rSettingPage(sf::Vector2f(255, 445)), rMap(sf::Vector2f(255, 445)), a4_theme_rec(sf::Vector2f(195, 445));

	///// for arrow start
	arrow.setScale(sf::Vector2f(0.06, 0.06));
	location.setScale(sf::Vector2f(0.2, 0.2));
	bool origin = true;
	if (origin)arrow.setOrigin(sf::Vector2f(arrow.getLocalBounds().width / 2.0f
		, arrow.getLocalBounds().height) / 2.0f); // rotate around the arrow about centre

	rAboutUsPage.setTexture(&tAboutUsPage);
	rAboutUsPage.setPosition(359, 65);

	rCheckForUpdatePage.setTexture(&tChechForUpdatePage);
	rCheckForUpdatePage.setPosition(359, 65);

	rSettingPage.setTexture(&tSettingPage);
	rSettingPage.setPosition(359, 65);

	rFeedbackPage.setTexture(&tFeedbackPage);
	rFeedbackPage.setPosition(359, 65);

	rMap.setTexture(&tMap);
	rMap.setPosition(359, 65);

	a4_Rec.setTexture(&a4);
	a4_Rec.setPosition(359, 65);

	a4_theme_rec.setTexture(&a4theme);
	a4_theme_rec.setPosition(359, 65);



	bool draw_UI = true;
	bool draw_theme = false;
	bool draw_map = false;
	bool draw_a3 = false;
	bool draw_a3_theme = false;
	bool draw_widgets = false;
	bool draw_feedback_page = false;
	bool draw_arrow = false;
	bool draw_searchBar = false;
	bool draw_setting_page = false;
	bool draw_aboutUsPage = false;
	bool draw_checkForUpdatePage = false;
	bool draw_location_icon = false;

	bool upFlag = false;
	bool downFlag = false;
	bool leftFlag = false;
	bool rightFlag = false;

	bool gateToFresh = false;
	bool DigitalToCafe = false;
	bool NBH_to_cafe = false;
	bool gateToDigital = false;

	int x; // for x coordinate of x
	int y; // for y coordinate of y
	tgui::Gui gui(mainWindow);
	tgui::Gui gui2(mainWindow);

	try
	{
		auto picture = tgui::Picture::create("blur1.jpg");
		picture->setSize(255, 445);
		picture->setPosition(359, 65);
		gui.add(picture);


		auto editBox1 = tgui::EditBox::create();
		editBox1->setSize(200, 60);
		editBox1->setPosition(400, 200);
		editBox1->setDefaultText("enter your current location");
		gui.add(editBox1);

		auto editBox2 = tgui::EditBox::copy(editBox1);
		editBox2->setPosition(400, 300);
		editBox2->setDefaultText("enter your destination");
		gui.add(editBox2);

		// Create the take me button
		auto button = tgui::Button::create("take me");
		button->setSize(100, 55);
		button->setPosition(450, 400);
		gui.add(button);
		button->connect("pressed", [&]()
		{ // button connect start

		  /// from main gate to fresh man building
			if (editBox1->getText().toAnsiString() == "main gate"
				&& editBox2->getText().toAnsiString() == "freshman building"
				&&draw_setting_page == false)
			{
				draw_map = true;
				draw_arrow = true;
				upFlag = true;
				arrow.setRotation(0);
				x = 437;
				y = 557;
				gateToFresh = true;
			}//

			// from digital lab  to  cafeteria
			else if (editBox1->getText().toAnsiString() == "digital lab"
				&& editBox2->getText().toAnsiString() == "cafeteria"
				&&draw_setting_page == false)
			{
				draw_map = true;
				draw_arrow = true;
				downFlag = true;
				arrow.setRotation(180);
				x = 534;
				y = 84;
				DigitalToCafe = true;
			}//

			//from NBH to cafeteria
			else if (editBox1->getText().toAnsiString() == "NBH"
				&& editBox2->getText().toAnsiString() == "cafeteria"
				&&draw_setting_page == false)
			{
				draw_map = true;
				draw_arrow = true;
				upFlag = true;
				arrow.setRotation(0);
				x = 532;
				y = 231;
				NBH_to_cafe = true;
			}
			//from main gate  to digital lab //555 112
			else if (editBox1->getText().toAnsiString() == "main gate"
				&& editBox2->getText().toAnsiString() == "digital lab"
				&&draw_setting_page == false)
			{
				draw_map = true;
				draw_arrow = true;
				upFlag = true;
				arrow.setRotation(0);
				x = 438;
				y = 341;
				gateToDigital = true;
			}


		}); // button connect end


	} // try ends
	catch (const tgui::Exception& e)
	{
		std::cerr << "Failed to load TGUI widgets: " << e.what() << std::endl;
	}
	//
	try
	{
		auto searchBox = tgui::EditBox::create();
		searchBox->setSize(211, 29);
		searchBox->setTextSize(12);
		searchBox->setPosition(400, 110);
		searchBox->setDefaultText("Search for a location");
		gui2.add(searchBox);

		auto searchButton = tgui::Button::create("search");
		searchButton->setSize({ 50, 28 });
		searchButton->setPosition({ 560, 111 });
		gui2.add(searchButton);

		searchButton->connect("pressed", [&]()
		{
			if (searchBox->getText().toAnsiString() == "pepsi")
			{
				draw_map = true;
				draw_location_icon = true;
				location.setPosition(483, 307);
			}
			else if (searchBox->getText().toAnsiString() == "cafeteria")
			{
				draw_map = true;
				draw_location_icon = true;
				location.setPosition(366, 69);
			}

			else if (searchBox->getText().toAnsiString() == "clinic")
			{
				draw_map = true;
				draw_location_icon = true;
				location.setPosition(362, 307);
			}
			else if (searchBox->getText().toAnsiString() == "NBH")
			{
				draw_map = true;
				draw_location_icon = true;
				location.setPosition(542, 194);
			}
			else if (searchBox->getText().toAnsiString() == "freshman building")
			{
				draw_map = true;
				draw_location_icon = true;
				location.setPosition(464, 196);
			}
			else if (searchBox->getText().toAnsiString() == "earth science")
			{
				draw_map = true;
				draw_location_icon = true;
				location.setPosition(362, 199);
			}
			else if (searchBox->getText().toAnsiString() == "digital lab")
			{
				draw_map = true;
				draw_location_icon = true;
				location.setPosition(547, 69);
			}
			else if (searchBox->getText().toAnsiString() == "toilet")
			{
				draw_map = true;
				draw_location_icon = true;
				location.setPosition(472, 103);
			}
			else {
				cout << "wrong location" << endl;
			}
		}); // search end
	}
	catch (const tgui::Exception& e)
	{
		std::cerr << "Failed to load TGUI widgets: " << e.what() << std::endl;
	}

	while (mainWindow.isOpen())
	{
		sf::Event event;

		while (mainWindow.pollEvent(event))
		{

			if (event.type == sf::Event::Closed) mainWindow.close();
			if (event.type == sf::Event::KeyPressed)
			{
				switch (event.key.code)
				{
				case  sf::Keyboard::Escape: mainWindow.close(); break;

				}
			}
			gui.handleEvent(event);
			gui2.handleEvent(event);

		}


		if (leftFlag) {
			x -= ARROW_SPEED;
			upFlag = false;
			downFlag = false;
			rightFlag = false;
		       }
		if (rightFlag) {
			x += ARROW_SPEED;
			upFlag = false;
			leftFlag = false;
			downFlag = false;
		}
		if (upFlag) {
			y -= ARROW_SPEED;
			leftFlag = false;
			downFlag = false;
			rightFlag = false;
		}
		if (downFlag) {
			y += ARROW_SPEED;
			upFlag = false;
			leftFlag = false;
			rightFlag = false;
		}


		if (x<100 + 13.44) { x = 100 + 13.44; origin = false; }
		if (x>552 - 13.44) { x = 552 - 13.44; origin = false; }
		if (y>432 - 13.44) { y = 432 - 13.44; origin = false; }
		if (y<100 + 13.44) { y = 100 + 13.44; origin = false; }


		/// from gate to freshman
		if (gateToFresh)
		{
			if (x >= 432 &&
				x <= 446 &&
				y >= 233 &&
				y <= 245
				)
			{
				upFlag = true;
				arrow.setRotation(90);
				rightFlag = true;
			}

			if (x >= 455 &&
				x <= 468 &&
				y >= 233 &&
				y <= 245
				)
			{
				rightFlag = false;
			}
		}
		/// from gate to freshman  end



		/// from digital lab to cafeteria  start
		if (DigitalToCafe) {

			if (x >= 530 &&
				x <= 534 &&
				y >= 175 &&
				y <= 179
				)
			{
				downFlag = false;
				arrow.setRotation(-90);
				leftFlag = true;
			}
			if (x >= 384 &&
				x <= 388 &&
				y >= 175 &&
				y <= 179
				)
			{
				upFlag = true;
				arrow.setRotation(0);
				leftFlag = false;
			}
			if (x >= 384 &&
				x <= 388 &&
				y >= 134 &&
				y <= 138
				)
			{
				upFlag = false;
			}

		}//


		if (gateToDigital) {
			if (x >= 436 &&
				x <= 438 &&
				y >= 170 &&
				y <= 174
				)
			{
				upFlag = false;
				rightFlag = true;
				arrow.setRotation(90);
			}
			if (x >= 531 &&
				x <= 535 &&
				y >= 170 &&
				y <= 174
				)
			{
				upFlag = true;
				rightFlag = false;
				arrow.setRotation(0);
			}
			if (x >= 531 &&
				x <= 535 &&
				y >= 101 &&
				y <= 105
				)
			{
				upFlag = false;
				rightFlag = true;
			}

			if (x >= 553
				&& x <= 557
				&& y >= 110
				&& y <= 114)
			{
				rightFlag = false;
			}
		          }//



		/// from NBH to cafeteria
		if (NBH_to_cafe) {
			if (x >= 384 &&
				x <= 388 &&
				y >= 134 &&
				y <= 138
				)
			{
				upFlag = false;
			}
			if (x >= 384 &&
				x <= 388 &&
				y >= 175 &&
				y <= 179
				)
			{
				upFlag = true;
				arrow.setRotation(0);
				leftFlag = false;
			}
			if (x >= 384 &&
				x <= 388 &&
				y >= 134 &&
				y <= 138
				)
			{
				upFlag = false;
			}

		}//


		//  for phone back button
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)
			&& sf::Mouse::getPosition(mainWindow).x >= 529
			&& sf::Mouse::getPosition(mainWindow).y >= 511
			&& sf::Mouse::getPosition(mainWindow).x <= 608
			&& sf::Mouse::getPosition(mainWindow).y <= 548
			&& draw_map == false
			&& draw_widgets == false
			) {//
			  draw_theme = false;
			  draw_a3 = false;
			 draw_a3_theme = false;
			 draw_widgets = false;
			 draw_feedback_page = false;
			 draw_arrow = false;
			 draw_searchBar = false;
			 draw_setting_page = false;
			 draw_aboutUsPage = false;
			 draw_checkForUpdatePage = false;
			 draw_location_icon = false;

		}//  for phone back button


		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)
			&& sf::Mouse::getPosition(mainWindow).x >= 529
			&& sf::Mouse::getPosition(mainWindow).y >= 511
			&& sf::Mouse::getPosition(mainWindow).x <= 608
			&& sf::Mouse::getPosition(mainWindow).y <= 548
			&& draw_feedback_page == true
			&& draw_setting_page == false
			) {//
			draw_feedback_page = false;
		}// for phone back button for feedback
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)
			&& sf::Mouse::getPosition(mainWindow).x >= 529
			&& sf::Mouse::getPosition(mainWindow).y >= 511
			&& sf::Mouse::getPosition(mainWindow).x <= 608
			&& sf::Mouse::getPosition(mainWindow).y <= 548
			&& draw_map == true
			&& draw_setting_page == false
			) {
			draw_map = false;

		} // back button for map

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)
			&& sf::Mouse::getPosition(mainWindow).x >= 529
			&& sf::Mouse::getPosition(mainWindow).y >= 511
			&& sf::Mouse::getPosition(mainWindow).x <= 608
			&& sf::Mouse::getPosition(mainWindow).y <= 548
			&& draw_widgets == true
			&& draw_map == false
			) {
			draw_widgets = false;
		}//back for widgets


		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)
			&& sf::Mouse::getPosition(mainWindow).x >= 364
			&& sf::Mouse::getPosition(mainWindow).y >= 117
			&& sf::Mouse::getPosition(mainWindow).x <= 391
			&& sf::Mouse::getPosition(mainWindow).y <= 134
			&& draw_a3 == false
			&& draw_a3_theme == false
			&& draw_widgets == false
			&& draw_setting_page == false
			) {//
			if (draw_a3_theme == false && draw_theme == false)draw_a3 = true;
			if (draw_a3 == false && draw_theme == true)draw_a3_theme = true;

		}//to draw side bar menu

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)
			&& sf::Mouse::getPosition(mainWindow).x >= 365
			&& sf::Mouse::getPosition(mainWindow).y >= 229
			&& sf::Mouse::getPosition(mainWindow).x <= 610
			&& sf::Mouse::getPosition(mainWindow).y <= 270
			&& draw_a3 == false
			&& draw_a3_theme == false
			&& draw_widgets == false
			&& draw_setting_page == false
			) {//
			draw_map = true;
			//draw_UI = false;
		}// map of the campus button

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)
			&& sf::Mouse::getPosition(mainWindow).x >= 402
			&& sf::Mouse::getPosition(mainWindow).y >= 111
			&& sf::Mouse::getPosition(mainWindow).x <= 608
			&& sf::Mouse::getPosition(mainWindow).y <= 137
			&& draw_setting_page == false)
		{
			draw_searchBar = true;
		}


		//for take me button
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)
			&& sf::Mouse::getPosition(mainWindow).x >= 365
			&& sf::Mouse::getPosition(mainWindow).y >= 298
			&& sf::Mouse::getPosition(mainWindow).x <= 610
			&& sf::Mouse::getPosition(mainWindow).y <= 339
			&& draw_a3 == false
			&& draw_a3_theme == false
			&& draw_widgets == false
			&& draw_setting_page == false
			) {//
			draw_widgets = true;
		}// takeme to button

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)
			&& sf::Mouse::getPosition(mainWindow).x >= 365
			&& sf::Mouse::getPosition(mainWindow).y >= 373
			&& sf::Mouse::getPosition(mainWindow).x <= 610
			&& sf::Mouse::getPosition(mainWindow).y <= 415
			&& draw_a3 == false
			&& draw_a3_theme == false
			&& draw_widgets == false
			&& draw_setting_page == false
			) {//
			mainWindow.close();
		}// exit button



		 //home button of sidebar menu code starts here
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)
			&& sf::Mouse::getPosition(mainWindow).x >= 350
			&& sf::Mouse::getPosition(mainWindow).y >= 200
			&& sf::Mouse::getPosition(mainWindow).x <= 520
			&& sf::Mouse::getPosition(mainWindow).y <= 248
			&& draw_a3 == true
			&& draw_setting_page == false
			) {
			////
			draw_a3 = false;
			///
		}//home button of sidebar menu code end here


		 //home button of sidebar menu for theme2
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)
			&& sf::Mouse::getPosition(mainWindow).x >= 350
			&& sf::Mouse::getPosition(mainWindow).y >= 200
			&& sf::Mouse::getPosition(mainWindow).x <= 520
			&& sf::Mouse::getPosition(mainWindow).y <= 248
			&& draw_a3_theme == true
			&& draw_setting_page == false
			) {
			////
			draw_a3_theme = false;
			///
		}



		//feedback button of sidebar menu code starts here
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)
			&& sf::Mouse::getPosition(mainWindow).x >= 350
			&& sf::Mouse::getPosition(mainWindow).y >= 248
			&& sf::Mouse::getPosition(mainWindow).x <= 520
			&& sf::Mouse::getPosition(mainWindow).y <= 300
			&& draw_a3 == true
			&& draw_setting_page == false
			) {
			    draw_feedback_page = true;
		      }//feedback button of sidebar menu code end here


		 //setting button of sidebar menu code starts here
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)
			&& sf::Mouse::getPosition(mainWindow).x >= 350
			&& sf::Mouse::getPosition(mainWindow).y >= 300
			&& sf::Mouse::getPosition(mainWindow).x <= 520
			&& sf::Mouse::getPosition(mainWindow).y <= 346
			&& draw_a3 == true
			&& draw_setting_page == false
			) {
			///
			draw_a3 = false;
			draw_setting_page = true;
			///
		}//setting button of sidebar menu code end here

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)
			&& sf::Mouse::getPosition(mainWindow).x >= 350
			&& sf::Mouse::getPosition(mainWindow).y >= 300
			&& sf::Mouse::getPosition(mainWindow).x <= 520
			&& sf::Mouse::getPosition(mainWindow).y <= 346
			&& draw_a3_theme == true
			&& draw_setting_page == false
			) {
			///
			draw_a3_theme = false;
			draw_setting_page = true;
			///
		}

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)
			&& sf::Mouse::getPosition(mainWindow).x >= 430
			&& sf::Mouse::getPosition(mainWindow).y >= 340
			&& sf::Mouse::getPosition(mainWindow).x <= 530
			&& sf::Mouse::getPosition(mainWindow).y <= 337
			&& draw_setting_page == true
			) {
			draw_a3_theme = false;
			draw_theme = false;
			draw_UI = true;
			draw_a3 = true;
			draw_setting_page = false;
			draw_checkForUpdatePage = false;
			draw_widgets = false;
			draw_map = false;
		}

		// for blue theme
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)
			&& sf::Mouse::getPosition(mainWindow).x >= 430
			&& sf::Mouse::getPosition(mainWindow).y >= 409
			&& sf::Mouse::getPosition(mainWindow).x <= 530
			&& sf::Mouse::getPosition(mainWindow).y <= 448
			&& draw_setting_page == true
			) {
			draw_a3_theme = true;
			draw_theme = true;
			draw_UI = false;
			draw_a3 = false;
			draw_setting_page = false;
			draw_feedback_page = false;
			draw_checkForUpdatePage = false;
		    draw_widgets = false;
			draw_map = false;

		}
		//about button of sidebar menu code starts here
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)
			&& sf::Mouse::getPosition(mainWindow).x >= 350
			&& sf::Mouse::getPosition(mainWindow).y >= 346
			&& sf::Mouse::getPosition(mainWindow).x <= 520
			&& sf::Mouse::getPosition(mainWindow).y <= 400
			&& draw_a3 == true
			) {
			draw_aboutUsPage = true;
		}//about button of sidebar menu code end here

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)
			&& sf::Mouse::getPosition(mainWindow).x >= 350
			&& sf::Mouse::getPosition(mainWindow).y >= 346
			&& sf::Mouse::getPosition(mainWindow).x <= 520
			&& sf::Mouse::getPosition(mainWindow).y <= 400
			&& draw_a3_theme == true
			&& draw_setting_page == false
			) {
			draw_aboutUsPage = true;
		}


		 //check update button of sidebar menu code starts here
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)
			&& sf::Mouse::getPosition(mainWindow).x >= 350
			&& sf::Mouse::getPosition(mainWindow).y >= 400
			&& sf::Mouse::getPosition(mainWindow).x <= 520
			&& sf::Mouse::getPosition(mainWindow).y <= 450
			&& draw_a3 == true
			&& draw_setting_page == false
			) {
			//draw_checkForUpdatePage = true;
		}//check update button of sidebar menu code end here

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)
			&& sf::Mouse::getPosition(mainWindow).x >= 350
			&& sf::Mouse::getPosition(mainWindow).y >= 400
			&& sf::Mouse::getPosition(mainWindow).x <= 520
			&& sf::Mouse::getPosition(mainWindow).y <= 450
			&& draw_a3_theme == true
			&& draw_setting_page == false
			) {
			//draw_checkForUpdatePage = true;
		}

		 //exit button code starts here
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)
			&& sf::Mouse::getPosition(mainWindow).x >= 350
			&& sf::Mouse::getPosition(mainWindow).y >= 450
			&& sf::Mouse::getPosition(mainWindow).x <= 520
			&& sf::Mouse::getPosition(mainWindow).y <= 499
			&& draw_a3 == true
			&& draw_setting_page == false
			) {
			mainWindow.close();
		} // exit button code end here

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)
			&& sf::Mouse::getPosition(mainWindow).x >= 350
			&& sf::Mouse::getPosition(mainWindow).y >= 450
			&& sf::Mouse::getPosition(mainWindow).x <= 520
			&& sf::Mouse::getPosition(mainWindow).y <= 499
			&& draw_a3_theme == true
			&& draw_setting_page == false
			) {
			mainWindow.close();
		}

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)
			&& sf::Mouse::getPosition(mainWindow).x >= 555
			&& sf::Mouse::getPosition(mainWindow).y >= 65
			&& sf::Mouse::getPosition(mainWindow).x <= 613
			&& sf::Mouse::getPosition(mainWindow).y <= 509
			&& draw_a3 == true
			&& draw_setting_page == false
			) {
			draw_a3 = false;
		} // to close side bar menu using open space around sidebar menu

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)
			&& sf::Mouse::getPosition(mainWindow).x >= 555
			&& sf::Mouse::getPosition(mainWindow).y >= 65
			&& sf::Mouse::getPosition(mainWindow).x <= 613
			&& sf::Mouse::getPosition(mainWindow).y <= 509
			&& draw_a3_theme == true
			&& draw_setting_page == false
			) {
			draw_a3_theme = false;
		}

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)
			&& sf::Mouse::getPosition(mainWindow).x >= 555
			&& sf::Mouse::getPosition(mainWindow).y >= 65
			&& sf::Mouse::getPosition(mainWindow).x <= 613
			&& sf::Mouse::getPosition(mainWindow).y <= 509
			&& draw_a3_theme == true
			&& draw_setting_page == false
			) {
			     draw_a3_theme = false;
		      } // to close side bar menu using open space around sidebar menu


		mainWindow.clear(sf::Color(127, 127, 127));


		if (draw_UI) mainWindow.draw(sprite_UI);
		if (draw_searchBar) gui2.draw();
		arrow.setPosition(x, y);
		if (draw_theme) mainWindow.draw(theme);
		if (draw_a3) { mainWindow.draw(a4_Rec); }
		if (draw_a3_theme) { mainWindow.draw(a4_theme_rec); }
		if (draw_feedback_page) { mainWindow.draw(rFeedbackPage); }
		if (draw_aboutUsPage) { mainWindow.draw(rAboutUsPage); }
		if (draw_checkForUpdatePage) { mainWindow.draw(rCheckForUpdatePage); }
		if (draw_widgets) gui.draw();
		if (draw_map) mainWindow.draw(rMap);
		if (draw_location_icon) mainWindow.draw(location);
		if (draw_arrow) { mainWindow.draw(arrow); }
		if (draw_setting_page) mainWindow.draw(rSettingPage);
		mainWindow.display();
	}
	return 0;
}
