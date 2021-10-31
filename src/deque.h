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

/*******************************************************************************
 * @brief  Initializes the deque object
 *
 * @details  The caller is responsible for allocating the deque object, and
 *           deque buffer.
 *
 * @param pObj      Pointer to the deque object
 * @param pBuf      Pointer to the deque buffer
 * @param bufSize   Size of the buffer
 * @param dataSize  Size of the data type that the deque is handling
 *
 * @return none
 ******************************************************************************/
void Deque_Init(Deque_t *pObj, void *pBuf, size_t bufSize, size_t dataSize);

/*******************************************************************************
 * @brief  Check if the deque is empty
 *
 * @details  Deque top is considered empty when set to largest `size_t` value,
 *           SIZE_MAX. The first added element "rolls" the top over from
 *           SIZE_MAX to 0.
 *
 * @param pObj  Pointer to the deque object
 *
 * @returns true if empty
 ******************************************************************************/
bool Deque_IsEmpty(Deque_t *pObj);

/*******************************************************************************
 * @brief Check if the deque is full
 *
 * @details  Deque top is considered full when set to one less than the buffer
 *           size.
 *
 * @param pObj  Pointer to the deque object
 *
 * @returns true if full
 ******************************************************************************/
bool Deque_IsFull(Deque_t *pObj);

/*******************************************************************************
 * @brief  Pushes data onto the front of the deque
 *
 * @param pObj     Pointer to the deque object
 * @param pDataIn  Pointer to the data that will be pushed
 *
 * @returns Deque error flag
 ******************************************************************************/
Deque_Error_e Deque_PushFront(Deque_t *pObj, void *pDataIn);

/*******************************************************************************
 * @brief  Pushes data onto the back of the deque
 *
 * @details This function is equivalent to a Queue_Push(), Stack_Push()
 *
 * @param pObj     Pointer to the deque object
 * @param pDataIn  Pointer to the data that will be pushed
 *
 * @returns Deque error flag
 ******************************************************************************/
Deque_Error_e Deque_PushBack(Deque_t *pObj, void *pDataIn);

/*******************************************************************************
 * @brief  Pops data member off the front of the deque
 *
 * @details This function is equivalent to a Queue_Pop()
 *
 * @param pObj      Pointer to the deque object
 * @param pDataOut  Pointer to the data that will be popped
 *
 * @returns Deque error flag
 ******************************************************************************/
Deque_Error_e Deque_PopFront(Deque_t *pObj, void *pDataOut);

/*******************************************************************************
 * @brief  Pops data member off the rear of the deque
 *
 * @details This function is equivalent to a Stack_Pop()
 *
 * @param pObj      Pointer to the deque object
 * @param pDataOut  Pointer to the data that will be popped
 *
 * @returns Deque error flag
 ******************************************************************************/
Deque_Error_e Deque_PopBack(Deque_t *pObj, void *pDataOut);

/*******************************************************************************
 * @brief  Peek at the data at the front of the deque
 *
 * @param  pObj      Pointer to the deque object
 * @param  pDataOut  Pointer to the peeked data
 *
 * @returns Deque error flag
 ******************************************************************************/
Deque_Error_e Deque_PeekFront(Deque_t *pObj, void *pDataOut);

/*******************************************************************************
 * @brief  Peek at the data at the back of the deque
 *
 * @param  pObj      Pointer to the deque object
 * @param  pDataOut  Pointer to the peeked data
 *
 * @returns Deque error flag
 ******************************************************************************/
Deque_Error_e Deque_PeekBack(Deque_t *pObj, void *pDataOut);


#endif /* DEQUE_H_INCLUDED */