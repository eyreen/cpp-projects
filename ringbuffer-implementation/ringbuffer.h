#include <array>


const int kMaxNumElements = 8;

enum class RingbufferStatus { Okay, Empty, Full };

/**
 * A class that defines a ringbuffer with 8 elements.
*/
class Ringbuffer
{
public:
    int getReadPos() const
    {
        return readPos_;
    }

    int getWritePos() const
    {
        return writePos_;
    }

    int getNumberOfElements() const
    {
        return numberOfElements_;
    }

    // Read the first element from the ringbuffer and remove it from the buffer.
    int readElement()
    {
        numberOfElements_--;
        int result = elements_[readPos_];
        increaseWithModulo(readPos_);
        return result;
    }

    // Add an element at the end of the buffer.
    void writeElement(int element)
    {
        elements_[writePos_] = element;
        increaseWithModulo(writePos_);
        numberOfElements_++;
    }

    // Return the status of the ringbuffer
    RingbufferStatus status() const
    {
        if (numberOfElements_ == 0)
            return RingbufferStatus::Empty;
        else if (numberOfElements_ >= kMaxNumElements)
            return RingbufferStatus::Full;
        else
            return RingbufferStatus::Okay;
    }

private:
    int readPos_ = 0;
    int writePos_ = 0;
    int numberOfElements_ = 0;
    std::array<int, kMaxNumElements> elements_ = {};

    void increaseWithModulo(int& i)
    {
        i = (i+1)%kMaxNumElements;
    }


};
