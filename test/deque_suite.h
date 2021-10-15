#ifndef DEQUE_SUITE_INCLUDED
#define DEQUE_SUITE_INCLUDED

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "greatest.h"
#include "deque_test_helper.h"
#include "deque.h"

/* Declare a local suite. */
SUITE(Deque_Suite);

TEST Deque_can_report_empty(void)
{
    /*****************    Arrange    *****************/
    Deque_t q;
    uint8_t buf[2];
    Deque_Init(&q, buf, sizeof(buf), sizeof(buf[0]));

    /*****************     Act       *****************/
    bool isEmpty = Deque_IsEmpty(&q);

    /*****************    Assert     *****************/
    ASSERT_EQ(true, isEmpty);

    PASS();
}

TEST Deque_can_report_not_full(void)
{
    /*****************    Arrange    *****************/
    Deque_t q;
    uint8_t buf[2];
    Deque_Init(&q, buf, sizeof(buf), sizeof(buf[0]));

    /*****************     Act       *****************/
    bool isFull = Deque_IsFull(&q);

    /*****************    Assert     *****************/
    ASSERT_EQ(false, isFull);

    PASS();
}

TEST Deque_can_report_not_empty_when_pushed_from_back(void)
{
    /*****************    Arrange    *****************/
    Deque_t q;
    uint8_t buf[2];
    uint8_t dataIn = 5;
    Deque_Init(&q, buf, sizeof(buf), sizeof(buf[0]));
    Deque_PushBack(&q, &dataIn);

    /*****************     Act       *****************/
    bool isEmpty = Deque_IsEmpty(&q);

    /*****************    Assert     *****************/
    ASSERT_EQ(false, isEmpty);

    PASS();
}

TEST Deque_can_report_not_empty_when_pushed_from_front(void)
{
    /*****************    Arrange    *****************/
    Deque_t q;
    uint8_t buf[2];
    uint8_t dataIn = 5;
    Deque_Init(&q, buf, sizeof(buf), sizeof(buf[0]));
    Deque_PushFront(&q, &dataIn);

    /*****************     Act       *****************/
    bool isEmpty = Deque_IsEmpty(&q);

    /*****************    Assert     *****************/
    ASSERT_EQ(false, isEmpty);

    PASS();
}

TEST Deque_can_report_full_when_pushed_from_back(void)
{
    /*****************    Arrange    *****************/
    Deque_t q;
    uint8_t buf[2];
    uint8_t dataIn = 5;
    Deque_Init(&q, buf, sizeof(buf), sizeof(buf[0]));
    Deque_PushBack(&q, &dataIn);
    Deque_PushBack(&q, &dataIn);

    /*****************     Act       *****************/
    bool isFull = Deque_IsFull(&q);

    /*****************    Assert     *****************/
    ASSERT_EQ(true, isFull);

    PASS();
}

TEST Deque_can_report_full_when_pushed_from_front(void)
{
    /*****************    Arrange    *****************/
    Deque_t q;
    uint8_t buf[2];
    uint8_t dataIn = 5;
    Deque_Init(&q, buf, sizeof(buf), sizeof(buf[0]));
    Deque_PushFront(&q, &dataIn);
    Deque_PushFront(&q, &dataIn);

    /*****************     Act       *****************/
    bool isFull = Deque_IsFull(&q);

    /*****************    Assert     *****************/
    ASSERT_EQ(true, isFull);

    PASS();
}

TEST Deque_front_pop_fails_if_underflow(void)
{
    /*****************    Arrange    *****************/
    Deque_t q;
    uint8_t buf[2];
    Deque_Init(&q, buf, sizeof(buf), sizeof(buf[0]));
    uint8_t dataOut;

    /*****************     Act       *****************/
    Deque_Error_e err = Deque_PopFront(&q, &dataOut);

    /*****************    Assert     *****************/
    ASSERT_EQ(Deque_Error, err);

    PASS();
}

TEST Deque_back_pop_fails_if_underflow(void)
{
    /*****************    Arrange    *****************/
    Deque_t q;
    uint8_t buf[2];
    Deque_Init(&q, buf, sizeof(buf), sizeof(buf[0]));
    uint8_t dataOut;

    /*****************     Act       *****************/
    Deque_Error_e err = Deque_PopBack(&q, &dataOut);

    /*****************    Assert     *****************/
    ASSERT_EQ(Deque_Error, err);

    PASS();
}

TEST Deque_back_push_fails_due_to_overflow_when_pushed_from_back(void)
{
    /*****************    Arrange    *****************/
    Deque_t q;
    uint8_t buf[2];
    Deque_Init(&q, buf, sizeof(buf), sizeof(buf[0]));
    uint8_t dataIn = 5;

    /* Fill the deque up */
    Deque_PushBack(&q, &dataIn);
    Deque_PushBack(&q, &dataIn);

    /*****************     Act       *****************/
    Deque_Error_e err = Deque_PushBack(&q, &dataIn);

    /*****************    Assert     *****************/
    ASSERT_EQ(Deque_Error, err);

    PASS();
}

TEST Deque_back_push_fails_due_to_overflow_when_pushed_from_front(void)
{
    /*****************    Arrange    *****************/
    Deque_t q;
    uint8_t buf[2];
    Deque_Init(&q, buf, sizeof(buf), sizeof(buf[0]));
    uint8_t dataIn = 5;

    /* Fill the deque up */
    Deque_PushFront(&q, &dataIn);
    Deque_PushFront(&q, &dataIn);

    /*****************     Act       *****************/
    Deque_Error_e err = Deque_PushBack(&q, &dataIn);

    /*****************    Assert     *****************/
    ASSERT_EQ(Deque_Error, err);

    PASS();
}

TEST Deque_front_push_fails_due_to_overflow_when_pushed_from_back(void)
{
    /*****************    Arrange    *****************/
    Deque_t q;
    uint8_t buf[2];
    Deque_Init(&q, buf, sizeof(buf), sizeof(buf[0]));
    uint8_t dataIn = 5;

    /* Fill the deque up */
    Deque_PushBack(&q, &dataIn);
    Deque_PushBack(&q, &dataIn);

    /*****************     Act       *****************/
    Deque_Error_e err = Deque_PushFront(&q, &dataIn);

    /*****************    Assert     *****************/
    ASSERT_EQ(Deque_Error, err);

    PASS();
}

TEST Deque_front_push_fails_due_to_overflow_when_pushed_from_front(void)
{
    /*****************    Arrange    *****************/
    Deque_t q;
    uint8_t buf[2];
    Deque_Init(&q, buf, sizeof(buf), sizeof(buf[0]));
    uint8_t dataIn = 5;

    /* Fill the deque up */
    Deque_PushFront(&q, &dataIn);
    Deque_PushFront(&q, &dataIn);

    /*****************     Act       *****************/
    Deque_Error_e err = Deque_PushFront(&q, &dataIn);

    /*****************    Assert     *****************/
    ASSERT_EQ(Deque_Error, err);

    PASS();
}

TEST Deque_can_front_pop_1_byte_data_types_when_pushed_from_back(void)
{
    /*****************    Arrange    *****************/
    Deque_t q;
    uint8_t buf[4];
    Deque_Init(&q, buf, sizeof(buf), sizeof(buf[0]));
    uint8_t dataIn = 201;
    uint8_t dataOut;

    Deque_PushBack(&q, &dataIn);

    /*****************     Act       *****************/
    Deque_Error_e err = Deque_PopFront(&q, &dataOut);

    /*****************    Assert     *****************/
    ASSERT_EQ(Deque_Error_None, err);
    ASSERT_EQ(dataIn, dataOut);

    PASS();
}

TEST Deque_can_front_pop_2_byte_data_types_when_pushed_from_back(void)
{
    /*****************    Arrange    *****************/
    Deque_t q;
    uint16_t buf[4];
    Deque_Init(&q, buf, sizeof(buf), sizeof(buf[0]));
    uint16_t dataIn = 999;
    uint16_t dataOut;

    Deque_PushBack(&q, &dataIn);

    /*****************     Act       *****************/
    Deque_Error_e err = Deque_PopFront(&q, &dataOut);

    /*****************    Assert     *****************/
    ASSERT_EQ(Deque_Error_None, err);
    ASSERT_EQ(dataIn, dataOut);

    PASS();
}

TEST Deque_can_front_pop_8_byte_data_types_when_pushed_from_back(void)
{
    /*****************    Arrange    *****************/
    Deque_t q;
    uint64_t buf[4];
    Deque_Init(&q, buf, sizeof(buf), sizeof(buf[0]));
    uint64_t dataIn = 12345678;
    uint64_t dataOut;

    Deque_PushBack(&q, &dataIn);

    /*****************     Act       *****************/
    Deque_Error_e err = Deque_PopFront(&q, &dataOut);

    /*****************    Assert     *****************/
    ASSERT_EQ(Deque_Error_None, err);
    ASSERT_EQ(dataIn, dataOut);
    ASSERT_EQ(true, Deque_IsEmpty(&q));
    PASS();
}

TEST Deque_can_front_pop_struct_data_types_when_pushed_from_back()
{
    /*****************    Arrange    *****************/
    typedef struct _Deque_Struct_t
    {
        uint8_t a;
        uint16_t b;
        uint32_t c;
        uint8_t d;
        uint32_t e;
    } Deque_Struct_t;

    Deque_t q;
    Deque_Struct_t buf[2];
    Deque_Struct_t dataIn = { .a = 5, .b = 54, .c = 1000, .d = 254, .e = 9999 };
    Deque_Struct_t dataOut;
    Deque_Error_e err = (uint8_t)Deque_Error_None;

    Deque_Init(&q, buf, sizeof(buf), sizeof(buf[0]));
    Deque_PushBack(&q, &dataIn);

    /*****************     Act       *****************/
    err = Deque_PopFront(&q, &dataOut);

    /*****************    Assert     *****************/
    ASSERT_EQ(Deque_Error_None, err);
    ASSERT_MEM_EQ(&dataIn, &dataOut, sizeof(Deque_Struct_t));
    ASSERT_EQ(true, Deque_IsEmpty(&q));

    PASS();
}

TEST Deque_can_front_pop_1_byte_data_types_when_pushed_from_front(void)
{
    /*****************    Arrange    *****************/
    Deque_t q;
    uint8_t buf[4];
    Deque_Init(&q, buf, sizeof(buf), sizeof(buf[0]));
    uint8_t dataIn = 201;
    uint8_t dataOut;

    Deque_PushFront(&q, &dataIn);

    /*****************     Act       *****************/
    Deque_Error_e err = Deque_PopFront(&q, &dataOut);

    /*****************    Assert     *****************/
    ASSERT_EQ(Deque_Error_None, err);
    ASSERT_EQ(dataIn, dataOut);

    PASS();
}

TEST Deque_can_front_pop_2_byte_data_types_when_pushed_from_front(void)
{
    /*****************    Arrange    *****************/
    Deque_t q;
    uint16_t buf[4];
    Deque_Init(&q, buf, sizeof(buf), sizeof(buf[0]));
    uint16_t dataIn = 999;
    uint16_t dataOut;

    Deque_PushFront(&q, &dataIn);

    /*****************     Act       *****************/
    Deque_Error_e err = Deque_PopFront(&q, &dataOut);

    /*****************    Assert     *****************/
    ASSERT_EQ(Deque_Error_None, err);
    ASSERT_EQ(dataIn, dataOut);

    PASS();
}

TEST Deque_can_front_pop_8_byte_data_types_when_pushed_from_front(void)
{
    /*****************    Arrange    *****************/
    Deque_t q;
    uint64_t buf[4];
    Deque_Init(&q, buf, sizeof(buf), sizeof(buf[0]));
    uint64_t dataIn = 12345678;
    uint64_t dataOut;

    Deque_PushFront(&q, &dataIn);

    /*****************     Act       *****************/
    Deque_Error_e err = Deque_PopFront(&q, &dataOut);

    /*****************    Assert     *****************/
    ASSERT_EQ(Deque_Error_None, err);
    ASSERT_EQ(dataIn, dataOut);
    ASSERT_EQ(true, Deque_IsEmpty(&q));
    PASS();
}

TEST Deque_can_front_pop_struct_data_types_when_pushed_from_front()
{
    /*****************    Arrange    *****************/
    typedef struct _Deque_Struct_t
    {
        uint8_t a;
        uint16_t b;
        uint32_t c;
        uint8_t d;
        uint32_t e;
    } Deque_Struct_t;

    Deque_t q;
    Deque_Struct_t buf[2];
    Deque_Struct_t dataIn = { .a = 5, .b = 54, .c = 1000, .d = 254, .e = 9999 };
    Deque_Struct_t dataOut;
    Deque_Error_e err = (uint8_t)Deque_Error_None;

    Deque_Init(&q, buf, sizeof(buf), sizeof(buf[0]));
    Deque_PushFront(&q, &dataIn);

    /*****************     Act       *****************/
    err = Deque_PopFront(&q, &dataOut);

    /*****************    Assert     *****************/
    ASSERT_EQ(Deque_Error_None, err);
    ASSERT_MEM_EQ(&dataIn, &dataOut, sizeof(Deque_Struct_t));
    ASSERT_EQ(true, Deque_IsEmpty(&q));

    PASS();
}

TEST Deque_can_back_pop_1_byte_data_types_when_pushed_from_back(void)
{
    /*****************    Arrange    *****************/
    Deque_t q;
    uint8_t buf[4];
    Deque_Init(&q, buf, sizeof(buf), sizeof(buf[0]));
    uint8_t dataIn = 201;
    uint8_t dataOut;

    Deque_PushBack(&q, &dataIn);

    /*****************     Act       *****************/
    Deque_Error_e err = Deque_PopBack(&q, &dataOut);

    /*****************    Assert     *****************/
    ASSERT_EQ(Deque_Error_None, err);
    ASSERT_EQ(dataIn, dataOut);

    PASS();
}

TEST Deque_can_back_pop_2_byte_data_types_when_pushed_from_back(void)
{
    /*****************    Arrange    *****************/
    Deque_t q;
    uint16_t buf[4];
    Deque_Init(&q, buf, sizeof(buf), sizeof(buf[0]));
    uint16_t dataIn = 999;
    uint16_t dataOut;

    Deque_PushBack(&q, &dataIn);

    /*****************     Act       *****************/
    Deque_Error_e err = Deque_PopBack(&q, &dataOut);

    /*****************    Assert     *****************/
    ASSERT_EQ(Deque_Error_None, err);
    ASSERT_EQ(dataIn, dataOut);

    PASS();
}

TEST Deque_can_back_pop_8_byte_data_types_when_pushed_from_back(void)
{
    /*****************    Arrange    *****************/
    Deque_t q;
    uint64_t buf[4];
    Deque_Init(&q, buf, sizeof(buf), sizeof(buf[0]));
    uint64_t dataIn = 12345678;
    uint64_t dataOut;

    Deque_PushBack(&q, &dataIn);

    /*****************     Act       *****************/
    Deque_Error_e err = Deque_PopBack(&q, &dataOut);

    /*****************    Assert     *****************/
    ASSERT_EQ(Deque_Error_None, err);
    ASSERT_EQ(dataIn, dataOut);
    ASSERT_EQ(true, Deque_IsEmpty(&q));
    PASS();
}

TEST Deque_can_back_pop_struct_data_types_when_pushed_from_back()
{
    /*****************    Arrange    *****************/
    typedef struct _Deque_Struct_t
    {
        uint8_t a;
        uint16_t b;
        uint32_t c;
        uint8_t d;
        uint32_t e;
    } Deque_Struct_t;

    Deque_t q;
    Deque_Struct_t buf[2];
    Deque_Struct_t dataIn = { .a = 5, .b = 54, .c = 1000, .d = 254, .e = 9999 };
    Deque_Struct_t dataOut;
    Deque_Error_e err = (uint8_t)Deque_Error_None;

    Deque_Init(&q, buf, sizeof(buf), sizeof(buf[0]));
    Deque_PushBack(&q, &dataIn);

    /*****************     Act       *****************/
    err = Deque_PopBack(&q, &dataOut);

    /*****************    Assert     *****************/
    ASSERT_EQ(Deque_Error_None, err);
    ASSERT_MEM_EQ(&dataIn, &dataOut, sizeof(Deque_Struct_t));
    ASSERT_EQ(true, Deque_IsEmpty(&q));

    PASS();
}

TEST Deque_can_back_pop_1_byte_data_types_when_pushed_from_front(void)
{
    /*****************    Arrange    *****************/
    Deque_t q;
    uint8_t buf[4];
    Deque_Init(&q, buf, sizeof(buf), sizeof(buf[0]));
    uint8_t dataIn = 201;
    uint8_t dataOut;

    Deque_PushFront(&q, &dataIn);

    /*****************     Act       *****************/
    Deque_Error_e err = Deque_PopBack(&q, &dataOut);

    /*****************    Assert     *****************/
    ASSERT_EQ(Deque_Error_None, err);
    ASSERT_EQ(dataIn, dataOut);

    PASS();
}

TEST Deque_can_back_pop_2_byte_data_types_when_pushed_from_front(void)
{
    /*****************    Arrange    *****************/
    Deque_t q;
    uint16_t buf[4];
    Deque_Init(&q, buf, sizeof(buf), sizeof(buf[0]));
    uint16_t dataIn = 999;
    uint16_t dataOut;

    Deque_PushFront(&q, &dataIn);

    /*****************     Act       *****************/
    Deque_Error_e err = Deque_PopBack(&q, &dataOut);

    /*****************    Assert     *****************/
    ASSERT_EQ(Deque_Error_None, err);
    ASSERT_EQ(dataIn, dataOut);

    PASS();
}

TEST Deque_can_back_pop_8_byte_data_types_when_pushed_from_front(void)
{
    /*****************    Arrange    *****************/
    Deque_t q;
    uint64_t buf[4];
    Deque_Init(&q, buf, sizeof(buf), sizeof(buf[0]));
    uint64_t dataIn = 12345678;
    uint64_t dataOut;

    Deque_PushFront(&q, &dataIn);

    /*****************     Act       *****************/
    Deque_Error_e err = Deque_PopBack(&q, &dataOut);

    /*****************    Assert     *****************/
    ASSERT_EQ(Deque_Error_None, err);
    ASSERT_EQ(dataIn, dataOut);
    ASSERT_EQ(true, Deque_IsEmpty(&q));
    PASS();
}

TEST Deque_can_back_pop_struct_data_types_when_pushed_from_front()
{
    /*****************    Arrange    *****************/
    typedef struct _Deque_Struct_t
    {
        uint8_t a;
        uint16_t b;
        uint32_t c;
        uint8_t d;
        uint32_t e;
    } Deque_Struct_t;

    Deque_t q;
    Deque_Struct_t buf[2];
    Deque_Struct_t dataIn = { .a = 5, .b = 54, .c = 1000, .d = 254, .e = 9999 };
    Deque_Struct_t dataOut;
    Deque_Error_e err = (uint8_t)Deque_Error_None;

    Deque_Init(&q, buf, sizeof(buf), sizeof(buf[0]));
    Deque_PushFront(&q, &dataIn);

    /*****************     Act       *****************/
    err = Deque_PopBack(&q, &dataOut);

    /*****************    Assert     *****************/
    ASSERT_EQ(Deque_Error_None, err);
    ASSERT_MEM_EQ(&dataIn, &dataOut, sizeof(Deque_Struct_t));
    ASSERT_EQ(true, Deque_IsEmpty(&q));

    PASS();
}

TEST Deque_can_peek_at_next_element_to_be_front_popped_when_pushed_from_back(void)
{
    /*****************    Arrange    *****************/
    Deque_t q;
    uint16_t buf[4];
    Deque_Init(&q, buf, sizeof(buf), sizeof(buf[0]));
    uint16_t dataIn[] = { 999, 244, 1500, 1 };
    uint16_t peekData;
    uint16_t poppedData;

    Deque_PushBack(&q, &dataIn[0]);
    Deque_PushBack(&q, &dataIn[1]);

    /*****************     Act       *****************/
    Deque_Error_e err = Deque_PeekFront(&q, &peekData);

    /*****************    Assert     *****************/
    ASSERT_EQ(Deque_Error_None, err);
    ASSERT_EQ(dataIn[0], peekData);
    Deque_PopFront(&q, &poppedData);
    ASSERT_EQ(peekData, poppedData);

    PASS();
}

TEST Deque_can_peek_at_next_element_to_be_front_popped_when_pushed_from_front(void)
{
    /*****************    Arrange    *****************/
    Deque_t q;
    uint16_t buf[4];
    Deque_Init(&q, buf, sizeof(buf), sizeof(buf[0]));
    uint16_t dataIn[] = { 999, 244, 1500, 1 };
    uint16_t peekData;
    uint16_t poppedData;

    Deque_PushFront(&q, &dataIn[0]);
    Deque_PushFront(&q, &dataIn[1]);

    /*****************     Act       *****************/
    Deque_Error_e err = Deque_PeekFront(&q, &peekData);

    /*****************    Assert     *****************/
    ASSERT_EQ(Deque_Error_None, err);
    ASSERT_EQ(dataIn[1], peekData);
    Deque_PopFront(&q, &poppedData);
    ASSERT_EQ(peekData, poppedData);

    PASS();
}

TEST Deque_can_peek_at_next_element_to_be_back_popped_when_pushed_from_back(void)
{
    /*****************    Arrange    *****************/
    Deque_t q;
    uint16_t buf[4];
    Deque_Init(&q, buf, sizeof(buf), sizeof(buf[0]));
    uint16_t dataIn[] = { 999, 244, 1500, 1 };
    uint16_t peekData;
    uint16_t poppedData;

    Deque_PushBack(&q, &dataIn[0]);
    Deque_PushBack(&q, &dataIn[1]);

    /*****************     Act       *****************/
    Deque_Error_e err = Deque_PeekBack(&q, &peekData);

    /*****************    Assert     *****************/
    ASSERT_EQ(Deque_Error_None, err);
    ASSERT_EQ(dataIn[1], peekData);
    Deque_PopBack(&q, &poppedData);
    ASSERT_EQ(peekData, poppedData);

    PASS();
}

TEST Deque_can_peek_at_next_element_to_be_back_popped_when_pushed_from_front(void)
{
    /*****************    Arrange    *****************/
    Deque_t q;
    uint16_t buf[4];
    Deque_Init(&q, buf, sizeof(buf), sizeof(buf[0]));
    uint16_t dataIn[] = { 999, 244, 1500, 1 };
    uint16_t peekData;
    uint16_t poppedData;

    Deque_PushFront(&q, &dataIn[0]);
    Deque_PushFront(&q, &dataIn[1]);

    /*****************     Act       *****************/
    Deque_Error_e err = Deque_PeekBack(&q, &peekData);

    /*****************    Assert     *****************/
    ASSERT_EQ(Deque_Error_None, err);
    ASSERT_EQ(dataIn[0], peekData);
    Deque_PopBack(&q, &poppedData);
    ASSERT_EQ(peekData, poppedData);

    PASS();
}

TEST Deque_can_empty_a_full_buffer_of_1_byte_data_types_by_push_back_and_pop_front(void)
{
    /*****************    Arrange    *****************/
    Deque_t q;
    int8_t buf[1000];
    int8_t dataIn[1000] =
    {
        [  0] = INT8_MIN,
        [101] = -1,
        [501] = 1,
        [999] = INT8_MAX,
    };
    int8_t dataOut[1000] = { 0 };
    uint8_t err = (uint8_t)Deque_Error_None;

    Deque_Init(&q, buf, sizeof(buf), sizeof(dataIn[0]));

    /* Fill the deque up */
    for (uint16_t i = 0; i < ELEMENTS_IN(dataIn); i++)
    {
        err |= Deque_PushBack(&q, &dataIn[i]);
    }

    /*****************     Act       *****************/
    /* Empty the deque */
    for (uint16_t i = 0; i < ELEMENTS_IN(dataOut); i++)
    {
        err |= Deque_PopFront(&q, &dataOut[i]);
    }

    /*****************    Assert     *****************/
    ASSERT_EQ(Deque_Error_None, (Deque_Error_e)err);
    ASSERT_MEM_EQ(dataIn, dataOut, ELEMENTS_IN(dataIn));
    ASSERT_EQ(true, Deque_IsEmpty(&q));

    PASS();
}

TEST Deque_can_empty_a_full_buffer_of_1_byte_data_types_by_push_front_and_pop_back(void)
{
    /*****************    Arrange    *****************/
    Deque_t q;
    int8_t buf[1000];
    int8_t dataIn[1000] =
    {
        [  0] = INT8_MIN,
        [101] = -1,
        [501] = 1,
        [999] = INT8_MAX,
    };
    int8_t dataOut[1000] = { 0 };
    uint8_t err = (uint8_t)Deque_Error_None;

    Deque_Init(&q, buf, sizeof(buf), sizeof(dataIn[0]));

    /* Fill the deque up */
    for (uint16_t i = 0; i < ELEMENTS_IN(dataIn); i++)
    {
        err |= Deque_PushFront(&q, &dataIn[i]);
    }

    /*****************     Act       *****************/
    /* Empty the deque */
    for (uint16_t i = 0; i < ELEMENTS_IN(dataOut); i++)
    {
        err |= Deque_PopBack(&q, &dataOut[i]);
    }

    /*****************    Assert     *****************/
    ASSERT_EQ(Deque_Error_None, (Deque_Error_e)err);
    ASSERT_MEM_EQ(dataIn, dataOut, ELEMENTS_IN(dataIn));
    ASSERT_EQ(true, Deque_IsEmpty(&q));

    PASS();
}

TEST Deque_can_empty_a_full_buffer_of_1_byte_data_types_by_push_front_and_pop_front(void)
{
    /*****************    Arrange    *****************/
    Deque_t q;
    int8_t buf[1000];
    int8_t dataIn[1000] =
    {
        [  0] = INT8_MIN,
        [101] = -1,
        [501] = 1,
        [999] = INT8_MAX,
    };
    int8_t dataOut[1000] = { 0 };
    uint8_t err = (uint8_t)Deque_Error_None;

    Deque_Init(&q, buf, sizeof(buf), sizeof(dataIn[0]));

    /* Fill the deque up */
    for (uint16_t i = 0; i < ELEMENTS_IN(dataIn); i++)
    {
        err |= Deque_PushFront(&q, &dataIn[i]);
    }

    /*****************     Act       *****************/
    /* Empty the deque */
    for (uint16_t i = 0; i < ELEMENTS_IN(dataOut); i++)
    {
        err |= Deque_PopFront(&q, &dataOut[i]);
    }

    /*****************    Assert     *****************/
    ASSERT_EQ(Deque_Error_None, (Deque_Error_e)err);
    /* Front cursor points at the last element inserted */
    ASSERT_EQ(dataIn[0], dataOut[999]);
    ASSERT_EQ(dataIn[101], dataOut[898]); /* 999 - 101 */
    ASSERT_EQ(dataIn[501], dataOut[498]); /* 999 - 501 */
    ASSERT_EQ(dataIn[999], dataOut[0]);
    ASSERT_EQ(true, Deque_IsEmpty(&q));

    PASS();
}

TEST Deque_can_empty_a_full_buffer_of_1_byte_data_types_by_push_back_and_pop_back(void)
{
    /*****************    Arrange    *****************/
    Deque_t q;
    int8_t buf[1000];
    int8_t dataIn[1000] =
    {
        [  0] = INT8_MIN,
        [101] = -1,
        [501] = 1,
        [999] = INT8_MAX,
    };
    int8_t dataOut[1000] = { 0 };
    uint8_t err = (uint8_t)Deque_Error_None;

    Deque_Init(&q, buf, sizeof(buf), sizeof(dataIn[0]));

    /* Fill the deque up */
    for (uint16_t i = 0; i < ELEMENTS_IN(dataIn); i++)
    {
        err |= Deque_PushBack(&q, &dataIn[i]);
    }

    /*****************     Act       *****************/
    /* Empty the deque */
    for (uint16_t i = 0; i < ELEMENTS_IN(dataOut); i++)
    {
        err |= Deque_PopBack(&q, &dataOut[i]);
    }

    /*****************    Assert     *****************/
    ASSERT_EQ(Deque_Error_None, (Deque_Error_e)err);
    /* Rear cursor points at the last element inserted */
    ASSERT_EQ(dataIn[0], dataOut[999]);
    ASSERT_EQ(dataIn[101], dataOut[898]); /* 999 - 101 */
    ASSERT_EQ(dataIn[501], dataOut[498]); /* 999 - 501 */
    ASSERT_EQ(dataIn[999], dataOut[0]);
    ASSERT_EQ(true, Deque_IsEmpty(&q));

    PASS();
}

TEST Deque_can_empty_a_full_buffer_of_8_byte_data_types_by_push_back_and_pop_front(void)
{
    /*****************    Arrange    *****************/
    Deque_t q;
    int64_t buf[1000];
    int64_t dataIn[1000] =
    {
        [  0] = INT64_MIN,
        [101] = -1,
        [501] = 1,
        [999] = INT64_MAX,
    };
    int64_t dataOut[1000] = { 0 };
    uint8_t err = (uint8_t)Deque_Error_None;

    Deque_Init(&q, buf, sizeof(buf), sizeof(dataIn[0]));

    /*****************     Act       *****************/

    /* Fill the deque up */
    for (uint16_t i = 0; i < ELEMENTS_IN(dataIn); i++)
    {
        err |= Deque_PushBack(&q, &dataIn[i]);
    }

    /* Empty the deque */
    for (uint16_t i = 0; i < ELEMENTS_IN(dataOut); i++)
    {
        err |= Deque_PopFront(&q, &dataOut[i]);
    }

    /*****************    Assert     *****************/
    ASSERT_EQ(Deque_Error_None, (Deque_Error_e)err);
    ASSERT_MEM_EQ(dataIn, dataOut, ELEMENTS_IN(dataIn));
    ASSERT_EQ(true, Deque_IsEmpty(&q));

    PASS();
}

TEST Deque_can_empty_a_full_buffer_of_8_byte_data_types_by_push_front_and_pop_back(void)
{
    /*****************    Arrange    *****************/
    Deque_t q;
    int64_t buf[1000];
    int64_t dataIn[1000] =
    {
        [  0] = INT64_MIN,
        [101] = -1,
        [501] = 1,
        [999] = INT64_MAX,
    };
    int64_t dataOut[1000] = { 0 };
    uint8_t err = (uint8_t)Deque_Error_None;

    Deque_Init(&q, buf, sizeof(buf), sizeof(dataIn[0]));

    /*****************     Act       *****************/

    /* Fill the deque up */
    for (uint16_t i = 0; i < ELEMENTS_IN(dataIn); i++)
    {
        err |= Deque_PushFront(&q, &dataIn[i]);
    }

    /* Empty the deque */
    for (uint16_t i = 0; i < ELEMENTS_IN(dataOut); i++)
    {
        err |= Deque_PopBack(&q, &dataOut[i]);
    }

    /*****************    Assert     *****************/
    ASSERT_EQ(Deque_Error_None, (Deque_Error_e)err);
    ASSERT_MEM_EQ(dataIn, dataOut, ELEMENTS_IN(dataIn));
    ASSERT_EQ(true, Deque_IsEmpty(&q));

    PASS();
}

TEST Deque_can_empty_a_full_buffer_of_8_byte_data_types_by_push_front_and_pop_front(void)
{
    /*****************    Arrange    *****************/
    Deque_t q;
    int64_t buf[1000];
    int64_t dataIn[1000] =
    {
        [  0] = INT64_MIN,
        [101] = -1,
        [501] = 1,
        [999] = INT64_MAX,
    };
    int64_t dataOut[1000] = { 0 };
    uint8_t err = (uint8_t)Deque_Error_None;

    Deque_Init(&q, buf, sizeof(buf), sizeof(dataIn[0]));

    /*****************     Act       *****************/

    /* Fill the deque up */
    for (uint16_t i = 0; i < ELEMENTS_IN(dataIn); i++)
    {
        err |= Deque_PushFront(&q, &dataIn[i]);
    }

    /* Empty the deque */
    for (uint16_t i = 0; i < ELEMENTS_IN(dataOut); i++)
    {
        err |= Deque_PopFront(&q, &dataOut[i]);
    }

    /*****************    Assert     *****************/
    ASSERT_EQ(Deque_Error_None, (Deque_Error_e)err);
    /* Rear cursor points at the last element inserted */
    ASSERT_EQ(dataIn[0], dataOut[999]);
    ASSERT_EQ(dataIn[101], dataOut[898]); /* 999 - 101 */
    ASSERT_EQ(dataIn[501], dataOut[498]); /* 999 - 501 */
    ASSERT_EQ(dataIn[999], dataOut[0]);
    ASSERT_EQ(true, Deque_IsEmpty(&q));

    PASS();
}

TEST Deque_can_empty_a_full_buffer_of_8_byte_data_types_by_push_back_and_pop_back(void)
{
    /*****************    Arrange    *****************/
    Deque_t q;
    int64_t buf[1000];
    int64_t dataIn[1000] =
    {
        [  0] = INT64_MIN,
        [101] = -1,
        [501] = 1,
        [999] = INT64_MAX,
    };
    int64_t dataOut[1000] = { 0 };
    uint8_t err = (uint8_t)Deque_Error_None;

    Deque_Init(&q, buf, sizeof(buf), sizeof(dataIn[0]));

    /*****************     Act       *****************/

    /* Fill the deque up */
    for (uint16_t i = 0; i < ELEMENTS_IN(dataIn); i++)
    {
        err |= Deque_PushBack(&q, &dataIn[i]);
    }

    /* Empty the deque */
    for (uint16_t i = 0; i < ELEMENTS_IN(dataOut); i++)
    {
        err |= Deque_PopBack(&q, &dataOut[i]);
    }

    /*****************    Assert     *****************/
    ASSERT_EQ(Deque_Error_None, (Deque_Error_e)err);
    /* Rear cursor points at the last element inserted */
    ASSERT_EQ(dataIn[0], dataOut[999]);
    ASSERT_EQ(dataIn[101], dataOut[898]); /* 999 - 101 */
    ASSERT_EQ(dataIn[501], dataOut[498]); /* 999 - 501 */
    ASSERT_EQ(dataIn[999], dataOut[0]);
    ASSERT_EQ(true, Deque_IsEmpty(&q));

    PASS();
}

// TEST Deque_can_fill_and_empty_a_large_buffer_with_struct_data_types(void)
// {
//     typedef struct _Deque_Struct_t
//     {
//         uint8_t a;
//         int16_t b;
//         uint32_t c;
//         int8_t d;
//         uint32_t e;
//     } Deque_Struct_t;

//     /*****************    Arrange    *****************/
//     Deque_t q;
//     Deque_Struct_t buf[1000];
//     Deque_Struct_t dataIn[1000] =
//     {
//         [  1] = { .a = UINT8_MAX, .b = INT16_MAX, .c = -1, .d = INT8_MIN, .e = 1  },
//         [101] = { .a = INT8_MAX,  .b = INT16_MIN, .c = 0,  .d = INT8_MAX, .e = -1 },
//         [501] = { .a = UINT8_MAX, .b = INT16_MAX, .c = -1, .d = INT8_MIN, .e = 1  },
//         [999] = { .a = INT8_MAX,  .b = INT16_MIN, .c = 0,  .d = INT8_MAX, .e = -1 },
//     };
//     Deque_Struct_t dataOut[1000];
//     uint8_t err = (uint8_t)Deque_Error_None;

//     Deque_Init(&q, buf, sizeof(buf), sizeof(Deque_Struct_t));

//     /*****************     Act       *****************/

//     /* Fill the deque up */
//     for (uint16_t i = 0; i < ELEMENTS_IN(dataIn); i++)
//     {
//         err |= Deque_Push(&q, &dataIn[i]);
//     }

//     /* Empty the deque */
//     for (uint16_t i = 0; i < ELEMENTS_IN(dataOut); i++)
//     {
//         err |= Deque_Pop(&q, &dataOut[i]);
//     }

//     /*****************    Assert     *****************/
//     ASSERT_EQ(Deque_Error_None, (Deque_Error_e)err);
//     ASSERT_MEM_EQ(dataIn, dataOut, ELEMENTS_IN(dataIn));
//     ASSERT_EQ(true, Deque_IsEmpty(&q));

//     PASS();
// }

// TEST Deque_can_partially_fill_and_empty_multiple_times()
// {
//     /*****************    Arrange    *****************/
//     Deque_t q;
//     int8_t buf[5];
//     int8_t dataIn[5] =
//     {
//         [0] = -7,
//         [1] = 121,
//         [2] = -121,
//         [3] = 7,
//         [4] = INT8_MAX,
//     };
//     int8_t dataOut[5] = { 0 };
//     uint8_t err = (uint8_t)Deque_Error_None;

//     Deque_Init(&q, buf, sizeof(buf), sizeof(dataIn[0]));

//     /*****************     Act       *****************/
//     for (uint16_t i = 0; i < 15; i++)
//     {
//         err |= Deque_Push(&q, &dataIn[i % sizeof(buf)]);
//         err |= Deque_Push(&q, &dataIn[i % sizeof(buf)]);
//         err |= Deque_Pop(&q, &dataOut[i % sizeof(buf)]);
//         err |= Deque_Pop(&q, &dataOut[i % sizeof(buf)]);

//         ASSERT_EQ(Deque_Error_None, (Deque_Error_e)err);
//         ASSERT_EQ(false, Deque_IsFull(&q));
//         ASSERT_EQ(true, Deque_IsEmpty(&q));
//     }

//     PASS();
// }

SUITE(Deque_Suite)
{
    /* Unit Tests */
    RUN_TEST(Deque_can_report_empty);
    RUN_TEST(Deque_can_report_not_full);

    RUN_TEST(Deque_can_report_not_empty_when_pushed_from_back);
    RUN_TEST(Deque_can_report_not_empty_when_pushed_from_front);

    RUN_TEST(Deque_can_report_full_when_pushed_from_back);
    RUN_TEST(Deque_can_report_full_when_pushed_from_front);

    RUN_TEST(Deque_front_pop_fails_if_underflow);
    RUN_TEST(Deque_back_pop_fails_if_underflow);

    RUN_TEST(Deque_back_push_fails_due_to_overflow_when_pushed_from_back);
    RUN_TEST(Deque_back_push_fails_due_to_overflow_when_pushed_from_front);
    RUN_TEST(Deque_front_push_fails_due_to_overflow_when_pushed_from_back);
    RUN_TEST(Deque_front_push_fails_due_to_overflow_when_pushed_from_front);

    RUN_TEST(Deque_can_front_pop_1_byte_data_types_when_pushed_from_back);
    RUN_TEST(Deque_can_front_pop_2_byte_data_types_when_pushed_from_back);
    RUN_TEST(Deque_can_front_pop_8_byte_data_types_when_pushed_from_back);
    RUN_TEST(Deque_can_front_pop_struct_data_types_when_pushed_from_back);

    RUN_TEST(Deque_can_front_pop_1_byte_data_types_when_pushed_from_front);
    RUN_TEST(Deque_can_front_pop_2_byte_data_types_when_pushed_from_front);
    RUN_TEST(Deque_can_front_pop_8_byte_data_types_when_pushed_from_front);
    RUN_TEST(Deque_can_front_pop_struct_data_types_when_pushed_from_front);

    RUN_TEST(Deque_can_back_pop_1_byte_data_types_when_pushed_from_back);
    RUN_TEST(Deque_can_back_pop_2_byte_data_types_when_pushed_from_back);
    RUN_TEST(Deque_can_back_pop_8_byte_data_types_when_pushed_from_back);
    RUN_TEST(Deque_can_back_pop_struct_data_types_when_pushed_from_back);

    RUN_TEST(Deque_can_back_pop_1_byte_data_types_when_pushed_from_front);
    RUN_TEST(Deque_can_back_pop_2_byte_data_types_when_pushed_from_front);
    RUN_TEST(Deque_can_back_pop_8_byte_data_types_when_pushed_from_front);
    RUN_TEST(Deque_can_back_pop_struct_data_types_when_pushed_from_front);

    RUN_TEST(Deque_can_peek_at_next_element_to_be_front_popped_when_pushed_from_back);
    RUN_TEST(Deque_can_peek_at_next_element_to_be_front_popped_when_pushed_from_front);
    RUN_TEST(Deque_can_peek_at_next_element_to_be_back_popped_when_pushed_from_back);
    RUN_TEST(Deque_can_peek_at_next_element_to_be_back_popped_when_pushed_from_front);

    /* Integration Tests */
    RUN_TEST(Deque_can_empty_a_full_buffer_of_1_byte_data_types_by_push_back_and_pop_front);
    RUN_TEST(Deque_can_empty_a_full_buffer_of_1_byte_data_types_by_push_front_and_pop_back);
    RUN_TEST(Deque_can_empty_a_full_buffer_of_1_byte_data_types_by_push_front_and_pop_front);
    RUN_TEST(Deque_can_empty_a_full_buffer_of_1_byte_data_types_by_push_back_and_pop_back);

    RUN_TEST(Deque_can_empty_a_full_buffer_of_8_byte_data_types_by_push_back_and_pop_front);
    RUN_TEST(Deque_can_empty_a_full_buffer_of_8_byte_data_types_by_push_front_and_pop_back);
    RUN_TEST(Deque_can_empty_a_full_buffer_of_8_byte_data_types_by_push_front_and_pop_front);
    RUN_TEST(Deque_can_empty_a_full_buffer_of_8_byte_data_types_by_push_back_and_pop_back);

    RUN_TEST(Deque_can_fill_and_empty_a_large_buffer_with_struct_data_types);
    // RUN_TEST(Deque_can_partially_fill_and_empty_multiple_times);
}

#endif /* DEQUE_SUITE_INCLUDED */