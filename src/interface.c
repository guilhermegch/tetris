#include <curses.h>
#include <locale.h>

int main(int argc, char** argv) {
  setlocale(LC_ALL, "");

  initscr();

  /* Escreve o título Tetris */ 
  move(0,15);
  printw("████████╗███████╗████████╗██████╗ ██╗███████╗");
  move(1,15);
  printw("╚══██╔══╝██╔════╝╚══██╔══╝██╔══██╗██║██╔════╝");
  move(2,15);
  printw("   ██║   █████╗     ██║   ██████╔╝██║███████╗");
  move(3,15);
  printw("   ██║   ██╔══╝     ██║   ██╔══██╗██║╚════██║");
  move(4,15);
  printw("   ██║   ███████╗   ██║   ██║  ██║██║███████║");
  move(5,15);
  printw("   ╚═╝   ╚══════╝   ╚═╝   ╚═╝  ╚═╝╚═╝╚══════╝");

  /* Define o tamanho das subjanelas */
  WINDOW* game = newwin(30, 40, 8, 3);
  WINDOW* next_piece = newwin(10, 21, 8, 50);
  WINDOW* score = newwin(10, 21, 20, 50);

  refresh();

  /* Desenha as caixas */
  box(game, 0, 0);
  box(next_piece, 0, 0);
  box(score, 0, 0);

  mvwprintw(score, 0, 8, "Score");

  refresh();

  /* Atualiza as subjanelas */  
  wrefresh(game);
  wrefresh(next_piece);
  wrefresh(score);

  /* Espera o input do usuário para fechar (vai ser removido) */
  getch();

  /* Apaga tudo */
  delwin(game);
  delwin(score);
  delwin(next_piece);

  endwin();
  return 0;
}