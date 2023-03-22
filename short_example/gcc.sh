rm short_example.elf
g++ -g -std=c++20 -Werror -Wall -Wextra -Wpedantic -Wconversion *.cpp ../*.cpp -o short_example.elf
valgrind ./short_example.elf
