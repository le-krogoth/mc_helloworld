/*-----------------------------------------------------------------------------
 **
 ** - Hello World on Heltect WifiKit8, based on Proteus -
 **
 ** Copyright 2018-22 by Krogoth and the contributing authors
 **
 ** This program is free software; you can redistribute it and/or modify it
 ** under the terms of the GNU Affero General Public License as published by the
 ** Free Software Foundation, either version 3 of the License, or (at your option)
 ** any later version.
 **
 ** This program is distributed in the hope that it will be useful, but WITHOUT
 ** ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 ** FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Affero General Public License
 ** for more details.
 **
 ** You should have received a copy of the GNU Affero General Public License
 ** along with this program. If not, see <http://www.gnu.org/licenses/>.
 **
 ** -----------------------------------------------------------------------------*/

#include "helloworld.h"

U8G2_SSD1306_128X32_UNIVISION_F_SW_I2C u8g2(U8G2_R0, /* clock=*/ 5, /* data=*/ 4, /* reset=*/ 16);
// There are some Heltec 8 Boards, which need the config below.
// I haven't found one yet, but I heard stories of.
// U8G2_SSD1306_128X32_UNIVISION_F_SW_I2C u8g2(U8G2_R0, /* clock=*/ 14, /* data=*/ 2, /* reset=*/ 4);

void setup()
{
    // start serial port
    Serial.begin(115200);
    Serial.setDebugOutput(true);
    delay(200);

    // set framerate
    eachFrameMillis = 1000 / 60;

    Serial.println("+ Initialising u8g2");

    // initialise the display connected to the heltec 8 wifi kit and set a default font, just in case
    u8g2.begin();
    u8g2.clearDisplay();
    u8g2.setFont(u8g2_font_logisoso32_tf);
    u8g2.setFontMode(0);    // enable transparent mode, which is faster

    Serial.println("+ Initialisation done");
}

void loop()
{
    // enforce framerate
    if(!nextFrame())
    {
        return;
    }

    // Paint the next frame now
    paintFrame();

    Serial.println("- Loop");
}



bool nextFrame()
{
    long now = millis();

    // if it's not time for the next frame yet
    if (now < nextFrameStart) {
        // remaining = nextFrameStart - now;
        // if we have more than 1ms to spare, lets sleep
        // we should be woken up by timer0 every 1ms, so this should be ok
        //if (remaining > 1)
        //    idle();
        return false;
    }

    // define when next render happens
    nextFrameStart = now + eachFrameMillis;
    return true;
}

void paintFrame()
{
    // standard helix
    u8g2.firstPage();
    do {

        float p = 2 * sin(d);
        float q = 2 * sin(-d);

        for (byte k = 1; k < 16; k++) {
            // some calculations are used multiple times
            // so better caclutate them once and reuse
            // the results.
            float r = sin(d + (k * 0.4));
            float t = sin(d + 3 + (k * 0.4));

            // First lets draw the top 12 balls
            u8g2.drawDisc(k * 8 + p, 12 + (r * 10), 2);
            // and now the bottom 12 balls
            u8g2.drawDisc(k * 8 + q, 12 + (t * 10), 2);

            // now we draw a line from the top ball to the bottom ball
            u8g2.drawLine(k * 8 + p, 10 + (r * 10), k * 8 + q, (10 + t * 10));

            // and finally we need a line from ball to ball on the top part
            if(k < 15) {
                u8g2.drawLine((k * 8 + p), 12 + (r * 10), 6 + (k * 8 + p), (12 + sin(d + ((k + 1) * 0.4)) * 10));
            }

            // and the bottom part
            if(k < 15) {
                u8g2.drawLine((k * 8 + q), 12 + (t * 10), 6 + (k * 8 + q), (12 + sin(d + 3 + ((k + 1) * 0.4)) * 10));
            }
        }

    } while ( u8g2.nextPage() );

    // float d goes 1 step further on the sine evolution
    d = d + 0.10;
}