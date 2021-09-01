#include <vector>

#include "sma_device.hpp"
#include "gtest/gtest.h"

namespace {

TEST(sma_device_test, InputSequence_all_0) {
    SmaDevice sma;

    std::vector<uint8_t> input_sequence(128, 0);
    sma.write(input_sequence.data(), input_sequence.size());

    std::vector<uint8_t> output_sequence(128, 0);
    sma.read(output_sequence.data(), output_sequence.size());

    for (int i = 0; i < 128; ++i) {
        EXPECT_EQ(0, output_sequence[i]);
    }
}

TEST(sma_device_test, InputSequence_all_255) {
    SmaDevice sma;

    std::vector<uint8_t> input_sequence(128, 255);
    sma.write(input_sequence.data(), input_sequence.size());

    std::vector<uint8_t> output_sequence(128, 255);
    sma.read(output_sequence.data(), output_sequence.size());

    for (int i = 0; i < 128; ++i) {
        EXPECT_EQ(255, output_sequence[i]);
    }
}

}