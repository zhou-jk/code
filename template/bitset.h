#include <vector>
#include <cstdint>
#include <stdexcept>
#include <iostream>
#include <algorithm>
#include <cassert>
#include <cstring> // For std::memmove
#include <immintrin.h>

class Bitset {
private:
    static constexpr size_t BITS_PER_WORD = 64;
    std::vector<uint64_t> bits;
    size_t numBits;

public:
    // 构造函数
    explicit Bitset(size_t size = 0)
        : bits((size + BITS_PER_WORD - 1) / BITS_PER_WORD, 0), numBits(size) {}
    
    size_t size() const {
        return numBits;
    }

    // 内联函数，访问单个位
    inline bool operator[](size_t index) const {
        if (index >= numBits) throw std::out_of_range("Bit index out of range");
        size_t wordIndex = index / BITS_PER_WORD;
        size_t bitIndex = index % BITS_PER_WORD;
        return (bits[wordIndex] >> bitIndex) & 1;
    }

    // 内联函数，设置单个位为 1
    inline void set(size_t index) {
        if (index >= numBits) throw std::out_of_range("Bit index out of range");
        size_t wordIndex = index / BITS_PER_WORD;
        size_t bitIndex = index % BITS_PER_WORD;
        bits[wordIndex] |= (uint64_t(1) << bitIndex);
    }

    // 内联函数，重置单个位为 0
    inline void reset(size_t index) {
        if (index >= numBits) throw std::out_of_range("Bit index out of range");
        size_t wordIndex = index / BITS_PER_WORD;
        size_t bitIndex = index % BITS_PER_WORD;
        bits[wordIndex] &= ~(uint64_t(1) << bitIndex);
    }

    // 左移运算符<<=
    Bitset& operator<<=(size_t shift) {
        if (shift == 0 || numBits == 0) {
            return *this;
        }
        if (shift >= numBits) {
            std::fill(bits.begin(), bits.end(), 0);
            return *this;
        }

        size_t wordShift = shift / BITS_PER_WORD;
        size_t bitShift = shift % BITS_PER_WORD;
        size_t n = bits.size();

        if (wordShift > 0) {
            // 使用 memmove 加速内存块移动
            std::memmove(&bits[wordShift], &bits[0], (n - wordShift) * sizeof(uint64_t));
            std::fill(bits.begin(), bits.begin() + wordShift, 0);
        }

        if (bitShift > 0) {
            uint64_t carry = 0;
            for (size_t i = 0; i < n; ++i) {
                uint64_t new_carry = bits[i] >> (BITS_PER_WORD - bitShift);
                bits[i] <<= bitShift;
                bits[i] |= carry;
                carry = new_carry;
            }
        }

        // 清除超出 numBits 的位
        size_t excessBits = (BITS_PER_WORD * n) - numBits;
        if (excessBits > 0) {
            bits[n - 1] &= (~uint64_t(0)) >> excessBits;
        }

        return *this;
    }

    // 左移操作符<<
    Bitset operator<<(size_t shift) const {
        Bitset result(*this);
        result <<= shift;
        return result;
    }

    Bitset& operator>>=(size_t shift) {
        if (shift == 0 || numBits == 0) {
            return *this;
        }
        if (shift >= numBits) {
            std::fill(bits.begin(), bits.end(), 0);
            return *this;
        }

        size_t wordShift = shift / BITS_PER_WORD;
        size_t bitShift = shift % BITS_PER_WORD;
        size_t n = bits.size();

        if (wordShift > 0) {
            // 使用 memmove 加速内存块移动
            std::memmove(&bits[0], &bits[wordShift], (n - wordShift) * sizeof(uint64_t));
            std::fill(bits.begin() + (n - wordShift), bits.end(), 0);
        }

        if (bitShift > 0) {
            uint64_t carry = 0;
            for (size_t i = n; i-- > 0; ) {
                uint64_t new_carry = bits[i] << (BITS_PER_WORD - bitShift);
                bits[i] >>= bitShift;
                bits[i] |= carry;
                carry = new_carry;
            }
        }

        // 清除超出 numBits 的位
        size_t excessBits = (BITS_PER_WORD * n) - numBits;
        if (excessBits > 0) {
            bits[n - 1] &= (~uint64_t(0)) >> excessBits;
        }

        return *this;
    }

    // 右移操作符>>
    Bitset operator>>(size_t shift) const {
        Bitset result(*this);
        result >>= shift;
        return result;
    }

    // 位异或赋值运算符^=，使用 SIMD 指令加速
    __attribute__((target("avx2")))
    Bitset& operator^=(const Bitset& other) {
        if (numBits != other.numBits) {
            throw std::invalid_argument("Bitsets must be of the same size for ^= operation");
        }

        size_t n = bits.size();
        size_t i = 0;

        // 使用 AVX2 指令一次处理 256 位（4 个 uint64_t）
        for (; i + 4 <= n; i += 4) {
            __m256i a = _mm256_loadu_si256(reinterpret_cast<const __m256i*>(&bits[i]));
            __m256i b = _mm256_loadu_si256(reinterpret_cast<const __m256i*>(&other.bits[i]));
            __m256i c = _mm256_xor_si256(a, b);
            _mm256_storeu_si256(reinterpret_cast<__m256i*>(&bits[i]), c);
        }

        // 处理剩余的位块
        for (; i < n; ++i) {
            bits[i] ^= other.bits[i];
        }
        return *this;
    }

    // 位异或运算符^
    Bitset operator^(const Bitset& other) const {
        Bitset result(*this);
        result ^= other;
        return result;
    }

    // 位或赋值运算符|=，使用 SIMD 指令加速
    __attribute__((target("avx2")))
    Bitset& operator|=(const Bitset& other) {
        if (numBits != other.numBits) {
            throw std::invalid_argument("Bitsets must be of the same size for |= operation");
        }

        size_t n = bits.size();
        size_t i = 0;

        // 使用 AVX2 指令一次处理 256 位（4 个 uint64_t）
        for (; i + 4 <= n; i += 4) {
            __m256i a = _mm256_loadu_si256(reinterpret_cast<const __m256i*>(&bits[i]));
            __m256i b = _mm256_loadu_si256(reinterpret_cast<const __m256i*>(&other.bits[i]));
            __m256i c = _mm256_or_si256(a, b);
            _mm256_storeu_si256(reinterpret_cast<__m256i*>(&bits[i]), c);
        }

        // 处理剩余的位块
        for (; i < n; ++i) {
            bits[i] |= other.bits[i];
        }
        return *this;
    }

    // 位或运算符|
    Bitset operator|(const Bitset& other) const {
        Bitset result(*this);
        result |= other;
        return result;
    }

    // 按位与赋值运算符&=，使用 SIMD 指令加速
    __attribute__((target("avx2")))
    Bitset& operator&=(const Bitset& other) {
        if (numBits != other.numBits) {
            throw std::invalid_argument("Bitsets must be of the same size for &= operation");
        }

        size_t n = bits.size();
        size_t i = 0;

        // 使用 AVX2 指令一次处理 256 位（4 个 uint64_t）
        for (; i + 4 <= n; i += 4) {
            __m256i a = _mm256_loadu_si256(reinterpret_cast<const __m256i*>(&bits[i]));
            __m256i b = _mm256_loadu_si256(reinterpret_cast<const __m256i*>(&other.bits[i]));
            __m256i c = _mm256_and_si256(a, b);
            _mm256_storeu_si256(reinterpret_cast<__m256i*>(&bits[i]), c);
        }

        // 处理剩余的位块
        for (; i < n; ++i) {
            bits[i] &= other.bits[i];
        }
        return *this;
    }

    // 按位与运算符&
    Bitset operator&(const Bitset& other) const {
        Bitset result(*this);
        result &= other;
        return result;
    }

    // 按位非运算符~
    Bitset operator~() const {
        Bitset result(numBits);
        size_t n = bits.size();

        // 使用 AVX2 指令加速按位非
        size_t i = 0;
        for (; i + 4 <= n; i += 4) {
            __m256i a = _mm256_loadu_si256(reinterpret_cast<const __m256i*>(&bits[i]));
            __m256i c = _mm256_xor_si256(a, _mm256_set1_epi64x(~0ULL));
            _mm256_storeu_si256(reinterpret_cast<__m256i*>(&result.bits[i]), c);
        }

        // 处理剩余的位块
        for (; i < n; ++i) {
            result.bits[i] = ~bits[i];
        }

        // 清除超出 numBits 的位
        size_t excessBits = (BITS_PER_WORD * n) - numBits;
        if (excessBits > 0) {
            result.bits[n - 1] &= (~uint64_t(0)) >> excessBits;
        }

        return result;
    }

    // 左移赋值运算符>>= (Note: Should this be right shift?)
    // I think this might be a typo in the user's code, but I'll proceed as per user's code.

    // 打印位集（用于调试）
    void print() const {
        for (size_t i = numBits; i-- > 0;) {
            std::cout << (*this)[i];
            if (i % 8 == 0) {
                std::cout << ' ';
            }
        }
        std::cout << std::endl;
    }

    // 调整 Bitset 的大小
    void resize(size_t new_size) {
        size_t new_numWords = (new_size + BITS_PER_WORD - 1) / BITS_PER_WORD;
        bits.resize(new_numWords, 0);
        numBits = new_size;

        // 清除多余的位
        if (new_size % BITS_PER_WORD != 0) {
            bits.back() &= (uint64_t(1) << (new_size % BITS_PER_WORD)) - 1;
        }
    }

    // 查找第一个设置为1的位的位置
    // 如果没有设置为1的位，则返回 numBits
    size_t _Find_first() const {
        for (size_t i = 0; i < bits.size(); ++i) {
            if (bits[i] != 0) {
                // __builtin_ffsll 返回从1开始的位索引，0表示没有找到
                int pos = __builtin_ffsll(bits[i]);
                if (pos != 0) {
                    size_t bitPos = i * BITS_PER_WORD + (pos - 1);
                    if (bitPos < numBits) {
                        return bitPos;
                    }
                }
            }
        }
        return numBits; // 表示没有找到
    }

    // 从给定位置 pos 开始，查找下一个设置为1的位的位置
    // 如果没有找到，则返回 numBits
    size_t _Find_next(size_t pos) const {
        if (pos >= numBits - 1) {
            return numBits;
        }

        pos++; // Start searching after the given position
        size_t wordIndex = pos / BITS_PER_WORD;
        size_t bitIndex = pos % BITS_PER_WORD;

        // 检查当前字的高位
        if (wordIndex < bits.size()) {
            uint64_t mask = (~uint64_t(0)) << bitIndex;
            uint64_t word = bits[wordIndex] & mask;
            if (word != 0) {
                int firstSet = __builtin_ffsll(word);
                if (firstSet != 0) {
                    size_t bitPos = wordIndex * BITS_PER_WORD + (firstSet - 1);
                    if (bitPos < numBits) {
                        return bitPos;
                    }
                }
            }
        }

        // 检查后续字
        for (size_t i = wordIndex + 1; i < bits.size(); ++i) {
            if (bits[i] != 0) {
                int firstSet = __builtin_ffsll(bits[i]);
                if (firstSet != 0) {
                    size_t bitPos = i * BITS_PER_WORD + (firstSet - 1);
                    if (bitPos < numBits) {
                        return bitPos;
                    }
                }
            }
        }

        return numBits; // 表示没有找到
    }
};
