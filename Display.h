#pragma once
#include <SFML/Graphics.hpp>
#include "VisualElements.h"
#include <algorithm>
#include "redblacktree.h"
#include "MaxHeap.h"
#include "Accidents.h"
#include <iostream>


void findButtonPressed(sf::Vector2i vect, std::map<string, Button>& buttons) {
	
	buttons["City"].isPressed = false; //text boxes should not stay highlighted if you click outside of them
	buttons["State"].isPressed = false;

	for (auto iter = buttons.begin(); iter != buttons.end(); iter++) {

		if ((*iter).first == "searchResults") { //if search results is selected, special care is needed to "toggle" to correct state

			if ((vect.x >= (*iter).second.yPos) && (vect.x < ((*iter).second.yPos + (*iter).second.height))) {
				if ((vect.y >= (*iter).second.xPos) && (vect.y < ((*iter).second.xPos + (*iter).second.width))) {

					if ((vect.x / 316) >= 1) { //right side clicked 
						if (!(*iter).second.isPressed) {
							(*iter).second.isPressed = true;
						}
					}
					else { //left side clicked
						if ((*iter).second.isPressed) {
							(*iter).second.isPressed = false;
						}
					}
				}
			}
		}

		else if ((vect.x >= (*iter).second.yPos) && (vect.x < ((*iter).second.yPos + (*iter).second.height))) { //for all other buttons

			if ((vect.y >= (*iter).second.xPos) && (vect.y < ((*iter).second.xPos + (*iter).second.width))) { //if the click is within this button


				if ((*iter).second.isPressed) { //toggle it: if selected, deselect it, and vice versa
					(*iter).second.isPressed = false;
				}
				else {
					(*iter).second.isPressed = true;
				}
				return;
			}

		}

	}

}

void printSupplementalImagesResults(sf::RenderWindow& window, std::map<string, Button>& buttons) { //prints supplemental images/text like title, text boxes, etc. for when results tab is selected
	
	sf::Font font;
	font.loadFromFile("Font/Montserrat-Medium.ttf");

	sf::RectangleShape boxes;
	sf::Text text;
	text.setFont(font);
	text.setCharacterSize(30);

	//TITLE
	text.setPosition(sf::Vector2f(650, 15));
	text.setString("United States Car Accident Database (2016-2020)");
	window.draw(text);

	text.setPosition(sf::Vector2f(1000, 75));
	text.setString("Project by: David Mendez, Jeffrey Yu, Cody Hutcheson");
	window.draw(text);

	boxes.setSize(sf::Vector2f(1230, 10));
	boxes.setPosition(sf::Vector2f(650, 5));
	boxes.setFillColor(sf::Color(0xf7, 0xb5, 0x00, 255));
	window.draw(boxes);

	boxes.setPosition(sf::Vector2f(650, 120)); //650 150
	window.draw(boxes);


	int index = 650;
	boxes.setSize(sf::Vector2f(50, 10));
	boxes.setPosition(sf::Vector2f(index, 60)); //80
	boxes.setFillColor(sf::Color(255, 255, 255, 255));
	while (index < 1850) {
		window.draw(boxes);
		index += 90;
		boxes.setPosition(sf::Vector2f(index, 60));
	}


	//DISPLAY TIME BOX
	boxes.setPosition(sf::Vector2f(20, 90));
	boxes.setSize(sf::Vector2f(600, 120));
	boxes.setFillColor(sf::Color(41, 41, 41, 255));
	window.draw(boxes);
}

void printSupplementalImagesSearch(sf::RenderWindow& window, std::map<string, Button>& buttons) { //print supplemental images for when search tab is selected
	sf::RectangleShape boxes;
	sf::Text text;

	sf::Font font;
	font.loadFromFile("Font/Montserrat-Medium.ttf");

	//YEAR
	boxes.setFillColor(sf::Color(41, 41, 41, 255));
	boxes.setSize(sf::Vector2f(600, 120));
	boxes.setPosition(sf::Vector2f(20, 90));
	window.draw(boxes);
	
	
	text.setFont(font);
	text.setCharacterSize(30);
	text.setPosition(sf::Vector2f(250, 95));
	text.setString("YEAR");
	window.draw(text);

	//MONTH
	boxes.setSize(sf::Vector2f(600, 250));
	boxes.setPosition(sf::Vector2f(20, 220));
	window.draw(boxes);

	text.setPosition(sf::Vector2f(250, 225));
	text.setString("MONTH");
	window.draw(text);

	//CITY
	text.setPosition(sf::Vector2f(35, 480));
	text.setString("CITY");
	window.draw(text);

	//STATE
	text.setPosition(sf::Vector2f(35, 565));
	text.setString("STATE");
	window.draw(text);

	//WEATHER

	text.setPosition(sf::Vector2f(250, 655));
	text.setString("WEATHER");
	window.draw(text);

	//TITLE
	text.setPosition(sf::Vector2f(650, 15));
	text.setString("United States Car Accident Database (2016-2020)");
	window.draw(text);

	text.setPosition(sf::Vector2f(1000, 75));
	text.setString("Project by: David Mendez, Jeffrey Yu, Cody Hutcheson");
	window.draw(text);

	boxes.setSize(sf::Vector2f(1230, 10));
	boxes.setPosition(sf::Vector2f(650, 5));
	boxes.setFillColor(sf::Color(0xf7, 0xb5, 0x00, 255));
	window.draw(boxes);

	boxes.setPosition(sf::Vector2f(650, 120)); //650 150
	window.draw(boxes);


	int index = 650;
	boxes.setSize(sf::Vector2f(50, 10));
	boxes.setPosition(sf::Vector2f(index, 60)); //80
	boxes.setFillColor(sf::Color(255, 255, 255, 255));
	while (index < 1850) {
		window.draw(boxes);
		index += 90;
		boxes.setPosition(sf::Vector2f(index, 60));
	}

}

void loadStates(std::map<string, sf::ConvexShape>& states) { //contains vertices of states to be printed out to screen

	states["FL"] = sf::ConvexShape(6);
	states["FL"].setPoint(0, sf::Vector2f(1461, 725));
	states["FL"].setPoint(1, sf::Vector2f(1465, 755));
	states["FL"].setPoint(2, sf::Vector2f(1577, 765));
	states["FL"].setPoint(3, sf::Vector2f(1623, 871));
	states["FL"].setPoint(4, sf::Vector2f(1660, 860));
	states["FL"].setPoint(5, sf::Vector2f(1600, 725));

	states["GA"] = sf::ConvexShape(5);
	states["GA"].setPoint(0, sf::Vector2f(1515, 718));
	states["GA"].setPoint(1, sf::Vector2f(1494, 616));
	states["GA"].setPoint(2, sf::Vector2f(1549, 616));
	states["GA"].setPoint(3, sf::Vector2f(1603, 674));
	states["GA"].setPoint(4, sf::Vector2f(1591, 718));

	states["AL"] = sf::ConvexShape(5);
	states["AL"].setPoint(0, sf::Vector2f(1436, 756));
	states["AL"].setPoint(1, sf::Vector2f(1461, 715));
	states["AL"].setPoint(2, sf::Vector2f(1505, 715));
	states["AL"].setPoint(3, sf::Vector2f(1490, 616));
	states["AL"].setPoint(4, sf::Vector2f(1436, 616));

	states["MS"] = sf::ConvexShape(6);
	states["MS"].setPoint(0, sf::Vector2f(1427, 760));
	states["MS"].setPoint(1, sf::Vector2f(1425, 619));
	states["MS"].setPoint(2, sf::Vector2f(1392, 619));
	states["MS"].setPoint(3, sf::Vector2f(1361, 735));
	states["MS"].setPoint(4, sf::Vector2f(1391, 735));
	states["MS"].setPoint(5, sf::Vector2f(1408, 760));

	states["LA"] = sf::ConvexShape(6);
	states["LA"].setPoint(0, sf::Vector2f(1314, 787));
	states["LA"].setPoint(1, sf::Vector2f(1390, 794));
	states["LA"].setPoint(2, sf::Vector2f(1390, 739));
	states["LA"].setPoint(3, sf::Vector2f(1355, 740));
	states["LA"].setPoint(4, sf::Vector2f(1365, 687));
	states["LA"].setPoint(5, sf::Vector2f(1307, 695));

	states["TX"] = sf::ConvexShape(11);
	states["TX"].setPoint(0, sf::Vector2f(1096, 711));
	states["TX"].setPoint(1, sf::Vector2f(1108, 596));
	states["TX"].setPoint(2, sf::Vector2f(1166, 606));
	states["TX"].setPoint(3, sf::Vector2f(1207, 657));
	states["TX"].setPoint(4, sf::Vector2f(1293, 656));
	states["TX"].setPoint(5, sf::Vector2f(1304, 776));
	states["TX"].setPoint(6, sf::Vector2f(1229, 819));
	states["TX"].setPoint(7, sf::Vector2f(1225, 897));
	states["TX"].setPoint(8, sf::Vector2f(1127, 774));
	states["TX"].setPoint(9, sf::Vector2f(1080, 789));
	states["TX"].setPoint(10, sf::Vector2f(1025, 711));

	states["SC"] = sf::ConvexShape(3);
	states["SC"].setPoint(0, sf::Vector2f(1553, 612));
	states["SC"].setPoint(1, sf::Vector2f(1605, 666));
	states["SC"].setPoint(2, sf::Vector2f(1647, 609));

	states["NC"] = sf::ConvexShape(4);
	states["NC"].setPoint(0, sf::Vector2f(1520, 604));
	states["NC"].setPoint(1, sf::Vector2f(1652, 604));
	states["NC"].setPoint(2, sf::Vector2f(1704, 538));
	states["NC"].setPoint(3, sf::Vector2f(1567, 559));

	states["TN"] = sf::ConvexShape(4);
	states["TN"].setPoint(0, sf::Vector2f(1391, 613));
	states["TN"].setPoint(1, sf::Vector2f(1511, 608));
	states["TN"].setPoint(2, sf::Vector2f(1553, 556));
	states["TN"].setPoint(3, sf::Vector2f(1406, 582));

	states["AR"] = sf::ConvexShape(4);
	states["AR"].setPoint(0, sf::Vector2f(1304, 683));
	states["AR"].setPoint(1, sf::Vector2f(1370, 679));
	states["AR"].setPoint(2, sf::Vector2f(1388, 593));
	states["AR"].setPoint(3, sf::Vector2f(1295, 594));

	states["OK"] = sf::ConvexShape(6);
	states["OK"].setPoint(0, sf::Vector2f(1113, 586));
	states["OK"].setPoint(1, sf::Vector2f(1169, 598));
	states["OK"].setPoint(2, sf::Vector2f(1211, 648));
	states["OK"].setPoint(3, sf::Vector2f(1288, 647));
	states["OK"].setPoint(4, sf::Vector2f(1283, 577));
	states["OK"].setPoint(5, sf::Vector2f(1109, 569));

	states["NM"] = sf::ConvexShape(5);
	states["NM"].setPoint(0, sf::Vector2f(961, 715));
	states["NM"].setPoint(1, sf::Vector2f(980, 562));
	states["NM"].setPoint(2, sf::Vector2f(1102, 574));
	states["NM"].setPoint(3, sf::Vector2f(1092, 707));
	states["NM"].setPoint(4, sf::Vector2f(1011, 701));

	states["AZ"] = sf::ConvexShape(4);
	states["AZ"].setPoint(0, sf::Vector2f(830, 652));
	states["AZ"].setPoint(1, sf::Vector2f(954, 710));
	states["AZ"].setPoint(2, sf::Vector2f(973, 563));
	states["AZ"].setPoint(3, sf::Vector2f(872, 533));

	states["CA"] = sf::ConvexShape(7);
	states["CA"].setPoint(0, sf::Vector2f(696, 336));
	states["CA"].setPoint(1, sf::Vector2f(782, 364));
	states["CA"].setPoint(2, sf::Vector2f(755, 440));
	states["CA"].setPoint(3, sf::Vector2f(847, 587));
	states["CA"].setPoint(4, sf::Vector2f(821, 644));
	states["CA"].setPoint(5, sf::Vector2f(742, 587));
	states["CA"].setPoint(6, sf::Vector2f(686, 445));

	states["NV"] = sf::ConvexShape(4);
	states["NV"].setPoint(0, sf::Vector2f(798, 364));
	states["NV"].setPoint(1, sf::Vector2f(775, 455));
	states["NV"].setPoint(2, sf::Vector2f(852, 580));
	states["NV"].setPoint(3, sf::Vector2f(893, 391));

	states["OR"] = sf::ConvexShape(4);
	states["OR"].setPoint(0, sf::Vector2f(703, 325));
	states["OR"].setPoint(1, sf::Vector2f(724, 235));
	states["OR"].setPoint(2, sf::Vector2f(868, 274));
	states["OR"].setPoint(3, sf::Vector2f(836, 363));

	states["WA"] = sf::ConvexShape(4);
	states["WA"].setPoint(0, sf::Vector2f(724, 224));
	states["WA"].setPoint(1, sf::Vector2f(762, 135));
	states["WA"].setPoint(2, sf::Vector2f(885, 180));
	states["WA"].setPoint(3, sf::Vector2f(861, 262));

	states["ID"] = sf::ConvexShape(4);
	states["ID"].setPoint(0, sf::Vector2f(895, 196));
	states["ID"].setPoint(1, sf::Vector2f(851, 367));
	states["ID"].setPoint(2, sf::Vector2f(955, 397));
	states["ID"].setPoint(3, sf::Vector2f(971, 336));

	states["MT"] = sf::ConvexShape(4);
	states["MT"].setPoint(0, sf::Vector2f(908, 191));
	states["MT"].setPoint(1, sf::Vector2f(973, 313));
	states["MT"].setPoint(2, sf::Vector2f(1098, 333));
	states["MT"].setPoint(3, sf::Vector2f(1107, 230));

	states["UT"] = sf::ConvexShape(6);
	states["UT"].setPoint(0, sf::Vector2f(906, 395));
	states["UT"].setPoint(1, sf::Vector2f(960, 404));
	states["UT"].setPoint(2, sf::Vector2f(955, 433));
	states["UT"].setPoint(3, sf::Vector2f(984, 442));
	states["UT"].setPoint(4, sf::Vector2f(972, 552));
	states["UT"].setPoint(5, sf::Vector2f(882, 526));

	states["WY"] = sf::ConvexShape(4);
	states["WY"].setPoint(0, sf::Vector2f(980, 319));
	states["WY"].setPoint(1, sf::Vector2f(1098, 346));
	states["WY"].setPoint(2, sf::Vector2f(1086, 443));
	states["WY"].setPoint(3, sf::Vector2f(962, 427));

	states["CO"] = sf::ConvexShape(4);
	states["CO"].setPoint(0, sf::Vector2f(995, 447));
	states["CO"].setPoint(1, sf::Vector2f(985, 547));
	states["CO"].setPoint(2, sf::Vector2f(1114, 563));
	states["CO"].setPoint(3, sf::Vector2f(1130, 459));

	states["ND"] = sf::ConvexShape(4);
	states["ND"].setPoint(0, sf::Vector2f(1114, 224));
	states["ND"].setPoint(1, sf::Vector2f(1229, 224));
	states["ND"].setPoint(2, sf::Vector2f(1245, 319));
	states["ND"].setPoint(3, sf::Vector2f(1108, 310));

	states["SD"] = sf::ConvexShape(4);
	states["SD"].setPoint(0, sf::Vector2f(1112, 322));
	states["SD"].setPoint(1, sf::Vector2f(1106, 390));
	states["SD"].setPoint(2, sf::Vector2f(1245, 399));
	states["SD"].setPoint(3, sf::Vector2f(1242, 326));

	states["NE"] = sf::ConvexShape(6);
	states["NE"].setPoint(0, sf::Vector2f(1102, 399));
	states["NE"].setPoint(1, sf::Vector2f(1246, 409));
	states["NE"].setPoint(2, sf::Vector2f(1267, 488));
	states["NE"].setPoint(3, sf::Vector2f(1141, 479));
	states["NE"].setPoint(4, sf::Vector2f(1141, 455));
	states["NE"].setPoint(5, sf::Vector2f(1096, 445));

	states["KS"] = sf::ConvexShape(4);
	states["KS"].setPoint(0, sf::Vector2f(1141, 488));
	states["KS"].setPoint(1, sf::Vector2f(1271, 496));
	states["KS"].setPoint(2, sf::Vector2f(1278, 564));
	states["KS"].setPoint(3, sf::Vector2f(1126, 562));

	states["MN"] = sf::ConvexShape(5);
	states["MN"].setPoint(0, sf::Vector2f(1237, 235));
	states["MN"].setPoint(1, sf::Vector2f(1354, 255));
	states["MN"].setPoint(2, sf::Vector2f(1319, 319));
	states["MN"].setPoint(3, sf::Vector2f(1348, 386));
	states["MN"].setPoint(4, sf::Vector2f(1256, 386));

	states["IA"] = sf::ConvexShape(4);
	states["IA"].setPoint(0, sf::Vector2f(1255, 397));
	states["IA"].setPoint(1, sf::Vector2f(1352, 398));
	states["IA"].setPoint(2, sf::Vector2f(1339, 466));
	states["IA"].setPoint(3, sf::Vector2f(1273, 467));

	states["MO"] = sf::ConvexShape(4);
	states["MO"].setPoint(0, sf::Vector2f(1278, 475));
	states["MO"].setPoint(1, sf::Vector2f(1342, 475));
	states["MO"].setPoint(2, sf::Vector2f(1402, 579));
	states["MO"].setPoint(3, sf::Vector2f(1296, 590));

	states["IL"] = sf::ConvexShape(5);
	states["IL"].setPoint(0, sf::Vector2f(1369, 418));
	states["IL"].setPoint(1, sf::Vector2f(1426, 428));
	states["IL"].setPoint(2, sf::Vector2f(1427, 538));
	states["IL"].setPoint(3, sf::Vector2f(1405, 565));
	states["IL"].setPoint(4, sf::Vector2f(1347, 475));

	states["KY"] = sf::ConvexShape(7);
	states["KY"].setPoint(0, sf::Vector2f(1409, 577));
	states["KY"].setPoint(1, sf::Vector2f(1519, 557));
	states["KY"].setPoint(2, sf::Vector2f(1551, 534));
	states["KY"].setPoint(3, sf::Vector2f(1538, 509));
	states["KY"].setPoint(4, sf::Vector2f(1488, 500));
	states["KY"].setPoint(5, sf::Vector2f(1463, 533));
	states["KY"].setPoint(6, sf::Vector2f(1431, 540));

	states["WI"] = sf::ConvexShape(5);
	states["WI"].setPoint(0, sf::Vector2f(1336, 295));
	states["WI"].setPoint(1, sf::Vector2f(1419, 327));
	states["WI"].setPoint(2, sf::Vector2f(1410, 406));
	states["WI"].setPoint(3, sf::Vector2f(1370, 407));
	states["WI"].setPoint(4, sf::Vector2f(1330, 318));

	states["IN"] = sf::ConvexShape(4);
	states["IN"].setPoint(0, sf::Vector2f(1436, 434));
	states["IN"].setPoint(1, sf::Vector2f(1486, 429));
	states["IN"].setPoint(2, sf::Vector2f(1487, 496));
	states["IN"].setPoint(3, sf::Vector2f(1435, 532));

	states["VA"] = sf::ConvexShape(4);
	states["VA"].setPoint(0, sf::Vector2f(1540, 553));
	states["VA"].setPoint(1, sf::Vector2f(1691, 534));
	states["VA"].setPoint(2, sf::Vector2f(1634, 470));
	states["VA"].setPoint(3, sf::Vector2f(1589, 523));

	states["WV"] = sf::ConvexShape(5);
	states["WV"].setPoint(0, sf::Vector2f(1548, 507));
	states["WV"].setPoint(1, sf::Vector2f(1556, 529));
	states["WV"].setPoint(2, sf::Vector2f(1632, 463));
	states["WV"].setPoint(3, sf::Vector2f(1595, 472));
	states["WV"].setPoint(4, sf::Vector2f(1576, 460));

	states["OH"] = sf::ConvexShape(5);
	states["OH"].setPoint(0, sf::Vector2f(1493, 426));
	states["OH"].setPoint(1, sf::Vector2f(1566, 407));
	states["OH"].setPoint(2, sf::Vector2f(1571, 453));
	states["OH"].setPoint(3, sf::Vector2f(1540, 503));
	states["OH"].setPoint(4, sf::Vector2f(1499, 494));

	states["MD"] = sf::ConvexShape(6);
	states["MD"].setPoint(0, sf::Vector2f(1602, 454));
	states["MD"].setPoint(1, sf::Vector2f(1678, 439));
	states["MD"].setPoint(2, sf::Vector2f(1693, 486));
	states["MD"].setPoint(3, sf::Vector2f(1658, 488));
	states["MD"].setPoint(4, sf::Vector2f(1633, 458));
	states["MD"].setPoint(5, sf::Vector2f(1602, 466));

	states["PA"] = sf::ConvexShape(4);
	states["PA"].setPoint(0, sf::Vector2f(1567, 400));
	states["PA"].setPoint(1, sf::Vector2f(1671, 379));
	states["PA"].setPoint(2, sf::Vector2f(1675, 434));
	states["PA"].setPoint(3, sf::Vector2f(1584, 454));

	states["NJ"] = sf::ConvexShape(4);
	states["NJ"].setPoint(0, sf::Vector2f(1681, 390));
	states["NJ"].setPoint(1, sf::Vector2f(1697, 391));
	states["NJ"].setPoint(2, sf::Vector2f(1702, 446));
	states["NJ"].setPoint(3, sf::Vector2f(1680, 447));

	states["NY"] = sf::ConvexShape(6);
	states["NY"].setPoint(0, sf::Vector2f(1578, 388));
	states["NY"].setPoint(1, sf::Vector2f(1588l, 353));
	states["NY"].setPoint(2, sf::Vector2f(1674, 286));
	states["NY"].setPoint(3, sf::Vector2f(1705, 385));
	states["NY"].setPoint(4, sf::Vector2f(1678, 390));
	states["NY"].setPoint(5, sf::Vector2f(1671, 367));

	states["CT"] = sf::ConvexShape(4);
	states["CT"].setPoint(0, sf::Vector2f(1709, 364));
	states["CT"].setPoint(1, sf::Vector2f(1732, 358));
	states["CT"].setPoint(2, sf::Vector2f(1729, 378));
	states["CT"].setPoint(3, sf::Vector2f(1705, 386));

	states["RI"] = sf::ConvexShape(4);
	states["RI"].setPoint(0, sf::Vector2f(1739, 364));
	states["RI"].setPoint(1, sf::Vector2f(1752, 361));
	states["RI"].setPoint(2, sf::Vector2f(1752, 377));
	states["RI"].setPoint(3, sf::Vector2f(1738, 377));

	states["MA"] = sf::ConvexShape(5);
	states["MA"].setPoint(0, sf::Vector2f(1702, 340));
	states["MA"].setPoint(1, sf::Vector2f(1742, 328));
	states["MA"].setPoint(2, sf::Vector2f(1775, 352));
	states["MA"].setPoint(3, sf::Vector2f(1732, 346));
	states["MA"].setPoint(4, sf::Vector2f(1706, 354));

	states["VT"] = sf::ConvexShape(4);
	states["VT"].setPoint(0, sf::Vector2f(1681, 282));
	states["VT"].setPoint(1, sf::Vector2f(1711, 272));
	states["VT"].setPoint(2, sf::Vector2f(1713, 329));
	states["VT"].setPoint(3, sf::Vector2f(1697, 336));

	states["NH"] = sf::ConvexShape(4);
	states["NH"].setPoint(0, sf::Vector2f(1713, 275));
	states["NH"].setPoint(1, sf::Vector2f(1732, 265));
	states["NH"].setPoint(2, sf::Vector2f(1750, 316));
	states["NH"].setPoint(3, sf::Vector2f(1717, 328));

	states["ME"] = sf::ConvexShape(5);
	states["ME"].setPoint(0, sf::Vector2f(1735, 261));
	states["ME"].setPoint(1, sf::Vector2f(1751, 309));
	states["ME"].setPoint(2, sf::Vector2f(1799, 239));
	states["ME"].setPoint(3, sf::Vector2f(1767, 185));
	states["ME"].setPoint(4, sf::Vector2f(1735, 188));

	states["MI"] = sf::ConvexShape(7);
	states["MI"].setPoint(0, sf::Vector2f(1370, 297));
	states["MI"].setPoint(1, sf::Vector2f(1404, 270));
	states["MI"].setPoint(2, sf::Vector2f(1485, 283));
	states["MI"].setPoint(3, sf::Vector2f(1527, 403));
	states["MI"].setPoint(4, sf::Vector2f(1444, 423));
	states["MI"].setPoint(5, sf::Vector2f(1456, 321));
	states["MI"].setPoint(6, sf::Vector2f(1422, 322));

	states["AK"] = sf::ConvexShape(9);
	states["AK"].setPoint(0, sf::Vector2f(764, 872));
	states["AK"].setPoint(1, sf::Vector2f(841, 787));
	states["AK"].setPoint(2, sf::Vector2f(870, 723));
	states["AK"].setPoint(3, sf::Vector2f(916, 710));
	states["AK"].setPoint(4, sf::Vector2f(966, 737));
	states["AK"].setPoint(5, sf::Vector2f(963, 799));
	states["AK"].setPoint(6, sf::Vector2f(1013, 888));
	states["AK"].setPoint(7, sf::Vector2f(910, 831));
	states["AK"].setPoint(8, sf::Vector2f(848, 861));

	states["HI"] = sf::ConvexShape(3);
	states["HI"].setPoint(0, sf::Vector2f(997, 786));
	states["HI"].setPoint(1, sf::Vector2f(1025, 779));
	states["HI"].setPoint(2, sf::Vector2f(1013, 803));

	states["HI2"] = sf::ConvexShape(3);
	states["HI2"].setPoint(0, sf::Vector2f(1039, 799));
	states["HI2"].setPoint(1, sf::Vector2f(1064, 793));
	states["HI2"].setPoint(2, sf::Vector2f(1060, 820));

	states["HI3"] = sf::ConvexShape(3);
	states["HI3"].setPoint(0, sf::Vector2f(1075, 815));
	states["HI3"].setPoint(1, sf::Vector2f(1109, 822));
	states["HI3"].setPoint(2, sf::Vector2f(1093, 841));

	states["HI4"] = sf::ConvexShape(3);
	states["HI4"].setPoint(0, sf::Vector2f(1107, 839));
	states["HI4"].setPoint(1, sf::Vector2f(1143, 864));
	states["HI4"].setPoint(2, sf::Vector2f(1109, 886));


}
void printStates(sf::RenderWindow& window, std::map<string, sf::ConvexShape>& states) { //prints states to screen
	for (auto iter = states.begin(); iter != states.end(); iter++) {
		window.draw((*iter).second);
	}
}
void displayNewBoard(sf::RenderWindow& window, std::map<string, Button>& buttons, sf::Texture* search, sf::Texture* result, std::vector<sf::Texture*> vect, std::map<string, sf::ConvexShape>& states, sf::Text& c, sf::Text& s, RedBlackTree& rbtree, MaxHeap<Accident>& maxheap, bool results) {

	//update the board

	window.clear(sf::Color(41, 41, 41, 255)); 

	sf::RectangleShape sidebar;								//draw the sidebar
	sidebar.setFillColor(sf::Color(0x21, 0x21, 0x21, 0xff)); 
	sidebar.setSize(sf::Vector2f(633, 1000));
	sidebar.setPosition(sf::Vector2f(0, 60));
	window.draw(sidebar);

	sf::RectangleShape searchResult;						//search and result buttons

	if (buttons["searchResults"].isPressed) { //if results tab is selected:
		searchResult.setTexture(search);

		searchResult.setSize(sf::Vector2f(633, 80));
		searchResult.setPosition(sf::Vector2f(0, 0));
		window.draw(searchResult);

		sf::Font font;
		font.loadFromFile("Font/Montserrat-Medium.ttf");

		printSupplementalImagesResults(window, buttons);

		if (results) {
			vector<Node*> treeAccidents;
			vector<Accident> maxHeapAccidents;

			rbtree.FindXMostSevereAccidents(10, treeAccidents); //get top 10 accidents for tree
			std::cout << rbtree.height();

			MaxHeap<Accident> heap = maxheap;

			for (int i = 0; i < 10; i++) { //get top 10 accidents for heap
				maxHeapAccidents.push_back(heap.top());
				heap.pop();
			}

			std::cout << treeAccidents.size() << " " << maxHeapAccidents.size() << std::endl;

			for (int i = 0; i < 10; i++) {

				std::cout << i << " tree: " << treeAccidents[i]->calculateSeverity() << " heap: " << maxHeapAccidents[i].getWeightedSeverity() << std::endl;
				states[treeAccidents[i]->state].setFillColor(sf::Color(0x03, 0xa9, 0xf4, 255));
			}



		}




	}
	else { //if search tab is selected
		searchResult.setTexture(result);

		searchResult.setSize(sf::Vector2f(633, 80));
		searchResult.setPosition(sf::Vector2f(0, 0));
		window.draw(searchResult);

		sf::Font font;
		font.loadFromFile("Font/Montserrat-Medium.ttf");



		printSupplementalImagesSearch(window, buttons);


		auto weatherIter = vect.begin();

		for (auto iter = buttons.begin(); iter != buttons.end(); iter++) { //print out each button
			if ((*iter).first == "searchResults") {

				continue;
			}
			sf::RectangleShape button;
			if ((*iter).second.isWeather) { //if weather button, print correct image showing it has been selected

				if ((*iter).second.isPressed) {
					button.setTexture(*weatherIter);
					weatherIter++;
				}
				else {
					button.setTexture(*(weatherIter + 4));
					weatherIter++;
				}

			}
			else if ((*iter).second.isPressed) { //if other button: if pressed, outline it in white to show this
				button.setOutlineColor(sf::Color(255, 255, 255, 255));
				button.setOutlineThickness(1.0);
				button.setFillColor(sf::Color(41, 41, 41, 255));
			}
			else { //else, show no border
				button.setFillColor(sf::Color(41, 41, 41, 255));
			}

			//print button
			button.setSize(sf::Vector2f((*iter).second.height, (*iter).second.width));
			button.setPosition(sf::Vector2f((*iter).second.yPos, (*iter).second.xPos));
			sf::Text text((*iter).second.text, font, 20);
			text.setPosition((*iter).second.yPos + 20, (*iter).second.xPos);
			window.draw(button);
			window.draw(text);


		}

		//draw the new texts in text boxes
		window.draw(c);
		window.draw(s);
	}
	printStates(window, states); //print states

	window.display(); //display new content


}
