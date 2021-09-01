#include <vector>

#include "sma_device.hpp"
#include "gtest/gtest.h"

namespace {

TEST(sma_device_calculation_test, InputSequence_all_0)
{
    SmaDevice sma;
    const unsigned int SEQUENCE_LENGTH = 128;
    int ret = -1;

    std::vector<uint8_t> input_sequence(SEQUENCE_LENGTH, 0);
    ret = sma.write(input_sequence.data(), SEQUENCE_LENGTH);
    EXPECT_EQ(ret, SEQUENCE_LENGTH);

    std::vector<uint8_t> output_sequence(SEQUENCE_LENGTH, 0);
    ret = sma.read(output_sequence.data(), SEQUENCE_LENGTH);
    EXPECT_EQ(ret, SEQUENCE_LENGTH);

    for (int i = 0; i < SEQUENCE_LENGTH; ++i) {
        EXPECT_EQ(output_sequence[i], 0);
    }
}

TEST(sma_device_calculation_test, InputSequence_all_255)
{
    SmaDevice sma;
    const unsigned int SEQUENCE_LENGTH = 128;
    int ret = -1;

    std::vector<uint8_t> input_sequence(SEQUENCE_LENGTH, 255);
    ret = sma.write(input_sequence.data(), SEQUENCE_LENGTH);
    EXPECT_EQ(ret, SEQUENCE_LENGTH);

    std::vector<uint8_t> output_sequence(SEQUENCE_LENGTH, 255);
    ret = sma.read(output_sequence.data(), SEQUENCE_LENGTH);
    EXPECT_EQ(ret, SEQUENCE_LENGTH);

    for (int i = 0; i < SEQUENCE_LENGTH; ++i) {
        EXPECT_EQ(output_sequence[i], 255);
    }
}

TEST(sma_device_calculation_test, InputSequence_1_element)
{
    SmaDevice sma;
    const unsigned int SEQUENCE_LENGTH = 1;
    int ret = -1;

    std::vector<uint8_t> input_sequence{78};
    ret = sma.write(input_sequence.data(), SEQUENCE_LENGTH);
    EXPECT_EQ(ret, SEQUENCE_LENGTH);

    std::vector<uint8_t> output_sequence(SEQUENCE_LENGTH, 0);
    ret = sma.read(output_sequence.data(), SEQUENCE_LENGTH);
    EXPECT_EQ(ret, SEQUENCE_LENGTH);

    std::vector<uint8_t> expected_sequence{78};

    for (int i = 0; i < SEQUENCE_LENGTH; ++i) {
        EXPECT_EQ(output_sequence[i], expected_sequence[i]);
    }
}

TEST(sma_device_calculation_test, InputSequence_2_elements)
{
    SmaDevice sma;
    const unsigned int SEQUENCE_LENGTH = 2;
    int ret = -1;

    std::vector<uint8_t> input_sequence{99, 2};
    ret = sma.write(input_sequence.data(), SEQUENCE_LENGTH);
    EXPECT_EQ(ret, SEQUENCE_LENGTH);

    std::vector<uint8_t> output_sequence(SEQUENCE_LENGTH, 0);
    ret = sma.read(output_sequence.data(), SEQUENCE_LENGTH);
    EXPECT_EQ(ret, SEQUENCE_LENGTH);

    std::vector<uint8_t> expected_sequence{99, 50};

    for (int i = 0; i < SEQUENCE_LENGTH; ++i) {
        EXPECT_EQ(output_sequence[i], expected_sequence[i]);
    }
}

TEST(sma_device_calculation_test, InputSequence_3_elements)
{
    SmaDevice sma;
    const unsigned int SEQUENCE_LENGTH = 3;
    int ret = -1;

    std::vector<uint8_t> input_sequence{35, 29, 255};
    ret = sma.write(input_sequence.data(), SEQUENCE_LENGTH);
    EXPECT_EQ(ret, SEQUENCE_LENGTH);

    std::vector<uint8_t> output_sequence(SEQUENCE_LENGTH, 0);
    ret = sma.read(output_sequence.data(), SEQUENCE_LENGTH);
    EXPECT_EQ(ret, SEQUENCE_LENGTH);

    std::vector<uint8_t> expected_sequence{35, 32, 106};

    for (int i = 0; i < SEQUENCE_LENGTH; ++i) {
        EXPECT_EQ(output_sequence[i], expected_sequence[i]);
    }
}

TEST(sma_device_calculation_test, InputSequence_4_elements)
{
    SmaDevice sma;
    const unsigned int SEQUENCE_LENGTH = 4;
    int ret = -1;

    std::vector<uint8_t> input_sequence{53, 92, 255, 7};
    ret = sma.write(input_sequence.data(), SEQUENCE_LENGTH);
    EXPECT_EQ(ret, SEQUENCE_LENGTH);

    std::vector<uint8_t> output_sequence(SEQUENCE_LENGTH, 0);
    ret = sma.read(output_sequence.data(), SEQUENCE_LENGTH);
    EXPECT_EQ(ret, SEQUENCE_LENGTH);

    std::vector<uint8_t> expected_sequence{53, 72, 133, 101};

    for (int i = 0; i < SEQUENCE_LENGTH; ++i) {
        EXPECT_EQ(output_sequence[i], expected_sequence[i]);
    }
}

TEST(sma_device_calculation_test, InputSequence_assignment_sample)
{
    SmaDevice sma;
    const unsigned int SEQUENCE_LENGTH = 8;
    int ret = -1;

    std::vector<uint8_t> input_sequence{10, 10, 50, 100, 100, 200, 100, 1};
    ret = sma.write(input_sequence.data(), SEQUENCE_LENGTH);
    EXPECT_EQ(ret, SEQUENCE_LENGTH);

    std::vector<uint8_t> output_sequence(SEQUENCE_LENGTH, 0);
    ret = sma.read(output_sequence.data(), SEQUENCE_LENGTH);
    EXPECT_EQ(ret, SEQUENCE_LENGTH);

    std::vector<uint8_t> expected_sequence{10, 10, 23, 42, 54, 92, 110, 100};

    for (int i = 0; i < SEQUENCE_LENGTH; ++i) {
        EXPECT_EQ(output_sequence[i], expected_sequence[i]);
    }
}

}