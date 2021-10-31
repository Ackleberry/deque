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

void Deque_Init(Deque_t *pObj, void *pBuf, size_t bufSize, size_t dataSize)
{
    pObj->bufSize = bufSize;
    pObj->front = SIZE_MAX;
    pObj->rear = 0;
    pObj->pBuf = pBuf;
    pObj->dataSize = dataSize;
}

bool Deque_IsEmpty(Deque_t *pObj)
{
    return (pObj->front == SIZE_MAX);
}

bool Deque_IsFull(Deque_t *pObj)
{
    return (pObj->rear == pObj->front);
}

Deque_Error_e Deque_PushFront(Deque_t *pObj, void *pDataInVoid)
{
    Deque_Error_e err = Deque_Error_None;
    uint8_t *pDataIn = (uint8_t *)pDataInVoid;

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
        pObj->pBuf[pObj->front] = pDataIn[idx];
    }

    return err;
}

Deque_Error_e Deque_PushBack(Deque_t *pObj, void *pDataInVoid)
{
    Deque_Error_e err = Deque_Error_None;
    uint8_t *pDataIn = (uint8_t *)pDataInVoid;

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

        pObj->pBuf[pObj->rear] = pDataIn[idx];

        /* Increment cursor around buffer */
        pObj->rear++;
        if (pObj->rear >= pObj->bufSize)
        {
            pObj->rear = 0;
        }
    }

    return err;
}

Deque_Error_e Deque_PopFront(Deque_t *pObj, void *pDataOutVoid)
{
    Deque_Error_e err = Deque_Error_None;
    uint8_t *pDataOut = (uint8_t *)pDataOutVoid;

    /* Pop the data off the deque one byte at a time */
    for (size_t idx = 0; idx < pObj->dataSize; idx++)
    {
        if (Deque_IsEmpty(pObj))
        {
            err = Deque_Error;
            break;
        }

        pDataOut[idx] = pObj->pBuf[pObj->front];

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

Deque_Error_e Deque_PopBack(Deque_t *pObj, void *pDataOutVoid)
{
    Deque_Error_e err = Deque_Error_None;
    uint8_t *pDataOut = (uint8_t *)pDataOutVoid;

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
        pDataOut[idx] = pObj->pBuf[pObj->rear];

        if (Deque_IsFull(pObj))
        {
            pObj->front = SIZE_MAX;
        }
    }

    return err;
}

Deque_Error_e Deque_PeekFront(Deque_t *pObj, void *pDataOutVoid)
{
    Deque_Error_e err = Deque_Error_None;
    size_t front = pObj->front;
    size_t rear = pObj->rear;

    err = Deque_PopFront(pObj, pDataOutVoid);

    pObj->front = front;
    pObj->rear = rear;
    return err;
}

Deque_Error_e Deque_PeekBack(Deque_t *pObj, void *pDataOutVoid)
{
    Deque_Error_e err = Deque_Error_None;
    size_t front = pObj->front;
    size_t rear = pObj->rear;

    err = Deque_PopBack(pObj, pDataOutVoid);

    pObj->front = front;
    pObj->rear = rear;
    return err;
}