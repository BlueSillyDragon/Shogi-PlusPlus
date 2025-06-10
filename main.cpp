#include <cstdio>
#include <shogi.hpp>

int main()
{
    kif::kifMove_t currentMove;

    display_board();

    if (!parse_kif_move(currentMove)) {
        printf("Parse error!\n");
    } else printf("Parse success!\n");
    return 0;
}
