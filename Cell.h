#pragma once

#ifndef CELL_H
#define CELL_H

#include <cstddef>
#include <memory>

class Cell
{
private:
	short rateLife;
	short row;
	short col;
	short id;
	static short idGenerator;
	std::weak_ptr<Cell> prevCell;

public:
	Cell(const short&, const short&);

	Cell(const short&, const short&, std::shared_ptr<Cell>);

#pragma region getters
	short getRate() const;

	short getRow() const;

	short getCol() const;
#pragma endregion

#pragma region setters
	void setRate(const short&);

	void setRow(const short&);

	void setCol(const short&);
#pragma endregion
};
#endif