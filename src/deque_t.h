/*******************************************************************************
 * @file  deque_t.h
 *
 * @brief Deque public function declarations
 *
 * @author Brooks Anderson <bilbrobaggins@gmail.com>
 ******************************************************************************/
#ifndef DEQUE_T_H_INCLUDED
#define DEQUE_T_H_INCLUDED

/*============================================================================*
 *                              I N C L U D E S                               *
 *============================================================================*/
#include <stddef.h>
#include <stdint.h>

/*============================================================================*
 *                                D E F I N E S                               *
 *============================================================================*/

/*============================================================================*
 *                           E N U M E R A T I O N S                          *
 *============================================================================*/

typedef enum _Deque_Error_e
{
    Deque_Error_None = 0,
    Deque_Error      = 1,
} Deque_Error_e;

/*============================================================================*
 *                             S T R U C T U R E S                            *
 *============================================================================*/

typedef struct _Deque_t
{
    size_t   front;    /*!< Buffer index to the front of the deque */
    size_t   rear;     /*!< Buffer index to the rear of the deque */
    uint8_t *pBuf;     /*!< Pointer to the deque buffer */
    size_t   bufSize;  /*!< Size of the deque buffer */
    size_t   dataSize; /*!< Size of the data type to be stored in the deque */
} Deque_t;

#endif /* DEQUE_T_H_INCLUDED */