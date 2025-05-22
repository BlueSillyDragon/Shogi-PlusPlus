#include <iostream>
#include <shogi.hpp>

using namespace std;

int main()
{
    std::cout << "Empty squares: " << empty_squares() << std::endl;
    std::cout << "Occupied squares: " << occupied_squares() << std::endl;
    std::cout << "Gote pieces: " << gote_pieces() << std::endl;
    std::cout << "Sente pieces: " << sente_pieces() << std::endl;

    print_piece_type(piece_at_pos(1, 1));
    print_color_type(color_at_pos(1, 1));

    std::cout << eval() << std::endl;

    parse_kif_move();

    return 0;
}
