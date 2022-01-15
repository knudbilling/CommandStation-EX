/*
 *  © 2022 Knud Billing
 *  All rights reserved.
 *  
 *  This file is part of CommandStation-EX
 *
 *  This is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  It is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with CommandStation.  If not, see <https://www.gnu.org/licenses/>.
 */
#ifndef DCCPACKET_H
#define DCCPACKET_H

#include <Arduino.h>
#include "DCC.h"

/*
 * NMRA standard extended packets, payload size WITHOUT checksum.
 */
const byte MAX_PACKET_SIZE = 5;

class DCCPacket
{
public:
    DCCPacket(void);
    void add_byte(uint8_t b);
    void add_cab(uint16_t cab);
    uint16_t length;
    uint8_t bytes[MAX_PACKET_SIZE];
    uint8_t errorDetection;
};

#endif /* DCCPACKET_H */