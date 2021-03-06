/*
 * FILE NAME: util.h - a random assortment of useful functions
 *
 * Copyright (c) 2014 Robert K. Parker
 *
 * This file was part of the TinyG project
 *
 * Copyright (c) 2010 - 2013 Alden S. Hart, Jr.
 *
 * Now it is in crystalfontz3D
 *
 * This file ("the software") is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License, version 2 as published by the
 * Free Software Foundation. You should have received a copy of the GNU General Public
 * License, version 2 along with the software.  If not, see <http://www.gnu.org/licenses/>.
 *
 * As a special exception, you may use this file as part of a software library without
 * restriction. Specifically, if other files instantiate templates or use macros or
 * inline functions from this file, or you compile this file and link it with  other
 * files to produce an executable, this file does not by itself cause the resulting
 * executable to be covered by the GNU General Public License. This exception does not
 * however invalidate any other reasons why the executable file might be covered by the
 * GNU General Public License.
 *
 * THE SOFTWARE IS DISTRIBUTED IN THE HOPE THAT IT WILL BE USEFUL, BUT WITHOUT ANY
 * WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT
 * SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF
 * OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */
/*
 * PURPOSE: Assorted supporting functions.
 *
 * NOTES:
 * util.c/.h contains an assortment of supporting functions that are not specific to 
 *	this program: including:
 *
 *	  - math and min/max utilities and extensions
 *	  - vector manipulation utilities
 *	  - support for debugging routines
 *
 *
 * CHANGE HISTORY:
 *
 *    Revision: Initial 1.0
 *    User: R.K.Parker     Date: 05/29/14
 *    First prototype.
 *
 */
 

#ifndef UTIL_H_ONCE
#define UTIL_H_ONCE

#ifdef __cplusplus
extern "C"{
#endif

/****** Global Scope Variables and Functions ******/

//*** vector utilities ***

extern float vector[AXES]; // vector of axes for passing to subroutines

#define clear_vector(a) memset(a,0,sizeof(a))
float get_axis_vector_length(const float a[], const float b[]);
uint8_t vector_equal(const float a[], const float b[]);
float *set_vector(float x, float y, float z, float a, float b, float c);
float *set_vector_by_axis(float value, uint8_t axis);
//void copy_vector(float dst[], const float src[], uint8_t length);

void copy_axis_vector(float dst[], const float src[]);
/*
#define copy_axis_vector(dst,src) ( dst[AXIS_X] = src[AXIS_X];\
									dst[AXIS_Y] = src[AXIS_Y];\
									dst[AXIS_Z] = src[AXIS_Z];\
									dst[AXIS_A] = src[AXIS_A];\
									dst[AXIS_B] = src[AXIS_B];\
									dst[AXIS_C] = src[AXIS_C]; )
*/

//*** math utilities ***

float min3(float x1, float x2, float x3);
float min4(float x1, float x2, float x3, float x4);
float max3(float x1, float x2, float x3);
float max4(float x1, float x2, float x3, float x4);
//float std_dev(float a[], uint8_t n, float *mean);

//*** string utilities ***

//#ifdef __ARM
//uint8_t * strcpy_U( uint8_t * dst, const uint8_t * src );
//#endif

uint8_t isnumber(char c);
char *escape_string(char *dst, char *src);
uint16_t compute_checksum(char const *string, const uint16_t length);

//*** other utilities ***
int fLineCount(FILE *file);
unsigned long compressFile(FILE *ifile, FILE *ofile);

#ifdef __ARM
uint32_t SysTickTimer_getValue(void);
#endif

//**** Math Support *****

#ifndef square
#define square(x) ((x)*(x))		/* UNSAFE */
#endif

// side-effect safe forms of min and max
#ifndef max
#define max(a,b) \
   ({ __typeof__ (a) termA = (a); \
      __typeof__ (b) termB = (b); \
	  termA>termB ? termA:termB; })
#endif

#ifndef min
#define min(a,b) \
	({ __typeof__ (a) term1 = (a); \
	   __typeof__ (b) term2 = (b); \
	   term1<term2 ? term1:term2; })
#endif

#ifndef avg
#define avg(a,b) ((a+b)/2)
#endif

#ifndef EPSILON
#define EPSILON		((float)0.00001)		// allowable rounding error for floats
//#define EPSILON 	((float)0.000001)		// allowable rounding error for floats
#endif

#ifndef fp_EQ
#define fp_EQ(a,b) (fabs(a-b) < EPSILON)	// requires math.h to be included in each file used
#endif
#ifndef fp_NE
#define fp_NE(a,b) (fabs(a-b) > EPSILON)	// requires math.h to be included in each file used
#endif
#ifndef fp_ZERO
#define fp_ZERO(a) (fabs(a) < EPSILON)		// requires math.h to be included in each file used
#endif
#ifndef fp_NOT_ZERO
#define fp_NOT_ZERO(a) (fabs(a) > EPSILON)	// requires math.h to be included in each file used
#endif
#ifndef fp_FALSE
#define fp_FALSE(a) (a < EPSILON)			// float is interpreted as FALSE (equals zero)
#endif
#ifndef fp_TRUE
#define fp_TRUE(a) (a > EPSILON)			// float is interpreted as TRUE (not equal to zero)
#endif

// Constants
#define MAX_LONG (2147483647)
#define MAX_ULONG (4294967295)
#define MM_PER_INCH (25.4)
#define INCH_PER_MM (1/25.4)
#define MICROSECONDS_PER_MINUTE ((float)60000000)
#define uSec(a) ((float)(a * MICROSECONDS_PER_MINUTE))

#define RADIAN (57.2957795)
//		M_PI is pi as defined in math.h
//		M_SQRT2 is radical2 as defined in math.h
#ifndef M_SQRT3
#define M_SQRT3 (1.73205080756888)
#endif

#ifdef __cplusplus
}
#endif

#endif	// End of include guard: UTIL_H_ONCE
