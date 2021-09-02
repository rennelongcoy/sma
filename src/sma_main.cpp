
#include "sma_device.hpp"

const size_t SEQUENCE_SIZE = 8;

int main()
{
    SmaDevice sma;

    uint8_t input_sequence[SEQUENCE_SIZE]{10, 10, 50, 100, 100, 200, 100, 1};
    sma.write(input_sequence, SEQUENCE_SIZE);
    std::cout << "Input Sequence: ";
    for (unsigned int i = 0; i < SEQUENCE_SIZE; ++i) {
        std::cout << (int) input_sequence[i] << " ";
    }
    std::cout << std::endl;

    uint8_t output_sequence[SEQUENCE_SIZE]{0};
    sma.read(output_sequence, SEQUENCE_SIZE);
    std::cout << "Output Sequence: ";
    for (unsigned int i = 0; i < SEQUENCE_SIZE; ++i) {
        std::cout << (int) output_sequence[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}