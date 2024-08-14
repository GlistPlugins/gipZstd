//
// Created by irrel on 13/08/2024.
//

#include "gipZstd.h"

#include "zstd.h"

std::vector<uint8_t> gipZstd::compressString(const std::string& input, int compresssionLevel, bool* outSuccess) {
	size_t maxdistsize = ZSTD_compressBound(input.size());
	std::vector<uint8_t> compresseddata(maxdistsize);

	size_t compressedsize = ZSTD_compress(
		compresseddata.data(),
		maxdistsize,
		input.data(),
		input.size(),
		compresssionLevel // compression level
	);

	if (ZSTD_isError(compressedsize)) {
		if (outSuccess) *outSuccess = false;
		return {};
	}

	compresseddata.resize(compressedsize);
	if (outSuccess) *outSuccess = true;
	return compresseddata;
}

std::string gipZstd::decompressString(const std::vector<uint8_t>& compresseddata, size_t originalSize, bool* outSuccess) {
	std::vector<uint8_t> decompresseddata(originalSize);

	size_t decompressedsize = ZSTD_decompress(
		decompresseddata.data(),
		originalSize,
		compresseddata.data(),
		compresseddata.size()
	);

	if (ZSTD_isError(decompressedsize)) {
		if (outSuccess) *outSuccess = false;
		return {};
	}

	if (outSuccess) *outSuccess = true;
	return {decompresseddata.begin(), decompresseddata.end()};
}
