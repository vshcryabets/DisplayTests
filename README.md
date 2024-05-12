Purpose of this project is to find which display is better for DIY  handheld devices.

I want to check different display modules and measure which current those modules requires.


## LCD1602 via the PCF8574 I2C IO extender

Module supply voltage - 3.3v.

|Test, no|Description|Current,mA|
|--|--|--|
|1|Blank screen|3.1|
|2|Blank screen + backlight|8.8|
|3|25% fill|3.1|
|4|25% fill + backlight|8.8|
|5|50% fill|3.1|
|6|50% fill + backlight|8.8|
|7|100% fill|3.1|
|8|100% fill + backlight|8.8|

## LCD2004 via the PCF8574 I2C IO extender

Module supply voltage - 3.3v.

|Test, no|Description|Current,uA|
|--|--|--|
|1|Blank screen|3142|
|2|Blank screen + backlight|13070|
|3|25% fill|3098|
|4|25% fill + backlight|13030|
|5|50% fill|3090|
|6|50% fill + backlight|13010|
|7|100% fill|3024|
|8|100% fill + backlight|12970|

After removal of power led from PCF8574 module

|Test, no|Description|Current,uA|
|--|--|--|
|1|Blank screen|1744|
|2|Blank screen + backlight|11630|
|3|25% fill|1698|
|4|25% fill + backlight|11600|
|5|50% fill|1690|
|6|50% fill + backlight|11600|
|7|100% fill|1621|
|8|100% fill + backlight|11550|

## SSD1306 OLED 0.96 128x64

Module supply voltage - 3.3v.

|Test, no|Description|Current,uA|
|--|--|--|
|1|Blank screen|2047|
|2|25% fill|6135|
|3|50% fill|11500|
|4|100% fill|19900|

## TM1636

Module supply voltage - 3.3v.

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

0x00-level brightness is hard to see in bright lighting.
