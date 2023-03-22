rm validation.elf
g++ -g -std=c++20 -Werror -Wall -Wextra -Wpedantic -Wconversion *.cpp ../*.cpp -o validation.elf
valgrind ./validation.elf
