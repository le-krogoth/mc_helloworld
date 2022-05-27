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

#ifndef MC_HELLOWORLD_HELLOWORLD_H
#define MC_HELLOWORLD_HELLOWORLD_H

#include <Arduino.h>
#include <U8g2lib.h>

uint8_t eachFrameMillis;
long nextFrameStart;

// sinus
int i = 0;
float d = 0.0;
int c = 129;

bool nextFrame();
void paintFrame();

#endif //MC_HELLOWORLD_HELLOWORLD_H
