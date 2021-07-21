#pragma once
#include <SFML/Graphics.hpp>
#include "VisualElements.h"
#include <algorithm>

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

	states["Florida"] = sf::ConvexShape(6);
	states["Florida"].setPoint(0, sf::Vector2f(1461, 725));
	states["Florida"].setPoint(1, sf::Vector2f(1465, 755));
	states["Florida"].setPoint(2, sf::Vector2f(1577, 765));
	states["Florida"].setPoint(3, sf::Vector2f(1623, 871));
	states["Florida"].setPoint(4, sf::Vector2f(1660, 860));
	states["Florida"].setPoint(5, sf::Vector2f(1600, 725));
	states["Florida"].setFillColor(sf::Color(0x01, 0x57, 0x9b, 255));

	states["Georgia"] = sf::ConvexShape(5);
	states["Georgia"].setPoint(0, sf::Vector2f(1515, 718));
	states["Georgia"].setPoint(1, sf::Vector2f(1494, 616));
	states["Georgia"].setPoint(2, sf::Vector2f(1549, 616));
	states["Georgia"].setPoint(3, sf::Vector2f(1603, 674));
	states["Georgia"].setPoint(4, sf::Vector2f(1591, 718));
	states["Georgia"].setFillColor(sf::Color(0x02, 0x88, 0xd1, 255));

	states["Alabama"] = sf::ConvexShape(5);
	states["Alabama"].setPoint(0, sf::Vector2f(1436, 756));
	states["Alabama"].setPoint(1, sf::Vector2f(1461, 715));
	states["Alabama"].setPoint(2, sf::Vector2f(1505, 715));
	states["Alabama"].setPoint(3, sf::Vector2f(1490, 616));
	states["Alabama"].setPoint(4, sf::Vector2f(1436, 616));
	states["Alabama"].setFillColor(sf::Color(255, 255, 255, 255));

	states["Mississippi"] = sf::ConvexShape(6);
	states["Mississippi"].setPoint(0, sf::Vector2f(1427, 760));
	states["Mississippi"].setPoint(1, sf::Vector2f(1425, 619));
	states["Mississippi"].setPoint(2, sf::Vector2f(1392, 619));
	states["Mississippi"].setPoint(3, sf::Vector2f(1361, 735));
	states["Mississippi"].setPoint(4, sf::Vector2f(1391, 735));
	states["Mississippi"].setPoint(5, sf::Vector2f(1408, 760));
	states["Mississippi"].setFillColor(sf::Color(0x81, 0xd4, 0xfa, 255));

	states["Louisiana"] = sf::ConvexShape(6);
	states["Louisiana"].setPoint(0, sf::Vector2f(1314, 787));
	states["Louisiana"].setPoint(1, sf::Vector2f(1390, 794));
	states["Louisiana"].setPoint(2, sf::Vector2f(1390, 739));
	states["Louisiana"].setPoint(3, sf::Vector2f(1355, 740));
	states["Louisiana"].setPoint(4, sf::Vector2f(1365, 687));
	states["Louisiana"].setPoint(5, sf::Vector2f(1307, 695));

	states["Texas"] = sf::ConvexShape(11);
	states["Texas"].setPoint(0, sf::Vector2f(1096, 711));
	states["Texas"].setPoint(1, sf::Vector2f(1108, 596));
	states["Texas"].setPoint(2, sf::Vector2f(1166, 606));
	states["Texas"].setPoint(3, sf::Vector2f(1207, 657));
	states["Texas"].setPoint(4, sf::Vector2f(1293, 656));
	states["Texas"].setPoint(5, sf::Vector2f(1304, 776));
	states["Texas"].setPoint(6, sf::Vector2f(1229, 819));
	states["Texas"].setPoint(7, sf::Vector2f(1225, 897));
	states["Texas"].setPoint(8, sf::Vector2f(1127, 774));
	states["Texas"].setPoint(9, sf::Vector2f(1080, 789));
	states["Texas"].setPoint(10, sf::Vector2f(1025, 711));

	states["South Carolina"] = sf::ConvexShape(3);
	states["South Carolina"].setPoint(0, sf::Vector2f(1553, 612));
	states["South Carolina"].setPoint(1, sf::Vector2f(1605, 666));
	states["South Carolina"].setPoint(2, sf::Vector2f(1647, 609));

	states["North Carolina"] = sf::ConvexShape(4);
	states["North Carolina"].setPoint(0, sf::Vector2f(1520, 604));
	states["North Carolina"].setPoint(1, sf::Vector2f(1652, 604));
	states["North Carolina"].setPoint(2, sf::Vector2f(1704, 538));
	states["North Carolina"].setPoint(3, sf::Vector2f(1567, 559));

	states["Tennessee"] = sf::ConvexShape(4);
	states["Tennessee"].setPoint(0, sf::Vector2f(1391, 613));
	states["Tennessee"].setPoint(1, sf::Vector2f(1511, 608));
	states["Tennessee"].setPoint(2, sf::Vector2f(1553, 556));
	states["Tennessee"].setPoint(3, sf::Vector2f(1406, 582));

	states["Arkansas"] = sf::ConvexShape(4);
	states["Arkansas"].setPoint(0, sf::Vector2f(1304, 683));
	states["Arkansas"].setPoint(1, sf::Vector2f(1370, 679));
	states["Arkansas"].setPoint(2, sf::Vector2f(1388, 593));
	states["Arkansas"].setPoint(3, sf::Vector2f(1295, 594));

	states["Oklahoma"] = sf::ConvexShape(6);
	states["Oklahoma"].setPoint(0, sf::Vector2f(1113, 586));
	states["Oklahoma"].setPoint(1, sf::Vector2f(1169, 598));
	states["Oklahoma"].setPoint(2, sf::Vector2f(1211, 648));
	states["Oklahoma"].setPoint(3, sf::Vector2f(1288, 647));
	states["Oklahoma"].setPoint(4, sf::Vector2f(1283, 577));
	states["Oklahoma"].setPoint(5, sf::Vector2f(1109, 569));

	states["New Mexico"] = sf::ConvexShape(5);
	states["New Mexico"].setPoint(0, sf::Vector2f(961, 715));
	states["New Mexico"].setPoint(1, sf::Vector2f(980, 562));
	states["New Mexico"].setPoint(2, sf::Vector2f(1102, 574));
	states["New Mexico"].setPoint(3, sf::Vector2f(1092, 707));
	states["New Mexico"].setPoint(4, sf::Vector2f(1011, 701));

	states["Arizona"] = sf::ConvexShape(4);
	states["Arizona"].setPoint(0, sf::Vector2f(830, 652));
	states["Arizona"].setPoint(1, sf::Vector2f(954, 710));
	states["Arizona"].setPoint(2, sf::Vector2f(973, 563));
	states["Arizona"].setPoint(3, sf::Vector2f(872, 533));

	states["California"] = sf::ConvexShape(7);
	states["California"].setPoint(0, sf::Vector2f(696, 336));
	states["California"].setPoint(1, sf::Vector2f(782, 364));
	states["California"].setPoint(2, sf::Vector2f(755, 440));
	states["California"].setPoint(3, sf::Vector2f(847, 587));
	states["California"].setPoint(4, sf::Vector2f(821, 644));
	states["California"].setPoint(5, sf::Vector2f(742, 587));
	states["California"].setPoint(6, sf::Vector2f(686, 445));

	states["Nevada"] = sf::ConvexShape(4);
	states["Nevada"].setPoint(0, sf::Vector2f(798, 364));
	states["Nevada"].setPoint(1, sf::Vector2f(775, 455));
	states["Nevada"].setPoint(2, sf::Vector2f(852, 580));
	states["Nevada"].setPoint(3, sf::Vector2f(893, 391));

	states["Oregon"] = sf::ConvexShape(4);
	states["Oregon"].setPoint(0, sf::Vector2f(703, 325));
	states["Oregon"].setPoint(1, sf::Vector2f(724, 235));
	states["Oregon"].setPoint(2, sf::Vector2f(868, 274));
	states["Oregon"].setPoint(3, sf::Vector2f(836, 363));

	states["Washington"] = sf::ConvexShape(4);
	states["Washington"].setPoint(0, sf::Vector2f(724, 224));
	states["Washington"].setPoint(1, sf::Vector2f(762, 135));
	states["Washington"].setPoint(2, sf::Vector2f(885, 180));
	states["Washington"].setPoint(3, sf::Vector2f(861, 262));

	states["Idaho"] = sf::ConvexShape(4);
	states["Idaho"].setPoint(0, sf::Vector2f(895, 196));
	states["Idaho"].setPoint(1, sf::Vector2f(851, 367));
	states["Idaho"].setPoint(2, sf::Vector2f(955, 397));
	states["Idaho"].setPoint(3, sf::Vector2f(971, 336));

	states["Montana"] = sf::ConvexShape(4);
	states["Montana"].setPoint(0, sf::Vector2f(908, 191));
	states["Montana"].setPoint(1, sf::Vector2f(973, 313));
	states["Montana"].setPoint(2, sf::Vector2f(1098, 333));
	states["Montana"].setPoint(3, sf::Vector2f(1107, 230));

	states["Utah"] = sf::ConvexShape(6);
	states["Utah"].setPoint(0, sf::Vector2f(906, 395));
	states["Utah"].setPoint(1, sf::Vector2f(960, 404));
	states["Utah"].setPoint(2, sf::Vector2f(955, 433));
	states["Utah"].setPoint(3, sf::Vector2f(984, 442));
	states["Utah"].setPoint(4, sf::Vector2f(972, 552));
	states["Utah"].setPoint(5, sf::Vector2f(882, 526));

	states["Wyoming"] = sf::ConvexShape(4);
	states["Wyoming"].setPoint(0, sf::Vector2f(980, 319));
	states["Wyoming"].setPoint(1, sf::Vector2f(1098, 346));
	states["Wyoming"].setPoint(2, sf::Vector2f(1086, 443));
	states["Wyoming"].setPoint(3, sf::Vector2f(962, 427));

	states["Colorado"] = sf::ConvexShape(4);
	states["Colorado"].setPoint(0, sf::Vector2f(995, 447));
	states["Colorado"].setPoint(1, sf::Vector2f(985, 547));
	states["Colorado"].setPoint(2, sf::Vector2f(1114, 563));
	states["Colorado"].setPoint(3, sf::Vector2f(1130, 459));

	states["North Dakota"] = sf::ConvexShape(4);
	states["North Dakota"].setPoint(0, sf::Vector2f(1114, 224));
	states["North Dakota"].setPoint(1, sf::Vector2f(1229, 224));
	states["North Dakota"].setPoint(2, sf::Vector2f(1245, 319));
	states["North Dakota"].setPoint(3, sf::Vector2f(1108, 310));

	states["South Dakota"] = sf::ConvexShape(4);
	states["South Dakota"].setPoint(0, sf::Vector2f(1112, 322));
	states["South Dakota"].setPoint(1, sf::Vector2f(1106, 390));
	states["South Dakota"].setPoint(2, sf::Vector2f(1245, 399));
	states["South Dakota"].setPoint(3, sf::Vector2f(1242, 326));

	states["Nebraska"] = sf::ConvexShape(6);
	states["Nebraska"].setPoint(0, sf::Vector2f(1102, 399));
	states["Nebraska"].setPoint(1, sf::Vector2f(1246, 409));
	states["Nebraska"].setPoint(2, sf::Vector2f(1267, 488));
	states["Nebraska"].setPoint(3, sf::Vector2f(1141, 479));
	states["Nebraska"].setPoint(4, sf::Vector2f(1141, 455));
	states["Nebraska"].setPoint(5, sf::Vector2f(1096, 445));

	states["Kansas"] = sf::ConvexShape(4);
	states["Kansas"].setPoint(0, sf::Vector2f(1141, 488));
	states["Kansas"].setPoint(1, sf::Vector2f(1271, 496));
	states["Kansas"].setPoint(2, sf::Vector2f(1278, 564));
	states["Kansas"].setPoint(3, sf::Vector2f(1126, 562));

	states["Minnesota"] = sf::ConvexShape(5);
	states["Minnesota"].setPoint(0, sf::Vector2f(1237, 235));
	states["Minnesota"].setPoint(1, sf::Vector2f(1354, 255));
	states["Minnesota"].setPoint(2, sf::Vector2f(1319, 319));
	states["Minnesota"].setPoint(3, sf::Vector2f(1348, 386));
	states["Minnesota"].setPoint(4, sf::Vector2f(1256, 386));

	states["Iowa"] = sf::ConvexShape(4);
	states["Iowa"].setPoint(0, sf::Vector2f(1255, 397));
	states["Iowa"].setPoint(1, sf::Vector2f(1352, 398));
	states["Iowa"].setPoint(2, sf::Vector2f(1339, 466));
	states["Iowa"].setPoint(3, sf::Vector2f(1273, 467));

	states["Missouri"] = sf::ConvexShape(4);
	states["Missouri"].setPoint(0, sf::Vector2f(1278, 475));
	states["Missouri"].setPoint(1, sf::Vector2f(1342, 475));
	states["Missouri"].setPoint(2, sf::Vector2f(1402, 579));
	states["Missouri"].setPoint(3, sf::Vector2f(1296, 590));

	states["Illinois"] = sf::ConvexShape(5);
	states["Illinois"].setPoint(0, sf::Vector2f(1369, 418));
	states["Illinois"].setPoint(1, sf::Vector2f(1426, 428));
	states["Illinois"].setPoint(2, sf::Vector2f(1427, 538));
	states["Illinois"].setPoint(3, sf::Vector2f(1405, 565));
	states["Illinois"].setPoint(4, sf::Vector2f(1347, 475));

	states["Kentucky"] = sf::ConvexShape(7);
	states["Kentucky"].setPoint(0, sf::Vector2f(1409, 577));
	states["Kentucky"].setPoint(1, sf::Vector2f(1519, 557));
	states["Kentucky"].setPoint(2, sf::Vector2f(1551, 534));
	states["Kentucky"].setPoint(3, sf::Vector2f(1538, 509));
	states["Kentucky"].setPoint(4, sf::Vector2f(1488, 500));
	states["Kentucky"].setPoint(5, sf::Vector2f(1463, 533));
	states["Kentucky"].setPoint(6, sf::Vector2f(1431, 540));

	states["Wisconsin"] = sf::ConvexShape(5);
	states["Wisconsin"].setPoint(0, sf::Vector2f(1336, 295));
	states["Wisconsin"].setPoint(1, sf::Vector2f(1419, 327));
	states["Wisconsin"].setPoint(2, sf::Vector2f(1410, 406));
	states["Wisconsin"].setPoint(3, sf::Vector2f(1370, 407));
	states["Wisconsin"].setPoint(4, sf::Vector2f(1330, 318));

	states["Indiana"] = sf::ConvexShape(4);
	states["Indiana"].setPoint(0, sf::Vector2f(1436, 434));
	states["Indiana"].setPoint(1, sf::Vector2f(1486, 429));
	states["Indiana"].setPoint(2, sf::Vector2f(1487, 496));
	states["Indiana"].setPoint(3, sf::Vector2f(1435, 532));

	states["Virginia"] = sf::ConvexShape(4);
	states["Virginia"].setPoint(0, sf::Vector2f(1540, 553));
	states["Virginia"].setPoint(1, sf::Vector2f(1691, 534));
	states["Virginia"].setPoint(2, sf::Vector2f(1634, 470));
	states["Virginia"].setPoint(3, sf::Vector2f(1589, 523));

	states["West Virginia"] = sf::ConvexShape(5);
	states["West Virginia"].setPoint(0, sf::Vector2f(1548, 507));
	states["West Virginia"].setPoint(1, sf::Vector2f(1556, 529));
	states["West Virginia"].setPoint(2, sf::Vector2f(1632, 463));
	states["West Virginia"].setPoint(3, sf::Vector2f(1595, 472));
	states["West Virginia"].setPoint(4, sf::Vector2f(1576, 460));

	states["Ohio"] = sf::ConvexShape(5);
	states["Ohio"].setPoint(0, sf::Vector2f(1493, 426));
	states["Ohio"].setPoint(1, sf::Vector2f(1566, 407));
	states["Ohio"].setPoint(2, sf::Vector2f(1571, 453));
	states["Ohio"].setPoint(3, sf::Vector2f(1540, 503));
	states["Ohio"].setPoint(4, sf::Vector2f(1499, 494));

	states["Maryland"] = sf::ConvexShape(6);
	states["Maryland"].setPoint(0, sf::Vector2f(1602, 454));
	states["Maryland"].setPoint(1, sf::Vector2f(1678, 439));
	states["Maryland"].setPoint(2, sf::Vector2f(1693, 486));
	states["Maryland"].setPoint(3, sf::Vector2f(1658, 488));
	states["Maryland"].setPoint(4, sf::Vector2f(1633, 458));
	states["Maryland"].setPoint(5, sf::Vector2f(1602, 466));

	states["Pennsylvania"] = sf::ConvexShape(4);
	states["Pennsylvania"].setPoint(0, sf::Vector2f(1567, 400));
	states["Pennsylvania"].setPoint(1, sf::Vector2f(1671, 379));
	states["Pennsylvania"].setPoint(2, sf::Vector2f(1675, 434));
	states["Pennsylvania"].setPoint(3, sf::Vector2f(1584, 454));

	states["New Jersey"] = sf::ConvexShape(4);
	states["New Jersey"].setPoint(0, sf::Vector2f(1681, 390));
	states["New Jersey"].setPoint(1, sf::Vector2f(1697, 391));
	states["New Jersey"].setPoint(2, sf::Vector2f(1702, 446));
	states["New Jersey"].setPoint(3, sf::Vector2f(1680, 447));

	states["New York"] = sf::ConvexShape(6);
	states["New York"].setPoint(0, sf::Vector2f(1578, 388));
	states["New York"].setPoint(1, sf::Vector2f(1588l, 353));
	states["New York"].setPoint(2, sf::Vector2f(1674, 286));
	states["New York"].setPoint(3, sf::Vector2f(1705, 385));
	states["New York"].setPoint(4, sf::Vector2f(1678, 390));
	states["New York"].setPoint(5, sf::Vector2f(1671, 367));

	states["Connecticut"] = sf::ConvexShape(4);
	states["Connecticut"].setPoint(0, sf::Vector2f(1709, 364));
	states["Connecticut"].setPoint(1, sf::Vector2f(1732, 358));
	states["Connecticut"].setPoint(2, sf::Vector2f(1729, 378));
	states["Connecticut"].setPoint(3, sf::Vector2f(1705, 386));

	states["Rhode Island"] = sf::ConvexShape(4);
	states["Rhode Island"].setPoint(0, sf::Vector2f(1739, 364));
	states["Rhode Island"].setPoint(1, sf::Vector2f(1752, 361));
	states["Rhode Island"].setPoint(2, sf::Vector2f(1752, 377));
	states["Rhode Island"].setPoint(3, sf::Vector2f(1738, 377));

	states["Massachusetts"] = sf::ConvexShape(5);
	states["Massachusetts"].setPoint(0, sf::Vector2f(1702, 340));
	states["Massachusetts"].setPoint(1, sf::Vector2f(1742, 328));
	states["Massachusetts"].setPoint(2, sf::Vector2f(1775, 352));
	states["Massachusetts"].setPoint(3, sf::Vector2f(1732, 346));
	states["Massachusetts"].setPoint(4, sf::Vector2f(1706, 354));

	states["Vermont"] = sf::ConvexShape(4);
	states["Vermont"].setPoint(0, sf::Vector2f(1681, 282));
	states["Vermont"].setPoint(1, sf::Vector2f(1711, 272));
	states["Vermont"].setPoint(2, sf::Vector2f(1713, 329));
	states["Vermont"].setPoint(3, sf::Vector2f(1697, 336));

	states["New Hampshire"] = sf::ConvexShape(4);
	states["New Hampshire"].setPoint(0, sf::Vector2f(1713, 275));
	states["New Hampshire"].setPoint(1, sf::Vector2f(1732, 265));
	states["New Hampshire"].setPoint(2, sf::Vector2f(1750, 316));
	states["New Hampshire"].setPoint(3, sf::Vector2f(1717, 328));

	states["Maine"] = sf::ConvexShape(5);
	states["Maine"].setPoint(0, sf::Vector2f(1735, 261));
	states["Maine"].setPoint(1, sf::Vector2f(1751, 309));
	states["Maine"].setPoint(2, sf::Vector2f(1799, 239));
	states["Maine"].setPoint(3, sf::Vector2f(1767, 185));
	states["Maine"].setPoint(4, sf::Vector2f(1735, 188));

	states["Michigan"] = sf::ConvexShape(7);
	states["Michigan"].setPoint(0, sf::Vector2f(1370, 297));
	states["Michigan"].setPoint(1, sf::Vector2f(1404, 270));
	states["Michigan"].setPoint(2, sf::Vector2f(1485, 283));
	states["Michigan"].setPoint(3, sf::Vector2f(1527, 403));
	states["Michigan"].setPoint(4, sf::Vector2f(1444, 423));
	states["Michigan"].setPoint(5, sf::Vector2f(1456, 321));
	states["Michigan"].setPoint(6, sf::Vector2f(1422, 322));

	states["Alaska"] = sf::ConvexShape(9);
	states["Alaska"].setPoint(0, sf::Vector2f(764, 872));
	states["Alaska"].setPoint(1, sf::Vector2f(841, 787));
	states["Alaska"].setPoint(2, sf::Vector2f(870, 723));
	states["Alaska"].setPoint(3, sf::Vector2f(916, 710));
	states["Alaska"].setPoint(4, sf::Vector2f(966, 737));
	states["Alaska"].setPoint(5, sf::Vector2f(963, 799));
	states["Alaska"].setPoint(6, sf::Vector2f(1013, 888));
	states["Alaska"].setPoint(7, sf::Vector2f(910, 831));
	states["Alaska"].setPoint(8, sf::Vector2f(848, 861));

	states["Hawaii1"] = sf::ConvexShape(3);
	states["Hawaii1"].setPoint(0, sf::Vector2f(997, 786));
	states["Hawaii1"].setPoint(1, sf::Vector2f(1025, 779));
	states["Hawaii1"].setPoint(2, sf::Vector2f(1013, 803));

	states["Hawaii2"] = sf::ConvexShape(3);
	states["Hawaii2"].setPoint(0, sf::Vector2f(1039, 799));
	states["Hawaii2"].setPoint(1, sf::Vector2f(1064, 793));
	states["Hawaii2"].setPoint(2, sf::Vector2f(1060, 820));

	states["Hawaii3"] = sf::ConvexShape(3);
	states["Hawaii3"].setPoint(0, sf::Vector2f(1075, 815));
	states["Hawaii3"].setPoint(1, sf::Vector2f(1109, 822));
	states["Hawaii3"].setPoint(2, sf::Vector2f(1093, 841));

	states["Hawaii4"] = sf::ConvexShape(3);
	states["Hawaii4"].setPoint(0, sf::Vector2f(1107, 839));
	states["Hawaii4"].setPoint(1, sf::Vector2f(1143, 864));
	states["Hawaii4"].setPoint(2, sf::Vector2f(1109, 886));


}
void printStates(sf::RenderWindow& window, std::map<string, sf::ConvexShape>& states) { //prints states to screen
	for (auto iter = states.begin(); iter != states.end(); iter++) {
		window.draw((*iter).second);
	}
}
void displayNewBoard(sf::RenderWindow& window, std::map<string, Button>& buttons, sf::Texture* search, sf::Texture* result, std::vector<sf::Texture*> vect, std::map<string, sf::ConvexShape> states, sf::Text& c, sf::Text& s) {

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
