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

/**
 * @brief Error flag
**/
typedef enum _Deque_Error_e
{
    Deque_Error_None = 0,
    Deque_Error      = 1,
} Deque_Error_e;

/*============================================================================*
 *                             S T R U C T U R E S                            *
 *============================================================================*/

/**
 * @brief  Deque Object
 *
 * @note   This object should never be directly manipulated by the caller.
**/
typedef struct _Deque_t
{
    size_t   front;    /*!< Front (read) buffer cursor */
    size_t   rear;     /*!< Rear (write) buffer cursor */
    uint8_t *pBuf;     /*!< Pointer to the deque buffer */
    size_t   bufSize;  /*!< Size of the deque buffer */
    size_t   dataSize; /*!< Size of the data type to be stored in the deque */
} Deque_t;

#endif /* DEQUE_T_H_INCLUDED */