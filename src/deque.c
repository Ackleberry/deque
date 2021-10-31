/*******************************************************************************
 * @file  deque.c
 *
 * @brief Deque implementation
 *
 * @author Brooks Anderson <bilbrobaggins@gmail.com>
 ******************************************************************************/

/*============================================================================*
 *                              I N C L U D E S                               *
 *============================================================================*/
#include "deque.h"

/*============================================================================*
 *                      P U B L I C    F U N C T I O N S                      *
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
void Deque_Init(Deque_t *pObj, void *pBuf, size_t bufSize, size_t dataSize)
{
    pObj->bufSize = bufSize;
    pObj->front = SIZE_MAX;
    pObj->rear = 0;
    pObj->pBuf = pBuf;
    pObj->dataSize = dataSize;
}

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
bool Deque_IsEmpty(Deque_t *pObj)
{
    return (pObj->front == SIZE_MAX);
}

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
bool Deque_IsFull(Deque_t *pObj)
{
    return (pObj->rear == pObj->front);
}

/*******************************************************************************
 * @brief  Pushes data onto the front of the deque
 *
 * @param pObj     Pointer to the deque object
 * @param pDataIn  Pointer to the data that will be pushed
 *
 * @returns Deque error flag
 ******************************************************************************/
Deque_Error_e Deque_PushFront(Deque_t *pObj, void *pDataIn)
{
    Deque_Error_e err = Deque_Error_None;
    uint8_t *pData = (uint8_t *)pDataIn;

    /* Push the data into the deque one byte at a time */
    size_t idx = pObj->dataSize;
    while (idx > 0)
    {
        if (Deque_IsFull(pObj))
        {
            err = Deque_Error;
            break;
        }

        if (Deque_IsEmpty(pObj))
        {
            pObj->front = pObj->rear;
        }

        /* Decrement cursor around buffer */
        pObj->front--;
        if (pObj->front == SIZE_MAX)
        {
            pObj->front = pObj->bufSize - 1;
        }

        idx--;
        pObj->pBuf[pObj->front] = pData[idx];
    }

    return err;
}

/*******************************************************************************
 * @brief  Pushes data onto the back of the deque
 *
 * @param pObj     Pointer to the deque object
 * @param pDataIn  Pointer to the data that will be pushed
 *
 * @returns Deque error flag
 ******************************************************************************/
Deque_Error_e Deque_PushBack(Deque_t *pObj, void *pDataIn)
{
    Deque_Error_e err = Deque_Error_None;
    uint8_t *pData = (uint8_t *)pDataIn;

    /* Push the data into the deque one byte at a time */
    for (size_t idx = 0; idx < pObj->dataSize; idx++)
    {
        if (Deque_IsFull(pObj))
        {
            err = Deque_Error;
            break;
        }

        if (Deque_IsEmpty(pObj))
        {
            pObj->front = pObj->rear;
        }

        pObj->pBuf[pObj->rear] = pData[idx];

        /* Increment cursor around buffer */
        pObj->rear++;
        if (pObj->rear >= pObj->bufSize)
        {
            pObj->rear = 0;
        }
    }

    return err;
}

/*******************************************************************************
 * @brief  Pops data member off the front of the deque
 *
 * @param pObj      Pointer to the deque object
 * @param pDataOut  Pointer to the data that will be popped
 *
 * @returns Deque error flag
 ******************************************************************************/
Deque_Error_e Deque_PopFront(Deque_t *pObj, void *pDataOut)
{
    Deque_Error_e err = Deque_Error_None;
    uint8_t *pData = (uint8_t *)pDataOut;

    /* Pop the data off the deque one byte at a time */
    for (size_t idx = 0; idx < pObj->dataSize; idx++)
    {
        if (Deque_IsEmpty(pObj))
        {
            err = Deque_Error;
            break;
        }

        pData[idx] = pObj->pBuf[pObj->front];

        /* Increment cursor around buffer */
        pObj->front++;
        if (pObj->front >= pObj->bufSize)
        {
            pObj->front = 0;
        }

        if (Deque_IsFull(pObj))
        {
            pObj->front = SIZE_MAX;
        }
    }

    return err;
}

/*******************************************************************************
 * @brief  Pops data member off the rear of the deque
 *
 * @details This function is most similar to a Stack_Pop()
 *
 * @param pObj      Pointer to the deque object
 * @param pDataOut  Pointer to the data that will be popped
 *
 * @returns Deque error flag
 ******************************************************************************/
Deque_Error_e Deque_PopBack(Deque_t *pObj, void *pDataOut)
{
    Deque_Error_e err = Deque_Error_None;
    uint8_t *pData = (uint8_t *)pDataOut;

    /* Pop the data off the deque one byte at a time */
    size_t idx = pObj->dataSize;
    while (idx > 0)
    {
        if (Deque_IsEmpty(pObj))
        {
            err = Deque_Error;
            break;
        }

        /* Decrement cursor around buffer */
        pObj->rear--;
        if (pObj->rear == SIZE_MAX)
        {
            pObj->rear = pObj->bufSize - 1;
        }

        idx--;
        pData[idx] = pObj->pBuf[pObj->rear];

        if (Deque_IsFull(pObj))
        {
            pObj->front = SIZE_MAX;
        }
    }

    return err;
}

/*******************************************************************************
 * @brief  Peek at the data at the front of the deque
 *
 * @param  pObj      Pointer to the deque object
 * @param  pDataOut  Pointer to the peeked data
 *
 * @returns Deque error flag
 ******************************************************************************/
Deque_Error_e Deque_PeekFront(Deque_t *pObj, void *pDataOut)
{
    Deque_Error_e err = Deque_Error_None;
    size_t front = pObj->front;
    size_t rear = pObj->rear;

    err = Deque_PopFront(pObj, pDataOut);

    pObj->front = front;
    pObj->rear = rear;
    return err;
}

/*******************************************************************************
 * @brief  Peek at the data at the back of the deque
 *
 * @param  pObj      Pointer to the deque object
 * @param  pDataOut  Pointer to the peeked data
 *
 * @returns Deque error flag
 ******************************************************************************/
Deque_Error_e Deque_PeekBack(Deque_t *pObj, void *pDataOut)
{
    Deque_Error_e err = Deque_Error_None;
    size_t front = pObj->front;
    size_t rear = pObj->rear;

    err = Deque_PopBack(pObj, pDataOut);

    pObj->front = front;
    pObj->rear = rear;
    return err;
}