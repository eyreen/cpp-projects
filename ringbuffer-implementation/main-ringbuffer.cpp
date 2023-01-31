#include "../test.h"
#include "ringbuffer.h"

TEST(emptyRingBufferTest)
{
    Ringbuffer r;
    check(r.getReadPos(), 0);
    check(r.getWritePos(), 0);
    check(r.getNumberOfElements(), 0);
}

TEST(addSingleElementTest)
{
    Ringbuffer r;
    r.writeElement(1);
    check(r.getNumberOfElements(), 1);
    check(r.readElement(), 1);
    check(r.getNumberOfElements(), 0);
}

TEST(addTwoElementsTest)
{
    Ringbuffer r;
    r.writeElement(1);
    r.writeElement(2);
    check(r.getNumberOfElements(), 2);
    check(r.readElement(), 1);
    check(r.getNumberOfElements(), 1);
    check(r.readElement(), 2);
    check(r.getNumberOfElements(), 0);
}

TEST(add8ElementsTest)
{
    Ringbuffer r;
    for (int i = 0; i < 8; ++i)
    {
        r.writeElement(i);
        check(r.getNumberOfElements(), i + 1);
    }

    for (int i = 0; i < 8; ++i)
    {
        check(r.readElement(), i);
        check(r.getNumberOfElements(), 7 - i);
    }
}

TEST(ringbufferStatusTest)
{
    Ringbuffer r;
    check(r.status(), RingbufferStatus::Empty);
    for (int i = 0; i < 7; i++)
    {
        r.writeElement(i);
        check(r.status(), RingbufferStatus::Okay);
    }
    r.writeElement(7);
    check(r.status(), RingbufferStatus::Full);
    for (int i=0; i<7; ++i)
    {
        r.readElement();
        check(r.status(), RingbufferStatus::Okay);
    }
    r.readElement();
    check(r.status(), RingbufferStatus::Empty);
}

int main()
{
}