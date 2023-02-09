echo "find ./src -name \"*.cpp\" -o -name \"*.h\" | xargs clang-format -i"
find ./src -name "*.cpp" -o -name "*.h" | xargs clang-format -i
echo "start......"
echo "complete!"