#pragma once
struct piece {
    unsigned int row, col;

    bool operator<(const piece b) const {
        return (row < b.row) || (row == b.row && col < b.col);
    }
};

struct move {
    unsigned int oldRow, oldCol, newRow, newCol;

    bool operator<(const move b) const {
        return (oldRow < b.oldRow) || (oldRow == b.oldRow && oldCol < b.oldCol) || (oldRow == b.oldRow && oldCol == b.oldCol && newRow < b.newRow) ||
               (oldRow == b.oldRow && oldCol == b.oldCol && newRow == b.newRow && newCol < b.newCol);
    }

    bool operator>(const move b) const {
        return (oldRow > b.oldRow) || (oldRow == b.oldRow && oldCol > b.oldCol) || (oldRow == b.oldRow && oldCol == b.oldCol && newRow > b.newRow) ||
               (oldRow == b.oldRow && oldCol == b.oldCol && newRow == b.newRow && newCol > b.newCol);
    }
};