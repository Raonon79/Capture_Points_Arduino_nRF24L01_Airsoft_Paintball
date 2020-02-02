# Capture Points - Arduino + nRF24L01 - Airsoft / Paintball
**Range Tester is free for use. Project Capture Points is paid, if you want to buy, contact at: martinius96@gmail.com**
# Description of functionality and use:
* The system is designed for Airsoft / Paintball / Nerf Wars for Capture points game mode.
* System is using 2 points, each consist of: Arduino Nano, 2 diodes, 2 buzzers, 2 WiFi modules nRF24l01( + PA + LNA). 
* In addition to these components, the buttons for each of the teams are also placed on the boards.
* One button is for Team 1 (blue team) and second for Team 2 (red team). In the event of a cast, they press their button to change the color of the point according to their team.
* If one team occupies both points, the detector sounds at both points (the game ends or continues according to the organizer"s rules). This may mean, for example, only the end of the round or the addition of points. 
* In real-time, both Arduina communicate with the nRF24l01 + PA + LNA modules. The response between the two Arduinos is at 1-5ms.
* Thanks to the nRF24l01 modules, it is possible to communicate with Arduinos at huge distances of hundreds of meters in an uninterrupted environment (nRF24l01 offers over 120 channels for communication to 2.4Ghz.) 
* With an external 5v (if using YL-105 adapter for maximum TX power) / 3.3v source it is possible to communicate up to 1.1 kilometers.
# Hardware requirements:
* <img src="https://www.vanheusden.com/modsyn/cvos/imgs/arduino-nano.jpg" width="128" height="128"> **2x Arduino Nano**
* <img src="https://www.robotop.lv/638-home/nrf24l01-wireless-module-24g.jpg" width="128" height="128"> **2x Nrf24l01 or with external antenna( + PA + LNA)**
* <img src="https://camo.githubusercontent.com/969c923235b513193b50de054f0b1263d0b5563e/68747470733a2f2f692e696d6775722e636f6d2f4a4d646b4254522e706e67" width="128" height="128"> **4x Pushbuttons**
* <img src="https://media.rs-online.com/t_large/F8609696-01.jpg" width="128" height="128"> **4x LED diodes (2x red, 2x blue)**
* <img src="https://www.gotron.be/media/catalog/product/cache/small_image/256x256/beff4985b56e3afdbeabfc89641a4582/b/e/bev18_1_1.jpg" width="128" height="128"> **2x Buzzer**
# Block scheme:
![Block scheme - Airsoft Paintball Capture points - Arduino + nRF24L01](https://i.imgur.com/hglnwgX.jpg)
# Wiring:
![Wiring - Airsoft Paintball Capture points - Arduino + nRF24L01](https://i.imgur.com/noWoy6S.png)
# Example of usage:
![Example - nRF24L01 - Capture Points with Arduino Mega](http://imag.sector.sk/files/users/blog/326500/13107/326500-1181972-960.jpg)
