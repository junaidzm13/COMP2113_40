#Ludo Game

FLAGS = -pedantic-errors -std=c++11

has_won.o: has_won.cpp has_won.h
	g++ $(FLAGS) -c $<

load_profile.o: load_profile.cpp load_profile.h structs.h
	g++ $(FLAGS) -c $<

make_a_move.o: make_a_move.cpp make_a_move.h structs.h show_board.h
	g++ $(FLAGS) -c $<

read_username.o: read_username.cpp read_username.h
	g++ $(FLAGS) -c $<

roll_dice.o: roll_dice.cpp roll_dice.h structs.h
	g++ $(FLAGS) -c $<

select_token.o: select_token.cpp select_token.h
	g++ $(FLAGS) -c $<

set_the_board.o: set_the_board.cpp set_the_board.h structs.h
	g++ $(FLAGS) -c $<

show_board.o: show_board.cpp show_board.h structs.h
	g++ $(FLAGS) -c $<

update_profile.o: update_profile.cpp update_profile.h structs.h
	g++ $(FLAGS) -c $<

output_profile.o: output_profile.cpp output_profile.h structs.h
	g++ $(FLAGS) -c $<

ludo_main.o: ludo_main.cpp has_won.h load_profile.h make_a_move.h read_username.h roll_dice.h select_token.h set_the_board.h show_board.h update_profile.h structs.h output_profile.h
	g++ $(FLAGS) -c $<

ludo_main: ludo_main.o update_profile.o show_board.o set_the_board.o select_token.o roll_dice.o read_username.o make_a_move.o load_profile.o has_won.o output_profile.o
	g++ $(FLAGS) $^ -o $@

clean:
	rm -f ludo_main *.o

tar:
	tar -czvf ludo.tgz *.cpp *.h

.PHONY: clean tar
