/*
 * $FILE: lwip_log.h
 *
 * lwIP log header
 *
 * Author: Jordi Sánchez <jorsanp3@upvnet.upv.es>
 *
 * $LICENSE:
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 *
 */

#ifndef _LWIP_LOG_H_
#define _LWIP_LOG_H_

#define LWIPLOG_ENTRIES    32
#define LWIPLOG_MSG_SIZE   256
#define LWIPPRINT(...)     print_log(__VA_ARGS__)//, sizeof(x))

struct lwiplog_struct {
   char msg[LWIPLOG_MSG_SIZE];
   int time;
};

//extern void print_log(const char *nmsg, int size);
extern void print_log(const char *format, ...);

#endif //_LWIP_LOG_H_
