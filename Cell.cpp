#include "Cell.h"

short Cell::idGenerator = 0;

Cell::Cell(const short& row, const short& col) : cell{'x'}, rateLife{0}, row{row}, col{col}
{
	id = idGenerator++;
}

Cell::Cell(const short& row, const short& col, std::shared_ptr<Cell> tail) :
	cell{'x'}, rateLife{0}, row{ row }, col{ col }
{
	prevCell = tail;
	id = idGenerator++;
}

char Cell::getCell() const {
	return this->cell;
}

short Cell::getRate() const {
	return this->rateLife;
}

short Cell::getRow() const {
	return this->row;
}

short Cell::getCol() const {
	return this->col;
}

void Cell::setRate(const short& rateLife) {
	this->rateLife += rateLife;
}

void Cell::setRow(const short& row) {
	this->row += row;
}

void Cell::setCol(const short& col) {
	this->col += col;
}