#include <vector>

#include "sma_device.hpp"
#include "gtest/gtest.h"

namespace {

TEST(sma_device_read_test, Read_min_size)
{
    SmaDevice sma;
    const unsigned int SEQUENCE_LENGTH = 0;
    int ret = -1;

    std::vector<uint8_t> output_sequence(SEQUENCE_LENGTH, 0);
    ret = sma.read(output_sequence.data(), SEQUENCE_LENGTH);

    EXPECT_EQ(ret, SEQUENCE_LENGTH);
}

TEST(sma_device_read_test, Read_max_size)
{
    SmaDevice sma;
    const unsigned int SEQUENCE_LENGTH = 128;
    int ret = -1;

    std::vector<uint8_t> output_sequence(SEQUENCE_LENGTH, 0);
    ret = sma.read(output_sequence.data(), SEQUENCE_LENGTH);

    EXPECT_EQ(ret, SEQUENCE_LENGTH);
}

TEST(sma_device_read_test, Read_exceed_size)
{
    SmaDevice sma;
    const unsigned int SEQUENCE_LENGTH = 129;
    int ret = 0;

    std::vector<uint8_t> output_sequence(SEQUENCE_LENGTH, 0);
    ret = sma.read(output_sequence.data(), SEQUENCE_LENGTH);

    EXPECT_EQ(ret, -1);
    EXPECT_EQ(errno, EFAULT);
}

TEST(sma_device_read_test, Read_invalid_size)
{
    SmaDevice sma;
    const unsigned int SEQUENCE_LENGTH = 128;
    int ret = 0;

    std::vector<uint8_t> output_sequence(SEQUENCE_LENGTH, 0);
    ret = sma.read(output_sequence.data(), -100);

    EXPECT_EQ(ret, -1);
    EXPECT_EQ(errno, EFAULT);
}

TEST(sma_device_read_test, Read_invalid_output_buffer)
{
    SmaDevice sma;
    const unsigned int SEQUENCE_LENGTH = 128;
    int ret = 0;

    ret = sma.read(nullptr, SEQUENCE_LENGTH);

    EXPECT_EQ(ret, -1);
    EXPECT_EQ(errno, EFAULT);
}

}