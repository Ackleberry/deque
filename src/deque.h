/*******************************************************************************
 * @file  deque.h
 *
 * @brief Deque public function declarations
 *
 * @author Brooks Anderson <bilbrobaggins@gmail.com>
 ******************************************************************************/

#ifndef DEQUE_H_INCLUDED
#define DEQUE_H_INCLUDED

/*============================================================================*
 *                              I N C L U D E S                               *
 *============================================================================*/
#include <stddef.h>
#include <stdbool.h>

#include "deque_t.h"

/*============================================================================*
 *                 F U N C T I O N    D E C L A R A T I O N S                 *
 *============================================================================*/

void Deque_Init(Deque_t *pObj, void *pBuf, size_t bufSize, size_t dataSize);

bool Deque_IsEmpty(Deque_t *pObj);

bool Deque_IsFull(Deque_t *pObj);

Deque_Error_e Deque_PushFront(Deque_t *pObj, void *pDataIn);

Deque_Error_e Deque_PushBack(Deque_t *pObj, void *pDataIn);

Deque_Error_e Deque_PopFront(Deque_t *pObj, void *pDataOut);

Deque_Error_e Deque_PopBack(Deque_t *pObj, void *pDataOut);

Deque_Error_e Deque_PeekFront(Deque_t *pObj, void *pDataOut);

Deque_Error_e Deque_PeekBack(Deque_t *pObj, void *pDataOut);


#endif /* DEQUE_H_INCLUDED */