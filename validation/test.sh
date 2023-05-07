rm validation.elf
g++ -g -std=c++20 -Werror -Wall -Wextra -Wpedantic -Wformat -Wmissing-include-dirs -Wuninitialized -Wunreachable-code -Wshadow -Wconversion -Wsign-conversion -Wmissing-declarations -Wredundant-decls -Winit-self -Wswitch-default -Wfloat-equal -Wundef -Wunused-parameter *.cpp ../*.cpp -o validation.elf
valgrind ./validation.elf
