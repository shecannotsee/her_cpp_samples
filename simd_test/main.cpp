#include <immintrin.h>  // AVX2头文件
#include <iostream>
#include <cstdlib>

int main() {
  // 分配对齐内存（AVX2建议32字节对齐）
  alignas(32) float a[8] = {0,1,2,3,4,5,6,7};
  alignas(32) float b[8] = {7,6,5,4,3,2,1,0};
  alignas(32) float result[8];

  // 加载数据到AVX2寄存器（256位）
  __m256 vec_a = _mm256_loadu_ps(a);
  __m256 vec_b = _mm256_loadu_ps(b);

  // 执行向量加法
  __m256 vec_sum = _mm256_add_ps(vec_a, vec_b);

  // 将结果存回内存
  _mm256_storeu_ps(result, vec_sum);

  // 验证结果（每个元素应为 7.0f）
  bool valid = true;
  for (int i = 0; i < 8; ++i) {
    if (result[i] != 7.0f) {
      valid = false;
      break;
    }
  }

  std::cout << "AVX2 test "
            << (valid ? "passed!" : "failed!")
            << std::endl;

  return EXIT_SUCCESS;
}