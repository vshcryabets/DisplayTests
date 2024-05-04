Purpose of this project is to find which display is better for DIY  handheld devices.

I want to check different display modules and measure which current those modules requires.


## LCD1602 via the PCF8574 I2C IO extender


## SSD1306 OLED 0.96 128x64

|Test, no|Description|Current,uA|
|--|--|--|
|1|Blank screen|2047|
|2|25% fill|6135|
|3|50% fill|11500|
|4|100% fill|19900|

## TM1636

|Test, no|Brightness|Description|Current,uA/mA|
|--|--|--|--|
|1|0x00|Blank|74ua|
|2|0x00|25% fill|536ua|
|3|0x00|50% fill|1043uA|
|4|0x00|100% fill|1966uA|
|5|0x01|Blank|74ua|
|6|0x01|25% fill|992ua|
|7|0x01|50% fill|1996uA|
|8|0x01|100% fill|3830uA|
|9|0x03|Blank|74ua|
|10|0x03|25% fill|4610ua|
|11|0x03|50% fill|9568mA|
|12|0x03|100% fill|18.6mA|
|13|0x05|Blank|74ua|
|14|0x05|25% fill|5505uA|
|15|0x05|50% fill|11.4mA|
|16|0x05|100% fill|22.2mA|
|17|0x07|Blank|74ua|
|18|0x07|25% fill|6397ua|
|19|0x07|50% fill|13.3mA|
|20|0x07|100% fill|25.9mA|

0-level brightness is hard to see in bright lighting.
Here is few samples of 0-level brightness:

<img src="./img/tm1637_0_fill25.jpg">
<img src="./img/tm1637_0_fill50.jpg">
<img src="./img/tm1637_0_fill100.jpg">