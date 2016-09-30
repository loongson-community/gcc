/* Intrinsics for ST Microelectronics Loongson-2E/2F SIMD operations.

   Copyright (C) 2008-2015 Free Software Foundation, Inc.
   Contributed by CodeSourcery.

   This file is part of GCC.

   GCC is free software; you can redistribute it and/or modify it
   under the terms of the GNU General Public License as published
   by the Free Software Foundation; either version 3, or (at your
   option) any later version.

   GCC is distributed in the hope that it will be useful, but WITHOUT
   ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
   or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public
   License for more details.

   Under Section 7 of GPL version 3, you are granted additional
   permissions described in the GCC Runtime Library Exception, version
   3.1, as published by the Free Software Foundation.

   You should have received a copy of the GNU General Public License and
   a copy of the GCC Runtime Library Exception along with this program;
   see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
   <http://www.gnu.org/licenses/>.  */

#ifndef _GCC_LOONGSON_H
#define _GCC_LOONGSON_H

#if !defined(__mips_loongson_vector_rev)
# error "You must select -march=loongson2e/2f/3a to use loongson.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

/* Vectors of unsigned bytes, halfwords and words.  */
typedef uint8_t uint8x8_t __attribute__((vector_size (8)));
typedef uint16_t uint16x4_t __attribute__((vector_size (8)));
typedef uint32_t uint32x2_t __attribute__((vector_size (8)));

/* Vectors of signed bytes, halfwords and words.  */
typedef int8_t int8x8_t __attribute__((vector_size (8)));
typedef int16_t int16x4_t __attribute__((vector_size (8)));
typedef int32_t int32x2_t __attribute__((vector_size (8)));

/* SIMD intrinsics.
   Unless otherwise noted, calls to the functions below will expand into
   precisely one machine instruction, modulo any moves required to
   satisfy register allocation constraints.  */

/* Pack with signed saturation.  */
__extension__ static __inline int16x4_t __attribute__ ((__always_inline__))
packsswh (int32x2_t s, int32x2_t t)
{
  return __builtin_loongson_packsswh (s, t);
}

__extension__ static __inline int8x8_t __attribute__ ((__always_inline__))
packsshb (int16x4_t s, int16x4_t t)
{
  return __builtin_loongson_packsshb (s, t);
}

/* Pack with unsigned saturation.  */
__extension__ static __inline uint8x8_t __attribute__ ((__always_inline__))
packushb (uint16x4_t s, uint16x4_t t)
{
  return __builtin_loongson_packushb (s, t);
}

/* Vector addition, treating overflow by wraparound.  */
__extension__ static __inline uint32x2_t __attribute__ ((__always_inline__))
paddw_u (uint32x2_t s, uint32x2_t t)
{
  return __builtin_loongson_paddw_u (s, t);
}

__extension__ static __inline uint16x4_t __attribute__ ((__always_inline__))
paddh_u (uint16x4_t s, uint16x4_t t)
{
  return __builtin_loongson_paddh_u (s, t);
}

__extension__ static __inline uint8x8_t __attribute__ ((__always_inline__))
paddb_u (uint8x8_t s, uint8x8_t t)
{
  return __builtin_loongson_paddb_u (s, t);
}

__extension__ static __inline int32x2_t __attribute__ ((__always_inline__))
paddw_s (int32x2_t s, int32x2_t t)
{
  return __builtin_loongson_paddw_s (s, t);
}

__extension__ static __inline int16x4_t __attribute__ ((__always_inline__))
paddh_s (int16x4_t s, int16x4_t t)
{
  return __builtin_loongson_paddh_s (s, t);
}

__extension__ static __inline int8x8_t __attribute__ ((__always_inline__))
paddb_s (int8x8_t s, int8x8_t t)
{
  return __builtin_loongson_paddb_s (s, t);
}

/* Addition of doubleword integers, treating overflow by wraparound.  */
__extension__ static __inline uint64_t __attribute__ ((__always_inline__))
paddd_u (uint64_t s, uint64_t t)
{
  return __builtin_loongson_paddd_u (s, t);
}

__extension__ static __inline int64_t __attribute__ ((__always_inline__))
paddd_s (int64_t s, int64_t t)
{
  return __builtin_loongson_paddd_s (s, t);
}

/* Vector addition, treating overflow by signed saturation.  */
__extension__ static __inline int16x4_t __attribute__ ((__always_inline__))
paddsh (int16x4_t s, int16x4_t t)
{
  return __builtin_loongson_paddsh (s, t);
}

__extension__ static __inline int8x8_t __attribute__ ((__always_inline__))
paddsb (int8x8_t s, int8x8_t t)
{
  return __builtin_loongson_paddsb (s, t);
}

/* Vector addition, treating overflow by unsigned saturation.  */
__extension__ static __inline uint16x4_t __attribute__ ((__always_inline__))
paddush (uint16x4_t s, uint16x4_t t)
{
  return __builtin_loongson_paddush (s, t);
}

__extension__ static __inline uint8x8_t __attribute__ ((__always_inline__))
paddusb (uint8x8_t s, uint8x8_t t)
{
  return __builtin_loongson_paddusb (s, t);
}

/* Logical AND NOT.  */
__extension__ static __inline uint64_t __attribute__ ((__always_inline__))
pandn_ud (uint64_t s, uint64_t t)
{
  return __builtin_loongson_pandn_ud (s, t);
}

__extension__ static __inline uint32x2_t __attribute__ ((__always_inline__))
pandn_uw (uint32x2_t s, uint32x2_t t)
{
  return __builtin_loongson_pandn_uw (s, t);
}

__extension__ static __inline uint16x4_t __attribute__ ((__always_inline__))
pandn_uh (uint16x4_t s, uint16x4_t t)
{
  return __builtin_loongson_pandn_uh (s, t);
}

__extension__ static __inline uint8x8_t __attribute__ ((__always_inline__))
pandn_ub (uint8x8_t s, uint8x8_t t)
{
  return __builtin_loongson_pandn_ub (s, t);
}

__extension__ static __inline int64_t __attribute__ ((__always_inline__))
pandn_sd (int64_t s, int64_t t)
{
  return __builtin_loongson_pandn_sd (s, t);
}

__extension__ static __inline int32x2_t __attribute__ ((__always_inline__))
pandn_sw (int32x2_t s, int32x2_t t)
{
  return __builtin_loongson_pandn_sw (s, t);
}

__extension__ static __inline int16x4_t __attribute__ ((__always_inline__))
pandn_sh (int16x4_t s, int16x4_t t)
{
  return __builtin_loongson_pandn_sh (s, t);
}

__extension__ static __inline int8x8_t __attribute__ ((__always_inline__))
pandn_sb (int8x8_t s, int8x8_t t)
{
  return __builtin_loongson_pandn_sb (s, t);
}

/* Average.  */
__extension__ static __inline uint16x4_t __attribute__ ((__always_inline__))
pavgh (uint16x4_t s, uint16x4_t t)
{
  return __builtin_loongson_pavgh (s, t);
}

__extension__ static __inline uint8x8_t __attribute__ ((__always_inline__))
pavgb (uint8x8_t s, uint8x8_t t)
{
  return __builtin_loongson_pavgb (s, t);
}

/* Equality test.  */
__extension__ static __inline uint32x2_t __attribute__ ((__always_inline__))
pcmpeqw_u (uint32x2_t s, uint32x2_t t)
{
  return __builtin_loongson_pcmpeqw_u (s, t);
}

__extension__ static __inline uint16x4_t __attribute__ ((__always_inline__))
pcmpeqh_u (uint16x4_t s, uint16x4_t t)
{
  return __builtin_loongson_pcmpeqh_u (s, t);
}

__extension__ static __inline uint8x8_t __attribute__ ((__always_inline__))
pcmpeqb_u (uint8x8_t s, uint8x8_t t)
{
  return __builtin_loongson_pcmpeqb_u (s, t);
}

__extension__ static __inline int32x2_t __attribute__ ((__always_inline__))
pcmpeqw_s (int32x2_t s, int32x2_t t)
{
  return __builtin_loongson_pcmpeqw_s (s, t);
}

__extension__ static __inline int16x4_t __attribute__ ((__always_inline__))
pcmpeqh_s (int16x4_t s, int16x4_t t)
{
  return __builtin_loongson_pcmpeqh_s (s, t);
}

__extension__ static __inline int8x8_t __attribute__ ((__always_inline__))
pcmpeqb_s (int8x8_t s, int8x8_t t)
{
  return __builtin_loongson_pcmpeqb_s (s, t);
}

/* Greater-than test.  */
__extension__ static __inline uint32x2_t __attribute__ ((__always_inline__))
pcmpgtw_u (uint32x2_t s, uint32x2_t t)
{
  return __builtin_loongson_pcmpgtw_u (s, t);
}

__extension__ static __inline uint16x4_t __attribute__ ((__always_inline__))
pcmpgth_u (uint16x4_t s, uint16x4_t t)
{
  return __builtin_loongson_pcmpgth_u (s, t);
}

__extension__ static __inline uint8x8_t __attribute__ ((__always_inline__))
pcmpgtb_u (uint8x8_t s, uint8x8_t t)
{
  return __builtin_loongson_pcmpgtb_u (s, t);
}

__extension__ static __inline int32x2_t __attribute__ ((__always_inline__))
pcmpgtw_s (int32x2_t s, int32x2_t t)
{
  return __builtin_loongson_pcmpgtw_s (s, t);
}

__extension__ static __inline int16x4_t __attribute__ ((__always_inline__))
pcmpgth_s (int16x4_t s, int16x4_t t)
{
  return __builtin_loongson_pcmpgth_s (s, t);
}

__extension__ static __inline int8x8_t __attribute__ ((__always_inline__))
pcmpgtb_s (int8x8_t s, int8x8_t t)
{
  return __builtin_loongson_pcmpgtb_s (s, t);
}

/* Extract halfword.  */
__extension__ static __inline uint16x4_t __attribute__ ((__always_inline__))
pextrh_u (uint16x4_t s, int field /* 0--3 */)
{
  return __builtin_loongson_pextrh_u (s, field);
}

__extension__ static __inline int16x4_t __attribute__ ((__always_inline__))
pextrh_s (int16x4_t s, int field /* 0--3 */)
{
  return __builtin_loongson_pextrh_s (s, field);
}

/* Insert halfword.  */
__extension__ static __inline uint16x4_t __attribute__ ((__always_inline__))
pinsrh_0_u (uint16x4_t s, uint16x4_t t)
{
  return __builtin_loongson_pinsrh_0_u (s, t);
}

__extension__ static __inline uint16x4_t __attribute__ ((__always_inline__))
pinsrh_1_u (uint16x4_t s, uint16x4_t t)
{
  return __builtin_loongson_pinsrh_1_u (s, t);
}

__extension__ static __inline uint16x4_t __attribute__ ((__always_inline__))
pinsrh_2_u (uint16x4_t s, uint16x4_t t)
{
  return __builtin_loongson_pinsrh_2_u (s, t);
}

__extension__ static __inline uint16x4_t __attribute__ ((__always_inline__))
pinsrh_3_u (uint16x4_t s, uint16x4_t t)
{
  return __builtin_loongson_pinsrh_3_u (s, t);
}

__extension__ static __inline int16x4_t __attribute__ ((__always_inline__))
pinsrh_0_s (int16x4_t s, int16x4_t t)
{
  return __builtin_loongson_pinsrh_0_s (s, t);
}

__extension__ static __inline int16x4_t __attribute__ ((__always_inline__))
pinsrh_1_s (int16x4_t s, int16x4_t t)
{
  return __builtin_loongson_pinsrh_1_s (s, t);
}

__extension__ static __inline int16x4_t __attribute__ ((__always_inline__))
pinsrh_2_s (int16x4_t s, int16x4_t t)
{
  return __builtin_loongson_pinsrh_2_s (s, t);
}

__extension__ static __inline int16x4_t __attribute__ ((__always_inline__))
pinsrh_3_s (int16x4_t s, int16x4_t t)
{
  return __builtin_loongson_pinsrh_3_s (s, t);
}

/* Multiply and add.  */
__extension__ static __inline int32x2_t __attribute__ ((__always_inline__))
pmaddhw (int16x4_t s, int16x4_t t)
{
  return __builtin_loongson_pmaddhw (s, t);
}

/* Maximum of signed halfwords.  */
__extension__ static __inline int16x4_t __attribute__ ((__always_inline__))
pmaxsh (int16x4_t s, int16x4_t t)
{
  return __builtin_loongson_pmaxsh (s, t);
}

/* Maximum of unsigned bytes.  */
__extension__ static __inline uint8x8_t __attribute__ ((__always_inline__))
pmaxub (uint8x8_t s, uint8x8_t t)
{
  return __builtin_loongson_pmaxub (s, t);
}

/* Minimum of signed halfwords.  */
__extension__ static __inline int16x4_t __attribute__ ((__always_inline__))
pminsh (int16x4_t s, int16x4_t t)
{
  return __builtin_loongson_pminsh (s, t);
}

/* Minimum of unsigned bytes.  */
__extension__ static __inline uint8x8_t __attribute__ ((__always_inline__))
pminub (uint8x8_t s, uint8x8_t t)
{
  return __builtin_loongson_pminub (s, t);
}

/* Move byte mask.  */
__extension__ static __inline uint8x8_t __attribute__ ((__always_inline__))
pmovmskb_u (uint8x8_t s)
{
  return __builtin_loongson_pmovmskb_u (s);
}

__extension__ static __inline int8x8_t __attribute__ ((__always_inline__))
pmovmskb_s (int8x8_t s)
{
  return __builtin_loongson_pmovmskb_s (s);
}

/* Multiply unsigned integers and store high result.  */
__extension__ static __inline uint16x4_t __attribute__ ((__always_inline__))
pmulhuh (uint16x4_t s, uint16x4_t t)
{
  return __builtin_loongson_pmulhuh (s, t);
}

/* Multiply signed integers and store high result.  */
__extension__ static __inline int16x4_t __attribute__ ((__always_inline__))
pmulhh (int16x4_t s, int16x4_t t)
{
  return __builtin_loongson_pmulhh (s, t);
}

/* Multiply signed integers and store low result.  */
__extension__ static __inline int16x4_t __attribute__ ((__always_inline__))
pmullh (int16x4_t s, int16x4_t t)
{
  return __builtin_loongson_pmullh (s, t);
}

/* Multiply unsigned word integers.  */
__extension__ static __inline int64_t __attribute__ ((__always_inline__))
pmuluw (uint32x2_t s, uint32x2_t t)
{
  return __builtin_loongson_pmuluw (s, t);
}

/* Absolute difference.  */
__extension__ static __inline uint8x8_t __attribute__ ((__always_inline__))
pasubub (uint8x8_t s, uint8x8_t t)
{
  return __builtin_loongson_pasubub (s, t);
}

/* Sum of unsigned byte integers.  */
__extension__ static __inline uint16x4_t __attribute__ ((__always_inline__))
biadd (uint8x8_t s)
{
  return __builtin_loongson_biadd (s);
}

/* Sum of absolute differences.
   Note that this intrinsic expands into two machine instructions:
   PASUBUB followed by BIADD.  */
__extension__ static __inline uint16x4_t __attribute__ ((__always_inline__))
psadbh (uint8x8_t s, uint8x8_t t)
{
  return __builtin_loongson_psadbh (s, t);
}

/* Shuffle halfwords.  */
__extension__ static __inline uint16x4_t __attribute__ ((__always_inline__))
pshufh_u (uint16x4_t dest, uint16x4_t s, uint8_t order)
{
  return __builtin_loongson_pshufh_u (s, order);
}

__extension__ static __inline int16x4_t __attribute__ ((__always_inline__))
pshufh_s (int16x4_t dest, int16x4_t s, uint8_t order)
{
  return __builtin_loongson_pshufh_s (s, order);
}

/* Shift left logical.  */
__extension__ static __inline uint16x4_t __attribute__ ((__always_inline__))
psllh_u (uint16x4_t s, uint8_t amount)
{
  return __builtin_loongson_psllh_u (s, amount);
}

__extension__ static __inline int16x4_t __attribute__ ((__always_inline__))
psllh_s (int16x4_t s, uint8_t amount)
{
  return __builtin_loongson_psllh_s (s, amount);
}

__extension__ static __inline uint32x2_t __attribute__ ((__always_inline__))
psllw_u (uint32x2_t s, uint8_t amount)
{
  return __builtin_loongson_psllw_u (s, amount);
}

__extension__ static __inline int32x2_t __attribute__ ((__always_inline__))
psllw_s (int32x2_t s, uint8_t amount)
{
  return __builtin_loongson_psllw_s (s, amount);
}

/* Shift right logical.  */
__extension__ static __inline uint16x4_t __attribute__ ((__always_inline__))
psrlh_u (uint16x4_t s, uint8_t amount)
{
  return __builtin_loongson_psrlh_u (s, amount);
}

__extension__ static __inline int16x4_t __attribute__ ((__always_inline__))
psrlh_s (int16x4_t s, uint8_t amount)
{
  return __builtin_loongson_psrlh_s (s, amount);
}

__extension__ static __inline uint32x2_t __attribute__ ((__always_inline__))
psrlw_u (uint32x2_t s, uint8_t amount)
{
  return __builtin_loongson_psrlw_u (s, amount);
}

__extension__ static __inline int32x2_t __attribute__ ((__always_inline__))
psrlw_s (int32x2_t s, uint8_t amount)
{
  return __builtin_loongson_psrlw_s (s, amount);
}

/* Shift right arithmetic.  */
__extension__ static __inline uint16x4_t __attribute__ ((__always_inline__))
psrah_u (uint16x4_t s, uint8_t amount)
{
  return __builtin_loongson_psrah_u (s, amount);
}

__extension__ static __inline int16x4_t __attribute__ ((__always_inline__))
psrah_s (int16x4_t s, uint8_t amount)
{
  return __builtin_loongson_psrah_s (s, amount);
}

__extension__ static __inline uint32x2_t __attribute__ ((__always_inline__))
psraw_u (uint32x2_t s, uint8_t amount)
{
  return __builtin_loongson_psraw_u (s, amount);
}

__extension__ static __inline int32x2_t __attribute__ ((__always_inline__))
psraw_s (int32x2_t s, uint8_t amount)
{
  return __builtin_loongson_psraw_s (s, amount);
}

/* Vector subtraction, treating overflow by wraparound.  */
__extension__ static __inline uint32x2_t __attribute__ ((__always_inline__))
psubw_u (uint32x2_t s, uint32x2_t t)
{
  return __builtin_loongson_psubw_u (s, t);
}

__extension__ static __inline uint16x4_t __attribute__ ((__always_inline__))
psubh_u (uint16x4_t s, uint16x4_t t)
{
  return __builtin_loongson_psubh_u (s, t);
}

__extension__ static __inline uint8x8_t __attribute__ ((__always_inline__))
psubb_u (uint8x8_t s, uint8x8_t t)
{
  return __builtin_loongson_psubb_u (s, t);
}

__extension__ static __inline int32x2_t __attribute__ ((__always_inline__))
psubw_s (int32x2_t s, int32x2_t t)
{
  return __builtin_loongson_psubw_s (s, t);
}

__extension__ static __inline int16x4_t __attribute__ ((__always_inline__))
psubh_s (int16x4_t s, int16x4_t t)
{
  return __builtin_loongson_psubh_s (s, t);
}

__extension__ static __inline int8x8_t __attribute__ ((__always_inline__))
psubb_s (int8x8_t s, int8x8_t t)
{
  return __builtin_loongson_psubb_s (s, t);
}

/* Subtraction of doubleword integers, treating overflow by wraparound.  */
__extension__ static __inline uint64_t __attribute__ ((__always_inline__))
psubd_u (uint64_t s, uint64_t t)
{
  return __builtin_loongson_psubd_u (s, t);
}

__extension__ static __inline int64_t __attribute__ ((__always_inline__))
psubd_s (int64_t s, int64_t t)
{
  return __builtin_loongson_psubd_s (s, t);
}

/* Vector subtraction, treating overflow by signed saturation.  */
__extension__ static __inline int16x4_t __attribute__ ((__always_inline__))
psubsh (int16x4_t s, int16x4_t t)
{
  return __builtin_loongson_psubsh (s, t);
}

__extension__ static __inline int8x8_t __attribute__ ((__always_inline__))
psubsb (int8x8_t s, int8x8_t t)
{
  return __builtin_loongson_psubsb (s, t);
}

/* Vector subtraction, treating overflow by unsigned saturation.  */
__extension__ static __inline uint16x4_t __attribute__ ((__always_inline__))
psubush (uint16x4_t s, uint16x4_t t)
{
  return __builtin_loongson_psubush (s, t);
}

__extension__ static __inline uint8x8_t __attribute__ ((__always_inline__))
psubusb (uint8x8_t s, uint8x8_t t)
{
  return __builtin_loongson_psubusb (s, t);
}

/* Unpack high data.  */
__extension__ static __inline uint32x2_t __attribute__ ((__always_inline__))
punpckhwd_u (uint32x2_t s, uint32x2_t t)
{
  return __builtin_loongson_punpckhwd_u (s, t);
}

__extension__ static __inline uint16x4_t __attribute__ ((__always_inline__))
punpckhhw_u (uint16x4_t s, uint16x4_t t)
{
  return __builtin_loongson_punpckhhw_u (s, t);
}

__extension__ static __inline uint8x8_t __attribute__ ((__always_inline__))
punpckhbh_u (uint8x8_t s, uint8x8_t t)
{
  return __builtin_loongson_punpckhbh_u (s, t);
}

__extension__ static __inline int32x2_t __attribute__ ((__always_inline__))
punpckhwd_s (int32x2_t s, int32x2_t t)
{
  return __builtin_loongson_punpckhwd_s (s, t);
}

__extension__ static __inline int16x4_t __attribute__ ((__always_inline__))
punpckhhw_s (int16x4_t s, int16x4_t t)
{
  return __builtin_loongson_punpckhhw_s (s, t);
}

__extension__ static __inline int8x8_t __attribute__ ((__always_inline__))
punpckhbh_s (int8x8_t s, int8x8_t t)
{
  return __builtin_loongson_punpckhbh_s (s, t);
}

/* Unpack low data.  */
__extension__ static __inline uint32x2_t __attribute__ ((__always_inline__))
punpcklwd_u (uint32x2_t s, uint32x2_t t)
{
  return __builtin_loongson_punpcklwd_u (s, t);
}

__extension__ static __inline uint16x4_t __attribute__ ((__always_inline__))
punpcklhw_u (uint16x4_t s, uint16x4_t t)
{
  return __builtin_loongson_punpcklhw_u (s, t);
}

__extension__ static __inline uint8x8_t __attribute__ ((__always_inline__))
punpcklbh_u (uint8x8_t s, uint8x8_t t)
{
  return __builtin_loongson_punpcklbh_u (s, t);
}

__extension__ static __inline int32x2_t __attribute__ ((__always_inline__))
punpcklwd_s (int32x2_t s, int32x2_t t)
{
  return __builtin_loongson_punpcklwd_s (s, t);
}

__extension__ static __inline int16x4_t __attribute__ ((__always_inline__))
punpcklhw_s (int16x4_t s, int16x4_t t)
{
  return __builtin_loongson_punpcklhw_s (s, t);
}

__extension__ static __inline int8x8_t __attribute__ ((__always_inline__))
punpcklbh_s (int8x8_t s, int8x8_t t)
{
  return __builtin_loongson_punpcklbh_s (s, t);
}

/* SSE2-style Vectors */
typedef double              __v1df __attribute__ ((__vector_size__ (8)));
typedef long long           __v1di __attribute__ ((__vector_size__ (8)));
typedef unsigned long long  __v1du __attribute__ ((__vector_size__ (8)));
typedef int                 __v2si __attribute__ ((__vector_size__ (8)));
typedef unsigned int        __v2su __attribute__ ((__vector_size__ (8)));
typedef short               __v4hi __attribute__ ((__vector_size__ (8)));
typedef unsigned short      __v4hu __attribute__ ((__vector_size__ (8)));
typedef char                __v8qi __attribute__ ((__vector_size__ (8)));
typedef unsigned char       __v8qu __attribute__ ((__vector_size__ (8)));

typedef struct  __v2df  { __v1df hi; __v1df lo; } __v2df;
typedef struct  __v2di  { __v1di hi; __v1di lo; } __v2di;
typedef struct  __v2du  { __v1du hi; __v1du lo; } __v2du;
typedef struct  __v4si  { __v2si hi; __v2si lo; } __v4si;
typedef struct  __v4su  { __v2su hi; __v2su lo; } __v4su;
typedef struct  __v8hi  { __v4hi hi; __v4hi lo; } __v8hi;
typedef struct  __v8hu  { __v4hu hi; __v4hu lo; } __v8hu;
typedef struct  __v16qi { __v8qi hi; __v8qi lo; } __v16qi;
typedef struct  __v16qu { __v8qu hi; __v8qu lo; } __v16qu;

typedef int         __m64  __attribute__ ((__vector_size__ (8), __may_alias__));
typedef long long   __m64i __attribute__ ((__vector_size__ (8), __may_alias__));
typedef double      __m64d __attribute__ ((__vector_size__ (8), __may_alias__));

typedef struct  __m128  { __m64  hi; __m64  lo; } __m128;
typedef struct  __m128i { __m64i hi; __m64i lo; } __m128i;
typedef struct  __m128d { __m64d hi; __m64d lo; } __m128d;

/* Create a selector for use with the SHUFPD instruction.  */
#define _MM_SHUFFLE2(fp1,fp0) \
 (((fp1) << 1) | (fp0))

/* Create a vector with element 0 as F and the rest zero.  */
extern __inline __m128d __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_set_sd (double __F)
{
  /* return __extension__ (__m128d){ __F, 0.0 }; */
  __m128d val;
  val.lo = (__m64d){ __F };
  val.hi = (__m64d){ 0.0 };
  return __extension__ val;
}

/* Create a vector with both elements equal to F.  */
extern __inline __m128d __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_set1_pd (double __F)
{
  /* return __extension__ (__m128d){ __F, __F }; */
  __m128d val;
  val.lo = (__m64d){ __F };
  val.hi = (__m64d){ __F };
  return __extension__ val;
}

extern __inline __m128d __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_set_pd1 (double __F)
{
  return _mm_set1_pd (__F);
}

/* Create a vector with the lower value X and upper value W.  */
extern __inline __m128d __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_set_pd (double __W, double __X)
{
  /* return __extension__ (__m128d){ __X, __W }; */
  __m128d val;
  val.lo = (__m64d){ __X };
  val.hi = (__m64d){ __W };
  return __extension__ val;
}

/* Create a vector with the lower value W and upper value X.  */
extern __inline __m128d __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_setr_pd (double __W, double __X)
{
  /* return __extension__ (__m128d){ __W, __X }; */
  __m128d val;
  val.lo = (__m64d){ __W };
  val.hi = (__m64d){ __X };
  return __extension__ val;
}

/* Create an undefined vector.  */
extern __inline __m128d __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_undefined_pd (void)
{
  __m128d __Y = __Y;
  return __Y;
}

/* Create a vector of zeros.  */
extern __inline __m128d __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_setzero_pd (void)
{
  /* return __extension__ (__m128d){ 0.0, 0.0 }; */
  __m128d val;
  val.lo = (__m64d){ 0.0 };
  val.hi = (__m64d){ 0.0 };
  return __extension__ val;
}

#if 0 /* FIXME */
/* Sets the low DPFP value of A from the low value of B.  */
extern __inline __m128d __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_move_sd (__m128d __A, __m128d __B)
{
  return (__m128d) __builtin_ia32_movsd ((__v2df)__A, (__v2df)__B);
}

/* Load two DPFP values from P.  The address must be 16-byte aligned.  */
extern __inline __m128d __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_load_pd (double const *__P)
{
  return *(__m128d *)__P;
}

/* Load two DPFP values from P.  The address need not be 16-byte aligned.  */
extern __inline __m128d __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_loadu_pd (double const *__P)
{
  return __builtin_ia32_loadupd (__P);
}
#endif

/* Create a vector with all two elements equal to *P.  */
extern __inline __m128d __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_load1_pd (double const *__P)
{
  return _mm_set1_pd (*__P);
}

/* Create a vector with element 0 as *P and the rest zero.  */
extern __inline __m128d __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_load_sd (double const *__P)
{
  return _mm_set_sd (*__P);
}

extern __inline __m128d __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_load_pd1 (double const *__P)
{
  return _mm_load1_pd (__P);
}

#if 0 /* FIXME */
/* Load two DPFP values in reverse order.  The address must be aligned.  */
extern __inline __m128d __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_loadr_pd (double const *__P)
{
  __m128d __tmp = _mm_load_pd (__P);
  return __builtin_ia32_shufpd (__tmp, __tmp, _MM_SHUFFLE2 (0,1));
}

/* Store two DPFP values.  The address must be 16-byte aligned.  */
extern __inline void __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_store_pd (double *__P, __m128d __A)
{
  *(__m128d *)__P = __A;
}

/* Store two DPFP values.  The address need not be 16-byte aligned.  */
extern __inline void __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_storeu_pd (double *__P, __m128d __A)
{
  __builtin_ia32_storeupd (__P, __A);
}
#endif

/* Stores the lower DPFP value.  */
extern __inline void __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_store_sd (double *__P, __m128d __A)
{
  /* *__P = ((__v2df)__A)[0]; */
  __asm__ volatile (
    "sdc1       %[lo],      %[__P]                                      \n\t"
    ::[lo]"f"((__m64i)__A.lo),      [__P]"m"(*__P)
    : "memory"
  );
}

extern __inline double __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_cvtsd_f64 (__m128d __A)
{
  /* return ((__v2df)__A)[0]; */
  double val;
  __asm__ volatile (
    "ldc1       %[val],      %[lo]                                      \n\t"
    : [val]"=&f"(val)
    : [lo]"m"(__A.lo)
  );
  return val;
}

extern __inline void __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_storel_pd (double *__P, __m128d __A)
{
  _mm_store_sd (__P, __A);
}

/* Stores the upper DPFP value.  */
extern __inline void __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_storeh_pd (double *__P, __m128d __A)
{
  /* *__P = ((__v2df)__A)[1]; */
  __asm__ volatile (
    "sdc1       %[hi],      %[__P]                                      \n\t"
    ::[hi]"f"((__m64i)__A.hi),      [__P]"m"(*__P)
    : "memory"
  );
}

#if 0 /* FIXME */
/* Store the lower DPFP value across two words.
   The address must be 16-byte aligned.  */
extern __inline void __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_store1_pd (double *__P, __m128d __A)
{
  _mm_store_pd (__P, __builtin_ia32_shufpd (__A, __A, _MM_SHUFFLE2 (0,0)));
}

extern __inline void __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_store_pd1 (double *__P, __m128d __A)
{
  _mm_store1_pd (__P, __A);
}

/* Store two DPFP values in reverse order.  The address must be aligned.  */
extern __inline void __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_storer_pd (double *__P, __m128d __A)
{
  _mm_store_pd (__P, __builtin_ia32_shufpd (__A, __A, _MM_SHUFFLE2 (0,1)));
}
#endif

extern __inline int __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_cvtsi128_si32 (__m128i __A)
{
  /* return __builtin_ia32_vec_ext_v4si ((__v4si)__A, 0); */
  int val;
  __asm__ volatile (
    "mfc1       %[val],    %[lo]                                        \n\t"
    : [val]"=&r"(val)
    : [lo]"f"(__A.lo)
  );
  return val;
}

extern __inline long long __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_cvtsi128_si64 (__m128i __A)
{
  /* return ((__v2di)__A)[0]; */
  long long val;
  __asm__ volatile (
    "dmfc1      %[val],    %[lo]                                        \n\t"
    : [val]"=&r"(val)
    : [lo]"f"(__A.lo)
  );
  return val;
}

extern __inline long long __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_cvtsi128_si64x (__m128i __A)
{
  /* return ((__v2di)__A)[0]; */
  long long val;
  __asm__ volatile (
    "dmfc1      %[val],    %[lo]                                        \n\t"
    : [val]"=&r"(val)
    : [lo]"f"(__A.lo)
  );
  return val;
}

extern __inline __m128d __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_add_pd (__m128d __A, __m128d __B)
{
  /* return (__m128d) ((__v2df)__A + (__v2df)__B); */
  __m128d val;
  val.lo = (__m64d) ((__v1df)__A.lo + (__v1df)__B.lo);
  val.hi = (__m64d) ((__v1df)__A.hi + (__v1df)__B.hi);
  return val;
}

#if 0 /* FIXME */
extern __inline __m128d __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_add_sd (__m128d __A, __m128d __B)
{
  return (__m128d)__builtin_ia32_addsd ((__v2df)__A, (__v2df)__B);
}
#endif

extern __inline __m128d __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_sub_pd (__m128d __A, __m128d __B)
{
  /* return (__m128d) ((__v2df)__A - (__v2df)__B); */
  __m128d val;
  val.lo = (__m64d) ((__v1df)__A.lo - (__v1df)__B.lo);
  val.hi = (__m64d) ((__v1df)__A.hi - (__v1df)__B.hi);
  return val;
}

#if 0 /* FIXME */
extern __inline __m128d __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_sub_sd (__m128d __A, __m128d __B)
{
  return (__m128d)__builtin_ia32_subsd ((__v2df)__A, (__v2df)__B);
}
#endif

extern __inline __m128d __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_mul_pd (__m128d __A, __m128d __B)
{
  /* return (__m128d) ((__v2df)__A * (__v2df)__B); */
  __m128d val;
  val.lo = (__m64d) ((__v1df)__A.lo * (__v1df)__B.lo);
  val.hi = (__m64d) ((__v1df)__A.hi * (__v1df)__B.hi);
  return val;
}

#if 0 /* FIXME */
extern __inline __m128d __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_mul_sd (__m128d __A, __m128d __B)
{
  return (__m128d)__builtin_ia32_mulsd ((__v2df)__A, (__v2df)__B);
}
#endif

extern __inline __m128d __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_div_pd (__m128d __A, __m128d __B)
{
  /* return (__m128d) ((__v2df)__A / (__v2df)__B); */
  __m128d val;
  val.lo = (__m64d) ((__v1df)__A.lo / (__v1df)__B.lo);
  val.hi = (__m64d) ((__v1df)__A.hi / (__v1df)__B.hi);
  return val;
}

#if 0 /* FIXME */
extern __inline __m128d __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_div_sd (__m128d __A, __m128d __B)
{
  return (__m128d)__builtin_ia32_divsd ((__v2df)__A, (__v2df)__B);
}

extern __inline __m128d __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_sqrt_pd (__m128d __A)
{
  return (__m128d)__builtin_ia32_sqrtpd ((__v2df)__A);
}

/* Return pair {sqrt (B[0]), A[1]}.  */
extern __inline __m128d __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_sqrt_sd (__m128d __A, __m128d __B)
{
  __v2df __tmp = __builtin_ia32_movsd ((__v2df)__A, (__v2df)__B);
  return (__m128d)__builtin_ia32_sqrtsd ((__v2df)__tmp);
}

extern __inline __m128d __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_min_pd (__m128d __A, __m128d __B)
{
  return (__m128d)__builtin_ia32_minpd ((__v2df)__A, (__v2df)__B);
}

extern __inline __m128d __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_min_sd (__m128d __A, __m128d __B)
{
  return (__m128d)__builtin_ia32_minsd ((__v2df)__A, (__v2df)__B);
}

extern __inline __m128d __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_max_pd (__m128d __A, __m128d __B)
{
  return (__m128d)__builtin_ia32_maxpd ((__v2df)__A, (__v2df)__B);
}

extern __inline __m128d __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_max_sd (__m128d __A, __m128d __B)
{
  return (__m128d)__builtin_ia32_maxsd ((__v2df)__A, (__v2df)__B);
}

extern __inline __m128d __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_and_pd (__m128d __A, __m128d __B)
{
  return (__m128d)__builtin_ia32_andpd ((__v2df)__A, (__v2df)__B);
}

extern __inline __m128d __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_andnot_pd (__m128d __A, __m128d __B)
{
  return (__m128d)__builtin_ia32_andnpd ((__v2df)__A, (__v2df)__B);
}

extern __inline __m128d __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_or_pd (__m128d __A, __m128d __B)
{
  return (__m128d)__builtin_ia32_orpd ((__v2df)__A, (__v2df)__B);
}

extern __inline __m128d __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_xor_pd (__m128d __A, __m128d __B)
{
  return (__m128d)__builtin_ia32_xorpd ((__v2df)__A, (__v2df)__B);
}

extern __inline __m128d __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_cmpeq_pd (__m128d __A, __m128d __B)
{
  return (__m128d)__builtin_ia32_cmpeqpd ((__v2df)__A, (__v2df)__B);
}

extern __inline __m128d __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_cmplt_pd (__m128d __A, __m128d __B)
{
  return (__m128d)__builtin_ia32_cmpltpd ((__v2df)__A, (__v2df)__B);
}

extern __inline __m128d __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_cmple_pd (__m128d __A, __m128d __B)
{
  return (__m128d)__builtin_ia32_cmplepd ((__v2df)__A, (__v2df)__B);
}

extern __inline __m128d __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_cmpgt_pd (__m128d __A, __m128d __B)
{
  return (__m128d)__builtin_ia32_cmpgtpd ((__v2df)__A, (__v2df)__B);
}

extern __inline __m128d __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_cmpge_pd (__m128d __A, __m128d __B)
{
  return (__m128d)__builtin_ia32_cmpgepd ((__v2df)__A, (__v2df)__B);
}

extern __inline __m128d __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_cmpneq_pd (__m128d __A, __m128d __B)
{
  return (__m128d)__builtin_ia32_cmpneqpd ((__v2df)__A, (__v2df)__B);
}

extern __inline __m128d __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_cmpnlt_pd (__m128d __A, __m128d __B)
{
  return (__m128d)__builtin_ia32_cmpnltpd ((__v2df)__A, (__v2df)__B);
}

extern __inline __m128d __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_cmpnle_pd (__m128d __A, __m128d __B)
{
  return (__m128d)__builtin_ia32_cmpnlepd ((__v2df)__A, (__v2df)__B);
}

extern __inline __m128d __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_cmpngt_pd (__m128d __A, __m128d __B)
{
  return (__m128d)__builtin_ia32_cmpngtpd ((__v2df)__A, (__v2df)__B);
}

extern __inline __m128d __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_cmpnge_pd (__m128d __A, __m128d __B)
{
  return (__m128d)__builtin_ia32_cmpngepd ((__v2df)__A, (__v2df)__B);
}

extern __inline __m128d __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_cmpord_pd (__m128d __A, __m128d __B)
{
  return (__m128d)__builtin_ia32_cmpordpd ((__v2df)__A, (__v2df)__B);
}

extern __inline __m128d __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_cmpunord_pd (__m128d __A, __m128d __B)
{
  return (__m128d)__builtin_ia32_cmpunordpd ((__v2df)__A, (__v2df)__B);
}

extern __inline __m128d __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_cmpeq_sd (__m128d __A, __m128d __B)
{
  return (__m128d)__builtin_ia32_cmpeqsd ((__v2df)__A, (__v2df)__B);
}

extern __inline __m128d __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_cmplt_sd (__m128d __A, __m128d __B)
{
  return (__m128d)__builtin_ia32_cmpltsd ((__v2df)__A, (__v2df)__B);
}

extern __inline __m128d __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_cmple_sd (__m128d __A, __m128d __B)
{
  return (__m128d)__builtin_ia32_cmplesd ((__v2df)__A, (__v2df)__B);
}

extern __inline __m128d __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_cmpgt_sd (__m128d __A, __m128d __B)
{
  return (__m128d) __builtin_ia32_movsd ((__v2df) __A,
					 (__v2df)
					 __builtin_ia32_cmpltsd ((__v2df) __B,
								 (__v2df)
								 __A));
}

extern __inline __m128d __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_cmpge_sd (__m128d __A, __m128d __B)
{
  return (__m128d) __builtin_ia32_movsd ((__v2df) __A,
					 (__v2df)
					 __builtin_ia32_cmplesd ((__v2df) __B,
								 (__v2df)
								 __A));
}

extern __inline __m128d __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_cmpneq_sd (__m128d __A, __m128d __B)
{
  return (__m128d)__builtin_ia32_cmpneqsd ((__v2df)__A, (__v2df)__B);
}

extern __inline __m128d __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_cmpnlt_sd (__m128d __A, __m128d __B)
{
  return (__m128d)__builtin_ia32_cmpnltsd ((__v2df)__A, (__v2df)__B);
}

extern __inline __m128d __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_cmpnle_sd (__m128d __A, __m128d __B)
{
  return (__m128d)__builtin_ia32_cmpnlesd ((__v2df)__A, (__v2df)__B);
}

extern __inline __m128d __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_cmpngt_sd (__m128d __A, __m128d __B)
{
  return (__m128d) __builtin_ia32_movsd ((__v2df) __A,
					 (__v2df)
					 __builtin_ia32_cmpnltsd ((__v2df) __B,
								  (__v2df)
								  __A));
}

extern __inline __m128d __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_cmpnge_sd (__m128d __A, __m128d __B)
{
  return (__m128d) __builtin_ia32_movsd ((__v2df) __A,
					 (__v2df)
					 __builtin_ia32_cmpnlesd ((__v2df) __B,
								  (__v2df)
								  __A));
}

extern __inline __m128d __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_cmpord_sd (__m128d __A, __m128d __B)
{
  return (__m128d)__builtin_ia32_cmpordsd ((__v2df)__A, (__v2df)__B);
}

extern __inline __m128d __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_cmpunord_sd (__m128d __A, __m128d __B)
{
  return (__m128d)__builtin_ia32_cmpunordsd ((__v2df)__A, (__v2df)__B);
}

extern __inline int __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_comieq_sd (__m128d __A, __m128d __B)
{
  return __builtin_ia32_comisdeq ((__v2df)__A, (__v2df)__B);
}

extern __inline int __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_comilt_sd (__m128d __A, __m128d __B)
{
  return __builtin_ia32_comisdlt ((__v2df)__A, (__v2df)__B);
}

extern __inline int __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_comile_sd (__m128d __A, __m128d __B)
{
  return __builtin_ia32_comisdle ((__v2df)__A, (__v2df)__B);
}

extern __inline int __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_comigt_sd (__m128d __A, __m128d __B)
{
  return __builtin_ia32_comisdgt ((__v2df)__A, (__v2df)__B);
}

extern __inline int __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_comige_sd (__m128d __A, __m128d __B)
{
  return __builtin_ia32_comisdge ((__v2df)__A, (__v2df)__B);
}

extern __inline int __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_comineq_sd (__m128d __A, __m128d __B)
{
  return __builtin_ia32_comisdneq ((__v2df)__A, (__v2df)__B);
}

extern __inline int __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_ucomieq_sd (__m128d __A, __m128d __B)
{
  return __builtin_ia32_ucomisdeq ((__v2df)__A, (__v2df)__B);
}

extern __inline int __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_ucomilt_sd (__m128d __A, __m128d __B)
{
  return __builtin_ia32_ucomisdlt ((__v2df)__A, (__v2df)__B);
}

extern __inline int __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_ucomile_sd (__m128d __A, __m128d __B)
{
  return __builtin_ia32_ucomisdle ((__v2df)__A, (__v2df)__B);
}

extern __inline int __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_ucomigt_sd (__m128d __A, __m128d __B)
{
  return __builtin_ia32_ucomisdgt ((__v2df)__A, (__v2df)__B);
}

extern __inline int __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_ucomige_sd (__m128d __A, __m128d __B)
{
  return __builtin_ia32_ucomisdge ((__v2df)__A, (__v2df)__B);
}

extern __inline int __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_ucomineq_sd (__m128d __A, __m128d __B)
{
  return __builtin_ia32_ucomisdneq ((__v2df)__A, (__v2df)__B);
}
#endif

/* Create a vector of Qi, where i is the element number.  */

extern __inline __m128i __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_set_epi64x (long long __q1, long long __q0)
{
  /* return __extension__ (__m128i)(__v2di){ __q0, __q1 }; */
  __m128i val;
  val.lo = (__m64i)(__v1di){ __q0 };
  val.hi = (__m64i)(__v1di){ __q1 };
  return __extension__ val;
}

extern __inline __m128i __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_set_epi64 (__m64 __q1,  __m64 __q0)
{
  return _mm_set_epi64x ((long long)__q1, (long long)__q0);
}

extern __inline __m128i __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_set_epi32 (int __q3, int __q2, int __q1, int __q0)
{
  /* return __extension__ (__m128i)(__v4si){ __q0, __q1, __q2, __q3 }; */
  __m128i val;
  val.lo = (__m64i)(__v2si){ __q0, __q1 };
  val.hi = (__m64i)(__v2si){ __q2, __q3 };
  return __extension__ val;
}

extern __inline __m128i __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_set_epi16 (short __q7, short __q6, short __q5, short __q4,
	       short __q3, short __q2, short __q1, short __q0)
{
  /* return __extension__ (__m128i)(__v8hi){
      __q0, __q1, __q2, __q3, __q4, __q5, __q6, __q7 }; */
  __m128i val;
  val.lo = (__m64i)(__v4hi){ __q0, __q1, __q2, __q3 };
  val.hi = (__m64i)(__v4hi){ __q4, __q5, __q6, __q7 };
  return __extension__ val;
}

extern __inline __m128i __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_set_epi8 (char __q15, char __q14, char __q13, char __q12,
	      char __q11, char __q10, char __q09, char __q08,
	      char __q07, char __q06, char __q05, char __q04,
	      char __q03, char __q02, char __q01, char __q00)
{
  /* return __extension__ (__m128i)(__v16qi){
      __q00, __q01, __q02, __q03, __q04, __q05, __q06, __q07,
      __q08, __q09, __q10, __q11, __q12, __q13, __q14, __q15
    }; */
  __m128i val;
  val.lo = (__m64i)(__v8qi){ __q00, __q01, __q02, __q03, __q04, __q05, __q06, __q07 };
  val.hi = (__m64i)(__v8qi){ __q08, __q09, __q10, __q11, __q12, __q13, __q14, __q15 };
  return __extension__ val;
}

/* Set all of the elements of the vector to A.  */

extern __inline __m128i __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_set1_epi64x (long long __A)
{
  return _mm_set_epi64x (__A, __A);
}

extern __inline __m128i __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_set1_epi64 (__m64 __A)
{
  return _mm_set_epi64 (__A, __A);
}

extern __inline __m128i __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_set1_epi32 (int __A)
{
  return _mm_set_epi32 (__A, __A, __A, __A);
}

extern __inline __m128i __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_set1_epi16 (short __A)
{
  return _mm_set_epi16 (__A, __A, __A, __A, __A, __A, __A, __A);
}

extern __inline __m128i __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_set1_epi8 (char __A)
{
  return _mm_set_epi8 (__A, __A, __A, __A, __A, __A, __A, __A,
		       __A, __A, __A, __A, __A, __A, __A, __A);
}

/* Create a vector of Qi, where i is the element number.
   The parameter order is reversed from the _mm_set_epi* functions.  */

extern __inline __m128i __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_setr_epi64 (__m64 __q0, __m64 __q1)
{
  return _mm_set_epi64 (__q1, __q0);
}

extern __inline __m128i __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_setr_epi32 (int __q0, int __q1, int __q2, int __q3)
{
  return _mm_set_epi32 (__q3, __q2, __q1, __q0);
}

extern __inline __m128i __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_setr_epi16 (short __q0, short __q1, short __q2, short __q3,
	        short __q4, short __q5, short __q6, short __q7)
{
  return _mm_set_epi16 (__q7, __q6, __q5, __q4, __q3, __q2, __q1, __q0);
}

extern __inline __m128i __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_setr_epi8 (char __q00, char __q01, char __q02, char __q03,
	       char __q04, char __q05, char __q06, char __q07,
	       char __q08, char __q09, char __q10, char __q11,
	       char __q12, char __q13, char __q14, char __q15)
{
  return _mm_set_epi8 (__q15, __q14, __q13, __q12, __q11, __q10, __q09, __q08,
		       __q07, __q06, __q05, __q04, __q03, __q02, __q01, __q00);
}

/* Create a vector with element 0 as *P and the rest zero.  */

extern __inline __m128i __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_load_si128 (__m128i const *__P)
{
  return *__P;
}

extern __inline __m128i __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_loadu_si128 (__m128i const *__P)
{
  /* return (__m128i) __builtin_ia32_loaddqu ((char const *)__P); */
  __m128i val;
  __asm__ volatile (
    "gsldlc1    %[lo],      0x07(%[__P])                                \n\t"
    "gsldrc1    %[lo],      0x00(%[__P])                                \n\t"
    "gsldlc1    %[hi],      0x0f(%[__P])                                \n\t"
    "gsldrc1    %[hi],      0x08(%[__P])                                \n\t"
    : [hi]"=&f"(val.hi),            [lo]"=&f"(val.lo)
    : [__P]"r"(__P)
  );
  return val;
}

extern __inline __m128i __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_loadl_epi64 (__m128i const *__P)
{
  return _mm_set_epi64 ((__m64)0LL, *(__m64 *)__P);
}

extern __inline void __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_store_si128 (__m128i *__P, __m128i __B)
{
  /* *__P = __B; */
  __asm__ volatile (
    "gssqc1     %[hi],      %[lo],      0x00(%[__P])                    \n\t"
    ::[hi]"f"(__B.hi),              [lo]"f"(__B.lo),
      [__P]"r"(__P)
    : "memory"
  );
}

extern __inline void __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_storeu_si128 (__m128i *__P, __m128i __B)
{
  /* __builtin_ia32_storedqu ((char *)__P, (__v16qi)__B); */
  __asm__ volatile (
    "gssdlc1    %[lo],      0x07(%[__P])                                \n\t"
    "gssdrc1    %[lo],      0x00(%[__P])                                \n\t"
    "gssdlc1    %[hi],      0x0f(%[__P])                                \n\t"
    "gssdrc1    %[hi],      0x08(%[__P])                                \n\t"
    ::[hi]"f"(__B.hi),              [lo]"f"(__B.lo),
      [__P]"r"(__P)
    : "memory"
  );
}

extern __inline void __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_storel_epi64 (__m128i *__P, __m128i __B)
{
  /* *(long long *)__P = ((__v2di)__B)[0]; */
  __asm__ volatile (
    "sdc1       %[lo],      %[__P]                                      \n\t"
    ::[lo]"f"(__B.lo),              [__P]"m"(*__P)
    : "memory"
  );
}

extern __inline __m64 __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_movepi64_pi64 (__m128i __B)
{
  /* return (__m64) ((__v2di)__B)[0]; */
  __m64 val;
  __asm__ volatile (
    "dmfc1      %[val],    %[lo]                                        \n\t"
    : [val]"=&r"(val)
    : [lo]"f"(__B.lo)
  );
  return val;
}

extern __inline __m128i __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_movpi64_epi64 (__m64 __A)
{
  return _mm_set_epi64 ((__m64)0LL, __A);
}

#if 0 /* FIXME */
extern __inline __m128i __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_move_epi64 (__m128i __A)
{
  return (__m128i)__builtin_ia32_movq128 ((__v2di) __A);
}

/* Create an undefined vector.  */
extern __inline __m128i __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_undefined_si128 (void)
{
  __m128i __Y = __Y;
  return __Y;
}
#endif

/* Create a vector of zeros.  */
extern __inline __m128i __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_setzero_si128 (void)
{
  /* return __extension__ (__m128i)(__v4si){ 0, 0, 0, 0 }; */
  __m128i val;
  val.hi = (__m64i)(__v2si){ 0, 0 };
  val.lo = (__m64i)(__v2si){ 0, 0 };
  return val;
}

#if 0 /* FIXME */
extern __inline __m128d __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_cvtepi32_pd (__m128i __A)
{
  return (__m128d)__builtin_ia32_cvtdq2pd ((__v4si) __A);
}

extern __inline __m128 __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_cvtepi32_ps (__m128i __A)
{
  return (__m128)__builtin_ia32_cvtdq2ps ((__v4si) __A);
}

extern __inline __m128i __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_cvtpd_epi32 (__m128d __A)
{
  return (__m128i)__builtin_ia32_cvtpd2dq ((__v2df) __A);
}

extern __inline __m64 __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_cvtpd_pi32 (__m128d __A)
{
  return (__m64)__builtin_ia32_cvtpd2pi ((__v2df) __A);
}

extern __inline __m128 __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_cvtpd_ps (__m128d __A)
{
  return (__m128)__builtin_ia32_cvtpd2ps ((__v2df) __A);
}

extern __inline __m128i __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_cvttpd_epi32 (__m128d __A)
{
  return (__m128i)__builtin_ia32_cvttpd2dq ((__v2df) __A);
}

extern __inline __m64 __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_cvttpd_pi32 (__m128d __A)
{
  return (__m64)__builtin_ia32_cvttpd2pi ((__v2df) __A);
}

extern __inline __m128d __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_cvtpi32_pd (__m64 __A)
{
  return (__m128d)__builtin_ia32_cvtpi2pd ((__v2si) __A);
}

extern __inline __m128i __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_cvtps_epi32 (__m128 __A)
{
  return (__m128i)__builtin_ia32_cvtps2dq ((__v4sf) __A);
}

extern __inline __m128i __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_cvttps_epi32 (__m128 __A)
{
  return (__m128i)__builtin_ia32_cvttps2dq ((__v4sf) __A);
}

extern __inline __m128d __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_cvtps_pd (__m128 __A)
{
  return (__m128d)__builtin_ia32_cvtps2pd ((__v4sf) __A);
}

extern __inline int __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_cvtsd_si32 (__m128d __A)
{
  return __builtin_ia32_cvtsd2si ((__v2df) __A);
}

#ifdef __x86_64__
/* Intel intrinsic.  */
extern __inline long long __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_cvtsd_si64 (__m128d __A)
{
  return __builtin_ia32_cvtsd2si64 ((__v2df) __A);
}

/* Microsoft intrinsic.  */
extern __inline long long __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_cvtsd_si64x (__m128d __A)
{
  return __builtin_ia32_cvtsd2si64 ((__v2df) __A);
}
#endif

extern __inline int __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_cvttsd_si32 (__m128d __A)
{
  return __builtin_ia32_cvttsd2si ((__v2df) __A);
}

#ifdef __x86_64__
/* Intel intrinsic.  */
extern __inline long long __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_cvttsd_si64 (__m128d __A)
{
  return __builtin_ia32_cvttsd2si64 ((__v2df) __A);
}

/* Microsoft intrinsic.  */
extern __inline long long __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_cvttsd_si64x (__m128d __A)
{
  return __builtin_ia32_cvttsd2si64 ((__v2df) __A);
}
#endif

extern __inline __m128 __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_cvtsd_ss (__m128 __A, __m128d __B)
{
  return (__m128)__builtin_ia32_cvtsd2ss ((__v4sf) __A, (__v2df) __B);
}

extern __inline __m128d __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_cvtsi32_sd (__m128d __A, int __B)
{
  return (__m128d)__builtin_ia32_cvtsi2sd ((__v2df) __A, __B);
}

#ifdef __x86_64__
/* Intel intrinsic.  */
extern __inline __m128d __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_cvtsi64_sd (__m128d __A, long long __B)
{
  return (__m128d)__builtin_ia32_cvtsi642sd ((__v2df) __A, __B);
}

/* Microsoft intrinsic.  */
extern __inline __m128d __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_cvtsi64x_sd (__m128d __A, long long __B)
{
  return (__m128d)__builtin_ia32_cvtsi642sd ((__v2df) __A, __B);
}
#endif

extern __inline __m128d __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_cvtss_sd (__m128d __A, __m128 __B)
{
  return (__m128d)__builtin_ia32_cvtss2sd ((__v2df) __A, (__v4sf)__B);
}

extern __inline __m128d __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_shuffle_pd(__m128d __A, __m128d __B, const int __mask)
{
  return (__m128d)__builtin_ia32_shufpd ((__v2df)__A, (__v2df)__B, __mask);
}

extern __inline __m128d __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_unpackhi_pd (__m128d __A, __m128d __B)
{
  return (__m128d)__builtin_ia32_unpckhpd ((__v2df)__A, (__v2df)__B);
}

extern __inline __m128d __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_unpacklo_pd (__m128d __A, __m128d __B)
{
  return (__m128d)__builtin_ia32_unpcklpd ((__v2df)__A, (__v2df)__B);
}
#endif

extern __inline __m128d __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_loadh_pd (__m128d __A, double const *__B)
{
  /* return (__m128d)__builtin_ia32_loadhpd ((__v2df)__A, __B); */
  __asm__ volatile (
    "sdc1       %[__B],     0x00+%[ahi]                                 \n\t"
    : [ahi]"=m"(__A.hi)
    : [__B]"f"(*__B)
    : "memory"
  );
  return __A;
}

#if 0 /* FIXME */
extern __inline __m128d __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_loadl_pd (__m128d __A, double const *__B)
{
  return (__m128d)__builtin_ia32_loadlpd ((__v2df)__A, __B);
}

extern __inline int __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_movemask_pd (__m128d __A)
{
  return __builtin_ia32_movmskpd ((__v2df)__A);
}
#endif

extern __inline __m128i __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_packs_epi16 (__m128i __A, __m128i __B)
{
  /* return (__m128i)__builtin_ia32_packsswb128 ((__v8hi)__A, (__v8hi)__B); */
  __m128i val;
  val.hi = (__m64i) __builtin_loongson_packsshb ((int16x4_t)__A.hi, (int16x4_t)__B.hi);
  val.lo = (__m64i) __builtin_loongson_packsshb ((int16x4_t)__A.lo, (int16x4_t)__B.lo);
  return val;
}

extern __inline __m128i __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_packs_epi32 (__m128i __A, __m128i __B)
{
  /* return (__m128i)__builtin_ia32_packssdw128 ((__v4si)__A, (__v4si)__B); */
  __m128i val;
  val.hi = (__m64i) __builtin_loongson_packsswh ((int32x2_t)__A.hi, (int32x2_t)__B.hi);
  val.lo = (__m64i) __builtin_loongson_packsswh ((int32x2_t)__A.lo, (int32x2_t)__B.lo);
  return val;
}

extern __inline __m128i __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_packus_epi16 (__m128i __A, __m128i __B)
{
  /* return (__m128i)__builtin_ia32_packuswb128 ((__v8hi)__A, (__v8hi)__B); */
  __m128i val;
  val.hi = (__m64i) __builtin_loongson_packushb ((uint16x4_t)__A.hi, (uint16x4_t)__B.hi);
  val.lo = (__m64i) __builtin_loongson_packushb ((uint16x4_t)__A.lo, (uint16x4_t)__B.lo);
  return val;
}

extern __inline __m128i __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_unpackhi_epi8 (__m128i __A, __m128i __B)
{
  /* return (__m128i)__builtin_ia32_punpckhbw128 ((__v16qi)__A, (__v16qi)__B); */
  __m128i val;
  val.hi = (__m64i) __builtin_loongson_punpckhbh_s ((int8x8_t)__A.hi, (int8x8_t)__B.hi);
  val.lo = (__m64i) __builtin_loongson_punpckhbh_s ((int8x8_t)__A.lo, (int8x8_t)__B.lo);
  return val;
}

extern __inline __m128i __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_unpackhi_epi16 (__m128i __A, __m128i __B)
{
  /* return (__m128i)__builtin_ia32_punpckhwd128 ((__v8hi)__A, (__v8hi)__B); */
  __m128i val;
  val.hi = (__m64i) __builtin_loongson_punpckhhw_s ((int16x4_t)__A.hi, (int16x4_t)__B.hi);
  val.lo = (__m64i) __builtin_loongson_punpckhhw_s ((int16x4_t)__A.lo, (int16x4_t)__B.lo);
  return val;
}

extern __inline __m128i __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_unpackhi_epi32 (__m128i __A, __m128i __B)
{
  /* return (__m128i)__builtin_ia32_punpckhdq128 ((__v4si)__A, (__v4si)__B); */
  __m128i val;
  val.hi = (__m64i) __builtin_loongson_punpckhwd_s ((__v2si)__A.hi, (__v2si)__B.hi);
  val.lo = (__m64i) __builtin_loongson_punpckhwd_s ((__v2si)__A.lo, (__v2si)__B.lo);
  return val;
}

extern __inline __m128i __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_unpackhi_epi64 (__m128i __A, __m128i __B)
{
  /* return (__m128i)__builtin_ia32_punpckhqdq128 ((__v2di)__A, (__v2di)__B); */
  __m128i val;
  __asm__ volatile (
    "mov.d      %[vlo],     %[ahi]                                      \n\t"
    "mov.d      %[vhi],     %[bhi]                                      \n\t"
    : [vhi]"=&f"(val.hi),           [vlo]"=&f"(val.lo)
    : [ahi]"f"(__A.hi),             [bhi]"f"(__B.hi)
  );
  return val;
}

extern __inline __m128i __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_unpacklo_epi8 (__m128i __A, __m128i __B)
{
  /* return (__m128i)__builtin_ia32_punpcklbw128 ((__v16qi)__A, (__v16qi)__B); */
  __m128i val;
  val.hi = (__m64i) __builtin_loongson_punpcklbh_s ((int8x8_t)__A.hi, (int8x8_t)__B.hi);
  val.lo = (__m64i) __builtin_loongson_punpcklbh_s ((int8x8_t)__A.lo, (int8x8_t)__B.lo);
  return val;
}

extern __inline __m128i __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_unpacklo_epi16 (__m128i __A, __m128i __B)
{
  /* return (__m128i)__builtin_ia32_punpcklwd128 ((__v8hi)__A, (__v8hi)__B); */
  __m128i val;
  val.hi = (__m64i) __builtin_loongson_punpcklhw_s ((int16x4_t)__A.hi, (int16x4_t)__B.hi);
  val.lo = (__m64i) __builtin_loongson_punpcklhw_s ((int16x4_t)__A.lo, (int16x4_t)__B.lo);
  return val;
}

extern __inline __m128i __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_unpacklo_epi32 (__m128i __A, __m128i __B)
{
  /* return (__m128i)__builtin_ia32_punpckldq128 ((__v4si)__A, (__v4si)__B); */
  __m128i val;
  val.hi = (__m64i) __builtin_loongson_punpcklwd_s ((__v2si)__A.hi, (__v2si)__B.hi);
  val.lo = (__m64i) __builtin_loongson_punpcklwd_s ((__v2si)__A.lo, (__v2si)__B.lo);
  return val;
}

extern __inline __m128i __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_unpacklo_epi64 (__m128i __A, __m128i __B)
{
  /* return (__m128i)__builtin_ia32_punpcklqdq128 ((__v2di)__A, (__v2di)__B); */
  __m128i val;
  __asm__ volatile (
    "mov.d      %[vlo],     %[alo]                                      \n\t"
    "mov.d      %[vhi],     %[blo]                                      \n\t"
    : [vhi]"=&f"(val.hi),           [vlo]"=&f"(val.lo)
    : [alo]"f"(__A.lo),             [blo]"f"(__B.lo)
  );
  return val;
}

extern __inline __m128i __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_add_epi8 (__m128i __A, __m128i __B)
{
  /* return (__m128i) ((__v16qu)__A + (__v16qu)__B); */
  __m128i val;
  val.hi = (__m64i) ((__v8qu)__A.hi + (__v8qu)__B.hi);
  val.lo = (__m64i) ((__v8qu)__A.lo + (__v8qu)__B.lo);
  return val;
}

extern __inline __m128i __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_add_epi16 (__m128i __A, __m128i __B)
{
  /* return (__m128i) ((__v8hu)__A + (__v8hu)__B); */
  __m128i val;
  val.hi = (__m64i) ((__v4hu)__A.hi + (__v4hu)__B.hi);
  val.lo = (__m64i) ((__v4hu)__A.lo + (__v4hu)__B.lo);
  return val;
}

extern __inline __m128i __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_add_epi32 (__m128i __A, __m128i __B)
{
  /* return (__m128i) ((__v4su)__A + (__v4su)__B); */
  __m128i val;
  val.hi = (__m64i) ((__v2su)__A.hi + (__v2su)__B.hi);
  val.lo = (__m64i) ((__v2su)__A.lo + (__v2su)__B.lo);
  return val;
}

extern __inline __m128i __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_add_epi64 (__m128i __A, __m128i __B)
{
  /* return (__m128i) ((__v2du)__A + (__v2du)__B); */
  __m128i val;
  val.hi = (__m64i) ((__v1du)__A.hi + (__v1du)__B.hi);
  val.lo = (__m64i) ((__v1du)__A.lo + (__v1du)__B.lo);
  return val;
}

extern __inline __m128i __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_adds_epi8 (__m128i __A, __m128i __B)
{
  /* return (__m128i)__builtin_ia32_paddsb128 ((__v16qi)__A, (__v16qi)__B); */
  __m128i val;
  val.hi = (__m64i) __builtin_loongson_paddsb ((int8x8_t)__A.hi, (int8x8_t)__B.hi);
  val.lo = (__m64i) __builtin_loongson_paddsb ((int8x8_t)__A.lo, (int8x8_t)__B.lo);
  return val;
}

extern __inline __m128i __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_adds_epi16 (__m128i __A, __m128i __B)
{
  /* return (__m128i)__builtin_ia32_paddsw128 ((__v8hi)__A, (__v8hi)__B); */
  __m128i val;
  val.hi = (__m64i) __builtin_loongson_paddsh ((int16x4_t)__A.hi, (int16x4_t)__B.hi);
  val.lo = (__m64i) __builtin_loongson_paddsh ((int16x4_t)__A.lo, (int16x4_t)__B.lo);
  return val;
}

extern __inline __m128i __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_adds_epu8 (__m128i __A, __m128i __B)
{
  /* return (__m128i)__builtin_ia32_paddusb128 ((__v16qi)__A, (__v16qi)__B); */
  __m128i val;
  val.hi = (__m64i) __builtin_loongson_paddusb ((uint8x8_t)__A.hi, (uint8x8_t)__B.hi);
  val.lo = (__m64i) __builtin_loongson_paddusb ((uint8x8_t)__A.lo, (uint8x8_t)__B.lo);
  return val;
}

extern __inline __m128i __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_adds_epu16 (__m128i __A, __m128i __B)
{
  /* return (__m128i)__builtin_ia32_paddusw128 ((__v8hi)__A, (__v8hi)__B); */
  __m128i val;
  val.hi = (__m64i) __builtin_loongson_paddush ((uint16x4_t)__A.hi, (uint16x4_t)__B.hi);
  val.lo = (__m64i) __builtin_loongson_paddush ((uint16x4_t)__A.lo, (uint16x4_t)__B.lo);
  return val;
}

extern __inline __m128i __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_sub_epi8 (__m128i __A, __m128i __B)
{
  /* return (__m128i) ((__v16qu)__A - (__v16qu)__B); */
  __m128i val;
  val.hi = (__m64i) ((__v8qu)__A.hi - (__v8qu)__B.hi);
  val.lo = (__m64i) ((__v8qu)__A.lo - (__v8qu)__B.lo);
  return val;
}

extern __inline __m128i __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_sub_epi16 (__m128i __A, __m128i __B)
{
  /* return (__m128i) ((__v8hu)__A - (__v8hu)__B); */
  __m128i val;
  val.hi = (__m64i) ((__v4hu)__A.hi - (__v4hu)__B.hi);
  val.lo = (__m64i) ((__v4hu)__A.lo - (__v4hu)__B.lo);
  return val;
}

extern __inline __m128i __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_sub_epi32 (__m128i __A, __m128i __B)
{
  /* return (__m128i) ((__v4su)__A - (__v4su)__B); */
  __m128i val;
  val.hi = (__m64i) ((__v2su)__A.hi - (__v2su)__B.hi);
  val.lo = (__m64i) ((__v2su)__A.lo - (__v2su)__B.lo);
  return val;
}

extern __inline __m128i __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_sub_epi64 (__m128i __A, __m128i __B)
{
  /* return (__m128i) ((__v2du)__A - (__v2du)__B); */
  __m128i val;
  val.hi = (__m64i) ((__v1du)__A.hi - (__v1du)__B.hi);
  val.lo = (__m64i) ((__v1du)__A.lo - (__v1du)__B.lo);
  return val;
}

extern __inline __m128i __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_subs_epi8 (__m128i __A, __m128i __B)
{
  /* return (__m128i)__builtin_ia32_psubsb128 ((__v16qi)__A, (__v16qi)__B); */
  __m128i val;
  val.hi = (__m64i) __builtin_loongson_psubsb ((int8x8_t)__A.hi, (int8x8_t)__B.hi);
  val.lo = (__m64i) __builtin_loongson_psubsb ((int8x8_t)__A.lo, (int8x8_t)__B.lo);
  return val;
}

extern __inline __m128i __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_subs_epi16 (__m128i __A, __m128i __B)
{
  /* return (__m128i)__builtin_ia32_psubsw128 ((__v8hi)__A, (__v8hi)__B); */
  __m128i val;
  val.hi = (__m64i) __builtin_loongson_psubsh ((int16x4_t)__A.hi, (int16x4_t)__B.hi);
  val.lo = (__m64i) __builtin_loongson_psubsh ((int16x4_t)__A.lo, (int16x4_t)__B.lo);
  return val;
}

extern __inline __m128i __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_subs_epu8 (__m128i __A, __m128i __B)
{
  /* return (__m128i)__builtin_ia32_psubusb128 ((__v16qi)__A, (__v16qi)__B); */
  __m128i val;
  val.hi = (__m64i) __builtin_loongson_psubusb ((uint8x8_t)__A.hi, (uint8x8_t)__B.hi);
  val.lo = (__m64i) __builtin_loongson_psubusb ((uint8x8_t)__A.lo, (uint8x8_t)__B.lo);
  return val;
}

extern __inline __m128i __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_subs_epu16 (__m128i __A, __m128i __B)
{
  /* return (__m128i)__builtin_ia32_psubusw128 ((__v8hi)__A, (__v8hi)__B); */
  __m128i val;
  val.hi = (__m64i) __builtin_loongson_psubush ((uint16x4_t)__A.hi, (uint16x4_t)__B.hi);
  val.lo = (__m64i) __builtin_loongson_psubush ((uint16x4_t)__A.lo, (uint16x4_t)__B.lo);
  return val;
}

extern __inline __m128i __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_madd_epi16 (__m128i __A, __m128i __B)
{
  /* return (__m128i)__builtin_ia32_pmaddwd128 ((__v8hi)__A, (__v8hi)__B); */
  __m128i val;
  val.hi = (__m64i) __builtin_loongson_pmaddhw ((int16x4_t)__A.hi, (int16x4_t)__B.hi);
  val.lo = (__m64i) __builtin_loongson_pmaddhw ((int16x4_t)__A.lo, (int16x4_t)__B.lo);
  return val;
}

extern __inline __m128i __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_mulhi_epi16 (__m128i __A, __m128i __B)
{
  /* return (__m128i)__builtin_ia32_pmulhw128 ((__v8hi)__A, (__v8hi)__B); */
  __m128i val;
  val.hi = (__m64i) __builtin_loongson_pmulhh ((int16x4_t)__A.hi, (int16x4_t)__B.hi);
  val.lo = (__m64i) __builtin_loongson_pmulhh ((int16x4_t)__A.lo, (int16x4_t)__B.lo);
  return val;
}

extern __inline __m128i __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_mullo_epi16 (__m128i __A, __m128i __B)
{
  /* return (__m128i) ((__v8hu)__A * (__v8hu)__B); */
  __m128i val;
  val.hi = (__m64i) ((__v4hu)__A.hi * (__v4hu)__B.hi);
  val.lo = (__m64i) ((__v4hu)__A.lo * (__v4hu)__B.lo);
  return val;
}

extern __inline __m64 __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_mul_su32 (__m64 __A, __m64 __B)
{
  /* return (__m64)__builtin_ia32_pmuludq ((__v2si)__A, (__v2si)__B); */
  __m64 val;
  val = (__m64) __builtin_loongson_pmuluw ((uint32x2_t)__A, (uint32x2_t)__B);
  return val;
}

extern __inline __m128i __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_mul_epu32 (__m128i __A, __m128i __B)
{
  /* return (__m128i)__builtin_ia32_pmuludq128 ((__v4si)__A, (__v4si)__B); */
  __m128i val;
  val.hi = (__m64i) __builtin_loongson_pmuluw ((uint32x2_t)__A.hi, (uint32x2_t)__B.hi);
  val.lo = (__m64i) __builtin_loongson_pmuluw ((uint32x2_t)__A.lo, (uint32x2_t)__B.lo);
  return val;
}

extern __inline __m128i __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_slli_epi16 (__m128i __A, int __B)
{
  /* return (__m128i)__builtin_ia32_psllwi128 ((__v8hi)__A, __B); */
  __m128i val;
  val.hi = (__m64i) __builtin_loongson_psllh_s ((int16x4_t)__A.hi, (uint8_t)__B);
  val.lo = (__m64i) __builtin_loongson_psllh_s ((int16x4_t)__A.lo, (uint8_t)__B);
  return val;
}

extern __inline __m128i __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_slli_epi32 (__m128i __A, int __B)
{
  /* return (__m128i)__builtin_ia32_pslldi128 ((__v4si)__A, __B); */
  __m128i val;
  val.hi = (__m64i) __builtin_loongson_psllw_s ((int32x2_t)__A.hi, (uint8_t)__B);
  val.lo = (__m64i) __builtin_loongson_psllw_s ((int32x2_t)__A.lo, (uint8_t)__B);
  return val;
}

extern __inline __m128i __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_slli_epi64 (__m128i __A, int __B)
{
  /* return (__m128i)__builtin_ia32_psllqi128 ((__v2di)__A, __B); */
  __m128i val;
  __asm__ volatile (
    "dsll       %[lo],      %[lo],      %[__B]                          \n\t"
    "dsll       %[hi],      %[hi],      %[__B]                          \n\t"
    : [hi]"=&f"(__A.hi),            [lo]"=&f"(__A.lo)
    : [__B]"f"(__B)
  );
  return val;
}

extern __inline __m128i __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_srai_epi16 (__m128i __A, int __B)
{
  /* return (__m128i)__builtin_ia32_psrawi128 ((__v8hi)__A, __B); */
  __m128i val;
  val.hi = (__m64i) __builtin_loongson_psrah_s ((int16x4_t)__A.hi, (uint8_t)__B);
  val.lo = (__m64i) __builtin_loongson_psrah_s ((int16x4_t)__A.lo, (uint8_t)__B);
  return val;
}

extern __inline __m128i __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_srai_epi32 (__m128i __A, int __B)
{
  /* return (__m128i)__builtin_ia32_psradi128 ((__v4si)__A, __B); */
  __m128i val;
  val.hi = (__m64i) __builtin_loongson_psraw_s ((int32x2_t)__A.hi, (uint8_t)__B);
  val.lo = (__m64i) __builtin_loongson_psraw_s ((int32x2_t)__A.lo, (uint8_t)__B);
  return val;
}

extern __inline __m128i __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_bsrli_si128 (__m128i __A, const int __N)
{
  /* return (__m128i)__builtin_ia32_psrldqi128 (__A, __N * 8); */
  __m128i val;
  val.hi = (__m64i) __builtin_loongson_psrlw_s ((int32x2_t)__A.hi, (uint8_t)(__N<<3));
  val.lo = (__m64i) __builtin_loongson_psrlw_s ((int32x2_t)__A.lo, (uint8_t)(__N<<3));
  return val;
}

extern __inline __m128i __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_bslli_si128 (__m128i __A, const int __N)
{
  /* return (__m128i)__builtin_ia32_pslldqi128 (__A, __N * 8); */
  __m128i val;
  val.hi = (__m64i) __builtin_loongson_psllw_s ((int32x2_t)__A.hi, (uint8_t)(__N<<3));
  val.lo = (__m64i) __builtin_loongson_psllw_s ((int32x2_t)__A.lo, (uint8_t)(__N<<3));
  return val;
}

extern __inline __m128i __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_srli_si128 (__m128i __A, const int __N)
{
  /* return (__m128i)__builtin_ia32_psrldqi128 (__A, __N * 8); */
  __m128i val;
  val.hi = (__m64i) __builtin_loongson_psrlw_s ((int32x2_t)__A.hi, (uint8_t)(__N<<3));
  val.lo = (__m64i) __builtin_loongson_psrlw_s ((int32x2_t)__A.lo, (uint8_t)(__N<<3));
  return val;
}

extern __inline __m128i __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_slli_si128 (__m128i __A, const int __N)
{
  /* return (__m128i)__builtin_ia32_pslldqi128 (__A, __N * 8); */
  __m128i val;
  val.hi = (__m64i) __builtin_loongson_psllw_s ((int32x2_t)__A.hi, (uint8_t)(__N<<3));
  val.lo = (__m64i) __builtin_loongson_psllw_s ((int32x2_t)__A.lo, (uint8_t)(__N<<3));
  return val;
}

extern __inline __m128i __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_srli_epi16 (__m128i __A, int __B)
{
  /* return (__m128i)__builtin_ia32_psrlwi128 ((__v8hi)__A, __B); */
  __m128i val;
  val.hi = (__m64i) __builtin_loongson_psrlh_s ((int16x4_t)__A.hi, (uint8_t)__B);
  val.lo = (__m64i) __builtin_loongson_psrlh_s ((int16x4_t)__A.lo, (uint8_t)__B);
  return val;
}

extern __inline __m128i __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_srli_epi32 (__m128i __A, int __B)
{
  /* return (__m128i)__builtin_ia32_psrldi128 ((__v4si)__A, __B); */
  __m128i val;
  val.hi = (__m64i) __builtin_loongson_psrlw_s ((int32x2_t)__A.hi, (uint8_t)__B);
  val.lo = (__m64i) __builtin_loongson_psrlw_s ((int32x2_t)__A.lo, (uint8_t)__B);
  return val;
}

extern __inline __m128i __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_srli_epi64 (__m128i __A, int __B)
{
  /* return (__m128i)__builtin_ia32_psrlqi128 ((__v2di)__A, __B); */
  __m128i val;
  __asm__ volatile (
    "dsrl       %[vlo],     %[lo],      %[__B]                          \n\t"
    "dsrl       %[vhi],     %[hi],      %[__B]                          \n\t"
    : [vhi]"=&f"(val.hi),           [vlo]"=&f"(val.lo)
    : [hi]"f"(__A.hi),              [lo]"f"(__A.lo),
      [__B]"f"(__B)
  );
  return val;
}

extern __inline __m128i __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_sll_epi16 (__m128i __A, __m128i __B)
{
  /* return (__m128i)__builtin_ia32_psllw128((__v8hi)__A, (__v8hi)__B); */
  __m128i val;
  __asm__ volatile (
    "psllh      %[vlo],     %[lo],      %[__B]                          \n\t"
    "psllh      %[vhi],     %[hi],      %[__B]                          \n\t"
    : [vhi]"=&f"(val.hi),           [vlo]"=&f"(val.lo)
    : [hi]"f"(__A.hi),              [lo]"f"(__A.lo),
      [__B]"f"(__B.lo)
  );
  return val;
}

extern __inline __m128i __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_sll_epi32 (__m128i __A, __m128i __B)
{
  /* return (__m128i)__builtin_ia32_pslld128((__v4si)__A, (__v4si)__B); */
  __m128i val;
  __asm__ volatile (
    "psllw      %[vlo],     %[lo],      %[__B]                          \n\t"
    "psllw      %[vhi],     %[hi],      %[__B]                          \n\t"
    : [vhi]"=&f"(val.hi),           [vlo]"=&f"(val.lo)
    : [hi]"f"(__A.hi),              [lo]"f"(__A.lo),
      [__B]"f"(__B.lo)
  );
  return val;
}

extern __inline __m128i __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_sll_epi64 (__m128i __A, __m128i __B)
{
  /* return (__m128i)__builtin_ia32_psllq128((__v2di)__A, (__v2di)__B); */
  __m128i val;
  __asm__ volatile (
    "dsll       %[vlo],     %[lo],      %[__B]                          \n\t"
    "dsll       %[vhi],     %[hi],      %[__B]                          \n\t"
    : [vhi]"=&f"(val.hi),           [vlo]"=&f"(val.lo)
    : [hi]"f"(__A.hi),              [lo]"f"(__A.lo),
      [__B]"f"(__B.lo)
  );
  return val;
}

extern __inline __m128i __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_sra_epi16 (__m128i __A, __m128i __B)
{
  /* return (__m128i)__builtin_ia32_psraw128 ((__v8hi)__A, (__v8hi)__B); */
  __m128i val;
  __asm__ volatile (
    "psrah      %[vlo],     %[lo],      %[__B]                          \n\t"
    "psrah      %[vhi],     %[hi],      %[__B]                          \n\t"
    : [vhi]"=&f"(val.hi),           [vlo]"=&f"(val.lo)
    : [hi]"f"(__A.hi),              [lo]"f"(__A.lo),
      [__B]"f"(__B.lo)
  );
  return val;
}

extern __inline __m128i __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_sra_epi32 (__m128i __A, __m128i __B)
{
  /* return (__m128i)__builtin_ia32_psrad128 ((__v4si)__A, (__v4si)__B); */
  __m128i val;
  __asm__ volatile (
    "dsra       %[vlo],     %[lo],      %[__B]                          \n\t"
    "dsra       %[vhi],     %[hi],      %[__B]                          \n\t"
    : [vhi]"=&f"(val.hi),           [vlo]"=&f"(val.lo)
    : [hi]"f"(__A.hi),              [lo]"f"(__A.lo),
      [__B]"f"(__B.lo)
  );
  return val;
}

extern __inline __m128i __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_srl_epi16 (__m128i __A, __m128i __B)
{
  /* return (__m128i)__builtin_ia32_psrlw128 ((__v8hi)__A, (__v8hi)__B); */
  __m128i val;
  __asm__ volatile (
    "psrlh      %[vlo],     %[lo],      %[__B]                          \n\t"
    "psrlh      %[vhi],     %[hi],      %[__B]                          \n\t"
    : [vhi]"=&f"(val.hi),           [vlo]"=&f"(val.lo)
    : [hi]"f"(__A.hi),              [lo]"f"(__A.lo),
      [__B]"f"(__B.lo)
  );
  return val;
}

extern __inline __m128i __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_srl_epi32 (__m128i __A, __m128i __B)
{
  /* return (__m128i)__builtin_ia32_psrld128 ((__v4si)__A, (__v4si)__B); */
  __m128i val;
  __asm__ volatile (
    "psrlw      %[vlo],     %[lo],      %[__B]                          \n\t"
    "psrlw      %[vhi],     %[hi],      %[__B]                          \n\t"
    : [vhi]"=&f"(val.hi),           [vlo]"=&f"(val.lo)
    : [hi]"f"(__A.hi),              [lo]"f"(__A.lo),
      [__B]"f"(__B.lo)
  );
  return val;
}

extern __inline __m128i __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_srl_epi64 (__m128i __A, __m128i __B)
{
  /* return (__m128i)__builtin_ia32_psrlq128 ((__v2di)__A, (__v2di)__B); */
  __m128i val;
  __asm__ volatile (
    "dsrl       %[lo],      %[lo],      %[__B]                          \n\t"
    "dsrl       %[hi],      %[hi],      %[__B]                          \n\t"
    : [hi]"=&f"(__A.hi),            [lo]"=&f"(__A.lo)
    : [__B]"f"(__B.lo)
  );
  return val;
}

extern __inline __m128i __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_and_si128 (__m128i __A, __m128i __B)
{
  /* return (__m128i) ((__v2du)__A & (__v2du)__B); */
  __m128i val;
  val.hi = (__m64i) ((__v1du)__A.hi & (__v1du)__B.hi);
  val.lo = (__m64i) ((__v1du)__A.lo & (__v1du)__B.lo);
  return val;
}

extern __inline __m128i __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_andnot_si128 (__m128i __A, __m128i __B)
{
  /* return (__m128i)__builtin_ia32_pandn128 ((__v2di)__A, (__v2di)__B); */
  __m128i val;
  val.hi = (__m64i)__builtin_loongson_pandn_sd ((int64_t)__A.hi, (int64_t)__B.hi);
  val.lo = (__m64i)__builtin_loongson_pandn_sd ((int64_t)__A.lo, (int64_t)__B.lo);
  return val;
}

extern __inline __m128i __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_or_si128 (__m128i __A, __m128i __B)
{
  /* return (__m128i) ((__v2du)__A | (__v2du)__B); */
  __m128i val;
  val.hi = (__m64i) ((__v1du)__A.hi | (__v1du)__B.hi);
  val.lo = (__m64i) ((__v1du)__A.lo | (__v1du)__B.lo);
  return val;
}

extern __inline __m128i __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_xor_si128 (__m128i __A, __m128i __B)
{
  /* return (__m128i) ((__v2du)__A ^ (__v2du)__B); */
  __m128i val;
  val.hi = (__m64i) ((__v1du)__A.hi ^ (__v1du)__B.hi);
  val.lo = (__m64i) ((__v1du)__A.lo ^ (__v1du)__B.lo);
  return val;
}

extern __inline __m128i __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_cmpeq_epi8 (__m128i __A, __m128i __B)
{
  /* return (__m128i) ((__v16qi)__A == (__v16qi)__B); */
  __m128i val;
  val.hi = (__m64i) ((__v8qi)__A.hi == (__v8qi)__B.hi);
  val.lo = (__m64i) ((__v8qi)__A.lo == (__v8qi)__B.lo);
  return val;
}

extern __inline __m128i __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_cmpeq_epi16 (__m128i __A, __m128i __B)
{
  /* return (__m128i) ((__v8hi)__A == (__v8hi)__B); */
  __m128i val;
  val.hi = (__m64i) ((__v4hi)__A.hi == (__v4hi)__B.hi);
  val.lo = (__m64i) ((__v4hi)__A.lo == (__v4hi)__B.lo);
  return val;
}

extern __inline __m128i __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_cmpeq_epi32 (__m128i __A, __m128i __B)
{
  /* return (__m128i) ((__v4si)__A == (__v4si)__B); */
  __m128i val;
  val.hi = (__m64i) ((__v2si)__A.hi == (__v2si)__B.hi);
  val.lo = (__m64i) ((__v2si)__A.lo == (__v2si)__B.lo);
  return val;
}

extern __inline __m128i __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_cmplt_epi8 (__m128i __A, __m128i __B)
{
  /* return (__m128i) ((__v16qi)__A < (__v16qi)__B); */
  __m128i val;
  val.hi = (__m64i) ((__v8qi)__A.hi < (__v8qi)__B.hi);
  val.lo = (__m64i) ((__v8qi)__A.lo < (__v8qi)__B.lo);
  return val;
}

extern __inline __m128i __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_cmplt_epi16 (__m128i __A, __m128i __B)
{
  /* return (__m128i) ((__v8hi)__A < (__v8hi)__B); */
  __m128i val;
  val.hi = (__m64i) ((__v4hi)__A.hi < (__v4hi)__B.hi);
  val.lo = (__m64i) ((__v4hi)__A.lo < (__v4hi)__B.lo);
  return val;
}

extern __inline __m128i __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_cmplt_epi32 (__m128i __A, __m128i __B)
{
  /* return (__m128i) ((__v4si)__A < (__v4si)__B); */
  __m128i val;
  val.hi = (__m64i) ((__v2si)__A.hi < (__v2si)__B.hi);
  val.lo = (__m64i) ((__v2si)__A.lo < (__v2si)__B.lo);
  return val;
}

extern __inline __m128i __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_cmpgt_epi8 (__m128i __A, __m128i __B)
{
  /* return (__m128i) ((__v16qi)__A > (__v16qi)__B); */
  __m128i val;
  val.hi = (__m64i) ((__v8qi)__A.hi > (__v8qi)__B.hi);
  val.lo = (__m64i) ((__v8qi)__A.lo > (__v8qi)__B.lo);
  return val;
}

extern __inline __m128i __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_cmpgt_epi16 (__m128i __A, __m128i __B)
{
  /* return (__m128i) ((__v8hi)__A > (__v8hi)__B); */
  __m128i val;
  val.hi = (__m64i) ((__v4hi)__A.hi > (__v4hi)__B.hi);
  val.lo = (__m64i) ((__v4hi)__A.lo > (__v4hi)__B.lo);
  return val;
}

extern __inline __m128i __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_cmpgt_epi32 (__m128i __A, __m128i __B)
{
  /* return (__m128i) ((__v4si)__A > (__v4si)__B); */
  __m128i val;
  val.hi = (__m64i) ((__v2si)__A.hi > (__v2si)__B.hi);
  val.lo = (__m64i) ((__v2si)__A.lo > (__v2si)__B.lo);
  return val;
}

#if 0 /* FIXME */
#ifdef __OPTIMIZE__
extern __inline int __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_extract_epi16 (__m128i const __A, int const __N)
{
  return (unsigned short) __builtin_ia32_vec_ext_v8hi ((__v8hi)__A, __N);
}

extern __inline __m128i __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_insert_epi16 (__m128i const __A, int const __D, int const __N)
{
  return (__m128i) __builtin_ia32_vec_set_v8hi ((__v8hi)__A, __D, __N);
}
#else
#define _mm_extract_epi16(A, N) \
  ((int) (unsigned short) __builtin_ia32_vec_ext_v8hi ((__v8hi)(__m128i)(A), (int)(N)))
#define _mm_insert_epi16(A, D, N)				\
  ((__m128i) __builtin_ia32_vec_set_v8hi ((__v8hi)(__m128i)(A),	\
					  (int)(D), (int)(N)))
#endif
#endif

extern __inline __m128i __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_max_epi16 (__m128i __A, __m128i __B)
{
  /* return (__m128i)__builtin_ia32_pmaxsw128 ((__v8hi)__A, (__v8hi)__B); */
  __m128i val;
  val.hi = (__m64i) __builtin_loongson_pmaxsh ((int16x4_t)__A.hi, (int16x4_t)__B.hi);
  val.lo = (__m64i) __builtin_loongson_pmaxsh ((int16x4_t)__A.lo, (int16x4_t)__B.lo);
  return val;
}

extern __inline __m128i __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_max_epu8 (__m128i __A, __m128i __B)
{
  /* return (__m128i)__builtin_ia32_pmaxub128 ((__v16qi)__A, (__v16qi)__B); */
  __m128i val;
  val.hi = (__m64i) __builtin_loongson_pmaxub ((uint8x8_t)__A.hi, (uint8x8_t)__B.hi);
  val.lo = (__m64i) __builtin_loongson_pmaxub ((uint8x8_t)__A.lo, (uint8x8_t)__B.lo);
  return val;
}

extern __inline __m128i __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_min_epi16 (__m128i __A, __m128i __B)
{
  /* return (__m128i)__builtin_ia32_pminsw128 ((__v8hi)__A, (__v8hi)__B); */
  __m128i val;
  val.hi = (__m64i) __builtin_loongson_pminsh ((int16x4_t)__A.hi, (int16x4_t)__B.hi);
  val.lo = (__m64i) __builtin_loongson_pminsh ((int16x4_t)__A.lo, (int16x4_t)__B.lo);
  return val;
}

extern __inline __m128i __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_min_epu8 (__m128i __A, __m128i __B)
{
  /* return (__m128i)__builtin_ia32_pminub128 ((__v16qi)__A, (__v16qi)__B); */
  __m128i val;
  val.hi = (__m64i) __builtin_loongson_pminub ((uint8x8_t)__A.hi, (uint8x8_t)__B.hi);
  val.lo = (__m64i) __builtin_loongson_pminub ((uint8x8_t)__A.lo, (uint8x8_t)__B.lo);
  return val;
}

/*  FIXME: return int8x8_t, not int */
extern __inline int8x8_t __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_movemask_epi8 (__m128i __A)
{
  /* return __builtin_ia32_pmovmskb128 ((__v16qi)__A); */
  int8x8_t val;
  val  = __builtin_loongson_pmovmskb_s ((int8x8_t)__A.hi);
  val  = val << 8;
  val |= __builtin_loongson_pmovmskb_s ((int8x8_t)__A.lo);
  return val;
}

extern __inline __m128i __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_mulhi_epu16 (__m128i __A, __m128i __B)
{
  /* return (__m128i)__builtin_ia32_pmulhuw128 ((__v8hi)__A, (__v8hi)__B); */
  __m128i val;
  val.hi = (__m64i) __builtin_loongson_pmulhuh ((uint16x4_t)__A.hi, (uint16x4_t)__B.hi);
  val.lo = (__m64i) __builtin_loongson_pmulhuh ((uint16x4_t)__A.lo, (uint16x4_t)__B.lo);
  return val;
}

extern __inline __m128i __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_shufflehi_epi16 (__m128i __A, const int __mask)
{
  /* return (__m128i)__builtin_ia32_pshufhw ((__v8hi)__A, __mask); */
  __m128i val;
  val.hi = (__m64i) __builtin_loongson_pshufh_s ((int16x4_t)__A.hi, (uint8_t)__mask);
  val.lo = (__m64i) __builtin_loongson_pshufh_s ((int16x4_t)__A.lo, (uint8_t)__mask);
  return val;
}

#if 0 /* FIXME */
extern __inline __m128i __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_shufflelo_epi16 (__m128i __A, const int __mask)
{
  return (__m128i)__builtin_ia32_pshuflw ((__v8hi)__A, __mask);
}

extern __inline __m128i __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_shuffle_epi32 (__m128i __A, const int __mask)
{
  return (__m128i)__builtin_ia32_pshufd ((__v4si)__A, __mask);
}

extern __inline void __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_maskmoveu_si128 (__m128i __A, __m128i __B, char *__C)
{
  __builtin_ia32_maskmovdqu ((__v16qi)__A, (__v16qi)__B, __C);
}
#endif

extern __inline __m128i __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_avg_epu8 (__m128i __A, __m128i __B)
{
  /* return (__m128i)__builtin_ia32_pavgb128 ((__v16qi)__A, (__v16qi)__B); */
  __m128i val;
  val.hi = (__m64i) __builtin_loongson_pavgb ((uint8x8_t)__A.hi, (uint8x8_t)__B.hi);
  val.lo = (__m64i) __builtin_loongson_pavgb ((uint8x8_t)__A.lo, (uint8x8_t)__B.lo);
  return val;
}

extern __inline __m128i __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_avg_epu16 (__m128i __A, __m128i __B)
{
  /* return (__m128i)__builtin_ia32_pavgw128 ((__v8hi)__A, (__v8hi)__B); */
  __m128i val;
  val.hi = (__m64i) __builtin_loongson_pavgh ((uint16x4_t)__A.hi, (uint16x4_t)__B.hi);
  val.lo = (__m64i) __builtin_loongson_pavgh ((uint16x4_t)__A.lo, (uint16x4_t)__B.lo);
  return val;
}

extern __inline __m128i __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_sad_epu8 (__m128i __A, __m128i __B)
{
  /* return (__m128i)__builtin_ia32_psadbw128 ((__v16qi)__A, (__v16qi)__B); */
  __m128i val;
  val.hi = (__m64i) __builtin_loongson_psadbh ((uint8x8_t)__A.hi, (uint8x8_t)__B.hi);
  val.lo = (__m64i) __builtin_loongson_psadbh ((uint8x8_t)__A.lo, (uint8x8_t)__B.lo);
  return val;
}

#if 0 /* FIXME */
extern __inline void __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_stream_si32 (int *__A, int __B)
{
  __builtin_ia32_movnti (__A, __B);
}

extern __inline void __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_stream_si128 (__m128i *__A, __m128i __B)
{
  __builtin_ia32_movntdq ((__v2di *)__A, (__v2di)__B);
}

extern __inline void __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_stream_pd (double *__A, __m128d __B)
{
  __builtin_ia32_movntpd (__A, (__v2df)__B);
}

extern __inline void __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_clflush (void const *__A)
{
  __builtin_ia32_clflush (__A);
}

extern __inline void __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_lfence (void)
{
  __builtin_ia32_lfence ();
}

extern __inline void __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_mfence (void)
{
  __builtin_ia32_mfence ();
}
#endif

extern __inline __m128i __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_cvtsi32_si128 (int __A)
{
  return _mm_set_epi32 (0, 0, 0, __A);
}

extern __inline __m128i __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_cvtsi64_si128 (long long __A)
{
  return _mm_set_epi64x (0, __A);
}

/* Microsoft intrinsic.  */
extern __inline __m128i __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_cvtsi64x_si128 (long long __A)
{
  return _mm_set_epi64x (0, __A);
}

/* Casts between various SP, DP, INT vector types.  Note that these do no
   conversion of values, they just change the type.  */
extern __inline __m128 __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_castpd_ps(__m128d __A)
{
  /* return (__m128) __A; */
  __m128 val;
  val.lo = (__m64) __A.lo;
  val.hi = (__m64) __A.hi;
  return val;
}

extern __inline __m128i __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_castpd_si128(__m128d __A)
{
  /* return (__m128i) __A; */
  __m128i val;
  val.lo = (__m64i) __A.lo;
  val.hi = (__m64i) __A.hi;
  return val;
}

extern __inline __m128d __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_castps_pd(__m128 __A)
{
  /* return (__m128d) __A; */
  __m128d val;
  val.lo = (__m64d) __A.lo;
  val.hi = (__m64d) __A.hi;
  return val;
}

extern __inline __m128i __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_castps_si128(__m128 __A)
{
  /* return (__m128i) __A; */
  __m128i val;
  val.lo = (__m64i) __A.lo;
  val.hi = (__m64i) __A.hi;
  return val;
}

extern __inline __m128 __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_castsi128_ps(__m128i __A)
{
  /* return (__m128) __A; */
  __m128 val;
  val.lo = (__m64) __A.lo;
  val.hi = (__m64) __A.hi;
  return val;
}

extern __inline __m128d __attribute__((__gnu_inline__, __always_inline__, __artificial__))
_mm_castsi128_pd(__m128i __A)
{
  /* return (__m128d) __A; */
  __m128d val;
  val.lo = (__m64d) __A.lo;
  val.hi = (__m64d) __A.hi;
  return val;
}

#ifdef __cplusplus
}
#endif

#endif
