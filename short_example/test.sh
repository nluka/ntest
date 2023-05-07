rm short_example.elf
g++ -g -std=c++20 -Werror -Wall -Wextra -Wpedantic -Wformat -Wmissing-include-dirs -Wuninitialized -Wunreachable-code -Wshadow -Wconversion -Wsign-conversion -Wmissing-declarations -Wredundant-decls -Winit-self -Wswitch-default -Wfloat-equal -Wundef -Wunused-parameter *.cpp ../*.cpp -o short_example.elf
valgrind --track-origins=yes ./short_example.elf
