/***************************************************************************
 *   Copyright (C) 2012 by Guillermo Ballester Valor                       *
 *   gbv@ogimet.com                                                        *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/
/*!
 \file bufr2syn_x22.c
 \brief decodes the descriptors with X = 22 (oceanographic data)
*/
#include "bufr2synop.h"


int syn_parse_x22 ( struct synop_chunks *syn, struct bufr_subset_state *s, char *err )
{
  char aux[16];
  switch ( s->a->desc.y )
    {
    case 49: // 0 22 049 Sea surface temperature
      if (syn->s2.TwTwTw[0] == 0)
        {
          if (kelvin_to_snTTT ( aux, s->val ))
            {
              syn->s2.ss[0] = aux[0];
              strcpy ( syn->s2.TwTwTw, aux + 1 );
            }
        }
     break;
    default:
      break;
    }
  return 0;
}