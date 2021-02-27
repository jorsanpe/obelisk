/*
 * $FILE: stddef.h
 *
 * Standard type definitions
 *
 * Author: Jordi Sánchez, <jorsanp3@upvnet.upv.es>
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

#ifndef _STDDEF_H_
#define _STDDEF_H_

#ifndef __ASSEMBLY__
#include <types.h>
#endif

#undef NULL
#define NULL ((void *) 0)

#ifndef TRUE
#define TRUE     1
#define FALSE    0
#endif

#define offsetof(st, m) ((size_t) ( (char *)&((st *)(0))->m - (char *)0 ))

#ifdef _KERNEL_
#define DEFINE(sym, val) \
        asm volatile("\n-> " #sym " %0 " #val : : "i" (val))

#define OFFSET(sym, str, mem) \
        DEFINE(sym, offsetof(str, mem));
#endif


#endif
