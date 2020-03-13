/* Copyright 2017 The Chromium Authors. All rights reserved.
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file. */

#ifndef THIRD_PARTY_ZLIB_CHROMECONF_H_
#define THIRD_PARTY_ZLIB_CHROMECONF_H_

#if defined(COMPONENT_BUILD)
#if defined(WIN32)
#if defined(ZLIB_IMPLEMENTATION)
#define ZEXTERN __declspec(dllexport)
#else
#define ZEXTERN __declspec(dllimport)
#endif
#elif defined(ZLIB_IMPLEMENTATION)
#define ZEXTERN __attribute__((visibility("default")))
#endif
#endif

/* Rename all zlib names with a  prefix. This is based on the Z_PREFIX
 * option from zconf.h, but with a custom prefix. Where zconf.h would rename
 * both a macro and its underscore-suffixed internal implementation (such as
 * deflateInit2 and deflateInit2_), only the implementation is renamed here.
 * The Byte type is also omitted.
 *
 * To generate this list, run
 * sed -rn -e 's/^# *define +([^ ]+) +(z_[^ ]+)$/#define \1 Cr_\2/p' zconf.h
 * (use -E instead of -r on macOS).
 *
 * gzread is also addressed by modifications in gzread.c and zlib.h. */

#define Z_CR_PREFIX_SET

#define _dist_code _dist_code
#define _length_code _length_code
#define _tr_align _tr_align
#define _tr_flush_bits _tr_flush_bits
#define _tr_flush_block _tr_flush_block
#define _tr_init _tr_init
#define _tr_stored_block _tr_stored_block
#define _tr_tally _tr_tally
#define adler32 adler32
#define adler32_combine adler32_combine
#define adler32_combine64 adler32_combine64
#define adler32_z adler32_z
#define compress compress
#define compress2 compress2
#define compressBound compressBound
#define crc32 crc32
#define crc32_combine crc32_combine
#define crc32_combine64 crc32_combine64
#define crc32_z crc32_z
#define deflate deflate
#define deflateBound deflateBound
#define deflateCopy deflateCopy
#define deflateEnd deflateEnd
#define deflateGetDictionary deflateGetDictionary
/* #undef deflateInit */
/* #undef deflateInit2 */
#define deflateInit2_ deflateInit2_
#define deflateInit_ deflateInit_
#define deflateParams deflateParams
#define deflatePending deflatePending
#define deflatePrime deflatePrime
#define deflateReset deflateReset
#define deflateResetKeep deflateResetKeep
#define deflateSetDictionary deflateSetDictionary
#define deflateSetHeader deflateSetHeader
#define deflateTune deflateTune
#define deflate_copyright deflate_copyright
#define get_crc_table get_crc_table
#define gz_error gz_error
#define gz_intmax gz_intmax
#define gz_strwinerror gz_strwinerror
#define gzbuffer gzbuffer
#define gzclearerr gzclearerr
#define gzclose gzclose
#define gzclose_r gzclose_r
#define gzclose_w gzclose_w
#define gzdirect gzdirect
#define gzdopen gzdopen
#define gzeof gzeof
#define gzerror gzerror
#define gzflush gzflush
#define gzfread gzfread
#define gzfwrite gzfwrite
#define gzgetc gzgetc
#define gzgetc_ gzgetc_
#define gzgets gzgets
#define gzoffset gzoffset
#define gzoffset64 gzoffset64
#define gzopen gzopen
#define gzopen64 gzopen64
#define gzopen_w gzopen_w
#define gzprintf gzprintf
#define gzputc gzputc
#define gzputs gzputs
#define gzread gzread
#define gzrewind gzrewind
#define gzseek gzseek
#define gzseek64 gzseek64
#define gzsetparams gzsetparams
#define gztell gztell
#define gztell64 gztell64
#define gzungetc gzungetc
#define gzvprintf gzvprintf
#define gzwrite gzwrite
#define inflate inflate
#define inflateBack inflateBack
#define inflateBackEnd inflateBackEnd
/* #undef inflateBackInit */
#define inflateBackInit_ inflateBackInit_
#define inflateCodesUsed inflateCodesUsed
#define inflateCopy inflateCopy
#define inflateEnd inflateEnd
#define inflateGetDictionary inflateGetDictionary
#define inflateGetHeader inflateGetHeader
/* #undef inflateInit */
/* #undef inflateInit2 */
#define inflateInit2_ inflateInit2_
#define inflateInit_ inflateInit_
#define inflateMark inflateMark
#define inflatePrime inflatePrime
#define inflateReset inflateReset
#define inflateReset2 inflateReset2
#define inflateResetKeep inflateResetKeep
#define inflateSetDictionary inflateSetDictionary
#define inflateSync inflateSync
#define inflateSyncPoint inflateSyncPoint
#define inflateUndermine inflateUndermine
#define inflateValidate inflateValidate
#define inflate_copyright inflate_copyright
#define inflate_fast inflate_fast
#define inflate_table inflate_table
#define uncompress uncompress
#define uncompress2 uncompress2
#define zError zError
#define zcalloc zcalloc
#define zcfree zcfree
#define zlibCompileFlags zlibCompileFlags
#define zlibVersion zlibVersion
/* #undef Byte */
#define Bytef Bytef
#define alloc_func alloc_func
#define charf charf
#define free_func free_func
#define gzFile gzFile
#define gz_header gz_header
#define gz_headerp gz_headerp
#define in_func in_func
#define intf intf
#define out_func out_func
#define uInt uInt
#define uIntf uIntf
#define uLong uLong
#define uLongf uLongf
#define voidp voidp
#define voidpc voidpc
#define voidpf voidpf
#define gz_header_s gz_header_s
/* #undef internal_state */
/* #undef z_off64_t */

/* An exported symbol that isn't handled by Z_PREFIX in zconf.h */
#define z_errmsg z_errmsg

/* Symbols added in simd.patch */
#define copy_with_crc copy_with_crc
#define crc_finalize crc_finalize
#define crc_fold_512to32 crc_fold_512to32
#define crc_fold_copy crc_fold_copy
#define crc_fold_init crc_fold_init
#define crc_reset crc_reset
#define fill_window_sse fill_window_sse
#define deflate_read_buf deflate_read_buf
#define x86_check_features x86_check_features
#define x86_cpu_enable_simd x86_cpu_enable_simd

/* Symbols added by adler_simd.c */
#define adler32_simd_ adler32_simd_
#define x86_cpu_enable_ssse3 x86_cpu_enable_ssse3

/* Symbols added by contrib/optimizations/inffast_chunk */
#define inflate_fast_chunk_ inflate_fast_chunk_

/* Symbols added by crc32_simd.c */
#define crc32_sse42_simd_ crc32_sse42_simd_

/* Symbols added by armv8_crc32 */
#define arm_cpu_enable_crc32 arm_cpu_enable_crc32
#define arm_cpu_enable_pmull arm_cpu_enable_pmull
#define arm_check_features arm_check_features
#define armv8_crc32_little armv8_crc32_little

#endif /* THIRD_PARTY_ZLIB_CHROMECONF_H_ */
