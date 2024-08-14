//
// Created by irrel on 13/08/2024.
//

#ifndef GIPZSTD_H_
#define GIPZSTD_H_

#include "gBaseComponent.h"

#include <cstdint>
#include <string>
#include <vector>

class gipZstd : public gBaseComponent {
public:
	gipZstd();
	~gipZstd();

	void update() override;

	/**
	 * Compresses the input string using Zstandard (ZSTD) compression with a specified compression level.
	 *
	 * @param input The input string to be compressed.
	 * @param compressionLevel The compression level to use, which ranges from 1 (fastest) to 22 (maximum compression).
	 *                         Higher values result in better compression but slower performance.
	 * @param outSuccess A pointer to a boolean flag that will be set to true if the compression is successful,
	 *                   or false if an error occurs during compression. Can be nullptr.
	 * @return A vector of uint8_t containing the compressed data. If compression fails, the returned vector will be empty.
	 */
	std::vector<uint8_t> compressString(const std::string& input, int compressionLevel, bool* outSuccess);

	/**
	 * Decompresses the compressed data back into a string using Zstandard (ZSTD) decompression.
	 *
	 * @param compressedData A vector of uint8_t containing the compressed data.
	 * @param originalSize The original size of the data before compression. This is needed to allocate
	 *                     the correct size for the decompressed output.
	 * @param outSuccess A pointer to a boolean flag that will be set to true if the decompression is successful,
	 *                   or false if an error occurs during decompression. Can be nullptr.
	 * @return A string containing the decompressed data. If decompression fails, the returned string will be empty.
	 */
	std::string decompressString(const std::vector<uint8_t>& compressedData, size_t originalSize, bool* outSuccess);
};

#endif