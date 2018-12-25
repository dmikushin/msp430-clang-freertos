/*
 * FreeRTOS Kernel V10.1.1
 * Copyright (C) 2018 Amazon.com, Inc. or its affiliates.  All Rights Reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * http://www.FreeRTOS.org
 * http://aws.amazon.com/freertos
 *
 * 1 tab == 4 spaces!
 */

#if defined(__LARGE_DATA_MODEL__)

#define pushm_x pushm.a
#define popm_x popm.a
#define push_x push.a
#define pop_x pop.a
#define mov_x mov.a
#define cmp_x cmp.a
#define inc_x incx.w

#else

#define pushm_x pushm.w
#define popm_x popm.w
#define push_x push.w
#define pop_x pop.w
#define mov_x mov.w
#define cmp_x cmp.w
#define inc_x inc.w

#endif /* __LARGE_DATA_MODEL__ */

#if defined(__LARGE_CODE_MODEL__)

#define call_x calla
#define ret_x reta

#else

#define call_x call
#define ret_x ret

#endif /* __LARGE_CODE_MODEL__ */

