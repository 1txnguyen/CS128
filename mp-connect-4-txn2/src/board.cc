#include "board.hpp"

// you might need additional includes
#include <iomanip>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>

/**************************************************************************/
/* your function definitions                                              */
/**************************************************************************/

void InitBoard(Board& b) {
  // define this function
  for (int i = 0; i < Board::kBoardHeight; i++) {
    for (int j = 0; j < Board::kBoardWidth; j++) {
      b.board[i][j] = DiskType::kEmpty;
    }
  }
}

void DropDiskToBoard(Board& b, DiskType disk, int col) {
  if (col >= Board::kBoardWidth || col < 0) {
    throw std::runtime_error("");
  }
  bool found = false;
  for (int i = 0; i < Board::kBoardHeight; i++) {
    if (b.board[i][col] == DiskType::kEmpty) {
      b.board[i][col] = disk;
      found = true;
      break;
    }
  }
  if (!found) {
    throw std::runtime_error("");
  }
}

bool CheckForWinner(Board& b, DiskType disk) {
  // define this function
  // the return statement below is only there so that the starter code compiles
  // against the test suite.
  if (SearchForWinner(b, disk, WinningDirection::kHorizontal)) {
    return true;
  }
  if (SearchForWinner(b, disk, WinningDirection::kVertical)) {
    return true;
  }
  if (SearchForWinner(b, disk, WinningDirection::kLeftDiag)) {
    return true;
  }
  if (SearchForWinner(b, disk, WinningDirection::kRightDiag)) {
    return true;
  }
  return false;
}
bool Horizontal(Board& b, DiskType disk) {
  for (int out = 0; out < Board::kBoardHeight; out++) {
    for (int i = 0; i < Board::kBoardWidth - 3; i++) {
      bool d = true;
      for (int g = i; g < i + 4; g++) {
        if (b.board[out][g] != disk) {
          d = false;
        }
      }
      if (d) {
        return true;
      }
    }
  }
  return false;
}
bool Vertical(Board& b, DiskType disk) {
  for (int out = 0; out < Board::kBoardHeight - 3; out++) {
    for (int i = 0; i < Board::kBoardWidth; i++) {
      bool d = true;
      for (int g = out; g < out + 4; g++) {
        if (b.board[g][i] != disk) {
          d = false;
        }
      }
      if (d) {
        return true;
      }
    }
  }
  return false;
}
bool Left(Board& b, DiskType disk) {
  for (int out = 0; out < Board::kBoardHeight; out++) {
    for (int i = 0; i < Board::kBoardWidth; i++) {
      bool d = true;
      for (int g = 0; g < 4; g++) {
        if (BoardLocationInBounds(out - g, i + g)) {
          if (b.board[out - g][i + g] != disk) {
            d = false;
          }
        } else {
          d = false;
          break;
        }
      }
      if (d) {
        return true;
      }
    }
  }
  return false;
}
bool Right(Board& b, DiskType disk) {
  for (int out = 0; out < Board::kBoardHeight; out++) {
    for (int i = 0; i < Board::kBoardWidth; i++) {
      bool d = true;
      for (int g = 0; g < 4; g++) {
        if (BoardLocationInBounds(out + g, i + g)) {
          if (b.board[out + g][i + g] != disk) {
            d = false;
          }
        } else {
          d = false;
          break;
        }
      }
      if (d) {
        return true;
      }
    }
  }
  return false;
}
bool SearchForWinner(Board& b, DiskType disk, WinningDirection to_check) {
  switch (to_check) {
  case WinningDirection::kHorizontal:
    return Horizontal(b, disk);
  case WinningDirection::kVertical:
    return Vertical(b, disk);
  case WinningDirection::kLeftDiag:
    return Left(b, disk);
  case WinningDirection::kRightDiag:
    return Right(b, disk);
  }
  return false;
}
bool BoardLocationInBounds(int row, int col) {
  // define this function
  // the return statement below is only there so that the starter code compiles
  // against the test suite.
  return (row < Board::kBoardHeight && row >= 0) &&
         (col < Board::kBoardWidth && col >= 0);
}

/**************************************************************************/
/* provided to you                                                        */
/**************************************************************************/
std::string BoardToStr(const Board& b) {
  constexpr int kTotalWidth = Board::kBoardWidth * 11 - Board::kBoardHeight - 1;
  std::stringstream ss;
  ss << std::endl;
  for (int row = Board::kBoardHeight; row > 0; --row) {
    ss << " |";
    for (int col = 0; col < Board::kBoardWidth; ++col) {
      std::string value_here;
      value_here.push_back(static_cast<char>(b.board[row - 1][col]));
      ss << ' ' << CenterStr(value_here, Board::kBoardWidth + 1) << '|';
    }
    ss << std::endl;
    ss << " |" << std::setw(kTotalWidth) << std::setfill('-') << '|'
       << std::endl;
  }
  ss << " |";
  for (int col = 0; col < Board::kBoardWidth; ++col) {
    ss << ' ' << CenterStr(std::to_string(col), Board::kBoardWidth + 1) << '|';
  }
  return ss.str();
}

std::string CenterStr(const std::string& str, int col_width) {
  // quick and easy (but error-prone) implementation
  auto padl = (col_width - str.length()) / 2;
  auto padr = (col_width - str.length()) - padl;
  std::string strf = std::string(padl, ' ') + str + std::string(padr, ' ');
  return strf;
}