#include "Game.hpp"
#include <iostream>
#include <string>

Game:: Game(): area() 
{
}

Game:: Game(int size, int num_mines): area(size, num_mines)
{
}

int Game::input() const 
{
    int num;
    std::cout << "Please choose a cell (the first starts from 0): ";
    std::cin >> num;

    while (true) 
    { // will loop continously
        if (!(num >= 0 && num <= this->area.get_size() - 1)) 
        { // if num is NOT a valid index
            std::cout << "Enter an integer in [0, " << area.get_size()-1 << "]: "; // asks user to re-enter num
            std::cin >> num;
            continue; // checks condition again
        }

        if(this->area.is_checked(num)) { // if cell is already checked
            std::cout << "Cell " << num << "is already chosen. Please re-enter: "; // asks user to re-enter num
            std::cin >> num;
            continue; // checks condition again
        }
      
        break;
    }
    return num;
}
void Game::play() 
{
  int round = 1;
  int check = 0; // # of checked cells

  while(true) 
  {
    std::cout << area.to_string() << "\n"; // prints current field
    std::cout << "Round " << round << ": ";

    int num = input(); // user's input for cell
    area.mark_checked(num); // marks user's choosen cell checked
    check++; // update checked cells

    if(area.has_mine(num)) 
    { // if choosen cell has mine
      std::cout << "Mine explodes! Game ends." << "\n";
      break;
    }

    else if(check == area.get_size() - area.get_num_mines()) { // once all cells has been checked
      std::cout << area.to_string() << "\n";
      std::cout << "Congratulations! Find out all the cells without mines." << "\n";
      break;
    }

    area.mark_checked(num); // marks cell checked
    round++;
  }
  std::cout <<"\nThe answer is " << "\n";
  std::cout << area.answer_string(); // prints the field with mines and non-mines

}