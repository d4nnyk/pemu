/* Test exception in current environment.
   Copyright (C) 2001, 2010 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, write to the Free
   Software Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA
   02111-1307 USA.  */

#include <fenv.h>

int
fetestexcept (int excepts)
{
  int temp;
  unsigned int mxscr;

  /* Get current exceptions.  */
  __asm__ ("fnstsw %0\n"
	   "stmxcsr %1" : "=m" (*&temp), "=m" (*&mxscr));

  return (temp | mxscr) & excepts & FE_ALL_EXCEPT;
}
libm_hidden_def (fetestexcept)