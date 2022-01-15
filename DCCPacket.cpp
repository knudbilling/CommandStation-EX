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
#include "DCC.h"
#include "DCCPacket.h"

DCCPacket::DCCPacket(void)
{
    length = 0;
    errorDetection = 0;
}

/*
 * Add one byte to the end of the dcc packet 
 *
 * Add the given byte to end end of the packet. If the packet is
 * full (there is no more room in the buffer) the byte is silently
 * ignored.
 * 
 * Input:
 *  b: byte to write to end of the packet
 * 
 * Return:
 *  -
 */
void DCCPacket::add_byte(uint8_t b)
{
    if (length < sizeof(bytes))
    {
        /*
         * Add byte to en the of the buffer
         */
        bytes[length++] = b;
        /*
         * Update error detection byte
         */
        errorDetection ^= b;
    }
}

/*
 * Add cab to the end of the dcc packet
 *
 * Add the given cab to end end of the packet. The cab is added as a
 * long address if it is larger than HIGHEST_SHORT_ADDR. Otherwise it
 * is added as a short address.
 * 
 * CAUTION:
 * If the buffer is full or nearly full, the cab might only be partially 
 * added or not added at all.
 * 
 * Input:
 *  cab: cab to write to end of the packet
 * 
 * Return:
 *  -
 */
void DCCPacket::add_cab(uint16_t cab)
{
    if (cab > HIGHEST_SHORT_ADDR)
    {
        add_byte(highByte(cab) | 0xC0);
    }
    add_byte(lowByte(cab));
}
