
#include <cstdio>
#include <fstream>
#include <vector>

#include "sma_device.hpp"

int main()
{
    SmaDevice sma;
    int ret = 0;

    // Read from an input file
    std::ifstream input_file("../input/input.txt");
    std::vector<uint8_t> input_sequence;
    unsigned int data;
    while (input_file >> data) {
        input_sequence.push_back((uint8_t) data);
    }

    // Print input sequence
    std::cout << "Input Sequence: ";
    for (uint8_t x : input_sequence) {
        std::cout << (int) x << " ";
    }
    std::cout << std::endl;

    // Write to device driver
    ret = sma.write(input_sequence.data(), input_sequence.size());
    if (ret == -1) {
        perror("Write to device driver failed");
        return -1;
    }

    // Read results from device driver
    std::vector<uint8_t> output_sequence(input_sequence.size());
    ret = sma.read(output_sequence.data(), input_sequence.size());
    if (ret == -1) {
        perror("Read from device driver failed");
        return -1;
    }

    // Print output sequence
    std::cout << "Output Sequence: ";
    for (uint8_t x : output_sequence) {
        std::cout << (int) x << " ";
    }
    std::cout << std::endl;

    // Write to an output file
    std::ofstream output_file("../output/output.txt");
    for (uint8_t x : output_sequence) {
        output_file << (int) x << std::endl;
    }

    return 0;
}