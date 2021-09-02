#include <vector>

#include "sma_device.hpp"
#include "gtest/gtest.h"

namespace {

TEST(sma_device_write_test, Write_min_size)
{
    SmaDevice sma;
    const unsigned int SEQUENCE_LENGTH = 128;
    int ret = -1;

    std::vector<uint8_t> input_sequence(SEQUENCE_LENGTH, 0);
    ret = sma.write(input_sequence.data(), SEQUENCE_LENGTH);

    EXPECT_EQ(ret, SEQUENCE_LENGTH);
}

TEST(sma_device_write_test, Write_max_size)
{
    SmaDevice sma;
    const unsigned int SEQUENCE_LENGTH = 128;
    int ret = -1;

    std::vector<uint8_t> input_sequence(SEQUENCE_LENGTH, 0);
    ret = sma.write(input_sequence.data(), SEQUENCE_LENGTH);

    EXPECT_EQ(ret, SEQUENCE_LENGTH);
}

TEST(sma_device_write_test, Write_exceed_size)
{
    SmaDevice sma;
    const unsigned int SEQUENCE_LENGTH = 129;
    int ret = 0;

    std::vector<uint8_t> input_sequence(SEQUENCE_LENGTH, 0);
    ret = sma.write(input_sequence.data(), SEQUENCE_LENGTH);

    EXPECT_EQ(ret, -1);
    EXPECT_EQ(errno, EFAULT);
}

TEST(sma_device_write_test, Write_invalid_size)
{
    SmaDevice sma;
    const unsigned int SEQUENCE_LENGTH = 128;
    int ret = 0;

    std::vector<uint8_t> input_sequence(SEQUENCE_LENGTH, 0);
    ret = sma.write(input_sequence.data(), -100);

    EXPECT_EQ(ret, -1);
    EXPECT_EQ(errno, EFAULT);
}

TEST(sma_device_write_test, Write_invalid_output_buffer)
{
    SmaDevice sma;
    const unsigned int SEQUENCE_LENGTH = 129;
    int ret = 0;

    ret = sma.write(nullptr, SEQUENCE_LENGTH);

    EXPECT_EQ(ret, -1);
    EXPECT_EQ(errno, EFAULT);
}

}